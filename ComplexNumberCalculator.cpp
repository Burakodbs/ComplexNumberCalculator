#include <iostream>
#include <cmath>

using namespace std;

double r1, r2, i1, i2;
int pref, anothercalc = 1;           //VARIABLES

class complex
{
public:
	complex(double r = 0, double i = 0)
	{
		real = r;                       //CONSTRUCTOR
		imag = i;
	}
	void print()
	{
		if (imag < 0 && real != 0.0)
		{
			cout << "RESULT: (" << real << imag << "i)" << "\n";
		}
		else if (imag > 0 && real != 0.0)
		{
			cout << "RESULT: (" << real << "+" << imag << "i)" << "\n";
		}
		else if (real == 0)                                        //SPECIAL PRINT FUNCTION FOR IMAGINER NUMBERS
		{
			cout << "RESULT: (" << imag << "i)\n";
		}
		else
		{
			cout << "RESULT: (" << real << ")\n";
		}
	}
	complex operator+(complex obj)
	{
		complex temp;
		temp.real = real + obj.real;
		temp.imag = imag + obj.imag;
		return temp;
	}
	complex operator-(complex obj)
	{
		complex temp;
		temp.real = real - obj.real;
		temp.imag = imag - obj.imag;
		return temp;
	}
	complex operator*(complex obj)
	{
		complex temp;
		temp.real = -(imag * obj.imag) + (real * obj.real);                                                                                     //OPERATOR OVERLOADING FUNCTIONS
		temp.imag = (real * obj.imag) + (imag * obj.real);
		return temp;
	}
	complex operator/(complex obj)
	{
		complex temp;
		temp.real = (real * obj.real + imag * obj.imag) / (pow(obj.real, 2) + pow(obj.imag, 2));
		temp.imag = (imag * obj.real - real * obj.imag) / (pow(obj.real, 2) + pow(obj.imag, 2));
		return temp;
	}
	complex operator+= (complex obj)
	{
		real = real + obj.real;
		imag = imag + obj.imag;
		return *this;
	}
	complex operator-= (complex obj)
	{
		real = real - obj.real;
		imag = imag - obj.imag;
		return *this;
	}
	complex operator*= (complex obj)
	{
		real = -(imag * obj.imag) + (real * obj.real);                                                                                     //OPERATOR OVERLOADING FUNCTIONS
		imag = (real * obj.imag) + (imag * obj.real);
		return *this;
	}
	complex operator/= (complex obj)
	{
		real = ((real * obj.real) + (imag * obj.imag)) / (pow(obj.real, 2) + pow(obj.imag, 2));
		imag = ((imag * obj.real) - (real * obj.imag)) / (pow(obj.real, 2) + pow(obj.imag, 2));
		return *this;
	}
	void polar()
	{
		double r = sqrt((pow(imag, 2)) + (pow(real, 2)));
		if ((imag / r) < 0)
		{
			cout << "**************POLAR REPRESENTATION**************" << "\n";
			cout << r << "(" << (real / r) << (imag / r) << "i)\n";                                   //POLAR REPRESENTATION
		}
		else
		{
			cout << "**************POLAR REPRESENTATION**************" << "\n";
			cout << r << "(" << (real / r) << "+" << (imag / r) << "i)\n";
		}
	}


	double real, imag;
};

void print_menu()
{
	cout << "**************WHICH OPERATION DO YOU WANT TO DO?**************" << "\n";
	cout << "1)ADD" << "\n";
	cout << "2)EXTRACT" << "\n";
	cout << "3)MULTIPLY" << "\n";
	cout << "4)DIVIDE" << "\n";
	cout << "5)SHOW POLAR REPRESENTATION OF FIRST NUMBER" << "\n";
	cout << "6)SHOW POLAR REPRESENTATION OF SECOND NUMBER" << "\n";
	cout << "0=ÇIKIŞ" << "\n";
	cin >> pref;
	while (pref != 0 && pref != 1 && pref != 2 && pref != 3 && pref != 4 && pref != 5 && pref != 6)
	{
		cout << "Please enter a valid value..." << "\n";
		cin >> pref;
	}
	system("CLS");
}
void request_input()
{
	cout << "**************COMPLEX NUMBER CALCULATOR**************" << "\n";
	cout << "Please enter the real part of the first number." << "\n";
	cin >> r1;
	cout << "Please enter the imaginary part of the first number." << "\n";
	cin >> i1;
	cout << "Please enter the real part of the second number." << "\n";
	cin >> r2;
	cout << "Please enter the imaginary part of the second number." << "\n";
	cin >> i2;
	while (r2 == 0 && i2 == 0)
	{
		system("CLS");                                                               //DATA VALIDITION

		cout << "PLEASE ENTER THE SECOND COMPLEX NUMBER DIFFERENT FROM 0." << "\n";
		cout << "FIRST COMPLEX NUMBER: (" << r1 << "," << i1 << "i)\n";
		cout << "Please enter the real part of the second number." << "\n";
		cin >> r2;
		cout << "Please enter the imaginary part of the second number." << "\n";
		cin >> i2;
	}
}

enum islem { EXIT, EXTRACT, SUBSTRACT, MULTIPLY, DIVIDE, POLAR1, POLAR2 };//FOR BETTER UNDERSTANDING 

int main()
{
	request_input();

	complex number3;
	complex number1 = complex(r1, i1);
	complex number2 = complex(r2, i2);
	system("PAUSE");
	system("CLS");

	while (anothercalc == 1)
	{
		system("CLS");
		print_menu();
		switch (pref)
		{
		case EXTRACT:
			number3 = number1 + number2;
			number3.print();
			break;

		case SUBSTRACT:
			number3 = number1 - number2;
			number3.print();
			break;

		case MULTIPLY:
			number3 = number1 * number2;
			number3.print();
			break;

		case DIVIDE:
			number3 = number1 / number2;
			number3.print();
			break;

		case POLAR1:
			number1.polar();
			break;

		case POLAR2:
			number2.polar();
			break;

		case EXIT:
			cout << "\t""\t""\t""\t""*************************************************" << "\n";
			cout << "\t""\t""\t""\t""*******PROGRAM ENDED SUCCESSFULLY.*******" << "\n";
			cout << "\t""\t""\t""\t""*************************************************" << "BURAK ODABAŞ 2022" << "\n";
			return 0;
		}
		cout << "ANOTHER OPERATION?1/0" << "\n";
		cin >> anothercalc;
		while (anothercalc != 0 && anothercalc != 1)
		{
			cout << "Please enter a valid value..." << "\n";
			cin >> anothercalc;
		}
	}
}