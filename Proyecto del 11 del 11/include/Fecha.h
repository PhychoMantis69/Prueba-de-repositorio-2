#ifndef FECHA_H
#define FECHA_H


class Fecha
{
public:
    Fecha(int dia = 0, int mes = 0, int anio = 0);
    ~Fecha();

    void setFecha(int dia, int mes, int anio);
    void setNombreDia(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    char* getNombreDia();
    int getNumeroDia();
    bool esCorrecta(int dia, int mes, int anio);
    bool esBisiesto(int anio);
    bool esFeriado();
    void Mostrar();
    bool operator > (Fecha &f);
    bool operator < (Fecha &f);

private:
    int _dia;
    int _mes;
    int _anio;
    char _nombreDia[10];
    int _numDia;
};


#endif // FECHA_H
