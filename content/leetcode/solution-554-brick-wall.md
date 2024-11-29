
+++
authors = ["grid47"]
title = "Leetcode 554: Brick Wall"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 554: Brick Wall in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/554.webp"
youtube = "Kkmv2h48ekw"
youtube_upload_date="2021-04-24"
youtube_thumbnail="https://i.ytimg.com/vi/Kkmv2h48ekw/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/554.webp" 
    alt="A wall made of bricks where the minimum number of bricks to be removed is calculated, with the optimal brick removals glowing."
    caption="Solution to LeetCode 554: Brick Wall Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a rectangular wall made up of bricks with varying widths, your task is to determine the minimum number of bricks that a vertical line crosses. The line should be drawn such that it does not cross any brick's edge, and you cannot place the line at the edges of the wall.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D array 'wall' where each row represents a row of bricks. Each brick in a row is represented by its width.
- **Example:** `Input: wall = [[2, 3, 1], [4, 2], [1, 3, 1], [3, 2, 1]]`
- **Constraints:**
	- 1 <= n <= 104
	- 1 <= wall[i].length <= 104
	- 1 <= sum(wall[i].length) <= 2 * 104
	- sum(wall[i]) is the same for each row i.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the minimum number of bricks that a vertical line crosses.
- **Example:** `Output: 2`
- **Constraints:**
	- The returned value should be an integer representing the minimum number of crossed bricks.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the vertical line position that crosses the fewest bricks.

- For each row, calculate the position of the brick edges as you iterate through the row.
- Track the frequency of these positions across all rows using a map or hash table.
- The most frequent position indicates where the fewest bricks are crossed, and the answer is the number of rows minus the maximum frequency.
{{< dots >}}
### Problem Assumptions ✅
- The input wall will always have at least one row.
- The number of bricks in each row is guaranteed to be consistent in terms of total width.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: wall = [[2, 3, 1], [4, 2], [1, 3, 1], [3, 2, 1]]`  \
  **Explanation:** The vertical line crossing the edge between the second and third bricks of the first row results in crossing only 2 bricks across all rows.

{{< dots >}}
## Approach 🚀
The approach involves tracking the positions of the edges of the bricks in each row and counting the frequency of these positions across all rows. The position that occurs most frequently is where the least number of bricks are crossed.

### Initial Thoughts 💭
- If the vertical line is placed at the edges where the most bricks align, fewer bricks will be crossed.
- We need to avoid crossing any edges of the bricks and aim for positions where the least number of bricks will be affected.
- This can be done efficiently by tracking the frequency of edge positions and selecting the one that minimizes the number of crossed bricks.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as the number of rows is guaranteed to be at least 1.
- The solution should efficiently handle up to 10^4 rows and total brick widths up to 2 * 10^4.
- If the wall has only one column, the vertical line will cross all bricks, and the answer is equal to the number of rows.
- The algorithm should work efficiently within the problem's constraints, particularly with large inputs.
{{< dots >}}
## Code 💻
```cpp
int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> edge_freq;
    int max_freq = 0;
    for(int row = 0; row < wall.size(); row++) {
        int edge_pos = 0;
        for(int brick_no = 0; brick_no < wall[row].size() - 1; brick_no++) {
            int curr_brick_length = wall[row][brick_no];
            edge_pos = edge_pos + curr_brick_length;
            edge_freq[edge_pos]++;
            max_freq = max(edge_freq[edge_pos], max_freq);
        }
    }
    return wall.size() - max_freq;
}
```

This function calculates the least number of bricks that a vertical line would intersect when passed through a wall represented as a 2D grid. It uses a frequency map to track the most common brick edge positions and minimizes the number of intersected bricks by finding the most frequent edge.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int leastBricks(vector<vector<int>>& wall) {
	```
	Defines the function `leastBricks`, which takes a 2D vector `wall` representing the brick wall and returns the minimum number of bricks that a vertical line intersects.

2. **Hash Map Initialization**
	```cpp
	    unordered_map<int, int> edge_freq;
	```
	Initializes an unordered map `edge_freq` to store the frequency of each edge position encountered while iterating over the wall.

3. **Variable Initialization**
	```cpp
	    int max_freq = 0;
	```
	Initializes a variable `max_freq` to track the highest frequency of any edge position encountered.

4. **Outer Loop (Row Traversal)**
	```cpp
	    for(int row = 0; row < wall.size(); row++) {
	```
	Begins a loop to traverse each row of the wall.

5. **Edge Position Initialization**
	```cpp
	        int edge_pos = 0;
	```
	Initializes `edge_pos` to keep track of the current edge position as we iterate through the bricks in a row.

6. **Inner Loop (Brick Traversal)**
	```cpp
	        for(int brick_no = 0; brick_no < wall[row].size() - 1; brick_no++) {
	```
	Starts a loop to traverse each brick in the current row, excluding the last brick, to avoid counting the edge of the last brick.

7. **Brick Length Extraction**
	```cpp
	            int curr_brick_length = wall[row][brick_no];
	```
	Extracts the length of the current brick in the row.

8. **Edge Position Update**
	```cpp
	            edge_pos = edge_pos + curr_brick_length;
	```
	Updates the current edge position by adding the length of the current brick.

9. **Edge Frequency Update**
	```cpp
	            edge_freq[edge_pos]++;
	```
	Increments the frequency count for the current edge position in the `edge_freq` map.

10. **Max Frequency Update**
	```cpp
	            max_freq = max(edge_freq[edge_pos], max_freq);
	```
	Updates the `max_freq` variable to track the highest frequency of any edge position encountered so far.

11. **Return Statement**
	```cpp
	    return wall.size() - max_freq;
	```
	Returns the minimum number of bricks intersected by a vertical line, which is the total number of rows minus the maximum frequency of edge positions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear with respect to the total number of bricks, as we are iterating through the entire wall once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the frequency map that tracks the edge positions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/brick-wall/description/)

---
{{< youtube Kkmv2h48ekw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
