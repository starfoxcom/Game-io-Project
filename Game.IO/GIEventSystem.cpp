#include "GIEventSystem.h"
#include "GIGameObject.h"
#include "GISteeringBehaviors.h"
#include "GIWindow.h"
#include"GIInputManager.h"
#include <chrono>
 

GIEventSystem::GIEventSystem()
{
}

GIEventSystem::~GIEventSystem()
{
}

void GIEventSystem::Init(GIGameObject & _player)
{
  m_radius = _player.getDescriptor().Radius;
  m_vortexCDTimer = 0;
  m_vortexUsageTimer = 0;
}

void GIEventSystem::Update(GIWindow & _window, GIGameObject & _player, vector<GIGameObject> & _food, vector<GIGameObject> & _enemies, vector<GIGameObject> & _vortex, vector<GIGameObject> & _ItemClon)
{
  playerRadius(_player, _food, _enemies, _ItemClon);
  vortexRadius(_player, _vortex);
  playerVelocity(_player);
  dash(_window,event, _player);

  //Checamos si el jugador hizo click derecho y aparte si tiene el item de clon
  if (m_IsInstanciated) {

      //Mandamos a crear una instancia del player de ese momento
      Instance(_player);
      for (int i = 0; i < m_Instances.size(); i++)
      {
          m_Instances[i].Init(_player.getDescriptor());
      }

      m_IsInstanciated = false;
      
  }
  

  //Ciclo para poder asignar los valores al clon
  for (int i = 0; i < m_Instances.size(); i++) {

      m_Instances[i].setVelocity(0);    //Velocidad del clon
      m_Instances[i].setPosition(m_tempInverse); //Direcci�n
  }
}

void GIEventSystem::Render(GIWindow& _window)
{
  for (int i = 0; i < m_Instances.size(); i++) {

    m_Instances[i].Render(_window);
  }
}

void GIEventSystem::Destroy()
{

}

void GIEventSystem::playerRadius(GIGameObject & _player, vector<GIGameObject> & _food, vector<GIGameObject> & _enemies, vector<GIGameObject> & _ItemClon)
{
   for (int i = 0; i < _ItemClon.size(); i++) //*@Author :Ramses
  {
      if (_player.getInterface()->getGlobalBounds().intersects(_ItemClon[i].getInterface()->getGlobalBounds()) && _ItemClon[i].getIsColliding() == false)
      {
          m_radius += 0.5f;
          _player.setRadius(m_radius);
          _player.setOrigin(sf::Vector2f(m_radius, m_radius));
          _ItemClon[i].setCollidingState(true);
          _player.setIsItemClon(true);
          _ItemClon.erase(_ItemClon.begin() + i);
      }
  }
  for (int i = 0; i < _food.size(); i++)
  {
    if (_player.getInterface()->getGlobalBounds().intersects(_food[i].getInterface()->getGlobalBounds()) && _food[i].getIsColliding() == false)
    {
      m_radius += 0.5f;
      _player.setRadius(m_radius);
      _player.setOrigin(sf::Vector2f(m_radius, m_radius));
      _food[i].setCollidingState(true);
      _food.erase(_food.begin() + i);
    }
  }
  for (int i = 0; i < _enemies.size(); i++)
  {
    if (_player.getInterface()->getGlobalBounds().intersects(_enemies[i].getInterface()->getGlobalBounds()) && _player.getRadius() >= 150)
    {
      m_radius += 5;
      _player.setRadius(m_radius);
      _player.setOrigin(sf::Vector2f(m_radius, m_radius));
      _enemies[i].setCollidingState(true);
      _enemies.erase(_enemies.begin() + i);
    }
  }
  

//   for (int i = 0; i < _enemies.size(); i++)
//   {
//     // If player collides with the enemy collider
//     if (_player.getInterface()->getGlobalBounds().intersects(_enemies[i].getInterface()->getGlobalBounds()) && _player.getRadius() >= 35)
//     {
//       m_radius -= 1;
//       _player.setRadius(m_radius);
//       _player.setOrigin(sf::Vector2f(m_radius, m_radius));
//     }
//   }
}

void GIEventSystem::vortexRadius(GIGameObject & _player, vector<GIGameObject>& _vortex) {
  for (int i = 0; i < _vortex.size(); i++) {
    //check magnitudes distances between player and vortex effect area
    sf::Vector2f distance = (_player.getPosition() - _vortex[i].getPosition());
    float mag = sqrtf((distance.x * distance.x) + (distance.y * distance.y));

    //On player on vortex radius
    if (mag <= 350.f && m_vortexCDTimer <= 0 && m_vortexUsageTimer < 1000) {
      //TODO: Add vortex pull force to players
      _vortex[i].setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));

      sf::Vector2f vortexPos = _vortex[i].getPosition();
      float tmpVel = _player.getVelocity() * 0.8f;
      _player.Update(GISteeringBehaviors::getSingleton().Seek(vortexPos, _player, tmpVel));
      _vortex[i].setIsOnVortex(true);
      if (_player.getInterface()->getGlobalBounds().intersects(_vortex[i].getInterface()->getGlobalBounds()) && _player.getRadius() <= 150) {
        if(_player.getRadius() >= 25) {
          m_radius -= 20;
        }
        _player.setRadius(m_radius);
        _player.setOrigin(sf::Vector2f(m_radius, m_radius));
        _vortex[i].setIsOnVortex(false);
        m_vortexCDTimer = 1000;
        break;
      }
      if (_player.getInterface()->getGlobalBounds().intersects(_vortex[i].getInterface()->getGlobalBounds()) && _player.getRadius() >= 150)
      {
		  std::cout << "\nx";
        m_radius += 5;
        _player.setRadius(m_radius);
        _player.setOrigin(sf::Vector2f(m_radius, m_radius));
        _vortex[i].setCollidingState(true);
        _vortex[i].setIsOnVortex(false);
        _vortex.erase(_vortex.begin() + i);
        m_vortexCDTimer = 1000;
        break;
      }
      m_vortexUsageTimer++;
    }
    else {
      _vortex[i].setFillColor(sf::Color::Magenta);
      if (_vortex[i].getIsOnVortex()) {
        _vortex[i].setIsOnVortex(false);
        m_vortexCDTimer = 1000;				
      }
    }
  }

  if(m_vortexCDTimer > 0) {
    for (int i = 0; i < _vortex.size(); i++) {
      _vortex[i].setFillColor(sf::Color(220,220,220));
    }
    m_vortexCDTimer--;
    if (m_vortexUsageTimer > 0) {
      m_vortexUsageTimer--;
    }
  }
}

void GIEventSystem::playerVelocity(GIGameObject & _player)
{
  if (GIGraphic_API::getSingleton().inRange(_player.getRadius(), 20, 50))
  {
    _player.setVelocity(5.0f);
  }
  if (GIGraphic_API::getSingleton().inRange(_player.getRadius(), 50, 80))
  {
    _player.setVelocity(5.0f);
  }
  if (GIGraphic_API::getSingleton().inRange(_player.getRadius(), 80, 100))
  {
    _player.setVelocity(2.0f);
  }
  if (GIGraphic_API::getSingleton().inRange(_player.getRadius(), 100, 130))
  {
    _player.setVelocity(1.0f);
  }
  if (GIGraphic_API::getSingleton().inRange(_player.getRadius(), 130, 160))
  {
    _player.setVelocity(0.8f);
  }
}

void GIEventSystem::handleInputs(sf::Keyboard::Key key, bool isPressed, GIGameObject& _player){

    if (key == sf::Mouse::Right && _player.getIsItemClon() == true  ) {

        _player.setIsItemClon(false);
        m_RightMouse = isPressed;
        m_IsInstanciated = true;
        m_tempInverse = _player.getPosition();
    }

    if (key == sf::Keyboard::Space) {
          m_space = isPressed;
    }

}

void GIEventSystem::Instance(GIGameObject& _player){

    GIGameObject tempObject = _player;

    m_Instances.push_back(tempObject);
}

void GIEventSystem::dash(GIWindow& _window, sf::Event& AnyEvent, GIGameObject& Player)
{

    GIInputManager Temp;
    /*while (_window.getInterface()->pollEvent(event))
    {

            if (AnyEvent.key.code == Temp.Inputs.Space)
            {

                Player.setVelocity(Player.getVelocity() += 18);
                Player.setRadius(Player.getRadius() -= 5);
                Player.CanDash = false;
            }

            std::cout << "Dash" << std::endl;

            Player.Dashes += 1;

         ElapsedTime = Player.CoolDown.getElapsedTime();

         if (ElapsedTime.asSeconds() > 0.25)
         {
             Player.CanDash = true;
             Player.CoolDown.restart();
         }
    }*/
    if (m_space)
    {
        Player.CanDash = true;
  
        
    }
    if (Player.CanDash)
    {
        Player.setVelocity(Player.getVelocity() += *Player.m_deltaTime * 50 * Player.getRadius());
        //Player.setRadius(Player.getRadius() -= 5);
        Player.CanDash = false;
        std::cout << "Dashing" << std::endl;
        std::cout << *Player.m_deltaTime;
    }

    if (!Player.CanDash)
    {

        int timer = Player.CoolDown.getElapsedTime().asSeconds();
        if (timer >= 2)
        {
            Player.CanDash = true;
            Player.CoolDown.restart();
            std::cout << "Dash" << std::endl;
            Player.Dashes += 1;
        }

    }
}