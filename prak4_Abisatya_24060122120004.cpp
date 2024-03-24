/*
Nama: Abisatya Hastarangga Pradana
NIM: 24060122120004
Tgl: 21 Mar 2024*/
#include <math.h>
//#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float angle=0.0, deltaAngle = 0.0, ratio;
float x=0.0f,y=1.75f,z=15.0f; // posisi awal kamera
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight=12;
void Reshape(int w1, int h1)
{
// Fungsi reshape
if(h1 == 0) h1 = 1;
w = w1;
h = h1;
ratio = 1.0f * w / h;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glViewport(0, 0, w, h);
gluPerspective(45,ratio,0.1,1000);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(
x, y, z,
x + lx,y + ly,z + lz,
0.0f,1.0f,0.0f);
}
void orientMe(float ang)
{
// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan)
lx = sin(ang);
lz = -cos(ang);
glLoadIdentity();
gluLookAt(x, y, z,
x + lx,y + ly,z + lz,
0.0f,1.0f,0.0f);
}
void moveMeFlat(int i)
{
// Fungsi ini untuk maju mundur kamera
x = x + i*(lx)*0.1;
z = z + i*(lz)*0.1;
glLoadIdentity();
gluLookAt(x, y, z,
x + lx,y + ly,z + lz,
0.0f,1.0f,0.0f);
}
void Grid() {
// Fungsi untuk membuat grid di "lantai"
double i;
const float Z_MIN = -50, Z_MAX = 50;
const float X_MIN = -50, X_MAX = 50;
const float gap = 1.5;
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_LINES);
for(i=Z_MIN;i<Z_MAX;i+=gap)
{
glVertex3f(i, 0, Z_MIN);
glVertex3f(i, 0, Z_MAX);
}
for(i=X_MIN;i<X_MAX;i+=gap)
{
glVertex3f(X_MIN, 0, i);
glVertex3f(X_MAX, 0, i);
}
glEnd();
}
void cylinder(float alas, float atas, float tinggi)
{
    float i;
    glPushMatrix();
    glTranslatef(1.0, 0.0, -alas / 8);
    glutSolidCone(alas, 0, 32, 4);
    for (i = 0; i <= tinggi; i += alas / 24)
    {
        glTranslatef(0.0, 0.0, alas / 24);
        glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
    }
    glTranslatef(0.0, 0.0, alas / 4);
    glutSolidCone(atas, 0, 20, 1);
    glColor3f(1., 0., 0.);
    glPopMatrix();
}

void blok(float tebal, int ratiol, int ratiop)
{
    float i, j;
    glPushMatrix();
    for (i = 0; i < ratiop; i++)
    {
        glTranslatef(-(ratiol + 1) * tebal / 2, 0.0, 0.0);
        for (j = 0; j < ratiol; j++)
        {
            glTranslatef(tebal, 0.0, 0.0);
            glutSolidCube(tebal);
        }
        glTranslatef(-(ratiol - 1) * tebal / 2, 0.0, tebal);
    }
    glPopMatrix();
}
void Mobil(float r, float g, float b)
{
    glPushMatrix();
    
        glColor3f(r, g, b);
        blok(10, 3, 2);
        glTranslatef(0, 9, 0);
        blok(10, 3, 2);
        glTranslatef(10, -10, 0);
        blok(10, 5.5, 2);
        glRotatef(-35, 0, 0, 15);
        glTranslatef(0, 7, 0);
        blok(10, 2, 2);
        glTranslatef(2, 4.9, -2.5);
        glColor3f(2.0, 1.0, 1.0);// warna kaca
        blok(0.5, 20, 31);

        glRotatef(180, 45, -45, 0);
        

        glPopMatrix();


        glPushMatrix();//roda
        glColor3f(0.5, 0.0, 0.0);
        glTranslatef(20, -8, -7);
        cylinder(5, 5, 3);

        glColor3f(0.5, 0.0, 0.0);
        glTranslatef(-20, 8, 7);
        glTranslatef(-5, -8, -7);
        cylinder(5, 5, 3);

        glColor3f(0.5, 0.0, 0.0);
        glTranslatef(5, 8, 7);
        glRotatef(180, 0, 180, 0);
        glTranslatef(3, -8, -17);
        cylinder(5, 5, 3);

        glColor3f(0.5, 0.0, 0.0);
        glTranslatef(-3, 8, 17);
        glTranslatef(-22, -8, -17);
        cylinder(5, 5, 3);

        glColor3f(1.0, 1.0, 1.0);

        glRotatef(90, 1, 0, 0);
        glTranslatef(8, 2.5, -15);
        blok(2, 4, 5);


        glRotatef(90, 0, 1, 0);
        glTranslatef(0, -0.2, 7);
        blok(2, 4, 8);


        glRotatef(0, 0, 0, 0);
        glTranslatef(0, 19.2, 0);
        blok(2, 4, 8);

        glRotatef(90, 0, 1, 0);
        glTranslatef(7, 0, -8);
        blok(2, 4, 5);

        glColor3f(9.9, 9.9, 0.0);//lampu
        glRotatef(90, 0, 1, 0);
        glTranslatef(0, -3, 20);
        cylinder(2, 2, 3);

        glColor3f(9.9, 9.9, 0.0);//lampu
        glRotatef(0, 0, 0, 0);
        glTranslatef(0, -12, 0);
        cylinder(2, 2, 3);

        glColor3f(1, 0.0, 0.0);//knalpot
        glRotatef(0, 0, 0, 0);
        glTranslatef(0, 0, -52);
        cylinder(1, 1, 3);

        glColor3f(1.0, 1.0, 1.0);
        glRotatef(90, 1, 0, 0);
        glTranslatef(-8, 3.5, -12);
        blok(2, 4, 8);

        glColor3f(9.0, 0.0, 0.0);//lampu atas
        glRotatef(0, 0, 0, 0);
        glTranslatef(-8, 28, 0);
        cylinder(1, 1, 12);


    glPopMatrix();
}

void display() {
    // Kalau move dan angle tidak nol, gerakkan kamera...
if (deltaMove)
moveMeFlat(deltaMove);
if (deltaAngle) {
angle += deltaAngle;
orientMe(angle);
}
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Gambar grid
Grid();
// Gambar objek di sini...
Mobil(25.5,8.5,0.1);
glutSwapBuffers();
glFlush();
}
void pressKey(int key, int x, int y) {
// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
// Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak
switch (key) {
case GLUT_KEY_LEFT : deltaAngle = -0.01f;break;
case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break;
case GLUT_KEY_UP : deltaMove = 1;break;
case GLUT_KEY_DOWN : deltaMove = -1;break;
}
}
void releaseKey(int key, int x, int y) {
// Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
// Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti
switch (key) {
case GLUT_KEY_LEFT :
if (deltaAngle < 0.0f)
deltaAngle = 0.0f;
break;
case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f)
deltaAngle = 0.0f;
break;
case GLUT_KEY_UP : if (deltaMove > 0)
deltaMove = 0;
break;
case GLUT_KEY_DOWN : if (deltaMove < 0)
deltaMove = 0;
break;
}
}
// Variable untuk pencahayaan
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.01f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.0f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 0.75f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 75.0f };
void lighting(){
// Fungsi mengaktifkan pencahayaan
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LESS);
glEnable(GL_LIGHT0);
glEnable(GL_NORMALIZE);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING);
glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}
void init(void)
{
glEnable (GL_DEPTH_TEST);
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition(100,100);
glutInitWindowSize(640,480);
glutCreateWindow("Praktikum 4- Abisatya Hastarangga P - 24060122120004");
glutIgnoreKeyRepeat(1); 
glutSpecialFunc(pressKey);
glutSpecialUpFunc(releaseKey);
glutDisplayFunc(display);
glutIdleFunc(display);
glutReshapeFunc(Reshape);
lighting();
init();
glutMainLoop();
return(0);
}