//
// Created by arsen on 20.09.2025.
//
#include <string>
#include <iostream>
#include <stack>
int main() {
    std::string s;
    getline(std::cin, s);
    std::string curr;
    int num = 0;
    std::stack<int> numStack;
    std::stack<std::string> strStack;
    for (char c : s) {
        if (isdigit(static_cast<unsigned char>(c))) {
            num = c - '0';
        }
        else if (c == '[') {
            numStack.push(num);
            strStack.push(curr);
            num = 0;
            curr.clear();
        }
        else if (c == ']') {
            int mult = 1;
            if (!numStack.empty()) {
                mult = numStack.top();
                numStack.pop();
            }
            std::string prev = strStack.top();
            strStack.pop();
            std::string combined = prev;
            combined.reserve(prev.size() + curr.size() * mult);
            while (mult--) {
                combined += curr;
            }
            curr = std::move(combined);
        }
        else {
            curr.push_back(c);
        }
    }
    std::cout << curr << '\n';
    return 0;
}