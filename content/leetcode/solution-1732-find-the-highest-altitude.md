
+++
authors = ["grid47"]
title = "Leetcode 1732: Find the Highest Altitude"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1732: Find the Highest Altitude in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rizlq7r8_Zg"
youtube_upload_date="2021-01-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rizlq7r8_Zg/maxresdefault.webp"
comments = true
+++



---
A biker is going on a road trip, where the trip consists of several points with different altitudes. The biker starts at point 0, which has an altitude of 0. You are given an array of integers `gain`, where each value represents the change in altitude between two consecutive points. Your task is to find the highest altitude the biker reaches during the trip.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array `gain` of length `n` (1 ≤ n ≤ 100), where each element of the array represents the change in altitude between two consecutive points. The biker starts at altitude 0.
- **Example:** `Input: gain = [-3, 2, 1, -4, 3]`
- **Constraints:**
	- n == gain.length
	- 1 <= n <= 100
	- -100 <= gain[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the highest altitude the biker reaches during the trip, including the starting point.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be a single integer representing the highest altitude reached.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the highest point the biker reaches on the trip by computing the cumulative altitude after applying each gain value sequentially.

- 1. Initialize the current altitude as 0.
- 2. Iterate through the `gain` array, updating the current altitude after each step.
- 3. Keep track of the maximum altitude reached during the journey.
- 4. Return the maximum altitude.
{{< dots >}}
### Problem Assumptions ✅
- The biker starts at altitude 0.
- The altitude changes are applied sequentially as per the gain array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: gain = [-3, 2, 1, -4, 3]`  \
  **Explanation:** Starting at altitude 0, the biker reaches altitudes [-3, -1, 0, -4, 3]. The highest altitude reached is 3.

- **Input:** `Input: gain = [2, -1, 3, -2, 0]`  \
  **Explanation:** Starting at altitude 0, the biker reaches altitudes [2, 1, 4, 2, 2]. The highest altitude reached is 4.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to simulate the biker's journey, calculating the cumulative altitude at each step while tracking the highest altitude encountered.

### Initial Thoughts 💭
- We can solve this problem in one pass through the `gain` array, keeping track of the current altitude and updating the maximum altitude reached.
- The solution requires O(n) time complexity since we are iterating through the array once.
{{< dots >}}
### Edge Cases 🌐
- An empty input array should not be possible due to the problem's constraints (n ≥ 1).
- The algorithm must be efficient enough to handle arrays with up to 100 elements.
- The gain array could have only negative values, in which case the highest altitude will still be 0.
- The solution should handle both positive and negative values in the gain array correctly.
{{< dots >}}
## Code 💻
```cpp
int largestAltitude(vector<int>& gain) {
    int mx = 0;
    int cur = 0;
    for(int x: gain) {
        cur += x;
        mx = max(mx, cur);
    }
    return mx;
}
```

This function computes the largest altitude based on a list of altitude gains, where each element in the input array represents a change in altitude. It tracks the current altitude and updates the maximum altitude encountered.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int largestAltitude(vector<int>& gain) {
	```
	The function `largestAltitude` is defined, taking a vector of integers `gain`, where each element represents the altitude change, as input.

2. **Initialization**
	```cpp
	    int mx = 0;
	```
	The variable `mx` is initialized to 0. It will store the maximum altitude encountered during the traversal of the `gain` array.

3. **Initialization**
	```cpp
	    int cur = 0;
	```
	The variable `cur` is initialized to 0. It will track the current altitude as we iterate through the `gain` array.

4. **Loop - Gain Iteration**
	```cpp
	    for(int x: gain) {
	```
	A for-loop is used to iterate over each element `x` in the `gain` vector. Each `x` represents the change in altitude.

5. **Update Current Altitude**
	```cpp
	        cur += x;
	```
	The current altitude `cur` is updated by adding the altitude change `x`.

6. **Update Maximum Altitude**
	```cpp
	        mx = max(mx, cur);
	```
	The maximum altitude `mx` is updated to be the larger of the current maximum and the current altitude `cur`.

7. **Return Result**
	```cpp
	    return mx;
	```
	The function returns `mx`, which contains the largest altitude encountered during the traversal of the `gain` array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), since the algorithm must iterate through the entire `gain` array once.
- **Average Case:** O(n), as there is no variation in time complexity based on input values.
- **Worst Case:** O(n), as we process each element in the array sequentially.

The time complexity is linear in terms of the length of the `gain` array.

### Space Complexity 💾
- **Best Case:** O(1), since no additional space is required beyond the variables for tracking the current and maximum altitude.
- **Worst Case:** O(1), as we are only storing a few integer variables.

The space complexity is constant because the solution uses only a fixed amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-highest-altitude/description/)

---
{{< youtube rizlq7r8_Zg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
