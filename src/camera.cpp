#include "pyalicevision.hpp"

#include <pybind11/stl.h>

#include <aliceVision/camera/camera.hpp>

#include <string>
#include <memory>

using namespace aliceVision;


void bind_camera(py::module & m) {
    // IntrinsicBase
    // Top-level of the intrinsic class hierarchy
    py::class_<camera::IntrinsicBase, std::shared_ptr<camera::IntrinsicBase>>(m, "IntrinsicBase")
        .def_property("width", &camera::IntrinsicBase::w, &camera::IntrinsicBase::setWidth)
        .def_property("height", &camera::IntrinsicBase::h, &camera::IntrinsicBase::setHeight)
        .def("intrinsicType",
            [] (std::shared_ptr<camera::IntrinsicBase> self) {
                return camera::EINTRINSIC_enumToString(self->getType());
            });
    
    // Intrinsic factory
    m.def("createIntrinsic",
        [] (const std::string & intrinsicType,
            unsigned int w, unsigned int h,
            double focalX, double focalY,
            double offsetX, double offsetY) {
            return camera::createIntrinsic(
                camera::EINTRINSIC_stringToEnum(intrinsicType),
                w, h, focalX, focalY, offsetX, offsetY);
        },
        "Factory method to create camera models.",
        py::arg("intrinsicType"),
        py::arg("w") = 0, py::arg("h") = 0,
        py::arg("focalX") = 0, py::arg("focalY") = 0,
        py::arg("offsetX") = 0, py::arg("offsetY") = 0);
}
