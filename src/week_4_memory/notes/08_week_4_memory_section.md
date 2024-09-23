# Week 4: Memory / Section

Instructor: [**Carter Zenke**](https://github.com/carterzenke)

---

## Pointers

At first, let's create a variable `calls`.

> A **_variable_** is a name for some value that can change.

| calls |
|-------|
| 3     |

A variable need to be stored somewhere, so all variables have an _**address**_ inside the computer's memory.

Let's try to visualize our variable `calls` in the memory:

| Address    | Value | Name        | Code             |
|------------|-------|-------------|------------------|
| 0x50000000 | 3     | _**calls**_ | `int calls = 3;` |
| 0x50000004 | ...   |             |                  |
| 0x50000008 | ...   |             |                  |

Then we can create a pointer `p` that points to `calls`:

| Address    | Value      | Name        | Code               |
|------------|------------|-------------|--------------------|
| 0x50000000 | 3          | _**calls**_ | `int calls = 3;`   |
| 0x50000004 | 0x50000000 | _**p**_     | `int *p = &calls;` |
| 0x50000008 | ...        |             |                    |

- `p` is a name of our pointer;
- `int *` is a pointer that stores the address of a type.
- `&x` takes `x` and gets its address.
- `*x` takes a pointer `x` and gets the value stored at that address.

> #### Reasons to use pointers:
> - You can pass variables to functions **by reference**, not just **by copy**. --> _The code you write is cleaner
> as a result._
> - You can use **dynamic memory** (e.g., with `malloc()`). --> _Your programs can now scale their usage of memory according
> to user behavior._

---

## Passing by Copy

```c++
#include <cs50.h>
#include <stdio.h>

void swap(int a, int b) // passing by copy
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    // using swap() 
}
```

### main

Inside `main()` we have two variables that we want to swap: 

| a    | b    |
|------|------|
| `10` | `50` |

We write `swap()` for the needed operation and it works, but it works only in `swap()` stack frame
and then terminates itself:

### swap

| a    | b    |
|------|------|
| `50` | `10` |

---->

### main

As a result, we have our variables from `main()` as they were before:

| a    | b    |
|------|------|
| `10` | `50` |

---

## Passing by Reference

```c++
#include <cs50.h>
#include <stdio.h>

void swap(int *a, int *b) // passing by reference
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 10, b = 50;
    swap(&a, &b); 
}
```

### main

Inside `main()` we have two variables that we want to swap:

| a    | b    |
|------|------|
| `10` | `50` |

This time we pass by reference at `swap()`. So at the stack frame we have two pointers to our variables from `main()`:

### swap

| pointer `*a` to `a` from `main()` | pointer `*b` to `b` from `main()` |
|-----------------------------------|-----------------------------------|
| address of `a`                    | address of `b`                    |

### main

`swap()` completes all operations inside and swaps variables in `main()`:

| a    | b    |
|------|------|
| `50` | `10` |

---

## File I/O

### - Opening & Closing:
- `fopen()` opens a file for future reading/writing.
- `fclose()` closes a file.

> Always `fclose()` all files you `fopen()`!

```c++
FILE *f = fopen("hi.txt", "r");
fclose(f);
```

### - Reading and Writing
- `fread()` reads data from a file into a buffer*.
- `fwrite()` writes data from a buffer* to a file.

Assume that we have a file `hi.txt` with a word `hi!` in it.

- When we read it with `fread()`, our variable gets string `hi!` from the file.
- After we use `fwrite()` to add string `bye!` to the file, the inner text within `hi.txt` will change like this `hi!bye!`

> `buffer` is a chunk of memory that can temporarily store some data from the file.

#### `fread()` - Reading from a File

```c++
// Template
fread(to where, what size, how many, from where);

// Example
fread(buffer, 1, 4, f);
```

#### `fwrite()` - Writing to a File

```c++
// Template
fread(to where, what size, how many, from where);

// Example
fwrite(buffer, 1, 4, f);
```

---

## Practice with reading

Create a program, `pdf.c`, that opens a file given as a command-line argument.

Check if that file is a `PDF`. PDF always begins with a four-byte sequence, corresponding to these integers: `37`, `80`, `68`, `70`

```c++
#include <cs50.h>
#include <stdio.h>
#include <stdint.h> // for uint8_t

int main(int argc, string argv[])
{
    string filename = argv[1];

    // Opens the file
    FILE *f = fopen(filename, "r");

    // Reads the file
    uint8_t buffer[4];
    int blocks_read = fread(buffer, 1, 4, f);

    // Prints buffered data
    for (int i = 0; i < 4; ++i)
    {
        printf("%i\n", buffer[i]);
    }
    printf("Blocks read: %i\n", blocks_read);

    // Closes the file
    fclose(f);

    return 0;
}
```