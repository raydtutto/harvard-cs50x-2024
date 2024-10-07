# Import a Python Image Library
from PIL import Image, ImageFilter

# Create variable
before = Image.open("bridge.bmp")

# Run filter
after = before.filter(ImageFilter.FIND_EDGES)

# Save the new image
after.save("out.bmp")