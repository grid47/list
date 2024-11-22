
+++
authors = ["grid47"]
title = "Leetcode 2529: Maximum Count of Positive Integer and Negative Integer"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2529: Maximum Count of Positive Integer and Negative Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "4uhvXmOp5Do"
youtube_upload_date="2023-01-08"
youtube_thumbnail="https://i.ytimg.com/vi/4uhvXmOp5Do/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0) pos++;
            else if(nums[i] < 0) neg++;
        return max(pos, neg);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to compute the maximum count of either positive or negative numbers in a given array `nums`. Specifically:

- You are provided with an integer array `nums`, and your task is to determine the maximum count between the number of positive integers and negative integers in the array.
- Positive integers are those greater than 0, and negative integers are those less than 0. If the number is zero, it should be ignored.

The function should return the maximum count of positive or negative integers present in the array.

### Approach

To solve this problem, the approach involves iterating through the array and counting how many positive and negative integers are present. Once we have the counts of positive and negative integers, we simply return the larger of the two counts.

#### Key Observations:
- We need to count positive numbers and negative numbers separately.
- We do not need to worry about zeroes in the array, as they do not contribute to either count.
- At the end of the loop, the result will be the larger of the two counts.

### Code Breakdown (Step by Step)

#### 1. Function Definition

```cpp
int maximumCount(vector<int>& nums) {
```

- The function `maximumCount` is defined to take a vector `nums` as input.
- The return type of the function is an integer, which will represent the maximum count of either positive or negative numbers in the array.

#### 2. Initialize Counters

```cpp
int pos = 0, neg = 0;
```

- We initialize two integer variables: `pos` for counting positive numbers and `neg` for counting negative numbers.
- Both `pos` and `neg` are initialized to 0, as we have not processed any elements yet.

#### 3. Iterate Through the Array

```cpp
for(int i = 0; i < nums.size(); i++)
```

- We start a `for` loop that will iterate through each element `nums[i]` in the array `nums`.

#### 4. Count Positive Numbers

```cpp
if(nums[i] > 0) pos++;
```

- If the current element `nums[i]` is greater than 0 (i.e., a positive number), we increment the `pos` counter by 1.
- This ensures that `pos` holds the total count of positive numbers in the array by the end of the loop.

#### 5. Count Negative Numbers

```cpp
else if(nums[i] < 0) neg++;
```

- If the current element `nums[i]` is less than 0 (i.e., a negative number), we increment the `neg` counter by 1.
- This ensures that `neg` holds the total count of negative numbers in the array by the end of the loop.

#### 6. Return the Maximum Count

```cpp
return max(pos, neg);
```

- After the loop completes, we return the maximum of the two counters (`pos` and `neg`), which represents the larger count between positive and negative numbers in the array.
- The function `max(pos, neg)` is used to determine which count is greater and returns the result.

### Complexity Analysis

#### Time Complexity

The time complexity is determined by the number of elements in the array. Specifically:

- We loop through all `n` elements of the array once, and for each element, we perform constant-time operations to check if it's positive or negative and update the corresponding counter.
- Therefore, the time complexity is \( O(n) \), where `n` is the number of elements in the array.

#### Space Complexity

The space complexity is determined by the amount of extra memory used by the algorithm:

- We only use two integer variables (`pos` and `neg`) to store the counts, regardless of the size of the input array.
- Therefore, the space complexity is \( O(1) \), which means the algorithm uses constant space.

### Conclusion

This solution provides an efficient way to solve the problem of finding the maximum count of positive or negative numbers in an array. By simply iterating through the array and keeping track of two counters, we can solve the problem in linear time with constant space.

This approach is optimal because:
- It processes each element exactly once, ensuring \( O(n) \) time complexity.
- It only requires a fixed amount of additional space, making the space complexity \( O(1) \).

Thus, this solution is both time-efficient and space-efficient, and it works well even for large arrays.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/)

---
{{< youtube 4uhvXmOp5Do >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
