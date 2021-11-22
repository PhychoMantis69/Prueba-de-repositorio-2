#include <iostream>
#include "Direccion.h"
#include "Empleado.h"
#include "FacturaConsulta.h"
#include "Fecha.h"
#include "HistoriaClinica.h"
#include "Hora.h"
#include "Paciente.h"
#include "Persona.h"
#include "Turno.h"
#include "FuncionesGlobales.h"
#include <string.h>
#include "FuncionesGlobalesDeMenus.h"

using namespace std;

int main()
{

/*
    Empleado reg;
    reg.setDNI(123456);
    reg.setNombres("Leandro");
    reg.setApellidos("Gomez");
    reg.setLegajo(22222);
    char pass[30];
    strcpy(pass, "12345678");
    reg.setPassword(pass);
    reg.setEmail("leandro.gomez3@alumnos.frgp.utn.edu.ar");
    reg.setTipoEmpleado(1);
    //reg.setEspecialidad(0);
    if(reg.grabarEnDisco(0)==true){

    cout << "Registro de empleado agregado correctamente" << endl;
    }
*/


    //login();

    /*
    Hora horaEntrada(7,0), horaSalida(18,0);
    Empleado reg(horaEntrada, horaSalida, 123456, "Leandro", "Gomez",12345, "12345", "leandro.gomez3@alumnos.frgp.utn.edu.ar", 1, 0, true);
    reg.grabarEnDisco();
    */

    /*
    Turno reg;
    int pos = 0;
    while (reg.leerDeDisco(pos)==true){
    reg.Mostrar();
    cout << endl;
    pos++;
    }
*/

/*
Turno reg;
Fecha f(2, 9, 2021);
reg.setFechaTurno(f);
reg.grabarEnDisco(0);
*/

    //AsignarTurno();
    //Listados();
    //Informes();
    //ExportarPacientes();
    //ExportarDatos();
    //Consultas();

    return 0;

}
