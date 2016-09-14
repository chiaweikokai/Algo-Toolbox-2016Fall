#include <cstdlib>
#include <iostream>
#include <vector>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    // use Naive algorithm
    long long result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (((long long)(numbers[i])) * numbers[j] > result) {
                result = ((long long)(numbers[i])) * numbers[j];
            }
        }
    }
    return result;
}


long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int n = numbers.size();
    // use fast algorithm
    // find the largest number
    int max_index1 = -1;
    for (int i = 0; i < n; i++) {
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1])) {
            max_index1 = i;
        }
    }
    // find the second largest number
    int max_index2 = -1;
    for (int i = 0; i < n; i++) {
        if ((i != max_index1) && 
            ((max_index2 == -1) || (numbers[i] > numbers[max_index2]))) {
            max_index2 = i;
        }
    }

    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main () {
    while (true) {
        int n = rand() % 100 + 2;
        std::cout << n << std::endl;
        std::vector<int> v;
        for (int i = 0; i < n; i++) {
            v.push_back(rand() % 100000);
        }
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << ' ';
        }
        std::cout << std::endl;

        long long result1 = MaxPairwiseProduct(v);
        long long result2 = MaxPairwiseProductFast(v);

        // 結果不一致の場合、テストを中断させる
        if (result2 != result1) {
            std::cout << "Wrong answer: " << result1 << " " << result2 << std::endl;
            break;
        } else {
            std::cout << "OK\n";
        }
    }

    // int n;
    // std::cin >> n;
    // std::vector<int> numbers(n);
    // for (int i = 0; i < n; i++) {
    //     std::cin >> numbers[i];
    // }

    // long long final_result = MaxPairwiseProductFast(numbers);
    // std::cout << final_result << std::endl;
    return 0;
}
