#include <iostream>

using namespace std;


#define WIDTH	32

class fraction;
fraction operator*(fraction left, fraction right);
fraction operator/=(fraction left, fraction right);




class fraction
{
	int integer;
	int numenator;
	int denominator;
	int n;


public:

	int get_integer()const
	{
		return integer;
	}
	int get_numenator()const
	{
		return numenator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	int get_n()const
	{
		return n;
	}
	void set_integer(int integer)
	{
		this->integer = integer;

	}
	void set_numenator(int numenator)
	{
		this->numenator = numenator;

	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;

	}
	void set_n(int n)
	{
		this->n = n;
	}

	//				Constuctors:
	fraction()
	{
		this->integer = 0;
		this->numenator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "DefaultConstructor:" << this << endl;


	}
	fraction(int integer)
	{
		this->integer = integer;
		this->numenator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "SingleArgumentConstructor:\t" << this << endl;


	}
	fraction(int numenator, int denominator)
	{
		this->integer = 0;
		this->numenator = numenator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "constructor:" << this << endl;


	}

	fraction(int integer, int numenator, int denominator)
	{
		this->integer = integer;
		this->numenator = numenator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	fraction(int integer, int numenator, int denominator, int n)
	{
		this->integer = integer;
		this->numenator = numenator;
		this->denominator = 1;
		this->n = 1;
		cout << std::left << "Constructor:" << this << endl;
	}
	//const fraction **operator  (const fraction& f) const
	//{
	//	this->n;
	//}
	//const fraction operator* (fraction B)
	//{
	//	fraction C;
	//	to_improper();
	//	B.to_improper();
	//	C.set_numenator(this->numenator * B.numenator);
	//	C.set_denominator(this->denominator * B.denominator);
	//	C.to_proper();
	//	C.reduce();
	//	if (C.get_integer() < 0)
	//		C.set_numenator(C.get_numenator() * (-1));
	//	return fraction (C);
	//	to_proper();

	//}

	//const fraction operator/ (fraction B)
	//{
	//	fraction C;
	//	to_improper();
	//	B.to_improper();
	//	C.set_numenator(this->numenator * B.numenator);
	//	C.set_denominator(this->denominator * B.denominator);
	//	C.to_proper();
	//	C.reduce();
	//	if (C.get_integer() < 0)
	//		C.set_numenator(C.get_numenator() * (-1));
	//	return fraction(C);
	//	to_proper();
	//}

	//const fraction operator + (fraction B)
	//{
	//	fraction C;
	//	to_improper();
	//	B.to_improper();
	//	C.set_numenator(this->numenator * B.numenator + B.numenator*this->denominator);
	//	C.set_denominator(this->denominator * B.denominator);
	//	C.to_proper();
	//	C.reduce();
	////	
	//	return fraction(C);
	//	to_proper();
	//	
	//}

	//const fraction operator- (fraction B)
	//{
	//	fraction C;
	//	to_improper();
	//	B.to_improper();
	//	C.set_numenator(this->numenator * B.numenator - B.numenator * this->denominator);
	//	C.set_denominator(this->denominator * B.denominator);
	//	C.to_proper();
	//	C.reduce();

	//	return fraction(C);
	//	to_proper();

	//}
	//fraction operator++()
	//{
	//	integer++;
	//	return*this;

	//}
	//fraction operator--()
	//{
	//	integer--;
	//	return*this;

	//}

	~fraction()
	{
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}
	//				Operators:
	fraction& operator=(const fraction& other)
	{
		this->integer = other.integer;
		this->numenator = other.numenator;
		this->denominator = other.denominator;
		cout.width(WIDTH);
		cout << std::left << "CopeAssignment: " << this << endl;
		return *this;

	}

	fraction& operator*=(const fraction& other)
	{

		return*this = *this * other;

	}
	//				Increment/Decrement
	fraction& operator++()
	{
		integer++;
		return *this;
	}

	fraction& operator++(int)
	{
		fraction old = *this;
		integer++;
		return old;
	}
	//				Methods:


	fraction& to_proper()
	{
		integer += numenator / denominator;
		numenator %= denominator;
		return*this;
	}
	fraction& reduce()
	{
		//https://www.webmath.ru/
		int more, less, rest;
		if (numenator > denominator)
		{
			more = numenator;
			less = denominator;
		}
		else
		{
			less = numenator;
			more = denominator;
		}
		do
		{

			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		{
			int GCD = more;
			numenator /= GCD;
			denominator /= GCD;
			return*this;
		}
	}
	fraction& to_improper()
	{
		numenator += integer * denominator;
		integer = 0;
		return *this;
	}

	fraction inverted()const
	{
		fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numenator, inverted.denominator);
		return inverted;
	}

	void Print()const
	{
		if (integer) cout << integer << " ";
		if (numenator)
		{
			cout << numenator << "/" << denominator;
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}


};


fraction operator*(fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	/*fraction res;
	res.set_numenator(left.get_numenator() * right.get_numenator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	res.to_proper();*/
	//	fraction res
	//	(
	//		left.get_numenator() * right.get_numenator(),
	//		left.get_denominator() * right.get_denominator()
	//
	//	);
	//	res.to_proper();
	//	return res;
	//}

	return fraction
	(
		left.get_numenator() * right.get_numenator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

fraction operator/(fraction left, fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return fraction
	(
		left.get_numenator() * right.get_denominator(),
		right.get_numenator() * left.get_denominator()
	).to_proper();*/

	return left * right.inverted();
}
ostream& operator<< (ostream& os, const fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer() << " ";
	if (obj.get_numenator())
	{
		os << obj.get_numenator() << "/" << obj.get_denominator();

	}
	else os << 0;
	return os;

}
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define CONSTRUCTORS_CHECK
void main()
{
#ifdef CONSTRUCTORS_CHECK
	setlocale(LC_ALL, "");
	fraction A; //Default
	A.Print();

	fraction B = 5; // Single-Argument
	B.Print();

	fraction C(1, 2);
	C.Print();

	fraction D(2, 3, 4);
	D.Print();
	D.to_improper();
	D.Print();

	D.to_proper();
	D.Print();

	fraction E(5, 2, 6);
	E.reduce();
	E.Print();
#endif
	//#ifdef ARITHMETICAL_OPERATORS_CHECK
	//
	//
	//
	//		double a = 2;
	//		double b = 3;
	//		double c = a * b;
	//
	//		fraction A(2, 3, 4);
	//		fraction B(3, 4, 5);
	//		fraction C = A / B;
	//		C.Print();
	//		
	//		A *= B;
	//		A /= B;
	//		A.Print();
	//
	//#endif 
#ifdef INCREMENT_CHECK
	for (double i = .0325; i < 10; i++) cout << i << "\t"; cout << endl;
	for (fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.Print();
	}
#endif // INCREMENT_CHECK
	fraction A(2, 3, 4);
	cout << A << endl;


	/*	C.Print();
		fraction D = A * B;
		D.Print();
		fraction E = A - B;
		E.Print();
		fraction F = A / B;
		F.Print();*/


}