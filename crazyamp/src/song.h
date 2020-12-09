#define NBR_SONG 6

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
}


void dispTitle(u8 n, u8 pos, u8 active)
{
switch (n) {
        case 0:
            k_PrintGphStr8x8("TITLE SCREEN (AYOR61)           ", 6, 142 + pos * 7, active);
            break;
        case 1:
            k_PrintGphStr8x8("THEME A (AYOR61)                ", 6, 142 + pos * 7, active);
            break;
        case 2:
            k_PrintGphStr8x8("THEME B (AYOR61)                ", 6, 142 + pos * 7, active);
            break;
        case 3:
            k_PrintGphStr8x8("THEME C (AYOR61)                ", 6, 142 + pos * 7, active);
            break;
        case 4:
            k_PrintGphStr8x8("SCORES (AYOR61)                 ", 6, 142 + pos * 7, active);
            break;
        case 5:
            k_PrintGphStr8x8("GAME OVER (AYOR61)              ", 6, 142 + pos * 7, active);
            break;

}
} /* dispTitle */
