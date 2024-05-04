# Variables and Scope

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

> **_Scope_** is a characteristic of a variable that defines
> from which functions that variable may be
> accessed.

- _**Local variables**_ can only be accessed within the functions in which they are created.
```c
int triple(int x); // Function declaration

int main(void)                
{                             |
int result = triple(5);       | // scope: 'result' is local to 'main()'
}                             |

int triple(int x)             
{                             |
return x * 3;                 | // scope: 'x' is local to 'triple()' function
}                             |
```
- _**Global variables**_ can be accessed by any function in the program.

```c
int triple(int x); // Function declaration

float global = 0.5050; // Declaration of a global variable 

int main(void)
{
triple();
printf(“%f\n”, global);
}

void triple(void)
{
global *= 3;
}
```

For the most
part, local variables in C are passed by value in
function calls.

- When a variable is passed by value, the callee
receives a copy of the passed variable, not the
variable itself.
- That means that the variable in the caller is
unchanged unless overwritten.

e.g. ```No effect``` on foo:

```c
int main(void)
{
int foo = 4;
triple(foo); // 'foo' stays with value '4'
}

int triple(int x)
{
return x *= 3;
}
```

e.g. ```Overwrites``` foo:

```c
int main(void)
{
int foo = 4;
foo = triple(foo); // Overwriting 'foo' value to '12'
}

int triple(int x)
{
return x *= 3;
}
```

---

## Miscellaneous points

Things can get particularly insidious if the same
variable name appears in multiple functions, which
is perfectly okay as long as the variables exist in
different scopes.

```c
int increment(int x);

int main(void)
{
int x = 1;
int y;
y = increment(x);
printf(“x is %i, y is %i\n”, x, y);
}

int increment(int x)
{
x++;
return x;
}

// Output:
// x is 1, y is 2
```