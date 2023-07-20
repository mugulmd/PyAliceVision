#include "pyalicevision.hpp"

#include <aliceVision/image/all.hpp>

#include <string>

using namespace aliceVision;


// Template to generate binding code for each image class
template<typename T>
void declare_image_class(py::module & m, const std::string & name) {
    // Image<PixelType>
    // Also takes care of Image IO
    py::class_<image::Image<T>>(m, name.c_str())
        .def(py::init<>())
        .def(py::init<int, int, bool, T>())
        .def(py::init([](const std::string & filename) {
            image::Image<T> self;
            image::readImage(filename, self, image::EImageColorSpace::SRGB);
            return self;
        }))
        .def("save", [](const image::Image<T> & self, const std::string & filename) {
            image::writeImage(filename, self, image::ImageWriteOptions());
        })
        .def("resize", &image::Image<T>::resize)
        .def("width", &image::Image<T>::Width)
        .def("height", &image::Image<T>::Height)
        .def("depth", &image::Image<T>::Depth)
        .def("channels", &image::Image<T>::Channels)
        .def("at",
            static_cast<const T & (image::Image<T>::*)(int, int) const>
                (&image::Image<T>::operator()));
}


void bind_image(py::module & m) {
    // Template instantiation for each image class
    declare_image_class<unsigned char>(m, "ImageUChar");
    declare_image_class<float>(m, "ImageFloat");
}
