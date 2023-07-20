import pytest
import os

import pyalicevision as AV


def test_image_uchar():
    """Test creating and resizing a uchar image."""
    img = AV.ImageUChar(50, 80, True, 2)
    assert img.width() == 50 and img.height() == 80
    assert img.channels() == 1
    img.resize(100, 10, False, 4)
    assert img.width() == 100 and img.height() == 10
    assert img.at(19, 8) == 2


def test_image_float():
    """Test creating and resizing a float image."""
    img = AV.ImageFloat()
    assert img.width() == 0 and img.height() == 0
    assert img.channels() == 1
    img.resize(1920, 1080, True, 1.2)
    assert img.width() == 1920 and img.height() == 1080
    assert img.at(100, 37) == pytest.approx(1.2)

def test_load():
    """Test loading an image from disk."""
    path = os.path.abspath(os.path.dirname(__file__))+'/data/pie.jpg'
    img = AV.ImageUChar(path)
    assert img.width() == 1008 and img.height() == 756

def test_save():
    """Test saving an image to disk."""
    img = AV.ImageFloat(16, 9, True, .6)
    path = os.path.abspath(os.path.dirname(__file__))+'/out/dump.exr'
    img.save(path)
    assert os.path.exists(path)
