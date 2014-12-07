#include <iostream>
#include <stdlib.h>
/**#include "../../../eric/fourteentwentyfive.hammer/input/joystick_linux.h"
#include "../../../eric/fourteentwentyfive.hammer/input/gamepad.h"**/

using namespace std;

struct Buttons {
	bool a;
	bool b;
	bool x;
	bool y;
	bool rb;
	bool rt;
	bool lb;
	bool lt;
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

void testgamepad (Controller &gamepad, float LJx, float LJy, float RJx, float RJy, bool a, bool b, bool x, bool y, bool RB, bool RT, bool LB, bool LT) {
	gamepad.left_joy.x = LJx;
	gamepad.left_joy.y = LJy;
	gamepad.right_joy.x = RJx;
	gamepad.right_joy.y = RJy;
	gamepad.button.a = a;
	gamepad.button.b = b;
	gamepad.button.x = x;
	gamepad.button.y = y;
	gamepad.button.rb = RB;
	gamepad.button.rt = RT;
	gamepad.button.lb = LB;
	gamepad.button.lt = LT;
}

int main(){
	Controller TestA;
	testgamepad(TestA,0,1,0,0,false,false,false,false,false,false,false,false);
	Controller gamepad;
	gamepad = TestA;
	std::cout<<gamepad<<"\n";
	/**Joystick_linux a("/dev/input/js0");
	cout<<a.read()<<"\n";**/
}
