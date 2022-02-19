fin = open("input.txt", "r", encoding="utf8")
fout = open("output.txt", "w", encoding="utf8")
flag = 1
matrix = []
for i in fin:
    if flag == 1:
        n, k = map(int, i.split())
        flag = 0
        for j in range(n):
            matrix.append([])
            for x in range(n):
                matrix[j].append([])
                matrix[j][x] = 0
        continue
    num1, num2 = map(int, i.split())
    matrix[num1 - 1][num2 - 1] = 1
for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        print(matrix[i][j], end=' ', file=fout)
    print(file=fout)
