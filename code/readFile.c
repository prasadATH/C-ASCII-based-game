#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"

/*
 NAME: Thilina Athukorala 
 PURPOSE: To extract the data in the file (contained in the file name passed from the main).
 IMPORTS: file name provided by the user(from the main)
 EXPORTS: returns the pointer containing the locations of P/G/X's and borders
 */
 

int** readFile(char* fileN)
{
    int count=0;/*to keep track of the element read after splitting each line*/
    int row=0;/*variable to store the first element of each line of the file which is the row coordinate*/
    int col=0;/*variable to store the first element of each line of the file which is the column coordinate*/

    int n=0;/*variable to iterate over each character of a line*/
    int i=0;/*variable to iterate over the array storing locations of P/G/X and borders*/
    int j=0;
    int marked=0;/*variable to check whether P/G/X is found in a line to omit them and extract the boder sizes*/
    int Xcount=3; /*variable to count ther number of X cordinates stores to print x intially on the game interface*/

       char line[25] = " ";/*variable to store each line when  the file is read*/
    char *ptr;/*Pointer to store each element of a splitted line*/
    int** locations = 0;/*pointer to store all the locations of P/G/X's and borders*/

      FILE* poitr = fopen(fileN, "r"); /*pointer for filereader*/
      
 
   

     locations=(int**)malloc(20 * sizeof(int*));/*allocating the pointer with dinamic memory */
/*Converting to a malloc 2D array by pointing each malloc row to store the lines read*/
	  for (i = 0; i < 20; i++)

           {
                  
	              locations[i] = (int*)malloc(2 * sizeof(int));
                  

           }
           /*initialize the malloc 2d array to store values*/
            for (i = 0; i < 20; i++)
           {        
            for (j = 0; j < 2; j++)
            {
                 locations[i][j]=0;
            }
           }


      
 
    if (NULL == poitr) {/*handling the exceptions in file reading*/
        
        return 0;
    }
 
   

       while (fgets(line, sizeof(line), poitr)!= NULL)/*reading lines of the file*/
        { count =0;/*element number is reset after reading each line*/
           marked =0; 
	
	

	 ptr = strtok(line, " ");/*tokenizing the line using spaces*/

    

	while(ptr != NULL)/*while line contains some information to be read*/
	{

         if(count == 0)/*if the pointer is pointing the first element in the line*/
        {
            row=atoi(ptr);/*converting the pointer of first element to an integer and saving it into a integer variable*/

        
        }else if(count == 1)/*if the pointer is pointing the second element in the line*/
        {   marked=0;
            col=atoi(ptr); /*converting the pointer of second element to an integer and saving it into a integer variable*/

            for(n=0;n<25;n++)
             {

                if(line[n] == 'P')/*if the line read contains character 'P' then the saved values will
                                     be assigned as the coordinates of the player and stored in the array*/
                {
                     locations[1][0] = row;
                     locations[1][1] = col;
                    marked =1;
                              
                }else if(line[n] == 'G')/*if the line read contains character 'G' then the saved values will
                                     be assigned as the coordinates of the goal and stored in the array*/
                {
                    locations[2][0] = row;
                    locations[2][1] = col;
                    marked =1;
                }else if(line[n] == 'X')/*if the line read contains character 'X' then the saved values will
                                     be assigned as the coordinates of the Blocks and stored in the array*/
                {
                    locations[Xcount][0] = row;
                    locations[Xcount][1] = col;
                    Xcount++;/*Number of blocks increased*/
                    marked =1;
                }

             }

    /*if the line read do not contain characters X/P/G then marked will be "0" then the saved values will
         be assigned as the values of Boders and stored in the array*/
     if(marked ==0)  
        {
            
            
            locations[0][0] = row;
            locations[0][1] = col;
            

        }

        }
        
        count++;
		ptr = strtok(NULL, " ");/*pointer is cleared to be used for next line*/
	}
 

        }
        fclose(poitr);/*closing the file reader*/


	return locations;/*returning the array pointer containing all the locations extracted from the file*/
}



