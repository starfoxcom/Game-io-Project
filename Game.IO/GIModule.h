/**
 * @LC	   : 22/01/2020
 * @file   : feModule.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 18/10/2019
 * @brief  : Template class in charge of creating a base module structure for the frost engine.
 * @bug	   : No known bugs.
 */

 /**
  * Headers
  */
#pragma once

  /**
   * @brief :  Template class in charge of creating a base module structure.
   */
template<class T>
class GIModule
{
public:
  /**
    * @brief  : Returns a reference to the module instance. Module has to have
     *          been started up first otherwise an exception will be thrown.
    * @bug    : No know bugs.
    */
  static T &
    getSingleton()
  {
    if (!isReady())
    {
      // TODO Error.
    }

    if (isDestroyed())
    {
      // TODO Error.
    }

    return *_singleton();
  }

  static T *
    getSingletonPtr()
  {
    if (!isReady())
    {
      // TODO Error.
    }

    if (isDestroyed())
    {
      // TODO Error.
    }

    return _singleton();
  }

  static void
    set(void * _module)
  {
    if (!isReady())
    {
      // TODO Error.
    }

    if (isDestroyed())
    {
      // TODO Error.
    }

    _singleton() = reinterpret_cast<T*>(_module);
    isReady() = true;

    return;
  }

  template<class... Args>
  static void
    Prepare(Args&& ...args)
  {
    if (isReady())
    {
      // TODO Error.
    }

    _singleton() = new T(std::forward<Args>(args)...);
    isReady() = true;

    static_cast<GIModule*>(_singleton())->onPrepare();
  }

  template<class SubType, class... Args>
  static void
    Prepare(Args&& ...args)
  {
    static_assert(std::is_base_of<T, SubType>::value,
      "Type isn't derived from type the Module is initialized with.");

    if (isReady())
    {
      // Error.
    }

    _singleton() = new SubType(std::forward<Args>(args)...);
    isReady() = true;

    static_cast<GIModule*>(_singleton())->onPrepare();
  }

  static void
    ShutDown()
  {
    if (isDestroyed())
    {
      // error.
    }

    if (isReady())
    {
      // error.
    }

    static_cast<GIModule*>(_singleton())->onShutDown();

    delete(_singleton());
    isDestroyed() = true;
  }

  static bool
    isStarted()
  {
    return isReady() && !isDestroyed();
  }

protected:

  GIModule() = default;

  virtual
    ~GIModule() = default;

  GIModule(GIModule &&) = delete;

  GIModule &
    operator = (GIModule &&) = delete;

  GIModule &
    operator = (const GIModule &&) = delete;

  virtual void
    onPrepare()
  { }

  virtual void
    onShutDown()
  { }

  static T* &
    _singleton()
  {
    static T* singleton = nullptr;
    return singleton;
  }

  static bool &
    isDestroyed()
  {
    static bool ready = false;
    return ready;
  }

  static bool &
    isReady()
  {
    static bool ready = false;
    return ready;
  }
};