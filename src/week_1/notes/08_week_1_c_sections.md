# Week 1: C / Sections

Preceptor: **Carter Zenke**

---

Goal of sections is to help to bridge the gap between lectures and problem sets.

### Structure

1. Variables and types
2. Input and Printing
3. Functions, Loops and conditionals
4. Problem set 1

---

# 1. Variables and types

***Variable*** - a name for some value that can change.

```c
int country_code = 65; // (type) (name) (assignment operator) (value)
```
Command looks like this in one sentence:  
"Create an **integer** named **"country_code"** that **gets** the value **65**."

- *Why have data types?*

```c
char country_code = 65; // The output will be 'A' instead of '65'
```

Binary code: 01000001 = int 65 = char 'A'

### Operators

```c
int calls = 4;
calls = calls + 2;
calls = calls - 1;
calls = calls * 2;
calls = calls / 2;
```

"Syntactic sugar" to shorten these lines:

```c
int calls = 4;
calls += 2; // = calls = calls + 2;
calls -= 1; // = calls = calls - 1;
calls *= 2; // = calls = calls * 2;
calls /= 2; // = calls = calls / 2;
```

Let's look at this:

```c
int calls = 4;
calls = calls + 1; // 5
calls = calls - 2; // 3
calls = calls * 3; // 9
calls = calls / 2; // 4.5 and then get rid of the '.5'
// int calls = 4
```

The output will be: '4' instead of '4.5' because of an integer variable holding this value, here we can see
the truncation process. e.g. If you want to have '4.5' use float type.

---

# 2. Input and Printing

### How to get an input from the user

```c
int calls = get_int("Calls: ");
```
This line will first call a function and then assign the value to the variable.

*get_int("Calls: ")* - a function call.

### How to print it

```c
int calls = 4;
printf("calls is %i\n", calls) // printf = print formatted

// Output: "calls is 4"
```

- *%i* - a format code for integer
- *%f* - a format code for float
- *%c* - a format code for char
- *%s* - a format code for string

---

# 3. Functions, Loops and conditionals

### Loops
#### while ...
Executes while condition is true.

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    int j = 0;
    while (j < 8)
    {
        printf("#");
        j++;
    }
    printf("\n");
}

// Output
####
```

#### for ...
Executes exact number of times.

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int j = 0; j < 4; j++)
    {
        printf("#");
    }
    printf("\n");
}

// Output
####
```

To type multiple "#" lines:

```c
for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 4; j++)
    {
        printf("#");
    }
    printf("\n");
}

// Output
####
####
####
####
```

### Functions

CS50 Function for getting integer from user.

```c
int get_int(string prompt)
{
    // Get int from user
}
```

### Mario
Let's print a left-aligned pyramid with a height prompt by a user.

```c
#include <cs50.h>
#include <stdio.h>

// Function declaration
void print_row(int lenght);

// Main program
int main(int argc, char *argv[])
{
    int height = get_int("Height: ");

    for (int i = 0; i < height; i++)
    {
        print_row(i + 1);
    }
}

// Function definition
void print_row(int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        printf("#");
    }
    printf("\n");
}
```
