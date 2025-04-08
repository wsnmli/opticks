#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <filesystem>
#include "math/math.hpp"
#include "input_classes.hpp"
using namespace std;

#define W_WIDTH  (1000)		// window width
#define W_HEIGHT (700)

static int SDL_SetRenderDrawColor(SDL_Renderer *renderer, SDL_Color color) {
	return SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}

class Framework { public:
    SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	SDL_Color background_color, draw_color;
    TTF_Font* font;

    Controller controller;
    int numControllers;
    Mouse mouse;
    Keyboard keys;

    unsigned long min_frame_time{16}, frame_time;
public:
    Framework(const char* title) {
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
        IMG_Init(IMG_INIT_JPG);
        TTF_Init();
        font = TTF_OpenFont("/usr/share/fonts/truetype/roboto/unhinted/RobotoCondensed-Medium.ttf", 100);
        if (!font) cerr << "Error font broke";

		window = SDL_CreateWindow(title, 0, 0, W_WIDTH, W_HEIGHT, 0);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        numControllers = SDL_NumJoysticks();
        controller = Controller(1);
    }

    void set_background_color(SDL_Color c) {
        background_color = {c.r, c.g, c.b};
    }

    void update_input() {
        controller.resetPressedButtons();
        mouse.resetPressedButtons();
        keys.resetPressedKeys();
        
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN: {
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE: 
                            exit(0);
                        case SDLK_a: 
                            keys.aPressed = true; 
                            keys.aHeld = true; 
                            break;
                        case SDLK_b: 
                            keys.bPressed = true; 
                            keys.bHeld = true; 
                            break;
                        case SDLK_c: 
                            keys.cPressed = true; 
                            keys.cHeld = true; 
                            break;
                        case SDLK_d: 
                            keys.dPressed = true; 
                            keys.dHeld = true; 
                            break;
                        case SDLK_e: 
                            keys.ePressed = true; 
                            keys.eHeld = true; 
                            break;
                        case SDLK_f: 
                            keys.fPressed = true; 
                            keys.fHeld = true; 
                            break;
                        case SDLK_g: 
                            keys.gPressed = true; 
                            keys.gHeld = true; 
                            break;
                        case SDLK_h: 
                            keys.hPressed = true; 
                            keys.hHeld = true; 
                            break;
                        case SDLK_i: 
                            keys.iPressed = true; 
                            keys.iHeld = true; 
                            break;
                        case SDLK_j: 
                            keys.jPressed = true; 
                            keys.jHeld = true; 
                            break;
                        case SDLK_k: 
                            keys.kPressed = true; 
                            keys.kHeld = true; 
                            break;
                        case SDLK_l: 
                            keys.lPressed = true; 
                            keys.lHeld = true; 
                            break;
                        case SDLK_m: 
                            keys.mPressed = true; 
                            keys.mHeld = true; 
                            break;
                        case SDLK_n: 
                            keys.nPressed = true; 
                            keys.nHeld = true; 
                            break;
                        case SDLK_o: 
                            keys.oPressed = true; 
                            keys.oHeld = true; 
                            break;
                        case SDLK_p: 
                            keys.pPressed = true; 
                            keys.pHeld = true; 
                            break;
                        case SDLK_q: 
                            keys.qPressed = true; 
                            keys.qHeld = true; 
                            break;
                        case SDLK_r: 
                            keys.rPressed = true; 
                            keys.rHeld = true; 
                            break;
                        case SDLK_s: 
                            keys.sPressed = true; 
                            keys.sHeld = true; 
                            break;
                        case SDLK_t: 
                            keys.tPressed = true; 
                            keys.tHeld = true; 
                            break;
                        case SDLK_u: 
                            keys.uPressed = true; 
                            keys.uHeld = true; 
                            break;
                        case SDLK_v: 
                            keys.vPressed = true; 
                            keys.vHeld = true; 
                            break;
                        case SDLK_w: 
                            keys.wPressed = true; 
                            keys.wHeld = true; 
                            break;
                        case SDLK_x: 
                            keys.xPressed = true; 
                            keys.xHeld = true; 
                            break;
                        case SDLK_y: 
                            keys.yPressed = true; 
                            keys.yHeld = true; 
                            break;
                        case SDLK_z: 
                            keys.zPressed = true; 
                            keys.zHeld = true; 
                            break;

                        case SDLK_UP:
                            keys.upPressed = true;
                            keys.upHeld = true; 
                            break;
                        case SDLK_DOWN:
                            keys.downPressed = true;
                            keys.downHeld = true; 
                            break;
                        case SDLK_LEFT:
                            keys.leftPressed = true;
                            keys.leftHeld = true; 
                            break;
                        case SDLK_RIGHT:
                            keys.rightPressed = true;
                            keys.rightHeld = true; 
                            break;

                        default: 
                            break;
                    }
                } break;
                case SDL_JOYBUTTONDOWN: {
                    int b = event.cbutton.button;
				    printf(" the button number is %d\n", b);
				    switch (event.cbutton.button) {
                        case 0:
                            controller.trianglePressed = true;
                            controller.triangleHeld = true;
                            break;
                        case 1:
                            controller.circlePressed = true;
                            controller.circleHeld = true;
                            break;
                        case 2:     // x button
                            controller.crossPressed = true;
                            controller.crossHeld = true;
                            break;
                        case 3:     // square button
                            controller.squarePressed = true;
                            controller.squareHeld = true;
                            break;
                        case 4:     // l2
                            controller.l2Pressed = true;
                            controller.l2Held = true;
                            break;
                        case 5:     // r2
                            controller.r2Pressed = true;
                            controller.r2Held = true;
                            break;
                        case 6:     // l1
                            controller.l1Pressed = true;
                            controller.l1Held = true;
                            break;
                        case 7:     // r2
                            controller.r2Pressed = true;
                            controller.r2Held = true;
                            break;
                        case 8:  // select
                            controller.selectPressed = true;
                            controller.selectHeld = true;
                            break;
                        case 9:     // start button
                            controller.startPressed = true;
                            controller.startHeld = true;
                            break;
                        case 10:    // l3
                            controller.l3Pressed = true;
                            controller.l3Held = true;
                            break;
                        case 11:    // r3
                            controller.r3Pressed = true;
                            controller.r3Held = true;
                            break;
                        default: 
                            break;
                    }
                } break;

                case SDL_JOYBUTTONUP: {
				    switch (event.cbutton.button) {
                        case 0:
                            controller.triangleHeld = false;
                            break;
                        case 1:
                            controller.circleHeld = false;
                            break;
                        case 2:     // x button
                            controller.crossHeld = false;
                            break;
                        case 3:     // square button
                            controller.squareHeld = false;
                            break;
                        case 4:     // l2
                            controller.l2Held = false;
                            break;
                        case 5:     // r2
                            controller.r2Held = false;
                            break;
                        case 6:     // l1
                            controller.l1Held = false;
                            break;
                        case 7:     // r2
                            controller.r2Held = false;
                            break;
                        case 8:     // select
                            controller.selectHeld = false;
                            break;
                        case 9:     // start button
                            controller.startHeld = false;
                            break;
                        case 10:    // l3
                            controller.l3Held = false;
                            break;
                        case 11:    // r3
                            controller.r3Held = false;
                            break;
                        
                        default: 
                            break;
                    }
                } break;

                case SDL_CONTROLLERBUTTONDOWN: {
                    switch(event.cbutton.button) {
                        case SDL_CONTROLLER_BUTTON_DPAD_UP:
                            controller.upHeld = true;
                            controller.upPressed = true;
                            break;
                        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                            controller.rightHeld = true;
                            controller.rightPressed = true;
                            break;
                        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                            controller.leftHeld = true;
                            controller.leftPressed = true;
                            break;
                        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                            controller.downHeld = true;
                            controller.downPressed = true;
                            break;
                        
                        default:
                            break;
                    }
                } break;
                case SDL_CONTROLLERBUTTONUP: {
                    switch(event.cbutton.button) {
                        case SDL_CONTROLLER_BUTTON_DPAD_UP:
                            controller.upHeld = false;
                            break;
                        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                            controller.rightHeld = false;
                            break;
                        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                            controller.leftHeld = false;
                            break;
                        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                            controller.downHeld = false;
                            break;
                        
                        default:
                            break;
                    }
                } break;

                case SDL_MOUSEBUTTONDOWN: {
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:
                            mouse.leftHeld = true;
                            mouse.leftPressed = true;
                            break;
                        case SDL_BUTTON_RIGHT:
                            mouse.rightHeld = true;
                            mouse.rightPressed = true;
                            break;

                        default:
                            break;
                    }
                } break;
                case SDL_MOUSEBUTTONUP: {
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:
                            mouse.leftHeld = false;
                            break;
                        case SDL_BUTTON_RIGHT:
                            mouse.rightHeld = false;
                            break;

                        default:
                            break;
                    }
                }
            }

            SDL_GetMouseState(&mouse.pos.x, &mouse.pos.y);
        }
    }

    void set_draw_color(Uint8 r, Uint8 g, Uint8 b) {
		draw_color = {r, g, b};
		SDL_SetRenderDrawColor(renderer, draw_color);
	}

    void blank() {
        frame_time = SDL_GetTicks();

        SDL_SetRenderDrawColor(renderer, background_color);
	    SDL_RenderClear(renderer);
    }

	void render() { // render first
        SDL_RenderPresent(renderer);
        
        // then delay necary amount
        if (SDL_GetTicks() - frame_time < min_frame_time) {
            SDL_Delay(min_frame_time - (SDL_GetTicks() - frame_time));
        } else cerr << "Frame took to long\n" << flush;
    }

    template<typename Vector>
    void draw_line(Vector v1, Vector v2) {
        SDL_SetRenderDrawColor(renderer, draw_color);
		SDL_RenderDrawLine(renderer, v1.x, v1.y, v2.x, v2.y);
	}

    template<typename Vector>
	void draw_circle(Vector centre, int radius) {
		for(int x=centre.x-radius; x<=centre.x+radius; x++)
			for(int y=centre.y-radius; y<=centre.y+radius; y++)
				if((pow(centre.y-y,2) + pow(centre.x-x,2)) <= pow(radius,2))
					SDL_RenderDrawPoint(renderer, x, y);
	}

    template<typename Vector>
    void draw_triangle(Vector P1, Vector P2, Vector P3) {
		draw_line(P1, P2);
        draw_line(P2, P3);
        draw_line(P3, P1);
	}

    void draw_rectangle(Vector2i centre, int w, int h) {
        SDL_Rect rect = {centre.x - w/2, centre.y - h/2, w, h};
        SDL_RenderFillRect(renderer, &rect);
    } 

    SDL_Texture* createTexture(const char *filePath) {
		SDL_Surface* surface = IMG_Load(filePath);
		SDL_Texture* tmp;
        if (!surface) 
            cerr << "Error file not found\n" << flush;
        tmp = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

        return tmp;
	}
};