#include "pyalicevision.hpp"

#include <aliceVision/camera/camera.hpp>

#include <string>

using namespace aliceVision;


void bind_camera(py::module & m) {
    // Intrinsic types
    py::enum_<camera::EINTRINSIC>(m, "IntrinsicType")
        .value("PINHOLE_CAMERA", camera::PINHOLE_CAMERA)
        .value("PINHOLE_CAMERA_RADIAL1", camera::PINHOLE_CAMERA_RADIAL1)
        .value("PINHOLE_CAMERA_RADIAL3", camera::PINHOLE_CAMERA_RADIAL3)
        .value("PINHOLE_CAMERA_3DERADIAL4", camera::PINHOLE_CAMERA_3DERADIAL4)
        .value("PINHOLE_CAMERA_BROWN", camera::PINHOLE_CAMERA_BROWN)
        .value("PINHOLE_CAMERA_FISHEYE", camera::PINHOLE_CAMERA_FISHEYE)
        .value("PINHOLE_CAMERA_FISHEYE1", camera::PINHOLE_CAMERA_FISHEYE1)
        .value("PINHOLE_CAMERA_3DEANAMORPHIC4", camera::PINHOLE_CAMERA_3DEANAMORPHIC4)
        .value("PINHOLE_CAMERA_3DECLASSICLD", camera::PINHOLE_CAMERA_3DECLASSICLD)
        .value("EQUIDISTANT_CAMERA", camera::EQUIDISTANT_CAMERA)
        .value("EQUIDISTANT_CAMERA_RADIAL3", camera::EQUIDISTANT_CAMERA_RADIAL3)
        .export_values();

    // IntrinsicBase
    // Top-level of the intrinsic class hierarchy
    py::class_<camera::IntrinsicBase, std::shared_ptr<camera::IntrinsicBase>>(m, "IntrinsicBase")
        .def_property("width", &camera::IntrinsicBase::w, &camera::IntrinsicBase::setWidth)
        .def_property("height", &camera::IntrinsicBase::h, &camera::IntrinsicBase::setHeight)
        .def("intrinsicType", &camera::IntrinsicBase::getType);
    
    // Intrinsic factory
    m.def("createIntrinsic",
        &camera::createIntrinsic,
        "Factory method to create camera models.",
        py::arg("intrinsicType"),
        py::arg("w") = 0, py::arg("h") = 0,
        py::arg("focalX") = 0, py::arg("focalY") = 0,
        py::arg("offsetX") = 0, py::arg("offsetY") = 0);
}
