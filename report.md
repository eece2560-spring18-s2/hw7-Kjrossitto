## P1. Building the graph (3 pt.)
My solution to P1 was to iterate through all the groups, and then add every member of each group to the connecting members of all the members in that group. 
The algorithm's complexity was O(G x K x B) because it is necessary to iterate through each Group G, their members K, which connects to B other members. 

## P3. Connecting to someone using IDDFS (3 pt.)
-Benchmark-
without pathfinding-Maximum resident set size (kbytes): 132012
p2
with pathfinding-Time to find path to member 0.384894
Maximum resident set size (kbytes): 126908
Memory consumption of BFS= 132012-126908 = 5104
p3
with pathfinding-Time to find path to member 0.0444846
Maximum resident set size (kbytes): 127004
Memory consumption of BFS= 132012-127004 = 5008



## P4. Find best Groups to join (2 pt.)
p4- 
Path: Scott Heiferman <- Nick <- Jordan Weill <- Matt Meeker
Time to generate MST 0.0500776

