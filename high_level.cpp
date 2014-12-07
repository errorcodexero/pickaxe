#include <iostream>
#include <math.h>
#include <std>

using namespace std;

struct Testcase{
	double joy_x,joy_y,joy_theta;
	Drivebase_goal expected;
};

static const unsigned MODULES=3;
struct Module_goal{
	double angle; //rad
	double speed; //in-1to1
};

struct Drivebase_goal{
	Module_goal mod[MODULES];
};

Drivebase_goal swerve goals(float joy_x, float joy_y, float joy_theta);

int main(){
	
}