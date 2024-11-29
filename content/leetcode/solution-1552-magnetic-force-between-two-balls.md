
+++
authors = ["grid47"]
title = "Leetcode 1552: Magnetic Force Between Two Balls"
date = "2024-06-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1552: Magnetic Force Between Two Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uixgQ1tejRs"
youtube_upload_date="2020-08-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uixgQ1tejRs/maxresdefault.webp"
comments = true
+++



---
You are given n baskets with distinct positions, and m balls to place in them. The magnetic force between two balls at positions x and y is |x - y|. The goal is to place the balls into baskets such that the minimum magnetic force between any two balls is maximized.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two parts: an array `position` representing the positions of baskets, and an integer `m` representing the number of balls.
- **Example:** `position = [1, 5, 10, 15], m = 2`
- **Constraints:**
	- 2 <= n <= 10^5
	- 1 <= position[i] <= 10^9
	- All integers in position are distinct.
	- 2 <= m <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum value of the minimum magnetic force between any two balls after placing them in baskets.
- **Example:** `Output: 10`
- **Constraints:**
	- The output is a single integer representing the maximum minimum magnetic force.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the minimum magnetic force by distributing the balls into baskets in a way that the force between any two balls is as large as possible.

- 1. Sort the positions array to facilitate easier comparison of distances.
- 2. Use binary search to find the largest possible minimum magnetic force.
- 3. For each mid value during binary search, check if it's possible to place the balls with that minimum force using a greedy approach.
{{< dots >}}
### Problem Assumptions ✅
- The positions array contains distinct values.
- The number of balls m is always less than or equal to n.
{{< dots >}}
## Examples 🧩
- **Input:** `position = [1, 2, 3, 4, 7], m = 3`  \
  **Explanation:** In this case, placing the 3 balls in positions 1, 4, and 7 gives a minimum magnetic force of 3 between the balls.

- **Input:** `position = [1, 5, 10, 15], m = 2`  \
  **Explanation:** By placing the two balls in positions 1 and 15, the magnetic force between them is 14, which is the maximum possible minimum force.

{{< dots >}}
## Approach 🚀
The problem can be solved by using binary search to maximize the minimum magnetic force between the balls while checking if it's possible to place the balls in such a configuration.

### Initial Thoughts 💭
- The positions array is unsorted, so the first step should be to sort the positions.
- We want to maximize the minimum magnetic force between any two balls.
- Binary search can be applied to the problem by testing different mid values of magnetic force and checking if it is possible to place all balls with at least that force between them.
{{< dots >}}
### Edge Cases 🌐
- The positions array is never empty, as it is guaranteed that 2 <= n.
- The solution must efficiently handle cases where n is as large as 10^5.
- When m equals 2, the task is simpler as we only need to place the two balls with the largest possible force between them.
- The positions array must be sorted before performing the binary search.
{{< dots >}}
## Code 💻
```cpp
int maxDistance(vector<int>& pos, int m) {
    sort(pos.begin(), pos.end());
    int n = pos.size();
    int l = 0;
    int r = pos[n - 1]-pos[0];
    while(l < r) {
        int mid = r - (r - l) / 2;
        if(isValid(pos, mid, m)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
bool isValid(vector<int> &nums, int mid, int cnt) {
    int res = 1, cur = nums[0];
    for(int i = 1; i < nums.size(); i ++) {
        if(nums[i] - cur >= mid) {
            res++;
            cur = nums[i];
        }
    }
    return res >= cnt;
}
```

This code defines two functions. The `maxDistance` function calculates the maximum possible distance between `m` items, ensuring that the distance between selected items is as large as possible. The `isValid` function checks if it's possible to select `cnt` items such that the minimum distance between them is at least `mid`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxDistance(vector<int>& pos, int m) {
	```
	This is the function definition for `maxDistance`, which takes a vector of integers `pos` and an integer `m` as input, and returns the maximum distance between the selected items.

2. **Sorting**
	```cpp
	    sort(pos.begin(), pos.end());
	```
	The positions in the `pos` array are sorted in ascending order to make it easier to calculate the distances between them.

3. **Variable Initialization**
	```cpp
	    int n = pos.size();
	```
	This line calculates the size of the `pos` array and stores it in variable `n`.

4. **Variable Initialization**
	```cpp
	    int l = 0;
	```
	Variable `l` is initialized to 0. It will be used as the lower bound for the binary search.

5. **Variable Initialization**
	```cpp
	    int r = pos[n - 1]-pos[0];
	```
	Variable `r` is initialized to the difference between the largest and smallest positions in the sorted array `pos`. This is the maximum possible distance.

6. **Binary Search Loop**
	```cpp
	    while(l < r) {
	```
	This while loop runs the binary search, iterating until the lower bound `l` is equal to or greater than the upper bound `r`.

7. **Binary Search Calculation**
	```cpp
	        int mid = r - (r - l) / 2;
	```
	The midpoint `mid` is calculated as the average of the current bounds `l` and `r`.

8. **Check Validity**
	```cpp
	        if(isValid(pos, mid, m)) {
	```
	The `isValid` function is called to check if it's possible to select `m` items with a minimum distance of `mid`.

9. **Update Lower Bound**
	```cpp
	            l = mid;
	```
	If the `isValid` function returns true, the lower bound `l` is updated to `mid`.

10. **Update Upper Bound**
	```cpp
	        } else {
	```
	If the `isValid` function returns false, the upper bound `r` is updated.

11. **Update Upper Bound**
	```cpp
	            r = mid - 1;
	```
	The upper bound `r` is updated to `mid - 1` because the current distance is too large to be valid.

12. **Return Statement**
	```cpp
	    return l;
	```
	The function returns the value of `l`, which is the maximum minimum distance found during the binary search.

13. **Helper Function Declaration**
	```cpp
	bool isValid(vector<int> &nums, int mid, int cnt) {
	```
	This is the helper function `isValid`, which checks if it's possible to select `cnt` items from the `nums` array such that the minimum distance between any two items is at least `mid`.

14. **Variable Initialization**
	```cpp
	    int res = 1, cur = nums[0];
	```
	Variable `res` is initialized to 1 (representing the first selected item), and `cur` is set to the first element in `nums`.

15. **Loop Iteration**
	```cpp
	    for(int i = 1; i < nums.size(); i ++) {
	```
	This loop iterates through the remaining elements in the `nums` array, starting from index 1.

16. **Condition Check**
	```cpp
	        if(nums[i] - cur >= mid) {
	```
	If the current element is sufficiently far from the last selected element (i.e., the distance is greater than or equal to `mid`), we select it.

17. **Increment Result**
	```cpp
	            res++;
	```
	The result `res` is incremented because we have selected a new item.

18. **Update Current Position**
	```cpp
	            cur = nums[i];
	```
	The variable `cur` is updated to the current element in `nums` to track the last selected item.

19. **Return Statement**
	```cpp
	    return res >= cnt;
	```
	The function returns `true` if the number of selected items is greater than or equal to `cnt`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n). Binary search adds a log factor.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the sorting step.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/magnetic-force-between-two-balls/description/)

---
{{< youtube uixgQ1tejRs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
