/*#include <stdio.h>

#include <GL\glew.h>
#include <GL\freeglut.h>

// Espacio para las variables globales de la ventana
float gl_ancho = 2.0, gl_alto = 2.0, gl_cerca = -1.0, gl_lejos = 5.0;
int w_ancho = 500, w_alto = 500;

bool rotando = false;
float sentido = +1;
int pasos_segundo = 50;
int angulo_paso = 1;
GLfloat angulo = 0;

// Espacio para la declaración de funciones
void InitGlew();
void InitGL();
void Display();
void ReshapeAspect(int ancho, int alto);
void ReshapeSize(int ancho, int alto);

void Timer(int v) {
	if (rotando) {
		angulo += angulo_paso * sentido;
		if (angulo > 360.0) angulo -= 360.0;
		if (angulo < -360.0) angulo += 360.0;
		glutPostRedisplay();
	}
	glutTimerFunc(1000 / pasos_segundo, Timer, v);
}

void Raton(int boton, int estado, int x, int y) {
	if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
		rotando = true;
		sentido = +1;
	}
	if (boton == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN) {
		rotando = true;
		sentido = -1;
	}
	if (boton == GLUT_MIDDLE_BUTTON && estado == GLUT_DOWN) {
		rotando = false;
	}
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w_ancho, w_alto);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	glutCreateWindow("OpenGL Practica 3 Aitor Garcia Hernandez");
	InitGlew(); // despues de crear la primera ventana
	InitGL();
	glutDisplayFunc(Display); // registra la funcion de rendering 
	glutReshapeFunc(ReshapeSize);
	glutTimerFunc(100, Timer, 0);
	glutMouseFunc(Raton);

	glutMainLoop(); // bucle principal

	return 0;
}


void InitGlew() {

	// para poder utilizar trasnparentemente todas las extensiones de OpenGL

	GLenum glew_init = glewInit();
	if (glew_init != GLEW_OK)
	{
		// Problem: glewInit failed, something is seriously wrong. 
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_init));
	}
	else
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	fprintf(stdout, "Practica 3 Aitor garcia Hernandez\n");
}

void InitGL() {

	if (gl_ancho / w_ancho != gl_alto / w_alto) {
		fprintf(stderr, "La relación de aspecto no es correcta\n");
	}

	glClearColor(0.0, 0.0, 0.0, 0.0);
	// TO DO

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-gl_ancho / 2.0, gl_ancho / 2.0, -gl_alto / 2.0, gl_alto / 2.0, gl_cerca, gl_lejos); // espacio de trabajo
}


// cambio de dimensiones de la ventana, manteniendo la relación de aspecto
void ReshapeAspect(int ancho, int alto) {

	float dx = gl_ancho;
	float dy = gl_alto;

	if (ancho > alto) {
		dx = dy * (float)ancho / (float)alto;
	}
	if (alto > ancho) {
		dy = dx * (float)alto / (float)ancho;
	}

	glViewport(0, 0, ancho, alto); // utiliza la totalidad de la ventana
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, gl_cerca, gl_lejos); // espacio de trabajo
	glutPostRedisplay();
}

// cambio de dimensiones de la ventana, manteniendo la dimension de los objetos
void ReshapeSize(int ancho, int alto) {

	float dx = gl_ancho;
	float dy = gl_alto;

	dx *= (float)ancho / (float)w_ancho;
	dy *= (float)alto / (float)w_alto;

	glViewport(0, 0, ancho, alto); // utiliza la totalidad de la ventana
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, gl_cerca, gl_lejos); // espacio de trabajo
	glutPostRedisplay();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glRotatef(angulo, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-0.5, -0.5, 0.5, 0.5);
	glFlush();
	glutSwapBuffers();
}*/



