#include <iostream>
#include <vector>

int get_max_index(std::vector<double> v) {
    int max_index = 0;
    int max_value = v[0];
    
    if (v.size() == 1) return max_index;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > max_value) {
            max_index = i;
            max_value = v[i];
        }
    }
    return max_index;
}


double get_optimal_value(int capacity, std::vector<int> weights,
    std::vector<int> values) {
    double value = 0;
    int capacity_rest = capacity; // 残存容量
    std::vector<int> weights_rest = weights; // 残るアイテム
    std::vector<int> values_rest = values;   // 残るアイテム

    std::vector<double> cp_values((int)values.size());
    for (int i = 0; i < cp_values.size(); i++) {
        cp_values[i] = (double)values[i] / (double)weights[i];
    }
    while (capacity_rest > 0) {
        if (cp_values.size() == 0) break;

        int max_index = get_max_index(cp_values);
        if (cp_values[max_index] == 0) break;

        if (capacity_rest >= weights_rest[max_index]) {
            value += values_rest[max_index];
            capacity_rest -= weights_rest[max_index];
            weights_rest.erase(weights_rest.begin() + max_index);
            values_rest.erase(values_rest.begin() + max_index);
            cp_values.erase(cp_values.begin() + max_index);
        } else {
            value += cp_values[max_index];
            capacity_rest -= 1;
        }
    }
    return value;
}


int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;

    std::vector<int> values(n);
    std::vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}

