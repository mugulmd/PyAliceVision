#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <aliceVision/sfmData/SfMData.hpp>
#include <aliceVision/sfmDataIO/sfmDataIO.hpp>

#include <stdexcept>
#include <string>
#include <memory>

namespace py = pybind11;
using namespace aliceVision;


PYBIND11_MAKE_OPAQUE(sfmData::Views)


PYBIND11_MODULE(pyalicevision, m) {
    m.doc() = "Python binding for AliceVision";

    py::class_<sfmData::View, std::shared_ptr<sfmData::View>>(m, "View")
        .def(py::init<>())
        .def_property("path", &sfmData::View::getImagePath, &sfmData::View::setImagePath)
        .def_property("width", &sfmData::View::getWidth, &sfmData::View::setWidth)
        .def_property("height", &sfmData::View::getHeight, &sfmData::View::setHeight)
        .def_property("viewId", &sfmData::View::getViewId, &sfmData::View::setViewId)
        .def_property("intrinsicId", &sfmData::View::getIntrinsicId, &sfmData::View::setIntrinsicId)
        .def_property("poseId", &sfmData::View::getPoseId, &sfmData::View::setPoseId)
        .def_property("frameId", &sfmData::View::getFrameId, &sfmData::View::setFrameId)
        .def_property_readonly("metadata", [](std::shared_ptr<sfmData::View> self) { return self->getMetadata(); });
    
    py::bind_map<sfmData::Views>(m, "Views");
    
    py::class_<sfmData::SfMData>(m, "SfMData")
        .def(py::init<>())
        .def(py::init([](const std::string & filename) {
            sfmData::SfMData self;
            if (!sfmDataIO::Load(self, filename, sfmDataIO::ESfMData(sfmDataIO::ALL))) {
                throw std::runtime_error("Failed to load SfMData file.");
            }
            return self;
        }))
        .def("save", [](const sfmData::SfMData & self, const std::string & filename) {
            if (!sfmDataIO::Save(self, filename, sfmDataIO::ESfMData(sfmDataIO::ALL))) {
                throw std::runtime_error("Failed to load SfMData file.");
            }
        })
        .def_readwrite("views", &sfmData::SfMData::views);
}
