//Nama: Abisatya Hastarangga Pradana
//NIM: 24060122120004
//Tanggal: 5 Mar 2024
//Lab C1
//Membuat gambar lengan bergerak di opengl dan glut
//Untuk merotasikan bahu gunakan A atau a
//Untuk merotasikan siku gunakan S atau s
//Untuk merotasikan telapak gunakan D atau d
//Untuk merotasikan jari gunakan 1/2/3/4/5


#include <windows.h>
#include <GL/glut.h>

static int bahu = 0, siku = 0, telapak = 0, jari1 = 0, jari2 = 0, jari3 = 0, jari4 = 0, jari5 = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat) bahu, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) siku, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) telapak, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.5, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75, -0.3, 0.0);
    glRotatef((GLfloat) jari1, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75, -0.1, 0.0);
    glRotatef((GLfloat) jari2, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75, 0.1, 0.0);
    glRotatef((GLfloat) jari3, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75, 0.3, 0.0);
    glRotatef((GLfloat) jari4, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25, 0.3, 0.0);
    glRotatef((GLfloat) jari5, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            bahu = (bahu + 5) % 360;
            glutPostRedisplay();
            break;
        case 'A':
            bahu = (bahu - 5) % 360;
            glutPostRedisplay();
            break;
        case 's':
            siku = (siku + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            siku = (siku - 5) % 360;
            glutPostRedisplay();
            break;
        case 'd':
            telapak = (telapak + 5) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            telapak = (telapak - 5) % 360;
            glutPostRedisplay();
            break;
        case '1':
            jari1 = (jari1 + 5) % 360;
            glutPostRedisplay();
            break;
        case '2':
            jari2 = (jari2 + 5) % 360;
            glutPostRedisplay();
            break;
        case '3':
            jari3 = (jari3 + 5) % 360;
            glutPostRedisplay();
            break;
        case '4':
            jari4 = (jari4 + 5) % 360;
            glutPostRedisplay();
            break;
        case '5':
            jari5 = (jari5 + 5) % 360;
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan Bergerak-Abisatya-24060122120004");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
