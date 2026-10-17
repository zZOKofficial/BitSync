#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>

#define PI 3.14159265

void drawOval(float centerX, float centerY, float radiusX, float radiusY) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float rad = i * PI / 180.0;
        glVertex2f(centerX + cos(rad) * radiusX, centerY + sin(rad) * radiusY);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f , 1.0f , 1.0f);

    glBegin(GL_POLYGON);

    glVertex2f(0, 0);
    glVertex2f(0, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0);

    glEnd();

    glColor3f(0.9569f, 0.1647f, 0.2549f);

    //top rect
    glBegin(GL_POLYGON);

    glVertex2f(0.5f, 0.8f);
    glVertex2f(0.35f, 0.6f);
    glVertex2f(0.65f, 0.6f);

    glEnd();

    //left portion
    glBegin(GL_POLYGON);

    glVertex2f(0.35f, 0.6f);
    glVertex2f(0.25f, 0.7f);
    glVertex2f(0.25f, 0.5f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(0.25f, 0.4f);
    glVertex2f(0.5f, 0.4f);
    glVertex2f(0.5f, 0.6f);
    glVertex2f(0.35f, 0.6f);
    glEnd();

    //right portion
    glBegin(GL_POLYGON);

    glVertex2f(0.65f, 0.6f);
    glVertex2f(0.75f, 0.7f);
    glVertex2f(0.75f, 0.5f);
    glVertex2f(0.95f, 0.5f);
    glVertex2f(0.75f, 0.4f);
    glVertex2f(0.5f, 0.4f);
    glVertex2f(0.5f, 0.6f);
    glVertex2f(0.65f, 0.6f);
    glEnd();

    //strand
    glColor3f(0.0f, 0.35f, 0.231f);

    glBegin(GL_POLYGON);

    glVertex2f(0.48f, 0.4f);
    glVertex2f(0.52f, 0.4f);
    glVertex2f(0.52f, 0.2f);
    glVertex2f(0.48f, 0.2f);

    glEnd();

    drawOval(0.5f, 0.12f, 0.12f, 0.08f);

    glutSwapBuffers();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(420, 10);
    glutCreateWindow("House");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1, 1);

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}