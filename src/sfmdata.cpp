#include "pyalicevision.hpp"

#include <aliceVision/sfmData/SfMData.hpp>
#include <aliceVision/sfmDataIO/sfmDataIO.hpp>

#include <stdexcept>
#include <string>
#include <memory>

using namespace aliceVision;


PYBIND11_MAKE_OPAQUE(sfmData::Views)
PYBIND11_MAKE_OPAQUE(sfmData::Poses)
PYBIND11_MAKE_OPAQUE(sfmData::Intrinsics)
PYBIND11_MAKE_OPAQUE(sfmData::Landmarks)


void bind_sfmdata(py::module & m) {
    py::class_<sfmData::View, std::shared_ptr<sfmData::View>>(m, "View")
        .def(py::init<>())
        .def_property("path", &sfmData::View::getImagePath, &sfmData::View::setImagePath)
        .def_property("width", &sfmData::View::getWidth, &sfmData::View::setWidth)
        .def_property("height", &sfmData::View::getHeight, &sfmData::View::setHeight)
        .def_property("viewId", &sfmData::View::getViewId, &sfmData::View::setViewId)
        .def_property("intrinsicId", &sfmData::View::getIntrinsicId, &sfmData::View::setIntrinsicId)
        .def_property("poseId", &sfmData::View::getPoseId, &sfmData::View::setPoseId)
        .def_property("frameId", &sfmData::View::getFrameId, &sfmData::View::setFrameId)
        .def("metadata",
            static_cast<const std::map<std::string, std::string> & (sfmData::View::*)() const>
                (&sfmData::View::getMetadata));
    
    py::class_<sfmData::CameraPose>(m, "CameraPose")
        .def(py::init<>())
        .def_property("transform", &sfmData::CameraPose::getTransform, &sfmData::CameraPose::setTransform)
        .def_property("locked",
            &sfmData::CameraPose::isLocked,
            [](sfmData::CameraPose & self, bool lock) {
                if (self.isLocked() && !lock) self.unlock();
                else if (!self.isLocked() && lock) self.lock();
            });
    
    py::class_<sfmData::Landmark>(m, "Landmark")
        .def(py::init<>())
        .def_readwrite("X", &sfmData::Landmark::X);
    
    py::bind_map<sfmData::Views>(m, "Views");
    py::bind_map<sfmData::Poses>(m, "Poses");
    py::bind_map<sfmData::Intrinsics>(m, "Intrinsics");
    py::bind_map<sfmData::Landmarks>(m, "Landmarks");
    
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
        .def_property("featuresFolders", &sfmData::SfMData::getFeaturesFolders, &sfmData::SfMData::setFeaturesFolders)
        .def_property("matchesFolders", &sfmData::SfMData::getMatchesFolders, &sfmData::SfMData::setMatchesFolders)
        .def_readwrite("views", &sfmData::SfMData::views)
        .def("poses",
            static_cast<const sfmData::Poses & (sfmData::SfMData::*)() const>
                (&sfmData::SfMData::getPoses))
        .def_readwrite("intrinsics", &sfmData::SfMData::intrinsics)
        .def_readwrite("structure", &sfmData::SfMData::structure);
}
