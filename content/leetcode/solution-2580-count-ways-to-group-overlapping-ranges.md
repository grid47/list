
+++
authors = ["grid47"]
title = "Leetcode 2580: Count Ways to Group Overlapping Ranges"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2580: Count Ways to Group Overlapping Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "5-8-2mDdoGs"
youtube_upload_date="2023-03-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/5-8-2mDdoGs/maxresdefault.webp"
comments = true
+++



---
There are `n` people standing in a line labeled from 1 to `n`. The first person starts with a pillow. Every second, the person holding the pillow passes it to the next person in line. Once the pillow reaches the last person in the line, it starts moving back in the opposite direction, passing towards the first person. Given `n` and `time`, return the index of the person holding the pillow after `time` seconds.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, `n` (number of people in the line) and `time` (the time in seconds after which we want to determine who holds the pillow).
- **Example:** `For example, `n = 4`, `time = 5`.`
- **Constraints:**
	- 2 <= n <= 1000
	- 1 <= time <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the index of the person holding the pillow after `time` seconds.
- **Example:** `For input `n = 4, time = 5`, the output is `2`.`
- **Constraints:**
	- The result will always be a valid person index in the range from 1 to `n`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the index of the person holding the pillow after `time` seconds, considering the back-and-forth passing mechanism.

- 1. Determine the cycle length: the pillow will move back and forth through all the people, so the cycle is `2 * (n - 1)` seconds.
- 2. If the time is less than the cycle length, determine if it's in the forward or backward direction.
- 3. Calculate the index of the person holding the pillow by simulating the movement through the cycle.
{{< dots >}}
### Problem Assumptions ✅
- The time will always be a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `For `n = 5, time = 7``  \
  **Explanation:** The pillow passes from person 1 to person 5, then back to person 4, and stops at person 4 after 7 seconds.

{{< dots >}}
## Approach 🚀
The approach is to determine the cycle of pillow passing, and based on the time value, compute the position of the pillow. We use a modulo operation to determine the effective time within the cycle.

### Initial Thoughts 💭
- The pillow follows a repeating back-and-forth pattern.
- Since the cycle is fixed, we can reduce the time into a manageable range using modulo operation.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs are expected; `n` and `time` will always be positive.
- The solution should handle large values for `n` and `time` efficiently.
- If `n` is the smallest value (2), the solution should handle it correctly.
- Ensure that `n` and `time` are within the constraints and that the result is correctly calculated.
{{< dots >}}
## Code 💻
```cpp
int countWays(vector<vector<int>>& range) {
    sort(range.begin(), range.end());
    int n = range.size();
    
    int mod = (int) 1e9 + 7;        
    int next = range[0][1];
    long cnt = 2;
    for(int i = 0; i < n; i++) {
        if(range[i][0] <= next) {
            next = max(next, range[i][1]);
            continue;
        }
        cnt = (cnt * 2) % mod;
        next = range[i][1];
    }

    return cnt;
}
```

This is the full implementation of the function `countWays`, which calculates the number of possible ways to arrange intervals based on the given ranges.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countWays(vector<vector<int>>& range) {
	```
	Define the function `countWays`, which takes a vector of integer vectors `range` as input.

2. **Sorting**
	```cpp
	    sort(range.begin(), range.end());
	```
	Sort the `range` vector in ascending order based on the first element of each sub-vector.

3. **Size Initialization**
	```cpp
	    int n = range.size();
	```
	Store the size of the `range` vector in the variable `n`.

4. **Modulo Constant**
	```cpp
	    int mod = (int) 1e9 + 7;        
	```
	Define a constant `mod` with the value `1e9 + 7`, used for modular arithmetic to prevent overflow.

5. **Initialization**
	```cpp
	    int next = range[0][1];
	```
	Initialize the `next` variable with the second value of the first range, representing the end of the current interval.

6. **Initialization**
	```cpp
	    long cnt = 2;
	```
	Initialize `cnt` to 2, representing the initial number of ways to arrange intervals.

7. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to iterate over each interval in the `range` vector.

8. **Condition Check**
	```cpp
	        if(range[i][0] <= next) {
	```
	Check if the start of the current interval is less than or equal to `next`, indicating overlap or continuity.

9. **Interval Update**
	```cpp
	            next = max(next, range[i][1]);
	```
	Update the `next` value to the maximum of the current `next` and the end of the current interval.

10. **Continue**
	```cpp
	            continue;
	```
	If the current interval overlaps with the previous one, continue to the next iteration.

11. **Counting**
	```cpp
	        cnt = (cnt * 2) % mod;
	```
	If no overlap, multiply the current number of ways `cnt` by 2 and take modulo `mod` to avoid overflow.

12. **Interval Update**
	```cpp
	        next = range[i][1];
	```
	Update `next` to the end of the current interval.

13. **Return**
	```cpp
	    return cnt;
	```
	Return the final result, which is the number of ways to arrange intervals.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The solution operates in constant time as it only requires modulo and basic arithmetic operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only use a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/)

---
{{< youtube 5-8-2mDdoGs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
