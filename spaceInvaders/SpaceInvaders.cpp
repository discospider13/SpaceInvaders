#define NUM_OPENGL_LIGHTS 8

//Author: Matt Engman, Logan Parmeter

//#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <GL/glui.h>
#include <freeglut.h>
#include "Shape.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Sphere.h"
#include "SceneParser.h"
#include "Camera.h"

using namespace std;

/** These are the live variables passed into GLUI ***/
int  wireframe = 0;
int  fillObj = 1;
int  segmentsX = 20;
int  segmentsY = 20;

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

/** These are GLUI control panel objects ***/
int  main_window;
string filenamePath = "data\\general\\ball.xml";
string gameText1 = "Welcome to Space Invaders!";
string gameText2 = "Controls:";
string gameText3 = "Use 'a' and 'd' to move left and right";
string gameText4 = "Use space to fire your laser";
string gameText5 = "Use 'q' and 'e' to rotate the camera";
string gameText6 = "Thanks for playing!";
string gameTextSpace = " ";
GLUI_EditText* filenameTextField = NULL;


/** these are the global variables used for rendering **/
Cube* cube = new Cube();
Cylinder* cylinder = new Cylinder();
Cone* cone = new Cone();
Sphere* sphere = new Sphere();
Shape* shape = NULL;
SceneParser* parser = NULL;
Camera* camera = new Camera();

void setupCamera();
void preOrderFill(SceneNode* node);
void preOrderWire(SceneNode* node);

void callback_load(int id) {
	if (parser != NULL) {
		delete parser;
	}
	parser = new SceneParser(filenamePath);
	cout << "success? " << parser->parse() << endl;

	setupCamera();
}

void renderShape(int shapeType) {
	switch (shapeType) {
	case SHAPE_CUBE:
		shape = cube;
		break;
	case SHAPE_CYLINDER:
		shape = cylinder;
		break;
	case SHAPE_CONE:
		shape = cone;
		break;
	case SHAPE_SPHERE:
		shape = sphere;
		break;
	case SHAPE_SPECIAL1:
		shape = cube;
		break;
	default:
		shape = cube;
	}
	shape->setSegments(segmentsX, segmentsY);
	shape->draw();
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
	camera->SetViewAngle(50);
	camera->Orient(Point(0, 5, 5), Point(0, 0, 0), Vector(0, 1, 0));

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



/***************************************** setLight() *****************/
void setLight(const SceneLightData &light)
{
	// Zero ambient light because the ambient light for the scene is
	// set with GL_LIGHT_MODEL_AMBIENT
	float zero[] = { 0, 0, 0, 0 };

	// There are 8 lights in OpenGL, GL_LIGHT0 to GL_LIGHT7, and
	// each GL_LIGHT* is one greater than the previous one.  This
	// means the nth light is GL_LIGHT0 + n.
	int id = GL_LIGHT0 + light.id;

	glLightfv(id, GL_AMBIENT, zero);
	glLightfv(id, GL_DIFFUSE, &light.color.r);
	glLightfv(id, GL_SPECULAR, &light.color.r);
	glLightf(id, GL_CONSTANT_ATTENUATION, light.function[0]);
	glLightf(id, GL_LINEAR_ATTENUATION, light.function[1]);
	glLightf(id, GL_QUADRATIC_ATTENUATION, light.function[2]);

	if (glIsEnabled(id))
		cout << "warning: GL_LIGHT" << light.id << " enabled more than once, not supposed to happen" << endl;

	switch (light.type)
	{
	case LIGHT_POINT:
	{
		// Convert from double[] to float[] and make sure the w coordinate is correct 
		float position[] = { light.pos[0], light.pos[1], light.pos[2], 1 };
		glLightfv(id, GL_POSITION, position);
		glEnable(id);
		break;
	}

	case LIGHT_DIRECTIONAL:
	{
		// Convert from double[] to float[] and make sure the direction vector is normalized (it isn't for a lot of scene files)
		Vector direction = -light.dir;
		direction.normalize();
		float position[] = { direction[0], direction[1], direction[2], direction[3] };
		glLightfv(id, GL_POSITION, position);
		glEnable(id);
		break;
	}
	}
}


/***************************************** applyMaterial() *****************/
void applyMaterial(const SceneMaterial &material)
{
	SceneGlobalData globalData;
	parser->getGlobalData(globalData);

	SceneMaterial material_local = material;
	material_local.cAmbient.r *= globalData.ka;
	material_local.cAmbient.g *= globalData.ka;
	material_local.cAmbient.b *= globalData.ka;
	material_local.cDiffuse.r *= globalData.kd;
	material_local.cDiffuse.g *= globalData.kd;
	material_local.cDiffuse.b *= globalData.kd;
	material_local.cSpecular.r *= globalData.ks;
	material_local.cSpecular.g *= globalData.ks;
	material_local.cSpecular.b *= globalData.ks;
	material_local.cReflective.r *= globalData.ks;
	material_local.cReflective.g *= globalData.ks;
	material_local.cReflective.b *= globalData.ks;
	material_local.cTransparent.r *= globalData.kt;
	material_local.cTransparent.g *= globalData.kt;
	material_local.cTransparent.b *= globalData.kt;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, &material_local.cAmbient.r);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &material_local.cDiffuse.r);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, &material_local.cSpecular.r);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, &material_local.cEmissive.r);
}


/***************************************** myGlutDisplay() *****************/

void myGlutDisplay(void)
{
	glClearColor(0.175f, 0.175f, 0.175f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (parser == NULL) {
		return;
	}

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

	//disable all the lights, and then enable each one...
	for (int i = 0; i < NUM_OPENGL_LIGHTS; i++) {
		glDisable(GL_LIGHT0 + i);
	}

	SceneNode* root = parser->getRootNode();
	Matrix compositeMatrix;

	//drawing the axes
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0); glVertex3f(1.0, 0, 0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0); glVertex3f(0.0, 1.0, 0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, 0); glVertex3f(0, 0, 1.0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	if (wireframe) {
		glDisable(GL_POLYGON_OFFSET_FILL);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		Matrix mv = camera->GetModelViewMatrix();
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixd(mv.unpack());
		preOrderWire(root);
	}

	glDisable(GL_COLOR_MATERIAL);
	int numLights = parser->getNumLights();
	for (int i = 0; i < numLights; i++) {
		SceneLightData lightData;
		parser->getLightData(i, lightData);
		setLight(lightData);
	}

	glEnable(GL_LIGHTING);
	if (fillObj == 1) {
		glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		preOrderFill(root);
	}
	glDisable(GL_LIGHTING);

	camera->RotateV(-camRotV);
	camera->RotateU(-camRotU);
	camera->RotateW(-camRotW);

	glutSwapBuffers();
}

// Apply transformation vectors
void applyTransform(SceneNode* node)
{
	double rad2deg = 180 / PI;
	// Look through all transformations
	for (int i = 0; i < node->transformations.size(); i++)
	{
		// Determine type and apply
		switch (node->transformations[i]->type)
		{
		case TRANSFORMATION_TRANSLATE: glTranslated(node->transformations[i]->translate[0], node->transformations[i]->translate[1], node->transformations[i]->translate[2]);
			break;
		case TRANSFORMATION_ROTATE: glRotated((node->transformations[i]->angle) * rad2deg, node->transformations[i]->rotate[0], node->transformations[i]->rotate[1], node->transformations[i]->rotate[2]);
			break;
		case TRANSFORMATION_SCALE: glScaled(node->transformations[i]->scale[0], node->transformations[i]->scale[1], node->transformations[i]->scale[2]);
			break;
		case TRANSFORMATION_MATRIX: glMultMatrixd(node->transformations[i]->matrix.unpack());
			break;
		}
	}
}

void preOrderWire(SceneNode* node)
{
	// Check if leaf and draw if so
	if (node->children.size() == 0)
	{
		glPushMatrix();
		applyTransform(node);
		renderShape(node->primitives.back()->type);
		glPopMatrix();
	}
	else
	{
		for (int i = 0; i < node->children.size(); i++)
		{
			glPushMatrix();
			applyTransform(node);
			preOrderWire(node->children[i]);
			glPopMatrix();
		}
	}
}

// same as above, but with applyMaterial for fill
void preOrderFill(SceneNode* node)
{
	if (node->children.size() == 0)
	{
		glPushMatrix();
		applyTransform(node);
		applyMaterial(node->primitives.back()->material);
		renderShape(node->primitives.back()->type);
		glPopMatrix();
	}
	else
	{
		for (int i = 0; i < node->children.size(); i++)
		{
			glPushMatrix();
			applyTransform(node);
			preOrderFill(node->children[i]);
			glPopMatrix();
		}
	}
}

void onExit()
{
	delete cube;
	delete cylinder;
	delete cone;
	delete sphere;
	delete camera;
	if (parser != NULL) {
		delete parser;
	}
}

void keyboardInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q': 
		camAngle++;
		radAngle = (PI / 180) * camAngle;
		eyeZ = cos(radAngle) * 5;
		eyeX = sin(radAngle) * 5;
		break;
	case 'e':
		camAngle--;
		radAngle = (PI / 180) * camAngle;
		eyeZ = cos(radAngle) * 5;
		eyeX = sin(radAngle) * 5;
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
	glutInitWindowSize(750, 750);

	main_window = glutCreateWindow("Space Invaders!");
	glutDisplayFunc(myGlutDisplay);
	glutReshapeFunc(myGlutReshape);
	glutKeyboardFunc(keyboardInput);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);

	// Specular reflections will be off without this, since OpenGL calculates
	// specular highlights using an infinitely far away camera by default, not
	// the actual location of the camera
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);

	// Show all ambient light for the entire scene (not one by default)
	GLfloat one[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, one);

	glPolygonOffset(1, 1);



	/****************************************/
	/*         Here's the GLUI code         */
	/****************************************/

	GLUI* glui = GLUI_Master.create_glui("GLUI");

	glui->add_statictext(gameText1);
	glui->add_statictext(gameTextSpace);
	glui->add_statictext(gameText2);
	glui->add_statictext(gameText3);
	glui->add_statictext(gameText4);
	glui->add_statictext(gameText5);
	glui->add_statictext(gameTextSpace);
	glui->add_statictext(gameText6);
	glui->add_statictext(gameTextSpace);

	glui->add_button("Start", 0, callback_load);

	glui->add_button("Quit", 0, (GLUI_Update_CB)exit);

	glui->set_main_gfx_window(main_window);

	/* We register the idle callback with GLUI, *not* with GLUT */
	GLUI_Master.set_glutIdleFunc(myGlutIdle);

	glutMainLoop();

	return EXIT_SUCCESS;
}



