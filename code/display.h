#ifndef DISPLAY_H
#define DISPLAY_H

/*Method declared to print the screen(refresh) each time user inputs a move command and at the start of the game*/

void printScreen(int printRow, int printCol, char** printMap, int plyRow, int plyCol, int golRow, int golCol, int blockRow, int blockCol, int remRed);

#endif