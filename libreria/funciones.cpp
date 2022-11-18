#include "funciones.h"
#include <string>
#include <iostream>
using namespace std;



void agregar_paciente(t_paciente*& Lista, t_paciente Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;  //agranda 1 en tamaño de la lista
	int i = 0;
	t_paciente* aux = new t_paciente[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];        //copia todo lo de la lista vieja a la nueva
		i++;
	}
	aux[i] = Nuevo;               //agrega el elemento a la ultima pos de la nueva lista

	delete[] Lista;
	Lista = aux;                  //reapunta el puntero a la nueva lista

	return;
}

void agregar_pacienteV(t_pacienteV*& Lista, t_pacienteV Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;  //agranda 1 en tamaño de la lista
	int i = 0;
	t_pacienteV* aux = new t_pacienteV[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];        //copia todo lo de la lista vieja a la nueva
		i++;
	}
	aux[i] = Nuevo;               //agrega el elemento a la ultima pos de la nueva lista

	delete[] Lista;
	Lista = aux;                  //reapunta el puntero a la nueva lista

	return;
}

void agregar_medico(t_medico*& Lista, t_medico Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	t_medico* aux = new t_medico[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];
		i++;
	}
	aux[i] = Nuevo;
	delete[] Lista;
	Lista = aux;
	return;
}
void agregar_OS(t_obra_social*& Lista, t_obra_social Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	t_obra_social* aux = new t_obra_social[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];
		i++;
	}
	aux[i] = Nuevo;
	delete[] Lista;
	Lista = aux;
	return;
}
void agregar_consulta(t_consulta*& Lista, t_consulta Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	t_consulta* aux = new t_consulta[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];
		i++;
	}
	aux[i] = Nuevo;
	delete[] Lista;
	Lista = aux;
	return;
}

void agregar_contacto(t_contacto*& Lista, t_contacto Nuevo, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	t_contacto* aux = new t_contacto[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = Lista[i];
		i++;
	}
	aux[i] = Nuevo;
	delete[] Lista;
	Lista = aux;
	return;
}

void FiltrarPacienteRep(t_paciente*& Lista, int* tamP) {
	int cont = 0, i, j;
	for (i = 0; i < *tamP - 1; i++) {
		for (j = i; j < *tamP - 1; j++) {
			if (Lista[i].dni == Lista[j + 1].dni) {  //recorro la lista marcando los repetidos
				Lista[j + 1].dni = "repetido";
				cont++;
			}
		}
	}
	t_paciente paciente_aux;
	for (i = 0; i < *tamP - 1; i++) {
		if (Lista[i].dni == "repetido") {
			for (j = i; j < *tamP - 1; j++) {      //ordeno los repetidos al final 
				paciente_aux = Lista[j];
				Lista[j] = Lista[j + 1];
				Lista[j + 1] = paciente_aux;
			}
		}

	}
	*tamP -= cont; //saco de la lista a los repetidos que me quedaron al final 
	return;
}
void FiltrarMedicoRep(t_medico*& Lista, int* tamM) {
	int cont = 0, i, j;
	for (i = 0; i < *tamM - 1; i++) {
		for (j = i; j < *tamM - 1; j++) {
			if (Lista[i].id == Lista[j + 1].id) {  //recorro la lista marcando los repetidos
				Lista[j + 1].id = "repetido";
				cont++;
			}
		}
	}
	t_medico paciente_aux;
	for (i = 0; i < *tamM - 1; i++) {
		if (Lista[i].id == "repetido") {
			for (j = i; j < *tamM - 1; j++) {      //ordeno los repetidos al final 
				paciente_aux = Lista[j];
				Lista[j] = Lista[j + 1];
				Lista[j + 1] = paciente_aux;
			}
		}

	}
	*tamM -= cont; //saco de la lista a los repetidos que me quedaron al final 
	return;
}

void FiltrarContactoRep(t_contacto*& Lista, int* tamM) {
	int cont = 0, i, j;
	for (i = 0; i < *tamM - 1; i++) {
		for (j = i; j < *tamM - 1; j++) {
			if (Lista[i].dni_paciente == Lista[j + 1].dni_paciente) {  //recorro la lista marcando los repetidos
				Lista[j + 1].dni_paciente = "repetido";
				cont++;
			}
		}
	}
	t_contacto paciente_aux;
	for (i = 0; i < *tamM - 1; i++) {
		if (Lista[i].dni_paciente == "repetido") {
			for (j = i; j < *tamM - 1; j++) {      //ordeno los repetidos al final 
				paciente_aux = Lista[j];
				Lista[j] = Lista[j + 1];
				Lista[j + 1] = paciente_aux;
			}
		}

	}
	*tamM -= cont; //saco de la lista a los repetidos que me quedaron al final 
	return;
}

bool MayorDiezAnios(tm fecha_Uconsulta, tm fecha_actual)
{

	int dif_anio = fecha_actual.tm_year - fecha_Uconsulta.tm_year;
	int dif_mes = fecha_actual.tm_mon - fecha_Uconsulta.tm_mon;
	int dif_dia = fecha_actual.tm_mday - fecha_Uconsulta.tm_mday;

	if (dif_anio < 10) {
		return false;
	}
	else if (dif_anio > 10)
	{
		return true;
	}
	else if (dif_anio == 10)
	{
		if (dif_mes > 0)
		{
			return true;
		}
		else if (dif_mes < 0)
		{
			return false;
		}
		else if (dif_anio == 10 && dif_mes == 0) {
			if (dif_dia > 0)
			{
				return true;
			}
			else if (dif_dia < 0)
			{
				return true;
			}
			else {
				return false;
			}
		}

	}
}



tm PasaStringaFecha(string a) //fecha si o si formato = DD/MM/AAAA
{
	tm f;

	stringstream stream(a);
	string tok;
	getline(stream, tok, '/');
	f.tm_mday = std::stoi(tok);
	getline(stream, tok, '/');
	f.tm_mon = std::stoi(tok);
	getline(stream, tok);
	f.tm_year = std::stoi(tok);

	return f;

}

t_consulta Ultima_consulta(t_consulta*& Lista_Consultas, int* tamC, t_paciente Paciente) // devuelve la consulta mas reciente
{
	t_consulta* Consultas = new t_consulta[0];
	int tam = 0;
	int* ptam = &tam;
	for (int i = 0; i < *tamC; i++) {
		if (Lista_Consultas[i].dni_paciente == Paciente.dni) {
			agregar_consulta(Consultas, Lista_Consultas[i], ptam);
		}
	}
	t_consulta min = Lista_Consultas[0];

	for (int k = 1; k < *ptam; k++) {
		if (compararFechas(PasaStringaFecha(Consultas[k].fecha_solicitado), PasaStringaFecha(min.fecha_turno)) == true) { //si la consulta en k es mas reciente que la consulta en min se actualiza min
			min = Consultas[k];
		}
	}

	return min;
}

void ClasificarPaciente(t_medico*& Lista_medicos, int* tamM, t_paciente*& Lista_pacientes, t_consulta*& Lista_Consultas, t_contacto*& Contactos, int* ptamCo, int* tamC, int* tamP, tm fecha_actual, fstream& archivo1, fstream& archivo2)
{

	t_consulta* Consultas = new t_consulta[0];
	t_medico Medico_aux;
	int* tam = 0;
	for (int i = 0; i < *tamP; i++)
	{
		if (Ultima_consulta(Lista_Consultas, tamC, Lista_pacientes[i]).presento == false
			&& MayorDiezAnios(PasaStringaFecha(Ultima_consulta(Lista_Consultas, tamC, Lista_pacientes[i]).fecha_turno), fecha_actual) == true)
		{
			for (int h = 0; h < *tamC; h++) {
				if (Lista_Consultas[h].dni_paciente == Lista_pacientes[i].dni) {
					archivo1 << Lista_Consultas[i].dni_paciente << ',' << "ARCHIVADO" << endl;
				}
			}
		}
		else if (Ultima_consulta(Lista_Consultas, tamC, Lista_pacientes[i]).presento == false &&
			MayorDiezAnios(PasaStringaFecha(Ultima_consulta(Lista_Consultas, tamC, Lista_pacientes[i]).fecha_turno), fecha_actual) == false)
		{
			if (Lista_pacientes[i].estado == "fallecido") {
				archivo1 << Lista_Consultas[i].dni_paciente << ',' << "ARCHIVADO" << endl;
			}
			else if (Lista_pacientes[i].estado == "internado" || Lista_pacientes[i].estado == "n/c") {
				for (int k = 0; k < *tamM; k++)
				{

					t_consulta consAux;
					consAux = Ultima_consulta(Lista_Consultas, tamC, Lista_pacientes[i]);

					if (consAux.id_medico == Lista_medicos[k].id)
					{
						Medico_aux = Lista_medicos[k];
					}

				}

				t_contacto auxc;

				for (int q = 0; q < *ptamCo; q++) {
					if (Lista_pacientes[i].dni == Contactos[q].dni_paciente) {
						auxc = Contactos[q];
						break;
					}
					else {
						auxc.celular = "SIN_CELULAR";
						auxc.direccion = "SIN_DIRECCION";
						auxc.telefono = "SIN_TELEFONO";
						auxc.mail = "SIN_MAIL";

					}

				}

				archivo2 << Lista_pacientes[i].nombre << " ," <<
					Lista_pacientes[i].apellido << " ," <<
					auxc.telefono << " ," <<
					Lista_pacientes[i].id_os << " ," << Medico_aux.nombre << " ," << Medico_aux.apellido << " ," << Medico_aux.id << " ," << Medico_aux.especialidad << endl;
			}
		}
	}
}

bool compararFechas(tm a, tm b) //retorna true si la primera es + reciente
{
	if (a.tm_year > b.tm_year) return true;
	if (a.tm_year < b.tm_year) return false;
	if (a.tm_year == b.tm_year && a.tm_mon > b.tm_mon) return true;
	if (a.tm_year == b.tm_year && a.tm_mon < b.tm_mon) return false;
	if (a.tm_year == b.tm_year && a.tm_mon == b.tm_mon && a.tm_mday > b.tm_mday) return true;
	if (a.tm_year == b.tm_year && a.tm_mon == b.tm_mon && a.tm_mday < b.tm_mday) return false;
	if (a.tm_year == b.tm_year && a.tm_mon == b.tm_mon && a.tm_mday == b.tm_mday) return false;
}

