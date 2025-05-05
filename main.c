#undef main
#include <SDL2/SDL.h>
#include <unistd.h>
#include "function.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define FPS 60

// Variables globales
int xb, yb, rb;
int viballx, vibally;
int vieb;

int xl, yl, xll, yll;

int xr, yr, lo, ha, espace, nbrick;
int largTab, longTab, tabmax;
int tabl[24];

int Lbarrepoint;
int menustart;
int xbord;

int yetoile, xetoile;
int xbonus, ybonus, rbonus;
int vibonusx, vibonusy;
int power;

void interface()
{
    changeColor(37, 157, 110);
    drawRect(xbord, (WINDOW_HEIGHT - Lbarrepoint), WINDOW_WIDTH, Lbarrepoint);
    sprite(xbord + 10, (WINDOW_HEIGHT - (Lbarrepoint / 2) - 25), "assets/pngwing.com.bmp");

    // Affichage des vies
    for (int i = 0; i < vieb; i++)
    {
        changeColor(255, 120, 96);
        drawCircle(espace + ((rb * 3) * i), (WINDOW_HEIGHT - (Lbarrepoint / 2)), rb);
    }
}

void drawBarre()
{
    changeColor(0, 0, 0);
    drawRect(xl, yl, xll, yll);
}

void drawBall()
{
    changeColor(255, 120, 96);
    drawCircle(xb, yb, rb);

    xb += viballx;
    yb += vibally;

    // Collision balle principale
    if ((xb > 1450 - rb) || (xb < xbord + rb))
    {
        viballx = -viballx;
    }
    if ((yb > WINDOW_HEIGHT - rb) || (yb < rb) ||
        ((((xb + rb) >= xl) && (xb - rb <= xl + xll)) && yb + rb == yl))
    {
        vibally = -vibally;
    }

    if (yb + rb > WINDOW_HEIGHT - Lbarrepoint)
    {
        vieb--;
        if (vieb > 0)
        {
            xb = WINDOW_WIDTH / 2;
            yb = WINDOW_HEIGHT / 2;
            viballx = 0;
            vibally = 0;
        }
    }

    // Collision balle bonus
    if ((xbonus > 1450 - rb) || (xbonus < xbord + rb))
    {
        vibonusx = -vibonusx;
    }
    if ((ybonus > WINDOW_HEIGHT - rb) || (ybonus < rb) ||
        ((((xbonus + rb) >= xl) && (xbonus - rb <= xl + xll)) && ybonus + rb == yl))
    {
        vibonusy = -vibonusy;
    }

    if (ybonus + rb > WINDOW_HEIGHT - Lbarrepoint)
    {
        power = 2;
    }
}

void powerup()
{
    if (nbrick < 20)
    {
        if (power == 1)
        {
            sprite(xetoile, yetoile, "assets/star.bmp"); // Taille étoile 40x40
        }

        if ((((xb) > xetoile) && ((xb) < (xetoile + 40))) &&
            ((yb) < (yetoile + 40) && (yb) > (yetoile)))
        {
            power = 0;
        }

        if (power == 0)
        {
            changeColor(255, 0, 96);
            drawCircle(xbonus, ybonus, rb);
            xbonus += vibonusx;
            ybonus += vibonusy;
        }
    }
}

void brick()
{
    int i, j;
    for (j = 0; j < longTab; j++)
    {
        for (i = j; i <= tabmax; i = i + longTab)
        {
            if (tabl[i] == 1)
            {
                xr = (((WINDOW_WIDTH - ((espace * (longTab - 1)) + lo)) / 2) + (j * espace));
                yr = ((espace / 2) + (i / longTab * (espace / 2)));

                changeColor(57, 156, 152);
                drawRect(xr, yr, lo, ha);

                // Collision brique principale
                if (((yb <= yr + ha + rb) && (yb > yr + ha)) && ((xb <= xr + lo) && (xb >= xr)) && (vibally < 0))
                {
                    vibally = -vibally;
                    tabl[i] = 0;
                    nbrick--;
                }
                else if (((xb <= xr + lo) && (xb >= xr)) && ((yb >= yr - rb) && (yb < yr)) && (vibally > 0))
                {
                    vibally = -vibally;
                    tabl[i] = 0;
                    nbrick--;
                }

                if (((xb >= xr - rb) && (xb < xr)) && ((yb >= yr) && (yb <= yr + ha)) && (viballx > 0))
                {
                    viballx = -viballx;
                    tabl[i] = 0;
                    nbrick--;
                }
                else if (((xb <= xr + lo + rb) && (xb > xr)) && ((yb >= yr) && (yb <= yr + ha)) && (viballx < 0))
                {
                    viballx = -viballx;
                    tabl[i] = 0;
                    nbrick--;
                }

                // Collision balle bonus
                if (((ybonus <= yr + ha + rb) && (ybonus > yr + ha)) && ((xbonus <= xr + lo) && (xbonus >= xr)) &&
                    (vibonusy < 0))
                {
                    vibonusy = -vibonusy;
                    tabl[i] = 0;
                    nbrick--;
                }
                else if (((xbonus <= xr + lo) && (xbonus >= xr)) && ((ybonus >= yr - rb) && (ybonus < yr)) &&
                         (vibonusy > 0))
                {
                    vibonusy = -vibonusy;
                    tabl[i] = 0;
                    nbrick--;
                }

                if (((xbonus >= xr - rb) && (xbonus < xr)) && ((ybonus >= yr) && (ybonus <= yr + ha)) &&
                    (vibonusx > 0))
                {
                    vibonusx = -vibonusx;
                    tabl[i] = 0;
                    nbrick--;
                }
                else if (((xbonus <= xr + lo + rb) && (xbonus > xr)) && ((ybonus >= yr) && (ybonus <= yr + ha)) &&
                         (vibonusx < 0))
                {
                    vibonusx = -vibonusx;
                    tabl[i] = 0;
                    nbrick--;
                }
            }
        }
    }
}

void init_game()
{
    // Position balle
    xb = WINDOW_WIDTH / 2;
    yb = WINDOW_HEIGHT / 2;
    rb = 15;
    viballx = 0;
    vibally = 0;
    vieb = 3;

    // Position barre
    xl = WINDOW_WIDTH / 2 - 100;
    yl = WINDOW_HEIGHT - 300;
    xll = 200;
    yll = 5;

    // Briques
    lo = 90;
    ha = 40;
    espace = 100;
    largTab = 4;
    longTab = 6;
    tabmax = largTab * longTab;
    nbrick = tabmax;
    for (int i = 0; i < tabmax; i++)
    {
        tabl[i] = 1;
    }

    Lbarrepoint = 60;
    menustart = 1;
    xbord = 470;

    // Balle bonus
    xetoile = WINDOW_WIDTH / 3;
    yetoile = WINDOW_HEIGHT / 3;
    xbonus = xetoile;
    ybonus = yetoile;
    vibonusx = 2;
    vibonusy = 2;
    power = 1;
}

void drawGame()
{
    if (menustart == 1)
    {
        clear();
        sprite(0, 0, "assets/ecran_base_fs.bmp");
        sprite(0, 0, "assets/menu_start_fs1.bmp");
    }
    else if (vieb > 0 && menustart == 0)
    {
        clear();
        sprite(0, 0, "assets/ecran_base_fs.bmp");
        interface();
        drawBall();
        drawBarre();
        brick();
        powerup();
    }

    if (nbrick == 0)
    {
        clear();
        sprite(0, 0, "assets/Design-sans-titre.bmp");
    }
    else if (vieb == 0)
    {
        clear();
        sprite(0, 0, "assets/Game-over.bmp");
    }

    actualize();
    usleep(1000000 / FPS); // 60 images par seconde
}

void KeyPressed(SDL_Keycode touche)
{
    switch (touche)
    {
    case SDLK_q:
        if (xl > 470)
            xl -= 8;
        break;
    case SDLK_d:
        if (xl + xll < 1455)
            xl += 8;
        break;
    case SDLK_SPACE:
        viballx = -5;
        vibally = -5;
        break;
    case SDLK_ESCAPE:
        freeAndTerminate();
        break;
    default:
        break;
    }
}

void joyButtonPressed()
{
    // Placeholder
}

void gameLoop()
{
    int programLaunched = 1;
    while (programLaunched)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                programLaunched = 0;
                break;

            case SDL_MOUSEBUTTONUP:
                printf("Position de la souris x : %d , y : %d\n", event.motion.x, event.motion.y);
                if ((event.motion.x < 846 && event.motion.x > 600) &&
                    (event.motion.y < 831 && event.motion.y > 741) && vieb > 0)
                {
                    menustart = 0;
                }
                else if ((event.motion.x < 846 && event.motion.x > 600) &&
                         (event.motion.y < 831 && event.motion.y > 741) && vieb == 0)
                {
                    vieb = 3;
                    largTab = 4;
                    longTab = 6;
                    tabmax = largTab * longTab;
                    nbrick = tabmax;
                    menustart = 0;
                }
                else if ((event.motion.x < 1328 && event.motion.x > 1081) &&
                         (event.motion.y < 831 && event.motion.y > 741))
                {
                    freeAndTerminate();
                }
                break;

            case SDL_KEYDOWN:
                KeyPressed(event.key.keysym.sym);
                break;

            case SDL_JOYBUTTONDOWN:
                joyButtonPressed();
                break;

            default:
                break;
            }
        }
        drawGame();
    }
}

int main(int argc, char *argv[])
{
    init(WINDOW_WIDTH, WINDOW_HEIGHT);
    init_game();
    gameLoop();
    printf("Fin du programme\n");
    freeAndTerminate();
    return 0;
}