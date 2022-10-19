/*
** EPITECH PROJECT, 2022
** WINDOW DISPLAY
** File description:
** Display a window.
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

int main(int ac, char *av[])
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 120};
    sfTexture *Lucario = sfTexture_createFromFile("sprites/lucario.png", NULL) ;
    sfSprite *LucarioSprite = sfSprite_create(); 
    sfEvent event;
    int x = 900, y = 500;
    sfVector2f pos = {x, y}; 

    sfSprite_setPosition(LucarioSprite, pos);
    sfSprite_setTexture(LucarioSprite, Lucario, sfFalse);
    window = sfRenderWindow_create(mode, "s/o a central fume de ouf comme une cheminee de la centrale", sfDefaultStyle, NULL);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            switch (event.type) {

            case sfEvtClosed:
                sfRenderWindow_close(window);

            case (sfEvtKeyPressed):

                if (event.key.code == sfKeyRight) {
                    x += 10;
                }

                else if (event.key.code == sfKeyLeft) {
                    x -= 10;
                }

                else if (event.key.code == sfKeyUp) {
                    y -= 10;
                }

                else if (event.key.code == sfKeyDown) {
                    y += 10;
                }

                else if (event.key.code == sfKeyF11) {
                    window = sfRenderWindow_create(mode, "s/o a central fume de ouf comme une cheminee de la centrale", sfFullscreen, NULL);
                }
            }
        }
        sfVector2f newpos = {x, y};

        sfSprite_setPosition(LucarioSprite, newpos);
        sfRenderWindow_drawSprite(window, LucarioSprite, NULL);
        sfRenderWindow_display(window);
    }
}
