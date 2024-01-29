/*
* 
*/
#include <iostream>
#include <sstream>
#include "Tools.hpp"
#include "triangle.hpp"
using namespace std;

int main() {

	string input_line="", Format="", new_format="";
		
		//VALIDATION
		while (!(new_format == "QUIT" || new_format == "BYE" || new_format == "EXIT")){
			//double variables are initialized inside the loop so every time the loop runs.
			//it will be automatically assigned to zero
			double x = 0, y = 0, z = 0; 
			// to bring -> in every input line
			cout << "-> ";
			/*
			*It prompts the user to enter a line of input using getline(cin, input_line).
            *It creates a stringstream iss from the input_line.
			*It extracts the format string Format and three integers a, b, and c from the iss.
			*/
			getline(cin, input_line);
			istringstream iss(input_line);
			iss >> Format >> x >> y >> z;
			//It converts the Format string to uppercase using the ToUpper function.
			new_format = ToUpper(Format);
			//If the converted new_format string is "QUIT", "BYE", or "EXIT", the loop breaks.
			if (new_format == "QUIT" || new_format == "BYE" || new_format == "EXIT")break;
			//Negative inputs are treated as positive.
			if (x < 0) x *= -1;
			if (y < 0) y *= -1;
			if (z < 0) z *= -1;
			//this if condition checks if the int variables are not zero
			//if any one of them is zero and not got any values the current loop will be skiped
			if (x == 0 || y == 0 || z == 0) {
				cout << "Bad command: Format # # #\nwhere Format = SSS | SAS | ASA | SSA\n\t# = a real number" << endl; continue;
			}
			// it checks if the new_format is a valid format ("SSS", "SAS", "SSA", "ASA", or "AAS"). 
			// If not, it prints "Invalid FORMAT" and continues to the next iteration of the loop.
			else if (!(new_format == "SSS" || new_format == "SAS" || new_format == "SSA" || new_format == "ASA" || new_format == "AAS")) {
				cout << "Bad command : Format # # #\nwhere Format = SSS | SAS | ASA | SSA\n\t# = a real number" << endl;continue;
			}
			/*
			crreating a triangle object 
			In reffrence to the triangle class
			{}: The empty initializer list used for uniform initialization.
			*/
			Triangle triangle{};

			//CALCULATION
			//with Sides and Angels

			//SSS scenario
			if (new_format == "SSS") 
			{	//calling SSS function
				triangle.SSS(x, y, z);
				//checking if the triangle is possible to form
				if (triangle.is_possible(triangle.side_a, triangle.side_b, triangle.side_c) == false)
				{	cout << "Impossible Triangle" << endl;
					continue;
				}
				//format print function is used to print the out put :)
				cout << "\nFormat: " << new_format << endl;
				format_print(triangle.side_a, triangle.side_b, triangle.side_c, triangle.alpha, triangle.beta, triangle.gamma, new_format);
				triangle.initialize_triangle();//after printing changing public variables to 0 for next case
				continue;//skipping the loop
			}
			//SAS scenario
			if (new_format == "SAS") 
			{	//calling SAS function
				triangle.SAS(x, y, z);
				//checking if the triangle is possible to form
				if (triangle.is_possible(triangle.side_a, triangle.side_b, triangle.side_c) == false)
				{	cout << "Impossible Triangle" << endl;
					continue;
				}
				//format print function is used to print the out put :)
				cout << "\nFormat: " << new_format << endl;
				format_print(triangle.side_a, triangle.side_b, triangle.side_c, triangle.alpha, triangle.beta, triangle.gamma, new_format);
				triangle.initialize_triangle();//after printing changing public variables to 0 for next case
				continue;//skipping the loop
			}
			//ASA scenario
			if (new_format == "ASA")
			{	//calling ASA function
				triangle.ASA(x, y, z);
				//checking if the triangle is possible to form
				if (triangle.is_possible(triangle.side_a, triangle.side_b, triangle.side_c) == false)
				{	cout << "Impossible Triangle" << endl;
					continue;
				}
				//format print function is used to print the out put :)
				cout << "\nFormat: " << new_format << endl;
				format_print(triangle.side_a, triangle.side_b, triangle.side_c, triangle.alpha, triangle.beta, triangle.gamma, new_format);
				triangle.initialize_triangle();//after printing changing public variables to 0 for next case
				continue;//skipping the loop	
			}
			//SSA scenario
			if (new_format == "SSA")
			{	//calling SSa function 
				triangle.SSA(x, y, z);
				//checking if the triangle is possible to form
				if (triangle.is_possible(triangle.side_a, triangle.side_b, triangle.side_c) == false)
				{	cout << "Impossible Triangle" << endl;
					continue;
				}
				if (triangle.gammaIN == 0)
				{	//format print function is used to print the out put :)
					cout << "\nFormat: " << new_format << endl;
					format_print(triangle.side_a, triangle.side_b, triangle.side_c, triangle.alpha, triangle.beta, triangle.gamma, new_format);
					triangle.initialize_triangle();//after printing changing public variables to 0 for next case
					continue;//skipping the loop
				}
				else if (triangle.gammaIN != 0)
				{	//In gamma
					cout << "\nFormat: " << new_format << endl;
					cout << "--> " << "gamma" << endl;
					format_print(triangle.side_a, triangle.side_b, triangle.side_c, triangle.alpha, triangle.beta, triangle.gamma, new_format);
					//In gamma'
					//finding alpha by 180 - B - G
					triangle.alpha = 180 - triangle.beta - triangle.gammaIN;
					//side_a can be found by b * ( sin(alpha) / sin(beta) ) >_o
					double alpha_rad = Degree_To_Radiant(triangle.alpha), beta_rad = Degree_To_Radiant(triangle.beta);
					triangle.side_a = triangle.side_b * (sin(alpha_rad) / sin(beta_rad));
					//format_output for gamma'
					cout << "--> " << "gamma'" << endl;
					format_print(triangle.side_a, triangle.side_b, triangle.side_c, triangle.alpha, triangle.beta, triangle.gammaIN, new_format);
				}
			}	
		}
		//Finally, the main function returns 0 to indicate successful completion.
		return 0;
}
