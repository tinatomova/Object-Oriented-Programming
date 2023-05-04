/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Tina Tomova
* @idnumber 62594
* @task 1
* @compiler VC
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

unsigned int Deck::monsterDeckCount()const
{
    unsigned int size = 0;
    for (unsigned int i = 0; i < container.size(); i++) {
        MonsterCard* monster = dynamic_cast<MonsterCard*>(container[i]);
        if (monster) {
            size++;
        }
    }    
    return size;
}

unsigned int Deck::magicDeckCount()const
{
    unsigned int size = 0;
    for (unsigned int i = 0; i < container.size(); i++) {
        MagicCard* magic = dynamic_cast<MagicCard*>(container[i]);
        if (magic) {
            size++;
        }
    }
    return size;
}

unsigned int Deck::pendulumDeckCount()const
{
    unsigned int size = 0;
    for (unsigned int i = 0; i < container.size(); i++) {
        PendulumCard* pendulum = dynamic_cast<PendulumCard*>(container[i]);
        if (pendulum) {
            size++;
        }
    }
    return size;
}

unsigned int Deck::allCardsCount() const
{
    return container.size();
}

void Deck::addCard(Card* card)
{
    PendulumCard* pendulum = dynamic_cast<PendulumCard*>(card);
    if (pendulum) {
        container.push_back(new PendulumCard(*pendulum));
        return;
    }
    
    MagicCard* magic = dynamic_cast<MagicCard*>(card);
    if (magic) {
        container.push_back(new MagicCard(*magic));
        return;
    }
    MonsterCard* monster = dynamic_cast<MonsterCard*>(card);
    if (monster) {
        container.push_back(new MonsterCard(*monster));
        return;
    }

    
    
    
}

bool Deck::changeCard(unsigned int index, Card* card)
{
    MonsterCard* monster = dynamic_cast<MonsterCard*>(container[index]);
    if (monster) {
        MonsterCard* mon = dynamic_cast<MonsterCard*>(card);
        if (mon) {
            container[index] = card;
            return 1;
        }
    }
    MagicCard* magic = dynamic_cast<MagicCard*>(container[index]);
    if (magic) {
        MagicCard* mag = dynamic_cast<MagicCard*>(card);
        if (mag) {
            container[index] = card;
            return 1;
        }
    }
    PendulumCard* pendulum = dynamic_cast<PendulumCard*>(container[index]);
    if (pendulum) {
        PendulumCard* pen = dynamic_cast<PendulumCard*>(card);
        if (pen) {
            container[index] = card;
            return 1;
        }
    }
    return 0;
}

void Deck::clear()
{
    container.clear();
}

void Deck::shuffle()
{
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(container.begin(), container.end());
    std::random_shuffle(container.begin(), container.end(),f);

}

Card& Deck::getCard(unsigned int i)
{
    return *container[i] ;
}



std::istream& operator>>(std::istream& in, Deck& deck)
{
    std::string line, n="";
    unsigned int size = 0, sizemon = 0, sizemag = 0, sizepen = 0;
    in >> line;
    int i = 0;
    for (; line[i] != '|'; i++) {
        n += line[i];
    }
    deck.setDeckName(n);
    i++;
    for (; line[i] != '|'; i++) {
        size += line[i] - '0';
        size *= 10;
    }
    size /= 10;
    i++;
    for (; line[i] != '|'; i++) {
        sizemon += line[i] - '0';
        sizemon *= 10;
    }
    sizemon /= 10;
    i++;
    for (; line[i] != '|'; i++) {
        sizemag += line[i] - '0';
        sizemag *= 10;
    }
    sizemag /= 10;
    i++;
    for (; line[i] >='0'&& line[i]<='9'; i++) {
        sizepen += line[i] - '0';
        sizepen *= 10;
    }
    sizepen /= 10;
    i = 0;
    MonsterCard mon;
    
    for (; i < sizemon; i++) {
        in >> mon;
        MonsterCard* monptr = &mon;
        deck.container.push_back(monptr);
    }
    i = 0;
    MagicCard mag;
    for (; i < sizemag; i++) {
        in >> mag;
        MagicCard* magptr = &mag;
        deck.container.push_back(magptr);
    }
    i = 0;
    PendulumCard pen;
    for (; i < sizepen; i++) {
        //in >> pen;
        PendulumCard* penptr = &pen;
        deck.container.push_back(penptr);
    }
    
    return in;
}

int f(int i)
{
    return std::rand()%i;
}


std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
    unsigned int all = deck.allCardsCount();
    unsigned int mon = deck.monsterDeckCount();
    unsigned int mag = deck.magicDeckCount();
    unsigned int pen = deck.pendulumDeckCount();

    out << deck.deckName << "|" << all << "|" << mon << "|" << mag << "|" << pen << '\n';
    unsigned int i = 0;
    for (; i < all; i++) {
        out << *deck.container[i];
    }
    //for (; i < mon+mag-1; i++) {
   //     out << *deck.container[i];
   // }
    //for (; i < ; i++) {
     //   out << *deck.container[i];
    //}
    return out;
}
/*
deck|3|1|1|1
mon|eff|60|10|10
mag|efff|67|trap
pen|effff|32|10|84|9|trap
*/