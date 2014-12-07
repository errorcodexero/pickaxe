#include <iostream>
#include <math.h>
//#include <stdlib>

using namespace std;

Drivebase_goal swerve goals(float joy_x, float joy_y, float joy_theta);

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



ostream& operator<<(ostream& o,Testcase){
	o<<"joy x=  "<<joy_x<<endl;
	o<<"joy y=  "<<joy_y<<endl;
	o<<"joy theta=  "<<joy_theta<<endl;
}




int main(){
	
}