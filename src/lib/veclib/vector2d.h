#pragma once

namespace vector_engine
{
class vector2d
{
	private:
		double i,j;
	public:
		vector2d(double i = 0, double j = 0);
		vector2d operator+(vector2d v);
		vector2d operator-(vector2d v);
		vector2d operator*(vector2d v);
		vector2d vector_input();
		double chk_number ();
		void print(vector2d d);
		void multi_print(vector2d d);
};
}