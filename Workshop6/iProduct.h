/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 11/20/2018
**********************************************************/
#ifndef W7_IPRODUCT_H_
#define W7_IPRODUCT_H_

#include <iostream>
#include <fstream>
#include <string>

namespace w7 {

	class iProduct {
	public:
		virtual double getPrice() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);

}
#endif

