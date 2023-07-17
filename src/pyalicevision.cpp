#include <pybind11/pybind11.h>

#include <aliceVision/sfmData/View.hpp>

#include <string>

namespace py = pybind11;
using namespace aliceVision;


PYBIND11_MODULE(pyalicevision, m)
{
    m.doc() = "Python binding for AliceVision";

    py::class_<sfmData::View>(m, "View")
        .def(py::init<const std::string &>())
        .def("getImagePath", &sfmData::View::getImagePath);
}
