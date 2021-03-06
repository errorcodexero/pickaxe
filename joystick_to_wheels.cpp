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
	if(type == 0){
		return variable*(M_PI/180);
	}
	return variable*(180/M_PI);
}

float strafeControl(float ljx, float ljy, bool type, float stoptrigger){
	//Strafing is controlled by the left joystick. This function outputs all the wheels' directions in degrees.
	//type determines if the function is computing degree of wheels, or speed of wheels.
	//type == 0 -> degree.
	//type == 1 -> speed.	
	float calc = atanf(ljy/ljx);
	float degree = convert(calc, 1);;
	float speed = sqrtf((powf(ljx, 2)) + (powf(ljy, 2)));
	float returnvar;
	
	if(stoptrigger > 0){
		speed = 0;
	}
	if(type == 0){
		returnvar = degree;
	} else {
		returnvar = speed;
	}
	return returnvar;
}

int main(){
	//Button variables - the physical button inputs are represented as variables
		//bool a;
		//bool b;
		//bool x;
		//bool y;
		//bool r1;
		float r2;
		//bool l1;
		float l2; //trigger is for all stop.
		//bool start;
		float ljx; //left joystick x-axis
		float ljy; //left joystick y-axis
		float rjx; //right joystick x-axis
		float rjy; //right joystick y-axis
	//Wheel variables are represented here 
	//speed variables are measured in %, that way Logan and Matthew can know how fast each wheel needs to go based off the top speed they define.
	//theta variables are measured in degrees, but are calculated in radians. A conversion function is used for that purpose.
		
		ljx = 30;
		ljy = 30;
		l2 = 0;
		
		float lwspeed = strafeControl(ljx, ljy, 1, l2);
		float lwtheta = strafeControl(ljx, ljy, 0, l2);
		float rwspeed = strafeControl(ljx, ljy, 1, l2);
		float rwtheta = strafeControl(ljx, ljy, 0, l2);
		float bwspeed = strafeControl(ljx, ljy, 1, l2);
		float bwtheta = strafeControl(ljx, ljy, 0, l2);
		
	//Testing Simulator - This area is for testing blocks of code.
		int count = 10;
	
		cout<<"lwspeed"<<"	"<<"lwtheta"<<"	"<<"rwspeed"<<"	"<<"rwtheta"<<"	"<<"bwspeed"<<"	"<<"bwtheta\n";
		while(count != 0){
			cout<<lwspeed<<"	"<<lwtheta<<"	"<<rwspeed<<"	"<<rwtheta<<"	"<<bwspeed<<"	"<<bwtheta<<"\n";
			count--;
		}
		
		/*
		float rwd = strafeControl(ljx, ljy, 0, l2);
		float rws = strafeControl(ljx, ljy, 1, l2);
		float rd ;
		cout<<"rwd"<<"	"<<"rws"<<"	"<<"rd\n";
		*/
}