#include <iostream>
#include <cstring>
#include <cstdlib>
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
    char inverso[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    cout << "Ingrese el mensaje a desencriptar: ";
    cin >> cadena;
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++){
        char indice = cadena[i];
        
    }

}

void ejercicio2() {
    int numCasa;
    bool valido = true;
    int acumulador = 0;
    int mayor = 0;
    
    cout << "Ingrese el numero de casas que hay en la residencial (entre 5 y 15): ";
    cin >> numCasa;
    while (valido) {
        if (numCasa >= 5 && numCasa <= 15) {
            valido = false;
        }
        else {
            cout << "NUMERO INVALIDO" << endl;
            cout << "Ingrese el numero de casas que hay en la residencial (entre 5 y 15): ";
            cin >> numCasa;
            valido = true;
        }
    }
    int* cajasFuertes = new int[numCasa];
    cout << "Valores de las cajas fuertes en cada casa: " << endl;
    for (int i = 0; i < numCasa; ++i) {
        cajasFuertes[i] = rand() % 9501 + 500;
        cout << "Casa " << i << ": " << cajasFuertes[i] << endl;
    }


    cout << endl;
    cout << "La mejor combinacion para robar es: ";
    cout << "Con una ganancia total de: " << acumulador << endl;
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

