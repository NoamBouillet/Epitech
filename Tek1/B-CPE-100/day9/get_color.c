/*
** EPITECH PROJECT, 2024
** get_color
** File description:
** gets the color as an int with the rgb components
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int color_bitshift = ((int)red << 16) | ((int)green << 8) | (int)blue;

    return color_bitshift;
}
