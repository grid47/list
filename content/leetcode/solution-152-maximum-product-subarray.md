
+++
authors = ["grid47"]
title = "Leetcode 152: Maximum Product Subarray"
date = "2024-10-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 152: Maximum Product Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/152.webp"
youtube = "lXVy6YWFcRM"
youtube_upload_date="2021-01-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lXVy6YWFcRM/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/152.webp" 
    alt="A radiant subarray of numbers, with the product of values glowing brightly as the maximum result."
    caption="Solution to LeetCode 152: Maximum Product Subarray Problem"
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
    int maxProduct(vector<int>& nums) {
        int mx = 1, mn = 1;

        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) swap(mx, mn);
            mx = max(nums[i], mx * nums[i]);
            mn = min(nums[i], mn * nums[i]);
            
            res = max(res, mx);
        }
        return res;
    }
};
{{< /highlight >}}
---

Your explanation is well-structured and thorough! Here’s a version with added emojis for readability and a slightly more engaging tone:

---

### 💥 Problem Statement

The goal is to find the **maximum product** of any **contiguous subarray** within a given array of integers. The array may contain both positive and negative integers, and we should consider subarrays of any length. A **subarray** is any continuous section of the array, and our task is to return the maximum product we can achieve from any such subarray.

For example, given an input array like `[-2, 3, -4]`, the subarray with the maximum product is `[3, -4]`, and its product is `12`. This problem becomes particularly intriguing because of **negative numbers**, which can flip the product's sign and potentially create larger products when combined with other negatives!

---

### 💡 Approach

To tackle this efficiently, we use a dynamic programming-inspired approach, keeping track of two variables:
1. **`mx`** (maximum product up to the current index)
2. **`mn`** (minimum product up to the current index)

Why track both `mx` and `mn`? Because a **negative number** can flip the sign of a product. The idea is:
- If the current number is **positive**, the maximum product can either be the current number itself or the product of `mx` and the current number.
- If the current number is **negative**, the **minimum product** can flip to become the maximum when multiplied by this negative number, and vice versa.

By tracking both values at each step, we can efficiently compute the maximum product of any subarray in just one pass!

---

### 📝 Code Breakdown (Step-by-Step)

#### 🔹 Step 1: Initialize Variables

```cpp
int mx = 1, mn = 1;
int res = INT_MIN;
```

Here’s what each variable means:
- `mx`: Holds the **maximum product** up to the current index. We initialize it to `1` since the product of no numbers is `1`.
- `mn`: Holds the **minimum product** up to the current index. We also initialize this to `1`.
- `res`: Stores the **global maximum product** so far, starting at `INT_MIN` to ensure any product is larger.

#### 🔹 Step 2: Traverse the Array

```cpp
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < 0) swap(mx, mn);
```

We loop through `nums` one element at a time. If the current number is negative, we **swap `mx` and `mn`**. This is because multiplying a negative number by a smaller negative can make it the **largest product**!

#### 🔹 Step 3: Update `mx` and `mn`

```cpp
    mx = max(nums[i], mx * nums[i]);
    mn = min(nums[i], mn * nums[i]);
```

Here’s why this works:
- `mx = max(nums[i], mx * nums[i])`: The new `mx` is either the current number itself or the product of `mx` and the current number, extending the subarray.
- `mn = min(nums[i], mn * nums[i])`: Similarly, `mn` is either the current number or the product of `mn` and the current number, for future flips.

#### 🔹 Step 4: Update the Global Maximum

```cpp
    res = max(res, mx);
```

At each step, we check if `mx` is the largest product so far and update `res` accordingly.

#### 🔹 Step 5: Return the Result

```cpp
return res;
```

When the loop ends, `res` will contain the maximum product of any contiguous subarray, so we return it!

---

### ⚙️ Complexity Analysis

#### Time Complexity
- **O(n)**, where `n` is the size of `nums`. We only traverse the array once, performing constant-time operations at each step.

#### Space Complexity
- **O(1)**, as we only need a constant amount of extra space to store `mx`, `mn`, and `res`.

---

### 🔍 Key Insights

1. **Handling Negatives:** A negative number can flip the sign of the product, so tracking both the minimum and maximum is key.
2. **Efficient DP Approach:** By using a DP-like approach and two variables, we avoid explicitly storing subarrays, keeping the space complexity low.

---

### 🎉 Conclusion

This solution is optimal for this problem, combining an efficient **O(n)** time complexity with a **O(1)** space complexity. It handles mixed arrays with positives and negatives effectively, computing the maximum product in one pass while using minimal space!



[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-subarray/description/)

---
{{< youtube lXVy6YWFcRM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
