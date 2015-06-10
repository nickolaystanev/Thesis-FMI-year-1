#pragma once
#include <iostream>
#include <fstream>

class TextTransformer
{
public:
	TextTransformer(char* fileName, char* commandLineArguments);
	virtual ~TextTransformer();
	void DoTransform();
	int FindString(char* str);
private:
	std::fstream fileToTransform;
	char* commandLineArguments;
};

