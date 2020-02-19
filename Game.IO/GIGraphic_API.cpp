#include "GIGraphic_API.h"
#include "GIWindow.h"
#include "GITexture.h"

GIGraphic_API::GIGraphic_API()
{
}


GIGraphic_API::~GIGraphic_API()
{
}

void GIGraphic_API::CreateSFMLWindow(GIWindow & _window)
{
  _window.getInterface() = new sf::RenderWindow
  (
    sf::VideoMode(
      _window.getDescriptor().Width,
      _window.getDescriptor().Height
    ),
    _window.getDescriptor().WndName
  );
}

void GIGraphic_API::Clear(GIWindow & _window, sf::Color _clearColor)
{
  _window.getInterface()->clear(_clearColor);
}

void GIGraphic_API::Present(GIWindow & _window)
{
  _window.getInterface()->display(); 
}

void GIGraphic_API::CreateTexture(GITexture & _texture)
{
  if (!_texture.getInterface().loadFromFile(_texture.getDescritor().FileName))
    cout << "cant load Texture!" << endl;
}

bool GIGraphic_API::inRange(float _x, float _y, float _z)
{
  if (_x >= _y && _x <= _z)
    return true;
  else
    return false;
}

sf::Event & GIGraphic_API::getEventInterface()
{
  return m_Event;
}
