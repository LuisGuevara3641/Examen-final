#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void agregarTarea(stack<string>& pila, queue<string>& cola);
void completarUltimaTarea(stack<string>& pila, queue<string>& cola);
void completarTareaAntigua(queue<string>& cola, stack<string>& pila);
void mostrarTodasTareas(const queue<string>& pila);
int main()
{
    int opc;
    stack<string> pila;
    queue<string> cola;
    do
    {
        gotoxy(45, 1);
        cout << "MENU PRINCIPAL" << endl;
        cout << "1- Agregar tarea." << endl;
        cout << "2- Completar ultima tarea." << endl;
        cout << "3- Completar la tarea mas antigua." << endl;
        cout << "4- Mostrar todas las tareas." << endl;
        cout << "5- Salir del menu." << endl;
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            system("cls");
            agregarTarea(pila, cola);
            system("pause");
            cout << endl;
            break;
        }

        case 2:
		{
            system("cls");
			completarUltimaTarea(pila, cola);

			system("pause");
			cout << endl;
			break;
		}

        case 3:
		{
            system("cls");
			completarTareaAntigua(cola, pila);

			system("pause");
			cout << endl;
			break;
		}

        case 4:
		{
            system("cls");
			mostrarTodasTareas(cola);

			system("pause");
			cout << endl;
			break;
		}

        default:
			break;
		}
        system("cls");
	} while (opc != 5);

    cout << "Fuera del programa";
    return 0;
}
/***********************************************************AgregarTarea()****************************************************************/
void agregarTarea(stack<string>& pila, queue<string>& cola) {
    string tarea;
    gotoxy(45, 1);
    cout << "Agregar tarea:" << endl << endl;
    cout << "Ingrese la tarea: ";
    getline(cin, tarea);

    pila.push(tarea);
    cola.push(tarea);
    cout << "Tarea agregada." << endl;
}
/***********************************************************CompletarUltimaTarea()****************************************************************/
void completarUltimaTarea(stack<string>& pila, queue<string>& cola) {
    gotoxy(45, 1);
    cout << "Completar ultima tarea:" << endl << endl;
    if (pila.empty()) {
        cout << "No hay tareas pendientes." << endl;
    } else {
        cout << "Tarea completada: " << pila.top() << endl;
        string tareaCompletada = pila.top();
        pila.pop();

        // Eliminar la tarea completada de la cola para que se pueda mostrar bien la información en la opción 4 del menú
        queue<string> colaTemporal;
        while (!cola.empty()) {
            if (cola.front() != tareaCompletada) {
                colaTemporal.push(cola.front());
            }
            cola.pop();
        }
        cola = colaTemporal;
    }
}
/***********************************************************completarTareaAntigua()****************************************************************/
void completarTareaAntigua(queue<string>& cola, stack<string>& pila) {
    gotoxy(45, 1);
    cout << "Completar tarea antigua:" << endl << endl;
    if (cola.empty()) {
        cout << "No hay tareas pendientes." << endl;
    } else {
        cout << "Tarea atendida: " << cola.front() << endl;
        string tareaAtendida = cola.front();
        cola.pop();

        // Eliminar la tarea atendida de la pila para que se pueda mostrar bien la información en la opción 4 del menú
        stack<string> pilaTemporal;
        while (!pila.empty()) {
            if (pila.top() != tareaAtendida) {
                pilaTemporal.push(pila.top());
            }
            pila.pop();
        }
        pila = pilaTemporal;
    }
}
/***********************************************************mostrarTodasTareas()****************************************************************/
void mostrarTodasTareas(const queue<string>& cola) {
    gotoxy(45, 1);
    cout << "Mostrar tareas:" << endl << endl;
    if (cola.empty()) {
        cout << "No hay tareas pendientes." << endl;
    } else {
        cout << "Tareas pendientes:" << endl;
        queue<string> colaTemporal = cola;
        while (!colaTemporal.empty()) {
            cout << colaTemporal.front() << endl;
            colaTemporal.pop();
        }
    }
}
