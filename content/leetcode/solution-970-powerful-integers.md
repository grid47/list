
+++
authors = ["grid47"]
title = "Leetcode 970: Powerful Integers"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 970: Powerful Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Enumeration"]
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
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for(int i = 1; i <= bound; i *= x) {
            for(int j = 1; i + j <= bound; j *= y) {
                s.insert(i + j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find all possible powerful integers, which are integers that can be written as the sum of powers of two integers `x` and `y`, where `x` and `y` are positive integers greater than or equal to 1, and the sum of these powers is less than or equal to a given bound. Specifically, the task is to return all unique integers that can be expressed as `x^i + y^j` such that the resulting number does not exceed the given `bound`.

For this problem, we are tasked to find all such values of `i` and `j` where:
- `x^i + y^j <= bound`
- The values of `x` and `y` are fixed.
- `i` and `j` are non-negative integers.

### Approach

The approach is based on brute-forcing the power values of `x` and `y` while ensuring that the sum of the powers does not exceed the `bound`. The main steps of the approach are:

1. **Iterate over powers of `x`**:
   - We start by iterating over all powers of `x` starting from `x^0 = 1` (the smallest power) up to the largest power of `x` that is still less than or equal to the `bound`. 
   - In each iteration, the current power of `x` is multiplied by `x`, generating the next power of `x`.

2. **Iterate over powers of `y`**:
   - For each power of `x`, we start iterating over the powers of `y`, from `y^0 = 1` and continue to calculate powers of `y` until the sum of the current power of `x` and the current power of `y` exceeds the `bound`.

3. **Store the results**:
   - If the sum of a power of `x` and a power of `y` is less than or equal to `bound`, we store that sum in an unordered set to ensure uniqueness. 
   - This ensures that we do not include duplicates in our result.

4. **Handle special cases**:
   - If `x == 1`, the powers of `x` will always be `1`, so we need to break out of the loop to avoid unnecessary calculations.
   - Similarly, if `y == 1`, the powers of `y` will always be `1`, and we only need to calculate sums involving `x`'s powers and `1`.

5. **Return the result**:
   - After processing all valid powers, we return the result as a vector containing all unique sums stored in the set.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
```
1. **Function Declaration**:
   - The function `powerfulIntegers` is defined to take three arguments: `x`, `y`, and `bound`. `x` and `y` are the base integers, and `bound` is the upper limit for the sum of the powers.

```cpp
        unordered_set<int> s;
```
2. **Unordered Set for Storing Unique Results**:
   - An unordered set `s` is used to store the unique sums of the form `x^i + y^j`. Using a set ensures that duplicate sums are not added, as the set automatically handles uniqueness.

```cpp
        for(int i = 1; i <= bound; i *= x) {
```
3. **Outer Loop for Powers of `x`**:
   - We begin the outer loop to iterate over the powers of `x`. Starting from `i = 1` (which represents `x^0`), we multiply `i` by `x` in each iteration. The loop continues until `i` exceeds the `bound`.
   - The condition `i <= bound` ensures that we stop iterating once `x^i` becomes greater than `bound`.

```cpp
            for(int j = 1; i + j <= bound; j *= y) {
```
4. **Inner Loop for Powers of `y`**:
   - For each power of `x`, we start an inner loop to iterate over the powers of `y`. Initially, `j = 1` represents `y^0`. We multiply `j` by `y` in each iteration, generating subsequent powers of `y`.
   - The loop continues as long as the sum of `i + j` is less than or equal to `bound`.

```cpp
                s.insert(i + j);
```
5. **Insert Sum into Set**:
   - For each valid pair of powers of `x` and `y` (i.e., where `i + j <= bound`), we insert the sum `i + j` into the set `s`. This ensures that only unique sums are stored, as the set does not allow duplicate values.

```cpp
                if(y == 1) break;
```
6. **Break if `y == 1`**:
   - If `y == 1`, the powers of `y` will always be `1` (since `y^j = 1` for all `j`). In this case, the inner loop will keep adding the same value (`i + 1`) to the set. Thus, we break the inner loop early to avoid redundant calculations.

```cpp
            if(x == 1) break;
```
7. **Break if `x == 1`**:
   - Similarly, if `x == 1`, the powers of `x` will always be `1` (since `x^i = 1` for all `i`). Thus, we break the outer loop early as further iterations of `i` will be unnecessary.

```cpp
        return vector<int>(s.begin(), s.end());
```
8. **Convert Set to Vector**:
   - After collecting all unique sums, we return the result as a vector. The unordered set `s` is converted to a vector using its iterator range (`s.begin()` to `s.end()`), and this vector is returned as the final result.

```cpp
    }
};
```
9. **End of Function and Class**:
   - The function ends, and the solution is complete.

### Complexity

- **Time Complexity**:
  - The time complexity is **O(log(bound) * log(bound))**, where `log(bound)` represents the number of iterations for `x^i` and `y^j` respectively. 
  - The outer loop runs for the powers of `x` (i.e., `log_x(bound)`), and for each power of `x`, the inner loop runs for the powers of `y` (i.e., `log_y(bound)`). Thus, the total time complexity is approximately the product of these two logarithms.

- **Space Complexity**:
  - The space complexity is **O(k)**, where `k` is the number of unique sums that are less than or equal to `bound`. This is because the unordered set `s` stores all unique results, and the resulting vector will also have a size of `k`.

### Conclusion

This solution efficiently computes all powerful integers that can be expressed as `x^i + y^j` without exceeding the given bound. By using nested loops for powers of `x` and `y`, and leveraging an unordered set to ensure uniqueness, the approach guarantees that only valid and unique sums are considered. The algorithm handles edge cases where either `x` or `y` is `1` by breaking early from loops, preventing unnecessary calculations. With logarithmic time complexity with respect to the bound, this solution is efficient and scalable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/powerful-integers/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
