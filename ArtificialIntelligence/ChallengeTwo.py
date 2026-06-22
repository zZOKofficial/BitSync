# 1. List Modification
# Write a Python program that takes a list of integers from the user.
# Do the followings -Remove duplicates. -Sort the list in descending order. -Filter out numbers divisible by 3. -Return the modified list.

inputNumbers = int(input("Enter the number of input you want to give: "))
inputList = []

for n in range(inputNumbers):
    temp = int(input(f"Enter numbers {n+1}:"))
    inputList.append(temp)

inputList.sort(reverse=True)

noDuplicatesList = []
for x in inputList:
    if x not in noDuplicatesList:
        noDuplicatesList.append(x)

finalList = [d for d in noDuplicatesList if d % 3 != 0]

print(finalList)

#2. Matrix Multiplication
# Write a python code to show matrix multiplication of two 2D matrix.

matrix1 = [
    [10, 20],
    [30, 40],
    [50, 60]
]

matrix2 = [
    [1, 2, 3],
    [4, 5, 6]
]
if len(matrix1[0]) == len(matrix2):
    result = [[0 for x in range(len(matrix2[0]))] for y in range(len(matrix1))]

    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix1[0])):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    for row in result:
        print(row)
else:
    print("Matrices are not compatible!")