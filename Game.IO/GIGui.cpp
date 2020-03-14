#include "GIGui.h"
#include <iostream>
#include <fstream>

// prints out a message with a solution
auto errorMessageWithSolution = []
(const char* msg, const char* solution) {std::cerr << msg << '\'' << solution << '\'' << '\n'; };

GIGui::GIGui()
{}

bool
GIGui::init(const char* pathToFront)
{
  bool isSuccesful = loadFront(pathToFront);
  if( !isSuccesful )
    return false;

  return true;
}

void
GIGui::addEvent(std::function<int(bool)>  functionOrLambda)
{
  m_events.push_back(EventAndID(functionOrLambda, m_events.size()));
}

int
GIGui::executeEvent(bool conditions, std::size_t chosenEvent)
{
  auto Iter = std::find_if(m_events.begin(),
                           m_events.end(),
                           [chosenEvent](EventAndID& element) { return element.m_id == chosenEvent; });

  if( Iter != m_events.end() )
  {
    return  Iter->m_event(conditions);
  }

  return -1337;
}

bool
GIGui::addBottonToWindow(sf::RenderWindow& window,
                         sf::Vector2i mousePosition,
                         sf::Vector2f ButtonPosition,
                         sf::Vector2f Size)

{
  sf::Rect<float> logicRect(ButtonPosition, Size);
  sf::RectangleShape visualRect(ButtonPosition);
  bool result = false;

  visualRect.setSize(Size);
  visualRect.setFillColor(sf::Color::Green);
  visualRect.setPosition(ButtonPosition);

  //
  if( logicRect.contains(static_cast<sf::Vector2f>(mousePosition))
     && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) )
  {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    visualRect.setFillColor(sf::Color::Red);
    result = true;
  }
  window.draw(visualRect);

  return result;
}

bool
GIGui::loadFront(const char* pathToFront)
{

  if( m_font.loadFromFile(pathToFront) )
  {
    m_text.setFont(m_font);
    m_hasFontLoaded = true;
    return true;
  }
  else
  {
    std::cerr << "error with path = \'" << pathToFront << "\'\n";
    return false;
  }

}

void
GIGui::placeText(const char* text,
                 sf::RenderWindow& window,
                 const sf::Vector2f& position)
{
  if( m_hasFontLoaded )
  {
    this->moveAndSetText(position, text);

    window.draw(m_text);

    m_String.clear();
  }
  else
  {
    errorMessageWithSolution("gui has no font loaded ", " please use the function 'loadFront' ");
  }
}


void
GIGui::placeColorText(const char* text,
                      sf::RenderWindow& window,
                      const sf::Vector2f& position,
                      sf::Color color)
{
  if( m_hasFontLoaded )
  {
    this->moveAndSetText(position, text);

    m_text.setFillColor(color);

    window.draw(m_text);
    m_String.clear();
    // reset the text color back to white
    m_text.setFillColor(sf::Color::White);
  }
  else
  {
    errorMessageWithSolution("gui has no font loaded ", " please use the function 'loadFront' ");
  }
}

void
GIGui::placeTextSize(const char* text,
                     sf::RenderWindow& window,
                     const sf::Vector2f& position,
                     unsigned int newSize,
                     sf::Color color)
{
  if( m_hasFontLoaded )
  {
    this->moveAndSetText(position, text);
    unsigned int originalSize = m_text.getCharacterSize();
    m_text.setCharacterSize(newSize);
    m_text.setFillColor(color);

    window.draw(m_text);
    m_text.setCharacterSize(originalSize);
    m_text.setFillColor(sf::Color::White);

    m_String.clear();
  }
  else
  {
    errorMessageWithSolution("gui has no font loaded please use the function ", "loadFront");
  }
}

void
GIGui::placeRect(sf::Vector2f Position,
                 sf::Vector2f Size,
                 sf::RenderWindow& window)
{
  sf::RectangleShape visualRect;
  this->moveAndSetRect(visualRect, Position, Size);
  visualRect.setFillColor(sf::Color::Green);

  window.draw(visualRect);
}

void
GIGui::placeColorRect(sf::Vector2f Position,
                      sf::Vector2f Size,
                      sf::RenderWindow& window,
                      sf::Color color)
{
  sf::RectangleShape visualRect;
  this->moveAndSetRect(visualRect, Position, Size);
  visualRect.setFillColor(color);

  window.draw(visualRect);
}


void
GIGui::placeSprite(sf::Sprite& sprite,
                   sf::Vector2f& position,
                   sf::RenderWindow& window,
                   sf::Color& colorForSprite)
{
  this->moveAndSetSprite(sprite, position);
  sprite.setColor(colorForSprite);
  window.draw(sprite);
}

std::size_t
GIGui::getMostRecenteEventID() const
{
  return m_events[m_events.size() - 1].m_id;
}

bool
GIGui::getIfFrontIsLoaded() const
{
  return m_hasFontLoaded;
}

void 
GIGui::createGuiRect(const GIGuiRectDescriptor& descriptor)
{
  m_guiRects.push_back(descriptor);
  auto const index = m_guiRects.size() - 1;
  m_guiRects[index].m_descriptor.id = m_guiRectIDCount++;
}

bool
GIGui::createGuiImage(const GIGuiImageDescriptor& descriptor,
                      const char* pathToFile)
{
  GIGuiImage newImage;
  bool const isSuccessful = newImage.init(pathToFile, descriptor);
  if( isSuccessful )
  {
    m_guiImages.emplace_back(std::move(newImage));
    auto const index = m_guiImages.size() - 1;
    m_guiImages[index].m_descriptor.id = m_guiImageIDCount++;
    return isSuccessful;
  }
  return isSuccessful;

}

void 
GIGui::DrawGuiRects(sf::RenderWindow& window)
{
  for( auto& element : m_guiRects )
  {
    element.draw(*this,&window);
  }
}

void 
GIGui::DrawGuiImages(sf::RenderWindow& window)
{

  for( GIGuiImage& image : m_guiImages )
  {
    image.draw(*this, window);
  }

}

void 
GIGui::UpdateGuiRects(sf::RenderWindow& window)
{
  for( auto& guiRect : m_guiRects )
  {
    guiRect.update(&window);
  }
}

void 
GIGui::UpdateGuiImages(sf::RenderWindow& window)
{
  for( GIGuiImage& image : m_guiImages )
  {
    image.update(window);
  }
}

void 
GIGui::update(sf::RenderWindow& window)
{
  this->UpdateGuiRects(window);
  this->UpdateGuiImages(window);
}

void
GIGui::moveAndSetText(const sf::Vector2f& position,
                      const char* text)
{
 //sf::Vector2f offset = Transform.transformPoint(position);
  //sf::Vector2f finalPosition = offset; //+ position;
  m_text.setPosition(position);

  std::string temp(text);

  m_String += temp;
  m_text.setString(m_String);
}

void
GIGui::moveAndSetRect(sf::RectangleShape& rectShape,
                      const sf::Vector2f& Position,
                      const sf::Vector2f& Size)
{
  rectShape.setPosition(Position);
  rectShape.setSize(Size);

}

void 
GIGui::moveAndSetSprite(sf::Sprite& sprite,
                        const sf::Vector2f& position)
{
  sprite.setPosition(position);

}

GIGuiRect* 
GIGui::getGuiRecPtrByID(std::size_t id)
{

  for( GIGuiRect& result : m_guiRects )
  {
    if(result.m_descriptor.id == id)
     return &result; 
  }

  return nullptr;
}

GIGuiImage*
GIGui::getGuiImagePtrByID(std::size_t id)
{

  for( GIGuiImage& result : m_guiImages)
  {
    if(result.m_descriptor.id == id)
     return &result; 
  }
  return nullptr;
}



