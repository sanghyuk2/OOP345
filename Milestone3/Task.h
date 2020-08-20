/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 12/03/2018
**********************************************************/
#pragma once
#include <iostream>
#include <deque>
#include "Item.h"
#include "CustomerOrder.h"


class Task : public Item
{
	std::deque<CustomerOrder> Orders;				//Current orders at this station

	Task* pNextTask = nullptr;								//Reference to the next task

public:
	Task(std::string&);								//Constructor

	Task(Task&) = delete;
	Task& operator=(Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;

	void RunProcess(std::ostream&);	//runs a single cycle of the assembly line for the given Task.   If there are CustomerOrders in the queue, it will verify the fill status of the last CustomerOrder and fill it if the order contains the Item specified by the current Task.
	bool MoveTask(); //moves the last CustomerOrder in the queue to the next task on the assembly line if the orders fill state for the current Item is true.  Otherwise, the CustomerOrder should remain in the queue for the next processing cycle.   If the queue is empty, return false.
	void setNextTask(Task& task); //stores the provided Task objects reference into the pNextTask pointer.
	bool getCompleted(CustomerOrder& src); //Removes the last CustomerOrder from the queue, places it in src and returns true.   If the CustomerOrder queue is empty, return false.
	void Validate(std::ostream& os); //writes the name of the Item this Task is responsible for to os.   If pNextTask exists, writes the name of the next task on the assembly line.

	Task& operator+=(CustomerOrder&& newOrder);	//Move a CustomerOrder into the orders queue

};