#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include <sstream>
using namespace std;

//Estructuras
typedef struct {
    string id;
    string nombre;
    string apellido;
    string telefono;
    string especialidad;
    bool activo;
} t_medico;

typedef struct {
    string dni;
    string nombre;
    string apellido;
    string sexo;
    string nacimiento;  // DD/MM/YY
    string estado;    //fallecido , internado ,n/c
    string id_os;
} t_paciente;

typedef struct {
    string nombre;
    string apellido;
    string numero;// DD/MM/YY   //fallecido , internado ,n/c
    string id_os;
    string nombre_medico;
    string apellido_medico;
    string id_medico;
    string especialidad_medico;
} t_pacienteV;


typedef struct {
    string id;
    string nombre;  //podria ser un enum
} t_obra_social;

typedef struct {
    string dni_paciente;
    string fecha_solicitado;
    string fecha_turno;   // DD/MM/YY
    bool presento;
    string id_medico;
} t_consulta;

typedef struct {
    string dni_paciente;
    string telefono;
    string celular;
    string direccion;
    string mail;
} t_contacto;

