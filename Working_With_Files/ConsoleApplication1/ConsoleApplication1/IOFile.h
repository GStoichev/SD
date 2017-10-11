#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
class IOFile
{
public:
	IOFile();
	IOFile(const char* name);
	char* ReadFile() const;
	char* ReadFile(const char* name);
	void WriteInFile(const char* name, const char* text);
	void WriteInFile(const char* text);
	void TransferData(const char* to);
	void TransferData(const char* from, const char* to);
	~IOFile();

private:
	char* name;
};
