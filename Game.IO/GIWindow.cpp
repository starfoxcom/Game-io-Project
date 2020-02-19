#include "GIWindow.h"



GIWindow::GIWindow()
{
}


GIWindow::~GIWindow()
{
}

void GIWindow::Init(GIWindowDesc _Desc)
{
  m_descriptor = _Desc;

  GIGraphic_API::getSingleton().CreateSFMLWindow(*this);
}

void GIWindow::Update()
{

}

void GIWindow::Render()
{

}

void GIWindow::Destroy()
{
  if (m_ID != nullptr)
  {
    delete m_ID;
  }
}

GIWindowDesc & GIWindow::getDescriptor()
{
  return m_descriptor;
}

sf::RenderWindow *& GIWindow::getInterface()
{
  return m_ID;
}
