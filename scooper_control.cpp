//Author: Logan Traffas
#include <iostream>
#include <vector>

using namespace std;

enum class Scooper_control{UP, STOP, DOWN};
enum class Sensor_states{UP, DOWN, INBETWEEN, ERROR};

ostream& operator<<(ostream & o, Scooper_control b){
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

ostream& operator<<(ostream & o, Sensor_states b){
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

Scooper_control motor_control(Scooper_control scooper_control, Sensor_states sensor_states){//Determines what to do with the motor.
	Scooper_control motor_state;
	if(scooper_control==Scooper_control::STOP){
		motor_state=Scooper_control::STOP;
	}
	else if(scooper_control==Scooper_control::UP && sensor_states!=Sensor_states::UP && sensor_states!=Sensor_states::ERROR){
		motor_state=Scooper_control::UP;
	}
	else if(scooper_control==Scooper_control::UP && sensor_states==Sensor_states::UP){
		motor_state=Scooper_control::STOP;
	}
	else if(scooper_control==Scooper_control::DOWN && sensor_states!=Sensor_states::DOWN && sensor_states!=Sensor_states::ERROR){
		motor_state=Scooper_control::DOWN;
	}
	else if(scooper_control==Scooper_control::DOWN && sensor_states==Sensor_states::DOWN){
		motor_state=Scooper_control::STOP;
	}
	else if(sensor_states==Sensor_states::ERROR){
		motor_state=Scooper_control::STOP;
	}
	return motor_state;
}

int main(){
	Scooper_control motor_state=Scooper_control::STOP;
	vector<Scooper_control> v_scooper_control;
	vector<Sensor_states> v_sensor_states;
	for(unsigned int i=0; i<4; i++){
		v_scooper_control.push_back(Scooper_control::UP);
	}
	for(unsigned int i=0; i<4; i++){
		v_scooper_control.push_back(Scooper_control::DOWN);
	}
	for(unsigned int i=0; i<4; i++){
		v_scooper_control.push_back(Scooper_control::STOP);
	}
	for(unsigned int i=0; i<3; i++){
		v_sensor_states.push_back(Sensor_states::UP);
		v_sensor_states.push_back(Sensor_states::DOWN);
		v_sensor_states.push_back(Sensor_states::INBETWEEN);
		v_sensor_states.push_back(Sensor_states::ERROR);
	}
	for(unsigned int i=0; i<12; i++){
		motor_state=motor_control(v_scooper_control[i], v_sensor_states[i]);
		cout<<motor_state<<endl;
	}
	return 0;
}