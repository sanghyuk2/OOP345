/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 12/03/2018
**********************************************************/
#include "Task.h"

//Constructor
Task::Task(std::string& file) : Item::Item(file) {
	pNextTask = nullptr;
}

void Task::RunProcess(std::ostream& os) {
	size_t max = Orders.size();
	size_t count = 0;
	while (!Orders.empty() && count != max) {
		while (!(Orders.back().getItemFillState(this->getName()))) {
			Orders.back().fillItem(*this, os);
		}
		if (this->pNextTask != nullptr) {
			*this->pNextTask += std::move(Orders.back());
			Orders.pop_back();
		}
		count++;
	}
}

bool Task::MoveTask() {
	if (Orders.empty() == false) {
		if (Orders.back().getOrderFillState() == true) {
			pNextTask->Orders.push_back(std::move(Orders.back()));
			Orders.pop_back();
		}
	}
	else {
		return false;
	}
	return true;
}

void Task::setNextTask(Task& task) {
	pNextTask = &task;
}
bool Task::getCompleted(CustomerOrder &co) {
	if (Orders.empty()) return false;
	co = std::move(Orders.back());
	Orders.pop_back();
	return true;
}
void Task::Validate(std::ostream& os) {
	os << "Validate" << std::endl;
	os << this->getName() << std::endl;
	os << "Next:" << pNextTask->getName() << std::endl;
}

Task& Task::operator+=(CustomerOrder&& newOrder) {
	Orders.push_front(std::move(newOrder));
	return *this;
}