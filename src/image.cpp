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
        .def(py::init<>(),
            "Create an empty image with dimensions (0, 0).")
        .def(py::init<int, int, bool, T>(),
            "Create an image with given dimensions and optionally fill it with a given value.",
            py::arg("w"), py::arg("h"),
            py::arg("fill") = false, py::arg("val") = T{})
        .def(py::init([](const std::string & filename) {
                image::Image<T> self;
                image::readImage(filename, self, image::EImageColorSpace::SRGB);
                return self;
            }),
            "Load an image from disk.",
            py::arg("filename"))
        .def("save", [](const image::Image<T> & self, const std::string & filename) {
                image::writeImage(filename, self, image::ImageWriteOptions());
            },
            "Save the image to disk.",
            py::arg("filename"))
        .def("width", &image::Image<T>::Width)
        .def("height", &image::Image<T>::Height)
        .def("depth", &image::Image<T>::Depth)
        .def("channels", &image::Image<T>::Channels)
        .def("at",
            static_cast<const T & (image::Image<T>::*)(int, int) const>(&image::Image<T>::operator()),
            "Get pixel value at position (row, col).",
            py::arg("row"), py::arg("col"));
}


void bind_image(py::module & m) {
    // Template instantiation for each image class
    declare_image_class<unsigned char>(m, "ImageUChar");
    declare_image_class<float>(m, "ImageFloat");
}
