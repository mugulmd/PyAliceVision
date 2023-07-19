#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;


void bind_camera(py::module & m);
void bind_geometry(py::module & m);
void bind_image(py::module & m);
void bind_sfmdata(py::module & m);
