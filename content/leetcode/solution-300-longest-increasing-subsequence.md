
+++
authors = ["grid47"]
title = "Leetcode 300: Longest Increasing Subsequence"
date = "2024-10-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 300: Longest Increasing Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/300.webp"
youtube = "VZc93A5v1JI"
youtube_upload_date="2023-07-01"
youtube_thumbnail="https://i.ytimg.com/vi/VZc93A5v1JI/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/300.webp" 
    alt="A series of numbers gently connecting to form the longest increasing subsequence, glowing brightly along the way."
    caption="Solution to LeetCode 300: Longest Increasing Subsequence Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), mx = 1;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(mx, dp[i]);
                }
        }
        return mx;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The task is to find the length of the **Longest Increasing Subsequence (LIS)** in a given array of integers. Imagine you’re given a list of numbers, and you need to find the longest sequence where each number is strictly greater than the previous one! This sequence doesn’t have to be continuous but should follow an increasing order.

**Example:**
- **Input:** `[10, 9, 2, 5, 3, 7, 101, 18]`
- **Output:** `4`  
  (The LIS is `[2, 3, 7, 101]`, with a length of 4)

---

### 🧠 Approach

Finding the LIS is a **classic dynamic programming problem**. Here, we’ll use an array `dp` to store the LIS ending at each index in `nums`. Each element `dp[i]` will represent the LIS length up to index `i`. With a two-loop structure, we’ll update `dp[i]` based on prior elements that could extend the sequence ending at `i`. Here’s how:

1. **Initialize** `dp` such that each element starts with 1 (as every element is an LIS of at least length 1).
2. **Iterate** through the array and compare each element `i` with all previous elements `j`.
   - If `nums[j] < nums[i]`, this means `nums[i]` can continue the sequence from `nums[j]`, so update `dp[i]` as `dp[i] = max(dp[i], dp[j] + 1)`.
3. **Result**: The maximum value in `dp` will be the length of the LIS.

---

### 🔨 Step-by-Step Code Breakdown

Here’s a walkthrough of the solution:

#### Step 1: Initialization

```cpp
int n = nums.size(), mx = 1;
vector<int> dp(n, 1);
```
- **`n`**: Total elements in `nums`.
- **`mx`**: Tracks the maximum LIS found.
- **`dp`**: Initializes each element to `1` since each element is an LIS of length 1 by itself.

#### Step 2: Building the `dp` Array

```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
        if(nums[j] < nums[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
            mx = max(mx, dp[i]);
        }
    }
}
```
- **Outer loop**: For each element `i`, checks preceding elements `j`.
- **Inner loop**: If `nums[j] < nums[i]`, then `nums[i]` can extend the LIS ending at `j`.
  - Update `dp[i]` to be the max of its current value or `dp[j] + 1`.
  - Update `mx` as needed.

#### Step 3: Returning the Result

```cpp
return mx;
```
- **Return `mx`**, which now holds the LIS length across the array!

---

### 📈 Complexity Analysis

- **Time Complexity**: **O(n^2)** due to two nested loops. For each element `i`, it compares with all previous elements `j`.
- **Space Complexity**: **O(n)** for the `dp` array.

---

### 🏁 Conclusion

This dynamic programming solution efficiently finds the LIS length in **O(n^2)**, suitable for small to medium input sizes. Here’s why it works well:

- **Dynamic Programming** simplifies tracking optimal subsequence lengths.
- **Intuitive Steps** to update LIS lengths using a two-loop structure.
- **Optimizations Possible**: For larger inputs, consider a binary search method for **O(n log n)**.

---

### 🌟 Key Takeaways

1. **Dynamic Programming** is a valuable approach to optimization problems with overlapping subproblems.
2. **Scalable Code**: While **O(n^2)** works for moderate input sizes, the problem can scale with an **O(n log n)** binary search variant.
3. **Visualize Your Approach**: Think of `dp[i]` as the longest LIS length that ends at each index.

Keep practicing, and soon enough, LIS and similar dynamic programming problems will feel like second nature!

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-increasing-subsequence/description/)

---
{{< youtube VZc93A5v1JI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
