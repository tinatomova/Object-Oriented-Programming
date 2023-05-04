#include "SectionVotes.hpp"


SectionVotes::SectionVotes()
{
	this->party1 = 0;
	this->party2 = 0;
	this->party3 = 0;
}

SectionVotes::SectionVotes(const SectionVotes& section)
{
	this->party1 = section.party1;
	this->party2 = section.party2;
	this->party3 = section.party3;
}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
	this->party1 = party1Votes;
	this->party2 = party2Votes;
	this->party3 = party3Votes;
}

int SectionVotes::votesForParty(Party p) const
{
	if (p == Party::PARTY1)return party1;
	if (p == Party::PARTY2)return party2;
	else return party3;
	
}
void SectionVotes::setP1(int p1)
{
	party1 = p1;
}
void SectionVotes::setP2(int p2)
{
	party2 = p2;
}
void SectionVotes::setP3(int p3)
{
	party3 = p3;
}
std::ostream& operator<<(std::ostream& out, const SectionVotes& obj)
{
	out << obj.party1 << " " << obj.party2 << " " << obj.party3 << '\n';
	return out;
}
std::istream& operator>>(std::istream& in, SectionVotes& obj)
{
	int input1, input2,input3;
	in >> input1 >> input2 >> input3;
	obj.party1 = input1;
	obj.party2 = input2;
	obj.party3 = input3;

	return in;
}
