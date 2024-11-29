
+++
authors = ["grid47"]
title = "Leetcode 2271: Maximum White Tiles Covered by a Carpet"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2271: Maximum White Tiles Covered by a Carpet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "U7fqZr_ZLd4"
youtube_upload_date="2022-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/U7fqZr_ZLd4/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D integer array `tiles`, where each element `tiles[i] = [li, ri]` represents that all integers from `li` to `ri` are painted white on a number line. Additionally, you are given an integer `carpetLen`, which represents the length of a carpet that can be placed anywhere on the number line. Your task is to return the maximum number of white tiles that can be covered by placing the carpet in a way that it maximizes the number of white tiles covered.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two values: a list `tiles` containing ranges, and a number `carpetLen` representing the length of the carpet.
- **Example:** `tiles = [[1, 4], [6, 8], [12, 14]], carpetLen = 5`
- **Constraints:**
	- 1 <= tiles.length <= 50,000
	- tiles[i].length == 2
	- 1 <= li <= ri <= 10^9
	- 1 <= carpetLen <= 10^9
	- The tiles are non-overlapping.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of white tiles that the carpet can cover.
- **Example:** `Output: 5`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the maximum number of white tiles that can be covered by placing the carpet optimally.

- Sort the tiles by their left endpoint.
- Use a sliding window approach to check each possible placement of the carpet over the tiles, and track the maximum number of tiles covered.
- For each placement, consider whether the carpet fully or partially covers each tile, and adjust the count of white tiles covered accordingly.
{{< dots >}}
### Problem Assumptions ✅
- The tiles are non-overlapping, so no two tiles will share the same number.
{{< dots >}}
## Examples 🧩
- **Input:** `tiles = [[1, 5], [10, 11], [12, 18], [20, 25], [30, 32]], carpetLen = 10`  \
  **Explanation:** In this example, placing the carpet starting at tile 10 will cover 9 white tiles, which is the maximum number of tiles that can be covered by a carpet of length 10.

- **Input:** `tiles = [[1, 2], [4, 5], [7, 10]], carpetLen = 4`  \
  **Explanation:** Placing the carpet from tile 4 to tile 7 covers 4 white tiles, which is the maximum number that can be covered.

{{< dots >}}
## Approach 🚀
This problem can be solved using a sliding window approach after sorting the tiles based on their left endpoints. By keeping track of the covered white tiles as the carpet slides over the tile ranges, we can find the maximum number of tiles that the carpet can cover.

### Initial Thoughts 💭
- The problem is about finding the optimal placement of the carpet, which requires considering each possible starting point and adjusting the number of covered tiles dynamically.
- By using a sliding window technique, we can efficiently determine the maximum coverage without needing to check each position individually.
{{< dots >}}
### Edge Cases 🌐
- This problem guarantees that the input array will contain at least one tile, so no need to handle empty input.
- Ensure that the solution works within the constraints for large inputs (up to 50,000 tiles).
- Tiles where the carpet length exactly matches the size of a tile or the sum of several tiles.
- The carpet's length should be carefully managed to ensure no overflow or inefficient calculations.
{{< dots >}}
## Code 💻
```cpp
int maximumWhiteTiles(vector<vector<int>>& t, int len) {
    
    int n = t.size(), res = 0,
        cover = 0, j = 0, partial = 0;

    sort(t.begin(), t.end());
    
    for(int i = 0; i < n && res < len ; ) {
        if(t[j][0] + len > t[i][1]) {
            cover += t[i][1] - t[i][0] + 1;
            res = max(res, cover);               
            i++;
        } else {
            partial = max(0, t[j][0] + len - t[i][0]);
            res = max(res, cover + partial);
            cover -= (t[j][1] - t[j][0] + 1);
            j++;
        }            
    }
    
    return res;        
}
```

This function calculates the maximum number of white tiles that can be covered given a list of intervals and a target length. It uses a greedy approach with two pointers to find the optimal covering solution.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maximumWhiteTiles(vector<vector<int>>& t, int len) {
	```
	This is the function header for `maximumWhiteTiles`, which takes a 2D vector `t` representing intervals and an integer `len` representing the target length, and returns the maximum number of white tiles covered.

2. **Variable Initialization**
	```cpp
	    int n = t.size(), res = 0,
	```
	Initializes `n` to store the size of the input intervals `t`, and initializes `res` to store the result (maximum number of white tiles covered).

3. **Variable Initialization**
	```cpp
	        cover = 0, j = 0, partial = 0;
	```
	Initializes `cover` to keep track of the current covered area, `j` as the pointer for the second interval, and `partial` to store partial coverage for the current interval.

4. **Sort Operation**
	```cpp
	    sort(t.begin(), t.end());
	```
	Sorts the intervals in ascending order based on the starting position to facilitate the greedy approach of checking coverage.

5. **Loop Start for Coverage Calculation**
	```cpp
	    for(int i = 0; i < n && res < len ; ) {
	```
	Starts a loop where we iterate through the intervals, ensuring the total coverage does not exceed the target `len`.

6. **Condition Check for Full Interval Coverage**
	```cpp
	        if(t[j][0] + len > t[i][1]) {
	```
	Checks if the current interval's end exceeds the target length `len` by comparing `t[j][0] + len` to `t[i][1]`. If true, it means the interval is fully covered.

7. **Cover Update**
	```cpp
	            cover += t[i][1] - t[i][0] + 1;
	```
	Updates `cover` by adding the length of the current interval, from `t[i][0]` to `t[i][1]`.

8. **Max Result Update**
	```cpp
	            res = max(res, cover);               
	```
	Updates the result `res` to be the maximum of the current `res` and `cover`, which tracks the maximum number of tiles covered.

9. **Interval Pointer Increment**
	```cpp
	            i++;
	```
	Increments the interval pointer `i` to move to the next interval.

10. **Else Block for Partial Coverage**
	```cpp
	        } else {
	```
	If the current interval is not fully covered, we calculate the partial coverage.

11. **Partial Coverage Calculation**
	```cpp
	            partial = max(0, t[j][0] + len - t[i][0]);
	```
	Calculates the partial coverage for the current interval, ensuring that the coverage does not go below zero.

12. **Max Result Update**
	```cpp
	            res = max(res, cover + partial);
	```
	Updates the result `res` with the maximum of the current `res` and the sum of `cover` and `partial` coverage.

13. **Cover Update**
	```cpp
	            cover -= (t[j][1] - t[j][0] + 1);
	```
	Decreases `cover` by the length of the interval that is no longer part of the current coverage.

14. **Interval Pointer Increment**
	```cpp
	            j++;
	```
	Increments the second interval pointer `j` to move to the next interval.

15. **Return Statement**
	```cpp
	    return res;        
	```
	Returns the result `res`, which is the maximum number of white tiles covered.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n) where `n` is the number of tiles.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage needed for the tiles array and any additional variables used for tracking the carpet placement.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/)

---
{{< youtube U7fqZr_ZLd4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
