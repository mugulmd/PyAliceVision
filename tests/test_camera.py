import pytest

import pyalicevision as AV


@pytest.mark.parametrize("intrinsicType", [
    AV.PINHOLE_CAMERA,
    AV.PINHOLE_CAMERA_RADIAL3,
    AV.PINHOLE_CAMERA_3DEANAMORPHIC4,
    AV.EQUIDISTANT_CAMERA
])
def test_create_intrinsic(intrinsicType):
    """Test creating intrinsics with different intrinsic types."""
    intrinsic = AV.createIntrinsic(intrinsicType, 1920, 1080, 0, 0, 0, 0)
    assert intrinsic.width == 1920 and intrinsic.height == 1080
    assert intrinsic.intrinsicType() == intrinsicType
