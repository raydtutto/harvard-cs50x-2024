# Week 3: Algorithms

Instructor: **[David J. Malan](https://github.com/dmalan)**

---

## Linear Search

**Array** - a contiguous collection of data with the same type / consecutive blocks of memory.

Suppose there are these numbers in the array:

> **[1] [5] [10] [20] [50] [100] [500]**

We have 7 integers sorted from smallest to largest.

Imagine that you need to find the number '50' in that array.

Computer can only look at each location one at a time.

So, metaphorically, from the computer's point of view this array may look something like lockers:

<img src="img/01.png" alt="Array as lockers">

All numbers are there, but the doors are closed.

<img src="img/02.png" alt="Returning the value: true or false">

In the black box is an **algorithm** that search through our lockers to see
if the number 50 is behind one of the doors: Returning the value true or false.

```commandline
For each door from left to right
    If 50 is behind door
        Return true
Return false
```

-->

```c
For i from 0 to n-1
    If 50 is behind doors[i]
        Return true
Return false
```

> **Linear search** - an algorithm that search from left to from right or right to left.

---

## Binary search

> **Binary search** - an algorithm with divide and conquer approach, starting in the middle and then going
> left / right.

Pseudocode:

```commandline
If no doors left
    Return false
If 50 is behind middle door
    Return true
Else if 50 < middle door
    Search left half
Else if 50 > middle door
    Search right half
```

-->

```c
If no doors left
    Return false
If 50 is behind doors[middle]
    Return true
Else if 50 < doors[middle]
    Search doors[0] through doors[middle - 1]
Else if 50 > doors[middle]
    Search doors[middle + 1] through doors[n - 1]
```

---

## Running time

Running time involves an analysis using **big O notation**:

<img src="img/03.png" alt="Array as lockers">

- O(n) - very slow: one page at a time;
- O(n) - twice faster but still slow: two page at a time;
- O(log n) - the best approach: you take 'n' and divide it in two by two again and again till the required result.

Some common running times we may see are:

- `O(n2)` - _quadratic_
- `O(n log n)` - _linearithmic_
- `O(n)` - _linear_
- `O(log n)` - _logarithmic_
- `O(1)` - _constant_

Of the running times above, ```O(n2)``` is considered the worst running time, ```O(1)``` is the fastest.

> **Linear search** was of order ```O(n)``` because it could take n steps in the worst case to run.
> **Binary search** was of order ```O(log n)``` because it would take fewer and fewer steps to run even in the worst case.

Programmers are interested in both the worst case, or _**upper bound**_, and the best case, or _**lower bound**_.

> The symbol ```Ω``` (Omega) is used to denote the best case of an algorithm, such as ```Ω(log n)```.
>
> - `Ω(n2)`, `Ω(n log n)`, `Ω(n)`, `Ω(log n)`, `Ω(1)`

> The symbol ```Θ``` (Theta) is used to denote where the upper bound and lower bound are the same, where the best case
> and the worst case running times are the same.
>
> - `Θ(n2)`, `Θ(n log n)`, `Θ(n)`, `Θ(log n)`, `Θ(1)`

---

## search.c

Implementing a linear search:

### Variant 1
In this case program will tell us "Not found." every time when the number is not the required one - bad design.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Number: ");

    for (int i = 0; i < 7; ++i)
    {
        if (numbers[i] == n)
        {
            printf("Found.\n");
        }
        else
        {
            printf("Not found.\n"); // bad design
        }
    }

    return 0;
}
```

### Variant 2
Here is the new bug: it will print "Not found." after the search loop on each run of the program - bad design too.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Number: ");

    for (int i = 0; i < 7; ++i)
    {
        if (numbers[i] == n)
        {
            printf("Found.\n");
        }
    }
    printf("Not found.\n"); // bad design

    return 0;
}
```

### Variant 3
Now it will exit the program after finding the number.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Number: ");

    for (int i = 0; i < 7; ++i)
    {
        if (numbers[i] == n)
        {
            printf("Found.\n");
            return 0; // exit with success result
        }
    }
    printf("Not found.\n");
    return 1; // exit with error
}
```

### String compare #1
```if (strings[i] == s)``` will not work correctly, because equal will compare the first character of the string
and not the whole word. So the required word will never be found.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");

    for (int i = 0, length = strlen(strings); i < length; ++i)
    {
        if (strings[i] == s)
        {
            printf("Found.\n");
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}
```

### String compare #2
```strcmp(strings[i], s) == 0)``` will compare two strings correctly.

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h> // for strcmp()

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");

    for (int i = 0, length = strlen(strings); i < length; ++i)
    {
        if (strcmp(strings[i], s) == 0) // strcmp() - compares two strings
        {
            printf("Found.\n");
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}
```

---

## phonebook.c

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>
```