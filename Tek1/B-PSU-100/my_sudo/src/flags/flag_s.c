/*
** EPITECH PROJECT, 2024
** flag_s
** File description:
** runs the shell
*/

#include "../../include/my_sudo.h"

void spawn_shell(char *shell)
{
    execlp(shell, shell, NULL);
}
