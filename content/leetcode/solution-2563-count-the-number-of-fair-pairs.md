
+++
authors = ["grid47"]
title = "Leetcode 2563: Count the Number of Fair Pairs"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2563: Count the Number of Fair Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Z9hOAQFSQ_I"
youtube_upload_date="2023-02-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Z9hOAQFSQ_I/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        for(int i = 0; i < n; i++) {
            int l = lower - nums[i];
            int r = upper - nums[i];
            int u = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
            int b = max((int)(lower_bound(nums.begin(), nums.end(), l) - nums.begin()), i + 1);
            cnt +=  (u < b)? 0: u - b;
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array of integers `nums`, a pair of indices `(i, j)` is considered "fair" if:

1. `i < j`
2. The sum of `nums[i]` and `nums[j]` lies between two given values `lower` and `upper`, inclusive.

The task is to count all fair pairs in the array.

### Approach

1. **Sorting the Array**: The first step is to sort the `nums` array. Sorting helps us use binary search techniques to efficiently find pairs within a specified range. By sorting, we can locate elements that add up to a sum within our desired bounds much faster.

2. **Iterate through Each Element**: For each element `nums[i]` in the array (from index `0` to `n-1`), we aim to find pairs where `i < j` such that the sum `nums[i] + nums[j]` lies within the `[lower, upper]` range.

3. **Define Bounds**:
   - Set `l` as `lower - nums[i]`, which represents the minimum required value for `nums[j]` so that `nums[i] + nums[j] >= lower`.
   - Set `r` as `upper - nums[i]`, representing the maximum allowable value for `nums[j]` so that `nums[i] + nums[j] <= upper`.

4. **Binary Search for Bounds**:
   - Use `lower_bound` to find the first position `b` where `nums[b] >= l`. Since we are only interested in pairs with `i < j`, we ensure `b > i` by taking `b = max(b, i + 1)`.
   - Use `upper_bound` to find the first position `u` where `nums[u] > r`. This means elements up to `u - 1` are valid pairs with `nums[i]`.

5. **Calculate the Number of Fair Pairs**:
   - If `u < b`, there are no valid pairs for `nums[i]`.
   - Otherwise, the count of valid pairs with `nums[i]` is `u - b`.

6. **Accumulate the Result**: Add the count of valid pairs for each `i` to a total counter `cnt`.

### Code Breakdown (Step by Step)

1. **Sort the Array**:  
   ```cpp
   sort(nums.begin(), nums.end());
   ```
   Sorting helps us efficiently locate elements within the target range for each `nums[i]`.

2. **Initialize Count and Loop Through Elements**:
   ```cpp
   long long cnt = 0;
   for(int i = 0; i < n; i++) { ... }
   ```
   Initialize `cnt` to store the number of fair pairs. We loop through each element in the sorted array to treat it as the first element of each potential fair pair.

3. **Define Lower and Upper Bounds**:
   ```cpp
   int l = lower - nums[i];
   int r = upper - nums[i];
   ```
   For each `nums[i]`, calculate `l` and `r` to set the bounds for potential values of `nums[j]` that would make a fair pair with `nums[i]`.

4. **Binary Search for Bounds**:
   ```cpp
   int u = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
   int b = max((int)(lower_bound(nums.begin(), nums.end(), l) - nums.begin()), i + 1);
   ```
   - `upper_bound` finds the first position where `nums[u] > r`, giving the index of the smallest element that would exceed the upper limit for `nums[j]`.
   - `lower_bound` finds the first position where `nums[b] >= l`, ensuring `nums[j]` is at least `l`. We use `max(b, i + 1)` to enforce `i < j`.

5. **Count Valid Pairs**:
   ```cpp
   cnt += (u < b) ? 0 : u - b;
   ```
   If `u < b`, no fair pairs are found. Otherwise, `u - b` gives the count of fair pairs for the current `nums[i]`.

6. **Return Result**:
   ```cpp
   return cnt;
   ```
   Finally, return the accumulated count of fair pairs.

### Complexity Analysis

- **Time Complexity**: Sorting the array takes \(O(n \log n)\). For each element, finding bounds using `lower_bound` and `upper_bound` is \(O(\log n)\), leading to an overall time complexity of \(O(n \log n)\).
  
- **Space Complexity**: The algorithm uses \(O(1)\) additional space for counters and indices, making it space-efficient.

### Conclusion

This solution efficiently counts all fair pairs in the array by combining sorting with binary search for rapid range checks, leveraging the power of `lower_bound` and `upper_bound`. This reduces the need for nested loops, enabling a more scalable solution for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-fair-pairs/description/)

---
{{< youtube Z9hOAQFSQ_I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
