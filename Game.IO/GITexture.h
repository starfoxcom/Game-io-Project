/**
 * @LC	   : 25/01/2020
 * @file   : GITexture.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 25/01/2020
 * @brief  : Class in charge of providing a texture resource.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "GIDefines.h"
#include "GIGraphic_API.h"
#pragma once
/**
 * @brief : Class descriptor 
 */
struct GITextureDesc
{
  const char* FileName;
};

/**
 * @brief : Class in charge of providing a texture resource.
 */
class GITexture
{
public:
  GITexture();
  ~GITexture();
  /**
   * Members 
   */
private:
  /**
   * @brief : Texture ID
   */
  sf::Texture m_ID;
  /**
   * @brief : Descriptor object
   */
  GITextureDesc m_descriptor;
  /**
   * Methods 
   */
public:
  /**
    * @brief  : Function in charge of initialize the texture.
    * @param  : GITextureDesc _desc : descriptor structure for the 
                initialization of the texture object.
    * @bug    : No known bugs.
    */
  void 
  Init(GITextureDesc _desc);
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
  GITextureDesc & getDescritor();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  sf::Texture & getInterface();
};

