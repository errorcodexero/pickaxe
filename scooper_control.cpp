//Author: Logan Traffas and Andrew Kassab.
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

enum class Scooper_control{UP, STOP, DOWN};//Values from control
enum class Sensor_states{UP, DOWN, INBETWEEN, ERROR};//Values for sensors that determine the arm's state

ostream& operator<<(ostream & o, Scooper_control b){//How to print this type
	if(b==Scooper_control::UP){
		o<<"UP";
	}
	else if(b==Scooper_control::STOP){
		o<<"STOP";
	}
	else if(b==Scooper_control::DOWN){
		o<<"DOWN";
	}
	return o;
}

ostream& operator<<(ostream & o, Sensor_states b){//How to print this type
	if(b==Sensor_states::UP){
		o<<"UP";
	}
	else if(b==Sensor_states::DOWN){
		o<<"DOWN";
	}
	else if(b==Sensor_states::INBETWEEN){
		o<<"INBETWEEN";
	}
	else if(b==Sensor_states::ERROR){
		o<<"ERROR";
	}
	return o;
}

ostream& operator<<(ostream & o, vector<Scooper_control> v){//How to print the vector
	unsigned int i=0;
	for(; i<v.size(); i++){
		o<<v[i]<<" ";
	}
	return o;
}

ostream& operator<<(ostream & o, vector<Sensor_states> v){//How to print the vector
	unsigned int i=0;
	for(; i<v.size(); i++){
		o<<v[i]<<" ";
	}
	return o;
}

Scooper_control motor_control(Scooper_control scooper_control, Sensor_states sensor_states){//Determines what to do with the motor.
	Scooper_control motor_state;
	if(scooper_control==Scooper_control::STOP){
		motor_state=Scooper_control::STOP;
		return motor_state;
	}
	else if(scooper_control==Scooper_control::UP && sensor_states!=Sensor_states::UP && sensor_states!=Sensor_states::ERROR){
		motor_state=Scooper_control::UP;
		return motor_state;
	}
	else if(scooper_control==Scooper_control::UP && sensor_states==Sensor_states::UP){
		motor_state=Scooper_control::STOP;	
		return motor_state;
	}
	else if(scooper_control==Scooper_control::DOWN && sensor_states!=Sensor_states::DOWN && sensor_states!=Sensor_states::ERROR){
		motor_state=Scooper_control::DOWN;
		return motor_state;
	}
	else if(scooper_control==Scooper_control::DOWN && sensor_states==Sensor_states::DOWN){
		motor_state=Scooper_control::STOP;
		return motor_state;
	}
	else if(sensor_states==Sensor_states::ERROR){
		motor_state=Scooper_control::STOP;
		return motor_state;
	}
	
	assert(0);

}

int main(){
	Scooper_control a = Scooper_control::UP;
	Sensor_states b = Sensor_states::UP;
	Scooper_control var = motor_control(a,b);
	
	Scooper_control motor_target = var;
	
	if (motor_target==Scooper_control::UP){
	//Move up 
	}
	else if (motor_target==Scooper_control::DOWN){
	//Move Down
	}
	else if (motor_target==Scooper_control::STOP){
	//Do nothing
	}
	
	Scooper_control motor_state=Scooper_control::STOP;//Declares all possible values for testing
	vector<Scooper_control> v_scooper_control;
	vector<Sensor_states> v_sensor_states;
	v_scooper_control.push_back(Scooper_control::UP);
	v_scooper_control.push_back(Scooper_control::DOWN);
	v_scooper_control.push_back(Scooper_control::STOP);
	v_sensor_states.push_back(Sensor_states::UP);
	v_sensor_states.push_back(Sensor_states::DOWN);
	v_sensor_states.push_back(Sensor_states::INBETWEEN);
	v_sensor_states.push_back(Sensor_states::ERROR);
	for(unsigned int i=0; i<v_scooper_control.size(); i++){
		Scooper_control i_v_scooper_control=v_scooper_control[i];
		for(unsigned int i=0; i<v_sensor_states.size(); i++){
			Sensor_states i_v_sensor_states=v_sensor_states[i];
			motor_state=motor_control(i_v_scooper_control, i_v_sensor_states);
			cout<<motor_state<<endl;
		}
	}
	return 0;
}