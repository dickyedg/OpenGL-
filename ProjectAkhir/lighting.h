#pragma once
#include <stdlib.h>
#include <glut.h>

#include "treestruct.h"

// light 0 = depan
// light 1 = kanan atas (merah)
// light 2 = kiri atas (ungu)
// light 3 = tengah atas (ijo)

// toggle light
bool light1on = true;
bool light2on = true;
bool light3on = true;
bool light4on = true;

// posisi lamp
GLfloat light_depan_x = 0,
light_depan_y = 0,
light_depan_z = 15;

GLfloat light_atas_kiri_x = -8,
light_atas_kiri_y = 8,
light_atas_kiri_z = 0;

GLfloat light_atas_tengah_x = 0,
light_atas_tengah_y = 8,
light_atas_tengah_z = 0;

GLfloat light_atas_kanan_x = 8,
light_atas_kanan_y = 8,
light_atas_kanan_z = 0;


// gambar lampu depan
static void draw_lamp_depan(void)
{
	GLfloat light_depan_pos[4] = { light_depan_x, light_depan_y, light_depan_z, 1.0 };

	static GLfloat lightdir[3] = { -light_depan_x, -light_depan_y, -light_depan_z };

    float r, g, b;

	if (light4on){
		glEnable(GL_LIGHT0);
		r = 1;
		g = 1;
		b = 0;
	}
	else {
		glDisable(GL_LIGHT0);
		r = 0;
		g = 0;
		b = 0;
	}

	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightdir);
	glLightfv(GL_LIGHT0, GL_POSITION, light_depan_pos);

	glPushMatrix();
	material_color(r, g, b);
	glTranslatef(light_depan_x, light_depan_y, light_depan_z);
	glutSolidSphere(0.6, 10, 10);
	glPopMatrix();

}

// gambar lampu atas kanan
static void draw_lamp_ataskanan()
{
	GLfloat diffuse1[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat ambient0[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat specular0[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light0_pos[] = { light_atas_kanan_x, light_atas_kanan_y, light_atas_kanan_z, 1 };

	float r, g, b;

	if (light1on){
		glEnable(GL_LIGHT1);
		r = 1;
		g = 0;
		b = 0;
	}
	else {
		glDisable(GL_LIGHT1);
		r = 0;
		g = 0;
		b = 0;
	}
	glLightfv(GL_LIGHT1, GL_POSITION, light0_pos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular0);

	glPushMatrix();
	material_color(r, g, b);
    glTranslatef(light_atas_kanan_x, light_atas_kanan_y, light_atas_kanan_z);
	glutSolidSphere(0.6, 10, 10);
	glPopMatrix();
}

// gambar lampu atas kiri
static void draw_lamp_ataskiri()
{
	GLfloat diffuse2[] = { 1.0, 0.0, 1.0, 1.0 };
	GLfloat ambient0[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat specular0[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light0_pos[] = { light_atas_kiri_x, light_atas_kiri_y, light_atas_kiri_z, 1.0 };

	float r, g, b;

	if (light2on) {
		glEnable(GL_LIGHT2);
		r = 1;
		g = 0;
		b = 1;
	}
	else {
		glDisable(GL_LIGHT2);
		r = 0;
		g = 0;
		b = 0;
	}
	glLightfv(GL_LIGHT2, GL_POSITION, light0_pos);
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient0);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specular0);

	glPushMatrix();
	glTranslatef(-8.0, 8.0, 0.0);
	material_color(r, g, b);
	glutSolidSphere(0.6, 10, 10);
	glPopMatrix();
}

// gambar lampu atas
static void draw_lamp_atas()
{
	GLfloat diffuse3[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat ambient0[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat specular0[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light0_pos[] = { light_atas_tengah_x, light_atas_tengah_y, light_atas_tengah_z, 1.0 };

	float r, g, b;

	if (light3on) {
		glEnable(GL_LIGHT3);
		r = 0;
		g = 1;
		b = 0;
	}
	else {
		glDisable(GL_LIGHT3);
		r = 0;
		g = 0;
		b = 0;
	}

	glLightfv(GL_LIGHT3, GL_POSITION, light0_pos);
	glLightfv(GL_LIGHT3, GL_AMBIENT, ambient0);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, specular0);

	glPushMatrix();
	glTranslatef(0.0, 8.0, 0.0);
	material_color(r, g, b);
	glutSolidSphere(0.6, 10, 10);
	glPopMatrix();
}
