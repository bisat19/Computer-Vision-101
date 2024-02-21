//Nama : Abisatya Hastarangga P
//NIM  : 24060122120004
//Lab C1
#include <windows.h>
#include <math.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Menggambar 5 pesergi berjejer dengan jarak 0.3
    glColor3f(1.0, 0.0, 0.0); // Merah
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, 0.0);
    glVertex2f(-0.45, 0.0);
    glVertex2f(-0.45, 0.2);
    glVertex2f(-0.6, 0.2);
    glEnd();

    glColor3f(0.0, 1.0, 0.0); // Hijau
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.0);
    glVertex2f(-0.15, 0.0);
    glVertex2f(-0.15, 0.2);
    glVertex2f(-0.3, 0.2);
    glEnd();

    glColor3f(0.0, 0.0, 1.0); // Biru
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.15, 0.0);
    glVertex2f(0.15, 0.2);
    glVertex2f(0.0, 0.2);
    glEnd();

    glColor3f(1.0, 1.0, 0.0); // Kuning
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.45, 0.0);
    glVertex2f(0.45, 0.2);
    glVertex2f(0.3, 0.2);
    glEnd();

    glColor3f(0.0, 1.0, 1.0); // Cyan
    glBegin(GL_POLYGON);
    glVertex2f(0.6, 0.0);
    glVertex2f(0.75, 0.0);
    glVertex2f(0.75, 0.2);
    glVertex2f(0.6, 0.2);
    glEnd();

    // Menggambar 4 pesergi di atas 5 pesergi dengan jarak 0.2
    glColor3f(1.0, 0.0, 0.0); // Merah
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, 0.3);
    glVertex2f(-0.45, 0.3);
    glVertex2f(-0.45, 0.5);
    glVertex2f(-0.6, 0.5);
    glEnd();

    glColor3f(0.0, 1.0, 0.0); // Hijau
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.3);
    glVertex2f(-0.15, 0.3);
    glVertex2f(-0.15, 0.5);
    glVertex2f(-0.3, 0.5);
    glEnd();

    glColor3f(0.0, 0.0, 1.0); // Biru
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.3);
    glVertex2f(0.15, 0.3);
    glVertex2f(0.15, 0.5);
    glVertex2f(0.0, 0.5);
    glEnd();

    glColor3f(1.0, 1.0, 0.0); // Kuning
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.45, 0.3);
    glVertex2f(0.45, 0.5);
    glVertex2f(0.3, 0.5);
    glEnd();

    // Menggambar 3 pesergi di atas 4 pesergi dengan jarak 0.2
    glColor3f(1.0, 0.0, 1.0); // Ungu
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.45, 0.6);
    glVertex2f(-0.45, 0.75);
    glVertex2f(-0.6, 0.75);
    glEnd();

    glColor3f(0.0, 1.0, 1.0); // Cyan
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.6);
    glVertex2f(-0.15, 0.6);
    glVertex2f(-0.15, 0.75);
    glVertex2f(-0.3, 0.75);
    glEnd();

    glColor3f(1.0, 0.5, 0.0); // Jingga
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.6);
    glVertex2f(0.15, 0.6);
    glVertex2f(0.15, 0.75);
    glVertex2f(0.0, 0.75);
    glEnd();

    //Menggambar 2 pesergi di atas 3 pesergi
    glColor3f(1.0, 0.0, 1.0); // Ungu
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, 0.9);
    glVertex2f(-0.45, 0.9);
    glVertex2f(-0.45, 0.8);
    glVertex2f(-0.6, 0.8);
    glEnd();

    glColor3f(0.0, 1.0, 1.0); // Cyan
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.15, 0.9);
    glVertex2f(-0.15, 0.8);
    glVertex2f(-0.3, 0.8);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Warna background (putih)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Soal3-Abi-24060122120004");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
