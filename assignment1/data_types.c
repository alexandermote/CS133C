#include <stdio.h>

int main()
{
    int number = 2047;
    char izard = 'E';
    short napoleon = 17;
    long thicc = 24487296120144168;
    float sigfig = 20.25;

    printf("The stored integer is %d, or %X in hexadecimal.\nThe stored character is %c.\nThe stored short is %hd.\nThe stored long is %ld.\nThe stored float is %f.\n", number, number, izard, napoleon, thicc, sigfig);
}