#include "GIGameObject.h"
#include "GIWindow.h"


GIGameObject::GIGameObject()
{
}


GIGameObject::~GIGameObject()
{
}

void GIGameObject::Init(GIGameObjectDesc _desc)
{

  m_descriptor = _desc;
  
  m_Mesh = new sf::CircleShape(m_descriptor.Radius);

  if (m_descriptor.TextureName != nullptr)
  {
    GITextureDesc TextureDesc;
    TextureDesc.FileName = m_descriptor.TextureName;
    m_texture.Init(TextureDesc);

    m_Mesh->setTexture(&m_texture.getInterface());
  }
  else
  {
    m_Mesh->setFillColor(_desc.Color);
    m_Mesh->setOutlineThickness(m_descriptor.OutlineSize);
    m_Mesh->setOutlineColor(m_descriptor.OutlineColor);
  }

  m_Mesh->setRadius(m_descriptor.Radius);
  m_Mesh->setPosition(m_descriptor.Position);
  m_Mesh->setOrigin(m_descriptor.Origin);
  m_velocity = _desc.Velocity;
}

void GIGameObject::Update(sf::Vector2f _position)// Transform
{
//   sf::Vector2f newDir = _position - getPosition();
//   newDir.x = _position.x - getPosition().x;
//   newDir.y = _position.y - getPosition().y;
// 
//   sf::Vector2f tmpPos = m_Mesh->getPosition();
// 
//   if (
//     newDir.x > -15 && newDir.x < 15 &&
//     newDir.y > -15 && newDir.y < 15
//     )
//   {
// 
//   }
//   else
//   {
//     float squareLength = (newDir.x * newDir.x + newDir.y*newDir.y);
//     float mod = squareLength;
//     float invLength = 1.0f / sqrtf(mod);
//     newDir.x = newDir.x *invLength;
//     newDir.y = newDir.y *invLength;
// 
//     tmpPos.x += newDir.x * m_velocity;
//     tmpPos.y += newDir.y * m_velocity;
//   }
//   m_Mesh->setPosition(tmpPos);
   m_Mesh->setPosition(_position);
}

void GIGameObject::Render(GIWindow & _window)
{
  _window.getInterface()->draw(*m_Mesh);
}

void GIGameObject::Destroy()
{
  if (m_Mesh != nullptr)
  {
    delete m_Mesh;
  }
}

void GIGameObject::setRadius(float _radius)
{
  m_Mesh->setRadius(_radius);
}

float GIGameObject::getRadius()
{
  float tmpRadius = m_Mesh->getRadius();
  return tmpRadius;
}

void GIGameObject::setPosition(sf::Vector2f _position)
{
  m_Mesh->setPosition(_position);
}

void GIGameObject::setOrigin(sf::Vector2f _origin)
{
  m_Mesh->setOrigin(_origin);
}

void GIGameObject::setOriginToCenter()
{
  m_Mesh->setOrigin(m_descriptor.Radius, m_descriptor.Radius);
}

void GIGameObject::setFillColor(sf::Color _color)
{
  m_Mesh->setFillColor(_color);
}

bool & GIGameObject::getIsColliding()
{
  return m_isColliding;
}

void GIGameObject::setCollidingState(bool _collidingState)
{
  m_isColliding = _collidingState;
}

sf::Vector2f & GIGameObject::getPosition()
{
  sf::Vector2f tmpPos = m_Mesh->getPosition();
  return tmpPos;
}

const sf::FloatRect & GIGameObject::getGlobalBounds()
{
  return m_Mesh->getGlobalBounds();
}

void GIGameObject::setVelocity(float _vel)
{
  m_velocity = _vel;
}

float & GIGameObject::getVelocity()
{
  return m_velocity;
}

GIGameObjectDesc & GIGameObject::getDescriptor()
{
  return m_descriptor;
}

sf::CircleShape *& GIGameObject::getInterface()
{
  return m_Mesh;
}
