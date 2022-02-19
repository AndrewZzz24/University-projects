fin = open("input.txt", 'r', encoding='utf8')
fout = open("output.txt", 'w', encoding='utf8')

flag = 0
matrix = []

for line in fin:

    tmp = list(map(int, line.split()))

    if flag == 0:
        flag = 1
        n = tmp[0]
        m = tmp[1]
        matrix = [[0] * n for index in range(n)]
        continue

    if matrix[tmp[0] - 1][tmp[1] - 1] == 1:
        print("YES", file=fout)
        exit(0)

    matrix[tmp[0] - 1][tmp[1] - 1] = 1
    matrix[tmp[1] - 1][tmp[0] - 1] = 1

print("NO", file=fout)
