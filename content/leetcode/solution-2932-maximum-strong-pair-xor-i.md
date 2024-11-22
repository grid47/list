
+++
authors = ["grid47"]
title = "Leetcode 2932: Maximum Strong Pair XOR I"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2932: Maximum Strong Pair XOR I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Trie","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "n6CncKaYGwk"
youtube_upload_date="2023-11-14"
youtube_thumbnail="https://i.ytimg.com/vi/n6CncKaYGwk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            if((nums[j] - nums[i] <= nums[i]) && (res <= (nums[i] ^ nums[j]))){
                // cout << nums[i] << " " << nums[j] << "\n";
                res = max(res, nums[i] ^ nums[j]);
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement:
The problem asks us to find the maximum XOR value of a "strong pair" from an array of integers `nums`. A pair `(nums[i], nums[j])` is considered a "strong pair" if the following conditions are met:
1. \( nums[j] - nums[i] \leq nums[i] \)
2. The XOR value of `nums[i]` and `nums[j]` should be the largest among all possible valid pairs.

The goal is to compute the maximum XOR value of all valid pairs satisfying these conditions. The XOR operation is used here because it has certain mathematical properties, making it an interesting operation in combinatorial problems like this one.

### Approach:
We need to find the maximum XOR value for pairs of numbers in the array `nums` that satisfy the condition:
\[
nums[j] - nums[i] \leq nums[i]
\]
This condition ensures that the second number in the pair is not significantly larger than the first one, making the pair "strong."

To solve the problem efficiently:
1. **Sort the Array**: Sorting the array helps us easily compare pairs. Sorting ensures that we can evaluate differences between numbers in a structured manner, as `nums[j]` will always be greater than or equal to `nums[i]` for any pair `(i, j)`.
2. **Brute Force Pair Comparison**: We can then iterate over each pair `(nums[i], nums[j])` and check if the pair satisfies the condition \( nums[j] - nums[i] \leq nums[i] \). If it does, we compute the XOR value of the pair and update the maximum XOR value encountered so far.
3. **Efficiency Consideration**: Sorting the array takes \(O(n \log n)\), and the nested loops over the array elements give a time complexity of \(O(n^2)\) for comparing all pairs. This brute force approach can be slow for large inputs, but it is straightforward and works for moderate-sized inputs.

### Code Breakdown (Step by Step):

1. **Function Definition**:
   The function `maximumStrongPairXor` takes a single argument, `nums`, which is a vector of integers. It returns the maximum XOR value of a strong pair.

   ```cpp
   int maximumStrongPairXor(vector<int>& nums) {
   ```

2. **Sorting the Array**:
   We start by sorting the array `nums` in ascending order. This ensures that for any pair `(i, j)`, we know that `nums[i] <= nums[j]`, which simplifies the comparison and helps to check the condition \( nums[j] - nums[i] \leq nums[i] \).

   ```cpp
   sort(nums.begin(), nums.end());
   ```

3. **Initialize Variables**:
   We initialize two variables:
   - `n` to store the size of the array.
   - `res` to keep track of the maximum XOR value found. We initialize it to 0 since the XOR of any two non-negative integers is at least 0.

   ```cpp
   int n = nums.size(), res = 0;
   ```

4. **Nested Loop to Compare Pairs**:
   We use two nested loops to iterate over all pairs of numbers `(nums[i], nums[j])`:
   - The outer loop runs through each number `i` from 0 to `n-1`.
   - The inner loop runs from `i` to `n-1`, comparing the current element `nums[i]` with `nums[j]` where `j >= i`.
   
   ```cpp
   for(int i = 0; i < n; i++)
       for(int j = i; j < n; j++) {
   ```

5. **Check Strong Pair Condition**:
   Inside the inner loop, we check if the pair `(nums[i], nums[j])` satisfies the condition \( nums[j] - nums[i] \leq nums[i] \). If it does, we compute the XOR value of `nums[i]` and `nums[j]` and check if it's greater than the current maximum XOR value `res`. If it is, we update `res` to this new value.

   ```cpp
   if((nums[j] - nums[i] <= nums[i]) && (res <= (nums[i] ^ nums[j]))) {
       res = max(res, nums[i] ^ nums[j]);
   }
   ```

6. **Return the Result**:
   After all iterations, we return the maximum XOR value `res`, which is the answer to the problem.

   ```cpp
   return res;
   }
   ```

### Complexity:

1. **Time Complexity**:
   The time complexity of this solution is dominated by the nested loops and the sorting step:
   - Sorting the array takes \(O(n \log n)\), where `n` is the size of the array.
   - The nested loops iterate over all pairs of elements in the array, which takes \(O(n^2)\) time.

   Thus, the overall time complexity is:
   \[
   O(n \log n + n^2)
   \]
   Since \(O(n^2)\) dominates \(O(n \log n)\) for large `n`, the time complexity is effectively \(O(n^2)\).

2. **Space Complexity**:
   The space complexity of this solution is \(O(1)\) for auxiliary space since we only use a few variables to keep track of the result and the array size. The space complexity of sorting the array is typically \(O(n)\) due to the internal sorting mechanism, but we are not explicitly using additional data structures that grow with the input size.

   Hence, the space complexity is \(O(n)\) due to the sorting step, but the overall auxiliary space used is constant.

### Conclusion:
This solution is a straightforward approach to the problem, leveraging sorting and brute force comparison of pairs to find the maximum XOR value that satisfies the given condition. The algorithm performs well for small and moderate-sized arrays but may become inefficient for large arrays due to the \(O(n^2)\) time complexity. 

The strengths of this solution are:
- Simplicity: The algorithm is easy to understand and implement.
- Correctness: It guarantees finding the maximum XOR value of a strong pair as per the problem's requirements.

However, for larger inputs, the time complexity can be a bottleneck, and optimizing this solution through more advanced techniques like dynamic programming or bit manipulation may be necessary to improve performance. In scenarios where the array size is relatively small or moderate, this brute-force solution should work efficiently within the time limits.

To summarize:
- **Time Complexity**: \(O(n^2)\)
- **Space Complexity**: \(O(n)\) (for sorting)


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-strong-pair-xor-i/description/)

---
{{< youtube n6CncKaYGwk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
