
+++
authors = ["grid47"]
title = "Leetcode 1536: Minimum Swaps to Arrange a Binary Grid"
date = "2024-06-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1536: Minimum Swaps to Arrange a Binary Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "OLA5Qwt4NKw"
youtube_upload_date="2020-08-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/OLA5Qwt4NKw/maxresdefault.webp"
comments = true
+++



---
You are given an n x n binary grid, and in one move, you can swap any two adjacent rows. The grid is valid if all the cells above the main diagonal are zeros. Your task is to return the minimum number of swaps needed to make the grid valid, or -1 if it's not possible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer grid of size n x n, where each element is either 0 or 1.
- **Example:** `grid = [[0, 1, 1], [1, 0, 1], [1, 0, 0]]`
- **Constraints:**
	- n == grid.length == grid[i].length
	- 1 <= n <= 200
	- grid[i][j] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of swaps required to make the grid valid, or -1 if it's not possible.
- **Example:** `For grid = [[0, 1, 1], [1, 0, 1], [1, 0, 0]], the output is 2.`
- **Constraints:**
	- The output is an integer indicating the number of swaps required or -1 if the grid cannot be made valid.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to transform the grid such that all the cells above the main diagonal are zeros by performing a minimum number of adjacent row swaps.

- For each row, count the number of trailing zeros.
- For each row, try to find a valid position that can be swapped to fulfill the condition of zeros above the main diagonal.
- Simulate the row swaps and track how many steps it takes to achieve a valid grid.
{{< dots >}}
### Problem Assumptions ✅
- The grid contains distinct rows in terms of binary values.
- It's guaranteed that a valid grid is achievable for some test cases, and for others, it's not possible.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[0, 1, 1], [1, 0, 1], [1, 0, 0]]`  \
  **Explanation:** By swapping rows 0 and 2, followed by swapping rows 1 and 2, we can make the grid valid with 2 moves.

- **Input:** `grid = [[0, 1, 1, 0], [0, 1, 1, 0], [0, 1, 1, 0], [0, 1, 1, 0]]`  \
  **Explanation:** Since all the rows are the same, no valid transformation is possible, and the output is -1.

{{< dots >}}
## Approach 🚀
The approach is to simulate the process of row swaps and track the number of steps required to transform the grid into a valid one.

### Initial Thoughts 💭
- The problem boils down to counting the trailing zeros of each row and determining whether we can swap rows to make the grid valid.
- We need to focus on minimizing the number of swaps and checking if it's possible to reach a valid state.
{{< dots >}}
### Edge Cases 🌐
- The grid will always have at least one row, as n >= 1.
- For large grids (up to 200x200), ensure the solution is optimized for time and space efficiency.
- Handle cases where all rows are the same and swaps won't help.
- Ensure that the solution handles grids with n up to 200.
{{< dots >}}
## Code 💻
```cpp
int minSwaps(vector<vector<int>>& grid) {
    
    int n = grid.size();
    
    set<int> found;
    
    vector<int> arr(n, 0);
    
    for(int i = 0; i < n; i++) {
        
        int j = n - 1, cnt = 0;
        while(j > -1 && grid[i][j] == 0) {
            j--;
            cnt++;
        }
        
        for(int k = n - 1; k >= 0; k--) {
            if(cnt >= k && !found.count(k)) {
                found.insert(k);
                arr[i] = n - 1 - k;
                break;
            }
        }
    }
    
    if(found.size() != n) return -1;
    
    return bubble(arr);
}

int bubble(vector<int> &arr) {
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++)
    for(int j = 1; j < arr.size(); j++)
        if(arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            cnt++;
        }
    
    return cnt;
}
```

This function calculates the minimum number of swaps required to arrange a grid of integers such that every row's non-zero elements are aligned with the non-zero elements of the next row. The approach involves counting trailing zeros in each row and calculating swaps through a bubble sort-like algorithm.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minSwaps(vector<vector<int>>& grid) {
	```
	This is the function declaration for `minSwaps`, which takes a 2D vector `grid` representing the grid of integers as input.

2. **Variable Initialization**
	```cpp
	    int n = grid.size();
	```
	The variable `n` is initialized to the size of the grid. This represents the number of rows in the grid.

3. **Set Declaration**
	```cpp
	    set<int> found;
	```
	The set `found` is used to store the indices of rows that have already been processed, ensuring no duplicate indices are used.

4. **Vector Initialization**
	```cpp
	    vector<int> arr(n, 0);
	```
	A vector `arr` is initialized with `n` elements, all set to zero. It will store the number of swaps for each row.

5. **For Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A for loop starts to iterate through each row of the grid.

6. **Variable Initialization**
	```cpp
	        int j = n - 1, cnt = 0;
	```
	Two variables are initialized: `j` is set to the last column index, and `cnt` is set to zero. `cnt` tracks the number of trailing zeros in the row.

7. **While Loop**
	```cpp
	        while(j > -1 && grid[i][j] == 0) {
	```
	A while loop starts, moving `j` backward until a non-zero element is found or all elements are checked.

8. **Decrement Operation**
	```cpp
	            j--;
	```
	Decrements `j` to check the previous column.

9. **Increment Operation**
	```cpp
	            cnt++;
	```
	Increments `cnt` as a trailing zero is encountered.

10. **For Loop**
	```cpp
	        for(int k = n - 1; k >= 0; k--) {
	```
	A nested for loop iterates backward through the rows to find the appropriate position for the number of trailing zeros in `arr[i]`.

11. **Conditional Check**
	```cpp
	            if(cnt >= k && !found.count(k)) {
	```
	Checks if the current `cnt` is greater than or equal to `k` and if `k` has not already been used.

12. **Insert Operation**
	```cpp
	                found.insert(k);
	```
	Inserts `k` into the set `found`, marking this row as processed.

13. **Array Update**
	```cpp
	                arr[i] = n - 1 - k;
	```
	Updates the `arr[i]` with the number of swaps needed for this row based on the value of `k`.

14. **Break Statement**
	```cpp
	                break;
	```
	Breaks out of the inner for loop after the swap has been made.

15. **Conditional Check**
	```cpp
	    if(found.size() != n) return -1;
	```
	Checks if the size of the set `found` is not equal to `n`. If true, it returns -1 indicating that it is impossible to rearrange the grid.

16. **Return Statement**
	```cpp
	    return bubble(arr);
	```
	Returns the result of the `bubble` function, which calculates the number of swaps required to sort the array `arr`.

17. **Function Declaration**
	```cpp
	int bubble(vector<int> &arr) {
	```
	This function performs a bubble sort on the `arr` and returns the number of swaps made.

18. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes `cnt` to count the number of swaps performed during the bubble sort.

19. **For Loop**
	```cpp
	    for(int i = 0; i < arr.size(); i++)
	```
	A loop that iterates through the elements of `arr`.

20. **Nested For Loop**
	```cpp
	    for(int j = 1; j < arr.size(); j++)
	```
	A nested loop that compares adjacent elements in `arr`.

21. **Conditional Check**
	```cpp
	        if(arr[j - 1] > arr[j]) {
	```
	Checks if the current element is greater than the next element.

22. **Swap Operation**
	```cpp
	            swap(arr[j - 1], arr[j]);
	```
	Swaps the two elements if the current element is greater than the next.

23. **Increment Operation**
	```cpp
	            cnt++;
	```
	Increments the swap counter.

24. **Return Statement**
	```cpp
	    return cnt;
	```
	Returns the number of swaps made during the bubble sort.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we perform row comparisons and potential swaps.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the auxiliary arrays used to track row positions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/)

---
{{< youtube OLA5Qwt4NKw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
