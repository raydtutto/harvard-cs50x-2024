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
- O(log2n) - the best approach: you take 'n' and divide it in two by two again and again till the required result.

