#pragma once
#include <stdbool.h>

#include "treestruct.h"
#include "texture.h"
#include "lighting.h"
#include "shadow.h"

GLfloat semut_pos_x = 2.5,
semut_pos_y = -5,
semut_pos_z = 0;

treenode torso_semut_node, head_semut_node, foot_semut1_node, foot_semut2_node, foot_semut3_node, foot_semut4_node;

void headsemut_draw()
{
	glPushMatrix();
	//material_color(0.5, 0.0, 0.0);
	draw_sphere(head_height / 4, 10, 10);
	glPopMatrix();
}

// buat structure
void init_semut()
{
	textureK = LoadTextureRAW("konoha.raw", true);
  	// torsokalajengking = kotak
	glLoadIdentity();
	glTranslatef(5, -0.5 * torso_height ,  torso_height / 2);
	glGetFloatv(GL_MODELVIEW_MATRIX, torso_semut_node.m);
	torso_semut_node.f = torsoKalajengking_draw;
	torso_semut_node.sibling = NULL;
	torso_semut_node.child = &head_semut_node;

	//headkalajengking = cone
	glLoadIdentity();
	glTranslatef(0.0, 0.0, torso_height/4 + head_height/2);
	glGetFloatv(GL_MODELVIEW_MATRIX, head_semut_node.m);
	head_semut_node.f = headsemut_draw;
	head_semut_node.sibling = &foot_semut1_node;
	head_semut_node.child = NULL;



	//kaki
	footKalajengking_quad = gluNewQuadric();

	//kaki depan kanan kalajengking
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - 1);
	glRotatef(90, 1.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_semut1_node.m);
	foot_semut1_node.f = footKalajengking_draw;
	foot_semut1_node.sibling = &foot_semut2_node;
	foot_semut1_node.child = NULL;

	//kaki kanan belakang kalajengking
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - 2.5);
	glRotatef(90, 1.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_semut2_node.m);
	foot_semut2_node.f = footKalajengking_draw;
	foot_semut2_node.sibling = &foot_semut3_node;
	foot_semut2_node.child = NULL;

	//kaki kiri depan kalajengking
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(-0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - 1);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glRotatef(45, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_semut3_node.m);
	foot_semut3_node.f = footKalajengking_draw;
	foot_semut3_node.sibling = &foot_semut4_node;
	foot_semut3_node.child = NULL;

	//kaki kiri belakang
	gluQuadricDrawStyle(footKalajengking_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(-0.5, tail_rad - 0.5, tail_height / 2 + tail_height / 4 - 2.5);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glRotatef(45, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_semut4_node.m);
	foot_semut4_node.f = footKalajengking_draw;
	foot_semut4_node.sibling = NULL;
	foot_semut4_node.child = NULL;



	glLoadIdentity();
}

void draw_semut(bool shadow)
{
	glPushMatrix();
	glScalef(0.7, 0.7, 0.7);
	glTranslatef(0.0, -2.0 , 0.0);
	glPushMatrix();
	if(shadow == false){
		glTranslatef(semut_pos_x, semut_pos_y, semut_pos_z);
	}
	traverse(&torso_semut_node);
	glPopMatrix();
	glPopMatrix();
}

void animate_semut(int angle)
{
	// kaki depan kanan
	if (angle == 14 || angle == 100) {
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(foot_semut1_node.m);
		glRotatef(tail_anim * 2, 1.0, 1.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, foot_semut1_node.m);
		glPopMatrix();
	}

	// kaki depan kiri
	if (angle == 15 || angle == 100) {
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(foot_semut2_node.m);
		glRotatef(-tail_anim * 2, 0.0, 1.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, foot_semut2_node.m);
		glPopMatrix();
	}

	// kaki belakang kanan
	if (angle == 16 || angle == 100) {
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(foot_semut3_node.m);
		glRotatef(tail_anim * 2, 1.0, 1.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, foot_semut3_node.m);
		glPopMatrix();
	}

	//kaki belakang kiri
	if (angle == 17 || angle == 100) {
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(foot_semut4_node.m);
		glRotatef(-tail_anim * 2, 0.0, 1.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, foot_semut4_node.m);
		glPopMatrix();
	}

}

/**** shadow ****/

// simpen shadow
static GLfloat semutshadow[4][4];
static GLfloat semutshadow2[4][4];
static GLfloat semutshadow3[4][4];
static GLfloat semutshadow4[4][4];

void update_shadow_semut(bool bay)
{
	GLfloat plane[4];
    baybelakang = bay;
	GLfloat v0[3] = { 0,-10, 0 };
	GLfloat v1[3] = { 0,-10, 1 };
	GLfloat v2[3] = { 1,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { light_depan_x - semut_pos_x, light_depan_y - semut_pos_y, light_depan_z - semut_pos_z, 1 };


	shadowmatrix(semutshadow, plane, light_sementara_depan);
}

void update_shadow_semut_bawah(bool bay)
{
	GLfloat plane[4];
    baybawah = bay;
	GLfloat v0[3] = { 0,-10, 0 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { 0 - semut_pos_x, 8 - semut_pos_y, 0 - semut_pos_z, 1 };


	shadowmatrix(semutshadow2, plane, light_sementara_depan);
}

void update_shadow_semut_bawah_kiri(bool bay)
{
	GLfloat plane[4];
    baybawahkiri = bay;
	GLfloat v0[3] = { 0,-10, 1 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { (-8) - semut_pos_x, 8 - semut_pos_y, 0 - semut_pos_z, 1 };

	shadowmatrix(semutshadow3, plane, light_sementara_depan);
}

void update_shadow_semut_bawah_kanan(bool bay)
{
	GLfloat plane[4];
    baybawahkanan = bay;
	GLfloat v0[3] = { 0,-10, 1 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { light_atas_kanan_x - semut_pos_x, light_atas_kanan_y - semut_pos_y, light_atas_kanan_z - semut_pos_z, 1 };

	shadowmatrix(semutshadow4, plane, light_sementara_depan);
}

void draw_shadow_semut()
{
	// taro shadow di base
	if(baybelakang){
        glPushMatrix();
        glMultMatrixf((GLfloat *)semutshadow);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_semut(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawah){
        glPushMatrix();
        glMultMatrixf((GLfloat *)semutshadow2);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_semut(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawahkiri){
        glPushMatrix();
        glMultMatrixf((GLfloat *)semutshadow3);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_semut(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawahkanan){
        glPushMatrix();
        glMultMatrixf((GLfloat *)semutshadow4);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_semut(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
}




