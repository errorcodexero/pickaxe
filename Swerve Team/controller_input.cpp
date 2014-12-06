#include <iostream>

using namespace std;

struct Buttons {
	int a;
	int b;
	int x;
	int y;
	int rb;
	int rt;
	int lb;
	int lt;
};

struct Joystick {
	float x;
	float y;
};

struct Controller {
	Joystick left_joy;
	Joystick right_joy;
	Buttons button;
};

void getgamepad (Controller &gamepad) {
}

int main()
	Controller gamepad;
}
