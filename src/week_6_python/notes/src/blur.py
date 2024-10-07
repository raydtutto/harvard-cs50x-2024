# Import a Python Image Library
from PIL import Image, ImageFilter

# Create variable
before = Image.open("bridge.bmp")

# Run filter
after = before.filter(ImageFilter.BoxBlur(10))

# Save the new image
after.save("out.bmp")