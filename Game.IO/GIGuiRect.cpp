#include "GIGuiRect.h"
#include "GIGui.h"


GIGuiRect::GIGuiRect(const GIGuiRectDescriptor& decriptor)
{
  m_descriptor = decriptor;
  m_shapeOfRect.setSize(m_descriptor.widthAndHeight);
  m_shapeOfRect.setOrigin(m_descriptor.widthAndHeight *.5f);
  m_shapeOfRect.setFillColor(m_descriptor.rectColor);
}

sf::RectangleShape
GIGuiRect::getRectRepresentation() const
{
  return m_shapeOfRect;
}

sf::Vector2f
GIGuiRect::getScreenPosition(sf::RenderWindow* window) const
{
  sf::Vector2f result = window->mapPixelToCoords(m_descriptor.screenPlacement,
                                                 window->getView());

  return  result;
}

sf::Vector2f 
GIGuiRect::getPositionInRect(sf::RenderWindow* window,
                             float offSetPercentageInX,
                             float offSetPercentageInY) const
{
  sf::Vector2f const result = window->mapPixelToCoords(m_descriptor.screenPlacement,
                                                       window->getView());

  float const offSetInX = m_descriptor.widthAndHeight.x * offSetPercentageInX;
  float const offSetInY = m_descriptor.widthAndHeight.y * offSetPercentageInY;

  sf::Vector2f const offSetInRect(offSetInX, offSetInY);

  return  result + offSetInRect;
}

sf::Vector2f 
GIGuiRect::getSize() const
{
  return m_descriptor.widthAndHeight;
}

void 
GIGuiRect::init(sf::RenderWindow* window,
                const GIGuiRectDescriptor& descriptor)
{
   this->m_descriptor = descriptor;
   update(window);
}


void 
GIGuiRect::update(sf::RenderWindow* window)
{
  m_shapeOfRect.setFillColor(m_descriptor.textColor);
  m_shapeOfRect.setSize(m_descriptor.widthAndHeight);
  sf::Vector2f const positionInWorldSpace = this->getScreenPosition(window);
  m_shapeOfRect.setPosition(positionInWorldSpace);
}

void
GIGuiRect::draw(GIGui& guiDraw,
                sf::RenderWindow* window) const
{

  guiDraw.placeColorRect(m_shapeOfRect.getPosition(),
                         m_shapeOfRect.getSize(),
                         *window,
                         m_descriptor.rectColor);

  sf::Vector2f const textWorldPosition = this->getScreenPosition(window);
  sf::Vector2f const textOffSet = this->caculateOffSet();

  if( m_descriptor.isTextCustomSize == false )
  {
    guiDraw.placeColorText(m_descriptor.text.c_str(),
                           *window,
                           (textWorldPosition)+textOffSet,
                           m_descriptor.textColor);
  }
  else
  {
    guiDraw.placeTextSize(m_descriptor.text.c_str(),
                          *window,
                          (textWorldPosition)+textOffSet,
                          m_descriptor.CustomSizeForText,
                          m_descriptor.textColor);
  }

}

sf::Vector2f
GIGuiRect::caculateOffSet() const
{
  const float offSetInX = m_descriptor.InRectPlacementPercentage.x * m_descriptor.widthAndHeight.x;
  const float offSetInY = m_descriptor.InRectPlacementPercentage.y * m_descriptor.widthAndHeight.y;
  return sf::Vector2f(offSetInX, offSetInY);
}

