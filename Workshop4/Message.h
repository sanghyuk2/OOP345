/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/24/2018
**********************************************************/
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>
#include <fstream>

namespace w5 {
	class Message {
		std::string m_user;
		std::string m_reply;
		std::string m_msg;
	public:
		Message();
		//constructor retrieves a record from the in file object, parses the record (as described above) and stores its components in the Message object.  c is the character that delimits each record
		Message(std::ifstream& in, char c);
		//returns true if the object is in a safe empty state
		bool empty() const;
		//displays the Message objects within the container
		void display(std::ostream&) const;
	};
}
#endif // !MESSAGE_H
