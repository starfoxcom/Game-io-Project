#include "GIRenderManager.h"


GIRenderManager::GIRenderManager()
{}

GIRenderManager::~GIRenderManager()
{}

void GIRenderManager::Init()
{
   // deltaTime = new float(0);
    
  GIWindowDesc WindowDesc;
  WindowDesc.Width = 1200;
  WindowDesc.Height = 800;
  WindowDesc.WndName = "Game.io";

  GIGameObjectDesc GameObjectDesc;
  GameObjectDesc.Radius = 20.0f;
  GameObjectDesc.Velocity = 20.0f;
  GameObjectDesc.Color = sf::Color::Green;
  GameObjectDesc.Origin = sf::Vector2f(20, 20);
  GameObjectDesc.OutlineSize = 2;
  GameObjectDesc.OutlineColor = sf::Color::Transparent;
  GameObjectDesc.TextureName = "evil.png";
  GameObjectDesc.DeltaTime = &deltaTime;

  GIGameObjectDesc SonDesc;
  SonDesc.Radius = 20.0f;
  SonDesc.Velocity = 4.0f;
  SonDesc.Color = sf::Color::Green;
  SonDesc.Origin = sf::Vector2f(20, 20);
  SonDesc.OutlineSize = 2;
  SonDesc.OutlineColor = sf::Color::Transparent;
  SonDesc.TextureName = "evil.png";
  SonDesc.DeltaTime = &deltaTime;

  GIGameObjectDesc FoodDesc;
  FoodDesc.Radius = 8.0f;
  FoodDesc.OutlineSize = 2;
  FoodDesc.Origin = sf::Vector2f(8, 8);
  FoodDesc.OutlineColor = sf::Color::Transparent;
  FoodDesc.TextureName = nullptr;

  GIGameObjectDesc ClonDesc; //*@Author :Ramses
  ClonDesc.Radius = 15.0f;
  ClonDesc.OutlineSize = 4;
  ClonDesc.OutlineColor = sf::Color::Transparent;
  ClonDesc.TextureName = "Clon.png";

  GIGameObjectDesc VirusDesc;
  VirusDesc.Radius = 50.0f;
  VirusDesc.OutlineSize = 0;
  VirusDesc.Origin = sf::Vector2f(50, 50);
  VirusDesc.OutlineColor = sf::Color::White;
  VirusDesc.TextureName = "virus.png";

  //Vortex virus desc
  GIGameObjectDesc VortexDesc;
  VortexDesc.Radius = 50.0f;
  VortexDesc.OutlineSize = 0;
  VortexDesc.Color = sf::Color::Magenta;
  VortexDesc.Origin = sf::Vector2f(50, 50);
  VortexDesc.OutlineColor = sf::Color::Transparent;
  VortexDesc.TextureName = nullptr;

  GITextureDesc GridTextureDesc;
  GridTextureDesc.FileName = "grid2.png";

  GICameraDesc CameraDesc;
  CameraDesc.width = WindowDesc.Width;
  CameraDesc.height = WindowDesc.Height;
  CameraDesc.MinZoom = 0.8f;
  CameraDesc.MaxZoom = 1.2f;
  CameraDesc.MoveSpeed = 0.50f;
  CameraDesc.Position = sf::Vector2f(0, 0);

  m_Camera.Init(CameraDesc);

  for (int i = 0; i < 40; i++) {//*@Author :Ramses, clon

      GIGameObject tmpClon;
      m_ItemClon.push_back(tmpClon);
  }

  if( !m_gui.init("resources/SatellaRegular-ZVVaz.ttf") )
  {
    std::cerr << "failed to load font " << std::endl;
  }

  {
    GIGuiRectDescriptor CenterWindowDesc;
    CenterWindowDesc.rectColor = sf::Color::White;
    CenterWindowDesc.textColor = sf::Color::Black;
    float const tempWidth = CenterWindowDesc.widthAndHeight.x = 250;
    float const tempHeight = CenterWindowDesc.widthAndHeight.y = 250;
    CenterWindowDesc.InRectPlacementPercentage.x = 0.05f;
    CenterWindowDesc.InRectPlacementPercentage.y = 0.09f;
    CenterWindowDesc.screenPlacement = sf::Vector2i((WindowDesc.Width * .5f) - tempWidth / 2,
      (WindowDesc.Height * .25f) - tempHeight / 2);
    CenterWindowDesc.text = "Game.IO";
    CenterWindowDesc.CustomSizeForText = 65u;
    CenterWindowDesc.isTextCustomSize = true;
    m_gui.createGuiRect(CenterWindowDesc);
  }

  {
    GIGuiRectDescriptor  PlayerWindow;
    PlayerWindow.rectColor = sf::Color::White;
    PlayerWindow.textColor = sf::Color::Black;
    float const tempWidth = PlayerWindow.widthAndHeight.x = 250;
    float const tempHeight = PlayerWindow.widthAndHeight.y = 250;
    PlayerWindow.InRectPlacementPercentage.x = 0.05f;
    PlayerWindow.InRectPlacementPercentage.y = 0.70f;
    PlayerWindow.screenPlacement = sf::Vector2i((WindowDesc.Width * .13f),// - tempWidth / 2,
      (WindowDesc.Height * .10f)); //- tempHeight / 2);
    PlayerWindow.text = "player";
    m_gui.createGuiRect(PlayerWindow);
  }

  {
    GIGuiRect* const ptr_rect = m_gui.getGuiRecPtrByID(1u);
    GIGuiImageDescriptor imageDescritor;
    imageDescritor.ptr_attached = ptr_rect;
    imageDescritor.offSetAttached = sf::Vector2f(0.3f, 0.3f);
    m_gui.createGuiImage(imageDescritor, "aer.png");
  }

  for( int i = 0; i < 850; i++ )
  {
    GIGameObject tmpFood;
    m_food.push_back(tmpFood);
  }

  for( int i = 0; i < 15; i++ )
  {
    GIGameObject tmpVirus;
    m_virus.push_back(tmpVirus);
  }

  for (int i = 0; i < 5; i++)
  {
	  GIGameObject tmpVortexVirus;
	  m_vortexVirus.push_back(tmpVortexVirus);
  }

  m_Player.Init(GameObjectDesc);
  m_Player.setPosition(sf::Vector2f(1000, 2000));

  m_son.Init(SonDesc);
  m_son.setPosition(sf::Vector2f(1000, 2000));

  for (int i = 0; i < m_ItemClon.size(); i++) { //*@Author :Ramses

      m_ItemClon[i].Init(ClonDesc);
      m_ItemClon[i].setPosition(sf::Vector2f(rand() % (WindowDesc.Width * 4) + 1, rand() % (WindowDesc.Height * 4) + 1));
  }

  for (int i = 0; i < m_food.size(); i++)
  {
    m_food[i].Init(FoodDesc);
    m_food[i].setPosition(sf::Vector2f(rand() % WindowDesc.Width + 1, rand() % WindowDesc.Height + 1));
    m_food[i].setPosition(sf::Vector2f(rand() % (WindowDesc.Width * 4) + 1, rand() % (WindowDesc.Height * 4) + 1));
    m_food[i].setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
  }

  for( int i = 0; i < m_virus.size(); i++ )
  {
    m_virus[i].Init(VirusDesc);
    m_virus[i].setPosition(sf::Vector2f(rand() % WindowDesc.Width + 1, rand() % WindowDesc.Height + 1));
    m_virus[i].setPosition(sf::Vector2f(rand() % (WindowDesc.Width * 4) + 1, rand() % (WindowDesc.Height * 4) + 1));
  }


  for (int i = 0; i < m_vortexVirus.size(); i++)
  {
	  m_vortexVirus[i].Init(VortexDesc);
	  m_vortexVirus[i].setPosition(sf::Vector2f(rand() % (WindowDesc.Width * 4) + 1, rand() % (WindowDesc.Height * 4) + 1));
  }


  m_EventSystem.Init(m_Player);

  m_window.Init(WindowDesc);
}

void GIRenderManager::Update()
{
  ClockTime.restart();
  sf::Event event;
  while( m_window.getInterface()->pollEvent(event) )
  {
    if( event.type == sf::Event::Closed )
      m_window.getInterface()->close();
    m_InputManager.GetInput(event, m_EventSystem, m_Player);
  }

  sf::Vector2f worldPos = GIInputManager::getSingleton().getWorldPosition(m_window, m_Camera);

  m_Player.Update(GISteeringBehaviors::getSingleton().Seek(worldPos, m_Player)); // This function is part of graphics API
  //m_Player.Update(worldPos); // This function is part of graphics API
  m_son.Update(GISteeringBehaviors::getSingleton().Seek(worldPos, m_son));

  // Set Camera Position
  m_Camera.setPosition(m_Player);
  // Update camera 
  m_Camera.Update();
  // Update Event system
  m_EventSystem.Update(m_Player, m_food, m_virus, m_vortexVirus, m_ItemClon);

  // update the position of each element of the Gui.
  m_gui.update(*m_window.getInterface());
}

void GIRenderManager::Render()
{
  GIGraphic_API::getSingleton().Clear(m_window, sf::Color(245, 245, 245));

  m_Player.Render(m_window);

  m_son.Render(m_window);

  m_EventSystem.Render(m_window);

  for (int i = 0; i < m_ItemClon.size(); i++) { //*@Author :Ramses

      m_ItemClon[i].Render(m_window);
  }

  for (int i = 0; i < m_food.size(); i++)
  {
    m_food[i].Render(m_window);
  }

  for( int i = 0; i < m_virus.size(); i++ )
  {
    m_virus[i].Render(m_window);
  }

  for (int i = 0; i < m_vortexVirus.size(); i++)
  {
	  m_vortexVirus[i].Render(m_window);
  }

  m_Camera.Render(m_window);

  if( m_isMainMenuPresent )
  {
    m_gui.Draw(*m_window.getInterface());

    bool removeMainMenu = false;

    sf::RenderWindow* ptr_window = m_window.getInterface();
    GIGuiRect* ptr_rect = m_gui.getGuiRecPtrByID(0);
    GIGuiRectDescriptor desc = ptr_rect->m_descriptor;

    sf::Vector2i screenPos = desc.screenPlacement;

    screenPos.x += (desc.widthAndHeight.x * .3f);
    screenPos.y += (desc.widthAndHeight.y * .6f);

    sf::Vector2i const mouseScreenPos = sf::Mouse::getPosition(*ptr_window);
    sf::Vector2f screenWorldPos = ptr_window->mapPixelToCoords(screenPos);
    sf::Vector2f mouseWorldPos = ptr_window->mapPixelToCoords(mouseScreenPos);

    removeMainMenu = m_gui.addBottonToWindow(*ptr_window,
                                              screenWorldPos);
    if( removeMainMenu )
    {
      m_isMainMenuPresent = false;
    }

  }

  GIGraphic_API::getSingleton().Present(m_window);
  deltaTime = ClockTime.getElapsedTime().asSeconds();
}

void GIRenderManager::Destroy()
{
  m_Player.Destroy();
  m_son.Destroy();

  for( int i = 0; i < m_food.size(); i++ )
  {
    m_food[i].Destroy();
  }

  m_window.Destroy();
  //delete deltaTime;
}

sf::RenderWindow*& GIRenderManager::getWindow()
{
  return m_window.getInterface();
}
