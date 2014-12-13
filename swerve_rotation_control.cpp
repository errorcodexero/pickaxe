//Author: Logan Traffas *****Unfinished***** Function: Simulates wheel movement given current and target positions (the current units are radians). Also determines the current wheel rotation given encoder output.
#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <vector>
#include <assert.h>

#ifndef M_PI//Defines a variable for pi if the variable does not exist
#define M_PI 3.141592653589793238462643383
#endif

using namespace std;

double correct_radian_form(double input){//Corrects to the correct radian form (i.e. 0-(2*pi))
	while(input<0)input+=(2*M_PI);
	while(input>(2*M_PI))input-=(2*M_PI);
	return input;
}

double determine_change(double current_rotation, double target_rotation){//Determine the amount of radians needed to change
	if(target_rotation-current_rotation==0 || target_rotation-current_rotation==(2*M_PI))return 0;//Calculates the direction and magnitude of radian change
	else if(current_rotation==-M_PI)return M_PI;//Corrects for preferred direction when direction and magnitude are equal
	else if(target_rotation-current_rotation<=M_PI && target_rotation-current_rotation>-M_PI)return (target_rotation-current_rotation);//Determine the amount of radians needed to change
	else if(target_rotation-current_rotation>M_PI)return ((target_rotation-current_rotation)-(2*M_PI));//Determine the amount of radians needed to change
	else if(target_rotation-current_rotation<-M_PI)return ((target_rotation-current_rotation)+(2*M_PI));//Determine the amount of radians needed to change
	else{
		cout<<endl<<"ERROR IN DETERMINING CHANGE."<<endl;
		return 0;
	}
}

double correct_rotating_form(double current_rotation){//During wheel turn, this will correct to radian form (i.e. 0-(2*pi))
	if(current_rotation<0)current_rotation+=(2*M_PI);//Changes negative values into the correct form
	else if(current_rotation>(2*M_PI))current_rotation-=(2*M_PI);//Changes numbers greater than (2*M_PI) radians into the correct form
	else if(current_rotation==(2*M_PI) || current_rotation==-(2*M_PI))current_rotation=0;//Changes numbers at (2*M_PI) radians into the correct form
	else{
		cout<<endl<<"ERROR IN DETERMINING CHANGE."<<endl;
		return 0;
	}
	return current_rotation;
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
			current_rotation=correct_rotating_form(current_rotation);
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
			current_rotation=correct_rotating_form(current_rotation);
			cout<<"At "<<current_rotation<<" radians."<<endl;
		}
	}
	return current_rotation;
}

struct Encoder_output{bool a,b;};//This is a type for the input received from the encoder -- "a" (pin two) and "b" (pin four)

struct Encoder_return{
	double estimated_rotation;
	unsigned int time;
	Encoder_output states;
};

ostream & operator<<(ostream & o, Encoder_output in){//Outputs from the vector if type Input the states of the a and b channels as this code interprets it
	o<<in.a<<" | "<<in.b;
	return o;
}

vector<Encoder_output> encoder_states;
Encoder_output channel_value;

Encoder_return current_rotation_direction(Encoder_return encoder_return){//Uses the order of channel outputs for pins two (a) and four (b) to determine wheel rotating direction and estimates the amount of rotational change
	channel_value.a=encoder_return.states.a;
	channel_value.b=encoder_return.states.b;
	encoder_states.push_back(channel_value);
	assert(encoder_return.time<encoder_states.size());
	bool now_a=encoder_states[encoder_return.time].a, now_b=encoder_states[encoder_return.time].b, pre_a=0, pre_b=0;
	if(encoder_states.size()>0){
		if(encoder_return.time>0){
			assert(encoder_return.time-1<encoder_states.size());
			pre_a=encoder_states[encoder_return.time-1].a; 
			pre_b=encoder_states[encoder_return.time-1].b;
		}
	}
	if((encoder_return.time!=0) && (now_a==pre_a && now_b==pre_b)){
		//Null. Nothing has changed.
	}
	else if((((encoder_return.time!=0) && (now_a==0 && now_b==0) && (pre_a==0 && pre_b==1)) || ((encoder_return.time!=0) && (now_a==1 && now_b==1) && (pre_a==1 && pre_b==0))) || (((now_a==1 && now_b==0) && (pre_a==0 && pre_b==0)) || ((now_a==0 && now_b==1) && (pre_a==1 && pre_b==1)))){//Determines if wheel is rotating clockwise
		encoder_return.estimated_rotation+=M_PI;
	}
	else if((((encoder_return.time!=0) && (now_a==0 && now_b==0) && (pre_a==1 && pre_b==0)) || ((encoder_return.time!=0) && (now_a==1 && now_b==1) && (pre_a==0 && pre_b==1))) || (((now_a==0 && now_b==1) && (pre_a==0 && pre_b==0)) || ((now_a==1 && now_b==0) && (pre_a==1 && pre_b==1)))){//Determines if wheel is rotating counter-clockwise
		encoder_return.estimated_rotation-=M_PI;
	}
	encoder_return.time++;
	return encoder_return;
}

int main(){
	std::cout<<std::setprecision(5)<<std::fixed;
	Encoder_return encoder_return;
	encoder_return.time=0;
	encoder_return.states.a=0;
	encoder_return.states.b=0;
	cout<<"time   | a | b | estimated rotation"<<endl;
	for(unsigned int i; i<10; i++){
		encoder_return=current_rotation_direction(encoder_return);
		if(encoder_return.time<10){
			assert(encoder_return.time-1>=0 && encoder_return.time-1<encoder_states.size());
			cout<<"  "<<encoder_return.time<<"    | "<<encoder_states[encoder_return.time-1]<<" | "<<encoder_return.estimated_rotation<<endl;//***Unnecessary after simulation***
		}
		else if(encoder_return.time<100)cout<<"  "<<encoder_return.time<<"   | "<<encoder_states[encoder_return.time-1]<<" | "<<encoder_return.estimated_rotation<<endl;
		else if (encoder_return.time<1000)cout<<"  "<<encoder_return.time<<"  | "<<encoder_states[encoder_return.time-1]<<" | "<<encoder_return.estimated_rotation<<endl;
		else{
			cout<<"  "<<encoder_return.time<<" | "<<encoder_states[encoder_return.time-1]<<" | "<<encoder_return.estimated_rotation<<endl;
		}
	}
	cout<<endl<<encoder_states[4]<<endl;
	/*double current_rotation, target_rotation, radian_change;
	cout<<endl<<"What is the current wheel rotation? ";//Prompts the user for current wheel rotation
	cin>>current_rotation;
	current_rotation=correct_radian_form(current_rotation);
	cout<<"What is the target wheel rotation? ";//Prompts the user for current wheel rotation
	cin>>target_rotation;
	cout<<endl;
	target_rotation=correct_radian_form(target_rotation);
	radian_change=determine_change(current_rotation, target_rotation);
	current_rotation=simulation(current_rotation, target_rotation, radian_change);//Returns current_rotation after simulation*/
	return 0;
}