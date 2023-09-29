#include "pyalicevision.hpp"

#include <pybind11/eigen.h>

#include <aliceVision/geometry/Pose3.hpp>

using namespace aliceVision;


void bind_geometry(py::module & m) {
    // Pose3
    // Represents a 3D rigid transform
    py::class_<geometry::Pose3>(m, "Pose3")
        .def(py::init<>())
        .def("rotation", &geometry::Pose3::rotation)
        .def("center", &geometry::Pose3::center);
}
