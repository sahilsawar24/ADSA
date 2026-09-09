INF = 999999

# Take number of vertices
V = int(input("Enter the number of vertices: "))

# Take graph input
print("Enter the adjacency matrix:")
print("(Enter 0 if there is no edge)")

graph = []

for i in range(V):
    row = list(map(int, input(f"Row {i + 1}: ").split()))
    graph.append(row)

# Selected vertices
selected = [False] * V

# Start from vertex 0
selected[0] = True

total_weight = 0

print("\nMinimum Spanning Tree:")
print("Edge\tWeight")

# MST contains V-1 edges
for _ in range(V - 1):
    minimum = INF
    x = -1
    y = -1

    # Find minimum edge
    for i in range(V):
        if selected[i]:
            for j in range(V):
                if not selected[j] and graph[i][j] != 0:
                    if graph[i][j] < minimum:
                        minimum = graph[i][j]
                        x = i
                        y = j

    # Add edge to MST
    if x != -1 and y != -1:
        print(f"{x} - {y}\t{graph[x][y]}")
        total_weight += graph[x][y]
        selected[y] = True

print("Total weight of MST:", total_weight)