set(pyalicevision_sources
    pyalicevision.cpp
    sfmdata.cpp
)

set(pyalicevision_headers
    pyalicevision.hpp
)


pybind11_add_module(pyalicevision
    ${pyalicevision_sources}
    ${pyalicevision_headers}
)


if(MSVC)
    target_compile_options(pyalicevision PUBLIC /W4)
else()
    target_compile_options(pyalicevision PUBLIC -Wall -Wextra -Wconversion -Wsign-conversion -Wshadow -Wpedantic)
endif()


target_link_libraries(pyalicevision
PUBLIC
    aliceVision_camera
    aliceVision_geometry
    aliceVision_sfmData
    aliceVision_sfmDataIO 
)


install(
TARGETS
    pyalicevision
DESTINATION
    ${CMAKE_INSTALL_PREFIX}
)
