
+++
authors = ["grid47"]
title = "Leetcode 1503: Last Moment Before All Ants Fall Out of a Plank"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1503: Last Moment Before All Ants Fall Out of a Plank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Brainteaser","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tl0akFR9IXQ"
youtube_upload_date="2020-07-05"
youtube_thumbnail="https://i.ytimg.com/vi/tl0akFR9IXQ/maxresdefault.jpg"
comments = true
+++



---
You are given a wooden plank of length n, and some ants are walking on the plank. Some ants move to the left, others to the right. When two ants meet, they change directions without any additional time loss. When an ant reaches the edge of the plank, it falls off. The task is to determine when the last ant will fall off the plank.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integer arrays: 'left' and 'right'. The array 'left' represents the positions of ants moving to the left, and the array 'right' represents the positions of ants moving to the right.
- **Example:** `n = 5, left = [3, 4], right = [1, 2]`
- **Constraints:**
	- 1 <= n <= 10^4
	- 0 <= left.length <= n + 1
	- 0 <= right.length <= n + 1
	- 1 <= left.length + right.length <= n + 1
	- All values in 'left' and 'right' are unique, and no position is repeated in both arrays.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the time when the last ant falls off the plank.
- **Example:** `6`
- **Constraints:**
	- The time is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the moment when the last ant falls off the plank.

- For each ant moving to the right, calculate how much time it takes to fall off the right end of the plank.
- For each ant moving to the left, calculate how much time it takes to fall off the left end of the plank.
- The time when the last ant falls off is the maximum of all these times.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays 'left' and 'right' contain unique values.
- The time for ants to change directions when they meet is negligible.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 5, left = [3, 4], right = [1, 2]`  \
  **Explanation:** The last ant to fall off is the one at position 4, which will take 5 seconds to reach the left end.

- **Input:** `n = 6, left = [], right = [0, 1, 2, 3, 4, 5]`  \
  **Explanation:** The ant at position 0 will take 6 seconds to fall off the plank, and all other ants fall off before it.

{{< dots >}}
## Approach 🚀
To solve the problem, calculate the time for each ant to fall off the plank. The solution is simply the maximum time of all ants.

### Initial Thoughts 💭
- The ants' movements are independent, so we just need to compute how long it will take for each ant to fall off the plank.
- The time for ants moving to the left is just their position, while the time for ants moving to the right is the plank's length minus their position.
{{< dots >}}
### Edge Cases 🌐
- If either 'left' or 'right' is empty, we only consider the times for the non-empty array.
- Ensure that the solution handles the maximum value of n, which is 10^4.
- If all ants are moving in one direction, the time will be the time it takes the farthest ant to fall off.
- The input arrays 'left' and 'right' should respect the given constraints.
{{< dots >}}
## Code 💻
```cpp
int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    
    int mx = 0;
    for(int i = 0; i < right.size(); i++)
        mx = max(mx, n - right[i]);
    
    for(int i = 0; i < left.size(); i++)
        mx = max(mx, left[i]);        
    
    return mx;
}
```

This function calculates the last moment in time when any of the elements in the `left` and `right` arrays reach their boundaries. It determines the maximum distance either from the right boundary or the left boundary.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
	```
	Defines the function that calculates the last moment any object in the `left` or `right` array reaches the boundary of size `n`.

2. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	Initializes a variable `mx` to store the maximum moment of time as the loop progresses.

3. **Loop**
	```cpp
	    for(int i = 0; i < right.size(); i++)
	```
	Loops through each element in the `right` array.

4. **Mathematical Operations**
	```cpp
	        mx = max(mx, n - right[i]);
	```
	For each element in the `right` array, calculates the moment when it reaches the right boundary. The time is updated in the `mx` variable.

5. **Loop**
	```cpp
	    for(int i = 0; i < left.size(); i++)
	```
	Loops through each element in the `left` array.

6. **Mathematical Operations**
	```cpp
	        mx = max(mx, left[i]);        
	```
	For each element in the `left` array, it calculates the moment when it reaches the left boundary. The time is updated in the `mx` variable.

7. **Return**
	```cpp
	    return mx;
	```
	Returns the maximum time calculated from both the left and right arrays.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), as we iterate through both the 'left' and 'right' arrays once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a few variables to store the maximum time.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/)

---
{{< youtube tl0akFR9IXQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
