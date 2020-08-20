/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/24/2018
**********************************************************/
#ifndef NOTIFICATION_H
#define NOTIFICATION_H 
#include <iostream>
#include "Message.h"

namespace w5 {
	class Notifications {
		Message messageArray[10];
		size_t size = 0;
	public:
		//default constructor - empty
		Notifications();
		//copy constructor
		Notifications(const Notifications&);
		//copy assignment operator
		Notifications& operator=(const Notifications&);
		//move constructor
		Notifications(Notifications&&);
		//move assignment operator
		Notifications& operator=(Notifications&&);
		//destructor
		~Notifications();
		//adds msg to the set
		void operator+=(const Message& msg);
		//inserts the Message objects to the os output stream
		void display(std::ostream& os) const;
	};
}

#endif
