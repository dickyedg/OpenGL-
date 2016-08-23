
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <glut.h>

#include "texture.h"
#include "cat.h"
#include "troli.h"
#include "kalajengking.h"
#include "semut.h"
#include "texture.h"
#include "lighting.h"
#include "Bird.h"

#define DEMO 100
#define INTERAKTIF 101

#define KUCING 22
#define KALAJENGKING 23
#define SEMUT 24

#ifndef M_PI
#define M_PI 3.14159265
#endif

// objek terpilih
int selected;

//camera parameter
GLfloat eyex = 0.0, eyey = 0.0, eyez =30.0,
centerx = 0.0, centery = 0.0, centerz = 0.0,
upx = 0.0, upy = 1.0, upz = 0.0;

GLfloat iX = eyex, iY = eyey, iZ = eyez, lX = 0, lY = 0, lZ = -30, uX = 0, uY = 1, uZ = 0;
float camAngle = 0;
float camAngle2 = 0;
float fraction = 0.05f;

// viewport
int SetupViewport(int cx, int cy)
{
	glViewport(0, 0, cx, cy);
	return 1;
}

// prespective
int SetupPerspectiveViewing(GLdouble aspect_ratio)
{
	gluPerspective(65.0f, aspect_ratio, 10.0f, -10.0f);
	return 1;
}

// viewing
int SetupViewingTransform()
{
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
	return 1;
}

// resize
void OnResizeWindow(int cx, int cy)
{
	GLdouble aspect_ratio;
	if (0 >= cx || 0 >= cy) return;
	SetupViewport(cx, cy);
	aspect_ratio = (GLdouble)cx / (GLdouble)cy;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	SetupPerspectiveViewing(aspect_ratio);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	SetupViewingTransform();
}

// update look at
void update_lookat() {

	OnResizeWindow(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

GLuint texwall;
GLuint texceil;
GLuint texfloor;

// draw room
void draw_room()
{
	if (!textureOn)
	{
		GLfloat ambient1[] = { 0.05375, 0.05, 0.06625, 1 };
		GLfloat diffuse1[] = { 0.18275, 0.17, 0.22525, 1 };
		GLfloat specular1[] = { 0.332741, 0.328634, 0.346435, 1 };
		GLfloat shine1 = 38.4;

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
		glMaterialf(GL_FRONT, GL_SHININESS, shine1);
	}
	else {
		material_color(1,1,1);
	}

	GLuint tex;

	glEnable(GL_TEXTURE_2D);

	if(textureOn) glBindTexture(GL_TEXTURE_2D, texfloor);

	/* Floor */
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-10, -10, -10);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(10, -10, -10);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(10, -10, 10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-10, -10, 10);
	glEnd();

	// texture atap

	if (textureOn) glBindTexture(GL_TEXTURE_2D, texceil);

	/* Ceiling */
	glBegin(GL_POLYGON);
	glNormal3f(0.0, -1.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-10, 10, -10);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(10, 10, -10);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(10, 10, 10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-10, 10, 10);
	glEnd();

	// texture tembok

	if (textureOn) glBindTexture(GL_TEXTURE_2D, texwall);

	/* Walls */
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-10, -10, -10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(10, -10, -10);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(10, 10, -10);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-10, 10, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(10, 10, 10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(10, -10, 10);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(10, -10, -10);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(10, 10, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-10, 10, 10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-10, -10, 10);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-10, -10, -10);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-10, 10, -10);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

// display function
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);

	// gambar
	glPushMatrix();

	// room
	draw_room();

	// shadow
	draw_shadow_cat();
	draw_shadow_troli();
	draw_shadow_kalajengking();
	draw_shadow_semut();
	draw_shadow_bird();

	// objek
	draw_cat(false);
    draw_troli(false);
    draw_semut(false);
    draw_Kalajengking(false);
	draw_bird(false);

	// lampu
	material_color(1, 1, 1);
	draw_lamp_depan();

	draw_lamp_ataskanan();
	draw_lamp_ataskiri();
	draw_lamp_atas();

	glPopMatrix();

	glutSwapBuffers();
}

static GLint mode_display = DEMO;

bool catcam = false;
bool kalacam = false;
bool semutcam = false;

float lastx = cat_pos_x;
float lasty = 0;
float lastz = cat_pos_z - 2;
float centercatx = 0.0;
float centercaty = 0.0;
float centercatz = 0.0;

float degcam = 0.5;
double tetha;

// cam cat
void objek_cam() {

	if (catcam) {
		eyex = cat_pos_x;
		eyey = cat_pos_y + 1;
		eyez = cat_pos_z;

		if (mode_display == DEMO) {

			centerx = centercatx;
			centery = centercaty;
			centerz = centercatz;
		}
		lastx = centercatx;
		lastz = centercatz;
		//}
	}
	else if (kalacam) {
		eyex = kalajengking_pos_x;
		eyey = kalajengking_pos_y;
		eyez = kalajengking_pos_z;

		centerx = cat_pos_x;
		centery = cat_pos_y;
		centerz = 10;
	}
	else if (semutcam) {
		eyex = semut_pos_x;
		eyey = semut_pos_y;
		eyez = semut_pos_z;

		centerx = semut_pos_x;
		centery = semut_pos_y;
		centerz = 10;
	}

	centercatx = (lastx - cat_pos_x)*cos(-tetha) - (lastz - cat_pos_z)*sin(-tetha) + cat_pos_x; // muter
	centercaty = cat_pos_y + 1;
	centercatz = (lastx - cat_pos_x)*sin(-tetha) + (lastz - cat_pos_z)*cos(-tetha) + cat_pos_z; // muter

	update_lookat();
	glutPostRedisplay();
}

// kamera awal
void cam_depan() {

	eyex = iX;
	eyey = iY;
	eyez = iZ;
	centerx = iX + lX;
	centery = iY + lY;
	centerz = iZ + lZ;
	upx = uX;
	upy = uY;
	upz = uZ;

	glLoadIdentity();
	update_lookat();
	glutPostRedisplay();
}


// animation
void animation()
{
	// camera
	if (catcam || kalacam || semutcam) objek_cam();
	else cam_depan();

	if (mode_display == DEMO) {
		degcam += 0, 5;
		tetha = (degcam / 360)*M_PI;
	}
	else degcam += 0;

	// animation
	animate_cat(mode_display);
	animate_bird(mode_display);
	animate_kalajengking(mode_display);
	animate_semut(mode_display);
	animate_troli(mode_display);

	// shadow
	update_shadow_cat(light4on);
	update_shadow_troli(light4on);
	update_shadow_kalajengking(light4on);
	update_shadow_semut(light4on);
	update_shadow_burung(light4on);

    update_shadow_cat_bawah(light3on);
    update_shadow_kalajengking_bawah(light3on);
    update_shadow_troli_bawah(light3on);
    update_shadow_semut_bawah(light3on);
	update_shadow_burung_bawah(light3on);

    update_shadow_cat_bawah_kanan(light1on);
    update_shadow_kalajengking_bawah_kanan(light1on);
    update_shadow_troli_bawah_kanan(light1on);
    update_shadow_semut_bawah_kanan(light1on);
	update_shadow_burung_bawah_kanan(light1on);

    update_shadow_cat_bawah_kiri(light2on);
    update_shadow_kalajengking_bawah_kiri(light2on);
    update_shadow_troli_bawah_kiri(light2on);
    update_shadow_semut_bawah_kiri(light2on);
	update_shadow_burung_bawah_kiri(light2on);

	glutPostRedisplay();
}

// init func
void init(void)
{
	glEnable(GL_LIGHTING);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	// texture room
	texwall = LoadTextureRAW("wall.raw", true);
	texfloor = LoadTextureRAW("grass.raw", true);
	texceil = LoadTextureRAW("sky.raw", true);

	// membuat objek
	init_cat();
	init_troli();
	init_kalajengking();
	init_semut();
	init_bird();

}

// keyboard
void keyBoardHandler(unsigned char c, int x, int y) {

	switch (c) {

    case 't':
		light_atas_kanan_y += 0.2;
		break;
	case 'f':
		light_atas_kanan_x -= 0.2;
		break;

	case 'g':
		light_atas_kanan_y -= 0.2;
		break;

	case 'h':
		light_atas_kanan_x += 0.2;
		break;

	case 's':  // cat mundur
		if (mode_display == DEMO) return ;
	    if(selected==22)
            cat_pos_z -= 0.2;
		else if (selected==23)
            kalajengking_pos_z -= 0.2;
        else if(selected==24)
            semut_pos_z -= 0.2;
		break;

	case 'a':  // cat kiri
		if (mode_display == DEMO) return ;
		if(selected==22)
            cat_pos_x -= 0.2;
		else if (selected==23)
            kalajengking_pos_x -= 0.2;
        else if(selected==24)
            semut_pos_x -= 0.2;
		break;

	case 'w': // cat maju
		if (mode_display == DEMO) return;
		if(selected==22)
            cat_pos_z += 0.2;
		else if (selected==23)
            kalajengking_pos_z += 0.2;
        else if(selected==24)
            semut_pos_z += 0.2;
		break;

	case 'd': // cat kanan
		if (mode_display == DEMO) return;
		if(selected==22)
            cat_pos_x += 0.2;
		else if (selected==23)
            kalajengking_pos_x += 0.2;
        else if(selected==24)
            semut_pos_x += 0.2;
		break;

	case 'q': //cat naek
	    if (mode_display == DEMO) return;
		if(selected==22)
            cat_pos_y += 0.2;
		else if (selected==23)
            kalajengking_pos_y += 0.2;
        else if(selected==24)
            semut_pos_y += 0.2;
		break;

	case 'e': //cat turun
		if (mode_display == DEMO) return;
		if(selected==22)
            cat_pos_y -= 0.2;
		else if (selected==23)
            kalajengking_pos_y -= 0.2;
        else if(selected==24)
            semut_pos_y -= 0.2;
		break;

    case 'j':
		camAngle -= 0.01f;
		lX = sin(camAngle);
		lZ = -cos(camAngle);
		break;

	case 'u':
		camAngle2 += 0.01f;
		lY = sin(camAngle2);
		lZ = -cos(camAngle2);
		break;

	case 'o':
		camAngle2 -= 0.01f;
		lY = sin(camAngle2);
		lZ = -cos(camAngle2);
		break;

	case 'l':
		camAngle += 0.01f;
		lX = sin(camAngle);
		lZ = -cos(camAngle);
		break;

	case 'i':
		iX += lX * fraction;
		iY += lY * fraction;
		iZ += lZ * fraction;
		break;

	case 'k':
		iX -= lX * fraction;
		iY -= lY * fraction;
		iZ -= lZ * fraction;
		break;


	case '.':
		textureOn = !textureOn;
		break;

    case '1':
		catcam = !catcam;
		kalacam = false;
		semutcam = false;
		break;
    case '2':
		catcam = false;
		kalacam = !kalacam;
		semutcam = false;
		break;
    case '3':
		catcam = false;
		kalacam = false;
		semutcam = !semutcam;
        break;
	}
}

// arrow
void specialKeyHandler(int key, int x, int y) {



	switch (key) {
	case GLUT_KEY_LEFT: // cahaya kiri
		light_depan_x -= 0.2;
		break;
	case GLUT_KEY_RIGHT: // cahaya kanan
		light_depan_x += 0.2;
		break;
	case GLUT_KEY_UP: // cahaya atas
		light_depan_y += 0.2;
		break;
	case GLUT_KEY_DOWN: // cahaya bawah
		light_depan_y -= 0.2;
		break;
	default:
		break;
	}
}

// light menu 1
void lightmenu1(int id) {

	if (id == 1) light1on = true;
	else light1on = false;
}

// light menu 2
void lightmenu2(int id) {

	if (id == 1) light2on = true;
	else light2on = false;
}

void lightmenu3(int id) {

	if (id == 1) light3on = true;
	else light3on = false;
}

// light menu 4
void lightmenu4(int id) {

	if (id == 1) light4on = true;
	else light4on = false;
}



// interaktif menu
void interaktifmenu(int id) {

	mode_display = INTERAKTIF;
	selected = id;
}

// mode display menu
void modedisplaymenu(int id) {

	if (id == DEMO)
	{
		mode_display = id;
	}
}

// main menu
void mainmenu(int id)
{
	if (id > 21 && id < 25)
	{
		selected = id;
	}
}

// mode shading
void modeshadingmenu(int id) {

	if (id == 1) {
		wire = false;
	}
	else {
		wire = true;
	}
}

// membuat menu
static void menuInit(void) {

	int lightmenu1_sub;
	lightmenu1_sub = glutCreateMenu(lightmenu1);
	glutAddMenuEntry("on", 1);
	glutAddMenuEntry("off", 2);

	int lightmenu2_sub;
	lightmenu2_sub = glutCreateMenu(lightmenu2);
	glutAddMenuEntry("on", 1);
	glutAddMenuEntry("off", 2);

	int lightmenu3_sub;
	lightmenu3_sub = glutCreateMenu(lightmenu3);
	glutAddMenuEntry("on", 1);
	glutAddMenuEntry("off", 2);

	int lightmenu4_sub;
	lightmenu4_sub = glutCreateMenu(lightmenu4);
	glutAddMenuEntry("on", 1);
	glutAddMenuEntry("off", 2);

	int interaktifmenu_sub;
	interaktifmenu_sub = glutCreateMenu(interaktifmenu);
	glutAddMenuEntry("Gerakin kucing", 22);
	glutAddMenuEntry("Gerakin kalajengking", 23);
	glutAddMenuEntry("Gerakin semut", 24);

	int modedisplaymenu_sub;
	modedisplaymenu_sub = glutCreateMenu(modedisplaymenu);
	glutAddMenuEntry("Demo", 100);
	glutAddSubMenu("Interaktif", interaktifmenu_sub);

	int modeshadingmenu_sub;
	modeshadingmenu_sub = glutCreateMenu(modeshadingmenu);
	glutAddMenuEntry("Shading", 1);
	glutAddMenuEntry("Wireframe", 2);

	glutCreateMenu(mainmenu);
	glutAddSubMenu("Mode Display", modedisplaymenu_sub);
	glutAddSubMenu("Mode Shading", modeshadingmenu_sub);
	glutAddSubMenu("Lampu 1", lightmenu1_sub);
	glutAddSubMenu("Lampu 2", lightmenu2_sub);
	glutAddSubMenu("Lampu 3", lightmenu3_sub);
	glutAddSubMenu("Lampu 4", lightmenu4_sub);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// main func
int main(int argc, char* argv[])
{
	int mode = GLUT_DOUBLE | GLUT_RGBA;

	glutInit(&argc, argv);
	glutInitDisplayMode(mode);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 75);
	glutCreateWindow("Tugas Akhir");
    menuInit();
	init();

	glutSpecialFunc(specialKeyHandler);
	glutKeyboardFunc(keyBoardHandler);
	glutDisplayFunc(display);
	glutReshapeFunc(OnResizeWindow);
	glutIdleFunc(animation);
	glutMainLoop();

	return 0;
}
