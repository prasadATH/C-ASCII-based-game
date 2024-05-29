#include<stdio.h>
#include <stdlib.h>
#include "display.h"
#include "color.h"
/*
 METHOD: printScreen
 PURPOSE: To refresh screen in each command(print the array).
 IMPORTS: Arguments for size of the game interface, location of player, goal,
 latest location of the block , command whether to remove the red background or not and the array containing all the game content.
 EXPORTS: None
 */
/*Method declared to print the screen(refresh) each time user inputs a move command and at the start of the game*/
void printScreen(int printRow, int printCol, char** printMap, int plyRow, int plyCol, int golRow, int golCol, int blockRow, int blockCol, int remRed)
{
	/*Integer variables to track rows and coloums of the array*/
	int s;
	int t;
	


	/*clears screen to display the game interface without the prompt */

	   system("clear");

                                   /*assigns player in the new positions user moved it into*/
					                printMap[plyRow][plyCol] = 'P';


/*assigning '*' as it's frame in the edge rows and columns of the array*/
       for(s=0;s<printRow;s++)
          {
	          for(t=0;t<printCol;t++)
                  {

			           printMap[s][0] = '*';
		               printMap[s][(printCol-1)] = '*';

					   printMap[0][t] = '*';
                       printMap[(printRow-1)][t] = '*';

		          }

           }
/*Prints all assigned characters to the array*/
         for(s=0;s<printRow;s++)
                    {

	                   for(t=0;t<printCol;t++)
                            {
								
								if((s==plyRow) &&(t==plyCol))/*If player location is matched; player is printed in blue*/
								{
									setForeground("blue");
									printf("%c",printMap[s][t]);
									setForeground("reset");
								}else if((s==golRow) &&(t==golCol))/*If goal location is matched; goal is printed in yellow*/
								{
									setForeground("yellow");
									printf("%c",printMap[s][t]);
									setForeground("reset");
								}else if((s==blockRow) &&(t==blockCol) &&(remRed ==0))
								{                               /*If the most recent block location is matched; block is printed with a background color red*/
									setBackground("red");
									printf("%c",printMap[s][t]);
									setBackground("reset");
								}

								else{
	                                printf("%c",printMap[s][t]);
								}
									

	                                if(t ==(printCol-1))
			                              {
				                              printf("\n");

			                               }
		                    }



                    }	


	             
           
					/*Displays all the content required to move the player*/
printf("Press 'W' key to move Up\nPress 'S' key to move Down\nPress 'A' key to move Left\nPress 'D' key to move Right\nPress 'U' key to undo the current move\n");


}