# Advanced Data Structures Laboratory (26PC1L01)


## Experiments

| No. | Experiment | Source |
|---|---|---|
| 1 | Quick Sort (integers, ascending) | [Exp1.c](Exp1.c) |
| 2 | Merge Sort (names, descending) | [Exp2.c](Exp2.c) |
| 3 | Dictionary using Hashing | [Exp3.c](Exp3.c) |
| 4 | Heap Data Structure | [Exp4.c](Exp4.c) |
| 5 | Fibonacci Heap | [Exp5.c](Exp5.c) |
| 6 | AVL Tree | [Exp6.c](Exp6.c) |
| 7 | Breadth First Search (BFS) | [Exp7.c](Exp7.c) |
| 8 | Depth First Search (DFS) | [Exp8.c](Exp8.c) |
| 9 | Dijkstra's Shortest Path | [Exp9.c](Exp9.c) |
| 10 | Kruskal's Minimum Spanning Tree | [Exp10.c](Exp10.c) |
| 11 | B+ Tree | [Exp11.c](Exp11.c) |
| 12 | Bloom Filter | [Exp12.c](Exp12.c) |


## Experiment 1: Quick Sort (integers, ascending)

**Code:** [Exp1.c](Exp1.c)

**Output:**

```text
Enter number of elements: 5
Enter 5 integers: 8 5 1 3 6
Sorted array in ascending order:
1 3 5 6 8 
```

## Experiment 2: Merge Sort (names, descending)

**Code:** [Exp2.c](Exp2.c)

**Output:**

```text
Enter number of names: 5
Enter 5 names:
Tamizh
Rahul
Giri
Sainath
Kumaran

Names in descending order:
Tamizh
Sainath
Rahul
Kumaran
Giri
```

## Experiment 3: Dictionary using Hashing

**Code:** [Exp3.c](Exp3.c)

**Output:**

_Division method_

```text
Method? 1=Div 2=Mul: 1

1.Insert 2.Search 3.Display 4.Exit: 1
Key: 11
Value: Apple

1.Insert 2.Search 3.Display 4.Exit: 1
Key: 21
Value: Banana

1.Insert 2.Search 3.Display 4.Exit: 1
Key: 31
Value: Cherry

1.Insert 2.Search 3.Display 4.Exit: 1
Key: 11
Value: Mango
Key 11 already present - value updated

1.Insert 2.Search 3.Display 4.Exit: 2
Key: 21
Found Banana

1.Insert 2.Search 3.Display 4.Exit: 2
Key: 99
Not found

1.Insert 2.Search 3.Display 4.Exit: 3

Index Key    Value
0     ---   ---
1     11    Mango
2     21    Banana
3     31    Cherry
4     ---   ---
5     ---   ---
6     ---   ---
7     ---   ---
8     ---   ---
9     ---   ---

1.Insert 2.Search 3.Display 4.Exit: 4
```

_Multiplication method_

```text
Method? 1=Div 2=Mul: 2

1.Insert 2.Search 3.Display 4.Exit: 1
Key: 11
Value: Apple

1.Insert 2.Search 3.Display 4.Exit: 1
Key: 21
Value: Banana

1.Insert 2.Search 3.Display 4.Exit: 1
Key: 31
Value: Cherry

1.Insert 2.Search 3.Display 4.Exit: 2
Key: 31
Found Cherry

1.Insert 2.Search 3.Display 4.Exit: 3

Index Key    Value
0     ---   ---
1     31    Cherry
2     ---   ---
3     ---   ---
4     ---   ---
5     ---   ---
6     ---   ---
7     11    Apple
8     ---   ---
9     21    Banana

1.Insert 2.Search 3.Display 4.Exit: 4
```

## Experiment 4: Heap Data Structure

**Code:** [Exp4.c](Exp4.c)

**Output:**

```text
Enter number of elements: 5
Enter 5 elements: 7 1 6 2 3
Max Heap (array form): 7 3 6 1 2 
Sorted array (Ascending using Heap): 1 2 3 6 7 
```

## Experiment 5: Fibonacci Heap

**Code:** [Exp5.c](Exp5.c)

**Output:**

```text

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 1
Enter key: 25

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 1
Enter key: 7

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 1
Enter key: 40

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 1
Enter key: 15

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 1
Enter key: 30

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 2
Root List (from min): 7 30 15 40 25 

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 3
Minimum = 7

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 4
Extracted minimum = 7

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 2
Root List (from min): 15(30 25(40)) 

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 4
Extracted minimum = 15

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 2
Root List (from min): 25(40) 30 

1. Insert
2. Display
3. Get Min
4. Extract Min
5. Exit
Enter choice: 5
```

## Experiment 6: AVL Tree

**Code:** [Exp6.c](Exp6.c)

**Output:**

```text
Enter number of nodes: 5
Enter 5 values: 20 10 60 50 30
Inorder Traversal (sorted keys): 10 20 30 50 60 
Preorder Traversal (shows the balanced shape): 20 10 50 30 60 
Height of tree: 3
```

## Experiment 7: Breadth First Search (BFS)

**Code:** [Exp7.c](Exp7.c)

**Output:**

```text
Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 0
1 0 0 0 1
0 1 0 0 1
0 0 1 1 0
Enter start vertex (0-4): 0
BFS Traversal: 0 1 2 3 4 
```

## Experiment 8: Depth First Search (DFS)

**Code:** [Exp8.c](Exp8.c)

**Output:**

```text
Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 0
1 0 0 0 1
0 1 0 0 1
0 0 1 1 0
Enter start vertex (0-4): 0
DFS Traversal: 0 1 3 4 2 
```

## Experiment 9: Dijkstra's Shortest Path

**Code:** [Exp9.c](Exp9.c)

**Output:**

```text
Enter number of vertices: 4
Enter adjacency matrix (0 = no edge):
0 2 3 0
2 0 1 4
3 1 0 5
0 4 5 0
Enter start vertex: 0
Shortest distances from 0:
0 -> 0 : 0   Path: 0
0 -> 1 : 2   Path: 0 -> 1
0 -> 2 : 3   Path: 0 -> 2
0 -> 3 : 6   Path: 0 -> 1 -> 3
```

## Experiment 10: Kruskal's Minimum Spanning Tree

**Code:** [Exp10.c](Exp10.c)

**Output:**

```text
Enter number of vertices: 4
Enter number of edges: 5
Enter edges (u v w):
0 1 2
0 2 3
1 2 1
1 3 4
2 3 5
Edges in MST:
1-2 (1)
0-1 (2)
1-3 (4)
Total cost of MST = 7
```

## Experiment 11: B+ Tree

**Code:** [Exp11.c](Exp11.c)

**Output:**

```text
Enter number of keys: 6
Enter the keys:
10
20
5
15
25
30
B+ Tree (level by level):
Level 0: [15 25] 
Level 1: [5 10] [15 20] [25 30] 
Leaf chain: [5 10] [15 20] [25 30] 
```

## Experiment 12: Bloom Filter

**Code:** [Exp12.c](Exp12.c)

**Output:**

```text
Enter number of elements: 4
Enter the elements:
apple
 apple -> bits 7, 5, 8
mango
 mango -> bits 9, 16, 18
orange
 orange -> bits 22, 5, 8
banana
 banana -> bits 16, 25, 4

Bloom Filter (31 bits):
0000110111000000101000100100000

Enter elements to search (type quit to stop):
mango
mango may be present in the set.
kiwi
kiwi is definitely not present in the set.
quit
```
