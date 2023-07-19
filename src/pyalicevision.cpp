#include "pyalicevision.hpp"


PYBIND11_MODULE(pyalicevision, m) {
    m.doc() = "Python binding for AliceVision";

    bind_sfmdata(m);
}
