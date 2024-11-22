
+++
authors = ["grid47"]
title = "Leetcode 209: Minimum Size Subarray Sum"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 209: Minimum Size Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/209.webp"
youtube = "RG17VCQOFpg"
youtube_upload_date="2024-06-21"
youtube_thumbnail="https://i.ytimg.com/vi/RG17VCQOFpg/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/209.webp" 
    alt="A glowing, shrinking subarray highlighting the smallest sum as it contracts into the minimal size."
    caption="Solution to LeetCode 209: Minimum Size Subarray Sum Problem"
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, idx = 0, g = INT_MAX, bdx = 0;
        while(idx < nums.size()) {
            sum += nums[idx];

            while(sum >= target) {
                g = min(g, idx - bdx + 1);
                sum -= nums[bdx];
                bdx++;
            }
            idx++;
        }
        return g == INT_MAX? 0: g;
    }
    
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The goal of this problem is to find the minimal length of a contiguous subarray within an array of integers that has a sum greater than or equal to a given target value. If no such subarray exists, we should return `0`. This is a classic problem that can be tackled efficiently with the **sliding window technique**, which is designed to handle such dynamic range problems.

---

### 🧠 Approach

To solve this problem, we can apply the **sliding window technique**, which involves maintaining a variable-sized window (or subarray) of elements. The key idea here is to **expand** the window by adding new elements and **contract** the window by removing elements from the left side when necessary, all while ensuring the sum of elements within the window is at least the target value.

By tracking the sum of the elements within the window, we can quickly check if the sum meets or exceeds the target. When it does, we attempt to shrink the window from the left to minimize its size, ensuring we find the smallest possible subarray that satisfies the condition.

---

### 🔨 Step-by-Step Code Breakdown

Let’s break down the code step by step to see how we can implement this approach:

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, idx = 0, g = INT_MAX, bdx = 0;
```
- **sum**: This keeps track of the current sum of the elements within our sliding window.
- **idx**: This is the "right" pointer, which will be used to expand the window by iterating over the array.
- **g**: This variable holds the length of the smallest valid subarray. It’s initially set to `INT_MAX` to indicate that we haven’t found any valid subarray yet.
- **bdx**: The "left" pointer, used to shrink the window once the sum meets or exceeds the target.

---

```cpp
        while(idx < nums.size()) {
            sum += nums[idx];
```
- The outer `while` loop runs through the entire array using the `idx` index.
- For each element in the array, we add it to the `sum`, expanding our window by including the current element.

---

```cpp
            while(sum >= target) {
                g = min(g, idx - bdx + 1);
                sum -= nums[bdx];
                bdx++;
            }
```
- The inner `while` loop checks whether the sum of the current window is greater than or equal to the target.
- If the condition is satisfied, we:
  1. Calculate the length of the current subarray (`idx - bdx + 1`) and update `g` with the smallest length between the current `g` and the length of the current subarray.
  2. Shrink the window by subtracting the value at `nums[bdx]` from `sum` and moving the `bdx` pointer to the right. This effectively removes the leftmost element from the subarray.

---

```cpp
            idx++;
        }
```
- After processing the current element, we increment `idx` to expand the window and move on to the next element in the array.

---

```cpp
        return g == INT_MAX ? 0 : g;
    }
};
```
- Finally, if `g` is still `INT_MAX`, it means we haven’t found any subarray that meets the target sum, so we return `0`.
- Otherwise, we return the value of `g`, which represents the length of the smallest subarray that satisfies the condition.

---

### 📊 Complexity Analysis

#### Time Complexity:
- **O(n)**, where `n` is the length of the input array `nums`.  
  - The `idx` pointer moves through the array exactly once, and for each `idx`, the `bdx` pointer only moves forward. Thus, both pointers together traverse the array at most once, resulting in a linear time complexity.

#### Space Complexity:
- **O(1)**, since we only use a constant amount of extra space for variables like `sum`, `g`, `bdx`, and `idx`. No additional data structures like arrays or hashmaps are used.

---

### 🏁 Conclusion

The sliding window technique is an optimal and efficient approach for finding the minimal length subarray with a sum greater than or equal to a target value. This solution achieves **O(n)** time complexity and **O(1)** space complexity, making it suitable for large inputs and real-time applications where performance is crucial.

#### Key Steps:
- **Expand the window** by adding elements to the sum.
- **Contract the window** by removing elements from the left as long as the sum meets the target.
- **Track the smallest valid subarray** to get the optimal result.

This approach is ideal for problems involving contiguous subarrays or sliding windows, providing a flexible and efficient way to solve a range of similar problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

---
{{< youtube RG17VCQOFpg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
