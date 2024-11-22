
+++
authors = ["grid47"]
title = "Leetcode 53: Maximum Subarray"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 53: Maximum Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/53.webp"
youtube = "5WZl3MMT0Eg"
youtube_upload_date="2020-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/5WZl3MMT0Eg/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/53.webp" 
    alt="A bright, uplifting wave rising, showing the peak of a series of numbers."
    caption="Solution to LeetCode 53: Maximum Subarray Problem"
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
    int maxSubArray(vector<int>& nums) {
        int l = nums[0], g = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > l + nums[i])
                l = nums[i];
            else l += nums[i];
            
            g = max(g, l);
        }
        return g;
    }
};
{{< /highlight >}}
---

### 💡 **Maximum Subarray Problem – Kadane’s Algorithm**

The **Maximum Subarray Problem** is a well-known problem in dynamic programming, and is often referred to as **Kadane’s Algorithm**. The task is to find the contiguous subarray within a given array of integers that has the largest sum. The challenge is to achieve this in **linear time (O(n))**, which is essential when dealing with large input arrays.

### 📝 **Problem Breakdown**

**Goal**: Find the contiguous subarray (which can have any length) within the array that has the largest sum. 

### 🔍 **Approach**

We solve this efficiently using **Kadane’s Algorithm**, which operates in linear time (**O(n)**). This algorithm works by iterating through the array and maintaining two variables:
- **`l` (local maximum):** Tracks the current subarray sum. If adding the current element increases the sum, `l` is updated; otherwise, it resets to the current element.
- **`g` (global maximum):** Stores the maximum sum found so far. Whenever `l` exceeds `g`, we update `g`.

The algorithm iterates through the array and decides whether to:
- Include the current element in the ongoing subarray sum or
- Start a new subarray from the current element.

The result is the largest possible sum of a contiguous subarray, which is found in **O(n)** time.

### 🧑‍💻 **Code Breakdown (Step by Step)**

#### Step 1: Initialize Variables

```cpp
int l = nums[0], g = nums[0];
```
- `l` is initialized to `nums[0]`, the first element of the array, representing the local maximum sum at the start.
- `g` is also initialized to `nums[0]`, and it stores the maximum subarray sum found so far. Initially, it starts with the first element.

#### Step 2: Iterate Through the Array

```cpp
for(int i = 1; i < nums.size(); i++) {
```
- We start the loop from `i = 1` because `nums[0]` has already been considered during initialization.
- The loop goes through each element and decides whether to continue the current subarray or start a new one.

#### Step 3: Update Local Maximum (`l`)

```cpp
if(nums[i] > l + nums[i])
    l = nums[i];
else
    l += nums[i];
```
- The algorithm checks if adding the current element `nums[i]` to the existing subarray sum (`l + nums[i]`) is better than starting a new subarray with just `nums[i]`.
- If `nums[i]` is greater than `l + nums[i]`, it means that the current subarray should be abandoned, and a new subarray starting at `nums[i]` should be considered. So, we update `l` to `nums[i]`.
- Otherwise, the current subarray can be extended, so `l` is updated by adding `nums[i]` to the existing sum.

#### Step 4: Update Global Maximum (`g`)

```cpp
g = max(g, l);
```
- After updating `l`, the algorithm checks if `l` is greater than `g`. If so, it updates `g` to `l`, ensuring that `g` always holds the largest subarray sum encountered so far.

#### Step 5: Return the Result

```cpp
return g;
```
- After iterating through the entire array, `g` contains the largest sum of any contiguous subarray, which is then returned as the final result.

### ⏱️ **Complexity Analysis**

#### Time Complexity:
- **O(n):** The algorithm iterates through the array exactly once. At each iteration, constant-time operations (comparisons and additions) are performed. Therefore, the overall time complexity is O(n).

#### Space Complexity:
- **O(1):** The algorithm only uses a constant amount of extra space (for the variables `l` and `g`), regardless of the input size. Thus, the space complexity is O(1).

### 🌟 **Conclusion**

This solution to the **Maximum Subarray Problem** uses **Kadane’s Algorithm**, which is efficient in both time and space. By maintaining two variables—`l` (the current subarray sum) and `g` (the global maximum sum)—the algorithm computes the result in a single pass through the array.

With a time complexity of **O(n)** and space complexity of **O(1)**, this algorithm is optimal for solving the problem on large datasets. It avoids the brute-force approach of checking all subarrays, which would have a time complexity of **O(n²)**, by leveraging dynamic programming principles to update the best subarray sum at each step.

Kadane’s Algorithm is widely used in competitive programming and real-world applications where performance is crucial. This clean, efficient, and easy-to-understand solution is ideal for solving problems that involve finding maximum subarrays in linear time.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-subarray/description/)

---
{{< youtube 5WZl3MMT0Eg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
