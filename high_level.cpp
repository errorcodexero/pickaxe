#include <iostream>
#include <math.h>
//#include <stdlib>

using namespace std;

static const unsigned MODULES=3;

struct Module_goal{
	double angle; //rad
	double speed; //in-1to1
};

struct Drivebase_goal{
	Module_goal mod[MODULES];
};

Drivebase_goal swerve_goals(float joy_x, float joy_y, float joy_theta);

struct Testcase{
	double joy_x,joy_y,joy_theta;
	Drivebase_goal expected;
};

ostream& operator<<(ostream& o,Module_goal m){
	o<<"angle=  "<<m.angle<<endl;
	o<<"speed=  "<<m.speed<<endl;
}

ostream& operator<<(ostream& o,Drivebase_goal d){
	o<<"Modules=  "<<d.mod[MODULES]<<endl;
}

ostream& operator<<(ostream& o,Testcase t){
	o<<"joy x=  "<<t.joy_x<<endl;
	o<<"joy y=  "<<t.joy_y<<endl;
	o<<"joy theta=  "<<t.joy_theta<<endl;
}

int main(){
	
}
