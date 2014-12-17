//Author: Logan Traffas *****Unfinished***** Function: Simulates wheel movement given current and target positions (the current units are radians).
//Also determines the current wheel rotation given encoder output.
#include <iostream>
#include <cmath>
#include <math.h>

#ifndef M_PI//Defines a variable for pi if the variable does not exist
#define M_PI 3.141592653589793238462643383
#endif

using namespace std;

struct Wheel_rotation{
	double current_rotation, target_rotation, radian_change;
};

double correct_radian_form(double input){//Corrects to the correct radian form (i.e. 0-(2*pi))
	while(input<0)input+=(2*M_PI);
	while(input>(2*M_PI))input-=(2*M_PI);
	return input;
}

double determine_change(double current_rotation, double target_rotation){//Determine the amount of radians needed to change
	if(target_rotation-current_rotation==0 || target_rotation-current_rotation==(2*M_PI))return 0;//Calculates the direction and magnitude of radian change
	else if(current_rotation==-M_PI)return M_PI;//Corrects for preferred direction when direction and magnitude are equal
	else if((target_rotation-current_rotation)<=M_PI && (target_rotation-current_rotation)>-M_PI)return (target_rotation-current_rotation);//Determine the amount of radians needed to change
	else if((target_rotation-current_rotation)>M_PI)return ((target_rotation-current_rotation)-(2*M_PI));//Determine the amount of radians needed to change
	else if((target_rotation-current_rotation)<-M_PI)return ((target_rotation-current_rotation)+(2*M_PI));//Determine the amount of radians needed to change
}

double simulation(double current_rotation, double target_rotation, double radian_change){//Simulates wheel rotation
	double decimal_difference;
	for(int i=-1;i<abs(radian_change);i++){//Simulates the wheel rotation
		if(i==-1)i++;
		if(i==0)cout<<"At "<<current_rotation<<" radians."<<endl;//Prints the starting rotation
		if(radian_change<0){//Simulates negative change
			decimal_difference=target_rotation-current_rotation;//Sets and corrects the difference of current and target rotations for fractional calculation
			if(decimal_difference>M_PI)decimal_difference=target_rotation-current_rotation-(2*M_PI);//Ensures it will calculate in the right direction
			if(decimal_difference>-1 && decimal_difference<0){//Changes wheel rotation for cases when the difference is less than one radian.
				current_rotation=target_rotation;
				cout<<"At "<<current_rotation<<" radians."<<endl;
				return current_rotation;
			}
			current_rotation--;
			current_rotation=correct_radian_form(current_rotation);
			cout<<"At "<<current_rotation<<" radians."<<endl;
		}
		else if(radian_change>0){//Simulates positive change
			decimal_difference=correct_radian_form(target_rotation-current_rotation);//Sets and corrects the difference of current and target rotations for fractional calculation 
			if(decimal_difference>0 && decimal_difference<1){//Changes wheel rotation for cases when the difference is less than one radian.
				current_rotation=target_rotation;
				cout<<"At "<<current_rotation<<" radians."<<endl;
				return current_rotation;
			}
			current_rotation++;
			current_rotation=correct_radian_form(current_rotation);
			cout<<"At "<<current_rotation<<" radians."<<endl;
		}
	}
	return current_rotation;
}

int main(){
	Wheel_rotation wheel_l;
	Wheel_rotation wheel_b;
	Wheel_rotation wheel_r;
	cout<<endl<<"What is the current wheel rotation?(l) ";//Prompts the user for current wheel rotation
	cin>>wheel_l.target_rotation;
	wheel_l.current_rotation=correct_radian_form(wheel_l.target_rotation);
	cout<<"What is the target wheel rotation?(l) ";//Prompts the user for current wheel rotation
	cin>>wheel_l.target_rotation;
	cout<<endl;
	wheel_l.target_rotation=correct_radian_form(wheel_l.target_rotation);
	wheel_l.radian_change=determine_change(wheel_l.current_rotation, wheel_l.target_rotation);
	wheel_l.current_rotation=simulation(wheel_l.current_rotation, wheel_l.target_rotation, wheel_l.radian_change);//Returns current_rotation after simulation
	return 0;
}