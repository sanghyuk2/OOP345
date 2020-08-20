/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 12/03/2018
**********************************************************/
#pragma once
#include <iostream>
#include <deque>
#include <fstream>
#include <vector>
#include "CustomerOrder.h"
#include "Task.h"

class LineManager
{
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;		//Queue of Customer Orders to be filled
	std::deque<CustomerOrder> Completed;		//Queue of Customer Orders completed
	unsigned int CustomerOrder_Count;			//The number of customer orders the process started with

public:
	LineManager(std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);

	bool Run(std::ostream& os);
};