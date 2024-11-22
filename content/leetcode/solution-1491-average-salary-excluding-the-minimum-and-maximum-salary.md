
+++
authors = ["grid47"]
title = "Leetcode 1491: Average Salary Excluding the Minimum and Maximum Salary"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1491: Average Salary Excluding the Minimum and Maximum Salary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "hTEVGYRGLsQ"
youtube_upload_date="2020-06-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/hTEVGYRGLsQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double average(vector<int>& nums) {
        int n = nums.size();
        double sum = 0, mx = nums[0], mn = nums[0];
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mx = max((double)nums[i], mx);
            mn = min((double)nums[i], mn);
        }
        return (sum - mx - mn) / (n - 2);
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to compute the average of an array of integers after removing the maximum and minimum values from the array. The average should be calculated based on the remaining elements, which means if the input array has less than three elements, it's impossible to compute the average in the required manner (since both the max and min would need to be removed). In such cases, the function should handle it gracefully, perhaps by returning a specific value or indicating the impossibility.

### Approach

To solve this problem, the solution follows these steps:

1. **Initialization**: Start by initializing variables to store the sum of elements, the maximum value, and the minimum value in the array.

2. **Iteration**: Loop through the array to calculate the sum of all elements, as well as to find the maximum and minimum values.

3. **Average Calculation**: After identifying the maximum and minimum values, calculate the average by subtracting these two values from the total sum and dividing by the count of the remaining elements.

4. **Return the Result**: Finally, return the computed average.

### Code Breakdown (Step by Step)

Let's break down the provided code snippet into manageable parts to understand how it functions:

```cpp
class Solution {
public:
    double average(vector<int>& nums) {
```
This defines the `Solution` class and its method `average`, which takes a vector of integers as input.

#### Step 1: Variable Initialization

```cpp
        int n = nums.size();
        double sum = 0, mx = nums[0], mn = nums[0];
```
- `n`: Stores the number of elements in the input vector `nums`.
- `sum`: Initializes the sum of the elements to zero.
- `mx` and `mn`: Set to the first element of the array, which will later be updated to reflect the maximum and minimum values respectively.

#### Step 2: Iteration and Calculating Sum, Max, and Min

```cpp
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mx = max((double)nums[i], mx);
            mn = min((double)nums[i], mn);
        }
```
- A loop iterates over each element in the `nums` array.
- In each iteration:
  - The current element `nums[i]` is added to `sum`.
  - The maximum value `mx` is updated using the `max` function, casting `nums[i]` to `double` to ensure correct type comparisons.
  - The minimum value `mn` is updated similarly using the `min` function.

#### Step 3: Calculating the Average

```cpp
        return (sum - mx - mn) / (n - 2);
    }
};
```
- The average is calculated by subtracting `mx` and `mn` from `sum` and then dividing the result by `(n - 2)`, which accounts for the two values that have been excluded (the maximum and minimum).
- Finally, the computed average is returned as a `double`.

### Complexity

#### Time Complexity
- The time complexity of this algorithm is **O(n)**, where `n` is the number of elements in the input array. This is because we iterate through the array once to calculate the sum, maximum, and minimum values.

#### Space Complexity
- The space complexity is **O(1)**, as the algorithm only uses a fixed amount of additional space for variables `sum`, `mx`, and `mn`, regardless of the input size.

### Conclusion

This solution effectively calculates the average of an array after excluding the maximum and minimum values. It uses a single pass through the array to gather the necessary information, ensuring efficiency in both time and space. 

**Key Points**:
- **Robustness**: The algorithm assumes the input array contains at least three elements. If it doesn't, the function should ideally handle such cases, perhaps by throwing an exception or returning a predefined value indicating the invalid input.
- **Performance**: The linear time complexity ensures that the function performs well even for large datasets, making it suitable for real-world applications.
- **Numerical Stability**: By using `double` for the calculations, the solution minimizes the risk of integer overflow, especially when dealing with large sums.

This method can be particularly useful in scenarios where data cleaning or preprocessing is needed before performing further statistical analysis, allowing for a cleaner representation of the data by focusing on the central tendencies after removing outliers.

[`Link to LeetCode Lab`](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/)

---
{{< youtube hTEVGYRGLsQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
