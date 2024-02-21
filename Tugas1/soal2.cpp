//Nama : Abisatya Hastarangga P
//NIM  : 24060122120004
//Lab C1
#include <windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();


    glColor3f(0.5, 0.5, 0.5); // Abu-abu
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.6, -0.2);
    glVertex2f(-0.4, 0.0);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.6, -0.2);
    glEnd();


    glColor3f(0.8, 0.6, 0.4); // Coklat
    glBegin(GL_QUADS);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, -0.6);
    glVertex2f(-0.2, -0.6);
    glEnd();


    glColor3f(1.0, 0.0, 0.0); // Merah
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3, -0.2);
    glVertex2f(0.3, -0.2);
    glVertex2f(0.0, 0.0);
    glEnd();


    glColor3f(0.0, 1.0, 0.0); // Hijau
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-1.0, -0.6);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -0.6);
    glVertex2f(1.0, -1.0);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Soal 2-Abi-24060122120004");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

