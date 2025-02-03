/*
** EPITECH PROJECT, 2025
** my_radar_h
** File description:
** contains all structs and functions prototypes
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <time.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <math.h>
    #define PI 3.141592653589793238462643383279502884197

//STRUCTS

typedef struct plane_list {
    sfVector2f end_position;
    sfVector2f current_pos;
    sfVector2f direction;
    sfRectangleShape *hitbox;
    float speed;
    int is_crashed;
    float delay;
    sfSprite *sprite;
    struct plane_list *next;
} planes_t;

typedef struct towers {
    sfVector2f position;
    float radius;
    sfCircleShape *hitbox;
    sfTexture *texture;
    sfSprite *sprite;
    struct towers *next;
} towers_t;

typedef struct bonus {
    sfVector2f start;
    sfVector2f end;
    int is_dragged;
    int number_collisions;
    sfText *f3;
    int is_F3;
} bonus_t;

typedef struct window {
    sfRenderWindow *window;
    sfTexture *background;
    sfSprite *map;
    sfTexture *plane;
    sfTexture *tower;
    sfClock *clock;
    int seconds;
    sfText *text_time;
    sfFont *font;
    int L_key;
    int S_key;
} parameters_t;

//LIB

int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n, int k);
char **my_str_to_word_array(char const *str);
char *turns_int_to_string(int nb);
int my_strlen(char const *str);
int str_toi(const char *str);
char *my_strcat(char *dest, char const *src);

//CSFML

int my_radar(char **argv);
int dash_h(void);
parameters_t create_structure(void);
bonus_t create_struct_bonus(parameters_t params);
sfRenderWindow* create_window(void);
void cleanup(parameters_t params, towers_t *towers
    , planes_t *planes, bonus_t bonus);
sfText* create_text(sfFont* font, const char *string, unsigned int size);
int is_intersecting_squares(planes_t *c1, planes_t *c2);
void run_sprites(planes_t **begin, float seconds);
planes_t *initialize_sprite(parameters_t params, char **data_planes);
void check_intersecting(planes_t **plane_list, towers_t *tower
    , float seconds, bonus_t *bonus);
planes_t *read_list_planes(char *path_to_file,
    parameters_t params, towers_t **towers);
int is_under_tower(planes_t *plane, towers_t *tower);
int show_hitbox(planes_t **list_planes, parameters_t *params
    , towers_t *tower, float seconds);
void show_sprites(planes_t **list_planes, parameters_t params
    , towers_t *tower, float seconds);
void change_params_if_key(parameters_t *params, sfEvent event
    , planes_t **list_planes, towers_t **tower);
int check_data_read(char **data_read, int status);
int check_data_tower(towers_t *tower);
int check_data_plane(planes_t *plane);
void assign_text_properties(parameters_t *params);
void show_program_time(float seconds, parameters_t params);
towers_t *add_towers_to_list(towers_t *towers,
    parameters_t params, char **data_planes);
planes_t *add_planes_to_list(planes_t *plane_list,
    parameters_t params, char **data_planes);
void handle_events(parameters_t *params, planes_t **list_planes
    , towers_t **tower, bonus_t *bonus);
sfVector2f calculate_direction(sfVector2f start, sfVector2f end);
sfRectangleShape *get_hitbox_square(void);
void set_rotation_plane(planes_t *plane);
void create_a_dragged_plane(bonus_t *bonus, planes_t **list_planes
    , parameters_t *params, sfEvent event);
void show_F3(bonus_t *bonus, parameters_t *params);

#endif /* !MY_HUNTER_H_ */
