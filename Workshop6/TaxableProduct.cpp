/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/20/2018
**********************************************************/
#include "TaxableProduct.h"
#include <iomanip>

namespace w7 {

	TaxableProduct::TaxableProduct(char taxable, int Num, double Price) {
		taxStatus = taxable;
		m_pNum = Num;
		m_pCost = Price;
	}

	double TaxableProduct::getPrice() const {
		if (taxStatus == 'H') {
			return m_pCost * rate[tax::HST];
		}
		else if (taxStatus == 'P') {
			return m_pCost * rate[tax::PST];
		}
		else {
			return m_pCost * rate[tax::NONE];
		}
	}

	void TaxableProduct::display(std::ostream& os) const {
		if (m_pNum != 0) {
			if (taxStatus == 'H') {
				os << m_pNum << std::setw(15) << m_pCost << std::setw(10) << "HST" << std::endl;
			}
			if (taxStatus == 'P') {
				os << m_pNum << std::setw(15) << m_pCost << std::setw(10) << "PST" << std::endl;
			}
		}
	}
}