#pragma once
/*
decalaration
*/
#include <string>
using namespace std;
/*
declaring public variable is not an efficient method
make setters and getters function -->!reminder (if You have time)
*/
//class Triangle to store public variable values
class Triangle {
public:
	double side_a = 0, side_b = 0, side_c = 0;
	double alpha = 0, beta = 0, gamma = 0, gammaIN = 0;
	//An inlline function to intialize publice variables or maybe a constructor :)
	//after printing the output
	void initialize_triangle() {
		side_a = 0, side_b = 0, side_c = 0, alpha = 0, beta = 0, gamma = 0, gammaIN = 0;
	}
	bool is_possible(double, double, double); //verify if the triangle is possible to form
	double perimeter(double, double, double);//to find the perimeter
	double area(double, double, double);// to find the area
	string triangle_type(double, double, double);//to find the ype of a triangle
	string triangle_angle_type(double, double, double);//to find the angle type of a triangle
	void SSS(double, double, double);//func that find 3 angles with given SSS
	void SAS(double, double, double);//func that 2 angles and 1 side with given SAS
	void ASA(double, double, double);//func that returns 2 sides and 1 angle given ASA
	void SSA(double, double, double);//func that return 2 angle and 1 side given SSA
};



