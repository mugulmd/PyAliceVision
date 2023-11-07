import pytest

import pyalicevision as AV


@pytest.mark.parametrize("intrinsicType", [
    "pinhole",
    "radial3",
    "3deanamorphic4",
    "equidistant"
])
def test_create_intrinsic(intrinsicType):
    """Test creating intrinsics with different intrinsic types."""
    intrinsic = AV.createIntrinsic(intrinsicType, 1920, 1080)
    assert intrinsic.width == 1920 and intrinsic.height == 1080
    assert intrinsic.intrinsicType() == intrinsicType
