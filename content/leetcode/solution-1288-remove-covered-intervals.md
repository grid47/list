
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---


### Problem Statement
The problem involves determining how many intervals from a given list are not covered by other intervals. An interval `[a, b]` is said to cover another interval `[c, d]` if `a <= c` and `b >= d`. The goal is to return the number of intervals that are not covered by any other interval in the list.

For example, given the input intervals `[[1,4],[3,6],[2,8]]`, the interval `[1,4]` is covered by `[2,8]`, and `[3,6]` is also covered by `[2,8]`. Therefore, the result would be `1`, as only the interval `[2,8]` remains.

### Approach
To solve this problem, we can follow these steps:
1. **Sort the Intervals**: First, we need to sort the list of intervals based on their starting point. If two intervals have the same starting point, the longer interval should come first. This sorting helps us easily compare the intervals to see if one is covered by another.
2. **Iterate and Count**: Initialize variables to track the count of non-covered intervals and the current boundaries of the last added interval. As we iterate through the sorted intervals, we compare each interval with the last added interval's boundaries. If the current interval starts after the last added interval ends, we increment the count.
3. **Return Result**: Finally, return the count of non-covered intervals.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& ivl) {
        sort(ivl.begin(), ivl.end());
```
- **Lines 1-3**: The `Solution` class is defined, and the method `removeCoveredIntervals` begins. The input parameter `ivl` is a vector of vectors, where each inner vector represents an interval. The intervals are sorted in ascending order based on their start times.

```cpp
        int res = 0, left = -1, right = -1;
```
- **Line 4**: We initialize `res` to keep track of the number of non-covered intervals, and `left` and `right` to manage the boundaries of the last added interval.

```cpp
        for(auto p: ivl) {
```
- **Line 5**: A for loop iterates over each interval `p` in the sorted list of intervals.

```cpp
            if(left < p[0] && right < p[1]) {
                res++;
                left = p[0];
            }
```
- **Lines 6-9**: We check if the current interval `p` starts after the last added interval (`left < p[0]`) and if the last interval's end is less than the current interval's end (`right < p[1]`):
  - If both conditions are true, it indicates that the current interval is not covered by the last added interval. We increment `res`, indicating a new non-covered interval and update `left` to the current interval's start.

```cpp
            right = max(p[1], right);
        }
```
- **Lines 10-12**: Regardless of whether the current interval is covered or not, we update the `right` boundary to be the maximum end value between the current interval and the last recorded `right`.

```cpp
        return res;
    }
};
```
- **Lines 13-15**: Finally, we return the count of non-covered intervals.

### Complexity Analysis
1. **Time Complexity**:
   - The time complexity of this algorithm is \(O(n \log n)\), where \(n\) is the number of intervals. This complexity arises primarily from the sorting step. The subsequent iteration through the intervals takes linear time, \(O(n)\).

2. **Space Complexity**:
   - The space complexity is \(O(1)\) if we do not consider the space used by the input itself. We only use a constant amount of additional space to store the counters and bounds.

### Conclusion
The `removeCoveredIntervals` function effectively identifies the number of non-covered intervals from a given list. By sorting the intervals and employing a straightforward linear pass to count valid intervals, the algorithm maintains an optimal time complexity of \(O(n \log n)\).

This solution showcases how sorting combined with a single-pass check can simplify problems involving intervals, making it a powerful approach in algorithmic design. The clarity of the logic and the efficiency of the implementation make it suitable for competitive programming and interview settings, where understanding and optimizing for time and space complexity is crucial.

By breaking down the problem and its solution comprehensively, this explanation serves as a useful resource for learners and developers interested in mastering interval-related problems in algorithmic contexts.

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-covered-intervals/description/)

---
{{< youtube nhAsMabiVkM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
