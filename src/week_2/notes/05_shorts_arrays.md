# Arrays

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

Arrays are a fundamental data structure. We use arrays to hold values of the same type at
contiguous memory locations.

> An **_array_** is a block of contiguous
> space in memory which has been partitioned into
> small, identically-sized blocks of
> space called elements each of which can store a certain
> amount of data all of the same data type such as
>  int or char and which can be accessed directly
> by an grade.

- In C, the elements of an array are indexed starting
from 0.
- If an array consists of ```n``` elements, the first element
is located at grade 0. The last element is located at
grade (```n```-1).
- C is very lenient. It will not prevent you from going
“out of bounds” of your array.

---

## Array declaration

```c
type name[size];

//Example
int student_grades[40];
```

- The ```type``` is what kind of variable each element of the
array will be.
- The ```name``` is what you want to call your array. Use plural.
- The ```size``` is how many elements you would like your
array to contain.

> If you think of a single element of an array of type
> data-type the same as you would any other
> variable of type data-type (which, effectively, it
> is) then all the familiar operations make sense.

```c
bool truthtable[10];
truthtable[2] = false; // the third element of the 'thruthtable'

if(truthtable[7] == true)
{
printf(“TRUE!\n”);
}

// Dangerous mistake:
truthtable[10] = true; // 'thruthtable' have [9]th elements as the last one.
// It will compile, but it might become pretty dangerous.
```

---

## Starting values in array

When declaring and initializing an array
simultaneously, there is a special syntax that may
be used to fill up the array with its starting values.

```c
// instantiation syntax variant #1
bool truthtable[3] = { false, true, true };

// instantiation syntax variant #2
// You don't need to indicate the size beforehand, the compiler can do it for you.
bool truthtable[] = { false, true, true };

// individual element syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```

---

## Dimensions

Arrays can consist of more than a single dimension.
You can have as many size specifiers as you wish.

```c
bool battleship[10][10]; // an abstraction to the board for game 'battleship'
```

You can choose to think of this as either a 10x10
grid of cells.
- In memory though, it’s really just a 100-element one-dimensional array.
- Multi-dimensional arrays are great abstractions to help
visualize game boards or other complex
representations.

---

## Assigning an array

> - While we can treat individual elements of arrays as
variables, we cannot treat entire arrays themselves
as variables.
> - We cannot, for instance, assign one array to
another array using the assignment operator. That is not
legal C.
> - Instead, we must use a loop to copy over the
elements one at a time.

🚫 You can't do this:

```c
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];

// Assigning will not work
bar = foo;
```

✅ Assigning through loop:

```c
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];

// Correct assigning: element by element
for(int j = 0; j < 5; j++)
{
bar[j] = foo[j];
}
```

---

## Passing by reference

**_Passing by value_** means that we're making a copy of the variable that's being passed in.
- The callee function, that's receiving the variable, doesn't get the variable itself - it gets its own local copy
of it to work with.

**BUT ARRAYS DO NOT FOLLOW THIS RULE**.

> Arrays are **_passed by reference_**. The callee receives the actual array, not a copy of it.

```c
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
int a = 10;
int b[4] = { 0, 1, 2, 3 };
set_int(a); // passed by value -> didn't change the value of int 'a'
set_array(b); // passed by reference -> changes the value of b[0]

// %d - Take the next argument and print it as an int
printf(“%d %d\n”, a, b[0]);
}

void set_array(int array[4])
{
array[0] = 22;
}

void set_int(int x)
{
x = 22;
}

// Output:
// 10 22
```