#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
public:
    Persona(int DNI = 0, const char* nombres = "vacio", const char* apellidos = "vacio", int Edad = 0);
    ~Persona();
    void setDNI(int dni);
    void setNombres(char* nombres);
    void setApellidos(char* apellidos);
    void setEdad(int Edad);
    int getDNI();
    char* getNombres();
    char* getApellidos();
    int getEdad();
    void Mostrar();
protected:
    int _DNI;
    char _nombres[50];
    char _apellidos[50];
    int _Edad;
};

#endif // PERSONA_H
