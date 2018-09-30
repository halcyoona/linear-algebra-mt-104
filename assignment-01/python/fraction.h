#ifndef FRACTION_H__
#define FRACTION_H__



#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;


class fraction
{
	protected:
		int numerator;
		int denumerator;
	public:
		void simplfy();
		void simple(fraction temp);
		fraction(int num, int denum);
		~fraction();
		void setValues(int num, int denum);
		void setValues();
		void updateNumerator(int num);
		void updateDenumerator(int denum);
		int getNumerator();
		int getDenumerator();
		fraction get();
		void print();
		friend istream& operator>>(istream& cin, fraction& fract);
		friend ostream& operator<<(ostream& cout, fraction& fract);

		friend ifstream& operator>>(ifstream& cin, fraction& fract);
		friend ofstream& operator<<(ofstream& cout, fraction& fract);
		
		fraction operator ++();
		fraction operator ++(int);
		fraction operator --();
		fraction operator --(int);
		
		fraction operator +(fraction fract);
		fraction operator -(fraction fract);
		fraction operator *(fraction fract);
		fraction operator /(fraction fract);
		
		
		bool operator ==(fraction fract);
		bool operator !=(fraction fract);
		bool operator >(fraction fract);
		bool operator <(fraction fract);
		bool operator >=(fraction fract);
		bool operator <=(fraction fract);
		
		fraction operator =(fraction fract);
		void operator +=(fraction fract);
		void operator -=(fraction fract);
		void operator *=(fraction fract);
		void operator /=(fraction fract);
};



#endif /* TEST_H__ */