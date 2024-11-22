
+++
authors = ["grid47"]
title = "Leetcode 2601: Prime Subtraction Operation"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2601: Prime Subtraction Operation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Greedy","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "CC0X2wxP7dE"
youtube_upload_date="2023-03-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/CC0X2wxP7dE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> arr = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
947, 953, 967, 971, 977, 983, 991, 997 };
        int n = nums.size();
        for(int i = n - 2; i >= 0; i--) {
            int j = 0, tmp = nums[i];
            if(nums[i] >= nums[i + 1]) {
                int diff = nums[i] - nums[i + 1] + 1;
                auto it = lower_bound(arr.begin(), arr.end(), diff);
                if(it == arr.end() || *it >= nums[i]) return false;
                nums[i] -= *it;
            }
            if(nums[i] >= nums[i + 1]) return false;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine if it is possible to perform a series of operations on an array `nums` such that after applying a sequence of operations, the resulting array is strictly increasing. In each operation, you are allowed to subtract a prime number from an element of the array. The goal is to check whether it's possible to apply the operation to each element such that the array becomes strictly increasing, with no element being greater than or equal to the next one after the operation.

### Approach

To solve this problem, we need to ensure that for each element in the array, we can find a prime number (from a pre-defined list of primes) that can be subtracted from the current element such that the result still maintains the condition of the array being strictly increasing. This will involve the following steps:

1. **Prime List**: We are given a list of prime numbers. These primes will be the only candidates for subtraction from each element of the array.
   
2. **Traversal of the Array**: We start from the second-to-last element and move towards the first element. For each element:
   - We check whether it is greater than or equal to the next element. If so, we need to subtract a prime from it.
   - The prime subtracted must make the current element strictly less than the next element.
   
3. **Using Lower Bound**: To find a suitable prime number to subtract, we calculate the difference between the current element and the next element. Then, we use binary search (`lower_bound`) to find the smallest prime that is greater than this difference.
   
4. **Checking Validity**: After subtracting the prime, we ensure that the current element becomes smaller than the next element. If at any point, the conditions are violated, we return `false`. If we can process all elements without violating the condition, we return `true`.

### Code Breakdown (Step by Step)

#### 1. **Prime List Initialization**:
   ```cpp
   vector<int> arr = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, ... };
   ```
   - We initialize a list of prime numbers `arr` that can be used for subtraction. This list contains all primes up to 1000. These primes will be used to determine which prime number to subtract from an element in the `nums` array.

#### 2. **Looping Through the Array**:
   ```cpp
   int n = nums.size();
   for(int i = n - 2; i >= 0; i--) {
       int j = 0, tmp = nums[i];
   ```
   - The array `nums` is processed from the second-to-last element to the first element (reverse order). This is done because we need to ensure each element is less than the next one. We compare `nums[i]` with `nums[i+1]` and adjust `nums[i]` accordingly.

#### 3. **Checking if Current Element is Greater Than or Equal to Next Element**:
   ```cpp
   if(nums[i] >= nums[i + 1]) {
       int diff = nums[i] - nums[i + 1] + 1;
   ```
   - For each element `nums[i]`, we check if it is greater than or equal to the next element `nums[i+1]`. If so, we calculate the difference `diff` between `nums[i]` and `nums[i+1]` and add `1` to it. This value represents the minimum difference needed to ensure `nums[i]` becomes strictly less than `nums[i+1]`.

#### 4. **Binary Search for a Suitable Prime**:
   ```cpp
   auto it = lower_bound(arr.begin(), arr.end(), diff);
   if(it == arr.end() || *it >= nums[i]) return false;
   nums[i] -= *it;
   ```
   - We then use `lower_bound` to find the smallest prime in the list `arr` that is greater than or equal to the difference `diff`. This prime will be subtracted from `nums[i]`.
   - If no suitable prime is found (i.e., the iterator `it` reaches the end of the list), or if the prime found is greater than or equal to `nums[i]`, we return `false`, because it would violate the condition that the array remains strictly increasing.
   - If a suitable prime is found, we subtract it from `nums[i]`.

#### 5. **Final Check for Validity**:
   ```cpp
   if(nums[i] >= nums[i + 1]) return false;
   ```
   - After the subtraction, we check if `nums[i]` is still greater than or equal to `nums[i + 1]`. If so, we return `false`, as the array is not strictly increasing.

#### 6. **Return True if All Elements are Processed**:
   ```cpp
   return true;
   ```
   - If the loop completes successfully without returning `false`, it means the array can be transformed into a strictly increasing array by subtracting the appropriate primes. Therefore, we return `true`.

### Complexity Analysis

- **Time Complexity**:
  - The main time complexity comes from the binary search (`lower_bound`) for each element in the array. The binary search takes \(O(\log p)\), where `p` is the number of primes in the list (`arr`), which is 168 primes.
  - The loop runs through the array from `n-2` to `0`, so it iterates `n-1` times.
  - Therefore, the total time complexity is \(O(n \cdot \log p)\), where `n` is the number of elements in `nums` and `p` is the number of primes in the list.

- **Space Complexity**:
  - The space complexity is dominated by the storage of the prime list `arr`, which has a constant size of 168 primes. Therefore, the space complexity is \(O(p)\), where `p` is the number of primes in the list.

### Conclusion

This solution efficiently checks whether it is possible to transform the `nums` array into a strictly increasing sequence by subtracting primes. The algorithm leverages binary search on a predefined list of primes to find the appropriate prime to subtract at each step, ensuring that the array is modified correctly. The solution has a time complexity of \(O(n \cdot \log p)\), which is efficient given the constraints, and a constant space complexity due to the fixed size of the prime list.

[`Link to LeetCode Lab`](https://leetcode.com/problems/prime-subtraction-operation/description/)

---
{{< youtube CC0X2wxP7dE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
