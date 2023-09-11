#include <iostream>
#include <string>

using namespace std;

const int MAX = 100; // Tamaño máximo de la lista estática

class empleado {
private:
    int claveEm;
    string nombre;
    string domicilio;
    float sueldo;
    string reportaA;

public:
    empleado() : claveEm(0), nombre(""), domicilio(""), sueldo(0), reportaA("") {} // Constructor por defecto

    empleado(int CE, string N, string D, float S, string R)
        : claveEm(CE), nombre(N), domicilio(D), sueldo(S), reportaA(R) {}

    // Otros métodos y operadores...

    void imprime() {
        cout << "Clave de empleado: " << claveEm << endl;
        cout << "Nombre empleado: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta a: " << reportaA << endl;
        cout << "\n\n";
    }

    int obtenerClaveEm() const {
        return claveEm;
    }

    float obtenerSueldo() const {
        return sueldo;
    }

    string obtenerNombre() const {
        return nombre;
    }

    string obtenerDomicilio() const {
        return domicilio;
    }

    string obtenerReportaA() const {
        return reportaA;
    }
};

template <typename T>
class ListaEstatica {
private:
    T Datos[MAX]; // Arreglo de elementos de tipo T
    int Tam;      // Tamaño actual de la lista

public:
    ListaEstatica() : Tam(0) {} // Constructor que inicializa el tamaño en 0

    int Agrega(T valor) {
        if (Llena()) {
            cout << "La lista está llena" << endl;
            return -1;
        }

        Datos[Tam] = valor;
        Tam++; // Incrementar el tamaño
        return Tam - 1; // Devuelve la posición en la que se insertó el valor
    }

    int Busca(T valor) {
        for (int i = 0; i < Tam; i++) {
            if (Datos[i] == valor) {
                return i; // Devuelve la posición del valor encontrado
            }
        }
        return -1; // Valor no encontrado
    }

    bool Vacia() const {
        return Tam == 0;
    }

    bool Llena() const {
        return Tam == MAX;
    }

    int Muestra() {
        cout << "Tamanio de la lista: " << Tam << endl;
        for (int i = 0; i < Tam; i++) {
            Datos[i].imprime(); // Llama al método imprime de la clase empleado
        }
        return Tam;
    }
};

int main() {
    ListaEstatica<empleado> miLista;

    empleado JefePlanta(217222, "Nancy Quintero", "Mezquite 136", 6500, "Juanita");
    empleado JefePersonal(2274782, "Paola Cruz", "Mezquite 137", 7500, "Rosa");

    miLista.Agrega(JefePlanta);
    miLista.Agrega(JefePersonal);

    cout << "Lista de empleados:" << endl;
    miLista.Muestra();

    return 0;
}
