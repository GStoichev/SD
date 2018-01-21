#pragma once
#include <fstream>
#include <sys/stat.h>
#include "Pair.h"
#include <string>
#include <vector>
#include <iostream>
#include "md5.h"
#include "Backup.h"
#include <direct.h>

class Backup
{
public:
	Backup();
	Backup(const char* directory, const char* copyDirectory);
	void synchronize();
	void restore();
	void load(const char* directory, const char* copyDirectory);
	~Backup();
private:
	bool fileExist(std::string str);
	void copyFile(const char* path);
	void restoreFile(const char* path);
	void getAllDir(std::vector<Pair>& records);
	char* directory;
	char* copyDirectory;
	bool creatingDataFile(std::string dir,std::vector<Pair>& records);
	bool readingDataFile(std::string dir, std::vector<Pair>& records);
	bool compareRecords(std::vector<Pair>& records, std::vector<Pair>& recordsDataFile);
	bool deleteRecords(bool*& finded, std::vector<Pair>& recordsDataFile);
	static const char* dataFile;
};
