#include "TextTransformer.h"


TextTransformer::TextTransformer(char* fileName, char* commandLineArguments)
{
	this->fileToTransform.open(fileName, std::fstream::in | std::fstream::out);
	size_t length = strlen(commandLineArguments + 1);
	this->commandLineArguments = new char[length];
	memcpy(this->commandLineArguments, commandLineArguments, length);
}


TextTransformer::~TextTransformer()
{
	this->fileToTransform.close();
	delete[] this->commandLineArguments;
}
