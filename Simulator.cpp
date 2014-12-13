/*--------------------------------
WARNING! THIS CODE DISPLAYS A TABLE IN THE CONSOLE!!
CONSOLE MAY NEED TO BE ENLARGED TO THE ENTIRE TABLE RENDERS CORRECTLY!!
--------------------------------*/

#include<iostream>
#include<math.h>

using namespace std;

struct ROBOTVAR{
	static float robot[3];
	static float currentangles[3];
	static float motorturnpowers[3];
	static float wheelspeeds[3];
	static float timestep[1];
} ROBOT;


void tableMaker(float robot[3], float currentangles[3], float motorturnpowers[3], float wheelspeeds[3], float timestep[1]){
	cout<<"Table\n\n";
	float count = 0;
	cout<<"Time"<<"	"<<"|"<<"	"<<"Robot"<<"	"<<"	"<<"|"<<"	"<<"Current angles"<<"	"<<"|"<<"	"<<"Turn powers"<<"	"<<"|"<<"	"<<"Current speeds"<<"	"<<"|"<<"\n";
	cout<<"Time"<<"	"<<"|"<<"X"<<"	"<<"Y"<<"	"<<"Theta"<<"	"<<"|"<<"LW"<<"	"<<"RW"<<"	"<<"BW"<<"	"<<"|"<<"LW"<<"	"<<"RW"<<"	"<<"BW"<<"	"<<"|"<<"LW"<<"	"<<"RW"<<"	"<<"BW"<<"	"<<"|\n";
	while(count != 10){
		float time = timestep[0] * count;
		cout<<time<<"	"<<"|"<<robot[0]<<"	"<<robot[1]<<"	"<<robot[2]<<"	"<<"|"<<currentangles[0]<<"	"<<currentangles[1]<<"	"<<currentangles[2]<<"	"<<"|"<<motorturnpowers[0]<<"	"<<motorturnpowers[1]<<"	"<<motorturnpowers[2]<<"	"<<"|"<<wheelspeeds[0]<<"	"<<wheelspeeds[1]<<"	"<<wheelspeeds[2]<<"	"<<"|";
		count++;
	}
}

int main(){
	float rwtheta;
	float rwspeed;
	float lwtheta;
	float lwspeed;
	float bwtheta;
	float bwspeed;
	
	float robottheta;
	float robotstrafe;
	float robotrotation;
	
	ROBOT.timestep[0] = 1;
	
	ROBOT.robot[0] = 30;
	ROBOT.robot[1] = 40;
	ROBOT.robot[2] = 50;
	
	ROBOT.currentangles[0] = 10;
	ROBOT.currentangles[1] = 20;
	ROBOT.currentangles[2] = 30;
	
	ROBOT.motorturnpowers[0] = 5;
	ROBOT.motorturnpowers[1] = 10;
	ROBOT.motorturnpowers[2] = 15;
	
	ROBOT.wheelspeeds[0] = 1;
	ROBOT.wheelspeeds[1] = 2;
	ROBOT.wheelspeeds[2] = 3;
	
	tableMaker(*ROBOT.robot, *ROBOT.currentangles, *ROBOT.motorturnpowers, *ROBOT.wheelspeeds, *ROBOT.timestep);
}