#include <stdio.h>
#include <stdlib.h>
#include "lock.h"

/*
 Method: searchLock
 PURPOSE: To return whether the new location of player contains a block or the border.
 IMPORTS: Arguments for location of player, and the array containing all the game content
 EXPORTS: whether player can move further
 */
/*Checks whether the player can move to the location which user defined
 (whether it's a cross or the end of row/column in the new location  )*/
int searchLock(char** crossMap, int pInRow, int pInCol)
 {
	int res=0;

	/*checks whether new location contains a '*' ( end of row/column)*/
			  if(crossMap[pInRow][pInCol] == '*')
			               {
				             res=1;

			               }
						  /*checks whether new location contains a 'X' block*/
						  else if(crossMap[pInRow][pInCol] == 'X')
						   {

							res=2;
						   }

	

						  
						
		  
        return res;
 }


/*
 Method: checkLock
 PURPOSE: To return whether the player is blocked from around it.
 IMPORTS: Arguments for location of player, goal,
 EXPORTS: whether player locked from eithersides
 */
/*checks whether the location of player/goal is surrounded by 'X' and '*' which ends the game*/
 int checkLock(char** lockMap, int playRow, int playCol)
 {
	int los =0;
/*checking whether it's surrounded by 4 'X' blocks*/
	if((lockMap[playRow-1][playCol]=='X')&&(lockMap[playRow+1][playCol]=='X')
	       && (lockMap[playRow][playCol-1]=='X')&&(lockMap[playRow][playCol+1]=='X'))
	{
        los =1;
	}

	else if((lockMap[playRow-1][playCol]=='*')&&(lockMap[playRow+1][playCol]=='X') 
			    && (lockMap[playRow][playCol-1]=='*')&&(lockMap[playRow][playCol+1]=='X'))
	{
       los =1;
	}
	else if((lockMap[playRow-1][playCol]=='*')&&(lockMap[playRow+1][playCol]=='X')
				 && (lockMap[playRow][playCol-1]=='X')&&(lockMap[playRow][playCol+1]=='*'))
	{
       los =1;
	}
	else if((lockMap[playRow-1][playCol]=='X')&&(lockMap[playRow+1][playCol]=='*')
			    && (lockMap[playRow][playCol-1]=='*')&&(lockMap[playRow][playCol+1]=='X'))
	{
        los =1;
	}else if((lockMap[playRow-1][playCol]=='X')&&(lockMap[playRow+1][playCol]=='*')
			    && (lockMap[playRow][playCol-1]=='X')&&(lockMap[playRow][playCol+1]=='*'))
	{
        los =1;
	}else if((lockMap[playRow-1][playCol]=='*')&&(lockMap[playRow+1][playCol]=='X')
			    && (lockMap[playRow][playCol-1]=='X')&&(lockMap[playRow][playCol+1]=='X'))
	{
        los =1;
	}else if((lockMap[playRow-1][playCol]=='X')&&(lockMap[playRow+1][playCol]=='*')
				  && (lockMap[playRow][playCol-1]=='X')&&(lockMap[playRow][playCol+1]=='X'))
	{
        los =1;
	}else if((lockMap[playRow-1][playCol]=='X')&&(lockMap[playRow+1][playCol]=='X')
			   && (lockMap[playRow][playCol-1]=='*')&&(lockMap[playRow][playCol+1]=='X'))
	{
        los =1;

	}else if((lockMap[playRow-1][playCol]=='X')&& (lockMap[playRow+1][playCol]=='X')
			    && (lockMap[playRow][playCol-1]=='X')&&(lockMap[playRow][playCol+1]=='*'))
	{
        los =1;
	}


	
	
	return los;


 }
