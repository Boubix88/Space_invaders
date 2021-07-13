/**\file main.h
*\date 24/05
*/
#ifndef __MAIN__H__
#define __MAIN__H__

#include <SDL.h> 
#include <stdio.h>
#include <stdlib.h>


#define SCREEN_HEIGHT 920
#define SCREEN_WIDTH 518
#define SHIP_HEIGHT 72
#define SHIP_WIDTH 50
#define MOVING_STEP 10

/**
 * \brief Type qui correspond aux ressources du jeu
 * \b background Texture liée à l'image du fond de l'écran.
 * \b spaceship Texture liée à l'image du vaisseau.
 * \b finish_line Texture liée à l'image de la ligne d'arrivée.
 * \b meteor Texture liée à l'image des météorites.
 * \b explosion Texture liée à l'image 'explosion lors de la colision
 * \b confettis Texture liée aux confettis de fin de partie.
 * \b ballon Texture liée aux ballons de fin de parties.
 * \b start Texture liée au boutton start du menu.
 * \b exit Texture liée au boutton exit du menu.
 * \b restart Texture liée au boutton restart.
 * \b start_selection Texture liée à l'encadrer jaune autour des bouttons du menu.
 * \b exit_selection Texture liée à l'encadrer jaune autour des bouttons du menu.
 * \b font Texture liée à la police d'écriture.
 * \b couleur Sdl  liée à la couleur de police.
*/

typedef struct ressources_s ressources_t;
struct ressources_s{
    SDL_Surface* icon;
    SDL_Surface* backgroundIMG;
    SDL_Surface* spaceshipIMG;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* background; 
    SDL_Texture* spaceship;                       /*!< Texture liée à l'image du vaisseau. */
    SDL_Texture* finish_line;   /*!< Texture liée a l'image de la ligne. */
    SDL_Texture* meteor;
    SDL_Texture* explosion;
    SDL_Texture* confettis;
    SDL_Texture* ballon;
    SDL_Texture* start;
    SDL_Texture* exit;
    SDL_Texture* restart;
    SDL_Texture* start_selection;
    SDL_Texture* exit_selection;
    SDL_Texture* restart_selection;
    SDL_Color* couleur;
};



/**
 * \brief Type qui correspond au sprite du jeu
 * \a x Coordonnée horizontale.
 * \a y Coordonnée verticale.
 * \a h Hauteur du sprite.
 * \a w Largeur du sprite.
*/

typedef struct sprite_s sprite_t;
struct sprite_s{
    int x;
    int y;
    int h;
    int w;
};



/**
 * 
 * \brief Type qui correspond aux données du monde
 * \a x Coordonnée horizontale.
 * \a y Coordonnée verticale.
 * \a gameover Indique si le jeu est fini ou non.
 * \a vy Vitesse verticale.
 * \a sprite_collision indique si il y a eu une collision
 * \a selection Indique si start ou exit est séléctionné dans le menu.
 * \a nbr Condition de sortie de la boucle while du menu.
 * \a vaisseau Considéré comme le vaisseau.
 * \a finishLine Considéré comme la ligne d'arrivé
 * \a meteorite Considère comme une méteorite.
 * \a meteorite_walls Considéré comme étant le mur de météorite.
 * \a time Variable ou est stockée le temps du timer.
 * \a time_menu Variable ou est stockée le temps du timer du menu.
 * \a temps Tableau pour convertir le temps.
 * \a temps_final Tableau ou est stockée le temps final.
 */


typedef struct world_s world_t;
struct world_s{
    int gameover; 
    int vy;
    sprite_t spaceship;
};



/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */

void Init_Spaceship();
void Init_Screen();
void pause();
void Free_Memory();
void Update_Screen(ressources_t* ressources, world_t *world);
void apply_sprite(SDL_Renderer *renderer, ressources_t *ressources, world_t *world);

void menu(SDL_Event *event, world_t *world, ressources_t *ressources, SDL_Renderer *renderer);
void menu_fin(SDL_Event *event, world_t *world, ressources_t *ressources, SDL_Renderer *renderer);
void Init_Sprite(sprite_t *sprite, int x, int y, int w, int h);
void print_sprite(sprite_t *sprite);
void init_data(world_t * world);
void clean_data(world_t *world);
int is_game_over(world_t *world);
void update_data(world_t *world);
void update_meteorite(world_t *world);
void handle_events(SDL_Event *event,world_t *world);
void clean(SDL_Window *window, SDL_Renderer * renderer, ressources_t *ressources, world_t * world);
void init(SDL_Window **window, SDL_Renderer ** renderer, ressources_t *ressources, world_t * world);
int handle_events_collision(sprite_t *sp1, sprite_t *sp2, world_t *world);
int sprites_collide(sprite_t *sp1, sprite_t *sp2);
void depassement_limite_gauche(sprite_t *sprite);
void depassement_limite_droite(sprite_t *sprite);
int test_collision (world_t *world);
void init_ttf();

void clean_textures(ressources_t *ressources);
void init_textures(SDL_Renderer *renderer, ressources_t *ressources);
void apply_mur_meteorite(SDL_Renderer *renderer, world_t *world, ressources_t *ressources);
void apply_background(SDL_Renderer *renderer, ressources_t *ressources);
void refresh_graphics(SDL_Renderer *renderer, world_t *world,ressources_t *ressources);
int timer(world_t *world);
int timer_menu(world_t *world);

#endif