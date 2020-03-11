/**
 * @LC	   : 04/march/2020
 * @file   : GIGuiRect.h
 * @Author : Yhaliff Barraza (idv17c.ybarraza@uartesdigitales.edu.mx)
 * @date   : 26/feb/2020
 * @brief  : represents a rectangle where a GUI can be placed relative
 *         to the screen can also make sure elements are drawn in the 
 *         right order ( aka make the background first ).
 * @bug	   : No known bugs.
 */
#pragma once
#include <iostream>
#include <cstdint>
#include <string>
#include "SFML/Graphics.hpp"

  /**
  * Forward declarations
  */
class GIGui;

  /**
  * @brief : describes the elements that will be drawn inside the
  *          GIGuiRect
  */
struct GIGuiRectDescriptor
{

  /**
  * @brief : this contains the text that will be drawn on the GuiRect
  */
  std::string text = "";

  /**
  * @brief : normalized coordinates for controlling the placement of text in the GuiRect
  *          any value within 1.0f - 0.0f will start placing the text in the GuiRect 
  */
  sf::Vector2f InRectPlacementPercentage = sf::Vector2f(0.0f, 0.0f);

  /**
  * @brief : controls where the GuiRect will be relative to the screen.
  */
  sf::Vector2i screenPlacement = sf::Vector2i(0, 0);

  /**
  * @brief : used to determine the width and height of the GuiRect
  */
  sf::Vector2f widthAndHeight = sf::Vector2f(100,100);

  /**
  * @brief : this is the color of the text 
  */
  sf::Color textColor = sf::Color::Black;

  /**
  * @brief : the color of the rectangle.
  */
  sf::Color rectColor = sf::Color::White;

  unsigned int CustomSizeForText = 70u;

  bool isTextCustomSize = false;
};

/**
* @brief : creates some area for drawing more element in order.
*          in other words first the rectangle is drawn then the text is next.
* @bug : no known bugs.
*/
class GIGuiRect
{
public:// constructors 
//descriptor
  GIGuiRect(const GIGuiRectDescriptor& decriptor);
  GIGuiRect(const GIGuiRect& other) = default;
  GIGuiRect(GIGuiRect&& other) = default;
  GIGuiRect() = default;
  ~GIGuiRect() = default;

public:// operators 

  GIGuiRect& operator =(const GIGuiRect& other) = default;
  GIGuiRect& operator =(GIGuiRect&& other) = default;
public:

  /**
  * @returns : a rect from the sfml library using the variables from inside the class.
  * @bug : no known bugs
  */
  sf::RectangleShape
  getRectRepresentation() const;

  /**
  * @returns: the position of where the rectangle is in world space.
  * @bug : no known bugs
  */
  sf::Vector2f
  getScreenPosition(sf::RenderWindow* window) const;

  /**
  * @returns :a position inside the rectangle in world space
  * @bug : no known bugs.
  */
  sf::Vector2f
  getPositionInRect(sf::RenderWindow* window,
                    float offSetPercentageInX = 0.0f,
                    float offSetPercentageInY = 0.0f) const;

  /**
  * @returns the width and height of the rectangle 
  * @bug : no known bugs
  */
  sf::Vector2f
  getSize() const;

  /**
  * @brief : controls the ,position ,size and text that the GuiRect will display.
  * @param[in] descriptor : controls what the GuiRect displays and where it is displayed.
  * @bug : no known bugs.
  */
  void
  init(sf::RenderWindow* window,
       const GIGuiRectDescriptor& descriptor);

  /**
  * @brief : updates all the elements of the GuiRect
  * @param[in] window: used to get the relative position of the rectangle
  *           to the screen.
  * @bug : no known bugs
  */
  void
  update(sf::RenderWindow* window);

  /**
  * @brief : draw the Rectangle and text that come with it.
  * @bug : no known bugs
  */
  void 
  draw(GIGui& guiDraw,
       sf::RenderWindow* window) const;

  /**
  * @brief : calculates the offset determined by 'InRectPlacementPercentage' from
  *          GIGuiRectDescriptor. 
  * @bug :no known bug.
  */
  sf::Vector2f
  caculateOffSet() const;



private:
  /**
  * @brief : the entity that gets drawn.
  */
  sf::RectangleShape m_shapeOfRect;
public:

  /**
  * @brief :controls the characteristics of the GIGuiRect
  */
  GIGuiRectDescriptor m_descriptor;
};

