/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/20/2018
**********************************************************/
#pragma once
#include <string>
#include <fstream>

class Utilities {
	size_t field_width;           // maximum field width needed 
	static char delimiter;        // field delimiter character

public:
	Utilities();
	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string&, size_t&, bool&);
	static void setDelimiter(const char);
	const char getDelimiter() const;
};