/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/24/2018
**********************************************************/
#ifndef _LIST_H
#define _LIST_H

#include <vector>

template<typename T, int N>

class List
{
	std::vector<T> m_List;

public:
// default constructor - adopts a safe empty state
	List() {
		m_List.reserve(N);      
	}

// returns the number of entries in the array
	size_t size() const {               
		return m_List.size();
	}

// overloaded operator that returns the requested array index
	const T& operator[](int index) const {   
		return m_List.at(index);
	}

// overloaded operator that adds an element to the array if space is available.
	void operator+=(const T& el) {            
		bool isSpace = (this->size() < N);
		if (isSpace)
			m_List.push_back(el);
	}
};

#endif // _LIST_H