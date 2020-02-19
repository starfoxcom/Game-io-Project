/**
 * @LC	   : //2020
 * @file   : 
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : //2020
 * @brief  : 
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "GIDefines.h"
#include "GIModule.h"
#pragma once
/**
 * Forward class declarations
 */
class GIGameObject;
/**
 * @brief : 
 */
class GISteeringBehaviors : public GIModule<GISteeringBehaviors>
{
public:
  GISteeringBehaviors();
  ~GISteeringBehaviors();
  /**
   * Members 
   */
private:
  /**
   * @brief : 
   */
  float m_velocity;
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
  sf::Vector2f Seek(GIGameObject & _object1, GIGameObject & _object2);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  sf::Vector2f Seek(sf::Vector2f & _object1, GIGameObject & _object2);
};

