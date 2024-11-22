
+++
authors = ["grid47"]
title = "Leetcode 2274: Maximum Consecutive Floors Without Special Floors"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2274: Maximum Consecutive Floors Without Special Floors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZQ6iiXxEhRY"
youtube_upload_date="2022-05-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZQ6iiXxEhRY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& spec) {

        sort(spec.begin(), spec.end());
        int prv = bottom - 1, n = spec.size();

        int res = 0;
        for(int cur : spec) {
            res = max(res, cur - prv - 1);
            prv = cur > prv ? cur : prv;
        }
        res = max(res, top - prv);

        return res;
    }
};

// bottom - top
// spec
// 
{{< /highlight >}}
---

### Problem Statement
In this problem, we are given a range of integers defined by `bottom` and `top`, and a list `spec` of special integers. The goal is to find the **maximum number of consecutive integers** in the range [bottom, top] that are **not present in `spec`**. In other words, we need to determine the longest gap of integers that are not specified in the list `spec`.

For example, if the range is from 1 to 10 and `spec` contains [3, 5, 8], the longest consecutive subsequence of integers that are not in `spec` is `[6, 7]` (a length of 2).

### Approach
The approach involves the following steps:
1. **Sort the `spec` array**: By sorting the list of special numbers, we can easily compare consecutive numbers and calculate the gaps between them.
2. **Track the previous special number**: We will keep track of the last seen special number and compare it with the current special number to determine the gap.
3. **Check the gaps between special numbers**: For each special number, we compute the difference between it and the previous special number (i.e., the gap). The goal is to find the maximum gap where no special number exists.
4. **Consider the gaps at the boundaries**: We need to check the gaps at the beginning (between `bottom` and the first special number) and at the end (between the last special number and `top`).

### Detailed Breakdown of the Code

#### Step 1: Sorting the Special Numbers
```cpp
sort(spec.begin(), spec.end());
```
- The `spec` vector is sorted in ascending order. Sorting helps in easily determining the gaps between consecutive special numbers, ensuring that we can process them in a linear pass.

#### Step 2: Initialize Variables
```cpp
int prv = bottom - 1, n = spec.size();
```
- **`prv`** is initialized to `bottom - 1`, which means that the first "special number" considered before the range starts is just before `bottom`. This helps when calculating the gap between the start of the range and the first special number.
- **`n`** is the size of the `spec` array, representing the total number of special numbers.

#### Step 3: Loop Through the Special Numbers
```cpp
int res = 0;
for(int cur : spec) {
    res = max(res, cur - prv - 1);
    prv = cur > prv ? cur : prv;
}
```
- **`res`** stores the maximum number of consecutive integers that are not in `spec`.
- **`cur`** iterates through each number in the sorted `spec` array. For each special number, we compute the gap between `cur` and `prv` (the previous special number).
- **`cur - prv - 1`** gives the number of integers between `prv` and `cur`, excluding `cur` itself.
- We update `res` with the maximum of the current `res` and the calculated gap.
- **`prv = cur > prv ? cur : prv;`** updates `prv` to the larger of `cur` and `prv`. This ensures that `prv` always points to the most recent special number, so the next gap calculation is correct.

#### Step 4: Check the Gap at the End of the Range
```cpp
res = max(res, top - prv);
```
- After processing all the special numbers, we need to check the gap between the last special number and `top`. The gap is given by `top - prv`, which represents the number of integers from the last special number to `top`.
- We update `res` with the maximum of the current `res` and this last gap.

#### Step 5: Return the Result
```cpp
return res;
```
- Finally, the function returns the value of `res`, which contains the maximum length of consecutive integers not present in `spec`.

### Complexity Analysis

#### Time Complexity
- **Sorting the `spec` array**: Sorting the `spec` array takes **O(n log n)**, where `n` is the number of elements in the `spec` vector.
- **Iterating through the `spec` array**: After sorting, the loop iterates through the `spec` array once, taking **O(n)** time.
- Therefore, the total time complexity is **O(n log n)** due to the sorting step.

#### Space Complexity
- The space complexity of this solution is **O(1)**, assuming that the space required for the input `spec` array is not counted. The solution only uses a few extra integer variables (`prv`, `res`, etc.) and does not require additional data structures, so the space complexity is constant.

### Example Walkthrough

Let’s walk through an example to understand how the code works.

#### Example 1
```cpp
int bottom = 1, top = 10;
vector<int> spec = {3, 5, 8};
```

1. **Sort `spec`**: `spec` becomes `{3, 5, 8}`.
2. Initialize `prv = 0` (since `bottom - 1 = 0`) and `res = 0`.
3. Loop through `spec`:
   - For `cur = 3`: The gap is `3 - 0 - 1 = 2`. Update `res` to 2. Now, `prv = 3`.
   - For `cur = 5`: The gap is `5 - 3 - 1 = 1`. `res` remains 2. Now, `prv = 5`.
   - For `cur = 8`: The gap is `8 - 5 - 1 = 2`. `res` remains 2. Now, `prv = 8`.
4. The gap at the end is `top - prv = 10 - 8 = 2`. `res` remains 2.
5. Return `res = 2`.

#### Example 2
```cpp
int bottom = 1, top = 15;
vector<int> spec = {3, 5, 8, 12};
```

1. **Sort `spec`**: `spec` becomes `{3, 5, 8, 12}`.
2. Initialize `prv = 0` (since `bottom - 1 = 0`) and `res = 0`.
3. Loop through `spec`:
   - For `cur = 3`: The gap is `3 - 0 - 1 = 2`. Update `res` to 2. Now, `prv = 3`.
   - For `cur = 5`: The gap is `5 - 3 - 1 = 1`. `res` remains 2. Now, `prv = 5`.
   - For `cur = 8`: The gap is `8 - 5 - 1 = 2`. `res` remains 2. Now, `prv = 8`.
   - For `cur = 12`: The gap is `12 - 8 - 1 = 3`. Update `res` to 3. Now, `prv = 12`.
4. The gap at the end is `top - prv = 15 - 12 = 3`. `res` remains 3.
5. Return `res = 3`.

### Conclusion
The solution is efficient in determining the maximum length of consecutive integers not present in the list `spec`. The key to the solution lies in sorting the `spec` array and calculating the gaps between consecutive special numbers, as well as considering the boundaries of the range. With a time complexity of **O(n log n)** and a constant space complexity, the solution is both time-efficient and space-efficient, making it well-suited for solving this problem even for larger inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/)

---
{{< youtube ZQ6iiXxEhRY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
