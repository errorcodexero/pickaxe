/*----------------------------------------------------------------------------------------------------------------------
BEFORE READING CODE!!
GO TO THE MAIN, IT DESCRIBES WHY THINGS ARE THE WAY THEY ARE!!
----------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include<math.h>

using namespace std;

float convert(float variable, bool type){ 
	//This function needs a variable to convert and needs to know if the variable is in degrees or radians.
	//This function returns a variable of the opposite type as the one specified!
	//If type == 0 -> variable is a degree!
	//If type == 1 -> variable is a radian!
	float returnvar;
	
	if(type == 0){
		returnvar = variable(pi/180);
	} else {
		returnvar = variable(180/pi);
	}
	
	return returnvar;
}

float strafeControl(float ljx, float ljy){
	//Strafing is controlled by the left joystick. This function outputs all the wheels' directions in degrees.
	float strafedirection;
	strafedirection = float atanf(ljy/ljx);
	
}

int main(){
	//Button variables - the physical button inputs are represented as variables
		bool a;
		bool b;
		bool x;
		bool y;
		bool r1;
		float r2;
		bool l1;
		float l2;
		bool start;
		float ljx; //left joystick x-axis
		float ljy; //left joystick y-axis
		float rjx; //right joystick x-axis
		float rjy; //right joystick y-axis
	//unknown/unable to declare a variable type for the input
		// ___ D-pad;
	//Wheel variables are represented here 
		//speed variables are measured in %, that way Logan and Matthew can know how fast each wheel needs to go based off the top speed they define.
		//theta variables are measured in degrees, but are calculated in radians. A conversion function is used for that purpose.
		float lwspeed;
		float lwtheta;
		float rwspeed;
		float rwtheta;
		float bwspeed;
		float bwtheta;
	
	
	
}