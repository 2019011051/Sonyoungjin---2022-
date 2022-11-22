#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//varation declare
	int i;
	char filepath[200] = "C:\\Document\\Githhub\\Test1\\test1.txt";
	char* pfilepath = filepath;
	char* pSplitfilepath[200] = { NULL, };

	char* split = strtok(pfilepath, "\\");   //Cut path files using strtok function
	char* ext_split[200] = {NULL, };
	char ext[200];           
	int nCounter = 0;    
	int nCounter1 = 0;

	char newfilename[200] = "C:\\Document\\Githhub\\Test1\\test2.txt";    //File path to be changed

	while (split != NULL)        //If split is not a NULL point,
	{
		pSplitfilepath[nCounter] = split;               
		nCounter++;
		split = strtok(NULL, "\\");     //Cut WW part
	}
	printf("file path : ");     
	
	for (i = 0; i < nCounter-1; i++)              //Outputs the path functions entered using the strtok function
	{
		printf("%s\\",pSplitfilepath[i]);
	}

	printf("%s\n", pSplitfilepath[nCounter-1]);

	split = strtok(pSplitfilepath[nCounter - 1], ".");   


	while (split != NULL)         //If it's not NULL,
	{
		ext_split[nCounter1] = split;       // Extract the file name.
		nCounter1++;
		split = strtok(NULL, ".");     
	}

	printf("file name : %s\n", ext_split[0]);     
	printf("extention name : %s\n", ext_split[1]);

	//rename : Rename the file and directory.
	if (rename(filepath, newfilename) == 0)    //If filepath and newfilename are the same,
	{
		printf("Change file name %s", newfilename);
	}
	else
	{
		printf("Change file name % s", newfilename);
	}

	return 0;
}

