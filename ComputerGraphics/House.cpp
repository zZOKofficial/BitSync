#include <GL/glut.h>
#include <GL/gl.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(.955, .963, 0.896);

    glBegin(GL_POLYGON);

    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.8f, 0.2f);
    glVertex2f(0.8f, 0.6f);
    glVertex2f(0.2f, 0.6f);

    glEnd();

    glColor3f(0.483, 0.945, 0.669);

    glBegin(GL_POLYGON);

    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.5f, 0.2f);
    glVertex2f(0.5f, 0.4f);
    glVertex2f(0.3f, 0.4f);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.7f, 0.3f);
    glVertex2f(0.7f, 0.4f);
    glVertex2f(0.6f, 0.4f);

    glEnd();

    glColor3f(0.898, 0.192, 0.486);
    glBegin(GL_POLYGON);

    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.8f, 0.6f);
    glVertex2f(0.5f, 0.8f);

    glEnd();



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