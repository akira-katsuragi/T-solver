#include <iostream>
#include "Tools.hpp"
#include "triangle.hpp"
#include <cctype>
#include <iomanip>
#define PI 3.14159265358979323846//cmath manipulator is not defining PI
using namespace std;
/*
implementation
*/
Triangle triangle{};
//making a function called toUpper 
//to change the entire string to upper case
string ToUpper(string str) {
	string new_str = "";
	//for each char C it is converted to upppercase
	for (char c : str) {
		new_str += toupper(c);
	}
	return new_str;
}
//to onvert from radiant to degree
double Radiant_To_Degree(double r) {
	r *= (180 / PI);
	return r;
}
//to convert from degree to radiant
double Degree_To_Radiant(double D) {
	double D_rad = D * (PI / 180);
	return D_rad;
}
//output formated values
void format_print(double a, double b, double c, double A, double B, double C, string str) {
	//getting perimete, area, type, angle type
	double perimeter = triangle.perimeter(a, b, c);
	double area = triangle.area(a, b, c);
	string Type = triangle.triangle_type(a, b, c);
	string angleType = triangle.triangle_angle_type(A, B, C);
	//Output is rounded to 3 decimal places.(dont forget to check if its rounded)
	cout << fixed << setprecision(3);
	cout << "a =  " << a << "  " << "alpha =  " << A << endl;
	cout << "b =  " << b << "  " << "beta  =  " << B << endl;
	cout << "c =  " << c << "  " << "gamma =  " << C << endl;
	cout << endl;
	cout << "Perimeter =  " << perimeter << endl;
	cout << "Area      =  " << area << endl;
	cout << "Type      =  " << Type + ", " + angleType << endl;
	cout << endl;
}
