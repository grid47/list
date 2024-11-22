
+++
authors = ["grid47"]
title = "Leetcode 2170: Minimum Operations to Make the Array Alternating"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2170: Minimum Operations to Make the Array Alternating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "LkSQby_5YMg"
youtube_upload_date="2022-02-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/LkSQby_5YMg/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    array<int, 3> top2Freq(vector<int>& nums, int start) {
        int first = 0, second = 0, cnt[100001] = {};
        for(int i = start; i < nums.size(); i += 2) {
            if(++cnt[nums[i]] >= cnt[first]) {
                if(nums[i] != first)
                    second = first;
                first = nums[i];
            } else if(cnt[nums[i]] > cnt[second]) second = nums[i];
        }
        return {first, cnt[first], cnt[second] };
    }

    int minimumOperations(vector<int>& nums) {
        auto ev = top2Freq(nums, 0), od = top2Freq(nums, 1);
        return nums.size() - (ev[0] != od[0]? ev[1] + od[1] : max(ev[1]+ od[2], ev[2] + od[1]));
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem involves finding the minimum number of operations needed to make an array `nums` such that no two adjacent elements are the same. An operation is defined as changing an element in the array to a different value. The goal is to minimize these changes while ensuring that adjacent elements have different values.

### Approach
The approach to solve this problem includes the following key steps:
1. **Divide and conquer**:
   - Separate the even-indexed and odd-indexed elements of the array into two groups.
2. **Find top frequencies**:
   - Use the `top2Freq` function to determine the two most frequent numbers and their counts for both even-indexed and odd-indexed elements.
3. **Calculate minimal operations**:
   - If the most frequent elements in the even and odd groups are different, the optimal solution is to keep these elements, minimizing changes.
   - If the most frequent elements in both groups are the same, consider swapping the second-most frequent number in one of the groups to avoid adjacent duplicates and maximize the number of unchanged elements.

### Code Breakdown (Step by Step)
1. **Helper Function `top2Freq`**:
   - The function takes the `nums` array and a `start` index (0 for even, 1 for odd).
   - It iterates through `nums` starting from `start`, incrementing by 2 to gather frequencies of either even or odd indexed elements.
   - A frequency array `cnt` is used to count occurrences of each number up to `100,000`.
   - The function returns an array containing:
     - The most frequent number (`first`).
     - The count of the most frequent number.
     - The count of the second most frequent number (`second`).

2. **Main Function `minimumOperations`**:
   - Calls `top2Freq` for both even and odd indexed positions to obtain their most and second most frequent numbers.
   - Checks if the most frequent numbers from even and odd positions (`ev[0]` and `od[0]`) are different:
     - If different, the number of operations needed is the total length of `nums` minus the sum of their counts (`ev[1] + od[1]`).
     - If the same, it calculates the best possible combination by considering using the second-most frequent number from either group (`max(ev[1] + od[2], ev[2] + od[1])`).

3. **Return Value**:
   - Returns the minimum number of operations needed to make the array valid by subtracting the highest achievable sum of unchanged elements from `nums.size()`.

### Complexity
- **Time Complexity**: O(n), where `n` is the length of `nums`. The `top2Freq` function runs in O(n) as it scans half of `nums` in each call. The main function calls `top2Freq` twice, keeping the time complexity linear.
- **Space Complexity**: O(1) for auxiliary space, apart from the constant-sized array `cnt` used for counting frequencies. The space used by this array is independent of `n`.

### Conclusion
This solution is an optimal approach for determining the minimum number of operations to make an array such that no two adjacent elements are the same. By breaking down the array into even and odd indexed elements and calculating their most and second-most frequent values, the solution efficiently evaluates the best strategy for minimizing operations. This method leverages frequency counting and careful selection logic to ensure an optimal result, with clear and maintainable code logic.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/description/)

---
{{< youtube LkSQby_5YMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
