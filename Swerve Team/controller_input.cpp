#include <iostream>
#include <stdlib.h>
/**#include "../../../eric/fourteentwentyfive.hammer/input/joystick_linux.h"
#include "../../../eric/fourteentwentyfive.hammer/input/gamepad.h"**/

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

ostream & operator<<(ostream&o,Controller gp){
	o<<"LJ:("<<gp.left_joy.x<<","<<gp.left_joy.y<<"),RJ:("<<gp.right_joy.x<<","<<gp.right_joy.y<<"),a:"<<gp.button.a<<",b:"<<gp.button.b<<",x:"<<gp.button.x<<",y:"<<gp.button.y<<",rb:"<<gp.button.rb<<",rt;"<<gp.button.rt<<",lb;"<<gp.button.lb<<",lt:"<<gp.button.lt;
	return o;
};

float input(string prompt) {
	string geti;
	std::cout<<prompt<<": ";
	getline(cin,geti);
	//std::cout<<"\n";
	float i = atof(geti.c_str());
	return i;
}

void getgamepad (Controller &gamepad) {
	gamepad.left_joy.x = input("J1.x");
	gamepad.left_joy.y = input("J1.y");
	gamepad.right_joy.x = input("J2.x");
	gamepad.right_joy.y = input("J2.y");
	gamepad.button.a = 0;
	gamepad.button.b = 0;
	gamepad.button.x = 0;
	gamepad.button.y = 0;
	gamepad.button.rb = 0;
	gamepad.button.rt = 0;
	gamepad.button.lb = 0;
	gamepad.button.lt = 0;
}

int main(){
	Controller gamepad;
	getgamepad(gamepad);
	std::cout<<gamepad<<"\n";
	/**Joystick_linux a("/dev/input/js0");
	cout<<a.read()<<"\n";**/
}
