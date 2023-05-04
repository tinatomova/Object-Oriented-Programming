#pragma once
#include<string>
#include"LeavingRequest.hpp"
#include"PromotionRequest.hpp"

using namespace std;
class TeamLead;
class Developer
{
protected:
	string name;
	double salary;
	TeamLead* lead;

public:
	Developer(const string& name);
	Developer(const string& name, double salary);
	string getName()const;
	double getSalary()const;
	TeamLead* getTeamLead()const;
	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
	void setLead(TeamLead* l);
	void increaseSalary(double amount);
	void decreaseSalary(double amount);
};
