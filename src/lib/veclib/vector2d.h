#pragma once

namespace vector_engine
{
class vector2d
{
	private:
		double i,j;
	public:
		vector2d();
		vector2d(double, double);
		vector2d operator+(vector2d);
		vector2d operator-(vector2d);
		vector2d operator*(vector2d);
		vector2d vector_input();
		double chk_number ();
		void print(vector2d);
		void multi_print(vector2d);
};
}