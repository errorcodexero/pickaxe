#include <iostream>
#include <math.h>
#include <vector>
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

Drivebase_goal swerve_goals(float joy_x, float joy_y, float joy_theta){
	Drivebase_goal d;
	d.mod[0].angle=1;
	d.mod[0].speed=1;
	d.mod[1].angle=1;
	d.mod[1].speed=1;
	d.mod[2].angle=1;
	d.mod[2].speed=1;	
	return d;
}


int main(){
	Drivebase_goal testd;
	testd=swerve_goals (1,0,0);
	cout<<testd<<endl;
	vector<Testcase> testcasetest;	
	testcasetest[0].joy_x=1;
	testcasetest[0].joy_y=1;
	testcasetest[0].joy_theta=1;
	testcasetest[1].joy_x=1;
	testcasetest[1].joy_y=1;
	testcasetest[1].joy_theta=1;
	testcasetest[2].joy_x=1;
	testcasetest[2].joy_y=1;
	testcasetest[2].joy_theta=1;
	
}
