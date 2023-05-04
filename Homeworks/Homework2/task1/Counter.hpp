#pragma once
class Counter
{
protected:
	int value;
	unsigned int step;
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned int step);
	Counter(const Counter& rhs);

	virtual void increment();
	int getTotal()const;
	unsigned int getStep()const;
};
