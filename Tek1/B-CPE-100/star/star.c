/*
** EPITECH PROJECT, 2024
** star
** File description:
** pictures a cute star
*/

void my_putchar(char c);
void star(unsigned int size);
void star_exceptions(unsigned int size, int choice);
void star_head(unsigned int size, int orientation);
void star_head2(unsigned int size, int orientation, int i);
void star_arms(unsigned int size);
void star_body(unsigned int size, int orientation);
void star_body2(unsigned int size, int orientation, int i);
void my_little_star(void);
void star(unsigned int size)
{
    if (size == 0)
        return;
    if (size == 1)
        my_little_star();
    else {
        star_exceptions(size, 0);
        star_head(size, 1);
        star_arms(size);
        star_body(size, 1);
        star_exceptions(size, 2);
        star_body(size, 0);
        star_arms(size);
        star_head(size, 0);
        star_exceptions(size, 0);
    }
}

void star_exceptions(unsigned int size, int choice)
{
    if (choice == 0) {
        for (int k = 1; k < 2 * size +size; k++) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
    }
    if (choice == 2) {
        for (int k = 0; k < size; k++) {
            my_putchar(' ');
        }
        my_putchar('*');
        for (int k = 0; k < 4 * size -3; k++) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
    }
}

void star_head(unsigned int size, int orientation)
{
    for (int i = 1; i < size; i++) {
        star_head2(size, orientation, i);
    }
}

void star_arms(unsigned int size)
{
    for (int j = 0; j < 2 * size +1; j++) {
        my_putchar('*');
    }
    for (int j = 0; j < 2 * size - 3; j++) {
        my_putchar(' ');
    }
    for (int j = 0; j < 2 * size +1; j++) {
        my_putchar('*');
    }
    my_putchar('\n');
}
