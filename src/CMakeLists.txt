# Sources
set(pyalicevision_sources
    pyalicevision.cpp
    camera.cpp
    feature_engine.cpp
    geometry.cpp
    image.cpp
    sfmdata.cpp
    system.cpp
)


# Headers
set(pyalicevision_headers
    pyalicevision.hpp
)


# PyAliceVision module
pybind11_add_module(pyalicevision
    ${pyalicevision_sources}
    ${pyalicevision_headers}
)


# Compile options
if(MSVC)
    target_compile_options(pyalicevision PUBLIC /W4)
else()
    target_compile_options(pyalicevision PUBLIC -Wall -Wextra -Wconversion -Wsign-conversion -Wshadow -Wpedantic)
endif()


# Libraries
target_link_libraries(pyalicevision
PUBLIC
    aliceVision_camera
    aliceVision_feature
    aliceVision_featureEngine
    aliceVision_geometry
    aliceVision_image
    aliceVision_sfmData
    aliceVision_sfmDataIO
    aliceVision_system
)


# Install
install(
TARGETS
    pyalicevision
DESTINATION
    ${CMAKE_INSTALL_PREFIX}
)
