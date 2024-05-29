#include <stdio.h>
#include "goal.h"
/*
 METHOD: reachGoal
 PURPOSE: To return whether the player has reached the goal.
 IMPORTS: Arguments for location of player, goal,
 EXPORTS: whether player reached goal
 */
/*Checks whether the player has reached the goal after each command user gives */
int reachGoal(int newRow, int newCol,int goalRow, int goalCol)
{
	int result =0;
/*checks whether the new row and column of the player is equal to the row and column of the goal*/
	if((newRow == goalRow) && (newCol == goalCol))
	{
		result =1;
		
	}
	/*Returns '0' if new position of player is not equal to goal's location */
	return result;
}
