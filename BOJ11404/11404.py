n = int(input())
m = int(input())

matrix = [[20000]*(n+1) for _ in range(n+1)]

for i in range(m):
    start, end, money = map(int, input().split())
    if money < matrix[start][end]:
        matrix[start][end] = money

for mid in range(1,n+1):
    for start in range(1, n+1):
        for end in range(1, n+1):
            #중간에 거쳐가는게 더 작다면 
            if start != end and matrix[start][end] > matrix[start][mid]+matrix[mid][end]:
                matrix[start][end] = matrix[start][mid] + matrix[mid][end]

#연결안되면 0으로 바꿈
for row in matrix[1:]:
    for col in row[1:]:
        if col == 20000:
            print(0, end=" ")
        else:
            print(col, end=" ")
    print()
