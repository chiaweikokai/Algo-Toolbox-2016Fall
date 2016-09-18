#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;
    else {
        int previous = 0;
        int current = 1;
        for (int i = 2; i <= n; i++) {
            int tmp_current = current;
            current = (current + previous) % 10;
            previous = tmp_current;
        }

        return current % 10;
    }
}


int main() {
    int n;
    std::cin >> n;
    // int c_naive = get_fibonacci_last_digit_naive(n);
    // std::cout << c_naive << '\n';
    int c_fast = get_fibonacci_last_digit_fast(n);
    std::cout << c_fast << '\n';

    return 0;
}
