
+++
authors = ["grid47"]
title = "Leetcode 2600: K Items With the Maximum Sum"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2600: K Items With the Maximum Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "HmEYKbfjCLA"
youtube_upload_date="2023-03-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HmEYKbfjCLA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kItemsWithMaximumSum(int one, int zero, int neg, int k) {
        int sum = 0;
        sum += min(one, k);
        k -= min(one, k);
        if(k > 0) {
            k -= min(zero, k);
        }
        if(k > 0) {
            sum -= min(neg, k);
            k -= min(neg, k);
        }
        return sum;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given three integers, `one`, `zero`, and `neg`, and an integer `k`, the task is to calculate the maximum possible sum of selecting `k` items from a list of `one` positive ones, `zero` zeroes, and `neg` negative ones. The goal is to select `k` items in such a way that their sum is as large as possible.

### Approach

To solve this problem, the key observation is to prioritize selecting the positive ones first, as they contribute the most to the sum. After that, we can consider the zeroes, which do not affect the sum at all. Finally, if there are still remaining selections to be made, we must choose the negative ones, which will reduce the sum.

The strategy for solving this problem involves:

1. **Prioritize Positive Numbers**: Since we want to maximize the sum, we select the positive ones first. The maximum number of positive ones we can select is the minimum of `one` and `k`, because we can only pick up to `k` items in total.
   
2. **Zero Contribution**: After selecting the positive ones, if we still have remaining selections (i.e., if `k` is still greater than zero), we pick zeroes next. Zeroes do not affect the sum, so selecting them does not change the total sum.

3. **Negative Numbers**: After selecting all positive ones and zeroes, if there are still remaining selections to be made, we must pick negative numbers. Since negative numbers decrease the sum, we select as many as needed to fill the remaining quota, adjusting the sum accordingly by subtracting the appropriate number of negative values.

### Code Breakdown (Step by Step)

#### 1. **Function Definition**:
   ```cpp
   int kItemsWithMaximumSum(int one, int zero, int neg, int k) {
       int sum = 0;
   ```
   - The function `kItemsWithMaximumSum` takes four parameters: `one`, `zero`, `neg`, and `k`.
     - `one`: The number of positive ones.
     - `zero`: The number of zeroes.
     - `neg`: The number of negative ones.
     - `k`: The number of items to select from these categories to maximize the sum.

#### 2. **Select Positive Numbers**:
   ```cpp
   sum += min(one, k);
   k -= min(one, k);
   ```
   - First, we select as many positive ones as possible. The number of positive ones we can select is the minimum between `one` (the number of positive ones available) and `k` (the number of items we still need to select).
   - We then subtract the number of positive ones selected from `k` to keep track of how many items are left to choose from.

#### 3. **Select Zeroes**:
   ```cpp
   if(k > 0) {
       k -= min(zero, k);
   }
   ```
   - Next, we select zeroes. Since zeroes do not affect the sum, we select as many as possible, but we are limited by the number of zeroes available and the remaining value of `k`.
   - We subtract the number of zeroes selected from `k` to keep track of how many items are left to select.

#### 4. **Select Negative Numbers**:
   ```cpp
   if(k > 0) {
       sum -= min(neg, k);
       k -= min(neg, k);
   }
   ```
   - Finally, if there are still items left to select, we must select negative ones. The maximum number of negative ones we can select is the minimum between `neg` (the number of negative ones available) and the remaining value of `k`.
   - Since negative ones decrease the sum, we subtract the selected number of negative ones from the `sum`.

#### 5. **Return the Final Result**:
   ```cpp
   return sum;
   }
   ```
   - After selecting the positive ones, zeroes, and negative ones, we return the total sum. This sum represents the maximum sum possible by selecting `k` items from the given categories.

### Complexity Analysis

- **Time Complexity**:
  The solution makes a constant number of operations for each step (selecting positive ones, zeroes, and negative ones). Each of these operations takes constant time, i.e., \(O(1)\). Therefore, the overall time complexity is \(O(1)\).

- **Space Complexity**:
  The solution uses only a few integer variables (`sum`, `k`, and temporary variables for the calculations), so the space complexity is \(O(1)\) as well.

### Conclusion

This problem is solved efficiently by strategically selecting the items that contribute the most to the sum. By focusing on selecting positive ones first, zeroes second (which do not affect the sum), and negative ones last (which reduce the sum), we can calculate the maximum sum in constant time. The solution runs in constant time and space, making it optimal for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/k-items-with-the-maximum-sum/description/)

---
{{< youtube HmEYKbfjCLA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
