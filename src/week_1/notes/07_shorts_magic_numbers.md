# Magic numbers

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

***Magic number*** is a unique value with unexplained meaning or multiple occurrences which could (preferably)
be replaced with a named constant.

```c
card deal_cards(deck name)
{
    for (int i = 0; i < 52; i++)
    {
        // deal the card
    }
}
```

- In this example the magic number is 52.
- If this function is just one of many in a suite of programs that manipulate decks of cards - there will be problems.

```c
card deal_cards(deck name)
{
    int deck_size = 52;
    for (int i = 0; i < deck_size; i++)
    {
       // deal the card
    }
}
```

- This fixes one problem, but introduces another.
  - Even if globally declared, what if some other function in our suite inadvertently manipulates deck_size.
  Could spell trouble.

## Macro

C provides a *preprocessor directive* (also called a
*macro*) for creating symbolic constants.

```c
#define NAME REPLACEMENT
```

- At the time your program is compiled, #define goes through your code and replaces NAME with REPLACEMENT.
  - If #include is similar to copy/paste, then #define is analogous to find/replace.

```c
#define PI 3.14159265
```

- At the time your program is compiled, #define goes through your code and replaces PI with 3.14159265.
  - If #include is similar to copy/paste, then #define is analogous to find/replace.

```c
#define COURSE “CS50”
```

- At the time your program is compiled, #define goes through your code and replaces COURSE with “CS50”.
  - If #include is similar to copy/paste, then #define is analogous to find/replace.

```c
#define DECKSIZE 52

card deal_cards(deck name)
{
    for (int i = 0; i < DECKSIZE; i++)
    {
        // deal the card
    }
}
```

You can change 'DECKSIZE' value as you wish.