/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/14/2018
**********************************************************/
#include <iostream>
#include <fstream>
#include "Grades.h"
#include "Letter.h"

using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	auto letter = [](double grade) -> const char* {
		grade = round(grade);

		return  grade >= 90 ? GradeReturn(Letter::Ap) :			
			grade >= 80 ? GradeReturn(Letter::A) :
			grade >= 75 ? GradeReturn(Letter::Bp) :
			grade >= 70 ? GradeReturn(Letter::B) :
			grade >= 65 ? GradeReturn(Letter::Cp) :
			grade >= 60 ? GradeReturn(Letter::C) :
			grade >= 55 ? GradeReturn(Letter::Dp) :
			grade >= 50 ? GradeReturn(Letter::D) :
			GradeReturn(Letter::F);
	};

	try {
		Grades grades(argv[1]);
		grades.displayGrades(std::cout, letter);
	}
	catch (const char* err) {
		std::cerr << std::endl << "*** ERROR! ***" << std::endl						

			<< "File \"" << err << "\" cannt be read or does not exist"
			<< std::endl;
		return 3;
	}
	// end of student portion

	return 0;
}