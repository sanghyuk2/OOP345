/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/20/2018
**********************************************************/
#ifndef W7_PRODUCT_H
#define W7_PRODUCT_H

#include "iProduct.h"

namespace w7 {

	class Product : public iProduct {
		int m_pNum;
		double m_pCost;
	public:
		Product(int Num = 0, double Price = 0);
		virtual double getPrice() const;
		virtual void display(std::ostream&) const;
	};
}
#endif // !W7_PRODUCT_H

