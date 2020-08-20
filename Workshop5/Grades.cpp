/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/14/2018
**********************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include "Grades.h"

using namespace sict;

Grades::Grades(const char* fileName) {
	count = 0;

	if (fileName) { // check for nullptr
		std::ifstream fin(fileName); // open file
		if (fin.fail()) {// check if file exists
			file = nullptr;
			m_Num = nullptr;
			m_Grade = nullptr;
			throw fileName; // throw error
		}

		file = new char[strlen(fileName) + 1]; // create array dynamically and copy filename
		strcpy(file, fileName);

		char line[40]; // count line number
		while (!fin.eof()) {
			fin.getline(line, 40);
			if (strlen(line) > 1) 
				++count;
		}

		fin.clear(); // go back to start of file
		fin.seekg(0, fin.beg);

		m_Num = new unsigned int[count]; // create array dynamically
		m_Grade = new double[count];

		for (size_t i = 0; i < count; ++i) // copy contents of file into array
			if (fin.peek() != '\n' || fin.peek() != '\r') { // account for blank lines
				fin >> m_Num[i] >> m_Grade[i];
			}
			else {
				fin.ignore();
			}

		fin.close();
	}
}

Grades::~Grades() {
	delete[] file;
	delete[] m_Num;
	delete[] m_Grade;
}