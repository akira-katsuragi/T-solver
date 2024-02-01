#include <iostream>
#include <cmath>
#include "Tools.hpp"
#include "triangle.hpp"
using namespace std;
//Triangle class functions::
/*
Triangle:: it used as for referencing a member of the Triangle class. 
This notation is used to access members (variables or functions) 
of a class from outside the class definition.
*/
//verifying a triangle if its possible or not
bool Triangle::is_possible(double a, double b, double c) {
	bool isPossible = (a + b > c) && (a + c > b) && (b + c > a);
	return isPossible;
}
//to find a perimeter of a triangle
double Triangle::perimeter(double a, double b, double c) {
	return a + b + c;
}
//to find the area of a triangle
double Triangle::area(double a, double b, double c) {
	double s = (a + b + c) / 2;
	double area = sqrt(s * (s - a) * (s - b) * (s - c));
	return area;
}//to find triangle type
string Triangle::triangle_type(double a, double b, double c) {
	//checking if a triangle is isosceles, equilatral, scalene
	if(a == b && a == c && b == c) {
		return "equilateral";
	}else if (a == b || a == c || b == c) {
		return "isosceles"; 
	}else {
		return "scalene";
	}
}
//to find triangle angle type
string Triangle::triangle_angle_type(double A, double B, double C){
	//LA = largest angle
	double LA = max(A, max(B, C));// finding the largest angle among A , B , C

	if (A == 90 || B == 90 || C == 90){
		return "right";
	}
	else if (LA > 90) {
		return "obtuse";
	}
	else if (LA < 90) {
		return "acute";
	}
	return "invalid";
}
//SSS function that takes 3 parameters as sides 
//and then assign 3 angles to the public variabels
void Triangle::SSS(double a, double b, double c) {
    side_a = a, side_b = b, side_c = c;// sides are reperesented as LOWS
	//finding alpha with arccos ((b^2 + c^2 - a^2) / 2 * a * c)
	double cos_alpha = (pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c);
	alpha = acos(cos_alpha);
	// Convert angle A from radians to degrees
	alpha = Radiant_To_Degree(alpha);
	//after findind alpha beta can be found by 
	//beta = arcos((a^2 + c^2 - b^2) / 2bc formula
	beta = acos((pow(side_a, 2) + pow(side_c, 2) - pow(side_b, 2)) / (2 * side_a * side_c));
	//beta is converted into degree
	beta = Radiant_To_Degree(beta);
	//gamma = 180 - alpha - beta
	gamma = 180 - alpha - beta;
}
//SAS function that takes 2 sides and 1 angle 
//and then assings 1 side and 2 angles to the public variabls
void Triangle::SAS(double a, double C, double b) {
	alpha = 0, beta = 0, gamma = C; //angles are repereesented as CAPS
	side_a = a, side_b = b, side_c = 0;// sides are reperesented as LOWS
	//convert angle B from degrees to radians
	double C_rad = Degree_To_Radiant(C);
	//b^2 = a^2 + c^2 - 2ab cos B
	side_c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(C_rad));
	//finding alpha
	double cos_alpha = (pow(b, 2) + pow(side_c, 2) - pow(a, 2)) / (2 * b * side_c);
	alpha = acos(cos_alpha);
	// Convert angle A from radians to degrees
	alpha = Radiant_To_Degree(alpha);
	//gamma = 180 - alpha - beta
	beta = 180 - alpha - gamma;
}
//ASA function that takes 2 angles and 1 side as parameters
//and assigns 2 side and 1 angle to the public variable
void Triangle::ASA(double A, double c, double B) {
	alpha = A, beta = B, side_c = c;
	//gamma = 180 - alpha - beta
	gamma = 180 - alpha - beta;
	//converting angle A, B, C to raidians by Degree-To-Radiant func
	double alpha_rad = Degree_To_Radiant(alpha), gamma_rad = Degree_To_Radiant(gamma);
	side_a = c * (sin(alpha_rad) / sin(gamma_rad)); // Using the law of sines
	//convert beta and gamme to radiant
	double beta_rad = Degree_To_Radiant(beta);
	//side b = c * (sin BETA / sin GAMMA)
	side_b = side_c * (sin(beta_rad) / sin(gamma_rad));
}
//SSA
void Triangle::SSA(double b, double c, double B) {
	side_b = b, side_c = c, beta = B;
	//there are four possible scenarios :) --> that returns gamma
	double beta_rad = Degree_To_Radiant(beta);
	double D = (side_c / side_b) * sin(beta_rad); //D =  right hand side of the equation :|
	//scenario 1
	if (D > 1)
	{	gamma = 0;//its just for reffrence to show its an impossible triangle 
		side_a = 0, side_b = 0, side_c = 0;// this condition may not satisfy but when 
		//the is_possible function is called this will return false 
		//no such triangle exsists
	}
	//scenario 2
	else if (D == 1)
	{	//a unique solution exists gamma = 90 i.e triangle is right angled
		gamma = 90;
	}
	//scenario 3
	else // D < 1
	{	//scenario 3.1
		if (side_b >= side_c)//i.e beta >= gamma :)
		{	gamma = asin(D);
			gamma = Radiant_To_Degree(gamma);
		}
		//scenario 3.2
		else if (side_b < side_c)
		{   //3.2.1 gamma = acute
			gamma = asin(D);
			gamma = Radiant_To_Degree(gamma);
			gammaIN = 180 - gamma;
		}
	}
	//finding alpha by 180 - B - G
	alpha = 180 - beta - gamma;
	//side_a can be found by b * ( sin(alpha) / sin(beta) ) >_o
	double alpha_rad = Degree_To_Radiant(alpha); 
	side_a = side_b * (sin(alpha_rad) / sin(beta_rad));
}
