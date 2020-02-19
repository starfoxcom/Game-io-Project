/**
 * @LC	   : 25/01/2020
 * @file   : GIGraphic_API.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 25/01/2020
 * @brief  : Manager in charge of setting all the resources and structures
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "GIDefines.h"
#include "GIModule.h"
#pragma once
/**
 * Forward Class Declaration 
 */
class GIWindow;
class GITexture;

/**
 * @brief : Manager in charge of setting all the resources and structures
 */
class GIGraphic_API : public GIModule<GIGraphic_API>
{
public:
  GIGraphic_API();
  ~GIGraphic_API();
  /**
   * Members 
   */
private:
  /**
   * @brief : Event Object
   */
  sf::Event m_Event;
  /**
   * Methods 
   */
  public:
    /**
   * @brief  : Function that initialize the module.
   * @bug    : No know bugs.
   */
    virtual void onPrepare() override {}
    /**
      * @brief  : Function in charge of release modules.
      * @bug    : No know bugs.
      */
    virtual void onShutDown() override {}
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Init();
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
  Render();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  /**
    * @brief  : Function in charge of initializing the window.
    * @param  : GIWindow & _window : Window reference.
    * @bug    : No known bugs.
    */
  void CreateSFMLWindow(GIWindow & _window);
  /**
    * @brief  : Function in charge of cleaning the current frame.
    * @param  : GIWindow & _window : Window reference.
                sf::Color _clearColor : Clear color.
    * @bug    : No known bugs.
    */
  void Clear(GIWindow & _window, sf::Color _clearColor);
  /**
    * @brief  : Function in charge of presenting the new frame.
    * @param  : GIWindow & _window : Reference to the window object. 
    * @bug    : No known bugs.
    */
  void Present(GIWindow & _window);
  /**
    * @brief  : Function in charge of initializing a texture.
    * @param  : GITexture & _texture : Texture reference of the object.
    * @bug    : No known bugs.
    */
  void CreateTexture(GITexture & _texture);
  /**
  * @brief  : Function in charge of compare a range of numbers.
  * @param  : float _x : Range to compare
              float _y : Interval 1
              float _z : Interval 2
  * @bug    : This function must be on math class
  */
  bool inRange(float _x, float _y, float _z);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  sf::Event & getEventInterface();
};

