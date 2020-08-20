/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/24/2018
**********************************************************/
#include "Message.h"

namespace w5 {

	Message::Message() {
		m_user = "\0";
		m_reply = "\0";
		m_msg = "\0";
	}

	Message::Message(std::ifstream& in, char c) {
		std::string temp;
		std::getline(in, temp, c);

		//if a message is empty then make it safe empty state.
		if ((temp.find(" ") + 1) == 0) {
			m_user = "\0";
			m_reply = "\0";
			m_msg = "\0";
		}

		else {
			std::string sub;
			m_user = temp.substr(0, temp.find(" "));
			if ((temp.find("@") + 1) == 0) {
				sub = temp.substr(temp.find(" "));
				m_reply = "\0";
				m_msg = sub.substr(1);
			}
			else {
				sub = temp.substr(temp.find("@"));
				m_reply = sub.substr(1, sub.find(" "));
				m_msg = sub.substr(sub.find(" ") + 1);
			}
		}
	}

	bool Message::empty() const {
		return (m_msg == "\0" && m_user == "\0" && m_reply == "\0") ? true : false;
	}

	void Message::display(std::ostream& os) const {
		if (!empty()) {
			os << "Message" << std::endl;
			os << " User  : " << m_user << std::endl;
			if (m_reply != "\0") {
				os << " Reply : " << m_reply << std::endl;
			}
			os << " Tweet : " << m_msg << std::endl;
			os << std::endl;
		}
	}
}