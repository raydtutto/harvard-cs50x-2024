# Week 5: Data structures

Instructor: **[David J. Malan](https://github.com/dmalan)**

---

## Data Structures

> `Data structures` essentially are forms of organization in memory.

There are many ways to organize data in memory:

`Abstract data structures` are those that we can conceptually imagine.

---

## Queues

> `Queues` are one form of abstract data structure.

`Queues` have:
- **specific property**:
  - `FIFO` or “first in first out.”
- **specific actions**:
  - `enqueued`; that is, the item can join the line or queue.
  - `dequeued` or leave the queue once it reaches the front of the line.

Imagine a `queue` as follows:
```c++
const int CAPACITY = 50;

typedef struct
{
    // Stored all data one after the other contiguously
    person people[CAPACITY];
    int size;
}
queue;
```

>**Queues contrast a stack**.

## Stack

`Stack` has:
- **specific property**:
  - `LIFO` or “last in first out.”
- **specific actions**:
  - `push` places something on top of a stack.
  - `pop` is removing something from the top of the stack.

`stack` is implemented almost identically to `queue`:
```c++
typedef struct
{
    // How high the stack could be
    person people[CAPACITY];
    // How full the stack actually is, regardless of how much it could hold
    int size;
}
stack;
```

> **Array** stores the data contiguously back to back.

You might imagine that the above code has a limitation. Since the capacity of the array is always predetermined
in this code. Therefore, the `stack may always be oversized`. You might imagine only using one place in the
stack out of 5000.

It would be nice for our stack to be dynamic – able to grow as items are added to it.

---

## Resizing Arrays

Imagine an array as follows:

<img src="img/01.png" alt="Array 1">

In memory, there are other values being stored by other programs, functions, and variables.
Many of these may be unused `garbage values` that were utilized at one point but are available now for use.

<img src="img/02.png" alt="Array 2">

What if we want to store a fourth value `4` in our array?

What would be needed is to allocate a new area of memory and move the old array to a new one.
Initially, this new area of memory would be populated with garbage values.

<img src="img/03.png" alt="Array 3">

As values are added to this new area of memory, old garbage values would be overwritten.

<img src="img/04.png" alt="Array 4">

Eventually, all old garbage values would be overwritten with our new data.

<img src="img/05.png" alt="Array 5">

One of the drawbacks of this approach is that it’s bad design: Every time we add a number,
we have to copy the array item by item.

> But wouldn’t it be nice if we were able to put the 4 somewhere else in memory?
>
> By definition, this would no longer be an array because 4 would no longer be in contiguous memory.

---

## `list` array and malloc()

Let's write code `list_1` as follows:

```c++
// Implements a list of numbers with an array of fixed size

#include <stdio.h>

int main(void)
{
    // List of size 3
    int list[3];

    // Initialize list with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Print list
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}
```

We have memory being preallocated for three items.

```c++
// Could not be modified
int list[3];
```

> Then we can use pointers to create a better design in this code.

Modify your code as follows in `list_2`:

```c++
// Implements a list of numbers with an array of dynamic size

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
// List of size 3
int *list = malloc(3 * sizeof(int));
if (list == NULL)
{
return 1;
}

    // Initialize list of size 3 with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // List of size 4
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // Copy list of size 3 into list of size 4
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    // Add number to list of size 4
    tmp[3] = 4;

    // Free list of size 3
    free(list);

    // Remember list of size 4
    list = tmp;

    // Print list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free list
    free(list);
    return 0;
}
```

1. The `list` of size three integers is created.
2. Then, three memory addresses can be assignded the values 1, 2, and 3.
3. Then, a `tmp` list of size four is created.
4. Next, the list is copied from the first to the second.
5. The value for the 4 is added to the `tmp` list.
6. Since the block of memory that list points to is no longer used, it is freed using the command `free(list)`.
7. Finally, the compiler is told to point `list` pointer now to the block of memory that `tmp` points to.
8. The contents of list are printed and then freed.

> Technically, by the end of the above code, `tmp` and `list` both pointed to the same block of memory.

---

## Linked list

The syntax that we need to make a `linked list`:

- `struct`
- `.` dot operator. Using to get inside the structure.
- `*` to dereference the pointer (on the last week we used it only to declare a pointer). 
- `->` it is the combination of `*` and `.` - goes to an address and looks inside a structure.

A `linked list` is one of the most powerful data structures within `C`:

- Allows you to include values that are located at varying areas of memory;
- Further, they allow you to dynamically grow and shrink the list as you desire.

Imagine three values stored at three different areas of memory as follows:

<img src="img/06.png" alt="Linked list 1">

How could one stitch together these values in a list?

We could imagine this data pictured above as follows with `pointers`:

<img src="img/07.png" alt="Linked list 2">

We could utilize more memory to keep track of where the next item is.

<img src="img/08.png" alt="Linked list 3">

> Notice that `NULL` is utilized to indicate that nothing else is next in the list.

> By convention, we would keep `one more element` in memory, a `pointer`, that keeps track of the first item in the list.

<img src="img/09.png" alt="Linked list 4">

Abstracting away the memory addresses, the list would appear as follows:

<img src="img/10.png" alt="Linked list 5">

These boxes are called nodes. A node contains both an item and a pointer called next.

In code, you can imagine a node as follows:

```c++
typedef
{
    int number;
    // Next line will cause an error:
    // The node is not declared yet on this line of code
    node *next;
} node;
```

The good template will be:

```c++
typedef struct node 
{
    int number;
    struct node *next;
} node; // this line just shrink `struct node` to `node`
```

- Notice that the item contained within this node is an integer called number.
- Second, a pointer to a node called next is included, which will point to another node somewhere in memory.

---

## Creating a linked list

