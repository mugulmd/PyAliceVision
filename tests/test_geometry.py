import pytest
import numpy as np

import pyalicevision as AV


def test_pose3():
    """Test creating a transform with no rotation and no translation."""
    tr = AV.Pose3()
    center = tr.center()
    rot = tr.rotation()
    assert isinstance(center, np.ndarray) and isinstance(rot, np.ndarray)
    assert center.shape == (3,)
    assert rot.shape == (3, 3)
    assert center.cumsum() == pytest.approx(0.)
    assert rot.trace() == pytest.approx(3.)
