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
  File "/workspaces/calculator.py", line 13, in <module>
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

### `if`

In C:

```c++
if (x < y)
{
  printf("x is less than y\n");
}
```

Python:

```python
if x < y:
    print("x is less than y")
```

- conditional statement not in parentheses `(...)`;
- no curly braces around, Python using `:` colon instead of them;
- in Python indentation is really important, when in C tabulation is a question of readability;

### What about `if ... else`?

C:

```c++
if (x < y)
{
  printf("x is less than y\n");
}
else
{
  printf("x is not less than y\n");
}
```

Python:

```python
if x < y:
    print("x is less than y")
else:
    print("x is not less than y")
```

### `if ... else if ... else`

C:

```c++
if (x < y)
{
  printf("x is less than y\n");
}
else if (x > y)
{
  printf("x is greater than y\n");
}
else
{
  printf("x is equal to y\n");
}
```

Python:

```python
if x < y:
    print("x is less than y")
elif x < y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

`elif` = `else if`

---

## Compare

### - `int`

`compare.py`

```python
from cs50 import get_int

x = get_int("What's x? ")
y = get_int("What's y? ")

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

### - `str`

```python
s = input("s: ")
t = input("t: ")

if s == t:
    print("Same")
else:
    print("Different")
```

In C string is a `char *`, so conditional `(s == t)` will always be false, `s` and `t` are located on different indexes.

> But Python is a higher-level language, where we don't work with pointers, only with values.

---

## Agree

At first, let's look on our code `agree` from one of the last weeks:

```c++
#include "cs50.h"
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? ");

    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }

    return 0;
}
```

In C we worked with upper-case and lower-case separately. What about Python?

```python
s = input("Do you agree? ")

if s == "Y" or s == "y":
    print("Agreed")
elif s == "N" or s == "n":
    print("Not agreed")
```

We can improve this code using Python data type `list`:

```python
s = input("Do you agree? ")

if s in ["y", "Y", "yes", "Yes", "YES", "YEs", "yES", "yEs", "YeS"]:
  print("Agreed")
elif s in ["n", "N", "no", "No", "NO", "nO"]:
  print("Not agreed")
```

But there is a problem: the list may become huge only because of the upper-lower-case variations.

We can do it better using `str` Python's data type.

> **Object-oriented programming** or **OOP**:
> Your data types cannot only have values, they can also have functionality built into them.
> 
> Strings in C should be lowercaseable, uppercaseable, capitalizable and so on.
>
> In Python's `str` all of those functions (tolower(), toupper(), isupper(), islower()) are built into the 
> strings themselves.
> 
> [Here](https://docs.python.org/3/library/stdtypes.html#string-methods) you can see all implemented methods in `str`.
> 
> > All up-to-date [Python documentation](https://docs.python.org/).

Let's improve again:

```python
s = input("Do you agree? ")

s = s.lower() 

if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not agreed")
```

Here we are converting the given string to lower-case before comparing. 

Remember struct from C? It works the same way:

- `s = s.lower()` - we have a variable `s` of data type `str`, separated it by dot `.`, we are going into `str` and
calling to method `lower()` within `str`.

✅ We can make it look simpler and _unite declaration with method_:

```python
s = input("Do you agree? ").lower() 

if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not agreed")
```

---

## Loops

> Let's get familiar with built-in functions within 
> [Python documentation](https://docs.python.org/3/library/functions.html).
>
> It is not a large list, but remember that much more functionality are built into data type themselves.

Now let's get back to loops.

`while` loop in C:

```c++
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
}
```

### - `while` loop

in Python:

```python
# while loop
i = 0
while i < 3:
  print("meow")
  i += 1
```

### - `for` loop

in Python:

```python 
# `for` loop
for i in [0, 1, 2]:
  print("meow")
  
# another more common `for` loop
for i in range(3):
  print("meow")
```

`range()` - method that returns a range of values, starting from `0`.

> Notice that `i` is never explicitly used. However, Python will increment the value of `i` for you.

Actually, we don't care so much for the name of `i`, it is not important, so we can also do this:
- `_` a valid character for a name, doesn't mean anything special. Just means that we need this variable only
for this loop.

```python
for _ in range(3):
  print("meow")
```

### - `forever` loop

in C: 

```c++
while(true)
{
  printf("meow");
}
```

in Python:

```c++
while True:
  print("meow")
```

> In Python `True` and `False` are capitalized.

---

## - uppercase.py

Let's write a program that will uppercase the given string:

```python
before = input("Before: ")

print("After: ")
for c in before:
    print(c.upper())
```

It will have an output like this:

```commandline
$ python uppercase.py
Before: cat
After: 
C
A
T
$
```

---

## Named parameters

We didn't want to the new line automatically inserted after `after`.

Let's talk about `named parameters`:
- we can pass in another argument to the `print()` function.

```python
before = input("Before: ")

print("After: ", end="")
for c in before:
  print(c.upper(), end="")
print()
```

- `end=""` - in Python by default we have `end="\0"`, with empty argument we are overriding this step.
- `print()` - an empty `print()` just prints a new line  `"\0"`

Output will be correct:

```commandline
$ python uppercase.py
Before: cat
After: CAT
$
```

Also, we will achieve the same result here:

```python
before = input("Before: ")
print("After: ", end="")
print(before.upper())
```

```commandline
$ python uppercase.py
Before: cat
After: CAT
$ 
```

Let's combine further:

```python
before = input("Before: ")
after = before.upper()
print(f"After: {after}")
```

And once more:

```python
before = input("Before: ")
print(f"After: {before.upper()}")
```

> We can put some code into curly braces with a variable. Just don't put a huge line of code for readability.
> 
> Named parameters as Positional parameters - matters the order in which you specify them, not something else.

---

## Abstraction

### - meow.py

`meow_1` will work, but it's not a good design:

```python
print("meow")
print("meow")
print("meow")
```

`meow_2` have a better way with `for` loop:

```python
for i in range(3):
    print("meow")
```

`meow_3` have a function:

```python
def meow():
  print("meow")

meow()
meow()
meow()
```

`meow_4` combines function with loop:

```python
def meow():
  print("meow")

for i in range(3):
    meow()
```

It will work. But like in C, we want to see in our `main()` only the main part of the program,
without function definitions at the top of the file.

> ❌ If we try to put definition at the bottom, the program will not work:

```python
for i in range(3):
  meow()

def meow():
  print("meow")
```

> We can define our main() in Python, although it's not necessary:

```python
def main():
    for i in range(3):
        meow()

        
def meow():
  print("meow")
```

❌ The output for `meow_5` will be **_empty_**.
- We didn't call `main()`

> ✅ `meow_6` Generally, the very last line of code in Python will be a call to `main()`.

```python
def main():
    for i in range(3):
        meow()

        
def meow():
  print("meow")

  
main()
```

Let's enhance implementation in `meow_7`.
- Parameterize and take an argument itself.

```python
def main():
    meow(3)

        
def meow(n):
  for i in range(n):
    print("meow")

  
main()
```

What we did here:
1. `def meow(n):` - we gave `meow()` a parameter `n`;
   2. inside `meow()` we have a loop with `range()` of `n`;
3. `meow(3)` - within `main()` we define `n` as `3`.

> We can also put a function into a library, import it from a file and make it usable by others.

---

## Truncation

Recall that in C, we experienced **_truncation_** where one integer being divided by another could result in an inprecise result.

You can see how Python handles such division as follows by modifying your code for `calculator_1.py`:

```python
x = int(input("x: "))
y = int(input("y: "))

z = x / y
print(z)
```

Output will be:

```commandline
$ python calculator_1.py
x: 3
y: 5
0.6
$ 
```

> We can see that Python doesn't truncate.
> 
> Python is smarter when it comes to converting one value to another.

## Floating Point imprecision

Whereby if you want to represent a number, like 1/3, and on a piece of paper it's, like 0.3 with a line over it.

Assume we want to see 50 decimal points:

```python
x = int(input("x: "))
y = int(input("y: "))

z = x / y
print(f"{z:.50f}")
```

- `{}` - curly braces indicates a variable within string
- `z:.50f` - `.50` the number of points we want to see,`f` at the end indicates a float value

Output:

```commandline
$ python calculator_1.py
x: 1
y: 3
0.33333333333333331482961625624739099293947219848633
$ 
```

As you can see we have a **_floating point imprecision_** here. 

You can use a third-party libraries to avoid this.

---

## Integer overflow

- If you count to high, you might accidentally overflow the capacity of an integer and end up going back 
to 0 or negative.

> _**There is no integer overflow in Python.**_
> 
> Integer will grow and grow as much as you need, if you have enough memory .

---

## Exceptions

`calculator_2.py` without exception:

```python
def get_int(prompt):
    return int(input(prompt))


def main():
    x = get_int("x: ")
    y = get_int("y: ")
     
    print(x + y)
    
    
main()
```

- double blanklines between definitions is a matter of readability

This code works, but if the user inputs words, there will be an error:

```commandline
$ python calculator_1.py
x: cat
Traceback (most recent call last):
  File "/workspaces/calculator_1.py", line 21, in <module>
    main()
  File "/workspaces/calculator_1.py", line 15, in main
    x = get_int("x: ")
        ^^^^^^^^^^^^^^
  File "/workspaces/calculator_1.py", line 11, in get_int
    return int(input(prompt))
           ^^^^^^^^^^^^^^^^^^
ValueError: invalid literal for int() with base 10: 'cat'
$ 
```

Let's look further into errors:
1. `line 21` calls a main function
2. `line 15` the real problem 
3. `ValueError` - the most common type of exception (also exist `NameError` and so on)

It was fixed in `cs50` lib, but how?

Now we will take a look on `calculator_3.py` with an exception:
 
```python
def get_int(prompt):
    try:
        return int(input(prompt))
    except ValueError:
        print("Not an integer")


def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)


main()
```

- `try` - literally means try, `try` demand for `except`, it will not work without `except`;
- `except` means except;
- `ValueError` - type of exception. 

'get_int' from cs50 lib continues to prompt the user for a number after the wrong input. We can do the same:

`calculator_4.py`

```python
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer")


def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)


main()
```

Now the program will continue to prompt for a number after the error explaining phrase.

We can do it silently also, without a phrase:

`calculator_5.py`

```python
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            pass


def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)


main()
```


- `pass` means just don't do anything.

---

## Mario

Let's revisit `mario_1` problem set from week 1.

```python
for i in range(3):
    print("#")
```

Now we can prompt for a height `mario_2`:

> There is no `do ... while` loop in Python.

```python
 from cs50 import get_int

# If there is a valid input break from the infinite loop
while True:
    n = get_int("Height: ")
    if n > 0:
        break

for i in range(n):
    print("#")
``` 

Let's make a horizontal version `mario_3.py`:

```python
for i in range(4):
    print("?", end="")
```

Or even like this `mario_4.py`:

```python
print("?" * 4)
```

Can we make a huge brick? `mario_5.py`:

```python
for i in range(3):
    for j in range(3):
        print("#")
```

Output for `mario_5.py`:

```commandline
$ python mario.py
#
#
#
#
#
#
#
#
#
$
```

Let's fix this in `mario_6.py`:

```python
for i in range(3):
    for j in range(3):
        print("#", end="")
    print()
```

or like in `mario_7.py`

```python
for i in range(3):
    print("#" * 3)
```

THe output will be correct:

```commandline
$ python mario.py
###
###
###
$ 
```

---

## Lists

List is like an `array[]` in C, but:
- size is automatically grow and shrink for you;
- no need to implement it, it already exists.

Python documentation for [lists](https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range).

Three basic sequence types:
- list
- tuple
- range objects

For example, if we wanted to taking averages of scores, we can do that using a combination of `list` and `len()`.

`len()` - calculate a length of a list, [len() documentation](https://docs.python.org/3/library/functions.html#len)

### - scores.py

Let's find an average of scores in `scores_1.py`:

```python
scores = [72, 73, 33]

average = sum(scores) / len(scores)
print(f"Average: {average:.1f}")
```

In `scores_2.py` we will prompt the user for scores:

```python
from cs50 import get_int

# Create an empty list
scores = []

for i in range(3):
     score = get_int("Score:  ")
     # Add new value onto the end
     scores.append(score)

average = sum(scores) / len(scores)
print(f"Average: {average:.1f}")
```

This variant will work too:

```python
for i in range(3):
     score = get_int("Score:  ")
     scores = scores + [score]
```

We are adding to lists `scores` and `[score]`.

### - phonebook.py

Let's implement a program `phonebook_1.py`, that will seek for a name from a list:

```python
names = ["Carter", "David", "John Harvard" ]

name = input("Name: ")

for n in names:
     if n == name:
           print("Found")
           break
print("Not found")
```

❌ It will have a wrong output:

```commandline
$ python phonebook.py 
Name: David
Found
Not found
```

Let's try again:

```python
names = ["Carter", "David", "John Harvard" ]

name = input("Name: ")

for n in names:
    if n == name:
        print("Found")
        break
    else:
        print("Not found")
```

❌ It will have a wrong output either:

```commandline
$ python phonebook.py 
Name: David
Not found
Found
```

What's wrong?
- in `phonebook_1.py` we break from a loop and then print "Not found" in every case;
- in `phonebook_2.py` we not found "David" at the first element and print "Not found", then we find "David"
in the next element and print "found".

✅ We can fix it in `phonebook_2.py`:

```python
names = ["Carter", "David", "John Harvard" ]

name = input("Name: ")

for n in names:
    if n == name:
        print("Found")
        break
else:
    print("Not found")
```

> In Python even `for` loops have an `else` clause:
> - If you break out of a loop
> - You get to the `else` clause

We can improve this code more and get rid of the loop in `phonebook_3.py`:

```python
names = ["Carter", "David", "John Harvard" ]

name = input("Name: ")

if name in names:
    print("Found")
else:
    print("Not found")
```

---

## Dictionaries

Python also have [dictionaries](https://docs.python.org/3/library/stdtypes.html#dict) - `dict`.

Let's rewrite phonebook using dictionaries in `phonebook_4.py`:

```python
people = [
    {"name": "Carter", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+1-617-495-1000"},
    {"name": "John", "number": "+1-949-468-2750"},
]

name = input("Name: ")

for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found: {number}")
        break
else:
    print("Not found")
```

- We make a list `people` of dictionaries with keys "name" and values "number";
- Within `for` loop we are searching for the needed data and put this dictionary "number" into variable `number`.

We can tighten the code in `phonebook_5.py`:

```python
people = [
    {"name": "Carter", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+1-617-495-1000"},
    {"name": "John", "number": "+1-949-468-2750"},
]

name = input("Name: ")

for person in people:
    if person["name"] == name:
        print(f"Found: {person['number']}")
        break
else:
    print("Not found")
```

- `print(f"Found: {person['number']}")` We used `''` within `""`, it is acceptable for clarifying the compiler
boundaries.

We can simplify our dictionaries in `phonebook_6.py`:

```python
people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-617-495-1000",
    "John": "+1-949-468-2750",
}

name = input("Name: ")

if name in people:
    number = people[name]
    print(f"Found: {number}")
else:
    print("Not found")
```

- Here we made just one dictionary instead of three.

---

## `sys` library

`sys` library have a system related functionality inside -
[Python documentation](https://docs.python.org/3/library/sys.html).

As with C, you can also utilize command-line arguments.

### - Command line arguments in Python

### -- `argv`

You can use `argc` and `argv` from the `sys` lib:

```python
from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")
```

It works!

```commandline
$ python greet.py 
hello, world
$ python greet.py ann
hello, ann
$ 
```

> There are three words at the prompt but command 'python' is ignored from 'argv'.

### -- `exit()`

Let's add an exit from a program in `greet_2.py`

```python
import sys

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)

```

> `sys.exit(1)` - an `exit()` function from `sys` can return values like it was in C.

---

## pip

Let's install some library with this command:

```commandline
$ pip install cowsay
```

```python
import cowsay

cowsay.cow("This is CS50")
```

```commandline
$ python moo.py 
  ____________
| This is CS50 |
  ============
            \
             \
               ^__^
               (oo)\_______
               (__)\       )\/\
                   ||----w |
                   ||     ||
$ 
```

```python
import cowsay

name = input("What's your name? ")
cowsay.cow(f"Hello, {name}")
```

```commandline
$ python moo.py 
What's your name? Ann
  ________________________
| Hello, Ann! This is CS50 |
  ========================
                        \
                         \
                           ^__^
                           (oo)\_______
                           (__)\       )\/\
                               ||----w |
                               ||     ||
$ 
```

Let's try something completely different:

```commandline
$ pip install qrcode
```

```commandline
import qrcode

img = qrcode.make("https://youtu.be/EHi0RDZ31VA")
img.save("qr.png", "PNG")
```

And we've got an image with a QR of this lecture!