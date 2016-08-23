#pragma once
#include <stdbool.h>

#include "treestruct.h"
#include "texture.h"
#include "lighting.h"
#include "shadow.h"


GLuint textureTroli;

// part structure
treenode torso_troli_node, head_troli_node, foot_troli_node_fl, foot_troli_node_fr, foot_troli_node_bl, foot_troli_node_br,
handle_node_l, handle_node_r, handle_bar_node;

GLfloat troli_pos_x = -5,
troli_pos_y = 0,
troli_pos_z = 0;

// gambar torso
GLdouble torso_troli_height = 5;
void torso_troli_draw()
{

	glPushMatrix();
	material_color(0.6, 0.2, 0.0);
	texSolidCube(torso_troli_height,textureTroli);
	glPopMatrix();
}

// gambar head
GLdouble head_troli_height = 2;
void head_trolid_draw()
{

	glPushMatrix();
	material_color(1.0, 1.0, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	draw_teapot(head_troli_height);
	glPopMatrix();
}

// gambar kaki
GLdouble rad_troli_foot = 0.5;
void foot_troli_draw()
{

	glPushMatrix();
	material_color(0.3, 0.3, 0.3);
	draw_sphere(rad_troli_foot, 10, 10);
	glPopMatrix();
}

// gambar handle
GLUquadricObj *handle_quad;
GLdouble rad_handle = 0.5;
GLdouble handle_height = 2;
/*
void handle_draw()
{

	glPushMatrix();
	material_color(0.7, 0.7, 0.7);
	glRotatef(- 30.0 ,1.0 ,0.0 ,0.0 );
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureTroli);
	gluQuadricTexture(handle_quad, 1);
	gluCylinder(handle_quad, rad_handle, rad_handle, handle_height, 10, 10);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}
*/
void handle_draw()
{
	glPushMatrix();
	material_color(0.7, 0.7, 0.7);
	glRotatef(-30.0, 1.0, 0.0, 0.0);
	glTranslatef(0, 0, rad_handle / 2);
	texSolidCube(rad_handle, textureTroli);
	glTranslatef(0, 0, rad_handle / 2);
	texSolidCube(rad_handle, textureTroli);
	glTranslatef(0, 0, rad_handle / 2);
	texSolidCube(rad_handle, textureTroli);
	glTranslatef(0, 0, rad_handle / 2);
	texSolidCube(rad_handle, textureTroli);
	glTranslatef(0, 0, rad_handle / 2);
	texSolidCube(rad_handle, textureTroli);
	glTranslatef(0, 0, rad_handle / 2);
	texSolidCube(rad_handle, textureTroli);
	glTranslatef(0, 0, rad_handle / 2);
	texSolidCube(rad_handle, textureTroli);


	glPopMatrix();
}

// gambar handle bar
GLUquadricObj *handle_bar_quad;
GLdouble rad_handle_bar = 0.5;
GLdouble handle_bar_height = torso_troli_height;
void handle_bar_draw()
{

	glPushMatrix();
	material_color(0.7, 0.7, 0.7);
	glRotatef(90.0, 0.0, 1.0, 0.0);

	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);

	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);
	glTranslatef(0, 0, rad_handle_bar / 2);
	texSolidCube(rad_handle_bar, textureTroli);


	glPopMatrix();
}

// buat structure
void init_troli()
{
	textureTroli = LoadTextureRAW("kucing.raw", true);
	// torso = kotak
	glLoadIdentity();
	glTranslatef(0.0, -0.5 * torso_troli_height, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, torso_troli_node.m);
	torso_troli_node.f = torso_troli_draw;
	torso_troli_node.sibling = NULL;
	torso_troli_node.child = &head_troli_node;

	// head = teapot
	glLoadIdentity();
	glTranslatef(0.0,torso_troli_height/2 + head_troli_height/2,0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, head_troli_node.m);
	head_troli_node.f = head_trolid_draw;
	head_troli_node.sibling = &foot_troli_node_fl;
	head_troli_node.child = NULL;

	// kaki depan kiri
	glLoadIdentity();
	glTranslatef(-(torso_troli_height/2), -(torso_troli_height/2 + rad_troli_foot/2), -(torso_troli_height/2));
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_troli_node_fl.m);
	foot_troli_node_fl.f = foot_troli_draw;
	foot_troli_node_fl.sibling = &foot_troli_node_fr;
	foot_troli_node_fl.child = NULL;

	// kaki depan kanan
	glLoadIdentity();
	glTranslatef((torso_troli_height/2), -(torso_troli_height/2 + rad_troli_foot/2), -(torso_troli_height/2));
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_troli_node_fr.m);
	foot_troli_node_fr.f = foot_troli_draw;
	foot_troli_node_fr.sibling = &foot_troli_node_bl;
	foot_troli_node_fr.child = NULL;

	// kaki belakang kiri
	glLoadIdentity();
	glTranslatef(-(torso_troli_height/2), -(torso_troli_height/2 + rad_troli_foot/2), (torso_troli_height/2));
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_troli_node_bl.m);
	foot_troli_node_bl.f = foot_troli_draw;
	foot_troli_node_bl.sibling = &foot_troli_node_br;
	foot_troli_node_bl.child = NULL;

	// kaki belakang kanan
	glLoadIdentity();
	glTranslatef((torso_troli_height/2), -(torso_troli_height/2 + rad_troli_foot/2), (torso_troli_height/2));
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_troli_node_br.m);
	foot_troli_node_br.f = foot_troli_draw;
	foot_troli_node_br.sibling = &handle_node_l;
	foot_troli_node_br.child = NULL;

	// handle kanan
	handle_quad = gluNewQuadric();
	gluQuadricDrawStyle(handle_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(-(torso_troli_height/2 - rad_handle), (torso_troli_height/2 - rad_handle), (torso_troli_height/2));
	glGetFloatv(GL_MODELVIEW_MATRIX, handle_node_l.m);
	handle_node_l.f = handle_draw;
	handle_node_l.sibling = &handle_node_r;
	handle_node_l.child = NULL;

	// handle kiri
	handle_quad = gluNewQuadric();
	gluQuadricDrawStyle(handle_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef((torso_troli_height/2 - rad_handle), (torso_troli_height/2 - rad_handle), (torso_troli_height/2));
	glGetFloatv(GL_MODELVIEW_MATRIX, handle_node_r.m);
	handle_node_r.f = handle_draw;
	handle_node_r.sibling = NULL;
	handle_node_r.child = &handle_bar_node;

	// handle bar
	handle_bar_quad = gluNewQuadric();
	gluQuadricDrawStyle(handle_bar_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(-(torso_troli_height-rad_handle), (rad_handle*2), (handle_height-rad_handle_bar));
	glGetFloatv(GL_MODELVIEW_MATRIX, handle_bar_node.m);
	handle_bar_node.f = handle_bar_draw;
	handle_bar_node.sibling = NULL;
	handle_bar_node.child = NULL;

	glLoadIdentity();
}

// gambar troli
void draw_troli(bool shadow)
{
	glPushMatrix();
	if(shadow == false){
		glTranslatef(troli_pos_x, troli_pos_y, troli_pos_z);
	}
	traverse(&torso_troli_node);
	glPopMatrix();
}


void animate_troli(int angle)
{
	// torso
	if (angle == 0 || angle == 100) {
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(torso_troli_node.m);
		glRotatef(anim, 0.0, 1.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, torso_troli_node.m);
		glPopMatrix();
	}
}

/**** shadow ****/

// simpen shadow
static GLfloat trolishadow[4][4];
static GLfloat trolishadow2[4][4];
static GLfloat trolishadow3[4][4];
static GLfloat trolishadow4[4][4];

void update_shadow_troli(bool bay)
{
	GLfloat plane[4];
    baybelakang = bay;
	GLfloat v0[3] = { 0,-10, 0 };
	GLfloat v1[3] = { 0,-10, 1 };
	GLfloat v2[3] = { 1,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { light_depan_x - troli_pos_x, light_depan_y - troli_pos_y, light_depan_z - troli_pos_z, 1 };

	shadowmatrix(trolishadow, plane, light_sementara_depan);
}

void update_shadow_troli_bawah(bool bay)
{
	GLfloat plane[4];
    baybawah = bay;
	GLfloat v0[3] = { 0,-10, 0 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { 0 - troli_pos_x, 8 - troli_pos_y, 0 - troli_pos_z, 1 };

	shadowmatrix(trolishadow2, plane, light_sementara_depan);
}

void update_shadow_troli_bawah_kiri(bool bay)
{
	GLfloat plane[4];
    baybawahkiri = bay;
	GLfloat v0[3] = { 0,-10, 1 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { (-8) - cat_pos_x, 8 - cat_pos_y, 0 - cat_pos_z, 1 };

	shadowmatrix(trolishadow3, plane, light_sementara_depan);
}


void update_shadow_troli_bawah_kanan(bool bay)
{
	GLfloat plane[4];
    baybawahkanan = bay;
	GLfloat v0[3] = { 0,-10, 1 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { light_atas_kanan_x - troli_pos_x, light_atas_kanan_y - troli_pos_y, light_atas_kanan_z - troli_pos_z, 1 };

	shadowmatrix(trolishadow4, plane, light_sementara_depan);
}

// gambar shadow

void draw_shadow_troli()
{
	// taro shadow di base
	if(baybelakang){
        glPushMatrix();
        glMultMatrixf((GLfloat *)trolishadow);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_troli(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawah){
        glPushMatrix();
        glMultMatrixf((GLfloat *)trolishadow2);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_troli(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawahkiri){
        glPushMatrix();
        glMultMatrixf((GLfloat *)trolishadow3);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_troli(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawahkanan){
        glPushMatrix();
        glMultMatrixf((GLfloat *)trolishadow4);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_troli(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
}

