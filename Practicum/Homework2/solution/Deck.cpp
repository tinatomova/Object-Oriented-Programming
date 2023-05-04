/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Tina Tomova
* @idnumber 62594
* @task 1
* @compiler GCC
*/

#include "Deck.hpp"


void Deck::setDeckName(std::string n)
{
    deckName = n;
}

std::string Deck::getDeckName()
{
    return deckName;
}

unsigned int Deck::monsterDeckCount()
{
    return monsterDeck.size();
}

unsigned int Deck::magicDeckCount()
{
    return magicDeck.size();
}

unsigned int Deck::pendulumDeckCount()
{
    return pendulumDeck.size();
}

void Deck::addMonster(const MonsterCard monster)
{
    monsterDeck.push_back(monster);
}

void Deck::addMagic(const MagicCard magic)
{
    magicDeck.push_back(magic);
}

void Deck::addPendulum(const PendulumCard pendulum)
{
    pendulumDeck.push_back(pendulum);
}

void Deck::changeMonster(unsigned int possition, const MonsterCard monster)
{
    monsterDeck[possition] = monster;
}

void Deck::changeMagic(unsigned int possition, const MagicCard magic)
{
    magicDeck[possition] = magic;
}

void Deck::changePendulum(unsigned int possition, const PendulumCard pendulum)
{
    pendulumDeck[possition] = pendulum;
}

void Deck::clear()
{
    monsterDeck.clear();
    magicDeck.clear();
    pendulumDeck.clear();
}

std::istream& operator>>(std::istream& in, Deck& deck)
{
    std::string line, n;
    unsigned int size1=0, size2=0, size3=0;
    in >> line;
    int i = 0;
    for (; line[i] != '|'; i++) {
        n[i] = line[i];
    }
    deck.setDeckName(n);
    i += 2;
    for (; line[i] != '|'; i++) {
        size1 += line[i] - '0';
        size1 *= 10;
    }
    size1 /= 10;
    i += 2;
    for (; line[i] != '|'; i++) {
        size2 += line[i] - '0';
        size2 *= 10;
    }
    size2 /= 10;
    i += 2;
    for (; line[i] != '|'; i++) {
        size3 += line[i] - '0';
        size3 *= 10;
    }
    size3 /= 10;


    for (unsigned int i = 0; i < size1; i++) {
        in >> deck.monsterDeck[i];
    }
    for (unsigned int i = 0; i <size2; i++) {
        in >> deck.magicDeck[i];
    }
    for (unsigned int i = 0; i < size3; i++) {
       // in >> deck.pendulumDeck[i];
    }
    return in;
}


std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
    unsigned int mon = deck.monsterDeck.size();
    unsigned int mag = deck.magicDeck.size();
    unsigned int pen = deck.pendulumDeck.size();

    out << deck.deckName << "|" << mon << "|" << mag << "|" << pen <<'\n';
    for (unsigned int i = 0; i < deck.monsterDeck.size(); i++) {
        out << deck.monsterDeck[i];
    }
    for (unsigned int i = 0; i < deck.magicDeck.size(); i++) {
        out << deck.magicDeck[i];
    }
    for (unsigned int i = 0; i < deck.pendulumDeck.size(); i++) {
       //out << deck.pendulumDeck[i];
    }
    return out;
}
