/*
EXAMÉN #1
Autor: Heidy Mendoza
Fecha: 18/03/2026
Enunciado: Sistema de registro y análisis de notas de estudiantes

ENTRADA:
    Cantidad de los estudiantes
    Nombres de los estudiantes
    Notas de los estudiantes

PROCESO:
    Validar los datos ingresados
    Almacenar la información en los arreglos
    Calcular el promedio general
    Buscar una nota mayor y una nota menor
    Mostrar el reporte de los aprobados y reprobados
    Permitir consultar un estudiante por su nombre

SALIDA:
    Listado de los estudiantes y de las notas
    Promedio general
    Nota mayor y nota menor
    Cantidad de los aprobados y reprobados
    Resultado de búsqueda por el nombre
*/


#include <iostream>
using namespace std;

// Funnción menú
void mostrarMenu() {
    cout << "\n------ MENU ------" << endl;
    cout << "1. Registrar los estudiantes y sus notas" << endl;
    cout << "2. Mostrar el listado completo" << endl;
    cout << "3. Mostrar el promedio general" << endl;
    cout << "4. Mostrar la nota mayor y nota menor" << endl;
    cout << "5. Mostrar los aprobados y reprobados" << endl;
    cout << "6. Buscar al estudiante por nombre" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

//  REGISTRO DE ESTUDIANTES 
void registrarEstudiantes(string nombres[], float notas[], int &n) {
    
    // SE validan la cantidad de los estudiantes
    do {
        cout << "Ingrese la cantidad de los estudiantes (1-20): ";
        cin >> n;
    } while(n < 1 || n > 20);

   
    for(int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
               
        do{
            cout << "Nombre: ";
            cin >> nombres[i];

        } while (nombres[i] == " "); // Aqui se valida que el nombre no este vacio
      
        do {
            cout << "Nota (0-20): ";
            cin >> notas[i];
        } while(notas[i] < 0 || notas[i] > 20);
    }
}

//  SE MUESTRAR EL LISTADO COMPLETO
void mostrarListado(string nombres[], float notas[], int n) {

    if(n == 0) {
        cout << "No hay estudiantes registrados" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        cout << i + 1 << ". " << nombres[i] << " - " << notas[i] << endl;
    }
}

// PROMEDIO GENERAL
void mostrarPromedio(float notas[], int n) {

    if(n == 0) {
        cout << "No hay estudiantes registrados aun" << endl;
        return;
    }

    float suma = 0;
    for(int i = 0; i < n; i++) {
        suma += notas[i];
    }

    cout << "Promedio general: " << suma / n << endl;
}

//SE MUESTRA LA NOTA MAYOR Y MENOR 
void mayorMenor(string nombres[], float notas[], int n) {

    if(n == 0) {
        cout << "No hay datos" << endl;
        return;
    }

    float mayor = notas[0];
    float menor = notas[0];
    string nomMayor = nombres[0];
    string nomMenor = nombres[0];

    for(int i = 1; i < n; i++) {

        if(notas[i] > mayor) {
            mayor = notas[i];
            nomMayor = nombres[i];
        }

        if(notas[i] < menor) {
            menor = notas[i];
            nomMenor = nombres[i];
        }
    }

    cout << "Nota mayor: " << nomMayor << " - " << mayor << endl;
    cout << "Nota menor: " << nomMenor << " - " << menor << endl;
}

// SE MUESTRA LA CANTIDAD DE LOS APROBADOS Y DE LOS REPROBADOS
void aprobadosReprobados(float notas[], int n) {

    if(n == 0) {
        cout << "No hay datos" << endl;
        return;
    }

    int aprobados = 0;
    int reprobados = 0;

    for(int i = 0; i < n; i++) {

        if(notas[i] >= 14) {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
}

//  BUSQUEDA DE UN ESTUDIANTE POR SU NOMBRE (SE MUESTRA SU NOTA Y SI ESTA A O R)
void buscar(string nombres[], float notas[], int n) {

    if(n == 0) {
        cout << "No hay datos" << endl;
        return;
    }

    string buscado;
    cout << "Ingrese nombre a buscar: ";
    cin >> buscado;

    for(int i = 0; i < n; i++) {

        if(nombres[i] == buscado) {

            cout << "Nombre: " << nombres[i] << endl;
            cout << "Nota: " << notas[i] << endl;

            if(notas[i] >= 14) {
                cout << "Estado: Aprobado" << endl;
            } else {
                cout << "Estado: Reprobado" << endl;
            }

            return; 
        }
    }

    cout << "Estudiante no encontrado" << endl;
}

int main() {

    string nombres[20]; // arreglo utlizado para los nombres
    float notas[20];    // arreglo de las notas
    int n = 0;          // cantidad de los estudiantes
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        if(opcion < 1 || opcion > 7) {
            cout << "Opcion invalida" << endl;
            continue;
        }

        switch(opcion) {

            case 1:
                registrarEstudiantes(nombres, notas, n);
                break;

            case 2:
                mostrarListado(nombres, notas, n);
                break;

            case 3:
                mostrarPromedio(notas, n);
                break;

            case 4:
                mayorMenor(nombres, notas, n);
                break;

            case 5:
                aprobadosReprobados(notas, n);
                break;

            case 6:
                buscar(nombres, notas, n);
                break;

                            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
        }


    } while(opcion != 7);

    return 0;
}