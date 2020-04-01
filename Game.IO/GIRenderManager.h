/**
 * @LC	   : 25/01/2020
 * @file   : GIRenderManager.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 25/01/2020
 * @brief  : Class in charge of setting the main loop of the game.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "GIDefines.h"
#include "GIWindow.h"
#include "GIGameObject.h"
#include "GITexture.h"
#include "GICamera.h"
#include "GIEventSystem.h"
#include "GIGraphic_API.h"
#include "GISteeringBehaviors.h"
#include "GIInputManager.h"
#include "GIGui.h"
#pragma once

/**
 * @brief : Class in charge of setting the main loop of the game.
 */
class GIRenderManager
{
public:
  GIRenderManager();
  ~GIRenderManager();
  /**
   * Members 
   */
private:
  /**
   * @brief : Window Object
   */
  GIWindow m_window;
  /**
   * @brief : 
   */
  GICamera m_Camera;
  /**
   * @brief : Player Object
   */

  GIGameObject m_Player;
  GIGameObject m_son;

   /**
   * @brief : Clon game object vector
    * @Author : Ramses Guerrero A.
   */
  vector<GIGameObject> m_ItemClon;
  bool m_IsItemClon;
  GIInputManager m_InputManager;
  /**
   * @brief : Food game object vector
   */
  vector<GIGameObject> m_food;
  /**
   * @brief : 
   */
  vector<GIGameObject> m_virus;

  /**
  * @brief : takes care drawing the gui U,I one screen.
  * @bug : no known bugs 
  */
  GIGui m_gui;
  /**
   * @brief :
   */
  vector<GIGameObject> m_vortexVirus;
  /**
   * @brief : Background object
   */
  //sf::RectangleShape * m_background;
  /**
   * @brief : Background Texture
   */
  GITexture m_backgroundTexture;
  /**
   * @brief : 
   */
  GIEventSystem m_EventSystem;
  /**
   * @brief : 
   */
  float m_radius;

  /**
  * @brief : controls if the main menu is being 
  * rendered.
  */
  bool m_isMainMenuPresent = true;

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
    * @brief  : Function that return the window interface.
    * @bug    : No know bugs.
    */
  sf::RenderWindow *& getWindow();
};

