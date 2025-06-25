#-----------------------------------------------------------------------------
set(MODULE_NAME IconSwitchPython)

#-----------------------------------------------------------------------------
set(MODULE_PYTHON_SCRIPTS
  ${MODULE_NAME}.py
  )

set(MODULE_PYTHON_RESOURCES
  Resources/Icons/${MODULE_NAME}.png
  Resources/UI/${MODULE_NAME}.ui
  Resources/Icons/Light/DataModule.svg
  Resources/Icons/Light/DefaultModule.svg
  Resources/Icons/Light/ModelsModule.svg
  Resources/Icons/Light/WelcomeModule.svg
  Resources/Icons/Light/IconSwitch.png
  Resources/Icons/Dark/DataModule.svg
  Resources/Icons/Dark/DefaultModule.svg
  Resources/Icons/Dark/ModelsModule.svg
  Resources/Icons/Dark/WelcomeModule.svg
  Resources/Icons/Dark/IconSwitch.png
  )

#-----------------------------------------------------------------------------
slicerMacroBuildScriptedModule(
  NAME ${MODULE_NAME}
  SCRIPTS ${MODULE_PYTHON_SCRIPTS}
  RESOURCES ${MODULE_PYTHON_RESOURCES}
  WITH_GENERIC_TESTS
  )

#-----------------------------------------------------------------------------
if(BUILD_TESTING)

  # Register the unittest subclass in the main script as a ctest.
  # Note that the test will also be available at runtime.
  slicer_add_python_unittest(SCRIPT ${MODULE_NAME}.py)

  # Additional build-time testing
  add_subdirectory(Testing)
endif()
