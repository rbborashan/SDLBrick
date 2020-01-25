#include <iostream>
#include <unistd.h>
#include <SDL2/SDL.h>

#include "view.h"
#include "colors.h"

using namespace std;

int main()
{
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 700;

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event pEvent;

    bool quit = false;

    Layout l;
    Board b(SCREEN_WIDTH, SCREEN_HEIGHT, l);

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create window
    window = SDL_CreateWindow("SDLAPP", SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_WIDTH, SCREEN_HEIGHT,
                                        SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
       printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        //Get window surface
        //screenSurface = SDL_GetWindowSurface(window);

        //Fill the surface white
        //SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x2B, 0x36));

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(renderer, COL_BK_GREY);
        SDL_RenderClear(renderer);

        SDL_Rect srcrect = {50, 50, 50, 50};

        //Update the surface
        //SDL_UpdateWindowSurface(window);

        int i = 0;
        bool drawn_rect = false;

        while (!quit)
        {
            b.renderBoard(renderer);
            /*
            int ticks = (SDL_GetTicks() / 100) % 4 + 1;

            if (ticks == 4 && !drawn_rect)
            {
                cout << "draw rect\n";
                srcrect.x += 20;
                srcrect.y += 20;

                SDL_SetRenderDrawColor(renderer, COL_BK_GREY);
                SDL_RenderClear(renderer);

                if (srcrect.x < SCREEN_HEIGHT && srcrect.y < SCREEN_WIDTH)
                {
                    SDL_SetRenderDrawColor(renderer, COL_WHITE);
                    SDL_RenderDrawRect(renderer, &srcrect);
                }

                drawn_rect = true;
            }
            else if (ticks != 4 && drawn_rect)
            {
                drawn_rect = false;
            }
            else
            {
                // nothing
            }

            cout << "ticks= " << ticks << endl;
            cout << "x= " << srcrect.x << "\ny= " << srcrect.y << endl;
            */

            while (SDL_PollEvent(&pEvent))
            {
                switch (pEvent.type)
                {
                    case SDL_QUIT:
                        quit = true;
                        break;

                    case SDL_KEYDOWN:
                        quit = true;
                        break;

                    case SDL_MOUSEBUTTONDOWN:
                        quit = true;
                        break;

                    default:
                        break;
                }
            }

            //SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }

    // Exit
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
