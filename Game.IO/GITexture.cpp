#include "GITexture.h"



GITexture::GITexture()
{
}


GITexture::~GITexture()
{
}

void GITexture::Init(GITextureDesc _desc)
{
  m_descriptor = _desc;

  GIGraphic_API::getSingleton().CreateTexture(*this);
}

GITextureDesc & GITexture::getDescritor()
{
  return m_descriptor;
}

sf::Texture & GITexture::getInterface()
{
  return m_ID;
}
