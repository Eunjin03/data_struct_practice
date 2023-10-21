#include <iostream>
#include <cstdlib>

using namespace std;

class ThinkingCap {
public:
	ThinkingCap() {};
	void slots(string new_green, string new_red);
	void push_green() const {
		cout << green_string << endl;
	}
	void push_red() const {
		cout << red_string << endl;
	}

private:
	string green_string;
	string red_string;
};

void ThinkingCap::slots(string new_green, string new_red) {
	green_string = new_green;
	red_string = new_red;
}

int main() {
	ThinkingCap student;
	ThinkingCap fan;

	student.slots("Hello", "Goodbye");
	fan.slots("Go Cougars!", "Boo!");
	student.push_green();
	fan.push_green();
	student.push_red();
}
