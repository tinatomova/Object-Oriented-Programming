#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
	std::ifstream in(filename);
	if (in.is_open()) { 
		in >> *this;
		/*std::string l;
		while (getline(inFile, l)) {
			std::string line = l;
			int p1 = 0, p2 = 0, p3 = 0;
			int i = 0;
			for (; line[i] != 32; i++) {
				p1 += line[i] - '0';
				p1 *= 10;
			}
			i += 2;
			p1 /= 10;
			for (; line[i] != 32; i++) {
				p2 += line[i] - '0';
				p2 *= 10;
			}
			i += 2;
			p2 /= 10;
			for (; line[i] != 32; i++) {
				p3 += line[i] - '0';
				p3 *= 10;
			}
			p3 /= 10;
			SectionVotes s(p1, p2, p3);
			vec.push_back(s);
		}*/
	}
	
	in.close();
}

int ElectionResultsDatabase::numberOfSections() const
{
	return vec.size();
}

int ElectionResultsDatabase::votesForParty(Party p) const
{
	int votes = 0;
	
		for (unsigned int i = 0; i < vec.size(); i++) {
			votes += vec.at(i).votesForParty(p);
		}
	
	
	return votes;
}

Party ElectionResultsDatabase::winningParty() const
{
	if (votesForParty(Party::PARTY1) >= votesForParty(Party::PARTY2) && votesForParty(Party::PARTY1) >= votesForParty(Party::PARTY3))return Party::PARTY1;
	else if (votesForParty(Party::PARTY2) > votesForParty(Party::PARTY1) && votesForParty(Party::PARTY2) >= votesForParty(Party::PARTY3))return Party::PARTY2;
	else return Party::PARTY3;
	
}

std::istream& operator>>(std::istream& in, ElectionResultsDatabase& res)
{
	SectionVotes s;
	while (in >> s) {
		res.vec.push_back(s);
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& res)
{
	for (unsigned int i = 0; i < res.vec.size(); i++) {
		out << res.vec.at(i).votesForParty(PARTY1) <<" " << res.vec.at(i).votesForParty(PARTY2)<<" "<< res.vec.at(i).votesForParty(PARTY3)<< '\n';

	}
	return out;
}

