/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/12/2018
**********************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"

namespace w2 {

	//Default Constructor initializing instance variables 
	Text::Text() {
		fileName = "";
		str = nullptr;
		n = 0;
	}

	//One argument construction which has File name as a parameter 
	Text::Text(const std::string Fname) {
		std::ifstream file;
		file.open(Fname);
		//If the file exist, then store the information
		if (file.good()) {
			std::string dummy;
			n = getFileLine(file);
			file.clear();
			file.seekg(0, std::ios::beg);
			str = new std::string[n];
			for (size_t i = 0; i < n; i++)
			{
				std::getline(file, str[i]);
			}
			fileName = Fname;
		}
		//if file does not open, set object to safe empty state
		else {
			fileName = "";
			str = nullptr;
			n = 0u;
		}
	}

	//Copy Constructor
	Text::Text(const Text &obj) {
		*this = obj;
	}

	//Move Constructor
	Text::Text(Text&& obj) {
		*this = std::move(obj);
	}

	//Copy assingment operator
	Text& Text::operator=(const Text& obj) {
		if (this != &obj) {
			fileName.assign(obj.fileName);
			n = obj.n;
			str = new std::string[n];
			for (size_t i = 0; i < n; i++)
			{
				str[i].assign(obj.str[i]);
			}
		}
		return *this;
	}

	//Move assignement operator
	Text& Text::operator=(Text&& obj) {
		if (this != &obj) {
			fileName = obj.fileName;
			str = obj.str;
			n = obj.n;
			obj.fileName = "";
			obj.str = nullptr;
			obj.n = 0u;
		}
		return *this;
	}

	//Destructor 
	Text::~Text() {
		delete[] str;
		str = nullptr;
	}

	//Return the number of lines.
	size_t Text::size() const {
		return n;
	}

	//Find out how many lines in the file opened by current object.
	int getFileLine(std::ifstream& Fname) {
		std::string temp;
		int NOLines = 0;
		while (!Fname.eof())
		{
			std::getline(Fname, temp);
			NOLines++;
		}
		return NOLines;
	}
}