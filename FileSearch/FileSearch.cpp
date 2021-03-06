// FileSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <sys/stat.h>
#include <sstream>
#include <Windows.h>
#include <direct.h>
#include <Lmcons.h>

namespace fs = std::experimental::filesystem;

//creates stat struct
struct stat s;


int main()
{

	std::vector<std::string> files;

	//gets username 
	TCHAR userName[UNLEN + 1];
	DWORD size = UNLEN + 1;

	GetUserName((TCHAR*)userName, &size);

	std::string name;
	name = userName;

	//sets the keyword
	std::string keyword = "Hello.txt";
	//sets directory to search
	std::string path = "C:\\Users\\" + name + "\\Desktop";

	files.clear();

	int place = 0;

	for (fs::recursive_directory_iterator end, dir(path);
		dir != end; ++dir) {
		 //std::cout << *dir << "\n";  // full path
		//std::cout << dir->path().filename() << "\n"; // just last bit
		std::string tempname = dir->path().string();

		if (tempname.find(keyword) != std::string::npos) {
			files.push_back(tempname);
		}//end of if

	}//end of for

    return 0;
}

