# pyalicevision

Python binding for AliceVision.

## Summary

**pyalicevision** exposes a number of features from the AliceVision library to Python.

Currently it mainly focuses on SfMData and image manipulation.

## Usage


Code sample for SfMData manipulation:
```python
import pyalicevision as AV

# Load SfMData
data = AV.SfMData('/path/to/input/sfmdata.sfm')

# Create new view
view = AV.View()
view.viewId = 1287057
view.path = '/some/path/to/an/image.jpg'

# Add view to SfMData
data.views[view.viewId] = view

# Save modified SfMData
data.save('/path/to/output/sfmdata.abc')
```

## Documentation

API documentation can be generated with Sphinx:
```
sphinx-build -b html docs/source/ docs/build/html/
```

After running this command, the documentation pages can be found at `docs/build/html/index.html`.
