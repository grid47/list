
+++
authors = ["grid47"]
title = "Leetcode 2498: Frog Jump II"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2498: Frog Jump II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7zFq991SKgQ"
youtube_upload_date="2022-12-10"
youtube_thumbnail="https://i.ytimg.com/vi/7zFq991SKgQ/maxresdefault.jpg"
comments = true
+++



---
A frog starts on the first stone in a river and wants to jump to the last stone and then return to the first stone. The frog can jump to any stone at most once. The cost of a jump is defined as the absolute difference between the positions of two stones. The frog must choose a path that minimizes the maximum jump length during the entire journey. Return the minimum cost of the path where the cost is defined as the maximum length of any jump.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array stones where each element represents the position of a stone, sorted in strictly increasing order. The frog will start at the first stone and needs to travel to the last stone and back.
- **Example:** `Input: stones = [0, 2, 5, 7, 10]`
- **Constraints:**
	- 2 <= stones.length <= 10^5
	- 0 <= stones[i] <= 10^9
	- stones[0] == 0
	- stones is sorted in strictly increasing order

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible cost of the path where the cost is the maximum length of any jump the frog makes.
- **Example:** `Output: 5`
- **Constraints:**
	- The minimum cost is determined by the path with the smallest maximum jump length.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum cost of a path where the maximum jump length is minimized during the frog's journey.

- 1. Iterate through the stones array and calculate the maximum jump length if the frog were to travel from the first stone to the last and back.
- 2. For each possible jump, calculate the jump length and track the largest jump.
- 3. The solution is the smallest maximum jump length among all possible paths.
{{< dots >}}
### Problem Assumptions ✅
- The frog always starts at the first stone (position 0) and ends at the last stone, completing the round trip.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: stones = [0, 2, 5, 7, 10]`  \
  **Explanation:** The frog starts at position 0 and needs to jump to 2, then to 5, 7, and finally 10. The maximum jump length is from 5 to 10, which is 5. Hence, the minimum cost is 5.

- **Input:** `Input: stones = [0, 3, 9]`  \
  **Explanation:** The frog starts at 0, jumps to 9, and returns to 0. The maximum jump length is 9. Hence, the minimum cost is 9.

{{< dots >}}
## Approach 🚀
We can solve this problem by considering the maximum difference between every second stone (representing the farthest distance the frog might jump at a time), which ensures that the maximum jump length is minimized.

### Initial Thoughts 💭
- The frog's journey consists of multiple jumps, and the goal is to minimize the maximum jump distance.
- The optimal approach would involve looking at the maximum differences between stones as the frog hops between them.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least two stones, so this case is not applicable.
- Ensure the solution is efficient for large inputs, where the number of stones is near the upper constraint of 100,000.
- Handle the case where the frog needs to make large jumps between stones located far apart.
- The solution should be optimal and run efficiently within time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
int maxJump(vector<int>& A) {
    int res = A[1] - A[0];
    int n = A.size();
    for(int i = 2; i < n; i++)
        res = max(res, A[i] - A[i - 2]);
    return res;
}
```

This code defines a function `maxJump` that calculates the maximum jump in an array `A`, where the jump is the difference between two elements, with the constraint that each jump must skip one element in between.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxJump(vector<int>& A) {
	```
	Defines the function `maxJump` that takes a vector of integers `A` and returns an integer representing the maximum jump between elements with one element skipped in between.

2. **Mathematical Operations**
	```cpp
	    int res = A[1] - A[0];
	```
	Initializes `res` with the difference between the second and first elements of the array, as the first possible jump.

3. **Array Operations**
	```cpp
	    int n = A.size();
	```
	Gets the size of the array `A` and stores it in the variable `n`, which is used to control the loop iteration.

4. **Looping**
	```cpp
	    for(int i = 2; i < n; i++)
	```
	Starts a loop from the third element (index 2) of the array and iterates through the rest of the array to compute the jump differences.

5. **Mathematical Operations**
	```cpp
	        res = max(res, A[i] - A[i - 2]);
	```
	In each iteration, the difference between the current element `A[i]` and the element two positions earlier `A[i-2]` is calculated. The maximum of this difference and the previous `res` is stored back in `res`.

6. **Return Statement**
	```cpp
	    return res;
	```
	Returns the maximum jump found after iterating through the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear (O(n)) since we only need to iterate through the stones list once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant (O(1)) since we only need a few extra variables to track the maximum jump.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/frog-jump-ii/description/)

---
{{< youtube 7zFq991SKgQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
