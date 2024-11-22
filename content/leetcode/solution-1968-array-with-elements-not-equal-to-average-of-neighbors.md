
+++
authors = ["grid47"]
title = "Leetcode 1968: Array With Elements Not Equal to Average of Neighbors"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1968: Array With Elements Not Equal to Average of Neighbors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Wmb3YdVYfqM"
youtube_upload_date="2021-08-15"
youtube_thumbnail="https://i.ytimg.com/vi/Wmb3YdVYfqM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        
        #define A(i) nums[(1 + 2 * i) % (n|1)]
        
        int i = 0, j = 0, k = n - 1;
        
        while(j <= k) {
            if(A(j) < mid)
                swap(A(j), A(k--));
            else if(A(j) > mid)
                swap(A(i++), A(j++));
            else j++;
        }
        return nums;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to rearrange an array of integers such that elements at even indices are non-negative, and elements at odd indices are negative. The array must be rearranged in a way that maintains the relative order of the numbers while ensuring that the specified conditions are met.

### Approach

To achieve this rearrangement, we can follow a three-step process:

1. **Partitioning the Array**: First, we will find a median value that will help us divide the numbers into two groups: those less than the median and those greater than or equal to the median.

2. **Rearranging Elements**: We will use the median to rearrange the elements in a specific pattern where:
   - Elements at even indices will be non-negative.
   - Elements at odd indices will be negative.

3. **Utilizing Indices Effectively**: We can achieve this by carefully swapping elements based on their current value relative to the median, ensuring that we maintain the correct order as we rearrange the array.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
```
This line defines the `Solution` class, which will contain the method to rearrange the array.

```cpp
    vector<int> rearrangeArray(vector<int>& nums) {
```
The `rearrangeArray` method takes a reference to a vector of integers `nums` as its parameter.

```cpp
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
```
Here, we start by determining the size of the input array `n`. We then create a pointer `midptr` that points to the middle element of the array. The `nth_element` function is used to rearrange the array such that all elements before `midptr` are less than or equal to the element pointed to by `midptr`, effectively finding a median. The median value is stored in `mid`.

```cpp
        #define A(i) nums[(1 + 2 * i) % (n|1)]
```
We define a macro `A(i)` that allows us to access the elements of `nums` at the desired rearranged positions. This ensures that the elements are accessed in the order required to satisfy the even/odd index conditions.

```cpp
        int i = 0, j = 0, k = n - 1;
```
We initialize three index variables:
- `i` will track the position of the next non-negative element (to be placed at even indices).
- `j` will be used to iterate through the array.
- `k` will track the position of the next negative element (to be placed at odd indices).

```cpp
        while(j <= k) {
```
We begin a loop that continues until the `j` index exceeds the `k` index.

```cpp
            if(A(j) < mid)
                swap(A(j), A(k--));
```
If the current element at index `j` is less than the median, we swap it with the element at index `k` (which will be a negative element) and decrement `k`.

```cpp
            else if(A(j) > mid)
                swap(A(i++), A(j++));
```
If the current element at index `j` is greater than the median, we swap it with the element at index `i` (which will be a non-negative element) and increment both `i` and `j`.

```cpp
            else j++;
```
If the current element equals the median, we simply move the `j` index forward without making any swaps.

```cpp
        }
        return nums;
    }
};
```
Finally, once the loop is finished, we return the rearranged `nums` array.

### Complexity

- **Time Complexity**: The overall time complexity of this algorithm is \(O(n)\) due to the linear partitioning operation performed by `nth_element`, which rearranges the elements in linear time.

- **Space Complexity**: The space complexity is \(O(1)\) since we are using a fixed amount of extra space for the indices and no additional data structures are required.

### Conclusion

The `rearrangeArray` function provides an efficient and effective way to rearrange an array such that all non-negative numbers are positioned at even indices and all negative numbers at odd indices. By utilizing the median as a pivot, we ensure that the rearrangement is done in a single pass through the array after partitioning, which makes this solution optimal for this problem.

### Key Features

1. **Optimal Partitioning**: The use of `nth_element` allows us to find the median efficiently, ensuring that the elements are divided properly.

2. **Index Management**: The macro `A(i)` simplifies the indexing logic, making the rearrangement of elements clear and straightforward.

3. **Single Pass Rearrangement**: The algorithm rearranges the elements in a single traversal of the array, ensuring efficiency in terms of time complexity.

### Example Usage

Here's how you can utilize the `rearrangeArray` function in practice:

```cpp
Solution sol;
vector<int> nums = {1, -1, 2, -2, 3, -3};
vector<int> result = sol.rearrangeArray(nums);
for(int num : result) {
    cout << num << " "; // Output may vary based on input
}
```

In this example, we create an instance of the `Solution` class, define a vector of integers that includes both non-negative and negative numbers, and call the `rearrangeArray` method. The output will show the rearranged array with the required properties.

### Potential Improvements and Variations

While the current implementation effectively solves the problem, there may be further optimizations or adjustments that could be explored based on specific constraints or additional requirements:

1. **Handling Edge Cases**: The solution could be adjusted to handle arrays with an unequal number of negative and non-negative elements more explicitly, ensuring the output format remains consistent.

2. **Alternative Algorithms**: Exploring different partitioning algorithms or rearrangement strategies could lead to different performance characteristics or use cases.

3. **Adaptability**: The approach can be adapted to work with other similar problems that require rearrangement based on specific conditions, such as sorting or grouping elements by certain criteria.

This solution demonstrates the use of efficient algorithms and techniques to solve problems involving rearrangement and partitioning, making it a valuable method in competitive programming and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/description/)

---
{{< youtube Wmb3YdVYfqM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
