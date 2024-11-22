
+++
authors = ["grid47"]
title = "Leetcode 2555: Maximize Win From Two Segments"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2555: Maximize Win From Two Segments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "trj4pn5uzZ0"
youtube_upload_date="2023-02-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/trj4pn5uzZ0/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeWin(vector<int>& pos, int k) {
        
        int n = pos.size(), res = 0;
        
        vector<int> dp(n + 1, 0);
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(pos[j] < pos[i] - k) j++;
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1+ dp[j]);
        }
        
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to maximize the number of non-overlapping intervals of positions in the array `pos`, where the difference between any two positions in the same interval does not exceed a given integer `k`. The goal is to find the maximum number of positions that can be grouped into intervals, ensuring that each group has a difference between the smallest and largest number less than or equal to `k`.

For example:
- Input: `pos = [1, 2, 3, 4, 5]`, `k = 2`
- Output: The maximum number of non-overlapping intervals that can be formed is `4`, because the intervals could be `[1, 2, 3]` and `[4, 5]`, both satisfying the condition.

### Approach

This problem can be solved using a **dynamic programming** approach combined with a **sliding window technique** to efficiently manage the positions and check the possible intervals.

#### Step-by-Step Breakdown

1. **Initialization**:
   - We are given an array `pos` that represents the positions in the sequence. The goal is to partition these positions into the maximum number of subarrays (or intervals) where the difference between the smallest and largest element in each subarray does not exceed `k`.
   - We will use a dynamic programming array `dp` to store the maximum number of positions we can select up to index `i` (inclusive).

2. **Sliding Window (Two Pointers)**:
   - We maintain two pointers (`i` and `j`) to represent the current interval under consideration.
   - The pointer `i` iterates through the positions, and `j` is used to find the valid starting position of the current interval such that the difference between the positions at `i` and `j` does not exceed `k`.
   - As `i` moves, we adjust `j` so that the interval formed by `pos[j]` to `pos[i]` is valid (i.e., `pos[i] - pos[j] <= k`).

3. **Dynamic Programming Update**:
   - For each `i`, we calculate `dp[i + 1]`, which represents the maximum number of positions we can select up to index `i`:
     - Either we don't select `pos[i]` and carry over the value from `dp[i]`, or we select `pos[i]`, and the size of the current interval is `i - j + 1` where `j` is the starting point of the current interval.
     - Update `dp[i + 1]` as the maximum of these two options.
   - Additionally, we calculate the result (`res`) by checking the value of `dp[i + 1] + dp[j]`, which represents the total number of positions that can be selected when combining the interval from `j` to `i` and the maximum number of positions selected before `j`.

4. **Return the Result**:
   - The final result is stored in `res`, which represents the maximum number of positions that can be selected under the given constraints.

### Code Breakdown (Step by Step)

Let's break the code into manageable parts to understand each segment:

#### Step 1: Function and Variable Initialization

```cpp
int n = pos.size(), res = 0;
vector<int> dp(n + 1, 0);
```
- `n` is the size of the `pos` array.
- `res` will store the final result, i.e., the maximum number of positions that can be selected.
- `dp` is a dynamic programming array, where `dp[i]` stores the maximum number of positions that can be selected from positions `0` to `i`.

#### Step 2: Sliding Window with Two Pointers

```cpp
int j = 0;
for(int i = 0; i < n; i++) {
    while(pos[j] < pos[i] - k) j++;
```
- `j` is a pointer used to represent the start of the current valid interval.
- The inner `while` loop ensures that the difference between `pos[i]` and `pos[j]` does not exceed `k`. We increment `j` until the condition `pos[i] - pos[j] <= k` is satisfied.

#### Step 3: Dynamic Programming Update

```cpp
dp[i + 1] = max(dp[i], i - j + 1);
```
- We update `dp[i + 1]` by either:
  - Not including `pos[i]` and taking the value from `dp[i]`.
  - Including `pos[i]`, and the size of the current valid interval is `i - j + 1`.

#### Step 4: Calculate the Result

```cpp
res = max(res, i - j + 1 + dp[j]);
```
- For each position `i`, we calculate the number of positions that can be selected if we combine the current interval `[j, i]` with the maximum number of positions selected before `j`. We update `res` with the maximum value of this combination.

#### Step 5: Return the Result

```cpp
return res;
```
- After iterating through all positions, `res` will contain the maximum number of positions that can be selected.

### Complexity

#### Time Complexity:
- **Sliding Window**: The outer loop runs `n` times, and for each iteration of the outer loop, the inner `while` loop also runs at most `n` times in total (since each position is processed at most once). Hence, the overall time complexity is \( O(n) \).
- **Dynamic Programming Update**: The `dp` array is updated in constant time for each iteration, so this part contributes \( O(n) \) time complexity.
- **Overall Time Complexity**: The total time complexity is \( O(n) \), where `n` is the number of elements in `pos`.

#### Space Complexity:
- **Dynamic Programming Array**: The `dp` array stores values for each position in the array, contributing \( O(n) \) space complexity.
- **Other Variables**: The other variables (`j`, `res`, etc.) use constant space \( O(1) \).
- **Overall Space Complexity**: The total space complexity is \( O(n) \).

### Conclusion

The solution uses a **greedy approach** combined with **dynamic programming** and a **sliding window technique** to efficiently solve the problem. The sliding window technique ensures that we can find the maximum valid intervals without rechecking all previous intervals for each position, while the dynamic programming array tracks the best possible result up to each position.

The time complexity of \( O(n) \) ensures that the solution can handle large inputs efficiently, making it suitable for real-world applications. The space complexity of \( O(n) \) is manageable, and the algorithm ensures that we compute the result in an optimal manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-win-from-two-segments/description/)

---
{{< youtube trj4pn5uzZ0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
