/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/20/2018
**********************************************************/
#include "Product.h"
#include <iomanip>

namespace w7 {

	Product::Product(int Num, double Price) {
		m_pNum = Num;
		m_pCost = Price;
	}

	double Product::getPrice() const {
		return m_pCost;
	}

	void Product::display(std::ostream& os) const {
		if (m_pNum != 0 && m_pCost != 0)
			os << m_pNum << std::setw(15) << m_pCost << std::endl;
	}

}