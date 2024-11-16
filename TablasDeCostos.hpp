#include <bits/stdc++.h>

std::map<char,std::map<char,int>> tabla_costo_sub;
std::map<char,std::map<char,int>> tabla_costo_trans;
std::map<char,int> tabla_costo_ins;
std::map<char,int> tabla_costo_del;

int costo_sub(char a, char b){
    int costo = tabla_costo_sub[a][b];
    return costo;
}
int costo_trans(char a, char b){
    int costo = tabla_costo_trans[a][b];
    return costo;
}
int costo_ins(char a){
    int costo = tabla_costo_ins[a];
    return costo;
}
int costo_del(char a){
    int costo = tabla_costo_del[a];
    return costo;
}

bool convertirStringAEnteros(const std::string& S, std::map<char,int>& myMap){
    int numero, contador = 0;
    char col;
    std::istringstream stream(S);
    while (stream >> numero){
        col = 'a' + contador;
        myMap[col] = numero;
        contador++;
    }
    return (contador == 26);
}

bool readReplace(){
    std::ifstream file; std::string line;
    int contador = 0; char fila; bool b = true;

    // Leer tabla sustitucion:
    file.open("cost_replace.txt");
    if (!file.is_open()){
        std::cout << "Error al abrir un archivo";
        return false;
        }
    while (getline(file, line)){
        fila = 'a' + contador;
        b = b && convertirStringAEnteros(line, tabla_costo_sub[fila]);
        contador++;
        }
    file.close();

    if (fila == 'z' && b)
        return true;
    std::cout << "Error en el tamano/formato de la tabla de costos";
    return false;
}
bool readTransform(){
    std::ifstream file; std::string line;
    int contador = 0; char fila; bool b = true;

    // Leer tabla transformacion:
    file.open("cost_transpose.txt");
    if (!file.is_open()){
        std::cout << "Error al abrir un archivo";
        return false;
        }
    while (getline(file, line)){
        fila = 'a' + contador;
        b = b && convertirStringAEnteros(line, tabla_costo_trans[fila]);
        contador++;
        }
    file.close();

    if (fila == 'z' && b)
        return true;
    std::cout << "Error en el tamano/formato de la tabla de costos";
    return false;
}
bool readInsertion(){
    std::istringstream stream; std::ifstream file; std::string line;
    char key; int numero, contador = 0;

    // Leer tabla insercion:
    file.open("cost_insert.txt");
    if (!file.is_open()){
        std::cout << "Error al abrir un archivo";
        return false;
        }
    while (getline(file, line)){
        key = 'a' + contador;
        contador++;
        numero = 0;
        for (int i = 0;i < line.length();i++){
            numero = numero * 10;
            numero += (int)line[i] - (int)'0';
        }
        tabla_costo_ins[key] = numero;
        }

    file.close();
    if (key == 'z')
        return true;
    std::cout << "Error en el tamano de la tabla de costos";
    return false;
}
bool readDelete(){
    std::istringstream stream; std::ifstream file; std::string line;
    int contador = 0, numero; char key;

    // Leer tabla Eliminacion:
    file.open("cost_delete.txt");
    if (!file.is_open()){
        std::cout << "Error al abrir un archivo";
        return false;
        }
    while (getline(file, line)){
        key = 'a' + contador;
        contador++;
        numero = 0;
        for (int i = 0;i < line.length();i++){
            numero = numero * 10;
            numero += (int)line[i] - (int)'0';
        }
        tabla_costo_del[key] = numero;
        }

    file.close();
    if (key == 'z')
        return true;
    std::cout << "Error en el tamano de la tabla de costos";
    return false;
}

bool simplified(){
    return (readReplace() && readTransform() && readInsertion() && readDelete());
}