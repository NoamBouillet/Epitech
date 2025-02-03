/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** main
*/

#include "../include/my_sudo.h"

static void display_help(int i)
{
    dprintf(i, "usage: ./my_sudo -h\n"
        "usage: ./my_sudo [-ugEs] [command [args ...]]");
}

int check_password(char *hash, char *salt, char *username)
{
    char *passwd = NULL;
    char *hash_passwd = NULL;
    size_t len_read = 0;

    for (int i = 0; i < 3; i++) {
        printf("[my_sudo] password for %s: ", username);
        disable_echo();
        if (getline(&passwd, &len_read, stdin) == -1)
            return -1;
        passwd[strlen(passwd) - 1] = '\0';
        enable_echo();
        putchar('\n');
        hash_passwd = crypt(passwd, salt);
        if (strcmp(hash, hash_passwd) == 0)
            return i;
        if (i == 0 || i == 1)
            printf("Sorry, try again.\n");
    }
    dprintf(2, "my_sudo: 3 incorrect password attempts\n");
    return -1;
}

int run_command(char **argv, int argc, flags_t flags)
{
    int index = 1;
    char command[MAX_LINE_LENGTH];

    for (; index < argc && argv[index][0] == '-'; index++) {
        if ((strstr(argv[index], "u") || strstr(argv[index], "g"))
            && index + 1 < argc)
            index += 1;
    }
    if (index >= argc) {
        if (flags.s)
            spawn_shell(getenv("SHELL"));
        display_help(2);
        return 84;
    }
    snprintf(command, sizeof(char) * MAX_LINE_LENGTH,
        "/usr/bin/%s", argv[index]);
    setenv("SUDO_COMMAND", command, 1);
    execvp(argv[index], &argv[index]);
    dprintf(2, "my_sudo: %s: command not found\n", argv[index]);
    return 84;
}

int check_authorized(char **argv, int argc, char *username, flags_t flags)
{
    char *hash = get_hash(username);
    char *salt = get_salt(hash);
    int result = -2;

    if (!hash || !salt)
        return 84;
    if (strcmp(username, "root") != 0)
        result = check_password(hash, salt, username);
    if (checks_permissions(username) == 84)
        return 84;
    if (change_ids(flags, username) == 84)
        return 84;
    free(hash);
    free(salt);
    free(username);
    if (result == -1) {
        return 84;
    } else if (result != -2)
        printf("%d incorrect attempts\n", result);
    return run_command(argv, argc, flags);
}

int run_flags(char **argv, flags_t flags, int argc)
{
    char *username = get_username(turns_int_to_string(getuid()));

    if (!username) {
        perror("Can't get the username from the uid\n");
        return 84;
    }
    if (!flags.E)
        sanitize_environment(username);
    if (sanitize_without_e(username) == 84)
        return 84;
    return check_authorized(argv, argc, username, flags);
}

int main(int argc, char **argv)
{
    flags_t flags = {0};

    if (argc < 2) {
        display_help(2);
        return 84;
    }
    if (geteuid() != 0) {
        perror("You do not have the root permissions :"
            "Quitting program !\n");
        return 84;
    }
    if (strcmp(argv[1], "-h") == 0 && argc == 2) {
        display_help(1);
        return 0;
    }
    if (search_for_flags(argc, argv, &flags) == 84) {
        display_help(2);
        return 84;
    }
    return run_flags(argv, flags, argc);
}
