#include "../TablasDeCostos.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

int editDistanceDP(const std::string& S1, const std::string& S2) {
    int L1 = S1.length(), L2 = S2.length();
    std::vector<std::vector<int>> dp(L1 + 1, std::vector<int>(L2 + 1));

    // Inicialización de la primera fila (costos de inserción)
    for (int j = 1; j <= L2; j++) {
        dp[0][j] = dp[0][j - 1] + costo_ins(S2[j - 1]);
    }

    // Inicialización de la primera columna (costos de eliminación)
    for (int i = 1; i <= L1; i++) {
        dp[i][0] = dp[i - 1][0] + costo_del(S1[i - 1]);
    }

    for (int i = 1; i <= L1; i++) {
        for (int j = 1; j <= L2; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min({
                    dp[i - 1][j] + costo_del(S1[i - 1]),             // Eliminación
                    dp[i][j - 1] + costo_ins(S2[j - 1]),             // Inserción
                    dp[i - 1][j - 1] + costo_sub(S1[i - 1], S2[j - 1]) // Sustitución
                });
                
                // Verificar transposición
                if (i > 1 && j > 1 && S1[i - 1] == S2[j - 2] && S1[i - 2] == S2[j - 1]) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 2][j - 2] + costo_trans(S1[i - 1], S1[i - 2]));
                }
            }
        }
    }
    return dp[L1][L2];
}