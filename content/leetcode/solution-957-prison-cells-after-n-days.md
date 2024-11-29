
+++
authors = ["grid47"]
title = "Leetcode 957: Prison Cells After N Days"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 957: Prison Cells After N Days in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mQQp6I985bw"
youtube_upload_date="2020-11-09"
youtube_thumbnail="https://i.ytimg.com/vi/mQQp6I985bw/maxresdefault.jpg"
comments = true
+++



---
You are given a row of 8 prison cells, where each cell is either occupied or vacant. The state of the cells changes every day according to the following rules: If a cell has two adjacent neighbors that are either both occupied or both vacant, the cell becomes occupied; otherwise, it becomes vacant. The first and last cells don't have two neighbors, so they are excluded from the rule. You need to determine the state of the cells after 'n' days of changes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of 8 integers representing the state of the prison cells, where 1 indicates an occupied cell and 0 indicates a vacant cell, followed by an integer n representing the number of days.
- **Example:** `Input: cells = [1,0,0,1,0,0,1,0], n = 4`
- **Constraints:**
	- The number of cells is always 8.
	- Each cell is represented as 0 or 1.
	- 1 <= n <= 10^9.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array of 8 integers representing the state of the prison cells after 'n' days of changes.
- **Example:** `Output: [0,0,1,1,0,0,1,0]`
- **Constraints:**
	- The output will always contain 8 integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to simulate the state changes for 'n' days, but since the state can repeat after a certain number of days, we need to optimize the solution.

- 1. Track the states of the cells on each day.
- 2. Use a set to detect repeating cell configurations to optimize the simulation process.
- 3. If a state repeats, the simulation enters a cycle. Thus, we can skip unnecessary days by calculating the effective number of days based on the cycle length.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always have 8 cells, and each cell is either 0 or 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: cells = [1,0,0,1,0,0,1,0], n = 4`  \
  **Explanation:** In this case, the prison cells will go through a series of changes, but after 4 days, the state of the cells will be [0,0,1,1,0,0,1,0].

- **Input:** `Input: cells = [0,1,0,1,0,1,0,1], n = 2`  \
  **Explanation:** After 2 days, the prison cells will change according to the rules and reach the final state [1,0,1,1,0,1,0,1].

{{< dots >}}
## Approach 🚀
The key to solving this problem efficiently is to detect repeating states, which would indicate the start of a cycle. Once a cycle is detected, we can skip unnecessary steps.

### Initial Thoughts 💭
- The number of cells is fixed at 8, so the possible states are limited. This makes it possible to track and detect cycles.
- To optimize the solution, we can use a set to track previously seen states. If a state repeats, we can calculate the effective number of days and avoid unnecessary computations.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as the number of cells is always 8.
- For large values of n (up to 10^9), we must avoid iterating over each day by detecting cycles early.
- The input will always contain exactly 8 cells, and the values will be binary (0 or 1).
- The simulation must be optimized to handle the upper constraint of n (up to 10^9).
{{< dots >}}
## Code 💻
```cpp
vector<int> prisonAfterNDays(vector<int>& cells, int n) {
    set<vector<int>> seen;
    int i = 0, flag = 0;
    vector<int> c;
    for(i = 0; i < n; i++) {
        vector<int> v = getNext(cells);
        if(!seen.count(v)) {
            seen.insert(v);
            cells = v;
        } else {
            for(int j = 0; j < n % i; j++) {
                cells = getNext(cells);
            }
            return cells;
        }
    }
    return cells;
}

vector<int> getNext(vector<int> &cells) {
    vector<int> n(cells.size(), 0);
    for(int i = 1; i < cells.size() -1; i++)
        n[i] = cells[i-1] == cells[i+1]?1:0;
    return n;
}
```

This function simulates the state of prison cells over `n` days. It identifies cycles using a set and computes the final state based on modular arithmetic to optimize computation for large `n` values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> prisonAfterNDays(vector<int>& cells, int n) {
	```
	Function declaration for `prisonAfterNDays` which takes the initial state of cells and the number of days as input.

2. **Data Structure Initialization**
	```cpp
	    set<vector<int>> seen;
	```
	Initialize a set to keep track of previously seen states of the cells, used for detecting cycles.

3. **Variable Initialization**
	```cpp
	    int i = 0, flag = 0;
	```
	Initialize variables `i` for iteration and `flag` for condition tracking (not used here).

4. **Temporary Vector**
	```cpp
	    vector<int> c;
	```
	Declare a temporary vector `c` (not used in this implementation).

5. **Outer Loop**
	```cpp
	    for(i = 0; i < n; i++) {
	```
	Iterate over each day up to `n` to compute the state transitions of the cells.

6. **Get Next State**
	```cpp
	        vector<int> v = getNext(cells);
	```
	Calculate the next state of the cells using the `getNext` helper function.

7. **Cycle Detection**
	```cpp
	        if(!seen.count(v)) {
	```
	Check if the current state has been seen before to detect a cycle.

8. **Insert State**
	```cpp
	            seen.insert(v);
	```
	Insert the current state into the set of seen states to keep track of cycles.

9. **Update State**
	```cpp
	            cells = v;
	```
	Update the cells to the next state.

10. **Cycle Found**
	```cpp
	        } else {
	```
	If a cycle is detected, exit the main loop and compute the state based on the cycle length.

11. **Cycle Optimization**
	```cpp
	            for(int j = 0; j < n % i; j++) {
	```
	Iterate only the remaining days modulo the cycle length to compute the final state.

12. **Get Next in Cycle**
	```cpp
	                cells = getNext(cells);
	```
	Update the cells state iteratively within the cycle to find the final state.

13. **Return State Early**
	```cpp
	            return cells;
	```
	Return the cells' state once the final state within the cycle is computed.

14. **Return Final State**
	```cpp
	    return cells;
	```
	Return the final state of the cells after `n` days.

15. **Helper Function Declaration**
	```cpp
	vector<int> getNext(vector<int> &cells) {
	```
	Helper function declaration for `getNext` which calculates the next state of the cells.

16. **Initialize Next State**
	```cpp
	    vector<int> n(cells.size(), 0);
	```
	Initialize a vector `n` with the same size as `cells` to store the next state.

17. **Inner Loop**
	```cpp
	    for(int i = 1; i < cells.size() -1; i++)
	```
	Iterate through the cells, skipping the first and last ones, to calculate the next state.

18. **Update Cell State**
	```cpp
	        n[i] = cells[i-1] == cells[i+1]?1:0;
	```
	Update the state of each cell based on the parity of its neighbors.

19. **Return Next State**
	```cpp
	    return n;
	```
	Return the computed next state of the cells.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(k + m)
- **Worst Case:** O(k + m)

Where k is the length of the cycle and m is the maximum number of iterations before detecting a cycle. In the worst case, the cycle detection is a constant-time operation after some iterations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(k)

The space complexity is O(k), where k is the number of distinct states that can occur before the system cycles.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/prison-cells-after-n-days/description/)

---
{{< youtube mQQp6I985bw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
