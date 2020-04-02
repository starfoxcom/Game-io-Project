#include "GIInputManager.h"
#include "GIEventSystem.h"
#include "GIGameObject.h"
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

void GIInputManager::GetInput(sf::Event& _event, GIEventSystem& _eventSystem, GIGameObject& _player) {

  switch (_event.type)
  {
  case sf::Event::MouseButtonPressed:
    _eventSystem.handleInputs(_event.key.code, true, _player);
    break;
  case sf::Event::MouseButtonReleased:
    _eventSystem.handleInputs(_event.key.code, false, _player);
    break;
    case sf::Event::KeyPressed:
            _eventSystem.handleInputs(_event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            _eventSystem.handleInputs(_event.key.code, false);
            break;
  default:
    break;
  }
}
