/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/3/2018
**********************************************************/
#ifndef W1_CSTRING_H__
#define W1_CSTRING_H__
#include <iostream>

extern int STORED;

namespace w1 {
	#define MAX 3 //decide the MAX characters that we can accept 
	class CString {
		char m_string[20];
	public:
		CString(const char *pString = nullptr);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const CString& str);
}

#endif