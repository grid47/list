
+++
authors = ["grid47"]
title = "Leetcode 2535: Difference Between Element Sum and Digit Sum of an Array"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2535: Difference Between Element Sum and Digit Sum of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wg-szN5zvr4"
youtube_upload_date="2023-01-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wg-szN5zvr4/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int dsum(int v) {
    return v == 0 ? 0 : v % 10 + dsum(v / 10);
}
int differenceOfSum(vector<int>& n) {
    return abs(accumulate(begin(n), end(n), 0) - 
        accumulate(begin(n), end(n), 0, [&](int s, int v){ return s + dsum(v); }));
}
};
{{< /highlight >}}
---

### Problem Statement

The problem requires calculating the absolute difference between the sum of elements in an array and the sum of the sum of digits of each element in the array. Specifically, given an array of integers, we need to compute:

1. **The sum of the array elements**.
2. **The sum of the digits of each element** (for each number, we sum its digits and then sum those results across all the numbers).
3. **The absolute difference** between the two sums.

The task is to compute this difference and return it.

### Approach

To solve this problem, we need to break it into two main parts:

1. **Sum of elements**: The sum of elements in the given array is straightforward to calculate using the `accumulate` function in C++.
   
2. **Sum of digits of elements**: For each number in the array, we need to calculate the sum of its digits. This can be done using a recursive approach.

Once both sums are computed, we can simply return the absolute difference between the two sums.

### Code Breakdown (Step by Step)

#### 1. **Recursive Function to Compute Sum of Digits**

```cpp
int dsum(int v) {
    return v == 0 ? 0 : v % 10 + dsum(v / 10);
}
```

- This function, `dsum`, computes the sum of the digits of a number recursively.
- The base case is when the number `v` is 0. If `v` is 0, the function returns 0, as the sum of digits of 0 is 0.
- In the recursive case, the function computes the last digit of the number using `v % 10` and adds it to the result of recursively calling `dsum(v / 10)`. This effectively breaks down the number by removing the last digit at each recursive step.
- For example, for `v = 123`, the function will compute `1 + 2 + 3 = 6`.

#### 2. **Calculating the Absolute Difference**

```cpp
int differenceOfSum(vector<int>& n) {
    return abs(accumulate(begin(n), end(n), 0) - 
               accumulate(begin(n), end(n), 0, [&](int s, int v){ return s + dsum(v); }));
}
```

- The function `differenceOfSum` calculates the absolute difference between the sum of the elements in the array and the sum of the digits of those elements.
  
- **Sum of elements**: `accumulate(begin(n), end(n), 0)` calculates the sum of all the elements in the array `n`. The `accumulate` function is used here, which is a standard C++ algorithm to sum the elements of a range (from `begin(n)` to `end(n)`), starting from an initial sum of 0.
  
- **Sum of digits of elements**: `accumulate(begin(n), end(n), 0, [&](int s, int v){ return s + dsum(v); })` calculates the sum of the sum of digits of each element in the array `n`. Here:
  - The `accumulate` function is again used, but this time with a custom lambda function. The lambda function computes the sum of digits of each number `v` by calling `dsum(v)`.
  - The lambda accumulates the sum of digits for each element in the array.
  
- **Absolute Difference**: Finally, the absolute difference between the sum of the elements and the sum of the sum of digits is calculated using `abs()`. This function ensures that the result is always a non-negative value, as we are interested in the magnitude of the difference, regardless of which sum is larger.

#### 3. **Final Return**

- The function returns the absolute difference between the two sums, as required by the problem statement.

### Complexity Analysis

#### Time Complexity

- **Sum of Elements**: The first `accumulate` function, which computes the sum of the elements, iterates through the entire array once. The time complexity for this step is \( O(n) \), where \( n \) is the number of elements in the array.
  
- **Sum of Digits**: The second `accumulate` function involves iterating over the array and, for each element, calculating the sum of its digits using the recursive `dsum` function.
  - The time complexity of `dsum(v)` depends on the number of digits in the number `v`. If `v` has \( d \) digits, then the time complexity of `dsum(v)` is \( O(d) \).
  - For each element, the `dsum` function is called, and if we assume the maximum number of digits in any number is \( D \), the overall time complexity for computing the sum of digits is \( O(n \cdot D) \), where \( n \) is the number of elements in the array and \( D \) is the number of digits in the largest number in the array.

- **Overall Time Complexity**: The total time complexity is \( O(n \cdot D) \), where \( n \) is the size of the array and \( D \) is the maximum number of digits in any element of the array.

#### Space Complexity

- **Auxiliary Space for Sum of Digits**: The `dsum` function uses recursion. The maximum depth of the recursion depends on the number of digits in the largest number. Thus, the space complexity for recursion is \( O(D) \), where \( D \) is the number of digits in the largest number in the array.
  
- **Overall Space Complexity**: The overall space complexity is \( O(D) \), as the space required for recursion dominates.

### Conclusion

This solution efficiently computes the absolute difference between the sum of the elements in the array and the sum of the sum of digits of each element. By utilizing the `accumulate` function and a recursive approach to calculate the sum of digits, the code is both clean and efficient. The primary time complexity arises from iterating through the elements of the array and calculating the sum of digits, which makes it suitable for arrays with relatively small numbers. However, for larger numbers with many digits, the solution still remains feasible due to its recursive nature.

[`Link to LeetCode Lab`](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/)

---
{{< youtube wg-szN5zvr4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
