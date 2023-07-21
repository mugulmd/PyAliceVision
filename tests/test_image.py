import pytest
import os

import pyalicevision as AV


def test_image_uchar():
    """Test creating a uchar image."""
    img = AV.ImageUChar(50, 80, True, 2)
    assert img.width() == 50 and img.height() == 80
    assert img.channels() == 1
    assert img.get(19, 8) == 2


def test_image_float():
    """Test creating a float image."""
    img = AV.ImageFloat(1920, 1080, True, 1.2)
    assert img.channels() == 1
    assert img.width() == 1920 and img.height() == 1080
    assert img.get(100, 37) == pytest.approx(1.2)

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

def test_rectangle():
    """Test drawing a grey rectangle on a black background."""
    img = AV.ImageUChar(50, 50, True, 0)
    for row in range(10, 20):
        for col in range(5, 30):
            img.set(row, col, 100)
    assert img.get(0, 0) == 0
    assert img.get(12, 22) == 100
