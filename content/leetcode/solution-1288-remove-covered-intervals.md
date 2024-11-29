
+++
authors = ["grid47"]
title = "Leetcode 1288: Remove Covered Intervals"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1288: Remove Covered Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "nhAsMabiVkM"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi/nhAsMabiVkM/maxresdefault.jpg"
comments = true
+++



---
Given an array of intervals, remove all intervals that are covered by another interval and return the number of remaining intervals.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of intervals where each interval is represented as [li, ri].
- **Example:** `Input: [[1,5], [2,6], [3,7], [4,8]]`
- **Constraints:**
	- 1 <= intervals.length <= 1000
	- intervals[i].length == 2
	- 0 <= li < ri <= 10^5
	- All the given intervals are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The function should return the number of remaining intervals after removing all covered intervals.
- **Example:** `Output: 2`
- **Constraints:**
	- The input intervals are unique.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove intervals that are covered by other intervals and return the count of the remaining intervals.

- Sort the intervals based on their starting value.
- Iterate through the sorted intervals and keep track of the rightmost end of the previous interval.
- For each new interval, if its end is less than or equal to the rightmost end, it is covered by the previous interval and can be discarded.
- Otherwise, update the rightmost end and increment the count of remaining intervals.
{{< dots >}}
### Problem Assumptions ✅
- Intervals are unique and no two intervals are identical.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [[1,5], [2,6], [3,7], [4,8]]`  \
  **Explanation:** Intervals `[2,6]`, `[3,7]`, and `[4,8]` are covered by `[1,5]`. The remaining intervals are `[1,5]` and `[4,8]`.

{{< dots >}}
## Approach 🚀
To solve this problem, we will sort the intervals based on their start value and then remove the intervals that are covered by others.

### Initial Thoughts 💭
- Sorting the intervals first helps us easily compare each interval to the previous one to check for coverage.
- We need to iterate through the intervals and keep track of the rightmost end seen so far to determine if the current interval is covered.
{{< dots >}}
### Edge Cases 🌐
- An empty array will never occur since the length of the intervals is guaranteed to be at least 1.
- The solution should handle arrays with up to 1000 intervals efficiently.
- If all intervals are distinct and no interval is covered, the output will be the total number of intervals.
- Since all intervals are unique, there will be no duplicate intervals to handle.
{{< dots >}}
## Code 💻
```cpp
int removeCoveredIntervals(vector<vector<int>>& ivl) {
    sort(ivl.begin(), ivl.end());
    int res = 0, left = -1, right = -1;
    
    for(auto p: ivl) {
        if(left < p[0] && right < p[1]) {
            res++;
            left = p[0];
        }
        right = max(p[1], right);
    }
    
    return res;
}
```

This function calculates the number of non-covered intervals in a sorted list of intervals by iterating through them and keeping track of boundaries.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int removeCoveredIntervals(vector<vector<int>>& ivl) {
	```
	Defines the function to compute the count of intervals that are not covered by others.

2. **Sorting**
	```cpp
	    sort(ivl.begin(), ivl.end());
	```
	Sorts the intervals by their starting point and, in case of ties, by their ending point.

3. **Variable Initialization**
	```cpp
	    int res = 0, left = -1, right = -1;
	```
	Initializes variables to keep track of the count of non-covered intervals and boundaries.

4. **Loop Start**
	```cpp
	    for(auto p: ivl) {
	```
	Iterates through each interval in the sorted list.

5. **Condition Check**
	```cpp
	        if(left < p[0] && right < p[1]) {
	```
	Checks if the current interval is not covered by the previous interval.

6. **Increment Counter**
	```cpp
	            res++;
	```
	Increments the counter for non-covered intervals.

7. **Update Left Boundary**
	```cpp
	            left = p[0];
	```
	Updates the left boundary to the starting point of the current interval.

8. **Update Right Boundary**
	```cpp
	        right = max(p[1], right);
	```
	Updates the right boundary to the maximum of the current interval's end or the previous boundary.

9. **Return Result**
	```cpp
	    return res;
	```
	Returns the count of non-covered intervals.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) - Sorting the intervals takes O(n log n), where n is the number of intervals.
- **Average Case:** O(n log n) - The sorting step dominates the time complexity.
- **Worst Case:** O(n log n) - In the worst case, we need to sort the intervals and iterate through them once.

The time complexity is O(n log n) because of the sorting step.

### Space Complexity 💾
- **Best Case:** O(n) - In the best case, we still need space for the sorted intervals.
- **Worst Case:** O(n) - The space complexity is O(n) in the worst case if we store the sorted intervals.

The space complexity is O(n) to store the sorted intervals.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-covered-intervals/description/)

---
{{< youtube nhAsMabiVkM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
