#include <pybind11/pybind11.h>

#include <aliceVision/sfmData/SfMData.hpp>
#include <aliceVision/sfmDataIO/sfmDataIO.hpp>

#include <stdexcept>
#include <string>

namespace py = pybind11;
using namespace aliceVision;


PYBIND11_MODULE(pyalicevision, m) {
    m.doc() = "Python binding for AliceVision";

    py::class_<sfmData::View>(m, "View")
        .def(py::init<const std::string &>())
        .def("getImagePath", &sfmData::View::getImagePath);
    
    py::class_<sfmData::SfMData>(m, "SfMData")
        .def(py::init([](const std::string & filename) {
            sfmData::SfMData self;
            if (!sfmDataIO::Load(self, filename, sfmDataIO::ESfMData::ALL)) {
                throw std::runtime_error("Failed to load SfMData file.");
            }
            return self;
        }))
        .def("save", [](const sfmData::SfMData & self, const std::string & filename) {
            if (!sfmDataIO::Save(self, filename, sfmDataIO::ESfMData::ALL)) {
                throw std::runtime_error("Failed to load SfMData file.");
            }
        });
}
