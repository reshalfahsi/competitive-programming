#!/usr/bin/python
from queue import PriorityQueue

direction = {
    'LEFT' : (0, -1),
    'RIGHT' : (0, 1),
    'UP' : (-1, 0),
    'DOWN': (1, 0)
}

class PqElement(object):
    def __init__(self, value: tuple):
        self.val = value

    def __lt__(self, other):
        """Custom Compare Function (less than or equal)."""
        return self.val[0] < other.val[0] # less on top

    def __repr__(self):
        """Print each element function."""
        return f'PQE:{self.val}'


pq = PriorityQueue()

INF = 999999999999


def prepare(grid):
    mario = None
    princess = None
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == "m":
                mario = (row, col)
            elif grid[row][col] == "p":
                princess = (row, col)
            # flag, cost, parent, direction
            grid[row][col] = (1, INF, (row, col), "IDLE")
    return mario, princess, grid


def displayPathtoPrincess(n,grid):
    #print all the moves here
    mario, princess, grid = prepare(grid)
    # cost, position, parent, direction
    pq.put(PqElement((0, mario, mario, "IDLE")))
    while not pq.empty():
        current = pq.get().val
        if not grid[current[1][0]][current[1][1]][0]:
            continue
        grid[current[1][0]][current[1][1]] = (0, current[0], (current[2][0], current[2][1]), current[3])
        if current[1] == princess:
            break
        for k, d in direction.items():
            row = current[1][0] + d[0]
            col = current[1][1] + d[1]
            if row < len(grid) and col < len(grid[0]) and row >= 0 and col >= 0:
                if current[0] + 1 < grid[row][col][1]:
                    pq.put(PqElement((current[0] + 1, (row, col), (current[1][0], current[1][1]), k)))
    
    pq.queue.clear()
    
    backtrack = princess
    path = list()
    while backtrack != mario:
        parent = grid[backtrack[0]][backtrack[1]]
        path.append(parent[3])
        backtrack = parent[2]
    
    for d in reversed(path):
        print(d)
                
    

m = int(input())
grid = [] 
for i in range(0, m):
    row = list(input().strip())
    grid.append(row)

displayPathtoPrincess(m,grid)
