#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
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
    bool mayus = true;
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char inverso[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    cout << "Ingrese el mensaje a desencriptar: ";
    cin >> cadena;    
    int longitud = strlen(cadena);
    while (mayus) {
        for (int i = 0; i < longitud; i++) {
            if (cadena[i]>='A' && cadena[i]<='Z') {
                mayus = false;
            }else {
                cout << "SOLO MAYUSCULAS" << endl;
                cout << "Ingrese el mensaje a desencriptar: ";
                cin >> cadena;
                longitud = strlen(cadena);
                mayus = true;
                break;
            }
        }
    }
    char* nuevaCad = new char[longitud];
    for (int i = 0; i < longitud; ++i) {
        if (i % 2 == 0) {
            if (i>=1 && i<=26){
                nuevaCad[i] = inverso[i + 2];
                cout << nuevaCad[i];
            }
            
        } else {
            if (i>=1 && i<=26) {
                nuevaCad[i] = alfabeto[i - 2];
                cout << nuevaCad[i];
            }
            
        }
    }

    nuevaCad[longitud] = '\0';

    cout << "La desencriptación de " << cadena << " es " << nuevaCad << endl;
    cout << endl;

    delete[] nuevaCad;
}

void ejercicio2() {
    int numCasa;
    bool valido = true;
    int acumulador = 0;
    int mayor = 0;
    
    cout << "Ingrese el número de casas que hay en la residencial (entre 5 y 15): ";
    cin >> numCasa;
    while (valido) {
        if (numCasa >= 5 && numCasa <= 15) {
            valido = false;
        }
        else {
            cout << "NÚMERO INVALIDO" << endl;
            cout << "Ingrese el número de casas que hay en la residencial (entre 5 y 15): ";
            cin >> numCasa;
            valido = true;
        }
    }
    int* cajasFuertes = new int[numCasa];
    cout << "Valores de las cajas fuertes en cada casa: " << endl;
    for (int i = 0; i < numCasa; ++i) {
        cajasFuertes[i] = 500 + rand() %(10000-500+1);
        cout << "Casa " << i << ": $" << cajasFuertes[i] << endl;
        if (i%2==0) {
            acumulador += cajasFuertes[i];
        }
    }


    cout << endl;
    cout << "La mejor combinacion para robar es: ";
    for (int i = 0; i < numCasa; i++) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Con una ganancia total de: " << acumulador << endl;
}

void llenarIslas(char* inicial, int tamano) {
    for (int i = 0; i < tamano; i++) {
        int random = rand() % 3;
        if (random == 0) {
            inicial[i] = '0';
        }
        else if (random == 1) {
            inicial[i] = '1';
        }
        else {
            inicial[i] = 'X';
        }
    }
}

void simularIslas(char* inicial, int tamano) {
    bool cambios = true;
    while (cambios) {
        cambios = false;

        for (int i = 0; i < tamano; ++i) {
            if (inicial[i] == '0') {
                if ((i > 0 && inicial[i - 1] == 'X') || (i < tamano - 1 && inicial[i + 1] == 'X')) {
                    inicial[i] = 'X';
                    cambios = true;
                }
                else if (i > 0 && i < tamano - 1 && inicial[i - 1] == '1' && inicial[i + 1] == '1') {
                    inicial[i] = '0';
                }
            }
        }

        for (int i = 0; i < tamano; ++i) {
            if (inicial[i] == 'X') {
                int j = i - 1;
                while (j >= 0 && inicial[j] != '1') {
                    if (inicial[j] == '0') {
                        inicial[j] = 'X';
                        cambios = true;
                    }
                    --j;
                }
                j = i + 1;
                while (j < tamano && inicial[j] != '1') {
                    if (inicial[j] == '0') {
                        inicial[j] = 'X';
                        cambios = true;
                    }
                    ++j;
                }
            }
        }
    }
   
}

void ejercicio3() {
    int tamano=0;    
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamano;    
    char* inicial = new char[tamano];
    
    llenarIslas(inicial, tamano);

    cout << "Arreglo inicial: ";
    for (int i = 0; i < tamano; i++) {
        cout << inicial[i] << " ";
    }
    cout << endl;

    simularIslas(inicial, tamano);

    int aSalvo = 0;
    for (int i = 0; i < tamano; i++) {
        if (inicial[i]=='0') {
            aSalvo++;
        }
    }

    

    cout << "Arreglo final: ";
    for (int i = 0; i < tamano; i++) {
        cout << inicial[i] << " ";
    }
    cout << endl;

    cout << "Personas a salvo: " << aSalvo << endl;
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
            ejercicio2();
            break;

        case 3:
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

