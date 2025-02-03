/*
** EPITECH PROJECT, 2024
** main
** File description:
** runs the program
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"

int get_added_words(char *buffer)
{
    int length_word = 0;
    int i = 0;

    while (buffer[i] != '(') {
        i++;
    }
    i++;
    while (buffer[i] != ')') {
        if ((buffer[i] > 57 && buffer[i] < 65)
        || (buffer[i] > 90 && buffer[i] < 97)
        || (buffer[i] > 122)
        || (buffer[i] < 48)) {
            i++;
            length_word++;
        } else
            i++;
    }
    return length_word;
}

char *get_command_name(char *buffer)
{
    char *command = NULL;
    int i = 0;
    int len = 0;
    int length_first_element = i;

    while (buffer[i] != '(') {
        i++;
    }
    i++;
    length_first_element = i;
    while (buffer[i] != ')') {
        len++;
        i++;
    }
    command = malloc(sizeof(char) * len + 1);
    if (!command)
        return "";
    strncpy(command, buffer + length_first_element, len);
    command[len] = '\0';
    return command;
}

char *get_virt(char *filename)
{
    long int virt = 0;
    char *result = malloc(sizeof(char) * 30);
    char line[256];
    char *filestatus = malloc(sizeof(char) * 30);
    FILE *file;

    snprintf(filestatus, 30, "/proc/%s/status", filename);
    file = fopen(filestatus, "r");
    if (!file || !result || !filestatus)
        return "";
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "VmSize: %lu kB", &virt) == 0)
            continue;
    }
    if (virt > 1024 * 1024)
        snprintf(result, 30, "%.1fg", virt / (1024.0 * 1024.0));
    else
        snprintf(result, 30, "%ld", virt);
    fclose(file);
    return result;
}

char *get_uid(char *filename)
{
    long int uid = 0;
    char *char_uid = malloc(sizeof(char) * 30);
    char line[256];
    char *filestatus = malloc(sizeof(char) * 30);
    FILE *file;

    snprintf(filestatus, 30, "/proc/%s/status", filename);
    file = fopen(filestatus, "r");
    if (!file || !filestatus)
        return "";
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "Uid: %lu", &uid) == 0)
            continue;
    }
    snprintf(char_uid, 30, "%ld", uid);
    fclose(file);
    free(filestatus);
    return char_uid;
}

static char *truncate_username(char *username)
{
    char *process_username = malloc(sizeof(char) * 10);

    if (!process_username)
        return "";
    if (strlen(username) > 8) {
        strncpy(process_username, username, 7);
        process_username[7] = '+';
        process_username[8] = '\0';
        free(username);
        return process_username;
    }
    free(process_username);
    return username;
}

static char *search_username(char *uid, char *username, FILE *file)
{
    char line[256];
    char file_username[30];
    char file_uid[30];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%[^:]:%*[^:]:%[^:]:", file_username, file_uid) != 2)
            continue;
        if (strcmp(uid, file_uid) == 0) {
            strncpy(username, file_username, 30);
            username[29] = '\0';
            fclose(file);
            free(uid);
            return truncate_username(username);
        }
    }
    fclose(file);
    free(uid);
    free(username);
    return "";
}

char *get_username(char *filename)
{
    char *uid = get_uid(filename);
    char *username = malloc(sizeof(char) * 30);
    FILE *file = fopen("/etc/passwd", "r");

    if (!uid || uid[0] == '\0') {
        free(uid);
        return "";
    }
    if (!username) {
        free(uid);
        return "";
    }
    if (!file) {
        free(uid);
        free(username);
        return "";
    }
    return search_username(uid, username, file);
}
