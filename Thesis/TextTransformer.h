#pragma once
#include <iostream>
#include <fstream>

class TextTransformer
{
public:
	TextTransformer(char* fileName, char* commandLineArguments);
	virtual ~TextTransformer();
private:
	std::fstream fileToTransform;
	char* commandLineArguments;
};

