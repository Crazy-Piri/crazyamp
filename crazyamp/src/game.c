#include <stdlib.h>
#include <string.h>

#include "shared.h"

#include "game.h"

#include "song.h"


extern u8 PLY_AKG_PLAY;

extern u8 PLY_AKG_PSGREG01_INSTR;
extern u8 PLY_AKG_PSGREG23_INSTR;
extern u8 PLY_AKG_PSGREG45_INSTR;
extern u8 PLY_AKG_PSGREG6_8_INSTR;
extern u8 PLY_AKG_PSGREG9_10_INSTR;

// void dispTitle(u8 n, u8 active)
// {
//     switch (n) {
//         case 0:
//             k_PrintGphStr8x8("TETRIS TITLE SCREEN - AYOR61", 6, 142, active);
//             break;
//         case 1:
//             k_PrintGphStr8x8("TETRIS THEME A - AYOR61", 6, 150, active);
//             break;
//         case 2:
//             k_PrintGphStr8x8("TETRIS THEME B - AYOR61", 6, 158, active);
//             break;
//         case 3:
//             k_PrintGphStr8x8("TETRIS THEME C - AYOR61", 6, 166, active);
//             break;
//         case 4:
//             k_PrintGphStr8x8("TETRIS GAME OVER - AYOR61", 6, 174, active);
//             break;
//         case 5:
//             k_PrintGphStr8x8("TETRIS SCORE - AYOR61", 6, 182, active);
//             break;
//     }
// } /* dispTitle */


#define MAXSONG 7

u8 current_song;
u8 first_song;
u16 pos;

void redrawScore(void)
{
    u8 n;

    for (n = 0; n < NBR_SONG; n++) {
        if (n < MAXSONG) {
            dispTitle(n + first_song, n, ((n + first_song) == current_song));
        }
    }
}

char mainGame(void)
{
    lzsa_expand(G_background_scr, (char *)(0xC000));
    cpc_PutSp(G_hud, 59, 80, cpc_GetScrAddress(0, (u16)(200 - 59)));

    loadSong(0);


    // k_PrintGphStr("MAIN", cpc_GetScrAddress((96 - 4 * 3) / 2, 32));

    u8 inGame = 1;
    u8 frame = 0;

    current_song = 0;
    first_song = 0;

    redrawScore();

    u8 c[9];

    while (inGame) {                                                       // Repeat until ESC pressed
        scr_waitVSYNC();

        frame++;

        if (frame == 4) {
            frame = 0;

            pos++;
            if (pos == 130) {
                cpc_PutSp(G_cursor_off, 8, 2, cpc_GetScrAddress(9 + (pos - 1) / 2, 73));
                pos = 0;
            }

            if ((pos & 1) == 0) {
                cpc_PutSp(G_cursor_1, 8, 2, cpc_GetScrAddress(9 + pos / 2, 73));
            } else {
                cpc_PutSp(G_cursor_2, 8, 2, cpc_GetScrAddress(9 + pos / 2, 73));
            }

        }


        if ((cpc_TestKey_withWait(KEY_ESCAPE)) || (cpc_TestKey_withWait(KEY_JOY_FIRE2))) {
            inGame = 0;
        }

        if ((cpc_TestKey_withWait(KEY_DOWN)) || (cpc_TestKey_withWait(KEY_JOY_DOWN))) {
            dispTitle(current_song, current_song - first_song, 0);

            current_song++;
            if (current_song == NBR_SONG) {
                current_song = 0;
                if (first_song != 0) {
                    first_song = 0;
                    redrawScore();
                }
            }

            cpc_PutSp(G_cursor_off, 8, 2, cpc_GetScrAddress(9 + pos  / 2, 73));
            pos = 0;
            loadSong(current_song);

            if (current_song - first_song >= MAXSONG) {
                first_song++;
                redrawScore();
            } else {
                dispTitle(current_song, current_song - first_song, 1);
            }
        }

        if ((cpc_TestKey_withWait(KEY_UP)) || (cpc_TestKey_withWait(KEY_JOY_UP))) {
            dispTitle(current_song, current_song - first_song, 0);

            if (current_song == 0) {
                current_song = NBR_SONG - 1;

                if (NBR_SONG >= MAXSONG) {
                    first_song = current_song - MAXSONG + 1;
                    redrawScore();
                }

            } else {
                current_song--;
                if (current_song < first_song) {
                    first_song--;
                    redrawScore();
                }
            }

            cpc_PutSp(G_cursor_off, 8, 2, cpc_GetScrAddress(9 + pos  / 2, 73));
            pos = 0;
            loadSong(current_song);

            dispTitle(current_song, current_song - first_song, 1);
        }


        u8 reg[16];

        // reg[0] = *(&PLY_AKG_PLAY + (u16)(0x707 - 0x1C3 + 1)) & 15;  // reg 1 = PLY_AKG_PSGREG01_INSTR + 1 - PLY_AKG_PLAY
        // reg[1] = *(&PLY_AKG_PLAY + (u16)(0x707 - 0x1C3 + 1)) / 16;

        reg[0] = *(&PLY_AKG_PSGREG01_INSTR + 1) & 15;
        reg[1] = *(&PLY_AKG_PSGREG01_INSTR + 1) / 16;

        // reg[2] = *(&PLY_AKG_PLAY + (u16)(0x726 - 0x1C3 + 1)) & 15;     // reg 2
        // reg[3] = *(&PLY_AKG_PLAY + (u16)(0x726 - 0x1C3 + 1)) / 16;

        reg[2] = *(&PLY_AKG_PSGREG23_INSTR + 1) & 15;  // reg 2
        reg[3] = *(&PLY_AKG_PSGREG23_INSTR + 1) / 16;

        // reg[4] = *(&PLY_AKG_PLAY + (u16)(0x747 - 0x1C3 + 1)) & 15;  // reg 3
        // reg[5] = *(&PLY_AKG_PLAY + (u16)(0x747 - 0x1C3 + 1)) / 16;

        reg[4] = *(&PLY_AKG_PSGREG45_INSTR + 1) & 15;  // reg 3
        reg[5] = *(&PLY_AKG_PSGREG45_INSTR + 1) / 16;

        // reg[6] = *(&PLY_AKG_PLAY + (u16)(0x768 - 0x1C3 + 2)); // reg 8

        reg[6] = *(&PLY_AKG_PSGREG6_8_INSTR + 2);// reg 8

        // reg[7] = *(&PLY_AKG_PLAY + (u16)(0x798 - 0x1C3 + 1)); // reg 9

        reg[7] = *(&PLY_AKG_PSGREG9_10_INSTR + 1); // reg 9

        // reg[8] = *(&PLY_AKG_PLAY + (u16)(0x798 - 0x1C3 + 2)); // reg 10

        reg[8] = *(&PLY_AKG_PSGREG9_10_INSTR + 2); // reg 10

        u8 n;
        for (n = 0; n < 9; n++) {
            // drawInteger(4 + n * 6, 182, (reg[n] & 15), 2);

            reg[n] = reg[n] & 15;

            if (c[n] != reg[n]) {
                if (c[n] < reg[n]) {
                    u8 y;
                    reg[n] = c[n] + 1;

                    for (y = c[n]; y < reg[n]; y++) {
                        switch (n) {
                            case 0:
                                cpc_PutSp(G_on_a, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                                break;
                            case 1:
                                cpc_PutSp(G_on_b, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                                break;
                            case 2:
                                cpc_PutSp(G_on_a, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                                break;
                            case 3:
                                cpc_PutSp(G_on_b, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                                break;
                            case 4:
                                cpc_PutSp(G_on_a, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                                break;
                            case 5:
                                cpc_PutSp(G_on_b, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                                break;
                            case 6:
                                cpc_PutSp(G_on_1, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                                break;
                            case 7:
                                cpc_PutSp(G_on_2, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                                break;
                            case 8:
                                cpc_PutSp(G_on_3, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                                break;
                        } /* switch */
                    }
                } else {
                    u8 y;

                    reg[n] = c[n] - 1;


                    for (y = reg[n]; y < c[n]; y++) {
                        cpc_PutSp(G_off, 2, 2, cpc_GetScrAddress(12 + n * 2 + 4, 57 - y * 2));
                    }
                }
                c[n] = reg[n];
            }

        }


    }

    while (cpc_AnyKeyPressed()) {
    }


    return (char)SC_INTRO;

}     /* mainGame */