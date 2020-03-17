/**
* @LC : 04 / March / 2020
* @file : GIGui "GIGui.h"
* Author : Yhaliff Said Barraza ( idv17c.ybarraza@uartesdigitales.edu.mx )
* @date : 24 / January / 2020
* @brief : is the Gui class
* @bug : no known bugs
*/
#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <deque>
#include <functional>
#include <cstdint>


#include "GIGuiRect.h"
#include "GIGuiImage.h"

/**
* @brief : will be used to know which events go where
* @bug : no known bugs
*/

struct EventAndID
{
  std::function<int(bool)> m_event;
  std::size_t m_id;

  EventAndID() = default;
  EventAndID(const EventAndID& other) = default;
  EventAndID(EventAndID&& other) = default;

  EventAndID(std::function<int(bool)> lambdaOrFuncPtr, std::size_t newID)
    :m_event(lambdaOrFuncPtr),
    m_id(newID)
  {}
};

/**
* @brief takes care of creating, setting events related with the gui and all
* events must be added as a function pointer or lambda
*/
class GIGui
{
public:
  GIGui();

  ~GIGui() = default;

public:
  /**
  * @brief : this will be used to initialize the Gui.
  * @bug : no known bugs
  */
  bool 
  init(const char* pathToFront);

/**
* @brief : adds a event(aka function) to the gui
* @param[in] lambdaOrFuncPtr : a pointer to a function or lambda
*/
  void 
  addEvent(std::function<int(bool)> functionOrLambda);

/**
* @brief : executes a event if one exist
*/
  int
  executeEvent(bool conditions,std::size_t chosenEvent);

/**
* @returns : if the bottom was clicked.
* @param[in] ButtonPosition : where the button in going to be.
* @param[in] Size : The size of the button.
*/
  bool
  addBottonToWindow(sf::RenderWindow& window,
                    sf::Vector2f& const ButtonPosition,
                    sf::Vector2f Size = sf::Vector2f(100.0f, 100.0f));
/**
* @brief : loads a font for the gui to use.
* @bug  : no known bugs
* @return : if the function was successful
*/
  bool 
  loadFront(const char * pathToFront);

/**
* @brief : puts text on the window
*/
  void 
  placeText(const char *text,
            sf::RenderWindow &window, 
            const sf::Vector2f& position);

/**
* @brief : puts text on the window
*/
  void
  placeColorText( const char *text ,
                 sf::RenderWindow& window,
                 const sf::Vector2f& position,
                 sf::Color color = sf::Color::Black);

/**
* @brief :puts text of different size on the window
*/
  void 
  placeTextSize(const char *text,
                sf::RenderWindow& window,
                const sf::Vector2f& position,
                unsigned int newSize,
                sf::Color color = sf::Color::White);

  /**
  * @brief : places a rect in the given position
  * @bug : no known bugs.
  */
  void
  placeRect(sf::Vector2f Position,
            sf::Vector2f Size,
            sf::RenderWindow& window);

  /**
  * @brief : draw a rectangle. 
  */
  void
  placeColorRect(sf::Vector2f Position,
                 sf::Vector2f Size,
                 sf::RenderWindow& window,
                 sf::Color color = sf::Color::White);
  /**
  * @brief : draws a sprite.
  * @param[in] sprite : the sprite to be drawn.
  * @param[in] position : where the sprite is going to be
  *           drawn.
  * @param[in] window : where the sprite is going to be rendered.
  * @param[in] colorForSprite : modifier of the original color.
  */
  void
  placeSprite(sf::Sprite& sprite, 
              sf::Vector2f& position,
              sf::RenderWindow& window,
              sf::Color& colorForSprite);


/**
* @return the value of the most recently added event ID.
*/
  std::size_t 
  getMostRecenteEventID() const;

/**
* @return a bool that tell you if the gui has a font loaded.
*/
  bool
  getIfFrontIsLoaded() const;

  /**
  * @brief :creates a GIGuiRect instance for use of this class.
  */
  void
  createGuiRect(const GIGuiRectDescriptor& descriptor);


  /**
  * @brief :creates a GIGuiImage instance for use of this class.
  * @returns : if the function successfully created a GuiImage.
  */
  bool
  createGuiImage(const GIGuiImageDescriptor& descriptor,
                 const char* pathToFile);

  /**
  * @brief : draw the elements on screen 
  * @bug : no known bugs.
  */
  void 
  DrawGuiRects(sf::RenderWindow& window );

  /**
  * @brief : draw the elements on screen 
  * @bug : no known bugs.
  */
  void 
  DrawGuiImages(sf::RenderWindow& window );

  /**
  * @brief : draws every element of the gui.
  * @bug : no known bugs.
  */
  void
  Draw(sf::RenderWindow& window);

  /**
  * @brief : updates them so that you can change the rect during run-time.
  * @bug : no known bugs.
  */
  void
  UpdateGuiRects(sf::RenderWindow& window);


  /**
  * @brief : updates them so that you can variable of the image and it changes 
  * during run-time.
  * @bug : no known bugs.
  */
  void 
  UpdateGuiImages(sf::RenderWindow& window);

  /**
  * @brief : call each update function individually.
  * @bug : no known bugs.
  */
  void 
  update(sf::RenderWindow& window);

  /**
  * @return : a pointer to a specific instance of a GuiRect or 
  * nullptr if no instance is found.
  * @bug : no known bugs.
  */
  GIGuiRect*
  getGuiRecPtrByID(std::size_t id);


  /**
  * @return : a pointer to a specific instance of a GuiImage or 
  * nullptr if no instance is found.
  * @bug : no known bugs.
  */
  GIGuiImage*
  getGuiImagePtrByID(std::size_t id);

private:
/**
* @brief : takes care of moving the position of the text
*/
  void 
  moveAndSetText(const sf::Vector2f& position,
                 const char* text);
/**
* @brief :move a rectangle to a position relative to world-space.
*/
  void
  moveAndSetRect(sf::RectangleShape &rectShape,
                 const sf::Vector2f& Position,
                 const sf::Vector2f& Size);

  /**
  * @brief : move a sprite to a position relative to world-space.
  * @bug :no known bugs.
  */
  void
  moveAndSetSprite(sf::Sprite& sprite,
                   const sf::Vector2f& position);
public:
  /**
  * @brief : contains all the GuiRects instances and it's 
  * a std::deque so it's safe to have a pointer to a individual 
  * instance of the GIGuiRect
  */
  std::deque<GIGuiRect> m_guiRects;

  /**
  * @brief : contains all the GuiImages instances and it's 
  * a std::deque so it's safe to have a pointer to a individual 
  * instance of the GuiImage
  */
  std::deque<GIGuiImage> m_guiImages;
private:
  std::vector<EventAndID> m_events;

/**
* @brief : the font of the text
*/
  sf::Font m_font;

/**
* @brief :this represents the text that will be in the window
*/
  sf::Text m_text;

/**
* @brief : this is the string the member 'm_text' is going to use for it messages
*/
  sf::String m_String;

  /**
  * @brief : keep track of latest available id for a guiRect.
  */
  std::size_t m_guiRectIDCount = 0u;

  /**
  * @brief : keep track of latest available id for a guiImage.
  */
  std::size_t m_guiImageIDCount = 0u;

  /**
  * @brief : used to know if we have a font loaded
  */
  bool m_hasFontLoaded = false;
};


