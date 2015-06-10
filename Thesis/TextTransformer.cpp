#include "TextTransformer.h"


TextTransformer::TextTransformer(char* fileName, char* commandLineArguments)
{
	this->fileToTransform.open(fileName, std::fstream::in | std::fstream::out);
	if (!this->fileToTransform.is_open())
	{
		//Handle exception
	}

	if (commandLineArguments == NULL)
	{
		this->commandLineArguments = NULL;
		return;
	}
	size_t length = strlen(commandLineArguments + 1);
	this->commandLineArguments = new char[length];
	memcpy(this->commandLineArguments, commandLineArguments, length);
}

void TextTransformer::DoTransform()
{
	return;
}

TextTransformer::~TextTransformer()
{
	this->fileToTransform.close();
	delete[] this->commandLineArguments;
}
int TextTransformer::FindString(char* str)
{
	int pos = 0;
	bool found = false;

	size_t strLength = strlen(str);

	fileToTransform.seekg(0, fileToTransform.end);
	size_t fileEnd = fileToTransform.tellg();
	fileToTransform.seekg(0, fileToTransform.beg);
	
	char* buffer = new char[strLength];
	for (int i = 0; i < fileEnd - strLength; i++)
	{
		fileToTransform.read(buffer, strLength);
		if (strcmp(buffer, str) == 0)
		{
			found = true;
			break;
		}
		pos++;
	}

	delete[] buffer;

	if (found)
		return pos;
	else
		return -1;
}