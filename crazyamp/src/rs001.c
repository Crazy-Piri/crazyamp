/*
 *      001 - 8x8 Chars & Small Scroll
 *      CPCRSLIB demo
 *
 *      zcc +cpc -lndos -create-app -Cz--audio -lm rs001.c
 */

#include <stdlib.h>
#include <string.h>

#include "shared.h"

#include "game.h"

CPC_SCENE partGame;


void main(void)
{
    __asm
    call _SetStack
        __endasm;

    cpc_DisableFirmware();

    cpc_SetMode(0);

// Song

  #ifdef SOUND
    __asm
    push af
    push bc
    push ix
    push iy

    ld hl, #_EMPTYSONG_START
    xor a, a
    call _PLY_AKG_INIT

    ld hl, #_SOUNDEFFECTS_SOUNDEFFECTS
    xor a, a
    call _PLY_AKG_INITSOUNDEFFECTS


    pop iy
    pop ix
    pop bc
    pop af
       __endasm;
#endif /* ifdef SOUND */

    installArkosHook();     // Load _PLY_AKG_INIT before installing the hook

// Keyboard definition

    cpc_AssignKey(KEY_RIGHT, 0x4002);       // key RIGHT
    cpc_AssignKey(KEY_LEFT, 0x4101);       // key LEFT
    cpc_AssignKey(KEY_DOWN, 0x4004);       // key DOWN
    cpc_AssignKey(KEY_UP, 0x4001);       // key UP
    cpc_AssignKey(KEY_FIRE, 0x4580);       // key "space"
    cpc_AssignKey(KEY_ESCAPE, 0x4804);       // key "ESC"

    cpc_AssignKey(KEY_JOY_RIGHT, 0x4908); // joy right
    cpc_AssignKey(KEY_JOY_LEFT, 0x4904);// joy left
    cpc_AssignKey(KEY_JOY_UP, 0x4901);       // joy up
    cpc_AssignKey(KEY_JOY_DOWN, 0x4902);   // joy down

    cpc_AssignKey(KEY_JOY_FIRE1, 0x4910);// joy fire1
    cpc_AssignKey(KEY_JOY_FIRE2, 0x4920);// joy fire2

    cpc_AssignKey(KEY_SHIFT, 0x4220);// joy shift



// Palette


    char hwInk[27] = {0x14, 0x04, 0x15, 0x1C, 0x18, 0x1D, 0x0C, 0x05, 0x0d, 0x16, 0x06, 0x17, 0x1E, 0x00, 0x1f, 0x0e, 0x07, 0x0f, 0x12, 0x02, 0X13, 0x1A, 0x19, 0x1B, 0x0A, 0x03, 0x0B};
    char col[16] = {0, 1, 3, 26,  11, 12, 13, 14, 15, 16, 18,  23, 25, 0, 0, 0};
    int n;

    for (n = 0; n < 16; n++) {
        cpc_SetColour(n, hwInk[col[n]]);
    }
    cpc_SetColour(16, 0x00);


// Game settings

    partGame = SC_GAME;


    while (partGame != SC_END) {

        if (partGame == SC_GAME) {
            partGame = mainGame();
        }

        if (partGame == SC_END) {

        }

    }


    cpc_EnableFirmware();         // before exit, firmware jump is restored


}     /* main */






