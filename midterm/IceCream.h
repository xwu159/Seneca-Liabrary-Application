#pragma once
#ifndef ICECREAM_H
#define ICECREAM_H
#define max_scoops 5
#define min_scoops 1
class IceCream {
	int numOfScoops;
	char flavour[19];
	public:
		IceCream();
		IceCream(int scoops,const char* flavor);
		void set(int scoops, const char* flavor);
		bool isEmpty() const;
		void display(std::ostream&) const;
		IceCream& operator++(int);
		IceCream operator-(int);
};

#endif //

