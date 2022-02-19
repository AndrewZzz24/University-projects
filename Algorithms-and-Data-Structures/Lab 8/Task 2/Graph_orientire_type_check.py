fin = open("input.txt", 'r', encoding='utf8')
fout = open("output.txt", 'w', encoding='utf8')
str_matrix = list(map(int, fin.read().split()))
n = str_matrix[0]
numerous = 1
matrix = [[0] * n for i in range(n)]
for i in range(n):
    for j in range(n):
        matrix[i][j] = str_matrix[numerous]
        numerous += 1
flag = 0
for i in range(n):
    for j in range(n):
        if i == j and matrix[i][i] == 1 or matrix[i][j] != matrix[j][i]:
            flag = 1
            print("NO", file=fout)
            break
    if flag == 1:
        break
if flag == 0:
    print("YES", file=fout)
