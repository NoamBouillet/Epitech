/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** utilities
*/

#include "../include/my_sudo.h"

static char *search_username(char *uid, char *username, FILE *file)
{
    char line[STRING_SIZE];
    char file_username[STRING_SIZE];
    char file_uid[STRING_SIZE];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%[^:]:%*[^:]:%[^:]:", file_username, file_uid) != 2)
            continue;
        if (strcmp(uid, file_uid) == 0) {
            strncpy(username, file_username, STRING_SIZE);
            username[STRING_SIZE - 1] = '\0';
            fclose(file);
            free(uid);
            return username;
        }
    }
    fclose(file);
    free(uid);
    free(username);
    return "";
}

static char *search_hash(char *username, char *hash, FILE *file)
{
    char line[STRING_SIZE] = "\0";
    char file_hash[STRING_SIZE] = "\0";
    char file_username[STRING_SIZE] = "\0";

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%[^:]:%[^:]:", file_username, file_hash) != 2)
            continue;
        if (strcmp(username, file_username) == 0) {
            strncpy(hash, file_hash, STRING_SIZE - 1);
            hash[STRING_SIZE - 1] = '\0';
            fclose(file);
            return hash;
        }
    }
    fclose(file);
    free(hash);
    free(username);
    return NULL;
}

char *get_username(char *uid)
{
    char *username = malloc(sizeof(char) * STRING_SIZE);
    FILE *file = fopen("/etc/passwd", "r");

    if (!uid || uid[0] == '\0') {
        perror("UID doesn't exist\n");
        free(uid);
        return "";
    }
    if (!username) {
        perror("malloc failed for get_username\n");
        free(uid);
        return "";
    }
    if (!file) {
        perror("Opening /etc/passwd failed in get_username\n");
        free(uid);
        free(username);
        return "";
    }
    return search_username(uid, username, file);
}

char *get_hash(char *username)
{
    char *hash = malloc(sizeof(char) * STRING_SIZE);
    FILE *file = fopen("/etc/shadow", "r");

    if (!username || username[0] == '\0') {
        perror("Username doesn't exist\n");
        free(username);
        return "";
    }
    if (!hash) {
        perror("Malloc for hash failed\n");
        free(hash);
        return "";
    }
    if (!file) {
        perror("Opening /etc/shadow failed\n");
        free(hash);
        free(username);
        return "";
    }
    return search_hash(username, hash, file);
}

char *get_salt(char *hash)
{
    int salt_len = 0;
    int doll_counter = 0;
    char *salt = NULL;

    if (!hash)
        return NULL;
    for (int i = 0; hash[i] != '\0'; i++) {
        salt_len++;
        if (doll_counter == 4)
            break;
        if (hash[i] == '$')
            doll_counter++;
    }
    salt = malloc(sizeof(char) * salt_len + 1);
    if (salt == NULL)
        return NULL;
    strncpy(salt, hash, salt_len - 1);
    salt[salt_len - 1] = '\0';
    return salt;
}

void disable_echo(void)
{
    struct termios oldt;
    struct termios newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void enable_echo(void)
{
    struct termios oldt;
    struct termios newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}
