
+++
authors = ["grid47"]
title = "Leetcode 1878: Get Biggest Three Rhombus Sums in a Grid"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1878: Get Biggest Three Rhombus Sums in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Sorting","Heap (Priority Queue)","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KAuzn8OcGXk"
youtube_upload_date="2021-05-29"
youtube_thumbnail="https://i.ytimg.com/vi/KAuzn8OcGXk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    typedef long long ll;
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> s;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int sz = 0; i + sz < m && i - sz >= 0 && j + 2 * sz < n; sz++) {
                    
                    ll x = i, y = j, rsum = 0;
                    do rsum += grid[x++][y++]; while(x < i + sz);
                    if(sz > 0) {
                        
                        do rsum += grid[x--][y++]; while(y < j + 2 * sz);
                        do rsum += grid[x--][y--]; while(x > i - sz);
                        do rsum += grid[x++][y--]; while(x < i);
                        
                    }
                    s.insert(rsum);
                    if(s.size() > 3) {
                        s.erase(begin(s));}
                }
                }
            }
        return vector<int>(rbegin(s), rend(s));
    }
};
{{< /highlight >}}
---

### Problem Statement

The objective of this problem is to identify the three largest unique sums of diamonds that can be formed in a given grid of integers. A diamond shape in this context is defined as a collection of cells where the center of the diamond is at a specific cell in the grid, and it expands outward symmetrically. The size of the diamond can vary, allowing it to encompass more cells as long as it remains within the boundaries of the grid. The task is to compute the sums of these diamond shapes and return the three largest unique sums.

### Approach

To solve this problem, the following steps are performed:

1. **Initialize Variables**: Set up the dimensions of the grid and a set to store the unique sums of the diamonds.

2. **Iterate Over Each Cell**: For each cell in the grid, treat it as the potential center of a diamond.

3. **Expand the Diamond**: For each cell, expand the diamond shape:
   - Use a nested loop to increase the size of the diamond until it reaches the boundaries of the grid.
   - Compute the sum of the values in the diamond shape by traversing the required cells.

4. **Store Unique Sums**: Store each computed sum in a set to ensure all values are unique.

5. **Limit the Size of the Set**: If the set exceeds three elements, remove the smallest sum to keep only the three largest sums.

6. **Return the Results**: Convert the set of sums to a vector and return it in descending order.

### Code Breakdown (Step by Step)

1. **Class Definition**: The code is encapsulated within a class named `Solution`, which follows the structure used in competitive programming.

   ```cpp
   class Solution {
       typedef long long ll; // Using typedef for long long type for large sums
   public:
   ```

2. **Function Declaration**: The `getBiggestThree` function is declared, taking a 2D vector of integers \( grid \) as input and returning a vector of integers.

   ```cpp
   vector<int> getBiggestThree(vector<vector<int>>& grid) {
   ```

3. **Initialize Variables**: The dimensions of the grid \( m \) and \( n \) are determined. A set \( s \) is created to store unique sums.

   ```cpp
   int m = grid.size(), n = grid[0].size();
   set<int> s;
   ```

4. **Iterate Over Each Cell**: A nested loop iterates through each cell in the grid, treating each cell as the potential center of a diamond.

   ```cpp
   for(int i = 0; i < m; i++) {
       for(int j = 0; j < n; j++) {
   ```

5. **Expand the Diamond**: A third loop is used to determine the size \( sz \) of the diamond while ensuring that the diamond stays within the grid boundaries.

   ```cpp
   for(int sz = 0; i + sz < m && i - sz >= 0 && j + 2 * sz < n; sz++) {
   ```

6. **Compute Diamond Sums**: Within the size loop, variables \( x \) and \( y \) are initialized to the current cell coordinates. The variable \( rsum \) is initialized to zero to accumulate the sum of the diamond's values.

   ```cpp
   ll x = i, y = j, rsum = 0;
   ```

   - The first `do-while` loop accumulates the sum of the left side of the diamond.

   ```cpp
   do rsum += grid[x++][y++]; while(x < i + sz);
   ```

   - If the diamond size is greater than zero, the following loops calculate the remaining sides of the diamond.

   ```cpp
   if(sz > 0) {
       do rsum += grid[x--][y++]; while(y < j + 2 * sz);
       do rsum += grid[x--][y--]; while(x > i - sz);
       do rsum += grid[x++][y--]; while(x < i);
   }
   ```

7. **Store Unique Sums**: The computed sum is inserted into the set \( s \). If the size of the set exceeds three, the smallest element is removed.

   ```cpp
   s.insert(rsum);
   if(s.size() > 3) {
       s.erase(begin(s));
   }
   ```

8. **Return the Results**: Finally, convert the set into a vector, returning it in descending order using reverse iterators.

   ```cpp
   return vector<int>(rbegin(s), rend(s));
   }
   ```

### Complexity

The time complexity of this solution is \( O(m \times n \times \min(m, n)) \), where \( m \) is the number of rows and \( n \) is the number of columns in the grid. This complexity arises because for each cell in the grid, the algorithm potentially examines a diamond of increasing size until it hits the boundary of the grid. The space complexity is \( O(1) \) for the output vector and \( O(k) \) for the set \( s \), where \( k \) is limited to 3 since we are only storing the three largest sums.

### Conclusion

In conclusion, the `getBiggestThree` function effectively identifies the three largest unique sums of diamond shapes in a grid of integers. This approach demonstrates a systematic way to explore possible shapes within a 2D array while efficiently managing and tracking unique sums. The use of nested loops to explore each cell and its potential diamonds illustrates fundamental algorithmic techniques that can be applied to various grid-based problems.

This solution not only provides a clear path to finding the desired sums but also serves as a great example of utilizing data structures like sets for uniqueness and efficiency in tracking results. By understanding and applying these techniques, programmers can enhance their problem-solving skills in both competitive programming and real-world applications where grid manipulation is common. Overall, this problem showcases the combination of mathematical reasoning and programming logic to solve complex challenges efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/)

---
{{< youtube KAuzn8OcGXk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
