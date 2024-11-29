
+++
authors = ["grid47"]
title = "Leetcode 519: Random Flip Matrix"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 519: Random Flip Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Reservoir Sampling","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/519.webp"
youtube = "9JsC0Dg9oX8"
youtube_upload_date="2024-09-13"
youtube_thumbnail="https://i.ytimg.com/vi/9JsC0Dg9oX8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/519.webp" 
    alt="A matrix where cells are randomly flipped, with each flipped cell softly glowing as it changes state."
    caption="Solution to LeetCode 519: Random Flip Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a binary grid of size m x n, where each cell is initially set to 0. The task is to design an algorithm that can randomly pick a cell that is still 0, flip it to 1, and ensure that all available cells are equally likely to be selected.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a pair of integers m and n representing the size of the grid, followed by a sequence of operations.
- **Example:** `[3, 1], [], [], [], []`
- **Constraints:**
	- 1 <= m, n <= 10^4
	- There will always be at least one cell with value 0 for every flip operation.
	- No more than 1000 flip and reset operations will be performed.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array representing the randomly selected index [i, j] for the flip operation, and null for other operations.
- **Example:** `[null, [1, 0], [2, 0], [0, 0], null, [2, 0]]`
- **Constraints:**
	- The flip operation should return the index of a randomly selected cell that is still 0 and flips it to 1.

{{< dots >}}
### Core Logic 🔍
**Goal:** To randomly select an index where the value is 0, flip it to 1, and ensure equal likelihood for all available indices.

- 1. Maintain a list or map to track available cells with value 0.
- 2. For each flip, randomly pick an index from the list of available cells.
- 3. After picking, flip the cell to 1 and update the list accordingly.
- 4. Reset the grid when the reset operation is called, restoring all values to 0.
{{< dots >}}
### Problem Assumptions ✅
- The grid is initially filled with 0s.
- Each flip picks a valid available index and updates the grid.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, 1], [], [], [], []`  \
  **Explanation:** A grid of size 3x1 is initialized with all zeros. Each flip returns a random index of a free cell, and after resetting, the grid is restored to its initial state.

{{< dots >}}
## Approach 🚀
The solution involves maintaining a list or map of available cells and efficiently selecting a random index while minimizing calls to the random function.

### Initial Thoughts 💭
- We can maintain a map or list that keeps track of the available cells to pick from.
- When selecting a cell, it should be done efficiently to minimize random function calls.
- The reset operation should restore the grid efficiently.
{{< dots >}}
### Edge Cases 🌐
- If the grid is of size 1x1, there is only one cell to flip.
- The algorithm must handle large grid sizes up to 10^4 efficiently.
- The grid should handle reset and flip operations correctly when all cells are flipped to 1 and then reset.
- Ensure that no flip operation is called when there are no available cells.
{{< dots >}}
## Code 💻
```cpp
class Solution {
map<int, int> mp;
int row, col, lmt;
public:
Solution(int m, int n) {
    row = m;
    col = n;
    reset();
}

vector<int> flip() {
    int idx = rand()%lmt;
    lmt--;
    int x = mp.count(idx)? mp[idx] : idx;
    mp[idx] = mp.count(lmt)? mp[lmt]: lmt;
    return vector<int>{x/col, x%col};
}

void reset() {
    mp.clear();
    lmt = row*col;
}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
```

This solution defines a class `Solution` which simulates flipping a 2D matrix using a random index, allowing for the flipping of coordinates and resetting the state.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	This defines the `Solution` class, which will contain methods for flipping and resetting the matrix simulation.

2. **Data Members**
	```cpp
	map<int, int> mp;
	```
	This is a map `mp` used to store the indices of flipped cells, mapping the index to a new location.

3. **Data Members**
	```cpp
	int row, col, lmt;
	```
	These integer variables represent the number of rows (`row`), columns (`col`), and the limit (`lmt`) for random index generation.

4. **Constructor**
	```cpp
	public:
	```
	This marks the start of the public section of the class where constructors and methods will be defined.

5. **Constructor**
	```cpp
	Solution(int m, int n) {
	```
	Constructor for the `Solution` class that takes the number of rows `m` and columns `n` as parameters and initializes the object.

6. **Constructor Initialization**
	```cpp
	    row = m;
	```
	Assign the value of `m` to the `row` data member.

7. **Constructor Initialization**
	```cpp
	    col = n;
	```
	Assign the value of `n` to the `col` data member.

8. **Constructor Method Call**
	```cpp
	    reset();
	```
	Call the `reset()` method to initialize or reset the state of the object.

9. **Method Definition**
	```cpp
	vector<int> flip() {
	```
	This method `flip` returns a random 2D index (row and column) based on a random number and the current state.

10. **Randomization**
	```cpp
	    int idx = rand()%lmt;
	```
	Generate a random index `idx` between 0 and `lmt-1`.

11. **Update Limit**
	```cpp
	    lmt--;
	```
	Decrease the limit `lmt` after every flip to reduce the number of possible indices.

12. **Mapping Logic**
	```cpp
	    int x = mp.count(idx)? mp[idx] : idx;
	```
	Check if the random index `idx` is already mapped; if yes, use the mapped value, otherwise, use the index itself.

13. **Mapping Update**
	```cpp
	    mp[idx] = mp.count(lmt)? mp[lmt]: lmt;
	```
	Map the current `idx` to the new limit `lmt`. This operation swaps the locations of the random index and the last available index.

14. **Return Statement**
	```cpp
	    return vector<int>{x/col, x%col};
	```
	Return the row and column of the flipped index as a vector, where `x/col` is the row and `x%col` is the column.

15. **Method Definition**
	```cpp
	void reset() {
	```
	This method `reset` is used to clear the map `mp` and reset the limit `lmt` to the total number of cells.

16. **Reset Logic**
	```cpp
	    mp.clear();
	```
	Clear the map `mp` to reset all the flipped cell mappings.

17. **Reset Logic**
	```cpp
	    lmt = row*col;
	```
	Reset the limit `lmt` to the total number of cells (rows * columns).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for reset operation.
- **Average Case:** O(1) for flip operation when using optimized data structures.
- **Worst Case:** O(1) for both flip and reset operations.

Both flip and reset operations are optimized to O(1) time using efficient data structures.

### Space Complexity 💾
- **Best Case:** O(1) when grid is empty (only when grid is reset).
- **Worst Case:** O(m * n) to store the grid and available cells.

The space complexity is O(m * n) due to the need to track the available cells in the grid.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/random-flip-matrix/description/)

---
{{< youtube 9JsC0Dg9oX8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
