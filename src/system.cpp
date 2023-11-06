#include "pyalicevision.hpp"

#include <aliceVision/system/hardwareContext.hpp>
#include <aliceVision/system/MemoryInfo.hpp>

using namespace aliceVision;


void bind_system(py::module & m)
{
	// MemoryInfo
	py::class_<system::MemoryInfo>(m, "MemoryInfo")
		.def_readonly("totalRam", &system::MemoryInfo::totalRam)
		.def_readonly("freeRam", &system::MemoryInfo::freeRam)
		.def_readonly("availableRam", &system::MemoryInfo::availableRam)
		.def_readonly("totalSwap", &system::MemoryInfo::totalSwap)
		.def_readonly("freeSwap", &system::MemoryInfo::freeSwap);

	m.def("getMemoryInfo", &system::getMemoryInfo);

	// HardwareContext
	py::class_<HardwareContext>(m, "HardwareContext")
		.def_property("userMaxMemoryAvailable", &HardwareContext::getUserMaxMemoryAvailable, &HardwareContext::setUserMaxMemoryAvailable)
		.def_property("userMaxCoresAvailable", &HardwareContext::getUserMaxCoresAvailable, &HardwareContext::setUserMaxCoresAvailable)
		.def("setUserCoresLimit", &HardwareContext::setUserCoresLimit)
		.def("getMaxThreads", &HardwareContext::getMaxThreads)
		.def("getMaxMemory", &HardwareContext::getMaxMemory);
}
