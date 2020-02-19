#include "GIEventSystem.h"
#include "GIGameObject.h"
#include "GIWindow.h"

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

void GIEventSystem::Update(GIGameObject & _player, vector<GIGameObject> & _food, vector<GIGameObject> & _enemies)
{
  playerRadius(_player, _food, _enemies);
  playerVelocity(_player);
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
