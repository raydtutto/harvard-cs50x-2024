# Week 6: Python

Instructor: **[David J. Malan](https://github.com/dmalan)**

---

Remember the simple `hello-world` program implemented in C:

```c++
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

Now have a look at exactly the same doing program but in **Python**:

```python
print("hello, world")
```

To run python program within terminal:
- We don't need to precompile our program and run it separately like it was in C;
- Just use command "python" before the program's name.

```c++
code hello.py // to create a program
python hello.py // to run it
```

What are the differences between those programs in Python and C?
- no library was included;
- no need to define the `main()` of the program;
- no more newline `\n` (just a reversed default behaviour);
- no more semicolon `;`
- there is no need to indicate strings with only double quotes`"`, you may use single quotes `'` also, 
just be consistent.

```python
print('hello, world')
```

---

## Examples

### - Speller

Let's dive into `Speller` problem from Week 5 once more and rewrite dictionaries.c in python.

```python
# Global variable `words`
# `set()` - is a collection of things that won't contain duplicates.
# Duplicates will be filtered out automatically.
words = set()

# Define a function
def check(word):
    # Check that word is within the set of words
    return word.lower() in words

def load(dictionary):
    # Open dictionary as a variable `file`
    with open(dictionary) as file:
        # Update the set of words to be the updated version of smth from `file` as a result of reading.
        # Then splitting its lines into one big collection.
        words.update(file.read().splitlines())
    return True

def size():
    return len(words)

def unload():
    # There is no necessity to unload, Python manages your memory for you. 
    return True
```

The main difference: we do not have our hash table, Python has built-in features. 

> Python handles all of that "magically" for you.
> - no `malloc()`;
> - no `free()`;
> - no pointers.
> 
> **BUT** Python have cons:
> - takes more RAM, may have an overhead;
> - slower than C.

---

### - Filter

Let's dive into Filter problem set from Week 4 and try to `blur` an image with Python.

```python
# Import a Python Image Library
from PIL import Image, ImageFilter

# Create variable
before = Image.open("bridge.bmp")

# Run filter
after = before.filter(ImageFilter.BoxBlur(10))

# Save the new image
after.save("out.bmp")
```

What about `edges` filter?

```python
from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("out.bmp")
```

### - Face detection

At first you need to install a library called face_recognition:

```commandline
pip install face_recognition
```

```python
# Find faces in picture
# https://github.com/ageitgey/face_recognition/blob/master/examples/find_faces_in_picture.py

from PIL import Image
import face_recognition

# Load the jpg file into a numpy array
image = face_recognition.load_image_file("office.jpg")

# Find all the faces in the image using the default HOG-based model.
# This method is fairly accurate, but not as accurate as the CNN model and not GPU accelerated.
# See also: find_faces_in_picture_cnn.py
face_locations = face_recognition.face_locations(image)

for face_location in face_locations:

    # Print the location of each face in this image
    top, right, bottom, left = face_location

    # You can access the actual face itself like this:
    face_image = image[top:bottom, left:right]
    pil_image = Image.fromarray(face_image)
    pil_image.show()
```

---

## Functions

```python
import CS50
```

As with C, the `CS50 library` can be utilized within Python:
- get_float
- get_int
- get_string

Import only specific functions from the CS50 library as follows:

```python
from CS50 import get_float, get_int, get_string
```

Let's implement a program that asking a name from a user and then greets him.

At first in C:

```c++
string answer = get_string("What's your name? ");
printf("hello, %s\n", answer);
```

Then in python:

```python
answer = get_string("What's your name? ")
print("hello, " + answer)
```

- there is no type for variable `answer`, python decide which type to use based on the given value;
- `+` plus operator joining the two strings together

You can also write like this:

```python
print("hello,", answer)
```

- Python will automatically add a space between the first and the second argument separated by comma `,`

Even weirder:

```python
print(f"hello, {answer}")
```

- The most common way nowadays to use format string or `f string` for short:
  - If you prefix the string with `f`, then you can use the curly braces `{}` inside of that string.

> Python already have a function `input()` that is the same as `get_string()`
>
> ```python
> answer = input("What's your name? ")
> print("hello, " + answer)
> ```

---

## Variables