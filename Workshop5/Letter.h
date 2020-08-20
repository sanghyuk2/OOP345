/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/14/2018
**********************************************************/
#ifndef SICT_LETTER_H
#define SICT_LETTER_H

namespace sict {

	enum class Letter {			

		Ap,
		A,
		Bp,
		B,
		Cp,
		C,
		Dp,
		D,
		F
	}; 

	template<typename T>
	const char* GradeReturn(const T& Letter) {				

		switch (Letter) {
		case T::Ap: return "A+";
		case T::A: return "A";
		case T::Bp: return "B+";
		case T::B: return "B";
		case T::Cp: return "C+";
		case T::C: return "C";
		case T::Dp: return "D+";
		case T::D: return "D";
		case T::F: return "F";
		default: return "Invalid";
		}
	}

} 
#endif // SICT_LETTER_H