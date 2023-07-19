#include "pyalicevision.hpp"

#include <aliceVision/camera/camera.hpp>

using namespace aliceVision;


void bind_camera(py::module & m) {
    py::class_<camera::IntrinsicBase, std::shared_ptr<camera::IntrinsicBase>>(m, "IntrinsicBase")
        .def_property("width", &camera::IntrinsicBase::w, &camera::IntrinsicBase::setWidth)
        .def_property("height", &camera::IntrinsicBase::h, &camera::IntrinsicBase::setHeight);
}
