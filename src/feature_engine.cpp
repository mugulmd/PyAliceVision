#include "pyalicevision.hpp"

#include <pybind11/stl.h>

#include <aliceVision/feature/feature.hpp>
#include <aliceVision/featureEngine/FeatureExtractor.hpp>
#include <aliceVision/sfmData/SfMData.hpp>
#include <aliceVision/system/hardwareContext.hpp>

#include <string>
#include <memory>

using namespace aliceVision;


void bind_feature_engine(py::module & m)
{
	// FeatureExtractor
	py::class_<featureEngine::FeatureExtractor>(m, "FeatureExtractor")
		.def(py::init<const sfmData::SfMData &>())
		.def("setRange", &featureEngine::FeatureExtractor::setRange)
		.def("setMasksFolder", &featureEngine::FeatureExtractor::setMasksFolder)
		.def("setOutputFolder", &featureEngine::FeatureExtractor::setOutputFolder)
		.def("addImageDescriber",
			[](featureEngine::FeatureExtractor & self, const std::string & describerType) {
				std::shared_ptr<feature::ImageDescriber> describer =
					feature::createImageDescriber(
						feature::EImageDescriberType_stringToEnum(describerType));
				self.addImageDescriber(describer);
			})
		.def("process",
			[](featureEngine::FeatureExtractor & self, HardwareContext hwc) {
				self.process(hwc);
			});
}
