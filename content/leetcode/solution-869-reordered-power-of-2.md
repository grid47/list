
+++
authors = ["grid47"]
title = "Leetcode 869: Reordered Power of 2"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 869: Reordered Power of 2 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Sorting","Counting","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rJu123dgDy8"
youtube_upload_date="2019-08-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rJu123dgDy8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int c = counter(n);
        for(int i = 0; i < 32; i++)
            if(counter(1<<i) == c) return true;
        return false;
    }

    int counter(int N) {
        int res = 0;
        for(;N; N/=10) res += pow(10, N%10);
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine if a given integer `n` can be reordered to form a power of 2. A power of 2 is any number that can be expressed as `2^x` for some integer `x`. The goal is to check whether there exists any permutation of the digits of `n` that forms a number which is a power of 2.

For example:
- **Input**: `n = 1`
- **Output**: `True`
  - `1` is already a power of 2 (`2^0 = 1`).
  
- **Input**: `n = 10`
- **Output**: `False`
  - `10` cannot be rearranged to form a power of 2.

The task is to return `true` if a permutation of the digits of `n` is a power of 2, and `false` otherwise.

### Approach

To solve this problem, we can use the following steps:
1. **Generate all powers of 2 up to the maximum possible integer**: We need to generate all the powers of 2 that could potentially match the number `n`. For a 32-bit integer, the largest possible power of 2 is `2^30`, since `2^31` exceeds the integer range.
  
2. **Check the digit permutations**: To determine if any permutation of the digits of `n` matches a power of 2, we can count the frequency of each digit in `n` and compare it against the frequencies of the digits in each power of 2.

3. **Efficiency considerations**: Instead of generating all permutations of the digits of `n`, we can simplify the problem by comparing the digit frequencies directly. We compute a "signature" of the number's digits by counting the frequency of each digit and compare it to the signatures of all powers of 2.

4. **Digit counting**: A function (`counter`) is created to convert a number into a frequency signature based on its digits. We use this signature to check if any power of 2 has the same digit frequency as `n`.

### Code Breakdown (Step by Step)

#### Step 1: Function `reorderedPowerOf2`

```cpp
bool reorderedPowerOf2(int n) {
    int c = counter(n);  // Get the digit signature of the number
    for(int i = 0; i < 32; i++)  // Iterate through powers of 2
        if(counter(1 << i) == c)  // Check if any power of 2 has the same digit signature
            return true;
    return false;  // No match found
}
```

- We first compute the "signature" of the input number `n` using the `counter` function.
- We then loop through all the powers of 2 from `2^0` to `2^31`. For each power of 2 (`1 << i`), we check if its digit signature matches that of `n`.
- If a match is found, we return `true`, indicating that `n` can be reordered to form a power of 2. Otherwise, we return `false`.

#### Step 2: Function `counter`

```cpp
int counter(int N) {
    int res = 0;
    for (; N; N /= 10)  // Loop through the digits of N
        res += pow(10, N % 10);  // Add each digit as a place value
    return res;  // Return the computed signature
}
```

- This function computes the "digit signature" of the number `N`.
- We iterate over the digits of `N` by repeatedly dividing `N` by 10. For each digit, we use `pow(10, N % 10)` to create a unique number that represents the position of the digit.
- We sum these values to produce a unique signature that represents the digits of the number.
  
For example:
- `counter(122)` would return a value that represents the frequency of the digits `1`, `2`, and `2`.

#### Step 3: Comparing the Digit Signatures

In the main function `reorderedPowerOf2`, the `counter` function is used to get the digit signature of both `n` and each power of 2. If any power of 2 has the same digit signature as `n`, the function returns `true`.

### Complexity

#### Time Complexity:
- **Generating powers of 2**: We loop over all powers of 2 from `2^0` to `2^30`, so there are 31 powers of 2 to check.
- **Counting digits for each power of 2**: For each power of 2, we compute its digit signature. In the worst case, a power of 2 could have 10 digits (e.g., `1073741824` for `2^30`).
- **Checking digit signature of `n`**: We also compute the digit signature for `n`.
  
Thus, the time complexity is `O(31 * D)`, where `D` is the number of digits in `n`. Since the maximum number of digits is around 10 (for `2^30`), the overall time complexity is approximately `O(310)` which is constant.

#### Space Complexity:
- The space complexity is `O(1)` because we are only using a few integer variables (`c`, `res`) and we are not using any additional data structures that grow with the input size. The space used to store the powers of 2 is constant as well.

### Conclusion

The algorithm effectively solves the problem of determining whether a number `n` can be reordered to form a power of 2. It uses a "digit signature" approach, where we compute a unique identifier for the digits of both `n` and the powers of 2. By comparing these signatures, we can efficiently check if any permutation of the digits of `n` can form a power of 2.

Key Points:
- **Digit Signature**: The main idea is to compute a "signature" for the digits of a number. This allows us to avoid checking all permutations of the digits.
- **Efficient Checking**: By only comparing digit signatures instead of checking permutations directly, we reduce the time complexity significantly.
- **Optimal Complexity**: The time complexity is constant in practice, making this solution highly efficient even for large inputs.

This solution demonstrates an elegant way to solve a problem by leveraging digit manipulation and frequency counting to avoid costly operations like generating permutations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/reordered-power-of-2/description/)

---
{{< youtube rJu123dgDy8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
