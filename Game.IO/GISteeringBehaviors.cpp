#include "GISteeringBehaviors.h"
#include "GIGameObject.h"


GISteeringBehaviors::GISteeringBehaviors()
{
}


GISteeringBehaviors::~GISteeringBehaviors()
{
}

sf::Vector2f GISteeringBehaviors::Seek(GIGameObject & _object1, GIGameObject & _object2)
{
  sf::Vector2f newDir = _object2.getPosition() - _object1.getPosition();
  newDir.x = _object2.getPosition().x - _object1.getPosition().x;
  newDir.y = _object2.getPosition().y - _object1.getPosition().y;

  sf::Vector2f tmpPos = _object1.getPosition();

  if (
    newDir.x > -15 && newDir.x < 15 &&
    newDir.y > -15 && newDir.y < 15
    )
  {

  }
  else
  {
    float squareLength = (newDir.x * newDir.x + newDir.y*newDir.y);
    float mod = squareLength;
    float invLength = 1.0f / sqrtf(mod);
    newDir.x = newDir.x *invLength;
    newDir.y = newDir.y *invLength;

    tmpPos.x += newDir.x * _object1.getVelocity();
    tmpPos.y += newDir.y * _object1.getVelocity();
  }
  
  return tmpPos;
}

sf::Vector2f GISteeringBehaviors::Seek(sf::Vector2f & _object2, GIGameObject & _object1)
{
  sf::Vector2f newDir = _object2 - _object1.getPosition();
  newDir.x = _object2.x - _object1.getPosition().x;
  newDir.y = _object2.y - _object1.getPosition().y;

  sf::Vector2f tmpPos = _object1.getPosition();

  if (
    newDir.x > -15 && newDir.x < 15 &&
    newDir.y > -15 && newDir.y < 15
    )
  {

  }
  else
  {
    float squareLength = (newDir.x * newDir.x + newDir.y*newDir.y);
    float mod = squareLength;
    float invLength = 1.0f / sqrtf(mod);
    newDir.x = newDir.x *invLength;
    newDir.y = newDir.y *invLength;

    tmpPos.x += newDir.x * _object1.getVelocity();
    tmpPos.y += newDir.y * _object1.getVelocity();
  }

  return tmpPos;
}
