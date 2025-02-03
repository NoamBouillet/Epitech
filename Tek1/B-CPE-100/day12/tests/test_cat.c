/*
** EPITECH PROJECT, 2024
** test for my_language
** File description:
** unit test for the file my_language.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include <fcntl.h>
#include <unistd.h>

int cat(int, char **);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(cat, single_file_output, .init = redirect_all_std)
{
    char *output_list[] = {"./a.out", "cat/cat.c"};
    cat(2, output_list);
    int fd = open("cat/cat.c", O_RDONLY);
    cr_assert(fd != -1, "Erreur: impossible d'ouvrir le fichier.");
    char file_content[1024];
    ssize_t bytes_read = read(fd, file_content, sizeof(file_content) - 1);
    close(fd);

    cr_assert(bytes_read > 0, "Erreur: impossible de lire le fichier.");
    file_content[bytes_read] = '\0';
    cr_assert_stdout_eq_str(file_content, "Le contenu du fichier ne correspond pas à la sortie attendue.");
}

/*Test(search_for_language, normal_string_spanish, .init = redirect_all_std)
{
  char *output_list[] = {strdup("fonction"), strdup("Somos muy buenos en tecnología. Nos encanta aprender sobre inteligencia artificial. La programación es nuestra pasión."), strdup("m"), strdup("f"), NULL};

    search_for_language(4, output_list);
    cr_assert_stderr_eq(84);
}
*/
