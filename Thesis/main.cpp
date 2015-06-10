#include<iostream>
#include "TextTransformer.h"

char** ExtractCommands(char **allStrings, unsigned int &count, int allStringsCount, bool &html);
char** ExtractPaths(char **allStrings, unsigned int &count, int allStringsCount);
void FreeMemory(char** arr1, char** arr2, unsigned int size1, unsigned int size2);
void DoTransform(char* file, char* command);
char* ExtractCommandLineArguments(char* argument);

int main(int argc, char *argv[])
{
	bool html = false;
	unsigned int commandsCount = 0;
	unsigned int filesCount = 0;
	char** commands;
	char** files;

	commands = ExtractCommands(argv , commandsCount , argc , html);
	files = ExtractPaths(argv, filesCount, argc);

	for (int filesToTransform = 0; filesToTransform < filesCount; filesToTransform++)
	{
		for (int commandsToDo = 0; commandsToDo < commandsCount; commandsToDo++)
		{
			DoTransform(files[filesToTransform], commands[commandsToDo]);
		}
	}

	TextTransformer text("test.cpp", NULL);
	std::cout << text.FindString("TextTransformer");

	FreeMemory(commands, files, commandsCount, filesCount);
	return 0;
}

void DoTransform(char* file, char* command)
{
	char* cmdArgument = ExtractCommandLineArguments(command);
	if (strstr(command, "--comments") != NULL)
	{
		//TODO
		std::cout << "1";
	}
	if (strstr(command, "--newlines") != NULL)
	{
		//TODO
		std::cout << "2";
	}
	if (strstr(command, "--indentation") != NULL)
	{
		//TODO
		std::cout << "3";
	}
	if (strstr(command, "--format") != NULL)
	{
		//TODO
		std::cout << "4";
	}
	delete[] cmdArgument;
}

char* ExtractCommandLineArguments(char* argument)
{
	int pos = 0;
	char c = argument[0];
	char* temp;
	while (c != '\0')
	{
		if (c == '=')
		{
			pos++;
			temp = new char[strlen(argument) + 1 - pos];
			memcpy(temp, argument + pos, strlen(argument) + 1 - pos);
			return temp;
		}
		pos++;
		c = argument[pos];
	}
	return NULL;
}

char** ExtractPaths(char **allStrings, unsigned int &count, int allStringsCount)
{
	for (int i = 1; i < allStringsCount-1; i++)
	{
		allStrings[i];
		if (allStrings[i][0] == '-' && allStrings[i][1] == '-')
		{
			continue;
		}
		else
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

char** ExtractCommands(char **allStrings, unsigned int &count, int allStringsCount , bool &html)
{
	for (int i = 1; i < allStringsCount; i++)
	{
		if (allStrings[i][0] == '-' && allStrings[i][0] == '-')
		{
			count++;
			if (strcmp(allStrings[i], "--html"))
				html = true;
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

//TODO check for excepitons
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