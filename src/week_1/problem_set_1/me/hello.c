// Says hello to the user

#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);

    return 0;
}