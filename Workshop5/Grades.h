/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/14/2018
**********************************************************/
#include <iostream>
#include <iomanip>

#ifndef SICT_GRADES_H
#define SICT_GRADES_H

namespace sict {

	class Grades {
		char* file;
		unsigned int* m_Num;			
		double* m_Grade;
		size_t count;

	public:
		
		Grades(const char*); // constructor
		~Grades(); // destructor

		template <typename T>
		void displayGrades(std::ostream& os, T func) const {
			for (int i = 0; i < count; ++i) {
				std::cout << std::setw(10) << m_Num[i]
					<< std::setw(6) << std::fixed << std::setprecision(2)
					<< m_Grade[i] << " " << std::setw(4) << std::left
					<< func(m_Grade[i]) << std::setfill(' ') << std::right
					<< std::endl;
			}
		}
	};
} 

#endif //SICT_GRADES_H