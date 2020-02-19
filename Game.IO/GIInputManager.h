/**
 * @LC	   : //2020
 * @file   : 
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : //2020
 * @brief  : 
 * @bug	   : No known bugs.
 */

/**
 * @brief : 
 */
#include "GIDefines.h"
#include "GIModule.h"
#pragma once
/**
 * Forward class declarations 
 */
class GIWindow;
class GICamera;
/**
 * @brief : 
 */
class GIInputManager : public GIModule<GIInputManager>
{
public:
  GIInputManager();
  ~GIInputManager();
  /**
   * Members 
   */
private:

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
    * @brief  :
    * @param  :
    * @bug    :
    */
  sf::Vector2f &
  getMousePosition(GIWindow & _window);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  sf::Vector2f & 
  getWorldPosition(GIWindow & _window, GICamera & _camera);
};

