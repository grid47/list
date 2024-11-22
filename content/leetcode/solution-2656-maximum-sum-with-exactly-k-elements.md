
+++
authors = ["grid47"]
title = "Leetcode 2656: Maximum Sum With Exactly K Elements "
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2656: Maximum Sum With Exactly K Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "lA9B6M4E_BQ"
youtube_upload_date="2023-04-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lA9B6M4E_BQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int i = *max_element(nums.begin(), nums.end());
        return i * k + k * (k - 1) / 2;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given an integer array `nums` and an integer `k`. You need to calculate the maximum possible sum you can get after performing the following operation exactly `k` times:

1. Choose any element from the array `nums`.
2. Add that element's value to the sum.
3. After selecting an element, increment it by `1` for the next operation.

The challenge is to maximize the sum obtained by repeating the above operation `k` times.

### Approach

To solve this problem efficiently, let's break down the problem and consider the following steps:

1. **Key Insight – Maximizing the Sum**:
   - The problem asks us to perform `k` operations and each time, select an element from the array to add to the total sum.
   - Each time we pick an element, we can increment it by `1` for the next operation. Hence, the first element selected will contribute its original value to the sum, the second will contribute its value incremented by `1`, the third will contribute its value incremented by `2`, and so on.
   - In order to maximize the sum, we should always pick the largest element from the array. This is because the larger the starting number, the more it will contribute over multiple increments.
   - Thus, the optimal approach is to find the maximum element in the array, then select it `k` times, incrementing it each time. This guarantees the largest possible sum.

2. **Formula for Sum Calculation**:
   - Let the maximum element in the array be `max_num`. The first time we pick this element, it contributes `max_num` to the sum.
   - The second time, we pick the same element but incremented by `1`, so it contributes `max_num + 1`.
   - The third time, it contributes `max_num + 2`, and so on until we have picked the element `k` times.
   - This means the sum we want to compute can be represented by the following formula:
     \[
     \text{sum} = \text{max\_num} \times k + \frac{k \times (k-1)}{2}
     \]
     where `max_num * k` is the sum of the `k` selections of the maximum element, and `k * (k - 1) / 2` is the sum of the incremental values added to the maximum element in each subsequent pick.

3. **Final Steps**:
   - Find the maximum element in the array.
   - Calculate the sum using the formula mentioned above.
   - Return the result.

### Code Breakdown

Let’s go step by step through the implementation:

```cpp
int i = *max_element(nums.begin(), nums.end());
```
- This line uses the C++ standard library function `max_element` to find the maximum element in the array `nums`. The `max_element` function returns an iterator pointing to the largest element in the range `[nums.begin(), nums.end()]`. We dereference this iterator to obtain the value of the maximum element and assign it to the variable `i`.

```cpp
return i * k + k * (k - 1) / 2;
```
- This line calculates and returns the maximum possible sum. The first part of the equation, `i * k`, represents the sum of `k` selections of the maximum element.
- The second part, `k * (k - 1) / 2`, calculates the sum of the incremental values for each subsequent selection. This sum is derived from the arithmetic progression: `0 + 1 + 2 + ... + (k-1)`, which can be simplified using the formula for the sum of the first `n` integers: \( \frac{n \times (n - 1)}{2} \).
- The sum of these two parts is then returned as the result.

### Complexity

- **Time Complexity**: 
   - The most computationally expensive part of this solution is finding the maximum element in the array. This is done using the `max_element` function, which has a time complexity of **O(n)**, where `n` is the number of elements in the array `nums`.
   - The rest of the operations, including calculating the sum, are constant time operations. Hence, the overall time complexity is **O(n)**.

- **Space Complexity**:
   - The space complexity is **O(1)**, since we are only using a few variables to store intermediate values (e.g., `i` for the maximum element and the result of the sum calculation). There are no additional data structures that grow with the size of the input, making the space complexity constant.

### Conclusion

The solution efficiently calculates the maximum sum that can be obtained by performing `k` operations, selecting the maximum element from the array `k` times and adding the incremental values. By leveraging the properties of arithmetic progressions and utilizing the built-in `max_element` function, the solution achieves an optimal time complexity of **O(n)**, which is efficient for the problem at hand.

The solution is simple and concise, with constant space complexity, making it both time and space-efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/)

---
{{< youtube lA9B6M4E_BQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
