#include<iostream>
#include "TextTransformer.h"

char** ExtractCommands(char **allStrings, unsigned int &count, int allStringsCount);
char** ExtractPaths(char **allStrings, unsigned int &count, int allStringsCount);
void FreeMemory(char** arr1, char** arr2, unsigned int size1, unsigned int size2);

int main(int argc, char *argv[])
{
	bool html = false;
	unsigned int commandsCount = 0;
	unsigned int filesCount = 0;
	char** commands;
	char** files;

	commands = ExtractCommands(argv , commandsCount , argc);
	files = ExtractPaths(argv, filesCount, argc);

	//FreeMemory(commands, files, commandsCount, filesCount);
	return 0;
}

char** ExtractPaths(char **allStrings, unsigned int &count, int allStringsCount)
{
	for (int i = 1; i < allStringsCount; i++)
	{
		if (allStrings[i][0] != '-' && allStrings[i][0] != '-')
		{
			count++;
		}
	}

	char** temp = new char*[count];
	int counter = 0;
	for (int i = 1; i < allStringsCount; i++)
	{
		if (allStrings[i][0] != '-' && allStrings[i][0] != '-')
		{
			temp[counter] = new char[strlen(allStrings[i]) + 1];
			memcpy(temp[counter], allStrings[i], strlen(allStrings[i]) + 1);
			counter++;
		}
	}

	return temp;
}

char** ExtractCommands(char **allStrings, unsigned int &count, int allStringsCount)
{
	for (int i = 1; i < allStringsCount; i++)
	{
		if (allStrings[i][0] == '-' && allStrings[i][0] == '-')
		{
			count++;
		}
	}

	char** temp = new char*[count];
	int counter = 0;
	for (int i = 1; i < allStringsCount; i++)
	{
		if (allStrings[i][0] == '-' && allStrings[i][0] == '-')
		{
			temp[counter] = new char[strlen(allStrings[i]) + 1];
			memcpy(temp[counter], allStrings[i], strlen(allStrings[i]) + 1);
			counter++;
		}
	}

	return temp;
}

void FreeMemory(char** arr1, char** arr2, unsigned int size1, unsigned int size2)
{
	for (int i = 0; i < size1; i++)
	{
		delete[] arr1[i];
	}
	delete[] arr1;
	for (int i = 0; i < size2; i++)
	{
		delete[] arr2[i];
	}
	delete[] arr2;
}