#include <iostream>
#include <cmath>

using namespace std;

double add(double number1, double number2) {
	return number1 + number2;
}

double subtraction(double number1, double number2) {
	return number1 - number2;
}

double multi(double number1, double number2) {
	return number1 * number2;
}



double div(double number1, double number2) {
	if (number2 == 0) {
		cout << "You Can not make the denomenator equals to 0." << endl;
		return 0;
	};
	return number1 / number2;
}

double squarRoot(double number1) {
	if (number1 < 0) {
		cout << "You can not put a negative number under a squar root." << endl;
		return 0;
	}
	return sqrt(number1);
}

double power(double number1, double number2) {
	return  pow(number1, number2);
}

double absol(double number1) {
	return abs(number1);
}

double sine(double number1) {
	double number = (number1 * 3.14) / 180;
	return sin(number);
}
double cosine(double number1) {
	double number = (number1 * 3.14) / 180;
	return cos(number);
}
double tangent(double number1) {
	double number = (number1 * 3.14) / 180;
	return tan(number1);
}

int Modulus(int number1,int number2) {
	if (cin.fail()) {
		cout << "Must be Integer" << endl;
		cin.clear();
		cin.ignore();
	}
	return number1 % number2;
}



double calculate(double number1, double number2, char operators) {
	switch (operators) {
	case '+':return add(number1, number2); break;
	case '-':return subtraction(number1, number2) ; break;
	case '*':return multi(number1, number2) ; break;
	case '/':return div(number1, number2) ; break;
	case '1':return squarRoot(number1) ; break;
	case '2':return power(number1, number2) ; break;
	case 'a':return absol(number1) ; break;
	case 's':return sine(number1) ; break;
	case 'c':return cosine(number1) ; break;
	case 't':return tangent(number1); break;
	case '%':return Modulus(number1, number2); break;
	case 'l':return calculate(number1, number2, operators); break;
	case 'n':return log10(number1); break;
	case 'r':number1 = number2 = 0;
		cout << "Reset Done"; break;

	default:
		cout << "Invalid Inpute" << endl;
	}
	return 0;
}

bool isValidInput(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '1'
        || op == '2' || op == 'a' || op == 's' || op == 'c' || op == 't'
        || op == '%' || op == 'r' || op == 'l' || op == 'n';
}

int main()
{
	char operators;

	double number1 = 0, number2 = 0;
	double lastResult{};

	char userDecision;
	bool completeCalculations = true;
	
	while (completeCalculations) {
		cout << "\n========== Calculator ==========\n";
		cout << "|(r) Reset| |(l) Last Result|\n--------------------------------\n (+) Add, (-) Subatraction\n (*) Multiplication, (/) Devision\n (1) Squar Root, (2) Power\n (a) Absolute\n (s) Sine, (c) Cosine, (t) Tangent\n (%) Modulus, (n) Logarithem Base 10" << endl;
        cout << " Choice: ";
        cin >> operators;
		
		if (operators == 'r') {
			continue;
		}
		
		if (operators == 'l') {
			cout << lastResult << endl;
			continue;

		}

		cout << "Enter the first number: ";
		cin >> number1;
		

		if (operators != '1' && operators != 'a' && operators != 's' && operators != 'c' && operators != 't' && operators != 'n') {
			cout << "Enter the second number: ";
			cin >> number2;
		}
		
		cout << calculate(number1, number2, operators) << endl;

		lastResult = calculate(number1, number2, operators);
		
		//Decision to Complete 
		cout << "Complete Calulations:(Y,N) ";
		cin >> userDecision;
		switch (userDecision) {
		case 'Y':
		case 'y':
			break;
		case'N':
		case'n':
			completeCalculations = false;
			break;
		}

	}
}

