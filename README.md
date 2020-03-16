# Find-the-longest-path-in-a-matrix-with-given-constraints
Find the longest path in a matrix with given constraints 
Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1.  We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.  
Example:     
        Input:  mat[][] = {{1, 2, 9}
                           {5, 3, 8}
                           {4, 6, 7}} 
                           
                Output: 4 The longest path is 6-7-8-9. 
