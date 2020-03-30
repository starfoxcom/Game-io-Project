/**
 * @LC	   : 25/01/2020
 * @file   : GIGameObject.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 25/01/2020
 * @brief  : Class in charge of setting components into the models. 
 * @bug	   : No known bugs.
 */

/**
 * Headers
 */
#include "GIDefines.h"
#include "GITexture.h"
#pragma once
/**
 * Forward Class Declarations 
 */
class GIWindow;

/**
 * @brief : Class in charge of setting components into the models.
 */
struct GIGameObjectDesc
{
  const char* TextureName;
  float Radius;
  float Velocity;
  int OutlineSize;
  sf::Vector2f Position;
  sf::Vector2f Origin;
  sf::Color Color;
  sf::Color OutlineColor;
  sf::Texture Tex;
  sf::Sprite sprite;
};
/**
 * @brief : Temporal structure for different shapes (not tested)
 */
struct GIGameObjectID 
{
  sf::RectangleShape rectangleShape;
  sf::CircleShape circleShape;
};

/**
 * @brief : Class in charge of setting components into the models.
 */
class GIGameObject
{
public:
  GIGameObject();
  ~GIGameObject();
  /**
   * Members 
   */
private:
  /**
   * @brief : Circle shape Object.
   */
  sf::CircleShape* m_Mesh;
  /**
   * @brief : Descriptor Object.
   */
  GIGameObjectDesc m_descriptor;
  /**
   * @brief : 
   */
  GITexture m_texture;
  /**
   * @brief : 
   */
  sf::Vector2f m_position;
  /**
   * @brief : 
   */
  bool m_isColliding = false;
  /**
   * @brief : 
   */
  float m_velocity;
  /**
   * @brief 
   */
  bool m_isOnVortex = false;
  /**
   * @brief 
   */
  bool m_isItemClon;//*@Author :Ramses
  /**
   * Methods 
   */
public:
  /**
    * @brief  : Function that initialize the shape attributes for the actual shape.
    * @param  : GIGameObjectDesc _desc : Description for the shape.
    * @bug    : No known bugs.
    */
  void 
  Init(GIGameObjectDesc _desc);
  /**
    * @brief  : Function in charge of updating the logic information of the shape.
    * @param  : sf::Vector2f _position : Current postion for the game object.
    * @bug    : No known bugs.
    */
  void 
  Update(sf::Vector2f _position);
  /**
    * @brief  : Function that updates the visual shape information.
    * @param  : GIWindow & _window : Window reference from the window class.
    * @bug    : No known bugs.
    */
  void 
  Render(GIWindow & _window);
  /**
    * @brief  : Function in charge of releasing the resources.
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  /**
    * @brief  : Function in charge of setting the radius of the shape.
    * @param  : float _radius : Radius float number.
    * @bug    : No known bugs.
    */
  void setRadius(float _radius);
  /**
   * @brief : 
   */
  float getRadius();
  /**
    * @brief  : Function in charge of setting the position of the shape.
    * @param  : sf::Vector2f _position : Position vector of the shape.
    * @bug    : No known bugs.
    */
  void setPosition(sf::Vector2f _position);
  /**
    * @brief  : Function in charge of setting the origin point of the shape.
    * @param  : sf::Vector2f _origin : Origin point of the shape.
    * @bug    : No known bugs.
    */
  void setOrigin(sf::Vector2f _origin);
  /**
    * @brief  : Function in charge of setting the origin point of the shape.
    * @bug    : No known bugs.
    */
  void setOriginToCenter();
  /**
    * @brief  : Function in charge of setting the color of the shape.
    * @param  : sf::Color _color : Color of the shape.
    * @bug    : No known bugs.
    */
  void setFillColor(sf::Color _color);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  bool & getIsColliding();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void setCollidingState(bool _collidingState);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  bool & getIsOnVortex();
  /**
    * @brief  :
    * @param  :
    * @bug    :
    */
  void setIsOnVortex(bool _vortexState);
  /**
    * @brief  :
    * @param  :
    * @bug    :
    */
  const sf::Vector2f & getPosition();
  /**
    * @brief  : function in charge of getting the global bounds of the shape.
    * @bug    : Does not work, needs new implementation to get the method data.
    */
  const sf::FloatRect & getGlobalBounds();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void setVelocity(float _vel);
  /**
   * @brief : 
   */
  float & getVelocity();
  /**
    * @brief  : Function in charge of getting the descriptor of the class.
    * @bug    : No known bugs.
    */
  GIGameObjectDesc & getDescriptor();
  /**
    * @brief  : Function in charge of getting the circle shape ID.
    * @bug    : No known bugs.
    */
  sf::CircleShape *& getInterface();
  /**
    * @brief  : Function in charge of getting the circle shape ID.
    * @bug    : No known bugs.
    //*@Author :Ramses
    */
  void setIsItemClon(bool _itemClon);
  /**
    * @brief  : Function in charge of getting the circle shape ID.
    * @bug    : No known bugs.
    //*@Author :Ramses
    */
  bool & getIsItemClon();
};

