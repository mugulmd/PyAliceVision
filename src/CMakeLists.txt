pybind11_add_module(pyalicevision
    pyalicevision.cpp
)


if(MSVC)
    target_compile_options(pyalicevision PUBLIC /W4)
else()
    target_compile_options(pyalicevision PUBLIC -Wall -Wextra -Wconversion -Wsign-conversion -Wshadow -Wpedantic)
endif()


target_link_libraries(pyalicevision
PUBLIC
    aliceVision_sfmData
    aliceVision_sfmDataIO 
)


install(
TARGETS
    pyalicevision
DESTINATION
    ${CMAKE_INSTALL_PREFIX}
)
