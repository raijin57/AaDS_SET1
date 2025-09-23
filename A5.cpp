//
// Created by arsen on 23.09.2025.
//
#include <vector>

int main() {
    int n;
    int lp[n + 1];
    std::vector<int> pr;
    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j <= pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
}