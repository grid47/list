
+++
authors = ["grid47"]
title = "Leetcode 2826: Sorting Three Groups"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2826: Sorting Three Groups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Q3wrIhMmpfA"
youtube_upload_date="2023-08-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Q3wrIhMmpfA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(vector<int>& A) {
        int a = 0, b = 0, c = 0;
        for (int x: A) {
            a += x != 1;
            b = min(a, b + (x != 2));
            c = min(b, c + (x != 3));
        }
        return c;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires determining the minimum number of operations required to convert a given array `A` into an array of only 1s, 2s, and 3s. In each operation, you can replace any element of the array with either 1, 2, or 3. The goal is to minimize the number of replacements.

- The given array `A` consists of integers, and we are allowed to replace elements with values `1`, `2`, or `3`.
- We need to calculate the minimum number of changes needed to ensure that the entire array consists only of `1`s, `2`s, and `3`s.

### Approach

This problem can be approached using dynamic programming, where we track the minimum number of operations needed to transform the array step by step. The solution takes into account the following observations:

- **State Variables**: We define three variables, `a`, `b`, and `c`, to represent the minimum number of operations required to transform the array into:
  - `a`: An array consisting entirely of `1`s.
  - `b`: An array consisting entirely of `1`s and `2`s.
  - `c`: An array consisting entirely of `1`s, `2`s, and `3`s.
  
- **Transition Logic**:
  - The variable `a` counts how many times a value in `A` is not equal to 1, and the number of operations increases as we move through the array.
  - The variable `b` ensures that we can have the array consisting of `1`s and `2`s. If the value in the array is not `2`, we increment the operations.
  - Similarly, the variable `c` ensures the array consists of `1`s, `2`s, and `3`s, where we increment the operations when the value is not `3`.
  
- **Dynamic Programming Transition**: As we traverse the array, at each step:
  - We calculate the minimum operations needed to replace any element that is not `1`, `2`, or `3`, by using `min()` functions to propagate the optimal solution.

By the end of the traversal, the variable `c` will hold the minimum number of operations required to transform the entire array into an array of only `1`s, `2`s, and `3`s.

### Code Breakdown (Step by Step)

```cpp
int minimumOperations(vector<int>& A) {
```
1. **Function Declaration**: The function `minimumOperations` takes a vector of integers `A` as input, representing the given array.

```cpp
    int a = 0, b = 0, c = 0;
```
2. **Initialization**:
   - `a`, `b`, and `c` are initialized to 0. These will track the minimum operations needed to transform the array to various forms as described earlier (i.e., `1`s, `1`s and `2`s, `1`s, `2`s, and `3`s).

```cpp
    for (int x: A) {
```
3. **Iterating Over Array `A`**: A loop is used to iterate over each element `x` of the array `A`.

```cpp
        a += x != 1;
```
4. **Updating `a`**:
   - `a` is incremented whenever the current element `x` is not equal to 1. This operation tracks the minimum operations required to convert the array to an array of `1`s.

```cpp
        b = min(a, b + (x != 2));
```
5. **Updating `b`**:
   - `b` is updated to the minimum of `a` and `b + (x != 2)`. This means that if the current element `x` is not equal to 2, the number of operations needed to transform the array into `1`s and `2`s is incremented. The `min()` ensures we choose the fewer operations between keeping `b` as is or adding one more operation to transform `x` into `2`.

```cpp
        c = min(b, c + (x != 3));
```
6. **Updating `c`**:
   - Similarly, `c` is updated to the minimum of `b` and `c + (x != 3)`. If the current element `x` is not equal to 3, we increment the operation count for transforming the array into `1`s, `2`s, and `3`s.

```cpp
    }
```
7. **Loop Completion**: The loop completes after iterating through all elements in the array.

```cpp
    return c;
```
8. **Return Result**:
   - The final result is the value of `c`, which represents the minimum number of operations needed to convert the entire array into an array consisting of only `1`s, `2`s, and `3`s.

### Complexity

1. **Time Complexity**:
   - The time complexity of this solution is **O(n)**, where `n` is the length of the input array `A`. The algorithm iterates through the array once, making a constant-time check for each element and updating the variables `a`, `b`, and `c`. Therefore, the overall time complexity is linear in terms of the size of the input array.

2. **Space Complexity**:
   - The space complexity is **O(1)**, as the algorithm uses only a constant amount of extra space (three variables: `a`, `b`, and `c`) to store the intermediate results. The solution does not use any additional data structures whose size depends on the input, making it space-efficient.

### Conclusion

The problem at hand is solved efficiently using dynamic programming principles. By keeping track of three variables (`a`, `b`, and `c`), the solution dynamically adjusts the minimum operations required as we traverse the array. The approach ensures that the solution is both time-efficient (with a linear time complexity) and space-efficient (constant space complexity).

The solution essentially transforms the problem into a series of optimal subproblems that progressively build up the result, making it a perfect candidate for dynamic programming. The `min()` function is a key tool in ensuring that we always take the optimal number of operations at each step. This method is both simple and effective for transforming arrays with constraints on allowable values.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sorting-three-groups/description/)

---
{{< youtube Q3wrIhMmpfA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
