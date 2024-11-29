
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
comments = true
+++



---
You are given an `m x n` matrix `grid`. A **rhombus sum** refers to the sum of the elements that form the border of a rhombus shape. The rhombus should be viewed as a square rotated 45 degrees, with each of its corners centered on a grid cell. Compute the biggest three distinct rhombus sums in the grid and return them in descending order. If there are fewer than three distinct sums, return all of them.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D matrix `grid` of integers.
- **Example:** `For grid = [[5,1,3],[4,2,6],[7,8,9]].`
- **Constraints:**
	- 1 <= m, n <= 50
	- 1 <= grid[i][j] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the biggest three distinct rhombus sums in descending order. If fewer than three distinct sums exist, return all of them.
- **Example:** `For grid = [[5,1,3],[4,2,6],[7,8,9]], the output is [25, 17, 12].`
- **Constraints:**
	- The output should be an array of integers representing the biggest three distinct rhombus sums.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the rhombus sums, we need to iterate through all possible centers in the grid and calculate the sum of elements that form the rhombus for each center.

- Iterate over each cell in the grid to treat it as a potential center of a rhombus.
- For each center, compute the sum of all grid elements that form the rhombus border.
- Store these sums in a set to ensure distinct values.
- Sort the set and return the top three distinct sums.
{{< dots >}}
### Problem Assumptions ✅
- The grid is at least 1x1 in size.
- All grid elements are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `For grid = [[5,1,3],[4,2,6],[7,8,9]].`  \
  **Explanation:** The rhombus sums for the three biggest distinct rhombuses are: 25, 17, and 12.

- **Input:** `For grid = [[7, 7, 7]].`  \
  **Explanation:** Since all rhombus sums are the same, the output is [7].

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves calculating the rhombus sum for each possible center in the grid. For each center, we add the values of the grid cells that make up the rhombus and store them. The biggest three distinct sums are then returned.

### Initial Thoughts 💭
- The rhombus shape can expand out from a center and includes values from adjacent cells at varying distances.
- We need to carefully iterate through all possible rhombus shapes, ensuring we compute the correct sums and handle distinct values efficiently.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as the grid is guaranteed to have at least one row and one column.
- The algorithm should efficiently handle grids as large as 50x50.
- All elements being the same value or all rhombus sums being identical.
- The grid should be within the given constraints.
{{< dots >}}
## Code 💻
```cpp
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
```

This code computes the three largest unique rhombus sums in a 2D grid by iterating over possible rhombus centers and sizes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Define a class to encapsulate the solution logic.

2. **Type Alias**
	```cpp
	typedef long long ll;
	```
	Define a type alias for long long integers to simplify usage.

3. **Access Modifier**
	```cpp
	public:
	```
	Specify public access for class members.

4. **Function Definition**
	```cpp
	vector<int> getBiggestThree(vector<vector<int>>& grid) {
	```
	Define a function to compute the three largest unique rhombus sums in a grid.

5. **Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Initialize the grid dimensions.

6. **Set Initialization**
	```cpp
	    set<int> s;
	```
	Use a set to store unique rhombus sums, automatically sorted.

7. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Iterate over all rows of the grid.

8. **Inner Loop**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	Iterate over all columns of the grid.

9. **Rhombus Size Loop**
	```cpp
	            for(int sz = 0; i + sz < m && i - sz >= 0 && j + 2 * sz < n; sz++) {
	```
	Iterate over possible rhombus sizes centered at (i, j).

10. **Variable Initialization**
	```cpp
	                ll x = i, y = j, rsum = 0;
	```
	Initialize variables for rhombus calculation.

11. **Diagonal Sum**
	```cpp
	                do rsum += grid[x++][y++]; while(x < i + sz);
	```
	Calculate the sum of the first diagonal.

12. **Check Size**
	```cpp
	                if(sz > 0) {
	```
	Proceed with additional rhombus sides if the size is greater than zero.

13. **Second Diagonal**
	```cpp
	                    do rsum += grid[x--][y++]; while(y < j + 2 * sz);
	```
	Calculate the sum of the second diagonal.

14. **Third Diagonal**
	```cpp
	                    do rsum += grid[x--][y--]; while(x > i - sz);
	```
	Calculate the sum of the third diagonal.

15. **Fourth Diagonal**
	```cpp
	                    do rsum += grid[x++][y--]; while(x < i);
	```
	Calculate the sum of the fourth diagonal.

16. **Insert to Set**
	```cpp
	                s.insert(rsum);
	```
	Insert the calculated rhombus sum into the set.

17. **Set Size Check**
	```cpp
	                if(s.size() > 3) {
	```
	Ensure the set only keeps the three largest sums.

18. **Erase Smallest**
	```cpp
	                    s.erase(begin(s));}
	```
	Remove the smallest sum if the set size exceeds three.

19. **End Rhombus Size Loop**
	```cpp
	            }
	```
	End the loop for iterating rhombus sizes.

20. **Return Statement**
	```cpp
	    return vector<int>(rbegin(s), rend(s));
	```
	Convert the set to a vector and return the three largest sums in descending order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n * k)
- **Worst Case:** O(m * n * k)

The time complexity depends on the size of the grid and the maximum possible size of a rhombus that can be formed from each cell.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m * n)

Space complexity is O(m * n) due to the storage of rhombus sums in a set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/)

---
{{< youtube KAuzn8OcGXk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
