
+++
authors = ["grid47"]
title = "Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WZhNEfbGYEo"
youtube_upload_date="2023-05-06"
youtube_thumbnail="https://i.ytimg.com/vi/WZhNEfbGYEo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int pow2(int idx) {
        if(idx == 0) return 1;
        long res;
        if(idx % 2) {
            res = pow2(idx / 2);
            res = (res * res * 2) % mod;
        }else {
            res = pow2(idx / 2);
            res = (res * res) % mod;            
        }
        return res;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        long res = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            if(nums[i] * 2 > target) break;
            
            int end = target - nums[i];
            auto it = upper_bound(nums.begin(), nums.end(), end);
            
            int idx = it - nums.begin();

            res = (res + pow2(idx - i - 1)) % mod;
            
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to find the number of non-empty subsequences of a given array `nums` such that the sum of the minimum and maximum elements in each subsequence is less than or equal to a specified value `target`. Given the potential size of the input and the constraints, we need an efficient approach to count these subsequences.

### Approach

To solve this problem efficiently, we can leverage sorting and binary search, along with properties of subsequences. Here’s a high-level breakdown of our approach:

1. **Sorting**: First, we sort the input array. Sorting allows us to easily identify the minimum and maximum elements of any subsequence.
2. **Two-Pointer Technique**: By iterating over each element of the sorted array as a potential minimum, we can use binary search to find the maximum valid element that, when combined with the current minimum, satisfies the target condition.
3. **Counting Subsequences**: For each valid pair of minimum and maximum, we can compute the number of valid subsequences that can be formed by combining elements between these two indices using the formula \(2^{(index_{max} - index_{min} - 1)}\). This is derived from the fact that each element can either be included or excluded in the subsequence.
4. **Modular Arithmetic**: Since the result can be large, we perform calculations modulo \(10^9 + 7\).

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int mod = (int) 1e9 + 7;
```
Here, we define a class `Solution` with a member variable `mod`, which is the modulus used for calculations to prevent overflow.

#### Step 1: Power of 2 Function

```cpp
    int pow2(int idx) {
        if(idx == 0) return 1;
        long res;
        if(idx % 2) {
            res = pow2(idx / 2);
            res = (res * res * 2) % mod;
        } else {
            res = pow2(idx / 2);
            res = (res * res) % mod;            
        }
        return res;
    }
```
This recursive function computes \(2^{idx} \mod \text{mod}\):
- If \( idx \) is 0, we return 1 (the base case).
- If \( idx \) is odd, we compute the power for half the index, square it, and multiply by 2.
- If \( idx \) is even, we just square the power computed for half the index.

This function allows us to efficiently calculate powers of 2 using recursion and modular arithmetic.

#### Step 2: Main Function to Count Subsequences

```cpp
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
```
We define the main function `numSubseq`, which first sorts the input array `nums`.

```cpp
        long res = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] * 2 > target) break;
```
- We initialize `res` to accumulate the count of valid subsequences.
- If the current minimum element multiplied by 2 exceeds the target, we break out of the loop as no valid maximum can be found.

#### Step 3: Finding Valid Maximum Elements

```cpp
            int end = target - nums[i];
            auto it = upper_bound(nums.begin(), nums.end(), end);
            
            int idx = it - nums.begin();
```
- We compute `end`, which is the maximum valid value that can be paired with the current minimum `nums[i]`.
- Using `upper_bound`, we find the first index in `nums` that exceeds `end`. This allows us to count how many elements can be paired with the current minimum.

#### Step 4: Counting Subsequences

```cpp
            res = (res + pow2(idx - i - 1)) % mod;
        }
        return res;
    }
};
```
- For each valid pair of indices, we compute the number of subsequences formed by the elements between the indices (i.e., `idx - i - 1`), and add this to `res`, taking care to apply the modulus to keep the number manageable.
- Finally, we return the result `res`.

### Complexity

#### Time Complexity
- Sorting the array takes \(O(n \log n)\).
- The loop iterates through the array once, and for each element, we perform a binary search, leading to a complexity of \(O(n \log n)\).
- Thus, the overall time complexity is \(O(n \log n)\).

#### Space Complexity
- The space complexity is \(O(1)\) if we consider only variables used in calculations. However, the input array may be considered to use additional space for sorting.

### Conclusion

The solution effectively counts the valid subsequences where the sum of the minimum and maximum elements does not exceed the target value. By combining sorting with binary search and leveraging modular arithmetic for efficiency, we ensure that the approach is both optimal and scalable for larger inputs.

**Key Points**:
- **Efficiency**: The combination of sorting and binary search enables an efficient solution.
- **Modular Arithmetic**: Ensures results remain within manageable bounds.
- **Power of Two Calculation**: The recursive approach for calculating powers is elegant and efficient.

Overall, this approach provides a robust framework for solving similar combinatorial problems involving subsequences and conditions based on their values.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)

---
{{< youtube WZhNEfbGYEo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
