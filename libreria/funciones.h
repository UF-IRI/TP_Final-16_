#pragma once
#include "general.h"

void agregar_paciente(t_paciente*& Lista, t_paciente Nuevo, int* tamactual);
void agregar_medico(t_medico*& Lista, t_medico Nuevo, int* tamactual);
void agregar_OS(t_obra_social*& Lista, t_obra_social Nuevo, int* tamactual);
void agregar_consulta(t_consulta*& Lista, t_consulta Nuevo, int* tamactual);
void agregar_contacto(t_contacto*& Lista, t_contacto Nuevo, int* tamactual);

void FiltrarPacienteRep(t_paciente*& Lista, int* tamLista);
void FiltrarMedicoRep(t_medico*& Lista, int* tamLista);
void FiltrarContactoRep(t_contacto*& Lista, int* tamLista);

bool MayorDiezAnios(tm fecha_Uconsulta, tm fecha_actual);


tm PasaStringaFecha(string a);

t_consulta Ultima_consulta(t_consulta*& Lista_Consultas, int* tamC, t_paciente Paciente);

void ClasificarPaciente(t_medico*& Lista_medicos, int* tamM, t_paciente*& Lista_pacientes, t_consulta*& Lista_Consultas, t_contacto*& Contactos, int* ptamCo, int* tamC, int* tamP, tm fecha_actual, fstream& archivo1, fstream& archivo2);

bool compararFechas(tm a, tm b);


