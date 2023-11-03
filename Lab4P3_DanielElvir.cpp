#include <iostream>
using namespace std;

void menu() {
    cout << "Bienvenido a mi cuarto laboratorio de Progra 3 :D" << endl;
    cout << "1. Desencriptador maquina de LCF" << endl;
    cout << "2. Ladrones de casas" << endl;
    cout << "3. Infección de Zombies" << endl;
    cout << "4. Salir del Programa" << endl;
    cout << "Escoja una opción válida" << endl;
}

void ejercicio1() {
    char cadena[100];
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char inverso[] =  "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    cout << "Ingrese el mensaje encriptado: ";
}

void ejercicio2() {

}

void ejercicio3() {

}

int main() {
    int opcion;
    bool seguir = true;
    setlocale(LC_ALL, "spanish");
    do {
        menu();
        cin >> opcion;
        switch (opcion) {

        case 1:
            cout << "En construcción" << endl;
            ejercicio1();
            break;

        case 2:
            cout << "En construcción" << endl;
            ejercicio2();
            break;

        case 3:
            cout << "En construcción" << endl;
            ejercicio3();
            break;

        case 4:
            cout << "Saliendo del programa...." << endl;
            cout << "Gracias por su tiempo :D" << endl;
            seguir = false;
            break;

        default:
            cout << "Ingresó una opcion que NO ES VALIDA" << endl;
            break;
        }
    } while (seguir);
    
    
}

