import threading

def matrix_multiply_row(row_a, matrix_b, result, row_index):
    for j in range(len(matrix_b[0])):
        result[row_index][j] = sum(row_a[k] * matrix_b[k][j] for k in range(len(row_a)))

def matrix_multiply_parallel(matrix_a, matrix_b):
    if len(matrix_a[0]) != len(matrix_b):
        print("Matrix dimensions are not suitable for multiplication")
        return

    result = [[0] * len(matrix_b[0]) for _ in range(len(matrix_a))]

    threads = []

    for i in range(len(matrix_a)):
        thread = threading.Thread(target=matrix_multiply_row, args=(matrix_a[i], matrix_b, result, i))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    return result

# Example usage:
matrix_a = [
    [1, 2, 3],
    [4, 5, 6],
]

matrix_b = [
    [7, 8],
    [9, 10],
    [11, 12],
]

result = matrix_multiply_parallel(matrix_a, matrix_b)
for row in result:
    print(row)