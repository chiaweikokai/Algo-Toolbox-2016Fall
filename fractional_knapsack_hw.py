# Uses python3
import sys


def get_optimal_value(capacity, weights, values):
    """
    Given a set of items and total capacity of a knapsack, find the
    maximal value of fractions of items that fit into the knapsack.
    :param capacity: the capacity of a knapsack
    :param weights: weight of the nth item
    :param values: value of the nth item
    :return: maximal value of fractions of items that fit into the knapsack
    """
    value = 0.
    # calculate cost of each item and put into a list
    cost_list = []
    for i in range(len(weights)):
        cost_list.append(values[i] / weights[i])

    # print(cost_list)
    # print(segment_list)
    # cost_list.sort(reverse=True)

    # put item value per unit into the knapsack bag
    if capacity == 0:
        return value

    for i in range(len(weights)):
        cost = max(cost_list)
        if cost == 0:
            break
        index = cost_list.index(cost)
        for j in range(weights[index]):
            if capacity > 0:
                value += cost
                capacity -= 1
            else:
                break
        cost_list[index] = 0

    return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))