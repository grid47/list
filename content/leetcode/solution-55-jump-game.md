
+++
authors = ["grid47"]
title = "Leetcode 55: Jump Game"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 55: Jump Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/55.webp"
youtube = "Yan0cv2cLy8"
youtube_upload_date="2021-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/Yan0cv2cLy8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/55.webp" 
    alt="A glowing, serene path with various stepping stones, symbolizing overcoming obstacles."
    caption="Solution to LeetCode 55: Jump Game Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array nums. Starting from the first index, each element represents the maximum jump length you can make from that position. Return true if you can reach the last index, or false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of integers, where each number represents the maximum number of steps you can jump from that index.
- **Example:** `["nums = [2, 3, 1, 1, 4]"]`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- 0 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value: true if it's possible to reach the last index, false otherwise.
- **Example:** `["true"]`
- **Constraints:**
	- The function must determine whether reaching the last index is possible.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if we can jump from the first index to the last index by considering the maximum jump lengths at each index.

- 1. Initialize a variable mx to keep track of the farthest index that can be reached.
- 2. Traverse the array, updating mx with the maximum index reachable from each position.
- 3. If at any index, mx is less than the current index, return false (we can't jump further).
- 4. If mx reaches or exceeds the last index, return true.
{{< dots >}}
### Problem Assumptions ✅
- You can always start from the first index, and there's no need to account for negative or invalid values in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `["nums = [2, 3, 1, 1, 4]"]`  \
  **Explanation:** By jumping from index 0 to index 1, and then from index 1 to the last index, you can reach the end of the array.

- **Input:** `["nums = [3, 2, 1, 0, 4]"]`  \
  **Explanation:** You will reach index 3, which has a jump length of 0, preventing further movement, so it's not possible to reach the last index.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the array while keeping track of the farthest index that can be reached. If at any point the farthest index is behind the current index, return false.

### Initial Thoughts 💭
- We need to track the farthest position that can be reached as we iterate through the array.
- A greedy approach is well-suited for this problem, where we update the maximum reachable index as we go.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the array has at least one element.
- The solution must efficiently handle arrays with lengths up to 10^4.
- If there are zeros in the array, they may prevent further jumps if encountered early.
- The solution must ensure that the algorithm runs in linear time, i.e., O(n).
{{< dots >}}
## Code 💻
```cpp
bool canJump(vector<int>& nums) {
    int mx = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(mx < i) return false;
        mx = max(mx, i + nums[i]);
        if(mx >= nums.size() - 1) return true;
    }
    return false;
}
```

This code determines if it's possible to reach the last index of a given array by jumping from one index to another, where the value at each index represents the maximum jump distance from that index.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool canJump(vector<int>& nums) {
	```
	This line declares a function named `canJump` that takes a vector of integers `nums` as input and returns a boolean value indicating whether it's possible to reach the last index.

2. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	This line initializes an integer variable `mx` to 0. This variable will keep track of the farthest reachable index from the current position.

3. **Array Size Calculation**
	```cpp
	    int n = nums.size();
	```
	This line calculates the size of the input array `nums` and stores it in the `n` variable.

4. **Iterate Over Array**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates over each index `i` of the `nums` array.

5. **Check Reachability**
	```cpp
	        if(mx < i) return false;
	```
	This condition checks if the current index `i` is beyond the farthest reachable index `mx`. If so, it's impossible to reach the end, so the function returns `false`.

6. **Update Maximum Reachable Index**
	```cpp
	        mx = max(mx, i + nums[i]);
	```
	This line updates the `mx` variable to the maximum of its current value and the farthest reachable index from the current position `i + nums[i]`. This effectively calculates the maximum possible jump distance from the current position.

7. **Check for Early Success**
	```cpp
	        if(mx >= nums.size() - 1) return true;
	```
	This condition checks if the current maximum reachable index `mx` is greater than or equal to the last index of the array. If so, it means we can reach the end, so the function returns `true`.

8. **Return False**
	```cpp
	    return false;
	```
	If the loop completes without finding a path to the end, the function returns `false`, indicating that it's not possible to reach the last index.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of elements in the array, since we only make a single pass over the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a constant amount of extra space for tracking the maximum reachable index.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/jump-game/description/)

---
{{< youtube Yan0cv2cLy8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
