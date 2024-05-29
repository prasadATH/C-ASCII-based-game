#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"

#include "game.h"


/*
 NAME: Thilina Athukorala 
 PURPOSE: Properties mandatory to start the game such as valid user inputs(arguments) are controlled in this function.
 IMPORTS: command line arguments for size of the game interface, location of player, goal
 (row, col , plRow, plCol, glRow, glCol)
 EXPORTS: return '0' at the end 
 ASSERTIONS:  
 PRE: row = number of rows in the game interface.
      col =  number of columns in the game interface.
	  plRow, plCol = location of player.
	  glRow, glCol = location of goal.
 POST: Game will either be won or lost.
 MODIFIED : 2022-10-16
 */


int main(int argc, char* argv[])
{    /*variable to handle the pointers array*/
	  int i;
	  

	
	int row, col, plRow, plCol, glRow, glCol;
	

	
	
/*six malloc pointers to assign the six variables*/
int* pointr = (int*)malloc(6 * sizeof(int));
 int** data = NULL;
  char* fileName = argv[1];
  

		   /*if the user did not enter the file name as a command line argument, it prints a statement and frees the memory before exiting*/
 	if(argc<2 )
	{

						free(pointr);
	                     pointr= NULL;

		     printf("\nIncorrect amount of data! Please enter the following argument with your run command to continue \n");
             printf("\n<Name of file containing the game data> \n\n");

			 return 0;
	}
	/*assinging data extracted from the file using readfile method to the malloc 2D arrray*/
   data = readFile(fileName);
   
    if ( data== NULL) {/*handling the exceptions in file reading*/
        printf("Invalid file name/File cannot be found! please try re-entering a valid file name \n");
		return 0;
    }
  
  

row =0;
col=0;
plRow=0;
plCol=0;
glRow=0;
glCol=0;


    row = data[0][0]+3;  /*increase the user given border sizes by 2 to print the borders in either sides*/
    col =data[0][1]+3;  /*and give the exact play area for the user without counting them to print '*' */

	plRow = data[1][0]+1; /*increase the user given position by 1 to print the player in exact index mentioned by user*/
	plCol = data[1][1]+1;

	glRow= data[2][0]+1; /*increase the user given position by 1 to print the goal in exact index mentioned by user*/
	glCol= data[2][1]+1;


pointr[0]= row;
pointr[1]= col;
pointr[2]= plRow;
pointr[3]= plCol;
pointr[4]= glRow;
pointr[5]= glCol;



	for(i=0;i<6;i++)
			{
				

				if(pointr[i]<1)
				{
						free(pointr);
	                     pointr= NULL;

						 			i=0;
	                               for (i = 0; i < 20; i++)

                                      {
	                                         free(data[i]);
			                           	  data[i] = NULL;

                                      }
		                          free(data);
		                         data = NULL;

                   printf("row and column numbers cannot be negative! \n please enter a valid integer \n");
				   
				    return 0;
				}
				

			}
/*checking whether the row and coloumn size of the play area are not too small and
 freeing the memory if the program does not meet the requirements*/
			if(((pointr[0]-2)<6) || ((pointr[1]-2)<6))
				{
					
					free(pointr);
	                     pointr= NULL;

						 			i=0;
	                               for (i = 0; i < 20; i++)

                                      {
	                                         free(data[i]);
			                           	  data[i] = NULL;

                                      }
		                          free(data);
		                         data = NULL;
					 printf("\nrow and column size cannot be less than 5!\n please enter a value greater than 5\n");
					  return 0;
				}
/*checking whether the row and coloumn size of the play area are not too large and 
freeing the memory if the program does not meet the requirements*/
			if((pointr[0]>30) || (pointr[1] >60))
				{
					free(pointr);
	                     pointr= NULL;

						 			i=0;
	                               for (i = 0; i < 20; i++)

                                      {      
	                                         free(data[i]);
			                           	  data[i] = NULL;

                                      }
		                          free(data);
		                         data = NULL;
					 printf("\nrow size cannot be greater than 30 and coloumn size cannot be greater than 60!");
					 printf("\n  please enter a value less than 30 for rows and less than 60 for columns\n");
					  return 0;
				}
/*checking whether the row and coloumn of the player and goal are in the play area(not exceeding the user defined region)*/
			if(((pointr[0]-2)<pointr[2]) || ((pointr[1]-2) <pointr[3]) || ((pointr[0]-2)<pointr[4]) || ((pointr[1]-2) <pointr[5]))
				{
					free(pointr);
	                     pointr= NULL;

						 			i=0;
	                               for (i = 0; i < 20; i++)

                                      {
	                                         free(data[i]);
			                           	  data[i] = NULL;

                                      }
		                          free(data);
		                         data = NULL;
					 printf("\nplayer and goal (row and column) size cannot be greater than the entered row and column size of the boders!\n");
					 printf("\n                   please enter a value less than the entered border sizes.\n");
					  return 0;
				}



	free(pointr);
	pointr= NULL;

gamePlay(row, col, plRow, plCol, glRow, glCol, data);/*calls the method which controls the game */


/*frees all the dynamically allocated memory */
			i=0;
	  for (i = 0; i < 20; i++)

           {
	              free(data[i]);
				  data[i] = NULL;

           }
		   free(data);
		    data = NULL;
	

	return 0;
}
















