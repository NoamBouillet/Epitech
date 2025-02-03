/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #include "structs.h"

//Main

void cleanup(window_t window, sprite_t *sprite);
void handle_events(window_t *window, sprite_t **sprites, stats_t *stats);
int dash_h(void);

//Loading

int draw_frame(window_t *window, sprite_t **sprite, stats_t *stats);
void display_score(window_t *window, stats_t *stats);
sfMusic* play_music(const char *filename);
sfFont *load_font(const char *filename);
sfTexture* load_texture(const char *filename);
sprite_t *run_sprites(sprite_t **begin, window_t *window, stats_t *stats);
void check_sprite_click(sprite_t *sprites
    , sfRenderWindow *window, sfEvent event, stats_t *stats);
void crosshair(window_t window);
char *turns_int_to_string(int nb);

int my_strlen(char const *str);
int check_lives(window_t *window, stats_t *stats);
void free_all_sprites(sprite_t *begin);
void restart_game(window_t *window, menu_t *menu);

//Menu

void cleanup_menu(menu_t *menu);
int display_menu(sfRenderWindow *window, sfTexture *background, menu_t *menu);
menu_t create_menu(sfFont *font);

//Creating

sfRenderWindow* create_window(unsigned int width, unsigned int height
    , unsigned int bitsPerPixel);
sfSprite* create_sprite(sfTexture* texture);
sfText* create_text(sfFont* font, const char *string, unsigned int size);
int update_sprite(sprite_t *sprite, window_t *window);
sprite_t *initialize_sprite(window_t *window);
void manage_sprites(window_t *window, sprite_t **first
    , sfClock *sprite_clock, stats_t *stats);
int my_strcmp(char const *s1, char const *s2);
void add_sprite_to_list(sprite_t **sprite, window_t window);

char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_hunter(void);

#endif /* !MY_HUNTER_H_ */
