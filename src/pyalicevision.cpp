#include "pyalicevision.hpp"


PYBIND11_MODULE(pyalicevision, m) {
    // Module documentation
    m.doc() = "Python binding for AliceVision.";

    // Binding order must respect dependencies between AliceVision libraries
    bind_image(m);
    bind_geometry(m);
    bind_camera(m);
    bind_sfmdata(m);
}
