#include <iostream>

int main() {
    int exp;
    std::cout << "Enter an exponent: ";
    std::cin >> exp;

    int res = 1;
    for (int i=1; i<10; i++) {
        res = 1;
        for (int j=0; j<exp; j++) {
            res = res * i;
        }
        std::cout << i << " ^ " << exp << ": " << res << "\n";
    }
    return 0;
}
