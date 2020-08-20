/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/3/2018
**********************************************************/
#include <iostream>
#include <fstream>
#include "process.h"

int STORED = 3;

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab1Output.txt");

	ofs << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		ofs << argv[i] << ' ';
	}

	if (argc < 2) {
		ofs << "\nInsufficient number of arguments\n";
		return 1;
	}

	/****
	TO DO:  Add code here that will print out the max characters stored
	by your CString object
	*****/

	ofs << "\nMaximum number of characters stored : " << STORED << std::endl;

	for (int i = 1; i < argc; i++) {
		process(argv[i], ofs);
	}

	int WaitKey;
	std::cin >> WaitKey;

	ofs.close();
	return 0;
}