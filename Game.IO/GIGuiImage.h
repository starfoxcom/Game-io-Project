#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "SFML/Graphics.hpp"

class GIGui;
class GIGuiRect;

struct GIGuiImageDescriptor
{

  /**
  * @brief :where the image will be on the screen.
  */
  sf::Vector2i screenPlacement = sf::Vector2i(0, 0);

  /**
  * @brief : where the image will be in the world.
  */
  sf::Vector2f worldPosition = sf::Vector2f(0.0f, 0.0f);;

  /**
  * @brief :the size of the image.
  */
  sf::Vector2u imageSize = sf::Vector2u(100u, 100u);

  /**
  * @brief : keeps track of what the last size of the image was.
  */
  sf::Vector2u prevImageSize = sf::Vector2u(100u, 100u);

  /**
  * @brief : use to attach a image to a GuiRect (AKA keep it in the same area).
  */
  GIGuiRect* ptr_attached = nullptr;//attached

  /**
  * @brief : used to control the offset when attach to a GuiRect
  */
  sf::Vector2f offSetAttached = sf::Vector2f(0.0f, 0.0f);

  /**
  * @brief : used to identify which GuiImage im using
  */
  std::size_t id = 0u;

  /**
  * @brief : some color to be applied to the current texture.
  */
  sf::Color maskColor = sf::Color(255, 255, 255, 255);
};

  /**
  * @brief :contains a texture and controls how and where
  * it's presented on screen.
  */
class GIGuiImage
{
public:
  GIGuiImage();
  GIGuiImage(const GIGuiImage& other) ;

  GIGuiImage(GIGuiImage&& other)noexcept;
  ~GIGuiImage() = default;
  /**
  * @brief : initializes the GuiImage with all the data it needs.
  * @bug : no known bugs
  */
  bool
  init(const char *pathToFile,
       const GIGuiImageDescriptor& descriptor);

  /**
  * @brief : updates the image's , position , color and size.
  * @bug : no known bugs
  */
  void
  update(sf::RenderWindow& window);

  /**
  * @brief : draw the image .
  * @param[in] guiDraw : does the drawing of the image.
  * @bug : no known bugs
  */
  void 
  draw(GIGui &guiDraw,
       sf::RenderWindow& window);

  /**
  * @brief : changes the size of the image if the parameter is different
  * from the current size.
  * @param[in] newSize : the new size of the image.
  * @bug : no known bugs.
  */
  void 
  changeImageSize(const sf::Vector2u &newSize);
private:

  /**
  * @brief : changes the size of the image and is used internally by
  *          the class.
  * @param[in] newSize : the new size of the image.
  * @bug : no known bugs.
  */
  void 
  Impl_changeImageSize(const sf::Vector2u &newSize);
public:

  sf::Sprite m_sprite;
  // TODO : replace with std::shared_ptr
  std::unique_ptr<sf::Texture> m_texture;

  /**
  * @brief : tell the class how to present the image 
  * and where.
  */
  GIGuiImageDescriptor m_descriptor;
};

