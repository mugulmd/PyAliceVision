#include "pyalicevision.hpp"

#include <aliceVision/geometry/Pose3.hpp>

using namespace aliceVision;


void bind_geometry(py::module & m) {
    py::class_<geometry::Pose3>(m, "Pose3")
        .def(py::init<>())
        .def("rotation",
            static_cast<const Mat3 & (geometry::Pose3::*)() const>
                (&geometry::Pose3::rotation))
        .def("center",
            static_cast<const Vec3 & (geometry::Pose3::*)() const>
                (&geometry::Pose3::center));
}
