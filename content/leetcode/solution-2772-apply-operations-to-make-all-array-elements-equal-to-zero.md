
+++
authors = ["grid47"]
title = "Leetcode 2772: Apply Operations to Make All Array Elements Equal to Zero"
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2772: Apply Operations to Make All Array Elements Equal to Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xpjC9rt9xsM"
youtube_upload_date="2023-07-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/xpjC9rt9xsM/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkArray(vector<int>& A, int k) {
        int cur = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (cur > A[i])
                return false;
            A[i] -= cur;
            cur += A[i];
            if (i >= k - 1)
                cur -= A[i - k + 1];
        }
        return cur == 0;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to check whether it is possible to transform an array `A` into an array where all elements are zero using the following operation multiple times:
1. For any index `i`, you can subtract a value `x` (which is positive) from `A[i]`.
2. For each operation at index `i`, you need to ensure that the value subtracted from index `i` also affects the next `k` elements of the array, i.e., each subsequent element from `i` to `i + k - 1` gets the value `x` subtracted from it.

The task is to determine if, by applying such operations, we can make all elements of the array `A` zero.

### Approach

The approach to solving this problem involves iterating over the array and maintaining a cumulative "current sum" (`cur`) that represents the ongoing effect of the operations. The key challenge is to ensure that at each step:
1. The current element can be transformed to zero by subtracting the cumulative value (`cur`).
2. If it's possible, the cumulative effect of the transformation must be tracked for the next `k` elements, so we know how much more is subtracted from each subsequent element.

To do this efficiently, we use a sliding window technique where the effect of the previous operations is stored and updated as we move through the array. This allows us to perform the operation in a linear scan without repeatedly modifying the entire array.

### Code Breakdown

#### Function: `checkArray`

```cpp
bool checkArray(vector<int>& A, int k) {
    int cur = 0, n = A.size();
```
- **`cur`**: Keeps track of the cumulative effect of all the previous operations. It starts as 0, meaning no operations have been applied yet.
- **`n`**: The length of the array `A`. This helps with iterating through the array.

```cpp
    for (int i = 0; i < n; ++i) {
        if (cur > A[i])
            return false;
```
- **Main loop**: The loop iterates over each element of the array `A`. At each step, we check if the current value of `cur` exceeds `A[i]`. If `cur` is greater than `A[i]`, it means the cumulative effect from previous operations has already made the value too small to make it zero, and thus it's impossible to proceed further. In this case, the function returns `false` immediately.

```cpp
        A[i] -= cur;
        cur += A[i];
```
- **Transform the current element**: Subtract the cumulative effect `cur` from the current element `A[i]`. This represents applying the operation at index `i`. The new value of `A[i]` is the result after subtracting `cur`.
- **Update `cur`**: Add the newly transformed value of `A[i]` to `cur`. This reflects that starting from index `i + 1`, the next elements will have this new value subtracted from them (i.e., the effect of the operation propagates).

```cpp
        if (i >= k - 1)
            cur -= A[i - k + 1];
```
- **Sliding window**: For indices `i` greater than or equal to `k - 1`, we subtract the value of `A[i - k + 1]` from `cur`. This is because the effect of the operation will no longer affect the element at index `i - k + 1` (the element that was initially within the window of length `k`). By subtracting this value from `cur`, we ensure the correct adjustment of the cumulative effect for the remaining elements.

```cpp
    }
    return cur == 0;
}
```
- **Return condition**: After processing all elements of the array, if `cur` equals 0, it means we were able to make all elements zero using valid operations, and the function returns `true`. If `cur` is not zero, it indicates there are still some leftover effects that couldn't be neutralized, so the function returns `false`.

### Complexity

#### Time Complexity:
- **O(n)**: The algorithm processes each element of the array exactly once in a single loop, performing constant-time operations at each step. Therefore, the time complexity is linear, i.e., **O(n)**, where `n` is the size of the array `A`.

#### Space Complexity:
- **O(1)**: The algorithm uses a constant amount of extra space. The variables `cur` and `n` take constant space, and no additional data structures are required beyond the input array `A`. Therefore, the space complexity is **O(1)**.

### Conclusion

This solution efficiently checks whether it is possible to transform an array into a zero array using a sliding window technique. By keeping track of the cumulative effects of the transformations (the variable `cur`), we avoid the need to repeatedly update the entire array, which would be computationally expensive. The time complexity of **O(n)** ensures that this approach is scalable even for larger arrays, and the space complexity of **O(1)** guarantees minimal memory usage.

By using this approach, we can solve the problem optimally, making it suitable for large inputs while maintaining simplicity and clarity in the code. The sliding window mechanism allows us to efficiently manage the cumulative effects of operations, ensuring that we can determine whether the transformation is possible without unnecessary recalculations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/)

---
{{< youtube xpjC9rt9xsM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
