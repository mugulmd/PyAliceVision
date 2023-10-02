import os
import numpy as np

import pyalicevision as AV


def test_view():
    """Test creating a view."""
    view = AV.View('/path/to/a/view')
    info = view.imageInfo()
    assert isinstance(info.path, str)
    assert info.path == '/path/to/a/view'
    info.width = 55
    assert info.width == 55
    info.height = 1986
    assert info.height == 1986
    view.viewId = 11689
    assert view.viewId == 11689
    view.intrinsicId = 22
    assert view.intrinsicId == 22
    view.poseId = 0
    assert view.poseId == 0
    view.frameId = 465
    assert view.frameId == 465
    assert isinstance(info.metadata(), dict)
    assert len(info.metadata().keys()) == 0

def test_camera_pose():
    """Test creating a camera pose."""
    pose = AV.CameraPose()
    pose.locked = False
    assert not pose.locked
    pose.locked = True
    assert pose.locked

def test_landmark():
    """Test creating a landmark."""
    landmark = AV.Landmark()
    pos = landmark.X
    assert isinstance(pos, np.ndarray)
    assert pos.shape == (3,)

def test_sfmdata_load():
    """Test loading a SfMData from disk."""
    path = os.path.abspath(os.path.dirname(__file__))+'/data/small.sfm'
    data = AV.SfMData(path)
    assert len(data.views().keys()) == 30
    assert len(data.intrinsics().keys()) == 1
    assert len(data.landmarks().keys()) == 0

def test_sfmdata_save():
    """Test saving a SfMData to disk."""
    data = AV.SfMData()
    for i in range(10):
        view = AV.View(f'/path/to/img{i}.jpg')
        view.viewId = i
        data.views()[i] = view
    assert len(data.views().keys()) == 10
    path = os.path.abspath(os.path.dirname(__file__))+'/out/dump.sfm'
    data.save(path)
    assert os.path.exists(path)

def test_camera_init():
    "Test completing a view and building the corresponding intrinsic."
    view = AV.View(os.path.abspath(os.path.dirname(__file__))+'/data/pie.jpg')
    view.complete()
    info = view.imageInfo()
    assert info.width == 1008 and info.height == 756
    assert len(info.metadata()) > 0
    cam = view.buildIntrinsic()
    assert cam.width == 1008 and cam.height == 756
    assert cam.intrinsicType() == AV.PINHOLE_CAMERA_RADIAL3
