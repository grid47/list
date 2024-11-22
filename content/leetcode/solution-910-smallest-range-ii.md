
+++
authors = ["grid47"]
title = "Leetcode 910: Smallest Range II"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 910: Smallest Range II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Sorting"]
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
    int smallestRangeII(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = nums[0] + k, right = nums[n - 1] - k;
        
        int res = nums[n - 1] - nums[0];
        for(int i = 0; i < n - 1; i++) {
            int maxi = max(nums[i] + k, right);
            int mini = min(nums[i + 1] - k, left);
            res = min(res, maxi - mini);
        }
        
        return res;
    }
    
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given an array of integers `nums` and an integer `k`. Your task is to return the **smallest possible range** that can be obtained by modifying the elements of the array. You can either increase or decrease each element of the array by at most `k` in order to minimize the difference between the maximum and minimum values in the array.

### Approach

The main goal is to reduce the difference between the maximum and minimum values of the array by modifying the elements. The most efficient way to do this is to exploit the properties of sorted arrays and the constraints provided by the problem. Below is a step-by-step breakdown of how we can solve this problem:

1. **Sort the Array**: 
   Sorting the array will allow us to identify the smallest and largest values easily. The main idea behind sorting is that the optimal solution to minimizing the range will involve modifying the largest and smallest elements in the array.

2. **Calculate the Initial Range**: 
   After sorting, the difference between the largest and smallest element gives the initial range. The goal is to reduce this range by adjusting the numbers with the given `k`.

3. **Modify Elements Within the Range**:
   After sorting the array, the two key actions to minimize the range are:
   - **Increasing the smallest values** by `k` to push them toward the larger values.
   - **Decreasing the largest values** by `k` to pull them down toward the smaller values.
   By adjusting both ends of the sorted array, we can explore possible ranges.

4. **Iterate to Find the Minimum Range**: 
   Iterate through the array, adjusting the `i-th` element and the `(i+1)-th` element and compute the possible maximum and minimum values. The range for each split is calculated by:
   - **Maximizing** the current value at position `i` increased by `k`, and the last value (position `n-1`) decreased by `k`.
   - **Minimizing** the next value at position `i+1` decreased by `k`, and the first value (position `0`) increased by `k`.

   This approach ensures that we explore all potential ways to adjust the range by modifying elements optimally.

### Code Breakdown (Step by Step)

#### **Sorting the Array**

```cpp
sort(nums.begin(), nums.end());
```
- First, we sort the array `nums` in ascending order. Sorting allows us to easily work with the smallest and largest elements in the array. The first element (`nums[0]`) represents the smallest value, and the last element (`nums[n-1]`) represents the largest value.

#### **Initial Range Calculation**

```cpp
int n = nums.size(), left = nums[0] + k, right = nums[n - 1] - k;
```
- We initialize `n` as the size of the array.
- The `left` value represents the smallest possible value we can achieve by adding `k` to the smallest element (`nums[0]`).
- The `right` value represents the largest possible value we can achieve by subtracting `k` from the largest element (`nums[n-1]`).

#### **Initial Range (Difference Between Largest and Smallest Elements)**

```cpp
int res = nums[n - 1] - nums[0];
```
- We calculate the initial range as the difference between the largest and smallest elements in the array, `nums[n-1] - nums[0]`.

#### **Iterate Through the Array to Minimize the Range**

```cpp
for (int i = 0; i < n - 1; i++) {
    int maxi = max(nums[i] + k, right);
    int mini = min(nums[i + 1] - k, left);
    res = min(res, maxi - mini);
}
```
- We iterate through the array and consider adjusting each element.
- For each element `i`, we calculate:
  - **`maxi`**: The maximum value after adjusting the current element at index `i`. This is calculated as `max(nums[i] + k, right)`, where `nums[i] + k` represents the value of the `i-th` element increased by `k`, and `right` represents the current largest possible value (after adjusting the largest element).
  - **`mini`**: The minimum value after adjusting the next element (`i+1`). This is calculated as `min(nums[i + 1] - k, left)`, where `nums[i + 1] - k` represents the value of the `i+1-th` element decreased by `k`, and `left` represents the current smallest possible value (after adjusting the smallest element).

- Finally, we update the result `res` with the minimum of the current `res` and `maxi - mini`, which represents the current range.

#### **Return the Result**

```cpp
return res;
```
- After iterating through all possible splits and adjusting the elements optimally, we return `res`, which holds the minimum possible range that can be achieved.

### Complexity

#### **Time Complexity**

- **O(n log n)**: The time complexity is dominated by the sorting step, which takes \(O(n \log n)\). After sorting, the iteration through the array takes linear time \(O(n)\), so the overall time complexity is \(O(n \log n)\).

#### **Space Complexity**

- **O(1)**: The space complexity is constant because we are only using a few extra variables (`res`, `left`, `right`) to store intermediate results. The input array is modified in place, so no additional space is required beyond the input.

### Conclusion

This approach efficiently minimizes the range between the maximum and minimum values of the array by optimally adjusting the elements with the given `k`. By sorting the array and adjusting both ends of the array, we ensure that we find the smallest possible range with minimal computations. The time complexity of \(O(n \log n)\) ensures that the solution can handle larger arrays efficiently. This solution provides an elegant and optimal approach to solving the problem of minimizing the range in the Snakes and Ladders game while adhering to the given constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-range-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
