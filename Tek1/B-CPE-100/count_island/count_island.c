/*
** EPITECH PROJECT, 2024
** count_island
** File description:
** project of the week
*/

char **changing_x(char **world, int lign, int column, int nbr)
{
    if (lign >= 0 && column >= 0 && world[lign] != 0
        && world[lign][column] != 0 && world[lign][column] == 'X') {
        world[lign][column] = nbr + 48;
        world = changing_x(world, lign - 1, column, nbr);
        world = changing_x(world, lign, column + 1, nbr);
        world = changing_x(world, lign + 1, column, nbr);
        world = changing_x(world, lign, column - 1, nbr);
    }
    return world;
}

int changing_island(char **world, int lign, int column, int nbr)
{
    if (world[lign] == 0)
        return nbr;
    if (world[lign][column] == 0)
        return changing_island(world, lign + 1, 0, nbr);
    if (world[lign][column] == 'X') {
        world = changing_x(world, lign, column, nbr);
        nbr++;
    }
    return changing_island(world, lign, column + 1, nbr);
}

int count_island(char **world)
{
    return changing_island(world, 0, 0, 0);
}
