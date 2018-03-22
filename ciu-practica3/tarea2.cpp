#include <stdio.h>

#include <GL\glew.h>
#include <GL\freeglut.h>

// Espacio para las variables globales de la ventana
float gl_ancho = 2.0, gl_alto = 2.0, gl_cerca = -1.0, gl_lejos = 5.0;
int w_ancho = 500, w_alto = 500;

// Espacio para otras variables globales
#define SALIR -1
#define VER_NADA 0
#define VER_ESFERA 1
#define VER_TORO 2
#define VER_CONO 3
#define VER_CILINDRO 4

#define VER_T4 5
#define VER_T6 6
#define VER_T8 7
#define VER_T12 8
#define VER_T20 9
#define VER_TETERA 10

int visualiza = VER_NADA;
int win1;
int menu1, menu2, menu3;

// Espacio para la declaración de funciones
void InitGlew();
void InitGL();
void Display();
void ReshapeAspect(int ancho, int alto);
void ReshapeSize(int ancho, int alto);

void gestor_menu(int value) {
	if (value == SALIR) {
		glutDestroyWindow(win1);
		exit(0);
	}
	visualiza = value;
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w_ancho, w_alto);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	glutCreateWindow("OpenGL Practica 3 Aitor Garcia Hernandez");
	InitGlew(); // despues de crear la primera ventana
	InitGL();
	glutDisplayFunc(Display); // registra la funcion de rendering 
	glutReshapeFunc(ReshapeSize);

	menu1 = glutCreateMenu(gestor_menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Esfera", VER_ESFERA);
	glutAddMenuEntry("Toro", VER_TORO);
	glutAddMenuEntry("Cono", VER_CONO);
	glutAddMenuEntry("Cilindro", VER_CILINDRO);
	glutAddMenuEntry("Salir", SALIR);

	menu2 = glutCreateMenu(gestor_menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Tetraedro", VER_T4);
	glutAddMenuEntry("Hexaedro", VER_T6);
	glutAddMenuEntry("Octaedro", VER_T8);
	glutAddMenuEntry("Dodecaedro", VER_T12);
	glutAddMenuEntry("Icosaedro", VER_T20);
	glutAddMenuEntry("Salir", SALIR);

	menu3 = glutCreateMenu(gestor_menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddSubMenu("Cuadraticas", menu1);
	glutAddSubMenu("S. Platonicos", menu2);
	glutAddMenuEntry("Tetera", VER_TETERA);
	glutAddMenuEntry("Salir", SALIR);

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	switch (visualiza) {
	case VER_ESFERA:
		glutWireSphere(0.5, 20, 20);
		break;
	case VER_TORO:
		glutWireTorus(0.2,0.6, 20, 20);
		break;
	case VER_CONO:
		glutWireCone(0.4,0.1, 20, 20);
		break;
	case VER_CILINDRO:
		glutWireCylinder(0.4,0.1, 20, 20);
		break;
	case VER_T4:
		glutWireTetrahedron();
		break;
	case VER_T6:
		glutWireCube(0.5);
		break;
	case VER_T8:
		glutWireOctahedron();
		break;
	case VER_T12:
		glutWireDodecahedron();
		break;
	case VER_T20:
		glutWireIcosahedron();
		break;
	case VER_TETERA:
		glutWireTeapot(0.5);
		break;
	}
	glutSwapBuffers();
	printf("Display\n");
}
