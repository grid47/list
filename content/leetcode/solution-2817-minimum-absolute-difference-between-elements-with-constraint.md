
+++
authors = ["grid47"]
title = "Leetcode 2817: Minimum Absolute Difference Between Elements With Constraint"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2817: Minimum Absolute Difference Between Elements With Constraint in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iZkBnYIJ9Qc"
youtube_upload_date="2023-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/iZkBnYIJ9Qc/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
    set<int> s;
    int res = INT_MAX;
    for (int i = x; i < nums.size() && res > 0; ++i) {
        s.insert(nums[i - x]);
        auto it = s.upper_bound(nums[i]);
        if (it != begin(s))
            res = min(res, nums[i] - *prev(it));
        if (it != end(s))
            res = min(res, *it - nums[i]);
    }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task requires finding the minimum absolute difference between two elements in the array `nums` such that the two elements are at least `x` indices apart. More formally, we are to return the minimum value of `|nums[i] - nums[j]|` for all pairs `(i, j)` where `|i - j| >= x`.

For example, given the array `nums = [1, 3, 6, 19, 20]` and `x = 2`, the function should find the minimum absolute difference between two numbers in `nums` where the difference in their indices is at least `x`. In this case, the smallest absolute difference is `1` (between `19` and `20`).

### Approach

This problem is a variant of the classical "minimum absolute difference" problem, but with an added constraint that the indices of the two numbers must differ by at least `x`. A brute force solution would involve checking all possible pairs of elements with the given constraint, but that would lead to a time complexity of O(n^2), which is inefficient for large input sizes.

A more efficient approach utilizes a **sorted data structure** (like a `set` in C++) to maintain a dynamically changing list of elements while iterating through the array. This allows us to quickly find the closest numbers to the current number as we move through the list, reducing the time complexity of the solution to O(n log n).

The plan is to:
1. Use a `set` to store the elements that are at least `x` indices apart.
2. For each element in the array, use binary search (`upper_bound`) to quickly find the closest elements in the `set`.
3. Track the minimum absolute difference found.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code:

```cpp
int minAbsoluteDifference(vector<int>& nums, int x) {
    set<int> s; // Set to store the numbers that are at least x indices apart
    int res = INT_MAX; // Initialize the result to the maximum possible value
```

1. **Initialization**: 
   - `set<int> s`: This `set` will store the elements of the array that are at least `x` indices apart. The `set` allows efficient binary search-like operations (`upper_bound`).
   - `int res = INT_MAX`: The variable `res` will hold the minimum absolute difference found. We initialize it to the largest possible value to ensure that any valid difference will be smaller.

```cpp
    for (int i = x; i < nums.size() && res > 0; ++i) {
        s.insert(nums[i - x]); // Insert the element nums[i - x] into the set
```

2. **Iteration**:
   - The `for` loop starts at `i = x` because the first valid pair of indices should have a difference of at least `x`.
   - In each iteration, the element at `nums[i - x]` is inserted into the set `s`. This ensures that we maintain the constraint that the elements in the set are at least `x` indices apart from the current element.

```cpp
        auto it = s.upper_bound(nums[i]); // Find the first element in the set that is greater than nums[i]
```

3. **Finding Closest Greater Element**:
   - The `upper_bound(nums[i])` function returns an iterator pointing to the first element in the set that is greater than `nums[i]`. This allows us to efficiently search for the closest element that is larger than the current element `nums[i]`.

```cpp
        if (it != begin(s))
            res = min(res, nums[i] - *prev(it)); // Check the previous element for the closest smaller value
```

4. **Finding Closest Smaller Element**:
   - If `it != begin(s)`, this means there is a valid element before `it` in the set. We calculate the absolute difference `nums[i] - *prev(it)` (the difference between the current number and the largest number smaller than it in the set).
   - We update `res` to the minimum of its current value and this difference.

```cpp
        if (it != end(s))
            res = min(res, *it - nums[i]); // Check the current element for the closest larger value
```

5. **Finding Closest Larger Element**:
   - If `it != end(s)`, there is a valid element after `it` in the set. We calculate the absolute difference `*it - nums[i]` (the difference between the closest larger number and the current number).
   - We again update `res` to the minimum of its current value and this difference.

```cpp
    }
    return res; // Return the minimum absolute difference found
}
```

6. **Return the Result**:
   - After iterating through the array, the value of `res` will be the minimum absolute difference found that satisfies the condition `|i - j| >= x`. We return this value.

### Complexity

1. **Time Complexity**:
   - The time complexity of the loop is O(n), where `n` is the size of the input array `nums`. In each iteration, we perform two operations:
     - **Insert operation** (`s.insert(nums[i - x])`): Insertion into a `set` takes O(log n) time due to the balanced tree structure used in the underlying implementation.
     - **Binary search** (`s.upper_bound(nums[i])`): The `upper_bound` function takes O(log n) time.
   - Therefore, for each iteration, the total time complexity is O(log n). Since the loop runs `n` times, the overall time complexity is **O(n log n)**.

2. **Space Complexity**:
   - The space complexity is **O(n)** because we are storing up to `n` elements in the `set`. The size of the `set` grows with the input size `n`.

### Conclusion

The solution efficiently finds the minimum absolute difference between any two elements in an array such that their indices differ by at least `x`. By leveraging the properties of a `set` for binary search operations, the algorithm reduces the time complexity to **O(n log n)**, making it suitable for large input sizes. This approach avoids the inefficiencies of brute-force solutions, providing a clear and optimized solution to the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/)

---
{{< youtube iZkBnYIJ9Qc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
