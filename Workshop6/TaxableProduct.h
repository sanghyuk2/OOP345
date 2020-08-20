/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/20/2018
**********************************************************/
#ifndef W7_TAXABLEPRODUCT_H
#define W7_TAXABLEPRODUCT_H

#include "Product.h"

static double rate[3] = { 0, 1.13, 1.08 };

namespace w7 {

	class TaxableProduct : public Product {
		enum tax { NONE, HST, PST };
		char taxStatus;
		int m_pNum;
		double m_pCost;
	public:
		TaxableProduct(char taxable = '\0', int num = 0, double price = 0.0);
		double getPrice() const;
		void display(std::ostream&) const;
	};
}

#endif // !W7_TAXABLEPRODUCT_H

