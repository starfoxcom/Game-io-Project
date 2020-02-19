#include "GIDefines.h"
#include "GIRenderManager.h"
int main()
{
  /**
   * @brief : Render Manager Object
   */
  GIRenderManager RenderManager;
  /**
   * @brief : Initialization of the graphic API module.
   */
  GIGraphic_API::Prepare();
  GISteeringBehaviors::Prepare();
  GIInputManager::Prepare();
  // Init
  RenderManager.Init();
	while (RenderManager.getWindow()->isOpen())
	{
    // Input Manager
//     while (RenderManager.getWindow()->pollEvent(GIGraphic_API::getSingleton().getEventInterface()))
//     {
//       if (GIGraphic_API::getSingleton().getEventInterface().type == sf::Event::Closed)
//       {
//         RenderManager.getWindow()->close();
//       }
//       if (GIGraphic_API::getSingleton().getEventInterface().key.code == sf::Keyboard::Escape)
//       {
//         RenderManager.getWindow()->close();
//       }
// 
//     }

    // Update
    RenderManager.Update();
    
    // Render
    RenderManager.Render();
	}
  // Destroy
  RenderManager.Destroy();

  GIGraphic_API::ShutDown();
  GISteeringBehaviors::ShutDown();
  GIInputManager::ShutDown();
	return 0;
}