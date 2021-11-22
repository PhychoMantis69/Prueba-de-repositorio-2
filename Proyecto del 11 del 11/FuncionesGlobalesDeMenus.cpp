#include "FuncionesGlobalesDeMenus.h"
#include "Direccion.h"
#include "Empleado.h"
#include "FacturaConsulta.h"
#include "Fecha.h"
#include "Fecha_Hora.h"
#include "HistoriaClinica.h"
#include "Hora.h"
#include "Paciente.h"
#include "Persona.h"
#include "Turno.h"
#include "Cadena.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

/*void AsignarTurno() {
	Empleado reg;
	Turno t1;
	int especialidad, pos = 0, nroMedico, opcHora;
	Cadena horarios[20];
//	CargarHorarios(horarios);
	vector<Empleado> vEmpleados;
	cout << "Ingrese la especialidad: ";
	cin >> especialidad;
	while (reg.leerDeDisco(pos)) {
		if (especialidad == reg.getEspecialidad()) {
			vEmpleados.push_back(reg);
		}
		pos++;
	}
	int filas = vEmpleados.size();
	int** TurnosDia = new int* [filas];
	for (int i = 0; i < filas; i++)
	{
		TurnosDia[i] = new int[20]{-1};
	}
	//InicializarMatrizTurnos(TurnosDia,vEmpleados, vEmpleados.size());
	cout << endl;
	cout << "Grilla de Turnos: " << endl;
	//MostrarMatrizTurnos(TurnosDia);
	cout << "Ingrese nro de medico a atender: ";
	cin >> nroMedico;
	cout << "Horarios disponibles: " << endl;
	for (int i = 0; i < 20; i++)
	{
		if (TurnosDia[nroMedico][i] == 0) {
			cout << i + 1 << ". ";
			horarios[i].Mostrar();
			cout << endl;
		}
	}
	cout << "Elija un horario: ";
	cin >> opcHora;
	TurnosDia[nroMedico][opcHora] = 1;
	cout << "Turno asignado." << endl;


	for (int i = 0; i < filas; i++)
	{
		delete TurnosDia[i];
	}
	delete TurnosDia;
}
void CargarHorarios(Cadena *horarios) {
	horarios[0].setValor("08:00");
	horarios[1].setValor("08:30");
	horarios[2].setValor("09:00");
	horarios[3].setValor("09:30");
	horarios[4].setValor("10:00");
	horarios[5].setValor("10:30");
	horarios[6].setValor("11:00");
	horarios[7].setValor("11:30");
	horarios[8].setValor("12:00");
	horarios[9].setValor("12:30");
	horarios[10].setValor("13:00");
	horarios[11].setValor("13:30");
	horarios[12].setValor("14:00");
	horarios[13].setValor("14:30");
	horarios[14].setValor("15:00");
	horarios[15].setValor("15:30");
	horarios[16].setValor("16:00");
	horarios[17].setValor("16:30");
	horarios[18].setValor("17:00");
	horarios[19].setValor("17:30");
}
void InicializarMatrizTurnos(int TurnosDia[][20], Empleado *vEmpleados, int tamVecEmpleados) {
	for (int fila = 0; fila < tamVecEmpleados; fila++)
	{
		int horaInicio = vEmpleados[fila].getHoraEntrada().getHora();
		int minutoInicio = vEmpleados[fila].getHoraEntrada().getMinuto();
		int horaSalida = vEmpleados[fila].getHoraSalida().getHora();
		int minutoSalida = vEmpleados[fila].getHoraSalida().getMinuto();
		for (int columna = 0; columna < 20; columna++)
		{

		}
	}
}*/


bool esBisiesto(int anio)
{
    if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
    {
        return true;
    }
    return false;
}

int dias_mes(int mes, int anio)
{
    int dias = 31;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        dias = 30;
    }
    else if (mes == 2)
    {
        if (esBisiesto(anio))
        {
            dias = 29;
        }
        else
        {
            dias = 28;
        }
    }
    return dias;
}
void cargarHorarios(Hora *vHorarios)
{
    int nro, aux=0;
    for (int i = 0; i < 19; i+=2)
    {
        vHorarios[i].setHora(aux + 8);
        vHorarios[i].setMinuto(0);
        vHorarios[i + 1].setHora(aux + 8);
        vHorarios[i + 1].setMinuto(30);
        aux++;
        /*vHorarios[i].setHora(i + 8);
        vHorarios[i].setMinuto(30);*/
    }
}
void cargarFechaHoy(Fecha& fechaHoy)
{
    int dia, mes, anio;
    time_t t;
    struct tm* f;
    time(&t);
    f = localtime(&t);
    dia = (f->tm_mday);
    mes = (f->tm_mon + 1);
    anio = (f->tm_year + 1900);
    fechaHoy.setFecha(dia, mes, anio);
}
void cargarFechaMax(Fecha& fechaMax, Fecha& fechaHoy, Fecha* vFechas)
{
    int dia = fechaHoy.getDia();
    int mes = fechaHoy.getMes();
    int anio = fechaHoy.getAnio();
    for (int i = 0; i < 59; i++)
    {
        dia++;
        if (dia > dias_mes(mes, anio))
        {
            dia = 1;
            mes++;
            if (mes > 12)
            {
                mes = 1;
                anio++;
            }
        }
        vFechas[i].setFecha(dia, mes, anio);
        //vFechas[i].setDia(dia);
        //vFechas[i].setMes(mes);
        //vFechas[i].setAnio(anio);
    }
    fechaMax.setFecha(dia, mes, anio);
    //fechaMax.setDia(dia);
    //fechaMax.setMes(mes);
    //fechaMax.setAnio(anio);
}
bool estaEnRangoFecha(int dia, int mes, int anio, Fecha *vFechas)
{
    for (int i = 0; i < 59; i++)
    {
        if (vFechas[i].getDia() == dia && vFechas[i].getMes() == mes && vFechas[i].getAnio() == anio)
        {
            return true;
        }
    }
    return false;
}
bool buscarLegajoMedico(int legajoMedico, Turno& t)
{
    Empleado reg;
    int pos = 0;
    while (reg.leerDeDisco(pos))
    {
        if (reg.getTipoEmpleado()==2 && reg.getLegajo()==legajoMedico)
        {
            t.setLegajoMedico(legajoMedico);
            return true;
        }
        pos++;
    }
    return false;
}
bool existeEspecialidad(int especialidad, Turno& t)
{
    Empleado reg;
    int pos = 0;
    while (reg.leerDeDisco(pos))
    {
        if (reg.getEspecialidad().getNEspecialidades() == especialidad)
        {
            t.setLegajoMedico(reg.getLegajo());
            return true;
        }
        pos++;
    }
    return false;
}
int generarID()
{
    Turno obj;
    bool ok = false;
    int pos = 0;
    srand(time(NULL));
    int nro, desde=1, hasta=100000;
    while (true)
    {
        nro = rand() % (hasta - desde + 1) + desde;
        while (obj.leerDeDisco(pos++))
        {
            if (nro == obj.getID())
            {
                ok = true;
                break;
            }
        }
        if(!ok) return nro;
    }
}
bool empleadoOcupado(/*int legajoMedico, Fecha f, Hora h*/Turno& b)
{
    Turno aux;
    int pos = 0;
    while (aux.leerDeDisco(pos))
    {
        if (aux.getFechaTurno().getDia() == b.getFechaTurno().getDia() && aux.getFechaTurno().getMes() == b.getFechaTurno().getMes() &&
                aux.getFechaTurno().getAnio() == b.getFechaTurno().getAnio())
        {
            if (aux.getLegajoMedico() == b.getLegajoMedico() && aux.getEstado() == true)
            {
                if (aux.getHoraTurno().getHora() == b.getHoraTurno().getHora() && aux.getHoraTurno().getMinuto()
                        == b.getHoraTurno().getMinuto() && b.getFechaTurno().esFeriado() == false )
                {
                    return true;
                }
            }
        }
        pos++;
    }
    return false;
}
void MostrarTurnosPorMedico(Fecha f, Turno *vTurnosDia, int tam, Turno *vTurnosOk)
{
    int b=0, a=0, hora, minuto, dia,mes, anio;
    for (int i = 0; i < tam; i++)
    {
        if (vTurnosDia[i].getEstado() == true)
        {
            b++;
        }
    }
    if (b == tam-1)
    {
        cout << "No hay turnos disponibles." << endl;
        return;
    }
    cout << "Turnos disponibles desde el " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << ": " << endl;
    /*for (int i = 0; i < tam; i++)
    {
    	if (vTurnosDia[i].getEstado() == false) {
    		vTurnosOk[a]=vTurnosDia[i];
    		a++;
    		cout << a << ". ";
    		//vTurnosDia[i].getHoraTurno().Mostrar();
    		//cout << endl;
    		int hora = vTurnosOk[a-1].getHoraTurno().getHora();
    		int minuto = vTurnosOk[a-1].getHoraTurno().getMinuto();
    		int dia = vTurnosOk[a-1].getFechaTurno().getDia();
    		int mes = vTurnosOk[a-1].getFechaTurno().getMes();
    		int anio = vTurnosOk[a-1].getFechaTurno().getAnio();
    		Fecha_Hora FH(hora, minuto, dia, mes, anio);
    		//cout << i + 1 << ". ";
    		FH.Mostrar();
    	}
    	if (a == 20) return;
    }*/
    for (int i = 0; i < tam; i++)
    {
        if (!vTurnosDia[i].getEstado() && !vTurnosDia[i].getFechaTurno().esFeriado())
        {
            vTurnosOk[a] = vTurnosDia[i];
            a++;
            cout << a << ". ";
            hora = vTurnosDia[i].getHoraTurno().getHora();
            minuto = vTurnosDia[i].getHoraTurno().getMinuto();
            dia = vTurnosDia[i].getFechaTurno().getDia();
            mes = vTurnosDia[i].getFechaTurno().getMes();
            anio = vTurnosDia[i].getFechaTurno().getAnio();
            Fecha_Hora FH(hora, minuto, dia, mes, anio);
            FH.Mostrar();
        }
        if (a == 20) return;
    }

}
bool nextDia(Fecha& f, Fecha *vFechas)
{
    int dia = f.getDia();
    int mes = f.getMes();
    int anio = f.getAnio();
    dia++;
    if (dia > dias_mes(mes, anio))
    {
        dia = 1;
        mes++;
        if (mes > 12)
        {
            mes = 1;
            anio++;
        }
    }
    if (estaEnRangoFecha(dia, mes, anio, vFechas))
    {
        f.setFecha(dia, mes, anio);
        return true;
    }
    return false;
}
/*void agregarTurno(Turno& b) {
	Turno aux;
	Hora h;
	int pos = 0, a=0;

		for (int i = 0; i < tam; i++)
		{

			if (empleadoOcupado(legajoMedico, aux, vTurnosDia[i].getHoraTurno()))//que esto figure en turnos.dat
			{
				vTurnosDia[i].setEstado(true);
				//a++;
			}
			else {
				//vTurnosDia[i].setFechaTurno(f);
				//h.setHora(vHorarios[i].getHora());
				//h.setMinuto(vHorarios[i].getMinuto());
				//vTurnosDia[i].setHoraTurno(h);
				vTurnosDia[i].setEstado(false);
				return;
			}
		}
		//if (nextDia(f, vFechas)) a = 0;
			if (!nextDia(aux, vFechas)) {
				cout << "Fin" << endl;
				return;
			}
			//a = 0;
}*/
void turnosDisponiblesPorMedico(int legajoMedico, /*vector<Turno>& vTurnosDia,*/ Fecha& f, Hora* vHorarios, Turno& t, Fecha* vFechas)
{
    Turno vTurnosOk[20];
    Hora h;
    Fecha aux;
    int pos = 0, opcion, a = 1, cont = 0;
    bool b = true;
    for (int i = 0; i < 60; i++)
    {
        cont++;
        if (vFechas[i].getDia() == f.getDia() && vFechas[i].getMes() == f.getMes() && vFechas[i].getAnio() == f.getAnio())
        {
            aux.setFecha(f.getDia(), f.getMes(), f.getAnio());
            i = 60;
        }
    }
    int tam = ((60 - cont)) * 20;
    Turno* vTurnosDia = new Turno[tam];
    for (int i = 0; i < tam; i++)
    {
        if (a == 21)
        {
            nextDia(aux, vFechas);
            a = 1;
        }
        //vTurnosDia[i].setEstado(false);
        vTurnosDia[i].setFechaTurno(aux);
        h.setHora(vHorarios[a - 1].getHora());
        h.setMinuto(vHorarios[a - 1].getMinuto());
        vTurnosDia[i].setHoraTurno(h);
        vTurnosDia[i].setLegajoMedico(legajoMedico);
        //aux = vTurnosDia[i];
        a++;
        Turno b = vTurnosDia[i];
        if (!vTurnosDia[i].getFechaTurno().esFeriado())
        {
            if (empleadoOcupado(b))
            {
                vTurnosDia[i].setEstado(true);
            }
            else
            {
                vTurnosDia[i].setEstado(false);
            }
        }
        else
        {
            vTurnosDia[i].setEstado(true);
        }

        //agregarTurno(vTurnosDia, legajoMedico, aux, vHorarios, vFechas,tam);
        //agregarTurno(b);
    }
    /*for (int i = 0; i < tam; i++)
    {
    	vTurnosDia[i].getFechaTurno().Mostrar();
    	vTurnosDia[i].getHoraTurno().Mostrar();

    }*/

    /*while (a != 20) {
    	for (int i = 0; i < 20; i++)
    	{
    		if (empleadoOcupado(legajoMedico, f, vTurnosDia[i].getHoraTurno())) {
    			vTurnosDia[i].setEstado(true);
    		}
    		else {
    			cont++;
    			vTurnosDia[i].setEstado(false);
    		}
    	}
    	if (!nextDia()) break;
    	a++;
    }*/


    MostrarTurnosPorMedico(f, vTurnosDia, tam, vTurnosOk);

    cout << "Elija una fecha y horario: ";
    cin >> opcion;
    Hora h1;
    int dia, mes, anio;
    h1.setHora(vTurnosOk[opcion - 1].getHoraTurno().getHora());
    h1.setMinuto(vTurnosOk[opcion - 1].getHoraTurno().getMinuto());
    dia = vTurnosOk[opcion - 1].getFechaTurno().getDia();
    mes = vTurnosOk[opcion - 1].getFechaTurno().getMes();
    anio = vTurnosOk[opcion - 1].getFechaTurno().getAnio();
    aux.setFecha(dia, mes, anio);
    /*if (horario % 2 != 0) {
    	h1.setMinuto(0);
    }
    else {
    	h1.setMinuto(30);
    }*/
    t.setHoraTurno(h1);
    t.setFechaTurno(aux);
    t.setEstado(true);

}
/*bool turnosDisponible(int dia, int mes, int anio, int hora, int minuto, int legajoMedico) {
	Turno reg;
	int pos = 0;
	while (reg.leerDeDisco(pos)) {
		if (reg.getFechaTurno().getDia() == dia && reg.getFechaTurno().getMes() == mes && reg.getFechaTurno().getAnio() == anio
			&& reg.getHoraTurno().getHora()==hora && reg.getHoraTurno().getMinuto()==minuto &&
			reg.getLegajoMedico() == legajoMedico && reg.getEstado() == true) {
			return false;
		}
		pos++;
	}
	return true;
}*/
void AsignarTurno()
{
    int dia, mes, anio, hora, minuto, idTurno, idPaciente, DNIPaciente, obraSocial, especialidad = -1, legajoMedico = 0, opcion, opcionTurnoDia;
    bool b = false, x = false, b1 = true;
    Turno t;
    //vector<Turno>vTurnosDia;
    Fecha f, fechaAsignacion, fechaHoy, fechaMax;

    Fecha vFechas[60];
    Hora h;
    Hora vHorarios[20];
    cargarHorarios(vHorarios);
    cargarFechaHoy(fechaHoy);
    cargarFechaMax(fechaMax, fechaHoy, vFechas);
    while (true)
    {
        system("cls");
        cout << "Solo puede asignar turnos hasta el: ";
        fechaMax.Mostrar();
        cout << endl;
        cout << "Asignar turnos por: " << endl;
        cout << "1. Medico." << endl;
        cout << "2.Especialidad." << endl;
        cout << "---------------------------------" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "Ingrese legajo del Medico: ";
            cin >> legajoMedico;
            if (!buscarLegajoMedico(legajoMedico, t))
            {
                b1 = false;
                cout << "El legajo no existe. " << endl;
                system("pause");

            }
            else
            {
                while (true)
                {
                    system("cls");
                    cout << "Ingrese dia: ";
                    cin >> dia;
                    cout << "Ingrese mes: ";
                    cin >> mes;
                    cout << "Ingrese anio: ";
                    cin >> anio;
                    if (f.esCorrecta(dia, mes, anio))
                    {
                        f.setFecha(dia, mes, anio);
                    }

                    /*
                    if (mostrarTurnosDisponiblesDia()) {
                    	cout << "Ingrese una opcion: ";
                    	cin >> opcionTurnoDia;
                    }
                    else {
                    	cout << "No hay turnos disponibles en el dia." << endl;
                    	return;
                    }*/
                    if (estaEnRangoFecha(dia, mes, anio, vFechas))
                    {
                        b = true;
                        if (legajoMedico != 0)
                        {
                            turnosDisponiblesPorMedico(legajoMedico,/*vTurnosDia,*/ f, vHorarios, t, vFechas);
                        }
                        /*else if (especialidad != -1) {
                        	//turnosDisponiblesPorEspecialidad(especialidad);
                        }*/
                        x = true;
                        /*cout << "Ingrese ID Turno: ";
                        cin >> idTurno;*/
                        cout << "Ingrese ID Paciente: ";
                        cin >> idPaciente;
                        cout << "Ingrese DNI del Paciente: ";
                        cin >> DNIPaciente;
                        cout << "Ingrese Obra Social: ";
                        cin >> obraSocial;
                        /*cout << "Ingrese legajo del medico: ";
                        cin >> legajoMedico;*/

                        t.setFechaAsignacionTurno();
                        t.setID(generarID());
                        //t.setID(idTurno);
                        t.setIDPaciente(idPaciente);
                        //t.setDNIPaciente(DNIPaciente);
                        t.setObraSocial(obraSocial);
                        //t.setEspecialidad(especialidad);
                        t.setFechaTurno(f);
                        //t.setLegajoMedico(legajoMedico);
                        t.setEstado(true);
                        if (t.grabarEnDisco(0))
                        {
                            cout << "El turno ha sido reservado." << endl;
                            return;
                        }

                    }
                    else if (!b)
                    {
                        cout << "La fecha ingresada se encuentra fuera del rango permitido. Ingrese nuevamente." << endl;
                        system("pause");
                        continue;
                    }
                    /*if (b && !x) {
                    	cout << "Ya existe un turno asignado en ese rango de fecha, ingrese nuevamente." << endl;
                    	system("pause");
                    }*/
                }
            }
            break;
        case 2:
            cout << "Ingrese especialidad: ";
            cin >> especialidad;
            if (!existeEspecialidad(especialidad, t))
            {
                cout << "La especialidad no existe." << endl;
                system("pause");
                break;
            }
            break;
        case 0:
            return;
            break;
        default:
            cout << "Opcion incorrecta. Vuelta a intentarlo." << endl;
            break;
        }
    }
}
bool turnosDisponible(int dia, int mes, int anio, int hora, int minuto, int legajoMedico)
{
    Turno reg;
    int pos = 0;
    while (reg.leerDeDisco(pos))
    {
        if (reg.getFechaTurno().getDia() == dia && reg.getFechaTurno().getMes() == mes && reg.getFechaTurno().getAnio() == anio
                && reg.getHoraTurno().getHora()==hora && reg.getHoraTurno().getMinuto()==minuto &&
                reg.getLegajoMedico() == legajoMedico && reg.getEstado() == true)
        {
            return false;
        }
        pos++;
    }
    return true;
}

///Cuenta y devuelve la cantidad de registros que hay en el archivo de pacientes
int ContarCantidadRegistrosPacientes()
{

    Paciente reg;
    int pos = 0;
    while (reg.leerDeDisco(pos)==true)
    {
        pos++;

    }

    return pos;
}

int ContarCantidadRegistrosEmpleados()
{
    Empleado reg;
    int pos = 0;
    int Cont = 0; ///CUENTA LA CANTIDAD DE VECES QUE ENCUENTRE UN REGISTRO CON NUMERO DE EMPLEADO = 1 (Administrativo)
    while (reg.leerDeDisco(pos)==true)
    {
        if(reg.getTipoEmpleado()==1)
        {
            Cont++;
        }
        pos++;
    }
    return Cont;


}


int ContarCantidadRegistroTurnos()
{

    Turno reg;
    int pos = 0;
    while (reg.leerDeDisco(pos)==true)
    {
        pos++;
    }
    return pos;


}

void CopiarRegistros(Paciente *p, int cantRegistros)
{
    for (int x = 0; x < cantRegistros; x++)
    {
        p[x].leerDeDisco(x);

    }

}


void CopiarRegistrosEmpleadoAdminitrativo(Empleado *p, int cantRegistros)
{
    Empleado reg;
    int Indice = 0;
    int Pos = 0;
    while(reg.leerDeDisco(Pos)==true)
    {
        if(reg.getTipoEmpleado()==1)
        {
            p[Indice] = reg;
            Indice++;
        }
        Pos++;
    }

}

void CopiarRegistrosTurnos(Turno *p, int cantRegistros)
{

    for (int x = 0; x < cantRegistros; x++)
    {
        p[x].leerDeDisco(x);

    }

}


///Ordena el vector de pacientes por apellido en orden alfabetico
void OrdenarRegistrosPorNombre(Paciente *p, int cantRegistros)
{

    int i, j;

    Paciente aux;

    for(i=0; i<cantRegistros; i++)
    {

        for(j=0; j<cantRegistros-1; j++)
        {
            if(strcmp(p[j].getApellidos(),p[j+1].getApellidos())>0)
            {

                aux = p[j+1];
                p[j+1]=p[j];
                p[j] = aux;
            }
        }
    }
}


void OrdenarRegistrosAdminitrativoPorLegajo(Empleado *p, int cantRegistros)
{

    int i, j;

    Empleado aux;

    for(i=0; i<cantRegistros; i++)
    {

        for(j=0; j<cantRegistros-1; j++)
        {
            if(p[j].getLegajo() < p[j+1].getLegajo())
            {

                aux = p[j+1];
                p[j+1]=p[j];
                p[j] = aux;
            }
        }
    }

}


void OrdenarRegistrosAdminitrativoPorNombre(Empleado *p, int cantRegistros)
{

    int i, j;

    Empleado aux;

    for(i=0; i<cantRegistros; i++)
    {

        for(j=0; j<cantRegistros-1; j++)
        {
            if(strcmp(p[j].getApellidos(),p[j+1].getApellidos())>0)
            {

                aux = p[j+1];
                p[j+1]=p[j];
                p[j] = aux;
            }
        }
    }

}

void OrdenarTurnosPorFecha(Turno *p, int cantRegistros)
{

    int i, j;

    Turno aux;
    Fecha f1;

    for(i=0; i<cantRegistros; i++)
    {

        for(j=0; j<cantRegistros-1; j++)
        {

            f1 = p[j+1].getFechaTurno();
            if(p[j].getFechaTurno() < f1)
            {

                aux = p[j+1];
                p[j+1]=p[j];
                p[j] = aux;
            }
        }
    }

}


void MostrarPacientes(Paciente *p, int cantRegistros)
{

    for (int x = 0; x < cantRegistros; x++)
    {
        p[x].Mostrar();
        cout << endl;
    }

}


void MostrarEmpleadosAdministrativos(Empleado *p, int cantRegistros)
{

    for (int x = 0; x < cantRegistros; x++)
    {
        p[x].Mostrar();
        cout << endl;
    }

}

void MostrarTurnos(Turno *p, int cantRegistros)
{
    for (int x = 0; x < cantRegistros; x++)
    {
        p[x].Mostrar();
        cout << endl;
    }

}


///NO ESTA COMPLETO, PORQUE PACIENTE NO TIENE NINGUN ATRIBUTO QUE SEA LA EDAD DEL PACIENTE
void OrdenarRegistrosPorEdad(Paciente *p, int cantRegistros)
{
    ///ACA USO EL ALGORITMO DE BURBUJA PARA ORDENAR A LOS PACIENTES POR LA EDAD
    int i, j;
    Paciente aux;

    for(i = 0; i < cantRegistros; i++)
    {
        for (j = 0; j < cantRegistros-1; j++)
        {

            if(p[j].getEdad() < p[j+1].getEdad())
            {
                aux = p[j+1];
                p[j+1] = p[j];
                p[j] = aux;

            }

        }
    }
}


void OrdenarRegistrosPorCiudad(Paciente *p, int cantRegistros)
{



    int i, j;
    Paciente aux;

    for(i = 0; i < cantRegistros; i++)
    {
        for (j = 0; j < cantRegistros-1; j++)
        {
            if(strcmp(p[j].getDireccionPaciente().getLocalidad(),p[j+1].getDireccionPaciente().getLocalidad())>0)
            {
                aux = p[j+1];
                p[j+1] = p[j];
                p[j] = aux;
            }
        }
    }
}

///OBTRNER MINIMO, BUSCA UN REGISTRO QUE CONTENGA EL ANIO MINIMO EN EL ARCHIVO, facturaconsulta
int BuscarAnioMinFactura()
{

    FacturaConsulta reg;

    int b = 0;
    int AnioMin = 0;
    int Pos = 0;

    while(reg.leerDeDisco(Pos)==true)
    {
        if(b == 0)
        {
            AnioMin = reg.getFechaFactura().getAnio();
            b++;
        }

        else
        {
            if(reg.getFechaFactura().getAnio()<AnioMin)
            {
                AnioMin = reg.getFechaFactura().getAnio();
            }
        }
        Pos++;
    }
    return AnioMin;
}

///OBTRNER MAXIMO
int BuscarAnioMaxFactura()
{

    FacturaConsulta reg;
    int Pos = 0, b = 0;
    int AnioMax = 0;
    while(reg.leerDeDisco(Pos)==true)
    {

        if(b == 0)
        {
            AnioMax = reg.getFechaFactura().getAnio();
            b++;
        }

        else
        {
            if(reg.getFechaFactura().getAnio()>AnioMax)
            {
                AnioMax = reg.getFechaFactura().getAnio();
            }
        }

        Pos++;
    }

    return AnioMax;
}


void ModificarTurno()
{

    Turno reg;
    int ID;
    cout << "Ingrese el ID turno que desea modificar" << endl;
    cin >> ID;
    cout << endl;

    int Pos = 0;

    while (reg.leerDeDisco(Pos) == true)
    {

        /*
        int getID();
        int getIDPaciente();
        int getObraSocial();
        Fecha_Hora getFechaTurno();
        Fecha_Hora getFechaAsignacionTurno();
        int getLegajoMedico();
        bool getAsistencia();
        bool getEstado();
        */

        if (reg.getID() == ID && reg.getEstado() == true)
        {
            int IDPaciente, ObraSocial, hora, minuto, dia, mes, anio, horaA, minutoA, diaA, mesA, anioA, LegajoMedico;
            bool Asistencia, Estado;

            cout << "Ingrese el ID del paciente: ";
            cin >> IDPaciente;
            cout << "Ingrese la obra social: ";
            cin >> ObraSocial;
            cout << "Ingrese la hora del turno: ";
            cin >> hora;
            cout << "Ingrese los minutos del turno: ";
            cin >> minuto;
            cout << "Ingrese el dia del turno: ";
            cin >> dia;
            cout << "Ingrese el mes del turno: ";
            cin >> mes;
            cout << "Ingrese el anio del turno: ";
            cin >> anio;
            Fecha f1(dia, mes, anio);
            cout << "Ingrese el dia que se asigno el turno: ";
            cin >> diaA;
            cout << "Ingrese el mes que se asigno turno: ";
            cin >> mesA;
            cout << "Ingrese el anio que se asigno el turno: ";
            cin >> anioA;
            cout << "Ingrese el legajo medico: ";
            cin >> LegajoMedico;
            /*
            cout << "Ingrese la asistencia: ";
            cin >> Asistencia;
            cout << "Ingrese el estado: ";
            cin >> Estado;
            */

            reg.setIDPaciente(IDPaciente);
            reg.setObraSocial(ObraSocial);
            reg.setFechaTurno(f1);
            //reg.setFechaAsignacionTurno();
            reg.setLegajoMedico(LegajoMedico);
            //reg.setAsistencia(Asistencia);
            //reg.setEstado(Estado);
            reg.grabarEnDisco(Pos);
            return;


        }

        Pos++;
    }

}

///ESTA FUNCION PERTENECE ListadoDePacientes
void ListadoDePacientesPorApellido()
{
    int cantRegistros;
    ///Cuenta la cantidad de registros que hay en el archivo de paciente
    ///Se puede hacer con ftell
    cantRegistros = ContarCantidadRegistrosPacientes();

    if(cantRegistros == 0)
    {
        cout << "NO HAY REGISTROS EN EL ARCHIVO DE PACIENTES, O EL ARCHIVO NO EXISTE" << endl;
        return;
    }

    Paciente *p;
    p = new Paciente [cantRegistros];

    if(p == NULL)
    {
        cout << "NO SE PUDO OBTENER MEMORIA DINAMICA PARA EL VECTOR DE PACIENTES" << endl;
        return;
    }

    ///Esta funcion copia todos los registros del archivo de pacientes a un vector de pacientes
    CopiarRegistros(p, cantRegistros);

    OrdenarRegistrosPorNombre(p, cantRegistros);

    MostrarPacientes(p, cantRegistros);

    delete p; //Comente este delete porque sino el programa me hacia un return raro

}




///ESTA FUNCION PERTENECE ListadoDePacientes
void PorEdad()
{

    int cantRegistros = 0;
    ///Cuenta la cantidad de registros que hay en el archivo de paciente
    cantRegistros = ContarCantidadRegistrosPacientes();

    if(cantRegistros == 0)
    {
        cout << "NO HAY REGISTROS EN EL ARCHIVO DE PACIENTES, O EL ARCHIVO NO EXISTE" << endl;
        return;
    }

    Paciente *p;
    p = new Paciente [cantRegistros];

    if(p == NULL)
    {
        cout << "NO SE PUDO OBTENER MEMORIA DINAMICA PARA EL VECTOR DE PACIENTES" << endl;
        return;
    }



    ///Esta funcion copia todos los registros del archivo de pacientes a un vector de pacientes
    CopiarRegistros(p, cantRegistros);

    ///ORDENA LOS PACIENTE POR EDAD DE MAYOR A MENOR, USA EL MOTODO BURBUJA
    OrdenarRegistrosPorEdad(p, cantRegistros);

    MostrarPacientes(p, cantRegistros);

    ///delete p; Comente este delete porque sino el programa me hacia un return raro
}

///ESTA FUNCION PERTENECE ListadoDePacientes
void PorCiudad()
{

    int cantRegistros;
    ///Cuenta la cantidad de registros que hay en el archivo de paciente
    cantRegistros = ContarCantidadRegistrosPacientes();

    if(cantRegistros == 0)
    {
        cout << "NO HAY REGISTROS EN EL ARCHIVO DE PACIENTES, O EL ARCHIVO NO EXISTE" << endl;
        return;
    }

    Paciente *p;
    p = new Paciente [cantRegistros];

    if(p == NULL)
    {
        cout << "NO SE PUDO OBTENER MEMORIA DINAMICA PARA EL VECTOR DE PACIENTES" << endl;
        return;
    }

    ///Esta funcion copia todos los registros del archivo de pacientes a un vector de pacientes
    CopiarRegistros(p, cantRegistros);

    OrdenarRegistrosPorCiudad(p, cantRegistros);

    MostrarPacientes(p, cantRegistros);


    //delete p;

}

///--------------------------------------------
///NO ESTA TERMINADA
void ListadoAdministrativosOrdenadoPorLegajo()
{

    int cantRegistros;
    ///Cuenta la cantidad de registros que hay en el archivo de paciente
    cantRegistros = ContarCantidadRegistrosEmpleados();

    if(cantRegistros == 0)
    {
        cout << "NO HAY REGISTROS DE ADMINISTRATIVOS EN EL ARCHIVO DE EMPLEADOS" << endl;
        return;
    }

    Empleado *p;
    p = new Empleado [cantRegistros];

    if(p == NULL)
    {
        cout << "NO SE PUDO OBTENER MEMORIA DINAMICA PARA EL VECTOR DE EMPLEADOS" << endl;
        return;
    }

    CopiarRegistrosEmpleadoAdminitrativo(p, cantRegistros);

    OrdenarRegistrosAdminitrativoPorLegajo(p, cantRegistros);

    MostrarEmpleadosAdministrativos(p, cantRegistros);


    //delete p;


}


void ListadoAdministrativosOrdenadoPorNombre()
{

    int cantRegistros;
    ///Cuenta la cantidad de registros que hay en el archivo de paciente
    cantRegistros = ContarCantidadRegistrosEmpleados();

    if(cantRegistros == 0)
    {
        cout << "NO HAY REGISTROS DE ADMINISTRATIVOS EN EL ARCHIVO DE EMPLEADOS" << endl;
        return;
    }

    Empleado *p;
    p = new Empleado [cantRegistros];

    if(p == NULL)
    {
        cout << "NO SE PUDO OBTENER MEMORIA DINAMICA PARA EL VECTOR DE EMPLEADOS" << endl;
        return;
    }

    CopiarRegistrosEmpleadoAdminitrativo(p, cantRegistros);

    OrdenarRegistrosAdminitrativoPorNombre(p, cantRegistros);

    MostrarEmpleadosAdministrativos(p, cantRegistros);

    //delete p;


}


void ListadoDeTurnosOrdenadosPorFecha()
{

    int cantRegistros;
    ///Cuenta la cantidad de registros que hay en el archivo de paciente
    cantRegistros = ContarCantidadRegistroTurnos();

    if(cantRegistros == 0)
    {
        cout << "NO HAY REGISTROS DE ADMINISTRATIVOS EN EL ARCHIVO DE EMPLEADOS" << endl;
        return;
    }

    Turno *p;
    p = new Turno [cantRegistros];

    if(p == NULL)
    {
        cout << "NO SE PUDO OBTENER MEMORIA DINAMICA PARA EL VECTOR DE EMPLEADOS" << endl;
        return;
    }

    CopiarRegistrosTurnos(p, cantRegistros);

    OrdenarTurnosPorFecha(p, cantRegistros);

    MostrarTurnos(p, cantRegistros);

///delete p;
}


void ListadoDeTurnosOrdenadosPorEspecialidad()
{




}


///------------------------------------------------------------------

///ESTA FUNCION PERTENECE A ConsultaDePaciente, no tenia que hacerlo yo xd
void ConsultaPorDni()
{

    int DNI;

    cout << "Ingrese el Dni del paciente que desea buscar" << endl;
    cin >> DNI;
    cout << endl;

    Paciente reg;

    int Pos = 0;
    while(reg.leerDeDisco(Pos)==true)
    {

        if(reg.getDNI()==DNI)
        {
            reg.Mostrar();
            return;
        }
        Pos++;
    }
    cout << "No existe ningun paciente con ese Dni" << endl;

}

///----------------------------------------------------------------

///ESTA FUNCION PERTENECE A ConsultaDePagos
void ConsultaPorRangoFecha()
{


    Fecha fecha1;
    int Dia_Inicial = 1;
    int Mes_Inicial;
    int Anio_Inicial;
    Fecha fecha2;
    int Dia_Final;
    int Mes_Final;
    int Anio_Final;
    while(Dia_Inicial != 0)
    {


        int Cont = 0;
        cout << "---------------BUSCAR PAGO POR RANGO DE FECHA---------------" << endl; ///Esto no se si dejarlo o sacarlo

        cout << "Ingrese el dia, el mes y el anio de la fecha inicial (Ingrese un dia inicial igual a 0 para volver al menu)" << endl;
        cout << "Ingrese el dia: ";
        cin >> Dia_Inicial;

        if(Dia_Inicial != 0)
        {
            cout << "Ingrese el mes: ";
            cin >> Mes_Inicial;
            cout << "Ingrese el anio: ";
            cin >> Anio_Inicial;
            cout << endl;
            cout << "Ingrese el dia, el mes y el anio de la fecha final" << endl;
            cout << "Ingrese el dia: ";
            cin >> Dia_Final;
            cout << "Ingrese el mes: ";
            cin >> Mes_Final;
            cout << "Ingrese el anio: ";
            cin >> Anio_Final;
            cout << endl;







            FacturaConsulta reg;

            int Pos = 0;
            while(reg.leerDeDisco(Pos)==true)
            {

                if(reg.getFechaFactura() > fecha1 && reg.getFechaFactura() < fecha2)
                {
                    Cont++;
                    reg.Mostrar();
                    cout << endl;
                }
                Pos++;
            }

            if(Cont == 0)
            {
                cout << "NO EXISTE UN PAGO QUE SE ENCUENTRE DENTRO DEL RANGO DE LAS DOS FECHAS INGRESADAS, INGRESE OTRAS FECHAS" << endl << endl;
            }

            system("pause");
            system("cls");

        }

    }





}


///ESTA FUNCION PERTENECE A ConsultaDePagos
void ConsultaPorCliente()
{

    int DniPaciente;

    while(DniPaciente !=0)
    {
        int Cont = 0;
        cout << "---------------BUSCAR PAGO POR CLIENTE---------------" << endl; ///Esto no se si dejarlo o sacarlo

        cout << "Ingrese el DNI del paciente que desea buscar (ingrese 0 para volver al menu)" << endl;
        cin >> DniPaciente;
        cout << endl;

        if(DniPaciente != 0)
        {

            FacturaConsulta reg;

            int Pos = 0;
            while(reg.leerDeDisco(Pos)==true)
            {

                if(reg.getDniPaciente()==DniPaciente)
                {

                    Cont++;
                    reg.Mostrar();
                    cout << endl;

                }
                Pos++;
            }

            if(Cont == 0)
            {
                cout << "NO EXISTE UN PAGO CON ESE NUMERO DE DNI, INTENTE CON OTRO NUMERO" << endl << endl;
            }

            system("pause");
            system("cls");
        }

    }

}

///ESTA FUNCION PERTENECE A CONSULTA DE PAGOS
void ConsultaPorObraSocial()
{

    int ObraSocial = 1;


    while(ObraSocial >= 0)
    {
        int Cont = 0;
        cout << "---------------BUSCAR PAGO POR OBRA SOCIAL---------------" << endl; ///Esto no se si dejarlo o sacarlo
        cout << "Ingrese la obra social del pago que desea buscar (ingrese un numero negativo para volver al menu)" << endl;
        cin >> ObraSocial;
        cout << endl;

        if(ObraSocial >= 0)
        {

            FacturaConsulta reg;

            int Pos = 0;
            while(reg.leerDeDisco(Pos)==true)
            {

                if(reg.getObraSocial()==ObraSocial)
                {
                    Cont++;
                    reg.Mostrar();
                    cout << endl;

                }
                Pos++;
            }

            if(Cont == 0)
            {
                cout << "NO EXISTE UN PAGO CON ESE NUMERO DE OBRA SOCIAL, INTENTE CON OTRO NUMERO" << endl << endl;
            }


            system("pause");
            system("cls");
        }

    }

}

/// ESTA FUNCION PERTENECE A ConsultaDePagos
void ConsultaPorAdministrativo()
{

    FacturaConsulta reg;

    int LegajoAdministrativo = 1;
    while(LegajoAdministrativo != 0)
    {
        int Cont = 0;
        cout << "---------------BUSCAR PAGO POR ADMINISTRATIVO QUE LO TOMO---------------" << endl; ///Esto no se si dejarlo o sacarlo
        cout << "Ingrese el legajo del administrativo que desea buscar (Ingrese 0 para volver al menu)" << endl;
        cin >> LegajoAdministrativo;
        cout << endl;

        if(LegajoAdministrativo !=0)
        {
            int Pos = 0;
            while(reg.leerDeDisco(Pos)==true)
            {

                if(reg.getLegajoAdministrativo()==LegajoAdministrativo)
                {
                    Cont++;
                    reg.Mostrar();
                    cout << endl;
                }
                Pos++;
            }


            if(Cont == 0)
            {
                cout << "EL NUMERO DE LEGAJO INGRESADO NO EXISTE EN EL ARCHIVO DE PACIENTES, INGRESE OTRO NUMERO" << endl;
            }

            system("pause");
            system("cls");
        }

    }
}




///ESTA FUNCION PERTENECE A INFORMES
void RecaudacionMensual()
{

    int AnioIngresado  = 1;
    int MesIngresado;
    while(AnioIngresado !=0)
    {
        cout << "------------------Recaudacion Mensual------------------" << endl;
        cout << "Ingrese el anio en el quiera ver la recaudacion total de ese anio (Ingrese 0 para volver al menu)" << endl;
        cin >> AnioIngresado;
        cout << endl;

        if(AnioIngresado != 0)
        {

            cout << "Ingrese el mes en el que quiera ver la recaudacion total de ese anio" << endl;
            cin >> MesIngresado;
            cout << endl;


            ///Puedo usar el ftell()
            int CantRegistros = ContarCantidadRegistrosPacientes();
            int AnioMin, AnioMax;

            FacturaConsulta reg;

            AnioMin = BuscarAnioMinFactura();
            AnioMax = BuscarAnioMaxFactura();


            ///CREA UNA MATRIZ DINAMICA, PIDO MEMORIA PARA ESA MATRIZ
            int tam = (AnioMax - AnioMin) + 1; ///Este el tamanio de la cantidad de filas de la matriz
            float **p;
            int c = 12; /// Meses del anio (Columnas de la matriz)
            p = new float *[tam];


            for (int x = 0; x < tam; x++)
            {
                p[x] = new float [c];
            }


            ///PONE CADA ELEMENTO DE LA MATRIZ EN 0
            for(int x = 0; x < tam; x++)
            {
                for (int j = 0; j < c; j++)
                {
                    p[x][j]=0;
                }
            }


            ///ASIGNA RECAUDACION DE LOS ANIOS A LA MATRIZ DINAMICA
            int Pos = 0;
            float RecaudacionTotal = 0; ///ACA SE GUARDA LA RECAUDACION TOTAL DE TODOS LOS MESES DEL ANIO INGRESADO
            ///Valida que el anio y el mes ingresado se encuentre en el archivo de facturaconsulta

            if(AnioIngresado >=AnioMin && AnioIngresado <= AnioMax && MesIngresado <= 12 && MesIngresado > 0)
            {

                while(reg.leerDeDisco(Pos)==true)
                {
                    p[reg.getFechaFactura().getAnio()-AnioMin][reg.getFechaFactura().getMes()-1]+=reg.getPrecioConsulta();
                    //RecaudacionTotal +=reg.getPrecioConsulta();
                    Pos++;
                }

                cout << "Anio: " << AnioIngresado << endl << endl;
                cout << "RECAUDACION DEL MES\t\t\t\tRECAUACION" << endl;
                cout << "------------------------------------------------------------"<<endl;

                ///Muestra la recaudacion del anio y mes que se ingresaron por teclado
                cout << MesIngresado << "\t\t\t\t\t\t   " << p[AnioIngresado - AnioMin][MesIngresado-1] << endl<<endl;



            }

            else
            {
                cout << "EL ANIO Y/O MES INGRESADO NO SE ENCUENTRAN EN EL ARCHIVO, INTENTE CON OTRO MES Y/O ANIO " << endl;
            }

            system("pause");
            system("cls");
            /*
                     ///Libera la memoria de la matriz
                    for (int x = 0; x < CantRegistros; x++)
                    {
                        delete p[x];
                    }
            */
        }

    }

}


///ESTA FUNCION PERTENECE A INFORMES
void RecaudacionAnual()
{

    int AnioIngresado = 1;
    while(AnioIngresado !=0)
    {
        cout << "------------------Recaudacion Anual------------------" << endl;
        cout << "Ingrese el anio en el quiera ver la recaudacion total de ese anio (Ingrese 0 para volver al menu)" << endl;
        cin >> AnioIngresado;
        cout << endl;

        if(AnioIngresado!=0)
        {
///Puedo usar el ftell()
            int CantRegistros = ContarCantidadRegistrosPacientes();
            int AnioMin, AnioMax;

            FacturaConsulta reg;

            AnioMin = BuscarAnioMinFactura();
            AnioMax = BuscarAnioMaxFactura();

///CREA UNA MATRIZ DINAMICA, PIDO MEMORIA PARA ESA MATRIZ
            int tam = (AnioMax - AnioMin) + 1; ///Este el tamanio de la cantidad de filas de la matriz
            float **p;
            int c = 12; /// Meses del anio (columnas de la matriz)
            p = new float *[tam];


            for (int x = 0; x < tam; x++)
            {
                p[x] = new float [c];
            }


            ///PONE CADA ELEMENTO DE LA MATRIZ EN 0
            for(int x = 0; x < tam; x++)
            {
                for (int j = 0; j < c; j++)
                {
                    p[x][j]=0;
                }
            }



///ASIGNA RECAUDACION DE LOS ANIOS A LA MATRIZ DINAMICA
            int Pos = 0;
            float RecaudacionTotal = 0; ///ACA SE GUARDA LA RECAUDACION TOTAL DE TODOS LOS MESES DEL ANIO INGRESADO
            ///Valida que el anio ingresado se encuentre en el archivo de facturaconsulta
            if(AnioIngresado >= AnioMin && AnioIngresado <= AnioMax)
            {
                while(reg.leerDeDisco(Pos)==true)
                {
                    p[reg.getFechaFactura().getAnio()-AnioMin][reg.getFechaFactura().getMes()-1]+=reg.getPrecioConsulta();
                    RecaudacionTotal +=reg.getPrecioConsulta();
                    Pos++;
                }

                cout << "La recaudacion del anio " << AnioIngresado << " fue: " << endl << endl;
                cout << "MES\t\t\t\tRECAUACION" << endl;
                cout << "-------------------------------------------------------"<<endl;
                for (int x = 0; x < 12; x++)
                {

                    cout << x+1 << "\t\t\t\t   " << p[AnioIngresado - AnioMin][x] << endl;
                }

                cout << "-------------------------------------------------------"<<endl;
                cout << "TOTAL:\t\t\t\t   " << RecaudacionTotal << endl << endl;
            }

            else
            {
                cout << "El anio que ingreso no se encuentra en el archivo, intente con otro anio" << endl;
            }
            /*
                ///Libera la memoria de la matriz
                for (int x = 0; x < CantRegistros; x++)
                {
                    delete p[x];
                }
            */

            system("pause");
            system("cls");
        }
    }



}

///ESTA FUNCION PERTENECE A Informes
void RecaudacionPorCliente()
{


    int DniCliente = 1;
    FacturaConsulta reg;
    while(DniCliente !=0)
    {
        int Cont = 0;
        cout << "--------------------Recaudacion por cliente--------------------" << endl;
        cout << "Ingrese el DNI de algun cliente para ver su recaudacion: (Ingrese 0 para volver al menu)" << endl;
        cin >> DniCliente;
        cout << endl;

        if(DniCliente!=0)
        {

            int Pos = 0;
            float Recaudacion = 0; ///ACA SE ACUMULA LA RECAUDACION DEL CLIENTE QUE SE BUSCA

            ///ESTO RECORRE EL ARCHIVO DE FACTURAS PARA ACUMULAR LA RECAUDACION
            ///DEL CLIENTE QUE SE INGRESO POR TECLADO
            while (reg.leerDeDisco(Pos)==true)
            {
                if(reg.getDniPaciente()==DniCliente)
                {
                    Recaudacion += reg.getPrecioConsulta();
                    Cont++;
                }

                Pos++;
            }

            if(Cont !=0)
            {

                Paciente obj;
                Pos = 0;
                ///BUSCA EL DNI QUE SE INGRESO EN EL ARCHIVO DE PACIENTES EL
                ///DNI QUE SE INGRESO POR TECLADO, PARA PODER MOSTRAR
                ///EL NOMBRE Y EL APELLIDO DEL CLIENTE

                while(obj.leerDeDisco(Pos)==true)
                {
                    if(obj.getDNI()==DniCliente)
                    {
                        cout << "Cliente\t\t\t\tTotal Recaudado" << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << obj.getNombres() << " " <<obj.getApellidos() << "\t\t\t\t $" << Recaudacion << endl << endl;
                    }
                    Pos++;
                }

            }

            else
            {
                cout << "No existe niguna factura con el numero de dni ingresado, intente con otro numero" << endl << endl;
            }

            system("pause");
            system("cls");
        }


    }

}


///ESTA FUNCION PERTENECE A Configuracion > ExportarDatos
void ExportarPacientes()
{

    Paciente reg;
    //reg.GrabarEnDisco(0);  ///Esta linea la use para grabar un objeto de tipo paciente a un archivo de pacientes


    ofstream File;
    int Pos = 0;
    File.open("csv/pacientes.csv"); //Este es el direcctorio adonde se guarda el archivo csv
    File <<";"<<"DNI"<<";"<<"Nombres"<<";"<<"Apellidos"<<";"<<"Edad";
    File <<";"<<"ID"<<";"<<"Telefono"<<";"<<"Email";
    File <<";"<<"Calle"<<";"<<"Localidad"<<";"<<"Partido"<<";"<<"Provincia"<<";"<<"CodigoPostal"<<";"<<"Pais"<<";"<<"Estado"<<endl;


    while(reg.leerDeDisco(Pos)==true) //Esto carga a un objeto de tipo paciente un registro de un archivo de oacientes
    {
        ///Esto convierte lo que esta cargado en el objeto de tipo paciente a un archivo csv y lo guarda ahi
        File <<";"<<reg.getDNI()<<";"<<reg.getNombres()<<";"<<reg.getApellidos()<<";"<<reg.getEdad();
        File <<";"<<reg.getID()<<";"<<reg.getTelefono()<<";"<<reg.getEmail();
        File <<";"<<reg.getDireccionPaciente().getCalle()<<";"<<reg.getDireccionPaciente().getLocalidad()<<";"<<reg.getDireccionPaciente().getPartido();
        File <<";"<<reg.getDireccionPaciente().getProvincia()<<";"<<reg.getDireccionPaciente().getCodigoPostal()<<";"<<reg.getDireccionPaciente().getCodigoPostal();
        File <<";"<<reg.getEstado()<<endl;
        Pos++;
    }

}


void ExportarTurnos()
{

    Turno reg;
    //reg.grabarEnDisco(0);  ///Esta linea la use para grabar un objeto de tipo Turno a un archivo de Turnos

    ofstream File;
    File.open("csv/Turnos.csv"); //Este es el direcctorio adonde se guarda el archivo csv


    File <<";"<<"ID"<<";"<<"IDPaciente"<<";"<<"ObraSocial";
    File <<";"<<"Dia del turno"<<";"<<"Mes del turno"<<";"<<"Anio del turno";
    File <<";"<<"Hora del turno"<<";"<<"Minuto del turno";
    File <<";"<<"Dia asignacion turno"<<";"<<"Mes asignacion turno"<<";"<<"Anio asignacion turno";
    File <<";"<<"LegajoMedico"<<";"<<"Asistencia"<<";"<<"Estado"<< endl;

    int Pos = 0;
    while (reg.leerDeDisco(Pos)==true) //Esto carga a un objeto de tipo Turno un registro de un archivo de Turnos
    {
        ///Esto convierte lo que esta cargado en el objeto de tipo Turno a un archivo csv y lo guarda ahi
        File <<";"<<reg.getID()<<";"<<reg.getIDPaciente()<<";"<<reg.getObraSocial();
        File <<";"<<reg.getFechaTurno().getDia()<<";"<<reg.getFechaTurno().getMes()<<";"<<reg.getFechaTurno().getAnio();
        File <<";"<<reg.getHoraTurno().getHora()<<";"<<reg.getHoraTurno().getMinuto();
        File <<";"<<reg.getFechaAsignacionTurno().getDia()<<";"<<reg.getFechaAsignacionTurno().getMes()<<";"<<reg.getFechaAsignacionTurno().getAnio();
        File <<";"<<reg.getLegajoMedico()<<";"<<reg.getAsistencia()<<";"<<reg.getEstado()<<endl;
        Pos++;
    }


}



void ExportarPagosConsultas()
{

    FacturaConsulta reg;
    //reg.grabarEnDisco(0);  ///Esta linea la use para grabar un objeto de tipo FacturaConsulta a un archivo de FacturaConsulta

    ofstream File;
    File.open("csv/FacturasConsultas.csv"); //Este es el direcctorio adonde se guarda el archivo csv


    File <<";"<<"ID"<<";"<<"PrecioConsulta"<<";"<<"IDPaciente"<<";"<<"ObraSocial";
    File <<";"<<"DiaFactura"<<";"<<"MesFactura"<<";"<<"AnioFactura";
    File <<";"<<"DiaTurno"<<";"<<"MesTurno"<<";"<<"AnioTurno";
    File <<";"<<"LegajoAdmin"<<";"<<"FormaPago"<<endl;

    int Pos = 0;

    while(reg.leerDeDisco(Pos)==true)
    {
        ///Esto convierte lo que esta cargado en el objeto de tipo FacturaConsulta a un archivo csv y lo guarda ahi
        ///Falta el get de precioconsulta
        File <<";"<<reg.getID()<<";"<<"precioConsul"<<";"<<reg.getIDPaciente()<<";"<<reg.getObraSocial();
        File <<";"<<reg.getFechaFactura().getDia()<<";"<<reg.getFechaFactura().getMes()<<";"<<reg.getFechaFactura().getAnio();
        File <<";"<<reg.getFechaTurno().getDia()<<";"<<reg.getFechaTurno().getMes()<<";"<<reg.getFechaTurno().getAnio();
        File <<";"<<reg.getLegajoAdministrativo()<<";"<<reg.getFormaPago()<<endl;
        Pos++;
    }


}



void ExportarHistoriasClinicas()
{

    HistoriaClinica reg;
    //reg.grabarEnDisco(0);  ///Esta linea la use para grabar un objeto de tipo HistoriaClinica a un archivo de HistoriaClinica

    ofstream File;
    File.open("csv/HistoriasClinicas.csv"); //Este es el direcctorio adonde se guarda el archivo csv


    File <<";"<<"IDTurno"<<";"<<"DetallesConsulta"<<endl;
    int Pos = 0;

    while(reg.leerDeDisco(Pos)==true)
    {

        File<<";"<<reg.getIDTurno()<<";"<<reg.getDetallesConsulta()<<endl;
        Pos++;
    }


}



void ExportarEmpleados()
{

    Empleado reg;
    //reg.grabarEnDisco(0);  ///Esta linea la use para grabar un objeto de tipo Empleado a un archivo de Empleado

    ofstream File;
    File.open("csv/Empleados.csv"); //Este es el direcctorio adonde se guarda el archivo csv

    /*private:
    int _legajo;
    char _password[30];
    char _email[50];
    int _tipoEmpleado;
    Especialidad _especialidad;
    HorarioEmpleado _horarioEntradaSalida;
    bool _estado;*/

    /*
        class Especialidad
        private:
    	int _IDEmpleado;
    	char _especialidades[12][20];
    	int _nEspecialidades;
    	*/

    //class HorarioEmpleado
    /* private:
    int _IDEmpleado;
    char _dias[7][11];
    bool _diasATrabajar[7];
    Hora _horaEntrada[7];
    Hora _horaSalida[7];
    bool _estado; */

    ///Aca tengo un problema con _especialidad > Esoecialidades
    File <<";"<<"Legajo"<<";"<<"Password"<<";"<<"Email"<<";"<<"TipoEmpleado";
    File <<";"<<"IDEmpleado"<<";"<<"Especialidades"<<";"<<"NEspecialidades";
    //File <<";"<<"IDempleado"<<";"<<"Dias"<<";"<<"DiasAtrabajar"<<";"<<
}



void ExportarTodosLosArchivos()
{

    ExportarPacientes();

    ExportarTurnos();

    ExportarPagosConsultas();

    ExportarHistoriasClinicas();

    ExportarEmpleados();


}
