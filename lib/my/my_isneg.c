/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** show if x is positive/negative
*/

void my_putchar(char c);

int my_isneg(int x)
{
    int num = x;

    if (num >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
