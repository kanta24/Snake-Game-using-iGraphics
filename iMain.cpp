/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/



#include<iostream>
# include "iGraphics.h"
#include <time.h>
int rollingValue;
int ic, i, j;


//#define screenwidth 1000;
//#define screenheight 600;

int mposx,  mposy;
int x = 0;
int y = 0;
int HEIGHT = 544;
int WIDTH = 1080;
char snlDice[6][20] = { "snl\\1.bmp", "snl\\2.bmp", "snl\\3.bmp", "snl\\4.bmp", "snl\\5.bmp", "snl\\6.bmp" };
//char snlGuti[2][20] = { "snl\\g1.bmp" };
int snlDiceCoordinateX = 920;
int snlDiceCoordinateY = 350;
int snlDiceIndex=0 ;
int snlGuti_X = 15, snlGuti_Y =10;
int snlGuti_X1 , snlGuti_Y1 ;
int snlGutiIndex = 0;


/*
	function iDraw() is called again and again by the system.
*/

bool dice=false;
bool dice_Running = false;


void diceRunning(){
	snlGuti_X = snlGuti_X +( 80 * rollingValue);

	iShowBMP2(snlGuti_X, snlGuti_Y, "snl\\g1.bmp", 255);

	dice_Running = false;
	rollingValue = 0;
	dice = false;
}


void diceChanging(){

	snlDiceIndex++;
	iShowBMP2(snlDiceCoordinateX, snlDiceCoordinateY, snlDice[snlDiceIndex], 255);

	if (snlDiceIndex == 5)
		snlDiceIndex = 0;

	if (snlDiceIndex+1  == rollingValue)
		dice = false;
	
}

/*void snlGutiCng(){
	snlGutiIndex++;
	iShowBMP(snlGuti_X, snlGuti_X,snl)
}*/




void iDraw()
{
	//place your drawing codes here
	iClear();

	
	iShowBMP(0, 0, "Back.bmp");
	iShowBMP(0, 0, "board.bmp");



	if (dice)
		diceChanging();
	else
		iShowBMP2(snlDiceCoordinateX, snlDiceCoordinateY, snlDice[snlDiceIndex], 0);

		
		if (dice_Running)
			diceRunning();
		else 
			iShowBMP2(snlGuti_X, snlGuti_Y, "snl\\g1.bmp", 255);
	

	

	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'r'){

		
		rollingValue = rand()%6;

		if (rollingValue > 0){
			dice_Running = true;
			dice = true;
			printf("%d", rollingValue);
		}
	}


}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
//

int main()
{
	srand((unsigned)time(NULL)); 

	iInitialize(WIDTH, HEIGHT, "Around The Town");
	
	return 0;
}
