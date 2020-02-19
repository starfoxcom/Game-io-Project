/**
 * @LC	   : 25/01/2020
 * @file   : GICamera.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 25/01/2020
 * @brief  : Class in charge of setting a basic camera for the project, 
             this class has a forward class declaration to the game object 
             in case that the class need it.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "GIDefines.h"
#include "GIGraphic_API.h"
#pragma once
/**
 * Forward class declarations
 */
class GIGameObject;
class GIWindow;
/**
 * @brief : 
 */
struct GICameraDesc
{
  float width;
  float height;
  float MinZoom;
  float MaxZoom;
  float MoveSpeed;
  sf::Vector2f Position;
};
/**
 * @brief : Class in charge of setting a basic camera for the project,
            this class has a forward class declaration to the game object
            in case that the class need it.
 */
class GICamera
{
public:
  GICamera();
  ~GICamera();
  /**
   * Members 
   */
private:
  /**
   * @brief : 
   */
  GICameraDesc m_descriptor;
  /**
   * @brief : 
   */
  sf::View* m_View;
  /**
   * @brief : 
   */
  float m_minZoom = 0.8f;
  /**
   * @brief : 
   */
  float m_maxZoom = 1.2f;
  /**
   * @brief : 
   */
  float m_moveSpeed = 0.50f;
  /**
   * @brief : 
   */
  sf::Vector2f m_position;
  /**
   * Public 
   */
public:
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Init(GICameraDesc _desc);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Update();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Render(GIWindow & _window);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void
  setView(sf::Vector2f & pos, const float& width, const float& height);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void
  moveCamera(const float& dirx, const float& diry, const float& dirz);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void
  setPosition(GIGameObject & _gameObject);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void
  setPosition(sf::Vector2f _Pos);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void
  incrementZoom();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void
  decrementZoom();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  sf::Vector2f
  getPosition();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  sf::View *& 
  getView();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  GICameraDesc & 
  getDescriptor();
};

