#include "shared.h"

void scr_waitVSYNC(void);
void switchTo192x160(void);
u8 cpc_TestKey_withWait(MY_KEY key);
void drawInteger(u16 x, u16 y, u16 i, u8 len);

void k_PrintGphStr(char *text, int destino);
void k_PrintGphStr8x8(char *text, u8 posx, u8 posy, u8 active);