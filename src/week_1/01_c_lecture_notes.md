# Week 1: C
    #include <stdio.h>
    
    int main(void)
    {
        printf("Hello, world\n"); // function
    }

## Source code
Computer understands only machine code.

*source code* -> [ **compiler** ] -> *machine code*

Compiler - is a program that translates one language to another.

## Hello, world
**Visual Studio Code** - the integrated development environment (IDE)

**Terminal window** - is a command line interface, known as a CLI, command line, or terminal window where we can
send commands to the computer in the cloud

Three commands in terminal to write, compile, and run our first program:

    $ code hello.c
    // Creates a file and allows us to type instructions for this program.

    $ make hello
    // Compiles the file from our instructions in C and creates an executable file called "hello"

    $ ./hello
    // Runs the program called "hello"

    $ - is not a part of your command, this is a common convention to represent your prompt.

Rules:
- Name your files with lower keys in most of the cases;
- Never use spaces;
- File extension is always in lower keys;

Source file: *src/week_1/hello.c*

    #include <stdio.h>

    int main(void)
    {
        printf("hello, world\n");
    }

**'printf'** is a function that can output a line of text.  
**'\n'** creates a new line after the words.

*arguments* -> [ **function** ] -> *side effects*

## Libraries
Collections of pre-written functions that others have written in the past that we can utilize in our code.

CS50 has its own library called cs50.h

Manual pages - [manual.cs50.io](https://manual.cs50.io/)

## Hello, world + name
*arguments* -> [ **function** ] -> *return value*

Task: Get a name and greet the user.

Let's use the function from cs50 library:

    string name = get_string("What's your name? ");


- *get_print* - prompt a user for a string;
- *string* - data type of variable;
- *name* - is the string being passed to %s.

*Variable* is a special holding place.  
*%s* is a placeholder called a format code that tells the 'printf' function to prepare to receive a string.

    #include <stdio.h>
    #include <cs50.h>

    int main(void)
    {
        string answer = get_string("What's your name? ");
        printf("Hello, %s\n", answer);
    }

Type *'clear'* in the terminal to clear all commands, just for the comfort. Or hit 'ctrl + l' on your keyboard.

> Error for not using the cs50 library:
> 
> <img src="img/01.png" alt="Compile error">
>
> hello_with_name.c:6:5 = file name : line6 : character5

## Types of data
- bool
- char
- double
- float
- int
- long
- string
- ...

> ### Format codes
> [*'printf'*](https://manual.cs50.io/3/printf) allows for many format codes.  
> Here is a non-comprehensive list of ones you may utilize in this course:
> - %c - for char variables
> - %f - for double and float variables
> - %i - for int or integer variables
> - %li - for long variables
> - %s - for string variables

## Conditionals