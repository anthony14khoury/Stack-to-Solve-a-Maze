# Stack to Solve a Maze

This C++ build is a depth first search using a stack to solve a maze.

The idea behind it is you input a set of data such as:
1 0 1 1
1 1 1 0
0 1 0 1
1 1 1 1

And finally give input coordinates, lets say (2,3). 
As you travel, pushing the path onto the stack and then popping off when you've hit a dead end (1 being a road and 0 being a dead end).

Considering the top left as index (0,0), using (2,3) as your final destination, your path should look like:
(0, 0) -> (1, 0) -> (1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3) -> (2, 3)

*- Anthony Khoury*
