/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/3/2018
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "CString.h"

namespace w1 {
	CString::CString(const char *pString) {
		if (pString == nullptr) { //if the pString is null pointer, which means it does not point anything, then initialize the string value as null character.
			m_string[0] = '\0';
		}
		else {
			strncpy(m_string, pString, MAX); //otherwise, copy the MAX characters of string to instance varaibles in class.
			m_string[MAX] = '\0'; //initialize the last character of instance variable as null character. The reason why of this is because strncpy copy null character as well.
		}
	}

	void CString::display(std::ostream& os) const { //by using the os object, display the m_string
		os << m_string;
	}

	std::ostream& operator<<(std::ostream& os, const CString& str) {
		str.display(os);
		return os;
	}
}