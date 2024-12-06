#include "TablasDeCostos.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
// Se asume que vamos a transformar S1 a S2.

int editDistanceBruteForce(const std::string& S1, const std::string& S2, int i, int j){
    /*
    Entrada:
        S1: Cadena de caracteres.
        S2: Cadena de caracteres al que S1 se va a intertar acercar.
        i: Posición del primer caracter que estamos leyendo de S1.
        j: Posición del primer caracter que estamos leyendo de S2.
    */

    int costo = 0;
    if (i == S1.length()){
        
        for (int k = j;k < S2.length();k++)
            costo += costo_ins(S2[k]);
        
        return costo;
        }
    if (j == S2.length()){
        for (int k = i;k < S1.length();k++)
            costo += costo_del(S1[k]);
        
        return costo;
        }
    
    
    if (S1[i] == S2[j]) {
        return editDistanceBruteForce(S1, S2, i + 1, j + 1);
    }

    int replaceCost = editDistanceBruteForce(S1, S2, i + 1, j + 1) + costo_sub(S1[i],S2[j]);
    int insertCost = editDistanceBruteForce(S1, S2, i, j + 1) + costo_ins(S2[j]);
    int deleteCost = editDistanceBruteForce(S1, S2, i + 1, j) + costo_del(S1[i]);
    
    int transposeCost = INT_MAX;
    if (i < S1.length() - 1 && j < S2.length() - 1 && S1[i] == S2[j + 1] && S1[i + 1] == S2[j]) {
        transposeCost = costo_trans(S1[i], S1[i + 1]) + editDistanceBruteForce(S1, S2, i + 2, j + 2);
    }

    return std::min(std::min(insertCost, deleteCost), std::min(replaceCost, transposeCost));
}