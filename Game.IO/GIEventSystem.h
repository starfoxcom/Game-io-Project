/**
 * @LC	   : 26/01/2020
 * @file   : GIEventSystem.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 26/01/2020
 * @brief  : Class in charge of setting the global events of the game,
             this class must be a module or manager for her proper function.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "GIDefines.h"
#include "GIGraphic_API.h"
#pragma once
/**
 * Forward Class Declarations 
 */
class GIGameObject;
class GIWindow;
/**
 * @brief : Class in charge of setting the global events of the game,
            this class must be a module or manager for her proper function.
 */
class GIEventSystem
{
public:
  GIEventSystem();
  ~GIEventSystem();
  /**
   * Members 
   */
private:
  /**
   * @brief : 
   */
  float m_radius;

  int m_vortexCDTimer; /**< Vortex cool down timer*/

  int m_vortexUsageTimer; /**< Vortex usage timer.*/
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
  Init(GIGameObject & _player);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Update(GIGameObject & _player, vector<GIGameObject> & _food, vector<GIGameObject> & _enemies, vector<GIGameObject> & _vortex);
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
    * @brief  : Function that checks if the player has a collision 
                with the food game object.
    * @param  : GIGameObject & _player : Player reference object.
                vector<GIGameObject> & _food : Food vector reference object.
    * @bug    : no know bugs.
    */
  void 
  playerRadius(GIGameObject & _player, vector<GIGameObject> & _food, vector<GIGameObject> & _enemies);

  /**
   * @brief	 :
   * @param	 :
   */
  void
  vortexRadius(GIGameObject & _player, vector<GIGameObject> & _vortex);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void 
  playerVelocity(GIGameObject & _player);

};

