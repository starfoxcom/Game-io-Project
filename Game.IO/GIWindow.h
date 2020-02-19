/**
 * @LC	   : 25/01/2020
 * @file   : GIWindow.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 25/01/2020
 * @brief  : Class in charge of creating a window.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "GIDefines.h"
#include "GIGraphic_API.h"
#pragma once
/**
 * @brief : Window descriptor
 */
struct GIWindowDesc
{
  int Width;
  int Height;
  const char * WndName;
};

/**
 * @brief : Class in charge of creating a window.
 */
class GIWindow
{
public:
  GIWindow();
  ~GIWindow();
  /**
   * Members 
   */
private:
  /**
   * @brief : Window ID object.
   */
  sf::RenderWindow* m_ID;
  /**
   * @brief : Descriptor Object.
   */
  GIWindowDesc m_descriptor;
  /**
   * Methods 
   */
  public:
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void
  Init(GIWindowDesc _Desc);
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
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  GIWindowDesc & getDescriptor();
  /**
  * @brief  :
  * @param  :
  * @bug    : No known bugs.
  */
  sf::RenderWindow *& getInterface();
};

