// To run this code, go to: https://sandbox.cs50.io/ to get access of all libraries used.

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Greetings
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}