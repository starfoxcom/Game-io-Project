#include "GIEventSystem.h"
#include "GIGameObject.h"
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
}

void GIEventSystem::Update(GIWindow & _window,  GIGameObject & _player, vector<GIGameObject> & _food, vector<GIGameObject> & _enemies)
{
  playerRadius(_player, _food, _enemies);
  playerVelocity(_player);
  dash(_window,event, _player);
}

void GIEventSystem::Render()
{

}

void GIEventSystem::Destroy()
{

}

void GIEventSystem::playerRadius(GIGameObject & _player, vector<GIGameObject> & _food, vector<GIGameObject> & _enemies)
{
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
    if (spacePressed)
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

void GIEventSystem::handleInputs(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Space) {
          spacePressed = isPressed;
    }
}
