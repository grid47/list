
+++
authors = ["grid47"]
title = "Leetcode 2475: Number of Unequal Triplets in Array"
date = "2024-03-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2475: Number of Unequal Triplets in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "AbSMJxiiJpk"
youtube_upload_date="2022-11-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AbSMJxiiJpk/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int unequalTriplets(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int n : nums)
        ++m[n];
    int res = 0, left = 0, right = nums.size();
    for (auto [n, cnt] : m) {
        right -= cnt;
        res += left * cnt * right;
        left += cnt;
    }
    return res;
}
};
{{< /highlight >}}
---

### Problem Statement:
The problem asks to find the number of unequal triplets in an array. A triplet `(i, j, k)` is considered unequal if the elements at those indices are distinct, i.e., `nums[i]`, `nums[j]`, and `nums[k]` are all different. We need to count how many such triplets exist where `0 <= i < j < k < nums.size()`.

### Approach:
To solve this problem efficiently, we need to count the number of distinct triplets in the array where each triplet contains unique elements. A brute-force approach would involve checking all possible triplets, but this would have a time complexity of \(O(n^3)\), which would be inefficient for large arrays. Instead, we can leverage a more optimized approach using hashing and precomputations.

The key observation is that we don't need to explicitly check each triplet. Instead, we can focus on counting how many elements are smaller and larger than a given number, then compute the number of valid triplets using this information.

#### Optimized Plan:
1. **Count Frequencies**: First, we need to determine how often each number appears in the array. This will allow us to compute the number of smaller and larger numbers for each distinct element in the array.
  
2. **Calculate Triplet Counts**: Once we have the frequency of each element, we can calculate how many numbers are smaller and larger than each element. For each distinct element `n`, we can count how many triplets can be formed where `n` is the middle element by counting how many numbers smaller than `n` exist (let's call this `left`), how many numbers greater than `n` exist (`right`), and then multiplying these two counts by the frequency of `n`.

3. **Efficient Calculation Using Two Pointers**: The key idea is to update the counts progressively as we iterate through the array, adjusting the `left` and `right` values dynamically as we process each distinct element.

### Code Breakdown (Step by Step):
Now, let’s break down the code to understand how it works:

1. **Frequency Count**:
   ```cpp
   unordered_map<int, int> m;
   for (int n : nums)
       ++m[n];
   ```
   - Here, we create an unordered map `m` to store the frequency of each number in the array `nums`.
   - We loop through the array and increment the count of each number in `m`.

2. **Variable Initialization**:
   ```cpp
   int res = 0, left = 0, right = nums.size();
   ```
   - `res` is initialized to 0, and it will store the final result — the count of unequal triplets.
   - `left` is initialized to 0, and it will track the number of elements less than the current element as we iterate over the array.
   - `right` is initialized to `nums.size()` (the total number of elements in the array), and it will track the number of elements greater than the current element.

3. **Iterating Over Frequency Map**:
   ```cpp
   for (auto [n, cnt] : m) {
       right -= cnt;
       res += left * cnt * right;
       left += cnt;
   }
   ```
   - This loop iterates over each distinct number `n` in the map `m`, where `cnt` is the frequency of that number in the array.
   - The `right -= cnt` line reduces the `right` count by `cnt` because we are processing the current element `n`, and the elements greater than `n` are no longer part of the remaining elements.
   - `res += left * cnt * right` calculates the number of triplets where `n` is the middle element. We multiply:
     - `left`: the number of elements smaller than `n`,
     - `cnt`: the number of occurrences of `n` itself,
     - `right`: the number of elements greater than `n`.
   - After processing the current element `n`, we increment `left` by `cnt` because now `n` becomes part of the left side for future elements.

4. **Return the Result**:
   ```cpp
   return res;
   ```
   - After iterating over all distinct elements in the array, the variable `res` will contain the total number of unequal triplets. We return `res` as the final result.

### Complexity:
Let’s analyze the time and space complexity of this approach:

- **Time Complexity**:
  - **Building Frequency Map**: The loop that constructs the frequency map takes \(O(n)\) time, where \(n\) is the number of elements in the array `nums`.
  - **Calculating Triplets**: The loop that iterates over the frequency map runs for each distinct element in the array. In the worst case, the number of distinct elements is \(n\), so this loop also takes \(O(n)\) time.
  - Thus, the overall time complexity of the algorithm is \(O(n)\), where \(n\) is the number of elements in the input array `nums`.

- **Space Complexity**:
  - **Frequency Map**: The space complexity for the frequency map is \(O(m)\), where \(m\) is the number of distinct elements in the array. In the worst case, \(m = n\), so the space complexity is \(O(n)\).
  - Thus, the overall space complexity is \(O(n)\), where \(n\) is the number of elements in the array `nums`.

### Conclusion:
The solution efficiently calculates the number of unequal triplets in the given array by leveraging frequency counting and dynamic counting of smaller and larger elements. This approach avoids the need for a brute-force solution, resulting in a time complexity of \(O(n)\), which is optimal for this problem. The space complexity is also \(O(n)\), which is required for storing the frequency map of the elements.

By processing the array in a single pass and using the frequency map to track the number of smaller and larger elements dynamically, the solution ensures that we can count the triplets efficiently, even for large arrays. This approach is ideal for solving the problem when the input size is large, as it scales linearly with the number of elements in the array.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/)

---
{{< youtube AbSMJxiiJpk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
