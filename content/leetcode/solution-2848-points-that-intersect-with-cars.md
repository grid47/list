
+++
authors = ["grid47"]
title = "Leetcode 2848: Points That Intersect With Cars"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2848: Points That Intersect With Cars in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "86n-e3Zwx34"
youtube_upload_date="2023-09-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/86n-e3Zwx34/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
    vector<int> v(102, 0);
    int ans = 0;
    for(auto n: nums){
        for(int i = n[0]; i <= n[1]; ++i) v[i-1]++;
    }
    for(auto e: v){
        if(e) ans++;
    }
    return ans;
}
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the number of unique points covered by a set of intervals. Each interval is given as a pair of integers `[start, end]` where each point between `start` and `end` is included in the interval. The task is to count how many distinct points are covered by at least one of the intervals.

### Approach

To solve this problem efficiently, we can use a simple technique involving an array that tracks whether a point is covered by an interval. For every interval, we can mark all the points that the interval covers. After processing all intervals, we can count how many unique points have been covered.

The key idea is to use a frequency array (`v`) where each index represents a point, and the value at that index indicates how many times that point is covered by intervals. Once we know which points are covered, we can simply count how many unique points are covered by at least one interval.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Frequency Array
```cpp
vector<int> v(102, 0);
```
- We initialize a vector `v` of size 102 with all elements set to 0. This array will track how many intervals cover each point.
- We use a size of 102 because the interval endpoints are between 1 and 100, and we need to accommodate for the fact that the index in `v` represents one less than the actual point (due to the 0-based indexing in the vector). The array is large enough to handle all points from 1 to 100.

#### Step 2: Process Each Interval
```cpp
for (auto n : nums) {
    for (int i = n[0]; i <= n[1]; ++i) v[i - 1]++;
}
```
- The outer loop iterates over each interval in the input vector `nums`. Each interval is represented by a pair `[start, end]` in the array `nums`.
- The inner loop iterates through each integer point between `start` and `end` (inclusive) in the current interval. For each point `i`, we increment the corresponding index in the vector `v`. Specifically, we increment `v[i-1]`, because the point `i` corresponds to index `i-1` in the vector `v` (due to the 0-based indexing of `v`).
  
This step marks all the points covered by each interval by incrementing the values in the array `v`.

#### Step 3: Count the Covered Points
```cpp
for (auto e : v) {
    if (e) ans++;
}
```
- After processing all the intervals, the array `v` contains the number of intervals covering each point. The value at index `i-1` in the array `v` represents how many intervals cover the point `i`.
- The loop goes through each element `e` in `v`, and if `e` is non-zero (indicating that the corresponding point is covered by at least one interval), we increment the variable `ans`. This step counts how many unique points are covered by at least one interval.

#### Step 4: Return the Result
```cpp
return ans;
```
- Finally, the variable `ans` holds the total count of unique points covered by at least one interval, and we return this value.

### Complexity

#### Time Complexity:
- **O(n * m)**: The outer loop runs for each interval in `nums`, which has `n` elements. For each interval, we iterate through its range from `start` to `end`. In the worst case, an interval can cover up to 100 points. Therefore, if we assume that the total number of points across all intervals is `m`, the overall time complexity is `O(n * m)`, where `n` is the number of intervals and `m` is the maximum number of points covered by any single interval. However, since the number of distinct points is at most 100, this operation is bounded by a constant.
  
#### Space Complexity:
- **O(1)**: The space complexity is constant because the array `v` always has a fixed size of 102, regardless of the size of the input. The size of the input does not affect the space usage.

### Conclusion

This solution efficiently solves the problem by using a frequency array to track the points covered by intervals. The approach ensures that we count all unique points covered by at least one interval without needing to store the exact points themselves. By incrementing values in the array for each point covered by an interval and then counting how many non-zero values are in the array, we can quickly compute the result.

The solution runs efficiently even with the maximum number of intervals and covers all edge cases, including when no points are covered or when all points are covered. This method also leverages simple array manipulation and avoids the need for more complex data structures, making it easy to implement and understand.

This approach is highly efficient, with linear time complexity relative to the number of intervals and constant space complexity, making it suitable for large datasets.

[`Link to LeetCode Lab`](https://leetcode.com/problems/points-that-intersect-with-cars/description/)

---
{{< youtube 86n-e3Zwx34 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
