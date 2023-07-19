#include "pyalicevision.hpp"

#include <aliceVision/image/all.hpp>

#include <string>

using namespace aliceVision;


template<typename T>
void declare_image_class(py::module & m, const std::string & name) {
    py::class_<image::Image<T>>(m, name.c_str())
        .def(py::init<>())
        .def(py::init([](const std::string & filename) {
            image::Image<T> self;
            image::readImage(filename, self, image::EImageColorSpace::SRGB);
            return self;
        }))
        .def("save", [](const image::Image<T> & self, const std::string & filename) {
            image::writeImage(filename, self, image::ImageWriteOptions());
        })
        .def("width", &image::Image<T>::Width)
        .def("height", &image::Image<T>::Height)
        .def("depth", &image::Image<T>::Depth)
        .def("channels", &image::Image<T>::Channels);
}


void bind_image(py::module & m) {
    declare_image_class<unsigned char>(m, "ImageUChar");
    declare_image_class<float>(m, "ImageFloat");
}
