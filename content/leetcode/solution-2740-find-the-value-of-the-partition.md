
+++
authors = ["grid47"]
title = "Leetcode 2740: Find the Value of the Partition"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2740: Find the Value of the Partition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WeaM8AiavbY"
youtube_upload_date="2023-06-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/WeaM8AiavbY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = nums[1] - nums[0];
        for(int i = 1; i < nums.size(); i++) {
            res = min(nums[i] - nums[i - 1], res);
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the minimum difference between any two adjacent elements in the array after sorting it. Specifically, we are given a list of integers, and the task is to return the smallest difference between any two numbers in the sorted version of the array. This problem is typically useful for applications like optimizing resource allocation, determining range spans, or analyzing ordered data for efficient operations.

### Approach

To solve this problem, we can follow a structured approach:

1. **Sorting the Array**:
   - The main idea behind this approach is that the smallest difference between any two elements in the array will always occur between adjacent elements when the array is sorted. This is because, in a sorted array, the values that are closest to each other will be placed next to each other.

2. **Calculate the Difference Between Adjacent Elements**:
   - Once the array is sorted, the next step is to traverse through the sorted array and compute the difference between every two consecutive elements.

3. **Keep Track of the Minimum Difference**:
   - As we compute the differences, we keep track of the smallest one. This can be done using a simple comparison mechanism that updates the minimum difference as we progress through the array.

### Code Breakdown (Step by Step)

Let’s break down the code line by line:

```cpp
int findValueOfPartition(vector<int>& nums) {
    sort(nums.begin(), nums.end());
```

- **Sorting the Array**:
  - The `sort` function is used to sort the array in ascending order. This ensures that the smallest and closest numbers in terms of magnitude are placed next to each other, making it easier to find the minimum difference.
  - Sorting the array is the first and necessary step to ensure that adjacent numbers in the array will have the smallest possible differences.

```cpp
    int res = nums[1] - nums[0];
```

- **Initial Minimum Difference**:
  - After sorting, the difference between the first two elements (`nums[1] - nums[0]`) is calculated and stored in the variable `res`. This is the starting value of the minimum difference.
  - At this point, we assume that the smallest difference is between the first two elements, as this is the only comparison we can make initially.

```cpp
    for(int i = 1; i < nums.size(); i++) {
        res = min(nums[i] - nums[i - 1], res);
    }
```

- **Iterating and Updating the Minimum Difference**:
  - A `for` loop iterates over the array starting from the second element (`i = 1`) up to the end of the array.
  - Inside the loop, the difference between each adjacent pair of numbers (`nums[i] - nums[i - 1]`) is calculated. This is the key part of the algorithm where we compare each adjacent pair of numbers in the sorted array.
  - The `min` function is used to keep track of the smallest difference encountered so far. At each iteration, we update `res` to hold the smaller value between the current difference and the previously stored minimum difference.

```cpp
    return res;
}
```

- **Return the Result**:
  - After the loop finishes, the variable `res` will hold the smallest difference between any two adjacent numbers in the sorted array.
  - The function returns `res` as the final result.

### Complexity Analysis

#### Time Complexity

1. **Sorting the Array**:
   - The `sort` function has a time complexity of \( O(n \log n) \), where \( n \) is the size of the input array. Sorting is the most time-consuming operation in this approach.

2. **Iterating Over the Array**:
   - The `for` loop runs once for each element in the array, so the time complexity of this step is \( O(n) \), where \( n \) is the size of the array.

Thus, the overall time complexity of the algorithm is dominated by the sorting step, resulting in \( O(n \log n) \).

#### Space Complexity

- The algorithm does not use any extra data structures that grow with the size of the input. It only uses a few variables (`res`, `i`), all of which take constant space.
- Thus, the space complexity is \( O(1) \), meaning the algorithm uses constant extra space.

### Conclusion

The solution efficiently solves the problem of finding the minimum difference between adjacent elements in an array by first sorting the array and then iterating over it to compute the differences. Sorting ensures that the closest values are adjacent, making it easy to find the minimum difference. The approach is optimal with a time complexity of \( O(n \log n) \), which is suitable for typical input sizes.

- **Time Complexity**: \( O(n \log n) \), where `n` is the size of the input array.
- **Space Complexity**: \( O(1) \), as the solution only uses a fixed amount of extra space.

This method is simple, intuitive, and runs efficiently for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-value-of-the-partition/description/)

---
{{< youtube WeaM8AiavbY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
