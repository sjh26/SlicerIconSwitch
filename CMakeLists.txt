cmake_minimum_required(VERSION 3.16.3...3.19.7 FATAL_ERROR)

project(IconSwitchSandBox)

#-----------------------------------------------------------------------------
# Extension meta-information
set(EXTENSION_HOMEPAGE "https://www.slicer.org/wiki/Documentation/Nightly/Extensions/IconSwitchSandBox")
set(EXTENSION_CONTRIBUTORS "Sam Horvath (Kitware, Inc)")
set(EXTENSION_DESCRIPTION "This extension holds the sand box code for exploring Icon theme switching")
set(EXTENSION_ICONURL "https://www.example.com/Slicer/Extensions/IconSwitchSandBox.png")
set(EXTENSION_SCREENSHOTURLS "https://www.example.com/Slicer/Extensions/IconSwitchSandBox/Screenshots/1.png")
set(EXTENSION_DEPENDS "NA") # Specified as a list or "NA" if no dependencies

#-----------------------------------------------------------------------------
# Extension dependencies
find_package(Slicer REQUIRED)
include(${Slicer_USE_FILE})

#-----------------------------------------------------------------------------
# Extension modules
add_subdirectory(IconSwitch)
add_subdirectory(IconSwitchPython)
## NEXT_MODULE

#-----------------------------------------------------------------------------
include(${Slicer_EXTENSION_GENERATE_CONFIG})
include(${Slicer_EXTENSION_CPACK})
