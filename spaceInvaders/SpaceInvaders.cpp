#define NUM_OPENGL_LIGHTS 8

//Author: Matt Engman, Logan Parmeter

//#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <gl/glew.h>
#include <GL/glew.h>
#include <freeglut.h>
#include "Shape.h"
#include "Cube.h"
#include "Camera.h"
#include "Plane.h"
#include "Player.h"
#include "GameControl.h"
#include "LaserControl.h"
#include "AlienControl.h"
#include "BarrierControl.h"
#include "Stars.h"
#include "Stats.h"

using namespace std;

/** These are the live variables passed into GLUI ***/
int  segmentsX = 1;
int  segmentsY = 1;
int score;
bool inGame = false;
int	 camRotU = 0;
int	 camRotV = 0;
int	 camRotW = 0;
int  viewAngle = 45;
int	 camAngle = 0;
float radAngle = 0.0;
float eyeX = 2;
float eyeY = 2;
float eyeZ = 2;
float lookX = -2;
float lookY = -2;
float lookZ = -2;

float player_speed = 0.125;
float player_x = 0.0;
float player_y = -1.0;
float player_z = 2.0;

/** These are GLUI control panel objects ***/
int  main_window;
string gameText1 = "Welcome to Space Invaders!";
string gameText2 = "Controls:";
string gameText3 = "Use 'a' and 'd' to move left and right";
string gameText3b = "Use 'w' and 's' to move up and down (M/H)";
string gameText4 = "Use space to fire your laser";
string gameText5 = "Use 'q' and 'e' to rotate the camera";
string gameText6 = "Thanks for playing!";
string gameTextSpace = " ";
string passText = "Enter Password: ";
string password = "";
int curLevel = 1;
int setLevels = 0;

/** these are the global variables used for rendering **/
Cube* cube = new Cube();
LaserControl lasers;
AlienControl aliens;
GameControl control;
BarrierControl barriers;
Stats* stats = new Stats();
Stars* stars = new Stars(7.0, 7.0, 7.0, 1000);
Plane* plane = new Plane(10.0, 0.1, 10.0);
Player* player = new Player(player_x, player_y, player_z, player_speed);
Shape* shape = NULL;
Camera* camera = new Camera();

void setupCamera();

void callback_start(int id) {
	control.setMode(id);
	control.setDiff(setLevels + 1);
	control.spawn(aliens);
	player->setLives(control.getDiff());
	barriers.create(control.getDiff());
	score = 0;
	inGame = true;
}

/*********************************************************
callback_boss()
Skip to boss level
**********************************************************/

void callback_boss(int id)
{
	if (password == "epicboss")
	{
		control.setMode(id);
		control.setDiff(setLevels + 1);
		control.setLevel(4);
		control.spawnBoss(aliens);
		player->setLives(control.getDiff());
		barriers.create(control.getDiff());
		score = 0;
		inGame = true;
	}
	else
	{
		control.setMode(id);
		control.setDiff(setLevels + 1);
		control.spawn(aliens);
		player->setLives(control.getDiff());
		barriers.create(control.getDiff());
		score = 0;
		inGame = true;
	}
}

/***************************************** myGlutIdle() ***********/

void myGlutIdle(void)
{
	/* According to the GLUT specification, the current window is
	undefined during an idle callback.  So we need to explicitly change
	it if necessary */
	if (glutGetWindow() != main_window)
		glutSetWindow(main_window);

	glutPostRedisplay();
}


/**************************************** myGlutReshape() *************/

void myGlutReshape(int x, int y)
{
	float xy_aspect;

	xy_aspect = (float)x / (float)y;
	glViewport(0, 0, x, y);

	camera->SetScreenSize(x, y);

	glutPostRedisplay();
}


/***************************************** setupCamera() *****************/
void setupCamera()
{
	camera->Reset();  //note that this is a new function. Be sure to set values for near and far plane!
	camera->SetViewAngle(70);
	camera->Orient(Point(0, 2, 6), Point(0, 0, -1), Vector(0, 1, 0));

	viewAngle = camera->GetViewAngle();
	Point eyeP = camera->GetEyePoint();
	Vector lookV = camera->GetLookVector();
	eyeX = eyeP[0];
	eyeY = eyeP[1];
	eyeZ = eyeP[2];
	lookX = lookV[0];
	lookY = lookV[1];
	lookZ = lookV[2];
	camRotU = 0;
	camRotV = 0;
	camRotW = 0;
	GLUI_Master.sync_live_all();
}


/***************************************** myGlutDisplay() *****************/

void myGlutDisplay(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera->SetViewAngle(viewAngle);
	glMatrixMode(GL_PROJECTION);
	Matrix projection = camera->GetProjectionMatrix();
	glLoadMatrixd(projection.unpack());

	camera->Orient(Point(eyeX, eyeY, eyeZ), Point(0, 0, 0), Vector(0, 1, 0));
	camera->RotateV(camRotV);
	camera->RotateU(camRotU);
	camera->RotateW(camRotW);
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(camera->GetModelViewMatrix().unpack());

	Matrix compositeMatrix;

	//draw and play the game
	if (inGame)
	{
		stars->draw();
		if (player->collide(lasers.laserList))
		{
			player->decLives();
		}
		aliens.collide(lasers.laserList, score);
		barriers.collide(lasers.laserList);
		barriers.draw();
		player->draw();
		stats->drawScore(player->getLocX(), player->getLocY(), player->getLocZ(), score);
		stats->drawHealth(player->getLocX(), player->getLocY(), player->getLocZ(), player->getLives());
		
		player->decFire();
		aliens.nextState();
		if (control.isBossfight())
		{
			aliens.bossMove(player);
			control.killboss(aliens, lasers, player);
		}
		else
		{
			aliens.move();
			control.shoot(aliens, lasers, player);
		}
		aliens.draw();
		lasers.move();
		lasers.draw();
	}
	else
	{
		aliens.aliens.clear();
		lasers.laserList.clear();
	}
	if (player->getLives() <= 0)
	{
		inGame = false;
	}
	if (control.checkEnd())
	{
		inGame = false;
	}
	if (aliens.empty() && inGame)
	{
		aliens.aliens.clear();
		lasers.laserList.clear();
		control.spawn(aliens);
	}
	else if (control.getMode() == 1)
	{
		aliens.respawn();
	}

	glEnable(GL_LIGHTING);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_LIGHTING);

	camera->RotateV(-camRotV);
	camera->RotateU(-camRotU);
	camera->RotateW(-camRotW);

	glutSwapBuffers();
}

void onExit()
{
	delete cube;
	delete camera;
}

/**************************************************************
rotateCameraLeft
Rotates the camera view
***************************************************************/
void rotateCameraLeft() {
	camAngle++;
	radAngle = (PI / 180) * camAngle;
	eyeZ = cos(radAngle) * 6;
	eyeX = sin(radAngle) * 6;
}

/**************************************************************
rotateCameraLRight
Rotates the camera view
***************************************************************/
void rotateCameraRight() {
	camAngle--;
	radAngle = (PI / 180) * camAngle;
	eyeZ = cos(radAngle) * 6;
	eyeX = sin(radAngle) * 6;
}

/***************************************************************
keyboardInput
This function gets keyboard input from the player
****************************************************************/
void keyboardInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		//rotate camera left
		rotateCameraLeft();
		break;
	case 'e':
		//rotate camera right
		rotateCameraRight();
		break;
	case 'a':
		//move player left
		if (player->getLocX() > -4.5)
		{
			player->move(player_speed, 1);
		}
		break;
	case 'd':
		//move player right
		if (player->getLocX() < 4.5)
		{
			player->move(player_speed, 0);
		}
		break;
	case 'w':
		//move player up level
		if (curLevel < control.getDiff())
		{
			curLevel++;
			float temp = player->getLocY();
			temp += 1.0;
			player->setLocY(temp);
		}
		break;
	case 's':
		//move player down level
		if (curLevel > 1)
		{
			curLevel--;
			float temp = player->getLocY();
			temp -= 1.0;
			player->setLocY(temp);
		}
		break;
	case 32:
		//fire laser
		if (player->getNumFire() == 0)
		{
			lasers.create(player->getLocX(), player->getLocY(), player->getLocZ(), false);
			player->resetFire();
		}
		break;
	}
}

/**************************************** main() ********************/

int main(int argc, char* argv[])
{
	atexit(onExit);

	/****************************************/
	/*   Initialize GLUT and create window  */
	/****************************************/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1600, 900);

	main_window = glutCreateWindow("Space Invaders!");
	glutDisplayFunc(myGlutDisplay);
	glutReshapeFunc(myGlutReshape);
	glutKeyboardFunc(keyboardInput);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);

	setupCamera();

	/****************************************/
	/*       Set up OpenGL lighting         */
	/****************************************/


	glClearColor(0.38, 0.38, 0.38, 0.0);
	glShadeModel(GL_SMOOTH);

	GLfloat light_pos0[] = { 0.0f, 0.0f, 1.0f, 0.0f };
	GLfloat diffuse[] = { 0.5f, 0.5f, 0.5f, 0.0f };
	GLfloat ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos0);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glPolygonOffset(1, 1);



	/****************************************/
	/*         Here's the GLUI code         */
	/****************************************/

	GLUI* glui = GLUI_Master.create_glui("GLUI");

	glui->add_statictext(gameText1);
	glui->add_statictext(gameTextSpace);
	glui->add_statictext(gameText2);
	glui->add_statictext(gameText3);
	glui->add_statictext(gameText3b);
	glui->add_statictext(gameText4);
	glui->add_statictext(gameText5);
	glui->add_statictext(gameTextSpace);
	glui->add_statictext(gameText6);
	glui->add_statictext(gameTextSpace);

	GLUI_Listbox *listbox = glui->add_listbox("Set difficulty", &setLevels);
	listbox->add_item(0, "Easy");
	listbox->add_item(1, "Medium");
	listbox->add_item(2, "Hard");

	glui->add_statictext(gameTextSpace);
	GLUI_EditText *pass = glui->add_edittext(passText, password, 0, callback_boss);
	pass->set_w(100);
	glui->add_statictext(gameTextSpace);

	glui->add_button("Start Classic Mode", 0, callback_start);
	glui->add_button("Start Endless Mode", 1, callback_start);

	glui->add_button("Quit", 0, (GLUI_Update_CB)exit);

	glui->set_main_gfx_window(main_window);

	/* We register the idle callback with GLUI, *not* with GLUT */
	GLUI_Master.set_glutIdleFunc(myGlutIdle);

	glutMainLoop();

	return EXIT_SUCCESS;
}



