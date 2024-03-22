#include <windows.h>
#include <GL/glut.h>

static int shoulder = 0, elbow = 0, palm = 0;
static int thumb1 = 0, thumb2 = 0, index1 = 0, index2 = 0, middle1 = 0, middle2 = 0, ring1 = 0, ring2 = 0, pinky1 = 0, pinky2 = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFingerSegment() {
    glutWireCube(1.0); // Ganti dengan model jari yang lebih kompleks jika diperlukan
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Upper Arm
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Forearm
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Palm
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) palm, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.5, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Thumb
    glPushMatrix();
    glTranslatef(1.25, -0.3, 0.0);
    glRotatef((GLfloat) thumb1, 0.0, 0.0, 1.0);
    glTranslatef(0.75, 0.0, 0.0);
    glPushMatrix();
    drawFingerSegment();
    glPopMatrix();

    glTranslatef(0.75, 0.0, 0.0);
    glRotatef((GLfloat) thumb2, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    drawFingerSegment();
    glPopMatrix();
    glPopMatrix();

    // Index Finger
    // Sisipkan logika untuk menggambar dan menggerakkan segmen jari lainnya (index, middle, ring, pinky) di sini...

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
        case 's':
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
            break;
        case 'p':
            palm = (palm + 5) % 360;
            glutPostRedisplay();
            break;
        case 'P':
            palm = (palm - 5) % 360;
            glutPostRedisplay();
            break;
        // Sisipkan logika untuk menggerakkan jari-jari di sini...

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
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
