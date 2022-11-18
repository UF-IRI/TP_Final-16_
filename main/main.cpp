#include <iostream>
#include "general.h"
#include "funciones.h"




int main() {


    t_paciente* Pacientes = new t_paciente[0];
    t_medico* Medicos = new t_medico[0];
    t_consulta* Consultas = new t_consulta[0];
    t_obra_social* ObrasS = new t_obra_social[0];
    t_contacto* Contactos = new  t_contacto[0];

    string trash;

    int tamP = 0;
    int* ptamP = &tamP;

    int tamM = 0;
    int* ptamM = &tamM;

    int tamC = 0;
    int* ptamC = &tamC;

    int tamCo = 0;
    int* ptamCo = &tamCo;

    int tamOS = 0;  //cantidades en las listas 
    int* ptamOS = &tamOS;

    // SE LLENAN LAS LISTAS CON LA INFO DE LOS ARCHIVOS 

    // Pacientes = Pacientes.csv + Contactos.csv
    fstream arch1, arch2; //punteros a archivos que vamos a usar y rotar para llenar las listas

    arch1.open("Pacientes.csv", ios::in); //abrimos los archivos para pegarlos en las listas de las diferentes estructuras
    arch2.open("Contactos.csv", ios::in);

    if (!(arch1.is_open() && arch2.is_open())) {
        cout << "ERROR PARA ABRIR ARCHIVOS" << endl;  // si hay error abriendo los archivos concluye el programa
        return -1;
    }

    t_paciente paciente_aux;
    char coma = ',';
    string dni_aux;
    t_contacto contacto;
    string H_paciente, dummy; //guardamos los headers de cada archivo --> como unimos el de pacientes con contactos se repite el id/dni de la persona --> dummy
    arch1 >> H_paciente >> coma >> H_paciente >> coma >> H_paciente >> coma >> H_paciente >> coma >> H_paciente >> coma >> H_paciente >> coma >> H_paciente;
    arch2 >> dummy >> coma >> H_paciente >> coma >> H_paciente >> coma >> H_paciente >> coma >> H_paciente;
    arch1.get();
    while (arch1) {
        //arch1 >> paciente_aux.dni >> coma >> paciente_aux.nombre >> coma >> paciente_aux.apellido >> coma >> paciente_aux.sexo >> coma >> paciente_aux.nacimiento >> coma >> paciente_aux.estado >> coma >> paciente_aux.id_os;

        getline(arch1, paciente_aux.dni, ' ');
        arch1.get();
        arch1.get();
        getline(arch1, paciente_aux.nombre, ' ');
        arch1.get();
        arch1.get();
        getline(arch1, paciente_aux.apellido, ' ');
        arch1.get();
        arch1.get();
        getline(arch1, paciente_aux.sexo, ' ');
        arch1.get();
        arch1.get();
        getline(arch1, paciente_aux.nacimiento, ' ');
        arch1.get();
        arch1.get();
        getline(arch1, paciente_aux.estado, ' ');
        arch1.get();
        arch1.get();
        getline(arch1, paciente_aux.id_os);

        agregar_paciente(Pacientes, paciente_aux, ptamP);
    }
    //agregamos el paciente
    arch2.get();
    while (arch2) {
        //arch2 >> contacto.dni_paciente >> coma >> contacto.telefono >> coma >> contacto.celular >> coma >>  >> coma >> contacto.mail;

        getline(arch2, contacto.dni_paciente, ' ');
        arch2.get();
        arch2.get();
        getline(arch2, contacto.telefono, ' ');
        arch2.get();
        arch2.get();
        getline(arch2, contacto.celular, ' ');
        arch2.get();
        arch2.get();
        getline(arch2, contacto.direccion, ',');
        arch2.get();
        getline(arch2, contacto.mail);

        agregar_contacto(Contactos, contacto, ptamCo);
    }


    arch1.close();
    arch2.close();

    arch1.open("IRI_ObraSocial.csv", ios::in);
    arch2.open("Medicos.csv", ios::in);
    if (!(arch1.is_open() && arch2.is_open())) {
        cout << "ERROR PARA ABRIR ARCHIVOS" << endl;
        return -1;
    }
    t_obra_social obsc_aux;
    t_medico medico_aux;
    string H_medico;
    string H_obraS;
    arch1 >> H_obraS >> coma >> H_obraS;
    arch2 >> H_medico >> coma >> H_medico >> coma >> H_medico >> coma >> H_medico >> coma >> H_medico >> coma >> H_medico;
    while (arch1) {
        arch1 >> obsc_aux.id >> coma >> obsc_aux.nombre;
        agregar_OS(ObrasS, obsc_aux, ptamOS);
    }

    while (arch2) {
        //arch2 >> medico_aux.id >> coma >> medico_aux.nombre >> coma >> medico_aux.apellido >> coma >> medico_aux.telefono >> coma >> medico_aux.especialidad >> coma >> medico_aux.activo;
        arch2.get();
        getline(arch2, medico_aux.id, ' ');
        arch2.get();
        arch2.get();
        getline(arch2, medico_aux.nombre, ' ');
        arch2.get();
        arch2.get();
        getline(arch2, medico_aux.apellido, ' ');
        arch2.get();
        arch2.get();
        getline(arch2, medico_aux.telefono, ' ');
        arch2.get();
        arch2.get();
        getline(arch2, medico_aux.especialidad, ' ');
        arch2.get();
        arch2.get();
        arch2 >> medico_aux.activo;

        agregar_medico(Medicos, medico_aux, ptamM);
    }
    arch1.close();
    arch2.close();

    arch1.open("Consultas.csv", ios::in);
    if (!(arch1.is_open())) {
        cout << "ERROR PARA ABRIR ARCHIVOS" << endl;
        return -1;
    }
    t_consulta consulta_aux;
    string H_consulta;
    arch1 >> H_consulta >> coma >> H_consulta >> coma >> H_consulta >> coma >> H_consulta >> coma >> H_consulta;
    arch1.get();
    while (arch1) {
        //arch1 >> consulta_aux.dni_paciente >> coma >> consulta_aux.fecha_solicitado >> coma >> consulta_aux.fecha_turno >> coma >> consulta_aux.presento >> coma >> consulta_aux.id_medico;
        getline(arch1, consulta_aux.dni_paciente, ' ');
        arch1.get();
        arch1.get();
        getline(arch1, consulta_aux.fecha_solicitado, ' ');
        arch1.get();
        arch1.get();
        getline(arch1, consulta_aux.fecha_turno, ' ');
        arch1.get();
        arch1.get();
        arch1 >> consulta_aux.presento >> coma;
        arch1.get();
        getline(arch1, consulta_aux.id_medico);

        agregar_consulta(Consultas, consulta_aux, ptamC);
    }
    arch1.close();

    // SE FILTRAN LOS MEDICOS Y PACIENTES REPETIDOS
    FiltrarMedicoRep(Medicos, ptamM);
    FiltrarPacienteRep(Pacientes, ptamP);
    // FiltrarContactoRep(Contactos, ptamCo);


     //---------CODIGO----------//

    arch1.open("Archivo.csv", ios::out);
    arch2.open("Secretaria.csv", ios::out);
    ClasificarPaciente(Medicos, ptamM, Pacientes, Consultas, Contactos, ptamCo, ptamC, ptamP, PasaStringaFecha("17/11/2022"), arch1, arch2);

    arch1.close();
    arch2.close();




    fstream ar, ar2, ar3;
    ar.open("Secretaria.csv", ios::in);
    ar2.open("Archivo.csv", ios::app);
    ar3.open("Vuelven.csv", ios::out);

    t_pacienteV* Pacientes_vuelven = new t_pacienteV[0];
    int tamPV = 0;
    int* ptamPV = &tamPV;
    t_pacienteV paciente_aux1;
    int retorna;
    while (ar) {
        //  arch1 >> coma >> paciente_aux1.nombre >> coma >> paciente_aux1.apellido >> coma >> paciente_aux1.numero >> coma >> paciente_aux1.id_os >> coma  >> paciente_aux1.nombre_medico >> coma >> paciente_aux1.apellido_medico >> coma >> paciente_aux1.id_medico >> coma >> paciente_aux1.especialidad_medico >> coma;
        getline(ar, paciente_aux1.nombre, ',');
        getline(ar, paciente_aux1.apellido, ',');
        getline(ar, paciente_aux1.numero, ',');
        getline(ar, paciente_aux1.id_os, ',');
        getline(ar, paciente_aux1.nombre_medico, ',');
        getline(ar, paciente_aux1.apellido_medico, ',');
        getline(ar, paciente_aux1.id_medico, ',');
        getline(ar, paciente_aux1.especialidad_medico);
        retorna = rand() % 2;
        if (retorna == 0) {
            agregar_pacienteV(Pacientes_vuelven, paciente_aux1, ptamPV);
        }
        if (retorna == 1) {
            ar2 << paciente_aux1.nombre << " " << paciente_aux1.apellido << "ARCHIVADO" << endl;
        }
    }
    string nueva_os;
    int aux_os;
    for (int i = 0; i < *ptamPV; i++) {
        aux_os = rand() % 6;
        switch (aux_os) {
        case 0:
            nueva_os = "Medicus";
            break;

        case 1:
            nueva_os = "OSDE";
            break;
        case 2:
            nueva_os = "IOSFA";
            break;
        case 3:
            nueva_os = "Italiano";
            break;
        case 4:
            nueva_os = "Aleman";
            break;
        case 5:
            nueva_os = "Espanyol";
            break;
        }

        if (Pacientes_vuelven[i].id_os != nueva_os)Pacientes_vuelven[i].id_os == nueva_os;
        ar3 << Pacientes_vuelven[i].nombre << coma << Pacientes_vuelven[i].apellido << coma << Pacientes_vuelven[i].numero << coma << Pacientes_vuelven[i].id_os << coma << Pacientes_vuelven[i].nombre_medico << coma << Pacientes_vuelven[i].apellido_medico << coma << Pacientes_vuelven[i].id_medico << coma << Pacientes_vuelven[i].especialidad_medico << endl;

    }


    ar.close();
    ar2.close();
    ar3.close();

    delete[] Pacientes;
    delete[] Medicos;
    delete[] ObrasS;
    delete[] Consultas;
    return EXIT_SUCCESS;
}