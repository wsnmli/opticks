#include "math/math.hpp"
#include <SDL2/SDL.h>

class Keyboard { public:
    bool qPressed;
    bool wPressed;
    bool ePressed;
    bool rPressed;
    bool tPressed;
    bool yPressed;
    bool uPressed;
    bool iPressed;
    bool oPressed;
    bool pPressed;
    bool aPressed;
    bool sPressed;
    bool dPressed;
    bool fPressed;
    bool gPressed;
    bool hPressed;
    bool jPressed;
    bool kPressed;
    bool lPressed;
    bool zPressed;
    bool xPressed;
    bool cPressed;
    bool vPressed;
    bool bPressed;
    bool nPressed;
    bool mPressed;

    bool qHeld;
    bool wHeld;
    bool eHeld;
    bool rHeld;
    bool tHeld;
    bool yHeld;
    bool uHeld;
    bool iHeld;
    bool oHeld;
    bool pHeld;
    bool aHeld;
    bool sHeld;
    bool dHeld;
    bool fHeld;
    bool gHeld;
    bool hHeld;
    bool jHeld;
    bool kHeld;
    bool lHeld;
    bool zHeld;
    bool xHeld;
    bool cHeld;
    bool vHeld;
    bool bHeld;
    bool nHeld;
    bool mHeld;

    bool upPressed;
    bool downPressed;
    bool leftPressed;
    bool rightPressed;

    bool upHeld;
    bool downHeld;
    bool leftHeld;
    bool rightHeld;

    void resetPressedKeys() {
    qPressed = false;
    wPressed = false;
    ePressed = false;
    rPressed = false;
    tPressed = false;
    yPressed = false;
    uPressed = false;
    iPressed = false;
    oPressed = false;
    pPressed = false;
    aPressed = false;
    sPressed = false;
    dPressed = false;
    fPressed = false;
    gPressed = false;
    hPressed = false;
    jPressed = false;
    kPressed = false;
    lPressed = false;
    zPressed = false;
    xPressed = false;
    cPressed = false;
    vPressed = false;
    bPressed = false;
    nPressed = false;
    mPressed = false;

    upPressed = false;
    downPressed = false;
    leftPressed = false;
    rightPressed = false;
    }
};

class Mouse { public:
    Vector2i pos;
	bool leftPressed, rightPressed, middlePressed;
	bool leftHeld, rightHeld, middleHeld;

    void resetPressedButtons() {
        leftPressed = false;
		rightPressed = false;
        middlePressed = false;
    }

    Vector2i postion() {
        int x, y;
        SDL_GetMouseState(&x, &y);
        return {x, y};
    }
};

class Controller{ public:
    SDL_GameController *controller;
    Controller() {
        leftHeld = false;
        rightHeld = false;
        upHeld = false;
        downHeld = false;

        crossHeld = false;
        squareHeld = false;
        triangleHeld = false;
        circleHeld = false;

        l1Held = false;
        l2Held = false;
        l3Held = false;
        r1Held = false;
        r2Held = false;
        r3Held = false;

        startHeld = false;
        selectHeld = false;
    }

    Controller(int n) : Controller() {
        controller = SDL_GameControllerOpen(n); 
    }
    
    Vector2i leftStick, rightStick;
	
	//	d-pad
	bool leftPressed, rightPressed, upPressed, downPressed;
	bool leftHeld, rightHeld, upHeld, downHeld;
	
	//	face buttons
	bool crossPressed, squarePressed, trianglePressed, circlePressed;
	bool crossHeld, squareHeld, triangleHeld, circleHeld;

    bool startPressed, selectPressed;
    bool startHeld, selectHeld;

    bool r1Pressed, r2Pressed, l1Pressed, l2Pressed;
    bool r1Held, r2Held, l1Held, l2Held;

    bool l3Pressed, r3Pressed;
    bool l3Held, r3Held;

    void resetPressedButtons() {
        leftPressed = false;
		rightPressed = false;
		upPressed = false;
		downPressed = false;

        crossPressed = false;
		squarePressed = false;
        trianglePressed = false;
        circlePressed = false;

        l1Pressed = false;
        l2Pressed = false;
        l3Pressed = false;
        r1Pressed = false;
        r2Pressed = false;
        r3Pressed = false;

        startPressed = false;
        selectPressed = false;
	}

    Vector2i leftAxis() {
	    return {SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX) / 256,
                SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY) / 256 };
    }

    Vector2i rightAxis() {
	    return {SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTX) / 256,
                SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTY) / 256 };
    }
};