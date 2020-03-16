# Dynamic Programming
# 1.Find-the-longest-path-in-a-matrix-with-given-constraints
Find the longest path in a matrix with given constraints 
Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1.  We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.  
Example:     
        Input:  mat[][] = {{1, 2, 9}
{5, 3, 8}
{4, 6, 7}} 
                           
                Output: 4 The longest path is 6-7-8-9. 


# 2.Cutting a rod for maximum profit (Given price of each piece length)
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, 

if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)
price = 1   5   8   9  10  17  17  20
for increasing length of piece from 1 to n


And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)
price = 3   5   8   9  10  17  17  20
for increasing length of piece from 1 to n
