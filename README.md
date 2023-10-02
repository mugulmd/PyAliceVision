# pyalicevision

Python binding for AliceVision.

## Summary

**pyalicevision** exposes a number of features from the AliceVision library to Python.

Currently it mainly focuses on SfMData and image manipulation.

## Setup

See [the installation steps](INSTALL.md) to build the project.

## Usage

Code sample for SfMData manipulation:
```python
import pyalicevision as AV

# Load SfMData
data = AV.SfMData('/path/to/input/sfmdata.sfm')

# Create new view and complete its information
view = AV.View('/some/path/to/an/image.jpg')
view.complete()

# Add view to SfMData
data.views()[view.viewId] = view

# Build corresponding intrinsic
cam = view.buildIntrinsic()

# Add intrinsic to SfMData
data.intrinsics()[view.intrinsicId] = cam

# Save modified SfMData
data.save('/path/to/output/sfmdata.abc')
```

## Documentation

API documentation can be generated with Sphinx:
```
sphinx-build -b html docs/source/ docs/build/html/
```

After running this command, the documentation pages can be found at `docs/build/html/index.html`.

## Testing

To run all unit tests, use the following command:
```
pytest tests/
```
