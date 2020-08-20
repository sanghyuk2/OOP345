/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/24/2018
**********************************************************/
#include "Notifications.h"

namespace w5 {

	Notifications::Notifications() {
	}

	// copy constructor 
	Notifications::Notifications(const Notifications& obj) {
		*this = obj;
	}

	// copy assignment operator
	Notifications& Notifications::operator=(const Notifications& obj) {
		if (this != &obj) {
			for (int i = 0; i < 10; i++) {
				messageArray[i] = obj.messageArray[i];
			}
		}
		return *this;
	}

	// move constructor
	Notifications::Notifications(Notifications&& obj) {
		*this = std::move(obj);
	}

	// move assignment operator
	Notifications& Notifications::operator=(Notifications&& obj) {
		if (this != &obj) {
			for (int i = 0; i < 10; i++) {
				messageArray[i] = obj.messageArray[i];
			}
		}
		return *this;
	}

	Notifications::~Notifications() {
	}

	void Notifications::operator+=(const Message& msg) {
		messageArray[size] = msg;
		size++;
	}

	void Notifications::display(std::ostream& os) const {
		for (int i = 0; i < 10; i++) {
			messageArray[i].display(os);
		}
	}
}