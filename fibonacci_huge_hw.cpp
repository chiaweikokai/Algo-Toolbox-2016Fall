#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


int get_fibonacci_last_digit_fast(long long n, long long m) {
    if (n <= 1)
        return n;
    else {
        int previous = 0;
        int current = 1;
        for (int i = 2; i <= n; i++) {
            int tmp_current = current;
            current = current % m + previous % m;
            previous = tmp_current;
        }

        return current % m;
    }
}


std::vector<long long> get_pisano_list(long long n, long long m) {
    std::vector<long long> pisano_list;
    pisano_list.push_back(0);
    if (n == 0) return pisano_list;
    pisano_list.push_back(1);
    if (n == 1) return pisano_list;
    
    // long long k;
    // if (n > m) k = m * m;
    // else {
    //     if (n % 2 == 0) k = 2 * n;
    //     else k = 4 * n;       
    // }
    long long i = 2;
    while (true) {
        int digit = get_fibonacci_last_digit_fast(i, m);
        if (digit == 0) {
            if (1 == get_fibonacci_last_digit_fast(i + 1, m)) {
                break;
            }
        }
        pisano_list.push_back(digit);
        i++;  
    }
    return pisano_list;
} 


int get_fibonacci_huge_fast(long long n, long long m) {
    // long long complete_n = n;
    // if (n < m) complete_n = m;
    // std::vector<long long> pisano_list = get_pisano_list(n, m);
    int pisano_list_length {0};
    if (m < 10000) {
        std::vector<long long> pisano_list = get_pisano_list(n, m);
        pisano_list_length = pisano_list.size() + 1;
    } else {
        if (n % 2 == 0) pisano_list_length = 2 * n;
        else pisano_list_length = 4 * n;
    }

    int r = n % pisano_list_length;
    return get_fibonacci_last_digit_fast(r, m);
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    // std::vector<long long> v = get_pisano_list(n, m);
    // for (long long num : v) {
    //     std::cout << num << " ";
    // }
    // std::cout << '\n';
    // std::cout << v.size() << std::endl;
    int result = get_fibonacci_huge_fast(n, m);
    std::cout << result << std::endl;
    return 0;
}

/*
Failed case #6/22: time limit exceeded
Input:
100 100000

Your output:

stderr:

 (Time used: 1.99/1.00, memory used: 8978432/536870912.)
*/


/*
Failed case #12/22: time limit exceeded
Input:
99999999999999999 100000

Your output:

stderr:

 (Time used: 1.99/1.00, memory used: 23461888/536870912.)
*/
