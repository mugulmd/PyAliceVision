#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <pybind11/eigen.h>

namespace py = pybind11;


void bind_camera(py::module & m);
void bind_geometry(py::module & m);
void bind_sfmdata(py::module & m);
