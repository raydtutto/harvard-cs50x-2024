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

Variable declaration is simplified too. You need not declare the type of the variable.

```python
counter = 0

# You can do Simple math
counter = counter + 1
counter += 1
```

❌ Python does not include this syntax:
- `++`
- `--`

---

## Types

Data types in Python do not need to be explicitly declared.

For example, you saw how `answer` above is a string, but we did not have to tell the interpreter this was the case:
- It knew data type on its own.

In Python, commonly used types include:
- `bool`
- `float`
- `int`
- `str` (`string` from C)

Notice that `long` and `double` are missing.

Python will handle what data type should be used for larger and smaller numbers.

Some other data types in Python include:
- `range` of values
- `list` of values (like an array but better)
- `tuple` (similar to list, but immutable)
- `dict` (hash tables for free)
- `set` (collection of values, that gets rid of any duplicates)

> Each of these data types can be implemented in C, but in Python they can be implemented more simply.

For Python cs50 lib provide this functions:
- `get_float`
- `get_int`
- `get_string` (that is `str` in Python)

---

## Calculator

Let's write simple calculator to sum up given numbers in C:

```c++
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", x + y);
    return 0;
}
```

And then in Python:

```python
from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

print(x + y)
```

If `x` = 1 and `y` = 2  
Output is correct: `3`

Now try the same but without cs50 lib:

```python
x = input("x: ")
y = input("y: ")

print(x + y)
```

Output is incorrect for our goal: `12`

> Python thinks that `x`, `y` are strings.

We need to define that we are using integers:

```python
# Convert x and y to integers
x = int(input("x: "))
y = int(input("y: "))

print(x + y)
```

Now the output is correct: `3`

There is also another way to convert data types:

```python
x = input("x: ")
x = int(x)
y = input("y: ")
y = int(y)

print(x + y)
```

And another way:

```python
x = input("x: ")
y = input("y: ")

print(int(x) + int(y))
```

> In Python we are _**casting**_ data types not _**converting**_ like it was in C.

It is better to use `get_int` and `get_float` from cs50 lib. Here is an explanation:

```python
x = int(input("x: "))
y = int(input("y: "))

print(x + y)
```

If the user give us numbers, everything will be as planned.

❌ But if the user give us some words, we're going to see a runtime error.

```commandline
x: fg
Traceback (most recent call last):
  File "/workspaces/160549765/calculator.py", line 13, in <module>
    x = int(input("x: "))
        ^^^^^^^^^^^^^^^^^
ValueError: invalid literal for int() with base 10: 'cat'
```

Simply, it just said that the cat is not an integer.

> ❌ Python's `int()` conversion cannot convert str to int.
> 
> ✅ So, it's safer to use `get_int` and `get_float` from cs50 lib.
> 
> They will prompt the user for an integer or float until the user provides it to us.
> 
> ```python
> from cs50 import get_float, get_int, get_string
> ```

There is another way to use functions from libraries:
- It helps when you have multiple libraries included and functions with the same names;
- You can clarify from which library you need the function to work.

```python
import cs50

x = cs50.get_int(input("x: "))
y = cs50.get_int(input("y: "))

print(x + y)
```

---

## Conditionals