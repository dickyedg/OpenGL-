#pragma once
#include <stdbool.h>

#include "treestruct.h"
#include "texture.h"
#include "lighting.h"
#include "shadow.h"

// texture kucing
GLuint textureCat;

// posisi kucing
GLfloat cat_pos_x = 5,
cat_pos_y = 0,
cat_pos_z = 0;

// part structure
treenode torso_node, head_node, foot_node_fl, foot_node_fr, foot_node_bl, foot_node_br,
tail_node, ear_node_l, ear_node_r, eye_node_l, eye_node_r;

bool baybelakang=true;
bool baybawah=true;
bool baybawahkiri=true;
bool baybawahkanan=true;

// gambar torso
GLdouble torso_height = 4.5;
GLdouble torso_width = torso_height / 2;
void torso_draw()
{
	glPushMatrix();
	glTranslatef(0, 0, -torso_height / 4);
	material_color(1.0, 1.0, 0.0);
	texSolidCube(torso_height/2, textureCat);
	glTranslatef(0, 0, torso_height / 2);
	material_color(1.0, 1.0, 0.0);
	texSolidCube(torso_height / 2, textureCat);
	glPopMatrix();
}

// gambar head
GLdouble head_height = torso_width;
void head_draw()
{
	glPushMatrix();
	material_color(1.0, 1.0, 0.0);
	texSolidCube(head_height, textureCat);
	material_color(0.6, 0.3, 0.3);
	glTranslatef(0.0, -head_height / 4, -(head_height / 3));
	draw_cube(head_height / 2);
	glPopMatrix();
}

// gambar mata
GLdouble eye_height = 0.7;
void eye_draw()
{
	material_color(1.0, 1.0, 1.0);
	glPushMatrix();
	draw_cube(eye_height);
	glPopMatrix();
}

GLUquadricObj *tail_quad;
GLdouble tail_height = 1;
GLdouble tail_rad = 0.5;
void tail_draw()
{
	material_color(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef( 0, 0, torso_width / 2);
	texSolidCube(tail_rad, textureCat);
	glTranslatef( 0, 0,tail_rad / 2);
	texSolidCube(tail_rad, textureCat);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureCat);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureCat);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureCat);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureCat);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureCat);
	glTranslatef(0, 0, tail_rad / 2);
	texSolidCube(tail_rad, textureCat);
	glTranslatef(0, 0, tail_rad / 2);

	glPopMatrix();
}

// gambar kaki
GLdouble rad_foot = 0.5;
void foot_draw()
{
	material_color(1.0, 1.0, 0.0);
	glPushMatrix();
	texSolidCube(rad_foot, textureCat);
	glTranslatef(0, rad_foot / 2, 0);
	texSolidCube(rad_foot, textureCat);
	glTranslatef(0, rad_foot / 2, 0);
	texSolidCube(rad_foot, textureCat);
	glTranslatef(0, rad_foot / 2, 0);
	texSolidCube(rad_foot, textureCat);
	glTranslatef(0, rad_foot / 2, 0);
	texSolidCube(rad_foot, textureCat);
	glTranslatef(0, rad_foot / 2, 0);
	texSolidCube(rad_foot, textureCat);

	glPopMatrix();
}

// gambar kuping
GLdouble rad_ear = 0.5;
void ear_draw()
{
	material_color(1.0, 1.0, 0.0);
	glPushMatrix();
	texSolidCube(rad_ear, textureCat);
	glPopMatrix();
}

// animation
float anim = 0.5;
float head_counter = 0.0;
float head_anim;
float foot_counter = 0.0;
float foot_anim;
void animate_cat(int angle)
{
    // torso
    if(angle==0||angle==100){
	    glPushMatrix();
        glLoadIdentity();
        glMultMatrixf(torso_node.m);
        glRotatef(anim, 0.0, 1.0, 0.0);
        glGetFloatv(GL_MODELVIEW_MATRIX, torso_node.m);
        glPopMatrix();
    }

    // kepala
	if(angle ==1||angle==100){
        glPushMatrix();
        glLoadIdentity();
        glMultMatrixf(head_node.m);
        glRotatef(head_anim, 1.0, 0.0, 0.0);
        glGetFloatv(GL_MODELVIEW_MATRIX, head_node.m);
        glPopMatrix();
	}

	if(angle ==3||angle==100){
        glPushMatrix();
        glLoadIdentity();
        glMultMatrixf(ear_node_r.m);
        glRotatef(anim, 0.0, 0.0, 1.0);
        glGetFloatv(GL_MODELVIEW_MATRIX, ear_node_r.m);
        glPopMatrix();
	}

	if(angle ==4||angle==100){
        glPushMatrix();
        glLoadIdentity();
        glMultMatrixf(ear_node_l.m);
        glRotatef(anim, 0.0, 0.0, 1.0);
        glGetFloatv(GL_MODELVIEW_MATRIX, ear_node_l.m);
        glPopMatrix();
	}
	if (angle == 6 || angle == 100){
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(foot_node_fr.m);
		glRotatef(foot_anim, 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, foot_node_fr.m);
		glPopMatrix();
	}

	if(angle==5||angle==100){
	glPushMatrix();
	glLoadIdentity();
	glMultMatrixf(foot_node_fl.m);
	glRotatef(foot_anim, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,foot_node_fl.m);
	glPopMatrix();
	}

	if(angle==8||angle==100){
	glPushMatrix();
	glLoadIdentity();
	glMultMatrixf(foot_node_br.m);
	glRotatef(-foot_anim, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,foot_node_br.m);
	glPopMatrix();
	}

	if(angle==7||angle==100){
	glPushMatrix();
	glLoadIdentity();
	glMultMatrixf(foot_node_bl.m);
	glRotatef(-foot_anim, 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,foot_node_bl.m);
	glPopMatrix();
	}

	if (foot_counter > 45) {
		foot_anim= -anim / 2;
	}
	else if (foot_counter <= 0) {
		foot_anim = anim / 2;
	}
	foot_counter += foot_anim;



	if (head_counter > 30) {
		head_anim = -anim / 2;
	}
	else if (head_counter <= 0) {
		head_anim = anim / 2;
	}
	head_counter += head_anim;
}

// buat structure
void init_cat()
{
	textureCat = LoadTextureRAW("kucing.raw", true);

	// torso = kotak
	glLoadIdentity();
	glTranslatef(0, -0.5 * torso_height, torso_height / 2);
	glGetFloatv(GL_MODELVIEW_MATRIX, torso_node.m);
	torso_node.f = torso_draw;
	torso_node.sibling = NULL;
	torso_node.child = &head_node;

	// head = kotak
	glLoadIdentity();
	glTranslatef(0, head_height*0.7, -torso_height / 2 - head_height / 2);
	glGetFloatv(GL_MODELVIEW_MATRIX, head_node.m);
	head_node.f = head_draw;
	head_node.sibling = &foot_node_fl;
	head_node.child = &ear_node_l;

	// kuping kiri
	glLoadIdentity();
	glTranslatef(-head_height / 2 + rad_ear / 2, head_height / 2 + rad_ear / 2, head_height / 2 - rad_ear / 2);
	glGetFloatv(GL_MODELVIEW_MATRIX, ear_node_l.m);
	ear_node_l.f = ear_draw;
	ear_node_l.sibling = &ear_node_r;
	ear_node_l.child = NULL;


	// kuping kanan
	glLoadIdentity();
	glTranslatef(-(-head_height / 2 + rad_ear / 2), head_height / 2 + rad_ear / 2, head_height / 2 - rad_ear / 2);
	glGetFloatv(GL_MODELVIEW_MATRIX, ear_node_r.m);
	ear_node_r.f = ear_draw;
	ear_node_r.sibling = &eye_node_l;
	ear_node_r.child = NULL;

	// mata kiri
	glLoadIdentity();
	glTranslatef(-head_height / 2 + rad_ear / 2 + 0.02, eye_height / 2, -(head_height / 2 - eye_height / 2 + 0.01));
	glGetFloatv(GL_MODELVIEW_MATRIX, eye_node_l.m);
	eye_node_l.f = eye_draw;
	eye_node_l.sibling = &eye_node_r;
	eye_node_l.child = NULL;

	// mata kanan
	glLoadIdentity();
	glTranslatef(-(-head_height / 2 + rad_ear / 2 + 0.02), eye_height / 2, -(head_height / 2 - eye_height / 2 + 0.01));
	glGetFloatv(GL_MODELVIEW_MATRIX, eye_node_r.m);
	eye_node_r.f = eye_draw;
	eye_node_r.sibling = NULL;
	eye_node_r.child = NULL;

	// kaki depan kiri
	glLoadIdentity();
	glTranslatef(-(torso_width / 2), -(torso_width / 2 + rad_foot / 2), -(torso_height / 2));
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_node_fl.m);
	foot_node_fl.f = foot_draw;
	foot_node_fl.sibling = &foot_node_fr;
	foot_node_fl.child = NULL;

	// kaki depan kanan
	glLoadIdentity();
	glTranslatef((torso_width / 2), -(torso_width / 2 + rad_foot / 2) , -(torso_height / 2));
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_node_fr.m);
	foot_node_fr.f = foot_draw;
	foot_node_fr.sibling = &foot_node_bl;
	foot_node_fr.child = NULL;

	// kaki belakang kiri
	glLoadIdentity();
	glTranslatef(-(torso_width / 2), -(torso_width / 2 + rad_foot / 2), (torso_height / 2));
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_node_bl.m);
	foot_node_bl.f = foot_draw;
	foot_node_bl.sibling = &foot_node_br;
	foot_node_bl.child = NULL;

	// kaki belakang kanan
	glLoadIdentity();
	glTranslatef((torso_width / 2), -(torso_width / 2 + rad_foot / 2), (torso_height / 2));
	glGetFloatv(GL_MODELVIEW_MATRIX, foot_node_br.m);
	foot_node_br.f = foot_draw;
	foot_node_br.sibling = &tail_node;
	foot_node_br.child = NULL;

	// Buntut
	tail_quad = gluNewQuadric();
	gluQuadricDrawStyle(tail_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(0, tail_rad + 0.05, tail_height / 2 + tail_height / 4);
	glGetFloatv(GL_MODELVIEW_MATRIX, tail_node.m);
	tail_node.f = tail_draw;
	tail_node.sibling = NULL;
	tail_node.child = NULL;

	glLoadIdentity();
}

// gambar cat
void draw_cat(bool shadow)
{
	glPushMatrix();
	if(shadow == false){
		glTranslatef(cat_pos_x, cat_pos_y, cat_pos_z);
	}
	traverse(&torso_node);
	glPopMatrix();
}


/**** shadow ****/

// menyimpan gambar shadow
static GLfloat catshadow[4][4];
static GLfloat catshadow2[4][4];
static GLfloat catshadow3[4][4];
static GLfloat catshadow4[4][4];

// pilih plane shadow untuk cat
void update_shadow_cat(bool bay)
{
    baybelakang = bay;
	GLfloat plane[4];

	GLfloat v0[3] = { 0,-10, 0 };
	GLfloat v1[3] = { 0,-10, 1 };
	GLfloat v2[3] = { 1,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { light_depan_x - cat_pos_x, light_depan_y - cat_pos_y, light_depan_z - cat_pos_z, 1 };
    shadowmatrix(catshadow, plane, light_sementara_depan);
}

// update shadow
void update_shadow_cat_bawah(bool bay)
{
	GLfloat plane[4];
    baybawah = bay;
	GLfloat v0[3] = { 0,-10, 1 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { 0 - cat_pos_x, 8 - cat_pos_y, 0 - cat_pos_z, 1 };

	shadowmatrix(catshadow2, plane, light_sementara_depan);
}

// update shadow
void update_shadow_cat_bawah_kiri(bool bay)
{
	GLfloat plane[4];
    baybawahkiri = bay;
	GLfloat v0[3] = { 0,-10, 1 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { (-8) - cat_pos_x, 8 - cat_pos_y, 0 - cat_pos_z, 1 };

	shadowmatrix(catshadow3, plane, light_sementara_depan);
}

// update shadow
void update_shadow_cat_bawah_kanan(bool bay)
{
	GLfloat plane[4];
    baybawahkanan = bay;
	GLfloat v0[3] = { 0,-10, 1 };
	GLfloat v1[3] = { 10,-10, 1 };
	GLfloat v2[3] = { 10,-10, 0 };

	findplane(plane, v0, v1, v2);
    GLfloat light_sementara_depan[4] = { light_atas_kanan_x - cat_pos_x, light_atas_kanan_y - cat_pos_y, light_atas_kanan_z - cat_pos_z, 1 };
	shadowmatrix(catshadow4, plane, light_sementara_depan);
}

// gambar shadow
void draw_shadow_cat()
{
	// taro shadow di base
	if(baybelakang){
        glPushMatrix();
        glMultMatrixf((GLfloat *)catshadow);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_cat(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawah){
        glPushMatrix();
        glMultMatrixf((GLfloat *)catshadow2);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_cat(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawahkiri){
        glPushMatrix();
        glMultMatrixf((GLfloat *)catshadow3);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_cat(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawahkanan){
        glPushMatrix();
        glMultMatrixf((GLfloat *)catshadow4);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_cat(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
}




