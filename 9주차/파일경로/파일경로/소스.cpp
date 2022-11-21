#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char filepath[200] = "C:\\Document\\Githhub\\Test1\\test1.txt";
	char* pfilepath = filepath;
	char* pSplitfilepath[200] = { NULL, };

	char* split = strtok(pfilepath, "\\");
	char* ext_split[200] = {NULL, };
	char ext[200];
	int nCounter = 0;
	int nCounter1 = 0;

	char newfilename[200] = "C:\\Document\\Githhub\\Test1\\test2.txt";

	while (split != NULL)
	{
		pSplitfilepath[nCounter] = split;
		nCounter++;
		split = strtok(NULL, "\\");
	}
	printf("file path : ");
	
	for (i = 0; i < nCounter-1; i++)
	{
		printf("%s\\",pSplitfilepath[i]);
	}

	printf("%s\n", pSplitfilepath[nCounter-1]);

	split = strtok(pSplitfilepath[nCounter - 1], ".");

	while (split != NULL)
	{
		ext_split[nCounter1] = split;
		nCounter1++;
		split = strtok(NULL, ".");
	}

	printf("file name : %s\n", ext_split[0]);
	printf("extention name : %s\n", ext_split[1]);

	if (rename(filepath, newfilename) == 0)
	{
		printf("Change file name %s", newfilename);
	}
	else
	{
		printf("Change file name % s", newfilename);
	}

	return 0;
}

