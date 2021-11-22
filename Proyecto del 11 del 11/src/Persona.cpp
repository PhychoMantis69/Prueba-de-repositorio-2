#include "Persona.h"
#include <iostream>
#include <cstring>

using namespace std;

Persona::Persona(int DNI, const char* nombres, const char* apellidos, int Edad) {
    _DNI = DNI;
    strcpy(_nombres, nombres);
    strcpy(_apellidos, apellidos);
    _Edad = Edad;
}
Persona::~Persona()
{

}
void Persona::setDNI(int dni) {
    if (dni > 0) {
        _DNI = dni;
    }
}
void Persona::setNombres(char* nombres) {
    if (strlen(nombres) > 1) {
        strcpy(_nombres, nombres);
    }
}
void Persona::setApellidos(char* apellidos) {
    if (strlen(apellidos) > 1) {
        strcpy(_apellidos, apellidos);
    }
}

void Persona::setEdad(int Edad){
 if(Edad > 0 && Edad < 120){
_Edad = Edad;
}

}

int Persona :: getEdad(){
return _Edad;
}

int  Persona::getDNI() {
    return _DNI;
}
char* Persona::getNombres() {
    return _nombres;
}
char* Persona::getApellidos() {
    return _apellidos;
}
void Persona::Mostrar() {
    cout << "DNI: " << _DNI << endl;
    cout << "Nombres: " << _nombres << endl;
    cout << "Apellidos: " << _apellidos << endl;
    cout << "Edad: " << _Edad << endl;
}
