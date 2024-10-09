# Python

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

Python is an example of a very commonly-used modern programming language.
- C was first released in 1972, Python in 1991.

Python is an excellent and versatile language choice for making complex C operations much simpler:
- String manipulation
- Networking

Fortunately, Python is heavily inspired by C (its primary interpreter, Cpython, is actually written in C)
and so the syntax should be a shallow learning curve.

To start writing Python, open up a file with the `.py` file extension.

Unlike a C program, which typically has to be compiled before you can run it,
a Python program can be run without explicitly compiling it first.

> #### Important note
> In CS50, we teach Python 3. (Not Python 2, which is also still fairly popular.)

---

## Variables

Python variables have two big differences from C:
- No type specifier;
- Declared by initialization only;
- Python statements needn't end with semicolons. 

```python
x = 54
phrase_1 = "This is CS50"
phrase_2 = 'This is CS50'
```

---

## Conditionals

> Indentations are very important in Python

All the old favorites from C are still available for you to use, but they look a little bit different now.

### `if ... else`
```python
if y < 43 or z == 15:
    # Code goes here
else:
    # code block 2



if y < 43 and z == 15:
    # code block 1
```

- `or` is `||` from C
- `and` is `&&` from C
- `#` indicates a comment on the line

### `if ... else if`

```python
if coursenum == 50:
    # code block 1
elif not coursenum == 51:
    # code block 2
```

- `elif` is `else if` from C
- `not` like `!` from C inverse the statement

### Ternary conditional operator

We had in C a ternary operator:

```c++
// Ternary conditional operator in C
char var = get_char();
bool alphabetic = isalpha(var) ? true : false;
```

In Python we have this:

```python
# Ternary conditional operator in Python
letters_only = True if input().isalpha() else False
```

- `True` and `False` are capitalized in Python;
- `input()` collects the user's input

---

## Loops

> There are two kinds of loops:
> - `while`
> - `for`

_There are no `do ... while` loop in Python._

### `while`

```python
counter = 0
while counter < 100:
    print(counter)
    counter += 1
```

- `counter += 1` - Python does not include `++` and `--`
- `print(counter)` - function `print()` will print a new line `\0` for by default.

### `for`

```python
for x in range(100):
    print(x)

# or

for x in range(0, 100, 2):
    print(x)
```

- `range(n)` gives us a list from `0` to `n`
- `range(0, 100, 2)` - (`start point`, `end point`, `how much to skip`): 0, 2, 4, 6,  8, etc

---

## `Lists` or arrays

- Python arrays (more appropriately known as `lists`) are **_not fixed in size_**;
- They can **_grow_** or **_shrink_** as needed;
- You can always **_tack extra_** elements onto your array and **_splice_** things in and out easily.

Declaring a list is pretty straightforward.

You can declare a list without definition with _square brackets_ `[]`:

```python
nums = []
```

Instead of a square bracket syntax, we can use a function `list()`, that returns an empty list.

```python
nums = list()
```

Or with definition:

```python
nums = [1, 2, 3, 4]
```

### - List comprehension

We can use a `for` loop to generate a list of numbers for us:
- newlist = [`expression` for `item` in `iterable if condition == True`]

```python
# Example of a list comprehension
nums = [x for x in range(500)]
```

- Creates a list `nums` of 500 elements, all the numbers from 0 to 499

### - Append

```python
nums = [1, 2, 3, 4]
nums.append(5)
```

- `append(n)` - a function that attaches an element `n` to the end of the list.

### - Insert

```python
nums = [1, 2, 3, 4]
nums.insert(4, 5)
```

- `insert(x, y)` - attaches an element `y` to the `x` index of the list.

```python
nums = [1, 2, 3, 4]
nums[len(nums):] = [5]
```

It is doing the same:
- `nums[len(nums):]` The `nums` list from position `4`, which is the length of the list;
- `= [5]` creates an unnamed list with a single element;
- Then it attaches an unnamed list to the existed list.

- `len()` works just like `strlen()`, but calculates the length of any arbitrary lists.

---

## Tuples

Python also has a data type that is not quite like anything comparable to C, a `tuple`.

`Tuples` are ordered, immutable sets of data.
- `Tuples` use parenthesis `()` for definition.

They are great for associating collections of data, sort of like a struct in C,
but where those values are unlikely to change.

Here is a `presidents` list that contains 4 tuples:

```python
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809)
]
```

- `(...)` indicates a tuple;
- `,` - separates items in a larger list.

We can iterate over this list:

```python
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809)
]

for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))
```

- `{1}`, `{0}` instead of `%s` from C;
- Here `{0} = prez` and `{1} = year` - We are specifying the order in which those parameters to come out.
- `.format()` method that we use at the end of a `print()` function

So, we get a list and then print its elements in a reverse order.

The output:

```
In 1789, George Washington took office
In 1797, John Adams took office
In 1801, Thomas Jefferson took office
In 1809, James Madison took office
```

---

## Dictionaries

Python also has built in support for dictionaries `dict`, allowing you to **_specify list indices with words_**
or **_phrases_** (keys), instead of integers, which you were restricted to in C.

- `dict` use curly braces `{}` for definition:

```python
pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}
```

- `"cheese"`, `"pepperoni"` and others are keys;
- `: n` - colon `:` separates key-value pair;
- `,` separates keys.

### - Change the value

We can change values of different key values from dictionaries:

```python
pizzas["cheese"] = 8
```

### - Use keys in conditionals

We can use them in conditionals:

```python
if pizza["vegetables"] < 12:
    # do something
```

### - Add a new key

We can add new key:

```python
pizzas["bacon"] = 14
```

> Python also has built in support for dictionaries, allowing you to specify list indices with words or phrases (keys),
> instead of integers, which you were restricted to in C.
> 
> ### There is a new problem:
> **_How do we iterate through a dictionary?_**  
> We don't have indexes ranging from [`0`, `n-1`] anymore.

### Loop through within dictionary (redux)

The for loop in Python is extremely flexible:

```python
for pie in pizzas:
    # use pie in here as a stand-in for "i"
```

Let's print out a list of all the keys in the dictionary and prices from it:
```python
# Define a dictionary
pizzas = {
"cheese": 9,
"pepperoni": 10,
"vegetable": 11,
"buffalo chicken": 12
}

# 1. Iterate over keys
for pie in pizzas:
    print(pie)

# or

# 2. Iterate over values
for pie, price in pizzas.items():
    print(price)
```
1. Prints all the keys
2. Prints all the prices using function `items()`, that transforms a dictionary into a list to iterate over values.

But be careful:

The prices output may not be in original order:
```
12
10
9
11
```

But usually it's not the case and you can specify the order manually.

Let's print the key and the value:

```python
for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie, price))
```

- `{}` there are no numbers like it was in the previous example, because we do not want to invert the order of elements;
- `.format(pie, price)`

Output:

```
A whole buffalo chicken pizza costs $12
A whole cheese pizza costs $9
A whole vegetable pizza costs $11
A whole pepperoni pizza costs $10
```

---

## Printing and variable interpolation

Format gives one way to interpolate variables into our printed statements in a very printf-like way,
but there are others.

```python
print("A whole {} pizza costs ${}".format(pie, price))

# Concatenate strings together.
# There are no interpolation, just plugging in the variables pie and price.
# `price` is transformed into a string.
# We need all the variables inside be strings, so it works correctly.
print("A whole " + pie + " pizza costs $" + str(price))
```

❌ Be familiar with syntax from Python 2, but do not use it in Python 3, it's deprecated:

```python
# Python 2 syntax
print("A whole %s pizza costs $%2d" % (pie, price))
```

---

## Functions

Python has support for functions as well. Like variables, we don't need to specify the return type
of the function (because it doesn't matter), nor the data types of any parameters (ditto).

All functions are introduced with the `def` keyword:
- Also, no need for `main()`;
- The interpreter reads from top to bottom;
- If you wish to define main nonetheless (and you might want to), you must at the very end of your code have:

```python
if __name__ == "__main__":
    main()
```

Square function declaration:

```python
def square(x):
    return x * x
```

Another variant:

```python
def square(x):
    return x ** 2
```

- `**` is an exponentiation operator, equivalent to `pow()` from C.

We can also write our own square function by adding x to itself:

```python
def square(x):
    result = 0
    for i in range(0, x):
        result += x
    return result

print(square(5))
```

---

## Objects

Python is an object-oriented programming language.

An object is sort of analogous to a C `structure`.

_In C structures contain a number of fields, which we might also call properties, but the properties
themselves can not ever stand on their own._

```c++
// C example
struct car
{
    int year;
    char *model;
}

struct car herbie;
herbie.year = 1963;
herbie.model = "Beetle";
```

Objects, meanwhile, have properties but also methods, or functions that are inherent to the object, and mean
nothing outside of it. You define the methods inside the object also.
- Thus, properties and methods don’t ever stand on their own.

> We don't pass objects into a function `function(object)`, we call methods on objects `object.method()`.

You define a type of object using the `class` keyword in Python.

Classes require an initialization function, also more-generally known as a `constructor`, which sets the starting
values of the properties of the object.

In defining each method of an object, `self` should be its first parameter, which stipulates on what object
the method is called.

We have a class called `Student`:
- three functions;
- the first function is a constructor, so our Student have two properties: name and ID;
- because we are defining a method inside of that class, we always have to include `self` parameter,
to know what object we are talking about.
- Inside the constructor we're assigning the `name` and `ID` properties of the `Student` object to whatever we pass here.
- The second function `changeID()` changes the `ID` of a `Student`.
- `print()`, which takes one parameter, but prints out two properties.

> `self` always has to be a part of any `methods` that you define for a `class`. 

```python
# Python class
class Student():
    def __init__(self, name, id):
        self.name = name
        self.id = id
    def changeID(self, id):
        self.id = id
    def print(self):
        print("{} – {}".format(self.name, self.id))
```

In the next code:
- Creating a new object `jane`;
- `Student()` calls the constructor function, initialize `jane` with name "Jane" and ID 10;
- `jane.print()` prints "Jane - 10";
- `jane.changeID(11)` changes ID property to 11;
- `jane.print()` prints "Jane - 11".

```python
jane = Student("Jane", 10)
jane.print()
jane.changeID(11)
jane.print()
```

---

## Style

If you haven't noticed, good style is **_crucial_** in Python.

Tabs and indentation actually matter in this language, and things will not work the way you intend for them
to if you disregard styling.

- No more curly braces to delineate blocks! Now they just are used to declare dictionaries.

---

## Including files

Just like C programs can consist of multiple files to form a single program, so can Python programs tie files together.

```
import cs50
```

Inside cs50 lib we have `get_int()`, `get_float()`, `get_string()`

We can also include functions selectively:

```
from cs50 import get_int, get_float()
```

Python programs can be prewritten in `.py` files, but you can also write and test short Python snippets using
the Python interpreter from the command line.

All that is required is that the Python interpreter is installed on the system you wish to run your Python programs on.

---

## Run a program

To run your Python program through the Python interpreter at the command-line, simply type:

```
python <file>
```

Your program will run through the interpreter, which will execute everything inside the file, top to bottom.

You can also make your programs look a lot more like C programs when they execute by adding a `shebang`
to the top of your Python files, which automatically finds and executes the interpreter for you.

```python
#!/usr/bin/env python3

# your program
```
 
If you do this, you need to change the permissions on your file as well using the Linux command chmod as follows:

```
chmod a+x <file>
```