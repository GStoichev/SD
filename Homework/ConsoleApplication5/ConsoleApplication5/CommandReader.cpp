#include"stdafx.h"
#include "CommandReader.h"

CommandReader::CommandReader()
{
	this->listen = false;
}
void CommandReader::listenForCommands()
{
	this->listen = true;

	char directory[1024];
	char copyDirectory[1024];
	bool restore = false;
	while (listen)
	{
		std::cin >> directory;
		if (!strcmp(directory,"stop"))
		{
			this->stopListener();
			return;
		}
		if (!strcmp(directory,"-restore"))
		{
			restore = true;
			std::cin >> directory;
		}
		std::cin >> copyDirectory;
		if (restore)
		{
			this->restore();
		}
		else
		{
			this->createBackup(directory, copyDirectory);
		}
	}
}
void CommandReader::stopListener()
{
	this->listen = false;
}
void CommandReader::createBackup(const char* directory, const char* copyDirectory)
{
	Backup backup(directory, copyDirectory);
	backup.synchronize();
}
void CommandReader::restore()
{

}