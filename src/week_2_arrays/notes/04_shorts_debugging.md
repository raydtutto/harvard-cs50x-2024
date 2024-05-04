# Variables and Scope

Instructor: [**Carter Zenke**](https://github.com/carterzenke)

---

```commandline
debug50 source-name
```

Command to call a debugger.

Use **_Step over_** (to the next step) and **_Step into_** (into the function)  to "stepping" inside your code.

For example, you have this buggy code:

```c
#include <cs50.h>

bool check_phrase(string);

int main(void)
{
    string phrase = get_string("What's the secret phrase? ");

    bool correct = check_phrase(phrase);

    if (correct == true)
    {
        printf("Come on in!\n");
    }
    return 0;
}

bool check_phrase(string)
{
    string password = "Please";

    if (phrase == password)
    {
        return true;
    }

    return false;
}
```

The problem here is that in C you can't compare two string using an equal sign.

Use function ```strcmp()``` to compare two strings:

```c
bool check_phrase(string)
{
string password = "Please";

    if (strcmp(phrase, password) == 0)
    {
        return true;
    }

    return false;
}
```