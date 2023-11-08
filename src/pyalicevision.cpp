#include "pyalicevision.hpp"


PYBIND11_MODULE(pyalicevision, m) {
    // Module documentation
    m.doc() = "Python binding for AliceVision.";

    // Binding order must respect dependencies between AliceVision libraries
    bind_image(m);
    bind_geometry(m);
    bind_camera(m);
    bind_feature(m);
    bind_matching(m);
    bind_sfmdata(m);
    bind_system(m);
    bind_feature_engine(m);
}
