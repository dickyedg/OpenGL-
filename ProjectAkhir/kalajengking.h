#pragma once
#include <stdbool.h>

#include "treestruct.h"
#include "texture.h"
#include "lighting.h"
#include "shadow.h"

GLuint textureK;

GLfloat kalajengking_pos_x = -5,
kalajengking_pos_y = -5,
kalajengking_pos_z = 0;

// part structure
treenode torsoKalajengking_node, headKalajengking_node, tailKalajengking1_node, tailKalajengking2_node,
stingKalajengking_node, footKalajengking1_node, footKalajengking2_node, footKalajengking3_node, footKalajengking4_node,
handR_node, handL_node, capitL_node, capitR_node;

// gambar torso
void torsoKalajengking_draw()
{
	GLfloat ambient1[] = { 0.05375, 0.05, 0.06625, 1 };
	GLfloat diffuse1[] = { 0.18275, 0.17, 0.22525, 1 };
	GLfloat specular1[] = { 0.332741, 0.328634, 0.346435, 1 };
	GLfloat shine1 = 38.4;

	//turqoise
	GLfloat ambient2[] = { 0.1, 0.18725, 0.1745, 1 };
	GLfloat diffuse2[] = { 0.396, 0.74151, 0.69102, 1 };
	GLfloat specular2[] = { 0.297254, 0.30829, 0.306678, 1 };
	GLfloat shine2 = 12.8;

	//gold
	GLfloat ambient3[] = { 0.24725, 0.1995, 0.0745, 1 };
	GLfloat diffuse3[] = { 0.75164, 0.60648, 0.22648, 1 };
	GLfloat specular3[] = { 0.628281, 0.555802, 0.366065, 1 };
	GLfloat shine3 = 51.2;


	//material_color(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0, 0, -torso_height / 8);
	texSolidCube(torso_height / 4,textureK);
	glTranslatef(0, 0, torso_height / 4);
	texSolidCube(torso_height / 4, textureK);
	glTranslatef(0, 0, torso_height / 4);
	texSolidCube(torso_height / 4, textureK);
	glPopMatrix();
}

// gambar head
void headKalajengking_draw()
{
	glPushMatrix();
	//material_color(0.5, 0.0, 0.0);
	texSolidCube(head_height / 3, textureK);
	glTranslatef(head_height/8, head_height/8, head_height/7);
	//material_color(1.0, 1.0, 1.0);
	draw_sphere(head_height/16, 10, 10);
	glTranslatef(-(head_height / 4), 0.0, 0.0);
	//material_color(1.0, 1.0, 1.0);
	draw_sphere(head_height / 16, 10, 10);
	glPopMatrix();
}

// gambar tail
GLUquadricObj *tailKalajengking1_quad;
void tailKalajengking1_draw()
{

	//material_color(0.5, 0.0, 0.0);
	glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	//gluQuadricTexture(tailKalajengking1_quad, 1);
	//gluCylinder(tailKalajengking1_quad, tail_rad, tail_rad, tail_height, 10, 10);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

}

GLUquadricObj *tailKalajengking2_quad;
void tailKalajengking2_draw()
{
	//material_color(0.5, 0.0, 0.0);
	glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureK);
	gluQuadricTexture(tailKalajengking2_quad, 1);
	gluCylinder(tailKalajengking2_quad, tail_rad, tail_rad, tail_height, 10, 10);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

// sting
GLdouble sting_height = 2;
void stingKalajengking_draw()
{
	//material_color(0.2, 0.2, 0.2);
	glPushMatrix();
	draw_cone(tail_rad, sting_height, 10, 10);
	glPopMatrix();
}

// capit
GLdouble capit_height = 1;
void capit_draw()
{
	//material_color(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(0, 0, tail_rad / 2);
	glTranslatef(0, 0, tail_rad / 2);
	glTranslatef(0, 0, tail_rad / 2);


	draw_cone(rad_foot, capit_height, 10, 10);
	glPopMatrix();
}

// gambar kaki
GLUquadricObj *footKalajengking_quad;
void footKalajengking_draw()
{
	//material_color(0.2, 0.2, 0.2);
	glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureK);


	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureK);


	//gluQuadricTexture(footKalajengking_quad, 1);
	//gluCylinder(footKalajengking_quad, tail_rad / 2, tail_rad / 2, tail_height / 1.5, 10, 10);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

// animation
GLfloat tail_counter, tail_anim = 2.0;
void animate_kalajengking(int angle)
{
	// torso
	if(angle == 9 || angle==100){

		if (tail_counter > 30) {
			tail_anim = -anim / 2;
		}
		else if (head_counter <= 0) {
			tail_anim = anim / 2;
		}
		tail_counter += tail_anim;

		// tail
		if (angle == 11 || angle == 100) {
			glPushMatrix();
			glLoadIdentity();
			glMultMatrixf(tailKalajengking2_node.m);
			glRotatef(-tail_anim, 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, tailKalajengking2_node.m);
			glPopMatrix();
		}

		// handL
		if (angle == 12 || angle == 100) {
			glPushMatrix();
			glLoadIdentity();
			glMultMatrixf(handL_node.m);
			glRotatef(-tail_anim, 1.0, 1.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, handL_node.m);
			glPopMatrix();
		}

		// handR
		if (angle == 13 || angle == 100) {
			glPushMatrix();
			glLoadIdentity();
			glMultMatrixf(handR_node.m);
			glRotatef(-tail_anim, 1.0, 1.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, handR_node.m);
			glPopMatrix();
		}

		// kaki depan kanan
		if (angle == 14 || angle == 100) {
			glPushMatrix();
			glLoadIdentity();
			glMultMatrixf(footKalajengking1_node.m);
			glRotatef(tail_anim * 2, 1.0, 1.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, footKalajengking1_node.m);
			glPopMatrix();
		}

		// kaki depan kiri
		if (angle == 15 || angle == 100) {
			glPushMatrix();
			glLoadIdentity();
			glMultMatrixf(footKalajengking3_node.m);
			glRotatef(-tail_anim * 2, 0.0, 1.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, footKalajengking3_node.m);
			glPopMatrix();
		}

		// kaki belakang kanan
		if (angle == 16 || angle == 100) {
			glPushMatrix();
			glLoadIdentity();
			glMultMatrixf(footKalajengking2_node.m);
			glRotatef(tail_anim * 2, 1.0, 1.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, footKalajengking2_node.m);
			glPopMatrix();
		}

		//kaki belakang kiri
		if (angle == 17 || angle == 100) {
			glPushMatrix();
			glLoadIdentity();
			glMultMatrixf(footKalajengking4_node.m);
			glRotatef(-tail_anim * 2, 0.0, 1.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, footKalajengking4_node.m);
			glPopMatrix();
		}

	}
}

// buat structure
void init_kalajengking()
{
	textureK = LoadTextureRAW("akatsuki.raw", true);
  	// torsokalajengking = kotak
	glLoadIdentity();
	glTranslatef(5, -0.5 * torso_height ,  torso_height / 2);
	glGetFloatv(GL_MODELVIEW_MATRIX, torsoKalajengking_node.m);
	torsoKalajengking_node.f = torsoKalajengking_draw;
	torsoKalajengking_node.sibling = NULL;
	torsoKalajengking_node.child = &headKalajengking_node;

	//headkalajengking = cone
	glLoadIdentity();
	glTranslatef(0.0, 0.0, torso_height/4 + head_height/2);
	glGetFloatv(GL_MODELVIEW_MATRIX, headKalajengking_node.m);
	headKalajengking_node.f = headKalajengking_draw;
	headKalajengking_node.sibling = &tailKalajengking1_node;
	headKalajengking_node.child = NULL;

	// buntut kalajengking1 = cylinder
	tailKalajengking1_quad = gluNewQuadric();
	gluQuadricDrawStyle(tailKalajengking1_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(0, tail_rad + 1, tail_height / 2 + tail_height / 4 - 5);
	glRotatef(30, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, tailKalajengking1_node.m);
	tailKalajengking1_node.f = tailKalajengking1_draw;
	tailKalajengking1_node.sibling = &footKalajengking1_node;
	tailKalajengking1_node.child = &tailKalajengking2_node;

	// buntut kalajengking2 = cylinder
	tailKalajengking2_quad = gluNewQuadric();
	gluQuadricDrawStyle(tailKalajengking2_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(-60, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, tailKalajengking2_node.m);
	tailKalajengking2_node.f = tailKalajengking2_draw;
	tailKalajengking2_node.sibling = NULL;
	tailKalajengking2_node.child = &stingKalajengking_node;

	// Sting kalajengking
	glLoadIdentity();
	glTranslatef(0.0, 0.0, tail_height);
	//glRotatef(-64, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, stingKalajengking_node.m);
	stingKalajengking_node.f = stingKalajengking_draw;
	stingKalajengking_node.sibling = NULL;
	stingKalajengking_node.child = NULL;

	//kaki
	footKalajengking_quad = gluNewQuadric();

	//kaki depan kanan kalajengking
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - 1);
	glRotatef(90, 1.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, footKalajengking1_node.m);
	footKalajengking1_node.f = footKalajengking_draw;
	footKalajengking1_node.sibling = &footKalajengking2_node;
	footKalajengking1_node.child = NULL;

	//kaki kanan belakang kalajengking
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - 2.5);
	glRotatef(90, 1.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, footKalajengking2_node.m);
	footKalajengking2_node.f = footKalajengking_draw;
	footKalajengking2_node.sibling = &footKalajengking3_node;
	footKalajengking2_node.child = NULL;

	//kaki kiri depan kalajengking
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(-0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - 1);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glRotatef(45, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, footKalajengking3_node.m);
	footKalajengking3_node.f = footKalajengking_draw;
	footKalajengking3_node.sibling = &footKalajengking4_node;
	footKalajengking3_node.child = NULL;

	//kaki kiri belakang
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(-0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - 2.5);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glRotatef(45, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, footKalajengking4_node.m);
	footKalajengking4_node.f = footKalajengking_draw;
	footKalajengking4_node.sibling = &handR_node;
	footKalajengking4_node.child = NULL;

	//tangan kanan
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(-0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - tail_height / 6);
	glRotatef(-45, 0.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, handR_node.m);
	handR_node.f = footKalajengking_draw;
	handR_node.sibling = &handL_node;
	handR_node.child = &capitR_node;

	//tangan kiri
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - tail_height/6);
	glRotatef(45, 0.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, handL_node.m);
	handL_node.f = footKalajengking_draw;
	handL_node.sibling = NULL;
	handL_node.child = &capitL_node;

	//capit LL
	glLoadIdentity();
	glTranslatef(0.0, 0.0, tail_height / 1.5);
	glGetFloatv(GL_MODELVIEW_MATRIX, capitL_node.m);
	capitL_node.f = capit_draw;
	capitL_node.sibling = NULL;
	capitL_node.child = NULL;

	//capit LL
	glLoadIdentity();
	glTranslatef(0.0, 0.0, tail_height / 1.5);
	glGetFloatv(GL_MODELVIEW_MATRIX, capitR_node.m);
	capitR_node.f = capit_draw;
	capitR_node.sibling = NULL;
	capitR_node.child = NULL;

	glLoadIdentity();
}

void draw_Kalajengking(bool shadow)
{
	glPushMatrix();
	if(shadow == false){
		glTranslatef(kalajengking_pos_x, kalajengking_pos_y, kalajengking_pos_z);
	}
	traverse(&torsoKalajengking_node);
	glPopMatrix();
}

/**** shadow ****/

// simpen shadow
static GLfloat kalajengkingshadow[4][4];
static GLfloat kalajengkingshadow2[4][4];
static GLfloat kalajengkingshadow3[4][4];
static GLfloat kalajengkingshadow4[4][4];

void update_shadow_kalajengking(bool bay)
{
	GLfloat plane[4];
    baybelakang = bay;
	GLfloat v0[3] = { 0,-10, 0 };
	GLfloat v1[3] = { 0,-10, 1 };
	GLfloat v2[3] = { 1,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { light_depan_x - kalajengking_pos_x, light_depan_y - kalajengking_pos_y, light_depan_z - kalajengking_pos_z, 1 };

	shadowmatrix(kalajengkingshadow, plane, light_sementara_depan);
}


void update_shadow_kalajengking_bawah(bool bay)
{
	GLfloat plane[4];
    baybawah = bay;
	GLfloat v0[3] = { 0,-10, 0 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { 0 - kalajengking_pos_x, 8 - kalajengking_pos_y, 0 - kalajengking_pos_z, 1 };

	shadowmatrix(kalajengkingshadow2, plane, light_sementara_depan);
}

void update_shadow_kalajengking_bawah_kiri(bool bay)
{
	GLfloat plane[4];
    baybawahkiri = bay;
	GLfloat v0[3] = { 0,-10, 0 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { (-8) - kalajengking_pos_x, 8 - kalajengking_pos_y, 0 - kalajengking_pos_z, 1 };

	shadowmatrix(kalajengkingshadow3, plane, light_sementara_depan);
}

void update_shadow_kalajengking_bawah_kanan(bool bay)
{
	GLfloat plane[4];
    baybawahkanan= bay;
	GLfloat v0[3] = { 0,-10, 0 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { light_atas_kanan_x - kalajengking_pos_x, light_atas_kanan_y - kalajengking_pos_y, light_atas_kanan_z - kalajengking_pos_z, 1 };

	shadowmatrix(kalajengkingshadow4, plane, light_sementara_depan);
}

// gambar shadow
void draw_shadow_kalajengking()
{
	// taro shadow di base
	if(baybelakang){
        glPushMatrix();
        glMultMatrixf((GLfloat *)kalajengkingshadow);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_Kalajengking(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawah){
        glPushMatrix();
        glMultMatrixf((GLfloat *)kalajengkingshadow2);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_Kalajengking(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawahkiri){
        glPushMatrix();
        glMultMatrixf((GLfloat *)kalajengkingshadow3);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_Kalajengking(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawahkanan){
        glPushMatrix();
        glMultMatrixf((GLfloat *)kalajengkingshadow4);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_Kalajengking(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
}


