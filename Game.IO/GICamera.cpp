#include "GICamera.h"
#include "GIGameObject.h"
#include "GIWindow.h"

GICamera::GICamera()
{
}


GICamera::~GICamera()
{
}

void GICamera::Init(GICameraDesc _desc)
{
  m_descriptor = _desc;

  m_position = m_descriptor.Position;

  m_View = new sf::View(sf::FloatRect(m_position.x, m_position.y, m_descriptor.width, m_descriptor.height));
}

void GICamera::Update()
{
  m_View->setCenter(m_position.x, m_position.y);
}

void GICamera::Render(GIWindow & _window)
{
  _window.getInterface()->setView(*getView());
}

void GICamera::Destroy()
{
  delete m_View;
}

void GICamera::setView(sf::Vector2f & pos, const float& width, const float& height)
{
  m_position = pos;
  m_View->reset(sf::FloatRect(m_position.x, m_position.y, width, height));
 // m_View->setCenter(m_position.x, m_position.y);
}

void GICamera::moveCamera(const float& dirx, const float& diry, const float& dirz)
{
  m_position.x += dirx * m_moveSpeed;
  m_position.y += diry * m_moveSpeed;
  m_position.y += dirz * m_moveSpeed;

  m_View->setCenter(m_position.x, m_position.y);
}

void GICamera::setPosition(GIGameObject & _gameObject)
{
  m_position.x = _gameObject.getInterface()->getPosition().x;
  m_position.y = _gameObject.getInterface()->getPosition().y;
}

void GICamera::setPosition(sf::Vector2f _Pos)
{
  m_position = _Pos;
}

void GICamera::incrementZoom()
{
  m_View->zoom(m_maxZoom);
}

void GICamera::decrementZoom()
{
  m_View->zoom(m_minZoom);
}

sf::Vector2f GICamera::getPosition()
{
  return m_position;
}

sf::View *& GICamera::getView()
{
  return m_View;
}

GICameraDesc & GICamera::getDescriptor()
{
  return m_descriptor;
}
