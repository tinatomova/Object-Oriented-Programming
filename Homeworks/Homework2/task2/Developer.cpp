#include "Developer.hpp"
#include "TeamLead.hpp"
Developer::Developer(const string& name)
{
	this->name = name;
	salary = 0;
	lead = nullptr;
}

Developer::Developer(const string& name, double salary)
{
	this->name = name;
	this->salary = salary;
	lead = nullptr;
}

string Developer::getName() const
{
	return name;
}

double Developer::getSalary() const
{
	return salary;
}

TeamLead* Developer::getTeamLead() const
{
	return lead;
}

void Developer::setInitialSalary(double amount)
{
	if (salary == 0) {
		salary = amount;
	}
}

void Developer::sendLeavingRequest()
{
	if (lead != nullptr) {
		LeavingRequest lr(name);
		lead->addLeavingRequest(lr);
	}
}

void Developer::sendPromotionRequest(double amount)
{
	if (lead != nullptr) {
		PromotionRequest pr(name,amount);
		lead->addPromotionRequest(pr);
	}
}

void Developer::setLead(TeamLead* l)
{
	lead = l;
}

void Developer::increaseSalary(double amount)
{
	salary += amount;
}

void Developer::decreaseSalary(double amount)
{
	salary -= amount;
}

