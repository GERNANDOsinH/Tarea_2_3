#include "TablasDeCostos.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

int editDistanceDP(const std::string S1, const std::string S2) {
    int L1 = S1.length(), L2 = S2.length();
    int a, b;
    std::vector<std::vector<int>> dp(L1 + 1, std::vector<int>(L2 + 1));

    for (int j = 1; j <= L2; j++) {
        dp[0][j] = dp[0][j - 1] + costo_ins(S2[j - 1]);
    }

    for (int i = 1; i <= L1; i++) {
        dp[i][0] = dp[i - 1][0] + costo_del(S1[i - 1]);
    }

    for (int i = 1; i <= L1; i++) {
        for (int j = 1; j <= L2; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                a = std::min(
                        dp[i - 1][j] + costo_del(S1[i - 1]),
                        dp[i][j - 1] + costo_ins(S2[j - 1])
                        );
                b = std::min(
                        a,
                        dp[i - 1][j - 1] + costo_sub(S1[i - 1], S2[j - 1])
                            );
                dp[i][j] = std::min(
                        b,
                        dp[i - 2][j - 2] + costo_trans(S1[i - 1], S1[i])
                );
        
                if (i > 1 && j > 1 && S1[i - 1] == S2[j - 2] && S1[i - 2] == S2[j - 1]) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 2][j - 2] + costo_trans(S1[i - 1], S1[i - 2]));
                }
            }
        }
    }
    return dp[L1][L2];
}

int main(){
    std::string title, a, b;
    std::string dir_0, dir_1;
    int L, d;
    std::cin >> dir_0 >> dir_1>> title;
    std::ifstream file_0; std::ofstream file_1;
    file_0.open(dir_0); file_1.open(dir_1, std::ios::out);

    if (!file_0.is_open()) {
        std::cout << "No se pudo abrir el archivo " << dir_0 << std::endl;
        return 1;
    }
    if (!file_1.is_open()) {
        std::cout << "No se pudo abrir el archivo " << dir_1 << std::endl;
        return 1;
    }

    file_1 << title << std::endl;
    while (std::getline(file_0, a)){
        if (!std::getline(file_0, b)) break;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
            editDistanceDP(a, b);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        L = a.size() * b.size();
        d = duration.count() / 1000;
        file_1 << L << " " << d << std::endl;
    }
    file_0.close(); file_1.close();
    return 0;
}