# Structures

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

`Structures` provide a way to unify several variables of different types into a single, new variable type which
can be assigned its own type name.

- We use structures (`structs`) to group together elements of a variety of data types that have a logical connection;
- Structure is like a “super-variable”.

```c++
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};
```

- `struct` - syntax for defining a structure type;
- `car` - type name;
- `{ int year, ... double engine size} ` - `members` or fields with different data types inside a “super-variable”;
- `;` - semicolon completes the definition of a struct.

> Structures are typically defined in separate `.h` files or atop our programs outside any functions.
> That way we can use our unique types in other programs.

## Static declaration

- We can also access the `members` of the structure using the dot operator `.`
- We can create variables of that type using the familiar syntax:

```c++
// static variable declaration
struct car mycar;

// field accessing
mycar.year = 2011;
strcpy(mycar.plate, "CS50");
mycar.odometer = 50505;
```

- `struct car` - type;
- `mycar` - variable name;
- `mycar.year` - accessing the member `year` inside `mycar`

## Dynamic allocation

Structures, like variables of all other data types, do not need to be created on the stack.
We can `dynamically allocate structures` at run time if our program requires it.

- In order to access the fields of our structures in that situation, we first need to `dereference the pointer`
to the structure, and then we can `access its fields`.

```c++
// dynamical variable declaration
struct car *mycar = malloc(sizeof(struct car));

// field accessing
(*mycar).year = 2011;
strcpy((*mycar).plate, "CS50");
(*mycar).odometer = 50505;
```

- `*` - dereferencing the pointer;
- `.` - access to the members.

### - Arrow operator `->`

The arrow operator `->` makes this process easier.

It’s an operator that does two things back-to-back:
- First, it `dereferences the pointer` on the left side of the operator.
- Second, it `accesses the field` on the right side of the operator.

```c++
// dynamical variable declaration
struct car *mycar = malloc(sizeof(struct car));

// field accessing
mycar->year = 2011;
strcpy(mycar->plate, "CS50");
mycar->odometer = 50505;
```