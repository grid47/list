
+++
authors = ["grid47"]
title = "Leetcode 1300: Sum of Mutated Array Closest to Target"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1300: Sum of Mutated Array Closest to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
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
    int findBestValue(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        
        int n = A.size(), i = 0;
        while(i < n && target > A[i] * (n - i)) {
            target -= A[i++];
        }
        
        if (i == n) return A[n - 1];
        
        int res = target / (n - i);
        
        if (target - res * (n - i) > (res + 1) * (n - i) - target)
            res++;
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The task is to find the best value that can replace all elements in an array such that the sum of the modified array is as close to a given target as possible. Specifically, if you replace all elements in the array with a value `x`, the resulting array's sum should ideally equal `target`. However, you want to minimize the absolute difference between the actual sum and the target.

The goal is to determine the optimal integer `x` such that replacing all elements of the array `A` with `x` yields the sum closest to the `target`. If there are two values that yield the same difference, return the smaller one.

### Approach
To solve the problem, we can follow these steps:

1. **Sorting the Array**: Begin by sorting the array `A` to facilitate the determination of how many elements can be replaced without exceeding the target.

2. **Iterate Through the Sorted Array**: We will maintain a cumulative sum of the elements processed so far and check if replacing the remaining elements with the current element value exceeds the target.

3. **Determine the Best Value**:
   - If we reach the end of the array and the sum is less than the target, the best value would be the maximum value in the array.
   - If not, calculate the average of the remaining elements that can be replaced. Depending on how the remaining target compares to this average, we can determine whether to round down or up to find the best value.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
```
- **Line 1-2**: The `Solution` class is defined, and the `findBestValue` method begins. It takes a vector `A` and an integer `target` as input.

```cpp
        sort(A.begin(), A.end());
```
- **Line 3**: Sort the array `A` in non-decreasing order. This will help in determining how many elements can be replaced while keeping the sum under the target.

```cpp
        int n = A.size(), i = 0;
```
- **Line 4**: Initialize `n` as the size of the array `A` and `i` as an index to iterate through the array.

```cpp
        while(i < n && target > A[i] * (n - i)) {
            target -= A[i++];
        }
```
- **Lines 5-7**: This while loop checks two conditions:
  - `i < n`: Ensure we don't exceed the bounds of the array.
  - `target > A[i] * (n - i)`: Check if the remaining target is greater than the maximum possible sum if the current element and all subsequent elements were set to `A[i]`.
  
  If both conditions are satisfied, subtract the current element `A[i]` from `target` and increment the index `i`.

```cpp
        if (i == n) return A[n - 1];
```
- **Line 8**: If `i` reaches `n`, it means we have considered all elements in `A`. In this case, the best value is simply the maximum value of the array, `A[n - 1]`, as replacing all values with the maximum will not exceed the target.

```cpp
        int res = target / (n - i);
```
- **Line 9**: Calculate the base result `res`, which is the integer division of the remaining target by the number of elements left to consider, `n - i`. This gives us an average value for the remaining elements.

```cpp
        if (target - res * (n - i) > (res + 1) * (n - i) - target)
            res++;
```
- **Lines 10-12**: Here we check whether increasing `res` by one will yield a closer sum to the target. The condition checks if the difference between the remaining target and the product of `res` with the number of remaining elements is greater than the difference produced by using `res + 1`. If true, we increment `res`.

```cpp
        return res;
    }
};
```
- **Lines 13-14**: Finally, return `res`, which represents the best value that can be used to replace elements in the array `A` to achieve the target sum as closely as possible.

### Complexity Analysis
1. **Time Complexity**:
   - The sorting operation takes \(O(n \log n)\), where \(n\) is the number of elements in the array. The subsequent loop for processing the elements is \(O(n)\). Thus, the overall time complexity is dominated by the sorting step, leading to a total time complexity of \(O(n \log n)\).

2. **Space Complexity**:
   - The space complexity is \(O(1)\) since we are using only a few extra variables and no significant additional data structures that scale with input size.

### Conclusion
The `findBestValue` function provides an efficient solution to determine the optimal value to replace all elements in an array while ensuring the total sum is as close to a specified target as possible. By leveraging sorting and a greedy approach to iterate through the sorted values, the function efficiently calculates the best possible replacement value.

This implementation exemplifies the use of sorting and cumulative analysis in solving numerical optimization problems, showcasing the importance of algorithmic thinking in competitive programming and real-world applications. With a robust time complexity, the solution is both efficient and effective, making it suitable for larger datasets typically encountered in practical scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
