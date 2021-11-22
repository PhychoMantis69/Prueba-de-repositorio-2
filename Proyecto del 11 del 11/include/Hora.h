#ifndef HORA_H
#define HORA_H


class Hora
{
public:
	Hora(int hora = 0, int minuto = 0);
	~Hora();
	void setHora(int hora);
	void setMinuto(int minuto);
	int getHora();
	int getMinuto();
	void Mostrar();
private:
	int _hora;
	int _minuto;
};

#endif // HORA_H
