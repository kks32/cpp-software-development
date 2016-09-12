#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <functional>
#include <map>
#include <memory>
#include <string>

//! Singleton factory implementation
template <class BaseClass, typename Key = std::string>
class Factory {
 public:
  // Get the single instance of the factory
  static Factory* instance() {
    static Factory factory;
    return &factory;
  }

  // register a factory function to create an instance of className
  void register_factory(Key key,
                        std::function<BaseClass*(void)> class_factory_fn) {
    // register the class factory function
    registry[key] = class_factory_fn;
  }

  // create an instance of a registered class
  std::shared_ptr<BaseClass> create(Key key) {
    BaseClass* instance = nullptr;
    // find name in the registry and call factory method.
    auto it = registry.find(key);
    if (it != registry.end()) {
      instance = it->second();
      return std::shared_ptr<BaseClass>(instance);
    } else
      return nullptr;
  }

 private:
  // Private constructor
  Factory() {}

  // Register of factory functions
  std::map<Key, std::function<BaseClass*(void)>> registry;
};

// A helper class to register a factory function
template <class BaseClass, class DerivedClass, typename Key = std::string>
class Register {
 public:
  Register(Key key) {
    // register the class factory function
    Factory<BaseClass, Key>::instance()->register_factory(
        key, [](void) -> BaseClass* { return new DerivedClass(); });
  }
};

#endif  // _FACTORY_H_
