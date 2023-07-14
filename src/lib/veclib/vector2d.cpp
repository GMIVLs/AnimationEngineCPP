#include <iostream>
#include "vector2d.h"

using namespace std;
using namespace vector_engine;

class vector2d
{
	private:
		double i,j;
	public:
		vector2d::vector2d(double i = 0, double j = 0)
		{
			this->i = i;
			this->j = j;
		}
		vector2d operator+(vector2d v)
		{
			vector2d c(0,0);
			c.i = this->i + v.i;
			c.j = this->j + v.j;
			return c;
		}
		vector2d operator-(vector2d v)
		{
			vector2d c(0,0);
			c.i = this->i - v.i;
			c.j = this->j - v.j;
			return c;
		}
		vector2d operator*(vector2d v)
		{
			vector2d c(0.0,0.0);
			c.i = this->i * v.j;
			c.j = this->j * v.i;
			return c;
		}
		vector2d vector_input()
		{
			vector2d c(0.0,0.0);
			cout << "Please Enter Your Vector:" << endl;
			try
			{
				c.i = chk_number();
				c.j = chk_number();
			}
			catch(...)
			{
				cout << "Error Accourd" << endl;
				exit(3);
			}
			return c;
		}
		double chk_number ()
		{
			double number;
			while(1)
				{
					cin >> number;
					if(cin.fail())
					{
						cout << "Enter a Valid Number Please..." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> number;
					}
					if (!cin.fail())
					{
						break;
					}
				}
				return number;
		}
		void print(vector2d d)
		{
			if (d.j > 0)
				cout << "This Vector is: " << d.i <<"i+" << d.j <<"j" << endl;
			else if (d.j < 0)
				cout << "This Vector is: " << d.i <<"i" << d.j <<"j" << endl;
		}
		void multi_print(vector2d d)
		{
			cout <<"This Vector is: " << d.i-d.j <<"k" << endl;
		}
};