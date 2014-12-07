#include <iostream>
#include <math.h>
#include <controller_input.h>
#include <std>

using namespace std;



int main(){
	bool grabber_open;
	bool grabber_close;
	bool arm_down;
	bool arm_up;
	bool grabber_dump;
	if(controller_input::gamepad.button.a==1){
		grabber_open==1;
	}
	if(controller_input::gamepad.button.b==1){
		grabber_close==1;
	}
	if(controller_input::gamepad.button.x==1){
		arm_down==1;
	}
	if(controller_input::gamepad.button.y==1){
		arm_up==1;
	}
		
}