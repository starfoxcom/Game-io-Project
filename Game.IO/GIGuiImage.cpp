#include "GIGuiImage.h"
#include "GIGui.h"


GIGuiImage::GIGuiImage()
{
  m_texture = std::make_unique<sf::Texture>();
}

GIGuiImage::GIGuiImage(const GIGuiImage& other)
  :GIGuiImage()
{
  m_texture->loadFromImage(other.m_texture->copyToImage());
  m_sprite = other.m_sprite;
  m_sprite.setTexture(*m_texture);
  m_descriptor = other.m_descriptor;
  this->changeImageSize(m_descriptor.imageSize);
}

GIGuiImage::GIGuiImage(GIGuiImage&& other) noexcept
  :m_texture(std::move(other.m_texture)),
  m_sprite(other.m_sprite),
  m_descriptor(std::move(other.m_descriptor))
{
  m_sprite.setTexture(*m_texture);
  this->changeImageSize(m_descriptor.imageSize);
}


bool
GIGuiImage::init(const char* pathToFile,
                 const GIGuiImageDescriptor& descriptor)
{

  if( m_texture->loadFromFile(pathToFile) == false )
  {
    return false;
  }

  this->m_descriptor = descriptor;

  m_sprite.setTexture(*m_texture);

  m_sprite.setColor(m_descriptor.maskColor);

  this->changeImageSize(m_descriptor.imageSize);

  return true;
}

void
GIGuiImage::update(sf::RenderWindow& window)
{
  if( m_descriptor.prevImageSize != m_descriptor.imageSize )
  {
    this->changeImageSize(m_descriptor.imageSize);
  }

  m_descriptor.worldPosition = window.mapPixelToCoords(m_descriptor.screenPlacement);

  m_sprite.setColor(m_descriptor.maskColor);
}


void
GIGuiImage::draw(GIGui& guiDraw,
                 sf::RenderWindow& window)
{
  guiDraw.placeSprite(m_sprite,
                      m_descriptor.worldPosition,
                      window,
                      m_descriptor.maskColor);
}

void
GIGuiImage::changeImageSize(const sf::Vector2u& newSize)
{
  m_descriptor.prevImageSize = m_descriptor.imageSize;
  m_descriptor.imageSize = newSize;
  this->Impl_changeImageSize(newSize);
}

void
GIGuiImage::Impl_changeImageSize(const sf::Vector2u& newSize)
{
  sf::IntRect const ImageRectangle = m_sprite.getTextureRect();

  float const reciprocalWidth = (1.0f / static_cast<float>(ImageRectangle.width));
  float const reciprocalHeight = (1.0f / static_cast<float>(ImageRectangle.height));

  float const newScaleInX = reciprocalWidth * newSize.x;
  float const newScaleInY = reciprocalHeight * newSize.y;

  m_sprite.setScale(newScaleInX,
                    newScaleInY);

  m_sprite.setOrigin((ImageRectangle.width * reciprocalWidth) * .5f,
    (ImageRectangle.height * reciprocalHeight) * .5f);

}
