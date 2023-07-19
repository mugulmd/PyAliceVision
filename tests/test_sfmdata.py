import pyalicevision as AV


def test_view():
    view = AV.View()
    view.path = "/path/to/a/view"
    assert isinstance(view.path, str)
    assert view.path == "/path/to/a/view"
    view.width = 55
    assert view.width == 55
    view.height = 1986
    assert view.height == 1986
    view.viewId = 11689
    assert view.viewId == 11689
    view.intrinsicId = 22
    assert view.intrinsicId == 22
    view.poseId = 0
    assert view.poseId == 0
    view.frameId = 465
    assert view.frameId == 465
    assert isinstance(view.metadata(), dict)
    assert len(view.metadata().keys()) == 0
