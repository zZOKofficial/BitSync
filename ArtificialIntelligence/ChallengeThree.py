# 1. Create two functions, one will show the even numbers
# from an array, and another function will show the grade 
# based on the marks from(marks should be asked from the user)

def even(arr):
    print ("Even numbers: ")
    for i in arr:
        if i%2 == 0:
            print (i, end = "\t")
    print ()

def grade():
    mark = float (input("Enter your marks: "))

    if 90 <= mark <= 100:
        print("A+")
    elif mark >= 85 :
        print ("A")
    elif mark >= 80:
        print ("B+")
    elif mark >= 75:
        print ("B")
    elif mark >= 70:
        print ("C+")
    elif mark >= 65:
        print ("C")
    elif mark >= 60:
        print ("D+")
    elif mark >= 50:
        print ("D")
    elif 0 <= mark < 50:
        print ("Fail")
    else:
        print ("Invalid Marks!")


numbers = [10, 20, 33, 45, 57, 63, 75, 82, 91, 94]
even(numbers)
grade()

# 2. Apply BFS for the following graph. Use the dictionary to create the graph.
from collections import deque

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': ['H'],
    'E': [],
    'F': [],
    'G': ['P'],
    'H': [],
    'P': []
}

def bfs(graph, start):
    visited = []
    queue = deque([start])

    while queue:
        node = queue.popleft()

        if node not in visited:
            visited.append(node)
            queue.extend(graph[node])

    print("BFS Traversal:")
    print(" -> ".join(visited))

bfs(graph, 'A')