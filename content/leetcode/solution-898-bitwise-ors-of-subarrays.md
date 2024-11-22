
+++
authors = ["grid47"]
title = "Leetcode 898: Bitwise ORs of Subarrays"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 898: Bitwise ORs of Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur, cur2;

        for(int x : arr) {
            cur2 = { x };
            for(int i : cur)        cur2.insert(i | x);
            for(int j : cur = cur2)  res.insert(j);
        }

        return res.size();
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the number of unique bitwise OR values that can be obtained from all possible subarrays of a given integer array `arr`. A subarray is a contiguous part of the array, and the bitwise OR of a subarray is computed by performing a bitwise OR operation on all its elements.

For example:
- For an array `arr = [1, 2, 4]`, the possible subarrays and their corresponding bitwise ORs are:
  - Subarrays: `[1]`, `[2]`, `[4]`, `[1, 2]`, `[2, 4]`, `[1, 2, 4]`
  - Bitwise ORs: `1`, `2`, `4`, `3`, `6`, `7`

The goal is to calculate the number of unique OR values from all subarrays.

### Approach

The problem essentially boils down to finding the distinct results of bitwise OR operations across all subarrays of the input array `arr`. To do this efficiently, we need to use an iterative approach that considers the OR of each possible subarray, but in a way that avoids recalculating the OR for every possible subarray from scratch.

1. **Bitwise OR Properties**:
   - The result of a bitwise OR operation is cumulative, meaning that once a bit is set to 1 in the result of an OR operation, it remains 1 in all subsequent OR operations with additional numbers.
   - For example, if the OR of `[1, 2]` is `3`, then the OR of `[1, 2, 4]` is `7`, because `3 | 4 = 7`.

2. **Efficient Calculation Using Sets**:
   - Use two sets, `cur` and `cur2`, to keep track of the OR results of the current subarray and the subarrays ending at the current element, respectively.
   - `cur` contains the OR results from the previous iteration, and `cur2` accumulates OR results for the current element.
   - For each element in the array, we update the set `cur2` by performing a bitwise OR between the current element and each element in the previous set `cur`.

3. **Updating the Results**:
   - After processing each element, we update the set `res` which stores all unique OR values encountered so far.
   - The set `res` allows us to automatically discard duplicates, keeping only the distinct OR results.

4. **Final Answer**:
   - At the end of the iteration, the size of the set `res` gives the number of distinct OR results from all subarrays.

### Code Breakdown (Step by Step)

1. **Initial Setup**:
   ```cpp
   unordered_set<int> res, cur, cur2;
   ```
   We declare three sets:
   - `res`: Stores all unique OR results from all subarrays.
   - `cur`: Keeps track of the OR results of subarrays ending at the previous element.
   - `cur2`: Accumulates the OR results for the current element.

2. **Iterating Through the Array**:
   ```cpp
   for(int x : arr) {
       cur2 = { x };
   ```
   For each element `x` in the array `arr`, we initialize `cur2` with a set containing only `x`. This represents the OR result of the subarray that consists of just the element `x`.

3. **Bitwise OR for Subarrays**:
   ```cpp
   for(int i : cur)        cur2.insert(i | x);
   ```
   For each OR result `i` in the set `cur` (representing OR results from subarrays ending at the previous element), we compute the OR of `i` with the current element `x`, and insert the result into `cur2`.

4. **Updating the Result Set**:
   ```cpp
   for(int j : cur = cur2)  res.insert(j);
   ```
   After processing the current element, the set `cur2` contains all the OR results from subarrays ending at the current element. We update `cur` to be equal to `cur2` and insert all elements of `cur2` into the result set `res`.

5. **Return the Result**:
   ```cpp
   return res.size();
   ```
   Finally, we return the size of the result set `res`, which contains all distinct OR values from the subarrays of `arr`.

### Complexity

- **Time Complexity**: O(n * m), where `n` is the number of elements in the array and `m` is the maximum number of unique OR values generated at each step. In the worst case, the number of unique OR values can grow exponentially with respect to the number of elements in the array, but typically the number of unique values grows much slower. This approach efficiently handles the subarrays without redundant calculations.
  
  Since the bitwise OR operation is generally inexpensive and the size of each set (`cur` and `cur2`) grows as we move through the array, the complexity is dominated by the number of iterations through the array and the number of OR results stored.

- **Space Complexity**: O(m), where `m` is the number of unique OR results stored in `res`. In the worst case, this can grow to the number of subarrays, but in practice, this will be much smaller due to the properties of the bitwise OR operation.

### Conclusion

This solution efficiently computes the number of distinct bitwise OR values from all subarrays by leveraging the properties of the bitwise OR operation and using sets to keep track of unique results. The approach ensures that we do not recompute ORs unnecessarily for each subarray, making it much faster than a naive approach. By using the iterative set-based accumulation of OR results, the solution achieves optimal performance while maintaining clarity and ease of understanding. The time and space complexity are well-suited for large input arrays, making this approach scalable and efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/bitwise-ors-of-subarrays/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
