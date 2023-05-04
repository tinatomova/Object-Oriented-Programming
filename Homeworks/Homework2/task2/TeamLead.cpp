#include "TeamLead.hpp"

TeamLead::TeamLead(const string& name, double salary) :Developer(name)
{
	this->salary = salary;
	lead = this;
}

vector<Developer*> TeamLead::getTeam() const
{
	return team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer != nullptr) {
		developer->setInitialSalary(salary);
		developer->setLead(this);
		team.push_back(developer);
	}
	
}

void TeamLead::removeDeveloperFromTeam(const string& name)
{
	for (int i = team.size() - 1; i >= 0; i--) {
		if (team[i]->getName() == name) {
			team.erase(team.begin()+i);
			break;
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (unsigned int i = 0; i < team.size(); i++) {
		team[i]->increaseSalary(amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (unsigned int i = 0; i < team.size(); i++) {
		team[i]->decreaseSalary(amount);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	lrequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	prequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	for (unsigned int i = 0; i < lrequests.size(); i++) {
		for (unsigned int j = 0; j < team.size(); j++) {
			if (lrequests[i].getSender() == team[j]->getName()) {
				team[j]->setLead(nullptr);
				removeDeveloperFromTeam(team[j]->getName());
				
			}
		}
	}
	lrequests.clear();
}

void TeamLead::fulfillPromotionRequests()
{
	for (unsigned int i = 0; i < prequests.size(); i++) {
		for (unsigned int j = 0; j < team.size(); j++) {
			if (prequests[i].getSender() == team[j]->getName()) {
				team[j]->increaseSalary(prequests[j].getAmount());
				
			}
		}
	}
	prequests.clear();
}

