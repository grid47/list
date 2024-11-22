
+++
authors = ["grid47"]
title = "Leetcode 2176: Count Equal and Divisible Pairs in an Array"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2176: Count Equal and Divisible Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "25az-hMz2YE"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/25az-hMz2YE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> umap;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(umap.find(nums[i]) != umap.end()) 
            {
                for(auto x : umap[nums[i]]) 
                    if((i * x) % k == 0)
                        count++;
            }
            
            umap[nums[i]].push_back(i);
        }
        return count;
    }
};
{{< /highlight >}}
---

### Problem Statement
You are given an array `nums` of integers and an integer `k`. The task is to find and count all pairs of indices `(i, j)` such that:
- `i < j`
- The product of the values at these indices `nums[i] * nums[j]` is divisible by `k`.

Your goal is to return the total count of such pairs.

### Approach
To solve this problem, we need to find pairs of indices `(i, j)` where `i < j` and the condition `(nums[i] * nums[j]) % k == 0` holds true. We can break down the approach as follows:

1. **Hash Map for Tracking Indices**:
   - A hash map (`unordered_map<int, vector<int>> umap`) is used to track the indices where each number appears. This will help in efficiently finding potential pairs without having to check every possible pair explicitly.

2. **Iterate Through the Array**:
   - Iterate through each element `nums[i]` of the array. For each element, check all previously encountered elements to see if their product with the current element is divisible by `k`.

3. **Check Divisibility**:
   - For each pair `(i, x)` where `nums[i] * nums[x] % k == 0` (where `x` is a previous index), increment the `count`.

4. **Store Indices**:
   - For every element `nums[i]`, after checking all previous elements, store the current index in the hash map corresponding to `nums[i]`.

5. **Return the Count**:
   - Once the iteration completes, the variable `count` will hold the total number of valid pairs satisfying the condition.

### Code Breakdown (Step by Step)

1. **Initialize the Hash Map and Count**:
   ```cpp
   unordered_map<int, vector<int>> umap;
   int count = 0;
   ```
   - `umap` is an unordered map where the keys are the numbers in the `nums` array, and the values are vectors of indices where those numbers appear. This will allow us to check for divisibility efficiently.
   - `count` is initialized to 0 and will store the total number of valid pairs.

2. **Iterate Through the Array**:
   ```cpp
   for(int i = 0; i < nums.size(); i++) {
   ```
   - This loop iterates through each element `nums[i]` in the array `nums`.

3. **Check for Previously Seen Elements**:
   ```cpp
   if(umap.find(nums[i]) != umap.end()) {
       for(auto x : umap[nums[i]]) {
           if((i * x) % k == 0)
               count++;
       }
   }
   ```
   - The condition `umap.find(nums[i]) != umap.end()` checks if the current number `nums[i]` has been encountered before. If so, the corresponding vector of previous indices is retrieved (`umap[nums[i]]`).
   - For each index `x` in this vector, we check if the product of `i` and `x` is divisible by `k` (`(i * x) % k == 0`). If true, we increment the count.

4. **Store the Current Index**:
   ```cpp
   umap[nums[i]].push_back(i);
   ```
   - After checking all previously encountered indices, the current index `i` is added to the vector of indices for the value `nums[i]` in the hash map.

5. **Return the Count**:
   ```cpp
   return count;
   ```
   - Once the iteration is complete, the final count of valid pairs is returned.

### Example Walkthrough
Let's walk through an example with `nums = [2, 4, 8, 16]` and `k = 8`:

- **Step 1: Initialize**:
  - `umap = {}` (empty hash map)
  - `count = 0`

- **Step 2: Iterate through `nums`**:
  - `i = 0`, `nums[i] = 2`
    - `umap` is empty, so no pairs are found.
    - `umap = {2: [0]}` (store index 0 for value 2).

  - `i = 1`, `nums[i] = 4`
    - Check if `nums[i] * nums[0]` is divisible by `8`: `(4 * 2) % 8 == 0` (True).
    - Increment `count = 1`.
    - `umap = {2: [0], 4: [1]}` (store index 1 for value 4).

  - `i = 2`, `nums[i] = 8`
    - Check if `nums[i] * nums[0]` is divisible by `8`: `(8 * 2) % 8 == 0` (True).
    - Increment `count = 2`.
    - Check if `nums[i] * nums[1]` is divisible by `8`: `(8 * 4) % 8 == 0` (True).
    - Increment `count = 3`.
    - `umap = {2: [0], 4: [1], 8: [2]}` (store index 2 for value 8).

  - `i = 3`, `nums[i] = 16`
    - Check if `nums[i] * nums[0]` is divisible by `8`: `(16 * 2) % 8 == 0` (True).
    - Increment `count = 4`.
    - Check if `nums[i] * nums[1]` is divisible by `8`: `(16 * 4) % 8 == 0` (True).
    - Increment `count = 5`.
    - Check if `nums[i] * nums[2]` is divisible by `8`: `(16 * 8) % 8 == 0` (True).
    - Increment `count = 6`.
    - `umap = {2: [0], 4: [1], 8: [2], 16: [3]}` (store index 3 for value 16).

- **Step 3: Return the Result**:
  - The final value of `count` is `6`, meaning there are 6 valid pairs where the product of the values at those indices is divisible by `k`.

### Complexity

- **Time Complexity**:
  - The time complexity is O(n * m), where `n` is the number of elements in the `nums` array, and `m` is the average number of times each number appears in the array (due to checking each previous index). In the worst case, `m` can be up to `n`, making the overall complexity O(n^2). However, this is a reasonable trade-off for this type of problem.

- **Space Complexity**:
  - The space complexity is O(n), where `n` is the number of elements in the `nums` array. This is because we store the indices of each number in the hash map.

### Conclusion
This solution efficiently counts the pairs of indices where the product of the corresponding values is divisible by `k`. Using a hash map to store previously encountered numbers and their indices allows the algorithm to check conditions in a streamlined manner, reducing the need for nested loops that would otherwise increase the time complexity. While the solution is optimized, it is still important to note the potential O(n^2) complexity for very large arrays. Nonetheless, for moderate-sized inputs, this approach should work efficiently within the problem's constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/)

---
{{< youtube 25az-hMz2YE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
