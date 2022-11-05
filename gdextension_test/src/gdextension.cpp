#include <godot/gdnative_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

// Include our class header.
#include "test_node2d.hpp"

// This function will be called to initialize types and other things the extension provides.
// It can be called multiple times, since the only the minimum initialization level is provided (see below the main entry point.)
void initializer(godot::ModuleInitializationLevel p_level)
{
  // Check if we are in the level we want to initialize stuff in. 
  // This prevents multiple overlapping registrations and reference errors during initialization 
  // (like parent class missing if initialization is done in wrong level).
  if (p_level == godot::MODULE_INITIALIZATION_LEVEL_SCENE)
  {
    // Handle initialization, register our test class to the engine.
    godot::ClassDB::register_class<gdextension_test::TestNode2D>();
  }
}

// This function will be called to uninitialize types and other things the extension provided.
// It can be called multiple times, since the only the minimum initialization level is provided (see below the main entry point.)
void terminator(godot::ModuleInitializationLevel p_level)
{
  // Check if we are in the level we want to uninitialize stuff in.
  if (p_level == godot::MODULE_INITIALIZATION_LEVEL_SCENE)
  {
    // Handle uninitialization.
  }
}

// Expose as unmangled C ABI.
extern "C"
{
  // Entry point function. Name is important here since it needs to be both unique and defined in the GDExtension manifest.
  GDNativeBool GDN_EXPORT gdextension_test_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization)
  {
    // Create "InitObject" that contains all the necessary information how to initialize the extension.
    godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);
    // Set the initializer function for the extension. Can be a lambda.
    init_obj.register_initializer(initializer);
    // Set the terminator ("uninitializer") function for the extension. Can be a lambda.
    init_obj.register_terminator(terminator);
    // Set the minimum initialization level the above functions are called within. 
    init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_SCENE);
    return init_obj.init();
  }
}