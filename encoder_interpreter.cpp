//Author: Logan Traffas
#include <iostream>
#include <iomanip>
#include <vector>
#include <assert.h>

#ifndef M_PI//Defines a variable for pi if the variable does not exist
#define M_PI 3.141592653589793238462643383
#endif

using namespace std;

struct Encoder_output{//This is a type for the input received from the encoder -- "a" (pin two) and "b" (pin four)
	bool a,b;
	Encoder_output():a(0),b(0){}
};

struct Encoder_return{//The important data values for each encoder are stored in this type
	char wheel;
	double estimated_rotation;
	unsigned int time;
	Encoder_output states;
	Encoder_return():estimated_rotation(0), time(0){}
};

ostream & operator<<(ostream & o, Encoder_output in){//Outputs from the vector if type Input the states of the a and b channels as this code interprets it
	o<<in.a<<" | "<<in.b;
	return o;
}

void print_encoder_values(Encoder_return encoder_return_l, vector<Encoder_output> encoder_states_l, Encoder_return encoder_return_b, vector<Encoder_output> encoder_states_b, Encoder_return encoder_return_r, vector<Encoder_output> encoder_states_r){//Prints out the values of a and b and the estimated rotation direction for each wheel over time
	assert(encoder_return_l.time-1>=0 && encoder_return_l.time-1<encoder_states_l.size());
	assert(encoder_return_b.time-1>=0 && encoder_return_b.time-1<encoder_states_b.size());
	assert(encoder_return_r.time-1>=0 && encoder_return_r.time-1<encoder_states_r.size());
	if(encoder_return_l.time<10){
		cout<<"  "<<encoder_return_l.time<<"        | "<<encoder_states_l[encoder_return_l.time-1]<<" | "<<encoder_return_l.estimated_rotation<<"                     | "<<encoder_states_b[encoder_return_b.time-1]<<" | "<<encoder_return_b.estimated_rotation<<"                     | "<<encoder_states_r[encoder_return_r.time-1]<<" | "<<encoder_return_r.estimated_rotation<<endl;
	}
	else if(encoder_return_l.time<100){
		cout<<"  "<<encoder_return_l.time<<"       | "<<encoder_states_l[encoder_return_l.time-1]<<" | "<<encoder_return_l.estimated_rotation<<"                     | "<<encoder_states_b[encoder_return_b.time-1]<<" | "<<encoder_return_b.estimated_rotation<<"                     | "<<encoder_states_r[encoder_return_r.time-1]<<" | "<<encoder_return_r.estimated_rotation<<endl;
	}
	else if (encoder_return_l.time<1000){
		cout<<"  "<<encoder_return_l.time<<"       | "<<encoder_states_l[encoder_return_l.time-1]<<" | "<<encoder_return_l.estimated_rotation<<"                     | "<<encoder_states_b[encoder_return_b.time-1]<<" | "<<encoder_return_b.estimated_rotation<<"                     | "<<encoder_states_r[encoder_return_r.time-1]<<" | "<<encoder_return_r.estimated_rotation<<endl;
	}
	else{
		cout<<"  "<<encoder_return_l.time<<"      | "<<encoder_states_l[encoder_return_l.time-1]<<" | "<<encoder_return_l.estimated_rotation<<"                     | "<<encoder_states_b[encoder_return_b.time-1]<<" | "<<encoder_return_b.estimated_rotation<<"                     | "<<encoder_states_r[encoder_return_r.time-1]<<" | "<<encoder_return_r.estimated_rotation<<endl;
	}
}

Encoder_output Channel_value(Encoder_return encoder_return){//Stores a and b values from the encoder in a vector for later use in determining wheel rotation direction
	Encoder_output channel_value;
	channel_value.a=encoder_return.states.a;
	channel_value.b=encoder_return.states.b;
	return channel_value;
}

Encoder_return current_rotation_direction(Encoder_return encoder_return, vector<Encoder_output> encoder_states){//Uses the order of channel outputs for pins two (a) and four (b) to determine wheel rotating direction and estimates the amount of rotational change
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
		encoder_return.estimated_rotation+=0.0261799388;
	}
	else if((((encoder_return.time!=0) && (now_a==0 && now_b==0) && (pre_a==1 && pre_b==0)) || ((encoder_return.time!=0) && (now_a==1 && now_b==1) && (pre_a==0 && pre_b==1))) || (((now_a==0 && now_b==1) && (pre_a==0 && pre_b==0)) || ((now_a==1 && now_b==0) && (pre_a==1 && pre_b==1)))){//Determines if wheel is rotating counter-clockwise
		encoder_return.estimated_rotation-=0.0261799388;
	}
	encoder_return.time++;
	return encoder_return;
}

int main(){
	std::cout<<std::setprecision(5)<<std::fixed;
	cout<<"time   l:  | a | b | estimated rotation      b:  | a | b | estimated rotation      r:  | a | b | estimated rotation"<<endl;
	
	Encoder_return encoder_return_b;//Back wheel encoder
	vector<Encoder_output> encoder_states_b;
	encoder_return_b.wheel='b';
	encoder_return_b.states.a=0;
	encoder_return_b.states.b=0;
	encoder_states_b.push_back(Channel_value(encoder_return_b));
	encoder_return_b=current_rotation_direction(encoder_return_b, encoder_states_b);
		
	Encoder_return encoder_return_l;//Left wheel encoder
	vector<Encoder_output> encoder_states_l;
	encoder_return_l.wheel='l';
	encoder_return_l.states.a=0;
	encoder_return_l.states.b=0;
	encoder_states_l.push_back(Channel_value(encoder_return_l));
	encoder_return_l=current_rotation_direction(encoder_return_l, encoder_states_l);
	
	Encoder_return encoder_return_r;//Right wheel encoder
	vector<Encoder_output> encoder_states_r;
	encoder_return_r.wheel='r';
	encoder_return_r.states.a=0;
	encoder_return_r.states.b=0;
	encoder_states_r.push_back(Channel_value(encoder_return_r));
	encoder_return_r=current_rotation_direction(encoder_return_r, encoder_states_r);
	
	print_encoder_values(encoder_return_l, encoder_states_l, encoder_return_b, encoder_states_b, encoder_return_r, encoder_states_r);//Prints out important data
	return 0;
}