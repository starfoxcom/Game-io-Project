#include "GIInputManager.h"
#include "GIWindow.h"
#include "GICamera.h"

GIInputManager::GIInputManager()
{
}


GIInputManager::~GIInputManager()
{
}


sf::Vector2f & GIInputManager::getMousePosition(GIWindow & _window)
{
  sf::Vector2i mousePos = sf::Mouse::getPosition(*_window.getInterface());
  float tmpX = mousePos.x;
  float tmpY = mousePos.y;
  sf::Vector2f tmpVectorf = sf::Vector2f(tmpX, tmpY);

  return tmpVectorf;
}

sf::Vector2f & GIInputManager::getWorldPosition(GIWindow & _window, GICamera & _camera)
{
  sf::Vector2i mousePos = sf::Mouse::getPosition(*_window.getInterface());
  sf::Vector2f worldPos = _window.getInterface()->mapPixelToCoords(mousePos, *_camera.getView());

  return  worldPos;
}
