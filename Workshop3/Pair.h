/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 10/24/2018
**********************************************************/
#ifndef _PAIR_H
#define _PAIR_H

template <typename A, typename B>

class Pair {
	A m_A;
	B m_B;

public:
//default constructor – adopts a safe empty state
	Pair() : m_A{}, m_B{} {}

//overloaded constructor that sets the key - value pair elements of the class
	Pair(const A& a, const B& b) : m_A{ a }, m_B{ b }{}

//returns a read - only version of the stored key information
	const A& getKey() const {
		return m_A;
	}

//returns a read - only version of the stored value information
	const B& getValue() const {
		return m_B;
	}

};

#endif 
