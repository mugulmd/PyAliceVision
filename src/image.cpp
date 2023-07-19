#include "pyalicevision.hpp"

#include <aliceVision/image/all.hpp>

#include <string>

using namespace aliceVision;


template<typename T>
void declare_image_class(py::module & m, const std::string & name) {
    py::class_<image::Image<T>>(m, name.c_str())
        .def(py::init<>())
        .def("width", &image::Image<T>::Width)
        .def("height", &image::Image<T>::Height);
}


void bind_image(py::module & m) {
    declare_image_class<float>(m, "ImageFloat");
}
