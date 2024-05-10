# Recursion

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

We might describe an implementation of an algorithm as being
particularly “elegant” if it solves a problem in a way that is
both interesting and easy to visualize.

The technique of recursion is a very common way to
implement such an “elegant” solution.

> The definition of a recursive function is one that, as part of its
> execution, invokes itself.

## Factorial example:

- The factorial function (`n!`) is defined over all positive integers.
- `n!` equals all of the positive integers less than or equal to `n`,
multiplied together.
- Thinking in terms of programming, we’ll define the
mathematical function `n!` as `fact(n)`.

A couple of factorials:

```
fact(1) = 1
fact(2) = 2 * 1
fact(3) = 3 * 2 * 1
fact(4) = 4 * 3 * 2 * 1
fact(5) = 5 * 4 * 3 * 2 * 1
...
```

It can be describe as:

```
fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * fact(3)
fact(5) = 5 * fact(4)
...
```

We recursively define the factorial function:

```
fact(n) = n * fact(n-1)
```

This forms the basis for a recursive definition of the factorial function.

> Every recursive function has two cases that could apply, given any input:

- The `base case`, which when triggered will terminate the recursive process.
- The `recursive case`, which is where the recursion will actually occur.

```c
int fact(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }
    
    // recursive case
    else
    {
        return n * fact(n-1);
    }
}
```

We can take away the curly braces if there is only single line loop or conditional branches -->

```c
// Recursive function
int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}
```

> In general, but not always, recursive functions replace loops in non-recursive functions.

```c
// Non-recursive loop
// has identical result with recursive function
int fact2(int n)
{
    int product = 1;
    while(n > 0)
    {
        product *= n;
        n--;
    }
    return product;
}
```

---

## Multiple base and recursive cases

> It’s also possible to have more than one base or recursive case, if the program might recurse or terminate
> in different ways, depending on the input being passed in.

### - Multiple base cases

#### Fibonacci sequence

The Fibonacci number sequence is defined as follows:

- The first element is 0.
- The second element is 1.
- The `n` element is the sum of the `(n-1)` and `(n-2)` elements.

### - Multiple recursive cases

#### The Collatz conjecture

The Collatz conjecture is applies to positive integers and
speculates that it is always possible to get “back to 1” if you
follow these steps:

- If `n` is `1`, stop.
- Otherwise, if `n` is even, repeat this process on `n/2`.
- Otherwise, if `n` is odd, repeat this process on `3n + 1`.

A recursive function `collatz(n)` that calculates how many steps it takes to get to `1` if you start from `n`
and recurse as indicated above.

```c
int collatz(int n)
{
    // Base case
    if (n == 1)
        return 0;
    
    // Even numbers
    else if ((n % 2) == 0)
        return 1 + collatz(n/2);
        
    // Odd numbers
    else
        return 1 + collatz(3 * n + 1);
}
```