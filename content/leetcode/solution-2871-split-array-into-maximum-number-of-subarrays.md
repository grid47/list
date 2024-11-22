
+++
authors = ["grid47"]
title = "Leetcode 2871: Split Array Into Maximum Number of Subarrays"
date = "2024-01-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2871: Split Array Into Maximum Number of Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xgzsBxfu8Ew"
youtube_upload_date="2023-09-30"
youtube_thumbnail="https://i.ytimg.com/vi/xgzsBxfu8Ew/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0, cur = 0;
        for (int n : nums) {
            cur = cur == 0 ? n : cur & n;
            res += cur == 0;
        }
        return max(1, res);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the maximum number of subarrays in the array `nums` such that the bitwise AND of all elements in each subarray is zero. The subarrays should be continuous, and we are required to return the maximum number of such subarrays that satisfy the condition. If no such subarray exists, return `1`.

A subarray is defined as a contiguous part of the array. For example, in the array `[1, 2, 3]`, subarrays include `[1]`, `[2]`, `[3]`, `[1, 2]`, `[2, 3]`, and `[1, 2, 3]`.

The bitwise AND operation between two numbers results in a number that has binary bits set to 1 only in positions where both operands have a 1. For example:
- `4 & 5 = 4` because their binary representations are `100` and `101`, respectively. The result will only have a 1 in the position where both numbers have a 1 (the first position).

The goal is to identify subarrays where the bitwise AND of all its elements equals 0. We need to return the number of such subarrays and ensure that the number is not less than 1.

### Approach

The approach to solving this problem revolves around calculating the bitwise AND for different subarrays in a linear pass through the array. Since the AND operation tends to reduce the value as we include more numbers (i.e., adding more numbers to the AND will usually set more bits to 0), we can exploit this property.

The steps for this approach are as follows:

1. **Track the AND of the Subarray:** Start with the first element of the array and maintain a running AND of the current subarray. For each new element added to the subarray, update the running AND.
  
2. **Reset when AND becomes zero:** If at any point, the running AND of the subarray becomes zero, this means we have found a valid subarray. We then reset the running AND and start a new subarray from the current position.

3. **Count the Number of Valid Subarrays:** Every time the AND of a subarray becomes zero, we count it as a valid subarray. Continue this process until the entire array has been processed.

4. **Handle Edge Case:** If no such subarrays exist, return `1`. This is done by ensuring that the minimum value of the result is `1`.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Result Variables

```cpp
int res = 0, cur = 0;
```

- The variable `res` is initialized to 0. This will store the count of subarrays where the bitwise AND is zero.
- The variable `cur` is initialized to 0. This will store the running AND of the current subarray as we iterate through the array.

#### Step 2: Iterate through the Array

```cpp
for (int n : nums) {
    cur = cur == 0 ? n : cur & n;
    res += cur == 0;
}
```

- The loop `for (int n : nums)` iterates over each element `n` in the array `nums`.
- Inside the loop:
  - `cur = cur == 0 ? n : cur & n;` checks if the running AND (`cur`) is zero. If it is zero, the AND operation with the current element `n` is restarted with `n`. Otherwise, the AND of `cur` and `n` is computed and stored in `cur`.
  - `res += cur == 0;` increments `res` if `cur` becomes zero after the AND operation. This means we found a subarray where the bitwise AND is zero.

#### Step 3: Return the Result

```cpp
return max(1, res);
```

- Finally, we return `max(1, res)`. This ensures that if no subarray is found where the AND is zero, the result is at least `1`.

### Example Walkthrough

#### Example 1: `nums = [1, 2, 3]`

1. **Step 1: Initialize Variables**
   - `res = 0`, `cur = 0`
   
2. **Step 2: Iterate through Array**
   - For `n = 1`: `cur = 1` (since `cur` is 0, it becomes `1`)
   - For `n = 2`: `cur = 0` (since `1 & 2 = 0`), increment `res` to 1.
   - For `n = 3`: `cur = 3` (since `0 & 3 = 0`, `cur` becomes `3`), but no increment for `res`.

3. **Step 3: Return Result**
   - `res = 1`, so `return max(1, 1) = 1`

**Output:**
```cpp
1
```

#### Example 2: `nums = [1, 2, 0, 3]`

1. **Step 1: Initialize Variables**
   - `res = 0`, `cur = 0`
   
2. **Step 2: Iterate through Array**
   - For `n = 1`: `cur = 1` (since `cur` is 0, it becomes `1`)
   - For `n = 2`: `cur = 0` (since `1 & 2 = 0`), increment `res` to 1.
   - For `n = 0`: `cur = 0` (since `0 & 0 = 0`), increment `res` to 2.
   - For `n = 3`: `cur = 0` (since `0 & 3 = 0`), increment `res` to 3.

3. **Step 3: Return Result**
   - `res = 3`, so `return max(1, 3) = 3`

**Output:**
```cpp
3
```

### Time Complexity

The time complexity of this solution is **O(n)**, where `n` is the length of the array `nums`. This is because we only iterate through the array once, performing constant-time operations (AND and comparisons) for each element.

### Space Complexity

The space complexity of the solution is **O(1)**, as we only use a few variables (`res` and `cur`) to store intermediate results. We do not use any extra space proportional to the input size.

### Conclusion

This solution is highly efficient, operating in linear time and constant space. The key observation is that the bitwise AND of a subarray will generally tend to zero as more elements are included. This makes it possible to count the valid subarrays in a single pass through the array. The algorithm is simple, effective, and works well even for larger inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/description/)

---
{{< youtube xgzsBxfu8Ew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
