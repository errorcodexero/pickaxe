#include <iostream>
#include <math.h>
#include <vector>
//#include <stdlib>
#include <string>
#include <stdio.h>

using namespace std;

static const unsigned MODULES=3;
//Module[0]=Back Module 
//Module[1]=Right Module
//Module[2]=Left Module

struct Module_goal{
	double angle; //rad
	double speed; //in-1to1
};

struct Drivebase_goal{
	Module_goal mod[MODULES];
};

struct Testcase{
	double joy_x,joy_y,joy_theta;
	Drivebase_goal expected;
};

ostream& operator<<(ostream& o,Module_goal m){
	o<<"angle=  "<<m.angle<<endl;
	o<<"speed=  "<<m.speed<<endl;
}

ostream& operator<<(ostream& o,Drivebase_goal d){
	o<<"Modules[0]="<<d.mod[0]<<endl;
	o<<"Modules[1]="<<d.mod[1]<<endl;
	o<<"Modules[2]="<<d.mod[2]<<endl;
}

ostream& operator<<(ostream& o,Testcase t){
	o<<"joy x=  "<<t.joy_x<<endl;
	o<<"joy y=  "<<t.joy_y<<endl;
	o<<"joy theta=  "<<t.joy_theta<<endl;
}

float findangle(float joy_x,float joy_y,float joy_theta){

}

float findspeed(float joy_x,float joy_y,float joy_theta){
	
}

Drivebase_goal swerve_goals(float joy_x, float joy_y, float joy_theta){
	Drivebase_goal d;
	d.mod[0].angle=0;
	d.mod[0].speed=joy_y;
	if (d.mod[0].speed>1)d.mod[0].speed=1;
	if (d.mod[0].speed<-1)d.mod[0].speed=-1;
	d.mod[1].angle=0;
	d.mod[1].speed=joy_y-joy_theta;
	if (d.mod[1].speed>1)d.mod[0].speed=1;
	if (d.mod[1].speed<-1)d.mod[0].speed=-1;
	d.mod[2].angle=0;
	d.mod[2].speed=joy_y+joy_theta;
	if (d.mod[2].speed>1)d.mod[0].speed=1;
	if (d.mod[2].speed<-1)d.mod[0].speed=-1;
	return d;
}


int main(){
	Drivebase_goal d;
	d=swerve_goals(.6,-.2,-.8);
	cout<<d<<endl;		
}




/*	Drivebase_goal testd;
	testd=swerve_goals (1,0,0);
	cout<<testd<<endl;
	string input;
	cout<<"Input joy_x"<<endl;
	cout<<"Input joy_y"<<endl;
	cout<<"Input joy_theta"<<endl;
	cin>>input;
	cout<<input<<endl;
	Testcase test;
	//test.joy_theta=input;
	vector<Testcase> testcasetest;	
	Testcase a;
	testcasetest.push_back(a);
	testcasetest.push_back(a);
	testcasetest.push_back(a);
	testcasetest[0].joy_x=1;
	testcasetest[0].joy_y=1;
	testcasetest[0].joy_theta=1;
	testcasetest[1].joy_x=1;
	testcasetest[1].joy_y=1;
	testcasetest[1].joy_theta=1;
	testcasetest[2].joy_x=1;
	testcasetest[2].joy_y=1;
	testcasetest[2].joy_theta=1; 
	
double theta_return(double joy_x, double joy_y){
	double hypotenuse=plug (joy_x,joy_y) and (0,0) into the distance formula;
	double adjacent=x_joy;
	double joy_theta=cos or sin using the above variables
	return joy_theta;
}
*/