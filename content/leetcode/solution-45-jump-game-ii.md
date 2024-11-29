
+++
authors = ["grid47"]
title = "Leetcode 45: Jump Game II"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 45: Jump Game II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/45.webp"
youtube = "CsDI-yQuGeM"
youtube_upload_date="2024-08-08"
youtube_thumbnail="https://i.ytimg.com/vi/CsDI-yQuGeM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/45.webp" 
    alt="A glowing path with multiple jumping stones, forming an easy, calming journey."
    caption="Solution to LeetCode 45: Jump Game II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a 0-indexed array 'nums' where each element represents the maximum length you can jump forward from that index. You are initially positioned at nums[0], and you need to reach the last index. Return the minimum number of jumps needed to reach the last index.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 0-indexed array of integers 'nums'. Each integer represents the maximum jump length from that index.
- **Example:** `Input: nums = [3, 4, 1, 1, 5]`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- 0 <= nums[i] <= 1000
	- It's guaranteed that you can reach nums[n-1].

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of jumps needed to reach the last index of the array.
- **Example:** `Output: 2`
- **Constraints:**
	- The output should be an integer representing the minimum number of jumps.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of jumps needed to reach the last index.

- Initialize two variables: 'cur' (current index) and 'far' (farthest reachable index) to track your position and the furthest you can jump.
- Iterate over the array, and for each index, update the 'far' index to reflect the maximum distance you can reach from that point.
- When you reach 'cur' (the point where a jump is necessary), update 'cur' to 'far' and increment the jump count.
- Repeat this process until you reach the last index.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always allow a valid path to reach the last index.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 4, 1, 1, 5]`  \
  **Explanation:** Start at index 0, jump 3 steps to index 1, then jump 4 steps to reach the last index. This takes 2 jumps.

- **Input:** `Input: nums = [2, 3, 1, 1, 4]`  \
  **Explanation:** Jump 1 step to index 1, then jump 3 steps to reach the last index, making it a total of 2 jumps.

- **Input:** `Input: nums = [1, 2, 3, 4, 5]`  \
  **Explanation:** Jump 1 step to index 1, 2 steps to index 3, and 1 step to the last index, resulting in 3 jumps.

{{< dots >}}
## Approach 🚀
The problem can be approached using a greedy algorithm that minimizes the number of jumps by always jumping to the farthest possible index within each jump.

### Initial Thoughts 💭
- The key observation is that we need to jump to the farthest reachable index to minimize the number of jumps.
- We can use a greedy strategy: always try to reach the farthest point from the current position in each jump.
{{< dots >}}
### Edge Cases 🌐
- If nums has only one element, no jump is needed.
- Ensure that the solution works efficiently with large inputs, up to the constraint limit of 10^4 elements.
- Handle the case where nums contains large jump values at the beginning, which could quickly minimize the number of jumps.
- The algorithm must efficiently handle arrays with lengths up to 10^4.
{{< dots >}}
## Code 💻
```cpp
int jump(vector<int>& nums) {
    int jumps = 0;
    int cur = 0;
    int far = 0;
    for(int i = 0; i < nums.size() - 1; i++) {
        far = max(far, i + nums[i]);
        if(i == cur) {
            cur = far;
            jumps++;
        }
    }
    return jumps;
}
```

This code calculates the minimum number of jumps required to reach the end of an array of non-negative integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int jump(vector<int>& nums) {
	```
	This line declares a function named `jump` that takes a vector of non-negative integers `nums` as input and returns the minimum number of jumps required to reach the end of the array.

2. **Variable Initialization**
	```cpp
	    int jumps = 0;
	```
	This line initializes a variable `jumps` to 0 to keep track of the number of jumps made so far.

3. **Variable Initialization**
	```cpp
	    int cur = 0;
	```
	This line initializes a variable `cur` to 0 to represent the current position in the array.

4. **Variable Initialization**
	```cpp
	    int far = 0;
	```
	This line initializes a variable `far` to 0 to represent the farthest reachable position from the current position.

5. **Loop Iteration**
	```cpp
	    for(int i = 0; i < nums.size() - 1; i++) {
	```
	This line starts a `for` loop to iterate through the array, excluding the last element.

6. **Update Farthest Reachable Position**
	```cpp
	        far = max(far, i + nums[i]);
	```
	This line updates the `far` variable to the maximum of its current value and the farthest reachable position from the current index `i`.

7. **Condition Check**
	```cpp
	        if(i == cur) {
	```
	This line checks if the current index `i` has reached the current farthest position `cur`.

8. **Update Current Position and Jump Count**
	```cpp
	            cur = far;
	            jumps++;
	```
	If the condition is true, it means we've reached the end of a jump. We update the `cur` position to the new farthest reachable position `far` and increment the `jumps` count.

9. **Return Result**
	```cpp
	    return jumps;
	```
	This line returns the final value of `jumps`, which represents the minimum number of jumps required to reach the end of the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, the solution iterates over the array exactly once, giving it a linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as the solution only uses a few extra variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/jump-game-ii/description/)

---
{{< youtube CsDI-yQuGeM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
