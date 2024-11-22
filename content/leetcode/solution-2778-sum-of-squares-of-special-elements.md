
+++
authors = ["grid47"]
title = "Leetcode 2778: Sum of Squares of Special Elements "
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2778: Sum of Squares of Special Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "7eI3tsBVCi4"
youtube_upload_date="2023-07-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/7eI3tsBVCi4/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            if(n % (i + 1) == 0) ans += nums[i] * nums[i];
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires calculating the sum of the squares of certain elements from an array based on their indices. Specifically, we need to find the sum of squares of elements at positions where the index (1-based) is a divisor of the size of the array.

### Approach

To solve this problem, we first identify the elements at indices that are divisors of the length of the array. We then square those elements and accumulate their sum. This approach ensures we only consider the elements whose indices meet the required condition.

1. **Identify Divisors**: The primary observation is that we need to consider the elements at positions `i` such that the index `i + 1` (1-based) divides the total size of the array `n`.
2. **Square the Elements**: For each identified index, we square the corresponding element and add it to the sum.

### Code Breakdown

#### Function: `sumOfSquares`

```cpp
int sumOfSquares(vector<int>& nums) {
```
- **Input**: The function takes a vector `nums` as input, which contains the elements of the array. 
- **Output**: It returns an integer, which is the sum of squares of elements at indices that are divisors of the array size.

```cpp
    int ans = 0;
    int n = nums.size();
```
- **`ans`**: This variable is initialized to zero and will store the final sum of the squares of the qualifying elements.
- **`n`**: The size of the array `nums` is stored in `n`, as we need it to determine the valid indices.

```cpp
    for(int i = 0; i < n; i++)
```
- **Loop Over Array**: This `for` loop iterates over each element of the array `nums`. The loop runs from `i = 0` to `i = n-1`, covering all indices of the array in a 0-based index system.

```cpp
        if(n % (i + 1) == 0) ans += nums[i] * nums[i];
```
- **Check Divisibility**: The condition `n % (i + 1) == 0` checks if the index `i + 1` (the 1-based index) divides `n` without a remainder. 
    - If `i + 1` is a divisor of `n`, we add the square of the element at index `i` to the answer. The square of the element is calculated as `nums[i] * nums[i]`.
    - This condition ensures that we only square and add elements whose indices meet the divisibility condition.
  
```cpp
    return ans;
}
```
- **Return Result**: After iterating through all the elements, the function returns the accumulated sum of squares as the result.

### Complexity

#### Time Complexity:
- **O(n)**: The algorithm makes a single pass over the array `nums` using a `for` loop, where `n` is the size of the array. The time complexity of the loop is O(n), and the operations inside the loop (modulus check and square calculation) take constant time.
  
#### Space Complexity:
- **O(1)**: The function uses only a constant amount of extra space for the variables `ans` and `n`, regardless of the size of the input array. The space complexity is O(1), which indicates that the function doesn't require additional space proportional to the input size.

### Conclusion

This solution efficiently computes the sum of squares of elements at specific indices in an array. By utilizing the modulus operation to check if an index is a divisor of the array size, the algorithm ensures that we only consider the elements that meet the required condition. The solution has a time complexity of **O(n)**, making it suitable for large input arrays, and a space complexity of **O(1)**, indicating minimal memory usage.

The approach is simple and straightforward, iterating over the array only once and performing constant-time operations at each step. It leverages the properties of divisors and indices to calculate the desired sum efficiently. This makes it an optimal solution for the given problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-squares-of-special-elements/description/)

---
{{< youtube 7eI3tsBVCi4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
