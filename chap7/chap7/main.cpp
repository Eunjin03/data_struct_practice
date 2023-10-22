#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
using namespace std;

void evaluate_stack(stack<double>& numbers, stack<char>& operations) {
	double operand1, operand2;
	operand2 = numbers.top();
	numbers.pop();
	operand1 = numbers.top();
	numbers.pop();

	switch (operations.top()) {
	case '+': numbers.push(operand1+operand2); break;
	case '-': numbers.push(operand1 - operand2); break;
	case '*': numbers.push(operand1 * operand2); break;
	case '/':numbers.push(operand1 / operand2); break;
	}
	operations.pop();

	
}

double read_and_evaluate(istream& ins){
	const char DECIMAL = '.';
	const char RIGHT_PARENTHESIS = ')';

	stack<double> numbers;
	stack<char> operators;
	double number;
	char symbol;

	while (ins && ins.peek() != '\n') {
		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
			ins >> number;
			numbers.push(number);
		}
		else if (strchr("+-*/", ins.peek()) != NULL) {
			ins >> symbol;
			operators.push(symbol);

		}
		else if (ins.peek() == RIGHT_PARENTHESIS) {
			ins.ignore();
			evaluate_stack(numbers, operators);

		}
		else {
			ins.ignore();
		}
	}
		

	return numbers.top();
}



int main() {
	cout << "수식을 입력하세요 (예: (3.5+4.2)*2): ";

	double result = read_and_evaluate(cin);

	cout << "결과: " << result << endl;

	return 0;
}
