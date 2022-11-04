// FileArgv.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

vector<string> extract_args_line(const char* line) {
    enum STATE {
        INITIAL,
        ARG_NO_QUOT,
        ARG_QUOT,
        ARG_QUOT_SCAPE
    };
    STATE st = INITIAL;
    vector<string> res;
    int i = 0;
    string aux = "";
    while (line[i]) {
        switch(st){
        case INITIAL:
            if (!isspace(line[i]) && !(line[i] == '"')) {
                aux.append(line[i], 1);
                st = ARG_NO_QUOT;
            }
            else if (line[i] == '"')
                st = ARG_QUOT;
            break;
        case ARG_QUOT:
            if (line[i] == '"') {
                st = ARG_QUOT_SCAPE;
            }
            else {
                aux.append(line[i], 1);
            }
            break;
        case ARG_QUOT_SCAPE:
            if (isspace(line[i])) {
                res.push_back(aux);
                aux = "";
                st = INITIAL;
            }
            else {
                aux.append(line[i], 1);
                if (line[i] == '"')
                    st = ARG_QUOT;
                else
                    st = ARG_NO_QUOT;
            }
            break;
        case ARG_NO_QUOT:
            if (isspace(line[i])) {
                res.push_back(aux);
                aux = "";
                st = INITIAL;
            }
            else if (line[i] == '"')
                st = ARG_QUOT;
            else
                aux.append(line[i], 1);
        }
        i++;
    }
    if (aux != "")
        res.push_back(aux);
    return res;
};

vector<string> extract_args_file(const char* filename) {
    vector<string> file_argv;
    ifstream file("argv.txt");
    char line_buff[1024];
    while (!file.eof()) {
        file.getline(line_buff, 1024);
        vector<string> line_argv = extract_args_line(line_buff);
        file_argv.insert(file_argv.end(), line_argv.begin(), line_argv.end());
    }
    file.close();
    return file_argv;
}


int main(int argc, char* argv[])
{
    if (argc == 2 && !strcmp(argv[1], "argv.txt")) {
        vector<string> file_argv = extract_args_file("argv.txt");
        for (auto x : file_argv) {
            cout << x << "|" << endl;
        }
    }
    else {
        for (int i = 0; i < argc; i++) {
            cout << argv[i] << "|" << endl;
        }
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
