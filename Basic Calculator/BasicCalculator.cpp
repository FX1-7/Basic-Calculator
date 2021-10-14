#include <iostream>;

using namespace std;

int main() {
	// Declare variables
	string input1;
	string Operator;
	string input2;
	int num1 = 0;
	int num2 = 0;
	int cont = 0;
	int rollingsum = 0;
	int finaltotal = 0;

	// I've set the while loop like this because I couldn't get it to be while input1 || input2 = "exit" to work, not sure why.
	while (cont == 0) {
		// Gets first input
		cout << "Please enter a number or 'exit' to quit the program" << endl;
		cin >> input1;
		// If input is exit then return 0 and close program.
		if (input1 == "exit") {
			return 0;
		}
		// Converts input to an int so we can do calculations with it.
		num1 = atoi(input1.c_str());
		// Gets the operator from the user.
		cout << "Please enter the mathmatical operator you with to use. e.g /, *, +, -" << endl;
		cin >> Operator;
		// Gets second input
		cout << "Please enter a number or 'exit' to quit the program" << endl;
		cin >> input2;
		// Same as above, exits if told so.
		if (input2 == "exit") {
			return 0;
		}
		// Converts str to int
		num2 = atoi(input2.c_str());

		// If this is the first loop then rolling sum is 0, created this nested if statement to avoid issues with * by 0
		if (rollingsum == 0) {
			if (Operator == "+") {
				rollingsum = num1 + num2;
			}
			else if (Operator == "-") {
				rollingsum = num1 - num2;
			}
			else if (Operator == "/") {
				rollingsum = num1 / num2;
			}
			else if (Operator == "*") {
				rollingsum = num1 * num2;
			}
			else {
				// If user has entered an alien input we will exit the program to avoid calculation errors
				cout << "Error: Please use the suggested operators the next time.";
				return 0;
			}
		}
		// If this is not the first time round the loop then we use rolling sum in the calculation to make sure we add ALL numbers together.
		else {
			if (Operator == "+") {
				rollingsum = rollingsum + (num1 + num2);
			}
			else if (Operator == "-") {
				rollingsum = rollingsum - (num1 - num2);
			}
			else if (Operator == "/") {
				rollingsum = rollingsum / (num1 / num2);
			}
			else if (Operator == "*") {
				rollingsum = rollingsum * (num1 * num2);
			}
			else {
				// use the right operators >:(
				cout << "Error: Please use the suggested operators the next time.";
				return 0;
			}
		}
		// Output of all rollingsum and numbers we used THIS loop.
		cout << "The sum of all numbers is: " << rollingsum << ". we used " << num1 << " and " << num2 << " this loop." << endl;
		// set numbers back to 0 to avoid issues with calculation if user goes back through the loop.
		num1 = 0;
		num2 = 0;
	}
	cout << "The final total is: " << rollingsum << endl;
}