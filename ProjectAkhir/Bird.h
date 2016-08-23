#pragma once
#include <stdbool.h>

#include "treestruct.h"
#include "texture.h"
#include "shadow.h"

// texture burung
GLuint textureBird;

// posisi burung
GLfloat bird_pos_x = 0,
bird_pos_y = -2,
bird_pos_z = 0;

// part structure
treenode torsoBird_node, headBird_node, wing_node_fl, wing_node_fr, wing_node_bl, wing_node_br,
eyeBird_node_l, eyeBird_node_r, tailBird_node;



// gambar torsoBird
GLdouble torsoBird_height = 2;
GLdouble torsoBird_width = torsoBird_height / 8;
void torsoBird_draw()
{
	glPushMatrix();
	glTranslatef(0, 0, -torsoBird_height / 4);
	material_color(1.0, 1.0, 0.0);
	texSolidCube(torsoBird_height / 2, textureBird);
	glTranslatef(0, 0, torsoBird_height / 2);
	material_color(1.0, 1.0, 0.0);
	texSolidCube(torsoBird_height / 2, textureBird);
	glPopMatrix();
}

// gambar headBird
GLdouble headBird_height = torsoBird_height/4;
void headBird_draw()
{
	glPushMatrix();
	material_color(1.0, 1.0, 0.0);
	texSolidCube(headBird_height, textureBird);
	material_color(0.6, 0.3, 0.3);
	glTranslatef(0.0, -headBird_height / 4, -(headBird_height / 3));
	draw_cube(headBird_height / 2);
	glPopMatrix();
}

// gambar mata
GLdouble eyeBird_height = 0.2;
void eyeBird_draw()
{
	material_color(1.0, 1.0, 1.0);
	glPushMatrix();
	draw_cube(eyeBird_height);
	glPopMatrix();
}


// gambar kaki
GLdouble rad_wing = 0.4;
void wing_draw()
{
	material_color(1.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(70, 0, 0, 1);
	glTranslatef(rad_wing, rad_wing*2, rad_wing*2);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);

	glRotatef(30, 0, 0, 1);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);


	glPopMatrix();
}

void wing_drawBawah()
{
	material_color(1.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(-70, 0, 0, 1);
	glTranslatef(-rad_wing , rad_wing*2, rad_wing * 2);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);

	glRotatef(-30, 0, 0, 1);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);
	glTranslatef(0, rad_wing / 2, 0);
	texSolidCube(rad_wing, textureBird);


	glPopMatrix();
}


// gambar tailBird
GLUquadricObj *tailBird_quad;
GLdouble tailBird_height = 1;
GLdouble tailBird_rad = 0.3;
void tailBird_draw()
{
	material_color(1.0, 1.0, 0.0);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBird);
	gluQuadricTexture(tailBird_quad, 1);
	gluCylinder(tailBird_quad, tailBird_rad, tailBird_rad, tailBird_height, 10, 10);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}


// animation
float animBird = 1;
float headBird_counter = 0.0;
float headBird_anim;
float wing_counter = 0.0;
float wing_anim;
void animate_bird(int angle)
{
	// torsoBird
	if (angle == 0 || angle == 100){
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(torsoBird_node.m);
		glRotatef(animBird, 0.0, 1.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, torsoBird_node.m);
		glPopMatrix();
	}

	// kepala
	if (angle == 1 || angle == 100){
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(headBird_node.m);
		glRotatef(headBird_anim, 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, headBird_node.m);
		glPopMatrix();
	}



	if (angle == 6 || angle == 100){
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(wing_node_fr.m);
		glRotatef(wing_anim, 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, wing_node_fr.m);
		glPopMatrix();
	}

	if (angle == 5 || angle == 100){
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(wing_node_fl.m);
		glRotatef(wing_anim, 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, wing_node_fl.m);
		glPopMatrix();
	}

	if (angle == 8 || angle == 100){
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(wing_node_br.m);
		glRotatef(-wing_anim, 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, wing_node_br.m);
		glPopMatrix();
	}

	if (angle == 7 || angle == 100){
		glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(wing_node_bl.m);
		glRotatef(-wing_anim, 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, wing_node_bl.m);
		glPopMatrix();
	}


	if (headBird_counter > 30) {
		headBird_anim = -animBird / 2;
	}
	else if (headBird_counter <= 0) {
		headBird_anim = animBird / 2;
	}
	headBird_counter += headBird_anim;
}
GLdouble rad_earBird = 0.5;
// buat structure
void init_bird()
{
	textureBird = LoadTextureRAW("kucing.raw", true);

	// torsoBird = kotak
	glLoadIdentity();
	glTranslatef(0, -0.5 * torsoBird_height, torsoBird_height / 2);
	glGetFloatv(GL_MODELVIEW_MATRIX, torsoBird_node.m);
	torsoBird_node.f = torsoBird_draw;
	torsoBird_node.sibling = NULL;
	torsoBird_node.child = &headBird_node;

	// headBird = kotak
	glLoadIdentity();
	glTranslatef(0, headBird_height*0.7, -torsoBird_height / 2 - headBird_height / 2);
	glGetFloatv(GL_MODELVIEW_MATRIX, headBird_node.m);
	headBird_node.f = headBird_draw;
	headBird_node.sibling = &wing_node_fl;
	headBird_node.child = &eyeBird_node_l;

	// mata kiri
	glLoadIdentity();
	glTranslatef(-headBird_height / 2 + rad_earBird / 2 + 0.02, eyeBird_height / 2, -(headBird_height / 2 - eyeBird_height / 2 + 0.01));
	glGetFloatv(GL_MODELVIEW_MATRIX, eyeBird_node_l.m);
	eyeBird_node_l.f = eyeBird_draw;
	eyeBird_node_l.sibling = &eyeBird_node_r;
	eyeBird_node_l.child = NULL;

	// mata kanan
	glLoadIdentity();
	glTranslatef(-(-headBird_height / 2 + rad_earBird / 2 + 0.02), eyeBird_height / 2, -(headBird_height / 2 - eyeBird_height / 2 + 0.01));
	glGetFloatv(GL_MODELVIEW_MATRIX, eyeBird_node_r.m);
	eyeBird_node_r.f = eyeBird_draw;
	eyeBird_node_r.sibling = NULL;
	eyeBird_node_r.child = NULL;

	// kaki depan kiri
	glLoadIdentity();
	glTranslatef(-(torsoBird_width / 2), -(torsoBird_width / 2 + rad_wing / 2), -(torsoBird_height / 2));
	glGetFloatv(GL_MODELVIEW_MATRIX, wing_node_fl.m);
	wing_node_fl.f = wing_draw;
	wing_node_fl.sibling = &wing_node_fr;
	wing_node_fl.child = NULL;

	// kaki depan kanan
	glLoadIdentity();
	glTranslatef((torsoBird_width / 2), -(torsoBird_width / 2 + rad_wing / 2), -(torsoBird_height / 2));
	glGetFloatv(GL_MODELVIEW_MATRIX, wing_node_fr.m);
	wing_node_fr.f = wing_drawBawah;
	wing_node_fr.sibling = &tailBird_node;
	wing_node_fr.child = NULL;

	// Buntut
	tailBird_quad = gluNewQuadric();
	gluQuadricDrawStyle(tailBird_quad, GLU_FILL);
	glLoadIdentity();
	glTranslatef(0, tailBird_rad + 0.05, tailBird_height / 2 + tailBird_height / 4);
	glGetFloatv(GL_MODELVIEW_MATRIX, tailBird_node.m);
	tailBird_node.f = tailBird_draw;
	tailBird_node.sibling = NULL;
	tailBird_node.child = NULL;

	glLoadIdentity();
}

// gambar cat
void draw_bird(bool shadow)
{
	glPushMatrix();
	if (shadow == false){
		glTranslatef(bird_pos_x, bird_pos_y, bird_pos_z);
	}
	traverse(&torsoBird_node);
	glPopMatrix();
}

/**** shadow ****/

// simpan shadow
static GLfloat birdshadow[4][4];
static GLfloat birdshadow2[4][4];
static GLfloat birdshadow3[4][4];
static GLfloat birdshadow4[4][4];


void update_shadow_burung(bool bay)
{
    baybelakang= bay;
	GLfloat plane[4];

	GLfloat v0[3] = { 0, -10, 0 };
	GLfloat v1[3] = { 0, -10, 1 };
	GLfloat v2[3] = { 1, -10, 0 };


    findplane(plane, v0, v1, v2);
    GLfloat light_sementara_depan[4] = { light_depan_x - bird_pos_x, light_depan_y - bird_pos_y, light_depan_z - bird_pos_z, 1 };
    shadowmatrix(birdshadow, plane, light_sementara_depan);

}

void update_shadow_burung_bawah(bool bay)
{
	GLfloat plane[4];
    baybawah = bay;
	GLfloat v0[3] = { 0, -10, 1 };
	GLfloat v1[3] = { 10, -10, 1 };
	GLfloat v2[3] = { 10, -10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { 0 - bird_pos_x, 8 - bird_pos_y, 0 - bird_pos_z, 1 };

	shadowmatrix(birdshadow2, plane, light_sementara_depan);
}


void update_shadow_burung_bawah_kiri(bool bay)
{
	GLfloat plane[4];
    baybawahkiri = bay;
	GLfloat v0[3] = { 0, -10, 1 };
	GLfloat v1[3] = { 10, -10, 1 };
	GLfloat v2[3] = { 10, -10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { (-8) - bird_pos_x, 8 - bird_pos_y, 0 - bird_pos_z, 1 };

	shadowmatrix(birdshadow3, plane, light_sementara_depan);
}

void update_shadow_burung_bawah_kanan(bool bay)
{
	GLfloat plane[4];
    baybawahkanan = bay;
	GLfloat v0[3] = { 0, -10, 1 };
	GLfloat v1[3] = { 10, -10, 1 };
	GLfloat v2[3] = { 10, -10, 0 };

	findplane(plane, v0, v1, v2);

	GLfloat light_sementara_depan[4] = { light_atas_kanan_x - bird_pos_x, light_atas_kanan_y - bird_pos_y, light_atas_kanan_z - bird_pos_z, 1 };

	shadowmatrix(birdshadow4, plane, light_sementara_depan);
}

// gambar shadow
void draw_shadow_bird()
{
	// taro shadow di base
	if(baybelakang){
        glPushMatrix();
        glMultMatrixf((GLfloat *)birdshadow);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_bird(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawah){
        glPushMatrix();
        glMultMatrixf((GLfloat *)birdshadow2);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_bird(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
	// taro shadow di base
	if(baybawahkiri){
        glPushMatrix();
        glMultMatrixf((GLfloat *)birdshadow3);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_bird(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}

	// taro shadow di base
	if(baybawahkanan){
        glPushMatrix();
        glMultMatrixf((GLfloat *)birdshadow4);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        // gambar shadow objek ke plane
        glColor3f(0.0, 0.0, 0.0);
        glScalef(0.25, 0.25, 0.25);
        draw_bird(true);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);

        glPopMatrix();
	}
}




