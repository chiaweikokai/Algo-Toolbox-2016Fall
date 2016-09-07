# Uses python3
n = int(input())
a = [int(x) for x in input().split()]
assert(len(a) == n)

# result = 0

# for i in range(0, n):
#     for j in range(i+1, n):s
#         if a[i]*a[j] > result:
#             result = a[i]*a[j]

# print("Naive result: ", result)


def find_largest(arr):
    res = 0
    index = 0
    for i in range(0, len(a)):
        if arr[i] > res:
            res = arr[i]
            index = i
    return res, index

num1, index1 = find_largest(a)
a.pop(index1)
num2, index2 = find_largest(a)

# print("Fast result: ", num1 * num2)
print(num1 * num2)
