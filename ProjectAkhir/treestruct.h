#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <glut.h>

// toggle wireframe
bool wire = false;

// tipe structure
typedef struct treenode
{
	GLfloat m[16];
	void(*f)();
	struct treenode *sibling;
	struct treenode *child;
}treenode;


// traverse draw
void traverse(treenode* root)
{
	if (root == NULL) return;
	glPushMatrix();
	glMultMatrixf(root->m);
	root->f();
	if (root->child != NULL) traverse(root->child);
	glPopMatrix();
	if (root->sibling != NULL) traverse(root->sibling);
}


// material color
void material_color(float r, float g, float b)
{
	GLfloat ambient[] = { r / 2, g / 2, b / 2, 1.0 };
	GLfloat diffuse[] = { r, g, b, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat shine = 100.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shine);
}

void draw_sphere(float sides, float a, float b)
{
	if (wire) glutWireSphere(sides,a,b);
	else glutSolidSphere(sides,a,b);
}

void draw_teapot(float sides)
{
	if (wire) glutWireTeapot(sides);
	else glutSolidTeapot(sides);
}

void draw_cone(float sides, float a, float b, float c)
{
	if (wire) glutWireCone(sides,a,b,c);
	else glutSolidCone(sides, a, b, c);
}

void draw_cube(float sides)
{
	if (wire) glutWireCube(sides);
	else glutSolidCube(sides);
}

// texture solid cube
void texSolidCube(float sides, GLuint tex)
{
	// wireframe
	if (wire)
	{
		glutWireCube(sides);
		return;
	}

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);

	float rad = sides / 2;


	/* Floor */
	glBegin(GL_POLYGON);
	glNormal3f(0.0, -1.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-rad, -rad, -rad);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(rad, -rad, -rad);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(rad, -rad, rad);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-rad, -rad, rad);
	glEnd();

	/* Ceiling */
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-rad, rad, -rad);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(rad, rad, -rad);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(rad, rad, rad);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-rad, rad, rad);
	glEnd();

	/* Walls */
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-rad, -rad, rad);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(rad, -rad, rad);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(rad, rad, rad);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-rad, rad, rad);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-rad, -rad, -rad);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(rad, -rad, -rad);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(rad, rad, -rad);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-rad, rad, -rad);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(rad, rad, rad);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(rad, -rad, rad);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(rad, -rad, -rad);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(rad, rad, -rad);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-rad, rad, rad);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-rad, -rad, rad);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-rad, -rad, -rad);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-rad, rad, -rad);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}
