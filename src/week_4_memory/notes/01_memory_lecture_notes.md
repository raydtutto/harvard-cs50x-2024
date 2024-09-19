# Week 4: Memory

Instructor: **[David J. Malan](https://github.com/dmalan)**

---

## Pixel Art

**Resolution** - the number of distinct pixels in each dimension.

`0` - black color  
`1` - white color

<img src="img/00.png" alt="Pixel art">

---

## Hexadecimal

RGB represents the amount of red, green and blue colors.

- Black: `#000000` - `R:0` `G:0` `B:0`
- White: `#FFFFFF` - `R:255` `G:255` `B:255`
- Red: `#FF0000` - `R:255` `G:0` `B:0`
- Green: `#00FF00` - `R:0` `G:255` `B:0`
- Blue: `#0000FF` - `R:0` `G:0` `B:255`

> **Hexadecimal** or also known as **base-16** - a system of counting that has 16 counting values from index `0` to `15`.
>
> `0` `1` `2` `3` `4` `5` `6` `7` `8` `9` `A` `B` `C` `D` `E` `F`
> 
> _Uppercase or lowercase for letters doesn't matter._

When counting in hexadecimal, each column is a power of 16.

| _16 * 0_ | _1 * 0_ | | _16_ | _1_ | --> | _16_ | _1_ | | _16_   | _1_    | | _16_   | _1_    | --> | _16_   | _1_    |
|----------|---------|-|------|-----|-----|------|-----|-|--------|--------|-|--------|--------|-----|--------|--------|
| 0        | 0       | | 0    | 1   | --> | 0    | 9   | | 0 (~1) | A (~0) | | 0 (~1) | B (~1) | --> | 0 (~1) | F (~5) |

| _16_   | _1_    | | _16_    | _1_    | --> | _16 * 15_ | _1 * 15_ |
|--------|--------|-|---------|--------|-----|-----------|----------|
| 1 (~1) | 0 (~6) | |  1 (~1) | 1 (~7) | --> | F         | F        |

`FF` = `16 * 15` + `1 * 15` = `240` + `15` = `255`

---

## Memory

Applying hexadecimal numbering to each of these blocks of memory, we can visualize these as follows:

<img src="img/01.png" alt="Memory visualisation">

By convention, all hexadecimal numbers are often represented with the `0x` prefix (not a mathematical operation) to avoid the confusion:

<img src="img/02.png" alt="Memory visualisation with 0x prefix">

```c++
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%i\n", n);
    return 0;
}

// Output:
// 50
```

<img src="img/03.png" alt="`n` visualisation within memory">

> **Ampersand** `&` is an address operator that gives access to the locations of variables inside the computer's memory.
>
> **Asterisks** `*` is a dereference operator which allows to taken address and go to it.

```c++
#include <stdio.h>

int main(void)
{
    int n = 50;
    
    // Format code for printing the address is `%p`
    printf("%p\n", &n);
}

// Output:
// 0x16f61b6cc
```

### `*` Pointer

**Pointer** - the address of some variable that we can store in another variable.

```c++
#include <stdio.h>

int main(void)
{
    int n = 50;

    // Creates a pointer with the address of `n`
    int *p = &n;

    printf("%p\n", p); // `%p` with `p` - prints the address

    // Prints an integer value
    printf("%i\n", *p); // `*p` - go to the address and show what's inside
}
```

<img src="img/04.png" alt="The Pointer inside memory">

The pointer seems rather large. Indeed, a pointer is usually stored as an `8-byte value` or `64 bits`. `p` is storing the address of the 50

---

## Strings

