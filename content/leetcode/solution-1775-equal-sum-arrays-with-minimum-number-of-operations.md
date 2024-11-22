
+++
authors = ["grid47"]
title = "Leetcode 1775: Equal Sum Arrays With Minimum Number of Operations"
date = "2024-05-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1775: Equal Sum Arrays With Minimum Number of Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "n-BwszD77og"
youtube_upload_date="2021-02-28"
youtube_thumbnail="https://i.ytimg.com/vi/n-BwszD77og/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() > 6*nums2.size() || 
            nums2.size() > 6*nums1.size())
            return -1;
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if(sum1 > sum2) return minOperations(nums2, nums1);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = nums2.size() - 1, ops = 0;
        while(sum2 > sum1) {

            if(j < 0 || i < nums1.size() && 6 - nums1[i] > nums2[j] - 1) {
                sum1 += 6 - nums1[i++];
            } else {
                sum2 -= nums2[j--] - 1;
            }

            ++ops;
        }
        return ops;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to find the minimum number of operations required to make the sum of two integer arrays equal, where each operation allows you to modify an element of either array. Specifically, you can:
- Increase an element in `nums1` by up to 5 (since it can be increased to a maximum of 6).
- Decrease an element in `nums2` by up to 5 (since it can be decreased to a minimum of 1).

Given two integer arrays `nums1` and `nums2`, the task is to compute the minimum number of operations needed to equalize their sums, or return -1 if it's impossible to achieve the equality based on the constraints.

### Approach

The approach to solving this problem involves several key steps:

1. **Input Validation**: First, check if the sizes of the two arrays allow for possible adjustments. If either array is more than six times larger than the other, it’s impossible to equalize the sums through the allowed operations, and we return -1.

2. **Sum Calculation**: Calculate the total sums of both arrays, `sum1` for `nums1` and `sum2` for `nums2`.

3. **Ensure Order**: Ensure that `sum1` is less than or equal to `sum2` by swapping the arrays if necessary. This simplifies the logic since we only need to consider operations that increase `sum1` or decrease `sum2`.

4. **Sorting**: Sort both arrays. This helps in efficiently accessing the largest possible reductions from `nums2` and the smallest possible increases from `nums1`.

5. **Greedy Operations**: Utilize a greedy approach to perform operations:
   - Use a pointer `i` to traverse `nums1` from the smallest to the largest and a pointer `j` to traverse `nums2` from the largest to the smallest.
   - Determine whether to increase `sum1` or decrease `sum2` based on which operation yields the greater change towards achieving equality.
   - Continue performing operations until `sum1` is equal to or exceeds `sum2`.

6. **Count Operations**: Keep track of the number of operations performed and return this count once the sums are equalized.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
```
- A class `Solution` is defined with a public method `minOperations` that takes two vectors of integers, `nums1` and `nums2`.

```cpp
        if( nums1.size() > 6*nums2.size() || 
            nums2.size() > 6*nums1.size())
            return -1;
```
- The first condition checks if the size of `nums1` is more than six times the size of `nums2`, or vice versa. If either condition is true, it is impossible to equalize the sums through the allowed operations, so the method returns -1.

```cpp
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
```
- Here, the method calculates the total sums of both arrays using the `accumulate` function from the `<numeric>` library.

```cpp
        if(sum1 > sum2) return minOperations(nums2, nums1);
```
- If `sum1` is greater than `sum2`, the arrays are swapped to ensure that `sum1` is always the smaller sum. This reduces complexity in further operations.

```cpp
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
```
- Both arrays are sorted. `nums1` is sorted in ascending order and `nums2` in ascending order, allowing for efficient access to the smallest and largest elements respectively.

```cpp
        int i = 0, j = nums2.size() - 1, ops = 0;
```
- The variables `i` and `j` are initialized as pointers for traversing `nums1` and `nums2`, respectively. `ops` is initialized to count the number of operations.

```cpp
        while(sum2 > sum1) {
```
- The loop continues as long as `sum2` is greater than `sum1`.

```cpp
            if(j < 0 || i < nums1.size() && 6 - nums1[i] > nums2[j] - 1) {
                sum1 += 6 - nums1[i++];
            } else {
                sum2 -= nums2[j--] - 1;
            }
```
- The condition checks if:
  - `j < 0`: all elements in `nums2` have been considered for decreasing, or
  - The maximum possible increase to `sum1` (i.e., `6 - nums1[i]`) is greater than the maximum possible decrease from `sum2` (i.e., `nums2[j] - 1`).
  
- If either condition is true, `sum1` is increased using the next smallest element from `nums1`. Otherwise, the largest element in `nums2` is decreased to maximize the reduction of `sum2`.

```cpp
            ++ops;
        }
```
- After each operation (increase or decrease), the operation count `ops` is incremented.

```cpp
        return ops;
    }
};
```
- Finally, the method returns the total number of operations performed to equalize the sums.

### Complexity

- **Time Complexity**: 
  - The time complexity of the solution is \(O(n \log n + m \log m)\), where \(n\) is the size of `nums1` and \(m\) is the size of `nums2`. The logarithmic terms arise from sorting both arrays. The linear part comes from traversing the arrays to perform the necessary operations.

- **Space Complexity**: 
  - The space complexity is \(O(1)\) for the in-place operations and array modifications, assuming the input arrays do not require additional space for storage.

### Conclusion

The provided solution effectively solves the problem of equalizing the sums of two integer arrays with minimal operations by leveraging a greedy approach and sorting. By focusing on the largest potential changes and systematically applying operations, it ensures that the target condition is met efficiently. 

This code serves as a good reference for similar problems involving optimization through operations on arrays and is illustrative of how to approach problems that have constraints based on the properties of the data involved. The balance between clarity and efficiency in the implementation makes it a valuable example in algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/description/)

---
{{< youtube n-BwszD77og >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
