#include <stdio.h>
#include <stdlib.h>
#include "blocking.h"
#include "random.h"
#include "game.h"
#include "linkedList.h"
/*
 METHOD: blocks 
 PURPOSE: Blocks are created and assigned to the array in this method.
 IMPORTS: Arguments for size of the game interface, location of player, goal, pointer to an 
 array to store the latest location of the block and the array containing all the game content.
 EXPORTS: pointer to the array containing  the location of the latest block
 */
/*Method declared to create the blocks for each move*/
int* blocks(char** blockMap, int bRow, int bcol, int pRow, int pCol, int gRow, int gCol, int* locat)
{
	

	
          /*Generating random numbers for row and coloumn for the blocks to be placed*/
		int rowNum = randomNum(1, (bRow-2)); 
		int colNum = randomNum(1, (bcol-2));
	

	  /*Row number and coloumn number are regenerated if it is created on the player, goal or on another block(overlapping)*/
	  /*So that in each move, a new block will be assigned ideally*/
	   while(((rowNum == pRow) && (colNum == pCol)) || ((rowNum == gRow) && (colNum == gCol)) || (blockMap[rowNum][colNum] == 'X') )
	   {
		/*Regeneration of blocks since they overlap goal, player or blocks*/
            rowNum = randomNum(1, (bRow-2)); 
		    colNum = randomNum(1, (bcol-2));
	   }
	   /*Assigning block in the generated position of the array */
	             blockMap[rowNum][colNum] = 'X';

				 locat[0] = rowNum;
				 locat[1] = colNum;
	

				 return locat;

	


}