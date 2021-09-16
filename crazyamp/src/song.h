#define NBR_SONG 16

void loadSong(char song)
{


if (song == 0) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG00_START
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
    }
if (song == 1) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG01_START
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
    }
if (song == 2) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG02_START
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
    }
if (song == 3) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG03_START
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
    }
if (song == 4) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG04_START
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
    }
if (song == 5) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG05_START
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
    }
if (song == 6) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG06_START
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
    }
if (song == 7) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG07_START
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
    }
if (song == 8) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG08_START
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
    }
if (song == 9) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG09_START
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
    }
if (song == 10) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG10_START
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
    }
if (song == 11) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG11_START
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
    }
if (song == 12) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG12_START
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
    }
if (song == 13) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG13_START
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
    }
if (song == 14) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG14_START
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
    }
if (song == 15) {
         #ifdef SOUND
        __asm
        push af
        push bc
        push ix
        push iy

        ld hl, #_SONG15_START
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
    }
}


void dispTitle(u8 n, u8 pos, u8 active)
{
switch (n) {
        case 0:
            k_PrintGphStr8x8("INTRO (OLD)                     ", 6, 142 + pos * 7, active);
            break;
        case 1:
            k_PrintGphStr8x8("03 - LET'S GO TO PAO PAO ISLAND ", 6, 142 + pos * 7, active);
            break;
        case 2:
            k_PrintGphStr8x8("BUBBLE BOBBLE THEME             ", 6, 142 + pos * 7, active);
            break;
        case 3:
            k_PrintGphStr8x8("INTRO (NEW)                     ", 6, 142 + pos * 7, active);
            break;
        case 4:
            k_PrintGphStr8x8("LET'S GO TO PAO PAO ISLAND (NEW)", 6, 142 + pos * 7, active);
            break;
        case 5:
            k_PrintGphStr8x8("YOU WIN                         ", 6, 142 + pos * 7, active);
            break;
        case 6:
            k_PrintGphStr8x8("APRIL FOREST                    ", 6, 142 + pos * 7, active);
            break;
        case 7:
            k_PrintGphStr8x8("RAINBOW ISLAND MAIN THEME       ", 6, 142 + pos * 7, active);
            break;
        case 8:
            k_PrintGphStr8x8("NEW ZEALAND  STORY THEME (OLD)  ", 6, 142 + pos * 7, active);
            break;
        case 9:
            k_PrintGphStr8x8("VERSUS CHALLENGE                ", 6, 142 + pos * 7, active);
            break;
        case 10:
            k_PrintGphStr8x8("HURRY UP                        ", 6, 142 + pos * 7, active);
            break;
        case 11:
            k_PrintGphStr8x8("ARKANOID THEME ( EXTENDED )     ", 6, 142 + pos * 7, active);
            break;
        case 12:
            k_PrintGphStr8x8("INTRODUCTION (NEW) DS VERSION   ", 6, 142 + pos * 7, active);
            break;
        case 13:
            k_PrintGphStr8x8("PARASOL STAR THEME              ", 6, 142 + pos * 7, active);
            break;
        case 14:
            k_PrintGphStr8x8("KIWI KRAZE                      ", 6, 142 + pos * 7, active);
            break;
        case 15:
            k_PrintGphStr8x8("CHASE HQ                        ", 6, 142 + pos * 7, active);
            break;

}
} /* dispTitle */
