# Defining custom data types

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

The `C` keyword `typedef` provides a way to create a shorthand or rewritten name for data types.

The basic idea is to first define a type in the normal way, then alias it to something else.

---

## Creating custom data type

Template for creating a custom data type:

```c++
// Template
typedef <old name> <new name>;
```

Simple example:

```c++
// Example
typedef unsigned char byte;

// Now we can use data type `byte` in our program
```

Example from `CS50` lib:

```c++
typedef char * string;
```

---

## Combining custom data type with structures

```c++
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};

typedef struct car car_t;
```

Every time when we create a variable with `car_t` data type, it will hold all the data from `car` struct.

Another way to combine `struct` and custom `data type`:

```c++
typedef struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
}
car_t;
```

## Declaring a struct variable with custom data type

Before we did like this with a struct:

```c++
// Simple struct variable declaration
struct car mycar;
```

But with the help of `typedef` we can declare a new variable like this:

```c++
typedef struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
}
car_t;

// Custom data type variable declaration
car_t mycar;

// field accessing
mycar.year = 2011;
strcpy(mycar.plate, “CS50”);
mycar.odometer = 50505;
```