#include "DP.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;

int main() {
    string title, a, b;
    string dir_0, dir_1;

    int L;
    double d;

    cin >> dir_0 >> dir_1 >> title;
    
    ifstream file_i(dir_0);

    if (!file_i.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de salida: " << dir_0 << endl;
        return 1;
    }

    ofstream file_o(dir_1, ios::out);

    if (!file_o.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de salida: " << dir_1 << endl;
        file_i.close();
        return 1;
    }
    file_o << title << endl;

    while (file_i >> a >> b){
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000; j++)
            editDistanceDP(a, b);
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        L = a.size() * b.size();
        d = duration.count() / 1000;

        file_o << L << " " << d << endl; 
    }
    
    file_i.close();
    file_o.close();
    return 0;
}