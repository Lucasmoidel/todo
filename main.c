#include <stdio.h>
#include <stdbool.h>
#include "kiss_sdl/kiss_sdl.h"

void button_event(kiss_button* new_entry, SDL_Event* e, int* draw, kiss_entry* entry);

int main(int argc, char **argv){
    SDL_Renderer *renderer;
    SDL_Event e;
    kiss_array objects;
    kiss_window window;
    kiss_button new_entry;
    kiss_entry entry;
    int draw, quit;
    quit = 0;
    draw = 1;
    kiss_array_new(&objects);
    renderer = kiss_init("Hello kiss_sdl", &objects, 1000, 500);
    if (!renderer) return 1;
    kiss_window_new(&window, NULL, 0, 0, 0, kiss_screen_width, kiss_screen_height);
    kiss_entry_new(&entry, &window, 1, "", 0, kiss_normal.h, 914);
    kiss_button_new(&new_entry, &window, "Add", window.rect.w - kiss_normal.w, kiss_normal.h);
    
    window.visible = 1;
    while (!quit) {
        SDL_Delay(10);
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = 1;
            kiss_window_event(&window, &e, &draw);
            button_event(&new_entry, &e, &draw, &entry);
            kiss_entry_event(&entry, &e, &draw);
        } 
        if (!draw) continue;
        SDL_RenderClear(renderer);
        kiss_window_draw(&window, renderer);
        kiss_button_draw(&new_entry, renderer);
        kiss_entry_draw(&entry, renderer);
        SDL_RenderPresent(renderer);
        draw = 0;
            }
    kiss_clean(&objects);
    return 0;
}



void button_event(kiss_button* new_entry, SDL_Event* e, int* draw, kiss_entry *entry) {
    if (kiss_button_event(new_entry, e, draw)) {
        FILE *fptr;
        fptr = fopen("todo.txt", "a");
        char thing[102];
        int x;
        bool end = false;
        for (x = 0; x < 100; x++) {
            if (entry->text[x] == 0) end = true ; 

            if (end == true) {
                thing[x] = ' ';    
            } else {
                thing[x] = entry->text[x];
            }
            
        }
        thing[100] = 'y';
        thing[101] = '\0';
        fprintf(fptr, "%s\n", thing);
        fclose(fptr);
        strcpy(entry->text, "");

    }
    
}