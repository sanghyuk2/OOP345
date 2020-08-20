/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/3/2018
**********************************************************/
#include <iostream>
#include "CString.h"
#include "process.h"

int count = 0;
void process(const char* str, std::ostream& os) {
	w1::CString object(str); //make an object named 'object' of CString and stores the string into a instance vairable named 'm_string'.
	os << count++ << ": " << object << std::endl;

}