#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"
#include "terminal.h"
#include "display.h"
#include "blocking.h"
#include "goal.h"
#include "lock.h"
#include "game.h"
#include "linkedList.h"


/*
 NAME: Thilina Athukorala 
 METHOD : gamePlay
 PURPOSE: Main features of the game are controlled in this function (moving player , lose and win conditions).
 IMPORTS: command line arguments for size of the game interface, location of player, goal
 (row, col , plRow, plCol, glRow, glCol)
 EXPORTS: none 
 ASSERTIONS:  
 PRE: row = number of rows in the game interface.
      col =  number of columns in the game interface.
	  plRow, plCol = location of player.
	  glRow, glCol = location of goal.
 POST: Game will either be won or lost.
 */


void gamePlay(int row, int col, int plRow, int plCol, int glRow, int glCol, int **fileData)
{
/*variable to handle arrays*/
	  int i;
	  int j;
	  

	char command =' ';
	int goal =0;
	int lose=0;
	int gLose=0;
	
	int lockRes=0;/*variable to store whether the new location of player is blocked with a 'X' or '*' */
	
	char** base;
	int blockRow=0;/*variable to store and pass the row number of most recent block*/
	int blockCol=0;/*variable to store and pass the column number of most recent block*/
	int count=0;
	int remRed=0;/*variable to store and pass the requirement of not printing the red background in unnessasary locations*/
	int* loc; /*pointer  to pass the locations of most recent blocks*/
	int loca[2];/*array for storing locations of the most recent blocks*/
	
	
	
	CIntlinkedList* list = NULL;/*linked list declared to store each movement of the player */

	CIntlinkedList* blockList = NULL;/*linked list declared to store location of each block created */
	blockList = createLinkedList();/*initilizing the linked list*/

	
	list = createLinkedList();/*initilizing the linked list*/


/*Initializing random number generator */
	initRandom();



	  /*creating an malloc array*/      
	         base=(char**)malloc(row * sizeof(char*));
/*Converting to a malloc 2D array by pointing each malloc row to store the game content*/
	  for (i = 0; i < row; i++)

           {
	              base[i] = (char*)malloc((col * sizeof(char)));

           }

   
  /*making the whole character array empty */ 
  for(i=0;i<row;i++)
          {
	          for(j=0;j<col;j++)
                  {
			           base[i][j] = ' ';
		          }
           }

base[glRow][glCol] = 'G';

  for(i=3;i<20;i++)/*assiging the blocks which are given by default from the input file*/
          {
	          base[fileData[i][0]][fileData[i][1]] = 'X';
           }


/*inserting the initial position of player to end of the linked list(row and column in order )*/
insertLast(list, plRow);
insertLast(list, plCol);


remRed=1;/*disable the red background for the block value present at this stage since no player movement yet*/
printScreen(row, col, base, plRow, plCol,glRow,glCol,blockRow, blockCol, remRed);
remRed=0;/*enable red background*/

/*Checking losing conditions in each user command */
/*Exits if player/goal is surrounded with 'X' block, border characters '*'  or if the player reaches goal*/
while((lose !=1) && (gLose !=1) && (goal !=1))
{
	/*To access user input directly without the 'Enter' key */
	disableBuffer();

	scanf("%c", &command);

	enableBuffer();

 /*clears previous position of the player*/
	 base[plRow][plCol] = ' ';

switch(command)
      {
           
        case ('w') :
				    /*Checks whether the new location player supposed to move, is blocked with a 'X' or '*' */
					lockRes = searchLock(base, (plRow-1), plCol);
					/*lockRes =0 means that new location is not blocked*/
				    if(lockRes ==0)
					{  /*change the player row by 1 to print in the upper row*/
                       plRow--;
					  loc= blocks(base, row, col, plRow, plCol, glRow, glCol, loca); /*blocks are generated only if the layer is moved*/
  
                      /*obtaining the most recent block location to be passed to print method and to store in the linked list*/
					  blockRow = loc[0];
                       blockCol= loc[1];
                      /*inserting the new player location to the list containing player locations*/
					   insertLast(list, plRow);
                       insertLast(list, plCol);
					  
                      /*inserting the new block location to the list containing block locations*/
					   insertLast(blockList, blockRow);
					    insertLast(blockList, blockCol);

					   	printScreen(row, col, base, plRow, plCol, glRow, glCol,blockRow, blockCol, remRed);
					}

					 count=0;
			
					 break;

	    case ('s') :
				    /*Checks whether the new location player supposed to move, is blocked with a 'X' or '*' */
						  lockRes = searchLock(base, (plRow+1), plCol);
		                  if(lockRes ==0)
					              {  /*change the player row by 1 to print in the Lower row*/
                         	          plRow++;
									 loc= blocks(base, row, col, plRow, plCol, glRow, glCol, loca); /*blocks are generated only if the layer is moved*/
                
				        /*obtaining the most recent block location to be passed to print method and to store in the linked list*/
						blockRow = loc[0];
                       blockCol= loc[1];

                      /*inserting the new block location to the list containing block locations*/
					   insertLast(blockList, blockRow);
					    insertLast(blockList, blockCol);
					  
                        /*inserting the new player location to the list containing player locations*/
					   insertLast(list, plRow);
					   insertLast(list, plCol);

					   					 printScreen(row, col, base, plRow, plCol, glRow, glCol,blockRow, blockCol, remRed);

					              }
                     
					  count=0;
				
					 break;					
										
	     case ('a') :
				            /*Checks whether the new location player supposed to move, is blocked with a 'X' or '*' */
						       lockRes = searchLock(base, plRow, (plCol-1));

		                        if(lockRes ==0)
					            {   /*change the player column by 1 to print in the new column*/
                                     plCol--;
									loc= blocks(base, row, col, plRow, plCol, glRow, glCol, loca); /*blocks are generated only if the layer is moved*/

                    /*obtaining the most recent block location to be passed to print method and to store in the linked list*/
					   blockRow = loc[0];
                       blockCol= loc[1];

                      /*inserting the new block location to the list containing block locations*/

					   insertLast(blockList, blockRow);
					    insertLast(blockList, blockCol);

                      /*inserting the new player location to the list containing player locations*/
					   insertLast(list, plRow);
					   insertLast(list, plCol);
					    printScreen(row, col, base, plRow, plCol, glRow, glCol,blockRow, blockCol, remRed);
								}
                     
					
					  count=0;
				
					 break;					
											
						
	        case ('d') :
						lockRes = searchLock(base, plRow, (plCol+1));
	                        if(lockRes ==0)
					                {	  /*change the player column by 1 to print in the new column*/
									    	 plCol++;
											loc= blocks(base, row, col, plRow, plCol, glRow, glCol, loca); /*blocks are generated only if the layer is moved*/

							   /*obtaining the most recent block location to be passed to print method and to store in the linked list*/
							  blockRow = loc[0];
                              blockCol= loc[1];

                      /*inserting the new block location to the list containing block locations*/
							  insertLast(blockList, blockRow);
					          insertLast(blockList, blockCol);

							  
                      /*inserting the new player location to the list containing player locations*/
							  insertLast(list, plRow);
							  insertLast(list, plCol);

							   printScreen(row, col, base, plRow, plCol, glRow, glCol,blockRow, blockCol, remRed);
									}							  
                              
							   count=0;
							   
							   
							  break;	

			case ('u') :

		                     	if((list-> count) >2)/*if the list of player locations contain more than one location only
			                                   (since initial position of the player should never be cleared)*/
		                             		{
			                                    count++;/*counts the number of times undo function has been used */
			                                   if((count == 1) && ((blockList-> count) !=2))/*only executed in the first undo move in a set of undo moves*/
			                                               {
			                                                  	removeLast(list);/*removes the final location of the player(since we do not need the currant position fopr undo function)*/
			                                                    removeLast(list);

			                                                   	plCol = peekLast(list);/*peek the previous location and assign it as the new location of player */
			                                                	plRow = peekBeforeLast(list);

				                                                 blockCol = removeLast(blockList);/*remove the location of most recent block and*/
				                                                blockRow = removeLast(blockList);  /*assign a empty character to the relevent index*/
				
			                                                    	base[blockRow][blockCol] = ' ';

			                                                 	blockCol = peekLast(blockList);/*peek the location of previous block to be printed with a red backgound by passing to the print method*/
			                                                	blockRow = peekBeforeLast(blockList);



			                                                	printScreen(row, col, base, plRow , plCol, glRow, glCol, blockRow, blockCol, remRed);

			                                             }else if(((blockList-> count) ==2))/*if the linked list of block locations contain only one location(row number and a column number)*/
			                                                    {/*when the final movement is to be undone*/
			                                                     	remRed=1;
			                                                    	removeLast(list);/*remove the most recent player movement(current)*/
			                                                    	removeLast(list);

			                                                    	plCol = peekLast(list);/*assign the initial position of the player(in the start of the game)*/
		                                                    	    plRow = peekBeforeLast(list);


                                                                 /*remove the final block and remove it from the game interface*/
			                                                      	blockCol = removeLast(blockList);
			                                                    	blockRow = removeLast(blockList);

			                                                     	base[blockRow][blockCol] = ' ';

				

			                                                      	printScreen(row, col, base, plRow , plCol, glRow, glCol, blockRow, blockCol, remRed);
			                                                     	remRed=0;/*set the background to re again*/
			                                                    	 count =0;

				
				
			                                                    }
			                                           else if((count >1) && (blockList-> count !=0))/*if it's not the start or end of a set of undo moves*/
                                                                {		
					
				                                                      blockCol = peekLast(blockList);/*peek the final block locaton  and assign an empty character for it*/
				                                                      blockRow = peekBeforeLast(blockList);
					                                                	 base[blockRow][blockCol] = ' ';

	                                                                  removeLast(list);/*remove the final location of player(current position)*/
					                                            	  removeLast(list);
						   

						                                              plCol = peekLast(list);/*peek the previous location of player*/
			                                                          plRow = peekBeforeLast(list);

						                                             blockCol = removeLast(blockList);
				                                                     blockRow = removeLast(blockList);

						                                              blockCol = peekLast(blockList);/*peek the final location of block(without removing)*/
			                                                        	blockRow = peekBeforeLast(blockList);

							                                        	printScreen(row, col, base, plRow , plCol, glRow, glCol, blockRow, blockCol, remRed);
							                                        	remRed=0;
			

								
                                                                 }
				                             }else/*user reaches the end of undo movement*/
				                                    {
				                                            remRed=1;
				                                            printScreen(row, col, base, plRow , plCol, glRow, glCol, blockRow, blockCol, remRed);
                                                            printf("\n      No more reverse moves possible!\nyou've reached the starting point of the game...\n");
				                                            remRed=0;
						
				                                    }
							
				            break;


	  }

							
						/*  printf("Blist count : %d\n count : %d\n",( blockList-> count), count);
						 printf("Plist count : %d\n",( list-> count));

							 printf("\nBlocks :");
							printLinkedlist(blockList);

						printf("\nplayer :");

						printLinkedlist(list);*/

					        goal = reachGoal(plRow, plCol , glRow, glCol); 
							/*reachGoal() returns 1 only if after checking whether the new location of player = location of goal*/

	                        lose =checkLock(base, plRow, plCol);
							/*checkLock() returns 1 only after checking whether the new location of player is surrounded with 'X' or '*' */

							gLose =checkLock(base, glRow, glCol);
							/*checkLock() returns 1 only after checking whether the location of Goal is surrounded with 'X' or '*' */


                                 if(goal ==1)/*reached goal*/
								  {
											    
                                                printf("\nCongratulations! \n\n You won!\n\n");

								  }else if(lose ==1)/*Player is surrounded*/
								  {
                                        printf("\nNo more moves possible! \n\n game over!\n\n");

								  }else if(gLose ==1)/*Goal is surrounded*/
								  {
									 printf("\n Unable to reach goal! \n\n All paths to reach the goal are blocked!\n\n game over!\n\n");

								  }	
	 
/*Checks whether each command is valid and pop's a warning if not*/
	   if((command != 'w') && (command != 's') && (command != 'a') && (command != 'd') && (command != 'u'))
	   {
		         remRed=1;
		       printScreen(row, col, base, plRow , plCol, glRow, glCol, blockRow, blockCol, remRed);
			   remRed=0;
			     printf("\n    Invalid kay! Please enter one of the keys mentioned above");	
	           printf("\n\nalert : Caps Lock might be on! (only lower case values are accepted)\n");
	   }
	}

   /*frees all allocated memory via malloc(each row of the array)*/
	
		   freeList(blockList);
		   freeList(list);
		   i=0;

		   	for (i = 0; i < row; i++)

           {
	              free(base[i]);

           }
		   free(base);

		   
	

	
}
















