#include "stdafx.h"
#include "Backup.h"

const char* Backup::dataFile = "dataFile.bin";
//Constructors
Backup::Backup()
{
	this->directory = nullptr;
	this->copyDirectory = nullptr;
}
Backup::Backup(const char* directory, const char* copyDirectory)
{
	//maybe without this
	this->directory = nullptr;
	this->copyDirectory = nullptr;
	
	this->load(directory, copyDirectory);
}
//Methods
void Backup::synchronize()
{
	if (this->copyDirectory == nullptr || this->directory == nullptr)
	{
		std::cout << "directories didn't load" << std::endl;
		return;
	}
	std::vector<Pair> records;
	std::string dataFile;
	dataFile = this->copyDirectory;
	dataFile.append(this->dataFile);
	getAllDir(records);
	if (this->fileExist(dataFile))
	{
		std::vector<Pair> recordsDataFile;
		if (!this->readingDataFile(dataFile, recordsDataFile))
		{
			std::cout << "can't read dataFile" << std::endl;
			return;
		}
		if (this->compareRecords(records,recordsDataFile))
		{
			this->creatingDataFile(dataFile, records);
		}
	}
	else
	{
		for (size_t i = 0; i < records.size(); i++)
		{
			if (!strcmp(records[i].getHash(),"Folder"))
			{
				std::string str;
				str.append(this->copyDirectory);
				str.append(records[i].getPath());
				_mkdir(str.data());
				std::cout << "Creating Folder : " << str;
			}
			else
			{
				this->copyFile(records[i].getPath());
			}
			std::cout << " (" << i << '\\' << records.size() -1 << ")" << std::endl;
		}
		if (!this->creatingDataFile(dataFile, records))
		{
			std::cout << "Error dataFile cann't be created" << std::endl;
			return;
		}
	}
	
}
void Backup::restore()
{
	std::string dataFile;
	dataFile = this->copyDirectory;
	dataFile.append(this->dataFile);
	std::vector<Pair> records;
	std::vector<Pair> recordsDataFile;
	getAllDir(records);
	std::string str;
	for (size_t i = 0; i < records.size(); i++)
	{
		str.append(this->directory);
		str.append(records[i].getPath());
		remove(str.data());
		str.clear();
		std::cout << "Deleting : " << this->directory << records[i].getPath();
		std::cout << " (" << i << '\\' << records.size() -1 << ")" << std::endl;
	}
	readingDataFile(dataFile, recordsDataFile);
	for (size_t i = 0; i < recordsDataFile.size(); i++)
	{
		if (!strcmp(recordsDataFile[i].getHash(), "Folder"))
		{
			std::string str;
			str.append(this->directory);
			str.append(recordsDataFile[i].getPath());
			_mkdir(str.data());
		}
		else
		{
			this->restoreFile(recordsDataFile[i].getPath());
		}
		std::cout << "Recovering : " << this->directory << recordsDataFile[i].getPath();
		std::cout << " (" << i << '\\' << recordsDataFile.size() -1 << ")" << std::endl;
	
	}
}
void Backup::load(const char* directory, const char* copyDirectory)
{
	if (this->directory != nullptr)
	{
		delete[] this->directory;
	}
	if (this->copyDirectory != nullptr)
	{
		delete[] this->copyDirectory;
	}
	int length = 0;
	while (directory[length++] != '\0');
	this->directory = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		this->directory[i] = directory[i];
	}
	this->directory[length - 1] = '\\';
	this->directory[length] = '\0';
	length = 0;
	while (copyDirectory[length++] != '\0');
	this->copyDirectory = new char[length + 1];
	for (size_t i = 0; i < length - 1; i++)
	{
		this->copyDirectory[i] = copyDirectory[i];
	}
	this->copyDirectory[length - 1] = '\\';
	this->copyDirectory[length] = '\0';
}
//Private methods
bool Backup::readingDataFile(std::string dir, std::vector<Pair>& records)
{
	std::ifstream stream(dir, std::ios::in | std::ios::binary);
	if (!stream)
	{
		return false;
	}
	int sizePath = 0;
	int sizeHash = 0;
	char* path;
	char* hash;
	while (!stream.eof())
	{
		stream.read((char*)&sizePath, sizeof(sizePath));
		path = new char[sizePath];
		stream.read(path, sizePath);
		stream.read((char*)&sizeHash, sizeof(sizeHash));
		hash = new char[sizeHash];
		stream.read(hash, sizeHash);
		Pair record(path, hash);
		records.push_back(record);
		delete[] path;
		delete[] hash;
	}
	records.pop_back();
	stream.close();
	return true;
}
bool Backup::creatingDataFile(std::string dir, std::vector<Pair>& records)
{
	std::ofstream stream(dir, std::ios::out | std::ios::binary | std::ios::trunc);
	if (!stream)
	{
		std::cout << "Error" << dataFile << std::endl;
		return false;
	}
	for (size_t i = 0; i < records.size(); i++)
	{
		int sizePath = records[i].getSizePath();
		int sizeHash = records[i].getSizeHash();
		stream.write((char*)&sizePath, sizeof(sizePath));
		stream.write(records[i].getPath(), sizePath);
		stream.write((char*)&sizeHash, sizeof(sizeHash));
		stream.write(records[i].getHash(), sizeHash);
	}
	stream.close();
	return true;
}
void Backup::getAllDir(std::vector<Pair>& records)
{
	//std::cout << this->directory << std::endl;
	int length = 0;
	while (this->directory[length++]);
	length--;
	FILE* pipe = NULL;
	std::string pCmd = "dir /B /S " + std::string(this->directory);
	char buf[256];
	char temp[256];

	if (NULL == (pipe = _popen(pCmd.c_str(), "rt")))
	{
		std::cout << "Error at file reading" << std::endl;
		return;
	}
	MD5 md5;
	while (!feof(pipe))
	{
		if (fgets(buf, 256, pipe) != NULL)
		{
			int i = 0;
			while (buf[i] != '\0')
			{
				if (buf[i] == '\n')
				{
					break;
				}
				i++;
			}
			buf[i++] = '\0';
			struct stat s;
			if (stat(buf, &s) == 0)
			{
				int j = length;
				for (; j < i; j++)
				{
					temp[j - length] = buf[j];
				}
				temp[j] = '\0';
				if (s.st_mode & S_IFDIR)
				{
					Pair pair(temp, "Folder");
					records.push_back(pair);
					std::cout << "Hashing folder : " << temp << std::endl;
				}
				else if (s.st_mode & S_IFREG)
				{
					Pair pair(temp, md5.digestFile(buf));
					records.push_back(pair);
					std::cout << "Hashing file : " << temp << std::endl;
				}
				else
				{
					std::cout << "unreadable file" << std::endl;
				}
			}
			else
			{
				//error
			}
		}
	}
	_pclose(pipe);
}
void Backup::copyFile(const char* path)
{
	std::string str;
	str.append(this->directory);
	str.append(path);
	std::string strr;
	strr.append(this->copyDirectory);
	strr.append(path);
	std::ifstream ifs(str, std::ios::in | std::ios::binary);
	if (!ifs)
	{
		std::cout << "File " << str << " can't load!" << std::endl;
		return;
	}
	std::ofstream ofs(strr, std::ios::out | std::ios::binary | std::ios::trunc);
	if (!ofs)
	{
		std::cout << "File " << strr << " can't load!" << std::endl;
		return;
	}
	char buf[1];
	while (true)
	{
		ifs.read(buf, 1);
		if (ifs.eof())
		{
			break;
		}
		ofs.write(buf,1);
	}
	std::cout << "Backuping file : " << strr << std::endl;
	ifs.close();
	ofs.close();
}
void Backup::restoreFile(const char* path)
{
	std::string from;
	from.append(this->copyDirectory);
	from.append(path);
	std::string to;
	to.append(this->directory);
	to.append(path);
	std::ifstream ifs(from, std::ios::in | std::ios::binary);
	if (!ifs)
	{
		std::cout << "File " << from << " can't load!" << std::endl;
		return;
	}
	std::ofstream ofs(to, std::ios::out | std::ios::binary | std::ios::trunc);
	if (!ofs)
	{
		std::cout << "File " << to << " can't load!" << std::endl;
		return;
	}
	char buf[1];
	while (true)
	{
		ifs.read(buf, 1);
		if (ifs.eof())
		{
			break;
		}
		ofs.write(buf, 1);
	}
	std::cout << "Restoring " << from << std::endl;
	ifs.close();
	ofs.close();
}
bool Backup::fileExist(std::string str)
{
	std::ifstream f(str);
	return f.good();
}
bool Backup::compareRecords(std::vector<Pair>& records, std::vector<Pair>& recordsDataFile)
{
	bool madedchange = false;
	bool finded;
	bool* findedd = new bool[recordsDataFile.size()];
	for (size_t i = 0; i < recordsDataFile.size(); i++)
	{
		findedd[i] = false;
	}
	for (size_t i = 0; i < records.size(); i++)
	{
		finded = false;
		for (size_t j = 0; j < recordsDataFile.size(); j++)
		{
			if (!strcmp(records[i].getPath(), recordsDataFile[j].getPath()))
			{
				findedd[j] = true;
				finded = true;
				if (strcmp(records[i].getHash(), recordsDataFile[j].getHash()))
				{
					this->copyFile(records[i].getPath());
					madedchange = true;
				}
				break;
				
			}
			
		}
		std::cout << "Compare files : ";
		std::cout << " (" << i << '\\' << records.size() << ")" << std::endl;
		if (finded == false)
		{
			this->copyFile(records[i].getPath());
			madedchange = true;
		}
	}
	if (this->deleteRecords(findedd,recordsDataFile))
	{
		madedchange = true;
	}
	return madedchange;
}
bool Backup::deleteRecords(bool*& finded,std::vector<Pair>& recordsDataFile)
{
	bool change = false;
	for (size_t i = 0; i < recordsDataFile.size(); i++)
	{
		if (!finded[i])
		{
			std::string str;
			str.append(this->copyDirectory);
			str.append(recordsDataFile[i].getPath());
			if (remove(str.data()) != 0)
			{
				perror("Error deleting file");
			}
			else
			{
				change = true;
				std::cout << "File " << str << " successfully deleted" << std::endl;
			}
		}
	}
	return change;
}
//Destructor
Backup::~Backup()
{
	delete[] this->copyDirectory;
	delete[] this->directory;
}
