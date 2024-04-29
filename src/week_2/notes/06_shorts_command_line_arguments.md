# Command Line Arguments

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

So far, all of your programs have begun pretty much
the same way:

```c
int main(void)
{
    ...
}
```

Since we’ve been collecting user input through in program prompts, we haven’t needed to modify
this declaration of ```main()```.

> If we want the user to provide data to our program
> before the program starts running, we need a new form.

To collect so called command-line arguments from
the user, declare main as:

```c
int main(int argc, string argv[])
{
    ...
}
```

These two special arguments enable you to know
what data the user provided at the command line
and how much data they provided.

### _argc_

_An argument count._

This ```integer```-type variable will store the number of
command-line arguments the user typed when the
program was executed.

| command            | argc |
|--------------------|------|
| ./greedy           | 1    |
| ./greedy 1024 cs50 | 3    |

### _argv_

_An argument vector._ (vector in C - another word for an array)

This array of ```strings``` stores, one string per element, the
actual text the user typed at the command-line when
the program was executed.

- The first element of argv is always found at ```argv[0]``` and contains file name.
- The last element of argv is always found at ```argv[argc-1]```.

---

Let’s assume the user executes the greedy program as follows:

```commandline
./greedy 1024 cs50
```

| argv indices | argv contents |
|--------------|---------------|
| argv[0]      | "./greedy"    |
| argv[1]      | "1024"        |
| argv[2]      | "cs50"        |
| argv[3]      | ???           |

**"1024"** is a ```string``` of characters, not an integer.
We can convert strings to another data types using a functions from ```stdlib.h```:

- ```atof``` - convert a string to a float
- ```atoi``` - convert a string to an int
- ```atol``` - convert a string to a long

With **argv[3]** we're overstepping the bounds of an array. The compiler will do it and may return something unexpected.