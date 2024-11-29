
+++
authors = ["grid47"]
title = "Leetcode 2579: Count Total Number of Colored Cells"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2579: Count Total Number of Colored Cells in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Gso3ss4daQI"
youtube_upload_date="2023-03-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Gso3ss4daQI/maxresdefault.webp"
comments = true
+++



---
You are given a 2D array `ranges`, where each entry `ranges[i] = [starti, endi]` denotes a range of integers between `starti` and `endi` (inclusive). You need to split the ranges into two groups, ensuring that overlapping ranges belong to the same group. Return the total number of ways to split the ranges into two groups modulo (10^9 + 7).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array `ranges`, where each element is a pair of integers [starti, endi].
- **Example:** `For example, `ranges = [[3, 6], [1, 5]]`.`
- **Constraints:**
	- 1 <= ranges.length <= 10^5
	- 0 <= starti <= endi <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the total number of ways to split the ranges into two groups modulo (10^9 + 7).
- **Example:** `For input `ranges = [[3, 6], [1, 5]]`, the output is `2`.`
- **Constraints:**
	- The output should be returned modulo (10^9 + 7).

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the total number of ways to split the given ranges into two groups, ensuring that overlapping ranges are in the same group.

- 1. Sort the ranges based on the starting value.
- 2. Use a union-find data structure to group overlapping ranges.
- 3. For each group of connected ranges, calculate the possible splits.
- 4. Return the total number of valid ways to split the groups.
{{< dots >}}
### Problem Assumptions ✅
- The number of ranges can be large, so the solution must be efficient.
{{< dots >}}
## Examples 🧩
- **Input:** `For input `ranges = [[3, 6], [1, 5]]`.`  \
  **Explanation:** Both ranges overlap, so there are only two possible ways to split them: both in group 1 or both in group 2.

{{< dots >}}
## Approach 🚀
We will use a union-find (disjoint-set) data structure to identify groups of overlapping ranges and calculate the number of ways to split these groups.

### Initial Thoughts 💭
- We need to efficiently group overlapping ranges.
- By sorting the ranges and using a union-find structure, we can determine the number of disjoint sets of overlapping ranges.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one range.
- For large inputs, ensure the union-find operations are efficient to handle up to 10^5 ranges.
- If all ranges are disjoint, there are multiple ways to split them.
- Handle the case where all ranges overlap or none of them overlap.
{{< dots >}}
## Code 💻
```cpp
long long coloredCells(int n) {
    long long x = 1;
    long long y = 4;
    while(--n) {
        x += y;
        y += 4;
    }
    // 0 4 8 12
    return x;
    
    queue<pair<int, int>> q;
    unordered_map<int, unordered_map<int, int>> mp;
    long long cnt = 1;
    q.push({0,0});
    mp[0][0] = true;
    int dir[] = {0,1,0,-1,0};
    while(--n) {
        int sz = q.size();
        while(sz--) {
            auto it = q.front();
            q.pop();
            // cout << it.first << " " << it.second << "\n";
            for(int i = 0; i < 4; i++) {
                int x = it.first + dir[i], y = it.second + dir[i + 1];
                if(mp.count(x) && mp[x].count(y)) continue;
                mp[x][y] = true;
                cnt++;
                q.push({x, y});
            }
        }
    }
    return cnt;
}
```

This function calculates the number of colored cells in a grid, first using a simple formula, then with a breadth-first search (BFS) approach for counting valid cells based on movement directions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long coloredCells(int n) {
	```
	Define a function to calculate the number of colored cells for a given value of n.

2. **Variable Initialization**
	```cpp
	    long long x = 1;
	```
	Initialize variable x to represent the initial colored cells count.

3. **Variable Initialization**
	```cpp
	    long long y = 4;
	```
	Initialize variable y for the number of colored cells in subsequent rows.

4. **Looping**
	```cpp
	    while(--n) {
	```
	Start a loop that continues until n is reduced to zero.

5. **Cell Calculation**
	```cpp
	        x += y;
	```
	Add the current value of y to x, incrementing the count of colored cells.

6. **Cell Calculation**
	```cpp
	        y += 4;
	```
	Increase y by 4 to account for the new number of cells in the next row.

7. **Return Statement**
	```cpp
	    return x;
	```
	Return the final value of x, which represents the total number of colored cells.

8. **Queue Initialization**
	```cpp
	    queue<pair<int, int>> q;
	```
	Initialize a queue to store the coordinates of the cells to be processed.

9. **Map Initialization**
	```cpp
	    unordered_map<int, unordered_map<int, int>> mp;
	```
	Initialize a map to track the visited cells, ensuring no repeats in processing.

10. **Counter Initialization**
	```cpp
	    long long cnt = 1;
	```
	Initialize the counter variable cnt to 1, accounting for the starting cell.

11. **Queue Push**
	```cpp
	    q.push({0,0});
	```
	Push the starting cell coordinates (0, 0) into the queue.

12. **Map Setup**
	```cpp
	    mp[0][0] = true;
	```
	Mark the starting cell (0, 0) as visited in the map.

13. **Direction Setup**
	```cpp
	    int dir[] = {0,1,0,-1,0};
	```
	Define an array of directions to move in the grid (right, down, left, up).

14. **Looping**
	```cpp
	    while(--n) {
	```
	Start a loop to process each level of BFS.

15. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Store the current size of the queue to process each element at this level.

16. **Inner Loop**
	```cpp
	        while(sz--) {
	```
	Loop through the current level of BFS by processing the elements in the queue.

17. **Queue Processing**
	```cpp
	            auto it = q.front();
	```
	Get the front element from the queue for processing.

18. **Queue Pop**
	```cpp
	            q.pop();
	```
	Remove the front element from the queue after processing it.

19. **Direction Loop**
	```cpp
	            for(int i = 0; i < 4; i++) {
	```
	Loop through all four possible movement directions (right, down, left, up).

20. **Coordinate Calculation**
	```cpp
	                int x = it.first + dir[i], y = it.second + dir[i + 1];
	```
	Calculate the new coordinates after moving in the current direction.

21. **Map Check**
	```cpp
	                if(mp.count(x) && mp[x].count(y)) continue;
	```
	Check if the new coordinates have already been visited. If so, continue to the next direction.

22. **Mark Visited**
	```cpp
	                mp[x][y] = true;
	```
	Mark the new coordinates as visited in the map.

23. **Increment Counter**
	```cpp
	                cnt++;
	```
	Increment the counter to reflect the newly visited cell.

24. **Queue Push**
	```cpp
	                q.push({x, y});
	```
	Push the new coordinates into the queue for further processing.

25. **Return Statement**
	```cpp
	    return cnt;
	```
	Return the final count of the visited cells.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, where n is the number of ranges.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the ranges and union-find structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-total-number-of-colored-cells/description/)

---
{{< youtube Gso3ss4daQI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
