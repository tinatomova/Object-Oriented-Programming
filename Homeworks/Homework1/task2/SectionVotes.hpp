#pragma once
#include <iostream>
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
    int party1, party2, party3;

public:
    SectionVotes();

    SectionVotes(const SectionVotes&);

    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;

    void setP1(int);
    void setP2(int);
    void setP3(int);


    friend std::istream& operator>>(std::istream& in, SectionVotes& obj);
    friend std::ostream& operator<<(std::ostream& out, const SectionVotes& obj);
};

std::ostream& operator<<(std::ostream& out, const SectionVotes& obj);
std::istream& operator>>(std::istream& in, SectionVotes& obj);

