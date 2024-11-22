
+++
authors = ["grid47"]
title = "Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores"
date = "2024-04-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "JU5XdBZZtlk"
youtube_upload_date="2021-08-29"
youtube_thumbnail="https://i.ytimg.com/vi/JU5XdBZZtlk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int minimumDifference(vector<int>& nums, int k) {
    int res = INT_MAX;
    sort(begin(nums), end(nums));
    for (int i = k - 1; i < nums.size(); ++i)
        res = min(res, nums[i] - nums[i - k + 1]);
    return res;
}
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the minimum difference between the maximum and minimum elements in any subarray of size `k` from a given array of integers `nums`. The goal is to determine the smallest range that can be achieved by selecting `k` contiguous elements from the sorted version of the array.

### Approach

To achieve the solution, we will utilize the following approach:
1. **Sorting**: First, sort the input array. This step is crucial because it allows us to efficiently find the minimum difference between the largest and smallest numbers in any group of `k` contiguous elements.
2. **Sliding Window Technique**: After sorting, we will use a sliding window of size `k` to compute the difference between the maximum and minimum values within that window. The maximum value will be the last element of the current window, and the minimum value will be the first element.
3. **Iterating**: By iterating through the sorted array and updating the minimum difference, we can derive the desired result.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
```
The `Solution` class encapsulates the function that will solve the problem.

```cpp
int minimumDifference(vector<int>& nums, int k) {
```
The method `minimumDifference` is defined to take a vector of integers (`nums`) and an integer (`k`) representing the size of the subarrays.

```cpp
    int res = INT_MAX;
```
The variable `res` is initialized to `INT_MAX` to store the minimum difference found during the iterations.

```cpp
    sort(begin(nums), end(nums));
```
We sort the `nums` array in non-decreasing order. This enables easy access to the smallest and largest values in any contiguous subarray of size `k`.

```cpp
    for (int i = k - 1; i < nums.size(); ++i)
```
This loop iterates from the `k-1` index to the end of the sorted array. The `k-1` index represents the last index of the first valid subarray of size `k`.

```cpp
        res = min(res, nums[i] - nums[i - k + 1]);
```
In each iteration, the difference between the maximum element (`nums[i]`) and the minimum element (`nums[i - k + 1]`) of the current window is calculated. The `min` function is then used to update `res` if a smaller difference is found.

```cpp
    return res;
}
```
Finally, the minimum difference found is returned.

### Complexity

- **Time Complexity**: The time complexity of the algorithm is dominated by the sorting step, which is \(O(n \log n)\), where \(n\) is the number of elements in `nums`. The subsequent loop runs in \(O(n)\) time, leading to an overall time complexity of \(O(n \log n)\).

- **Space Complexity**: The space complexity is \(O(1)\) if we consider the input array and only use a few additional variables, as sorting can be done in place.

### Conclusion

The solution efficiently finds the minimum difference between the maximum and minimum values in any contiguous subarray of size `k` by leveraging sorting and a sliding window approach. By sorting the array first, the problem is simplified to a linear pass to calculate differences, thus optimizing the overall complexity.

### Example Usage

Here’s an example of how you can utilize the `minimumDifference` method:

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 9, 13, 15};
    int k = 3;
    int result = sol.minimumDifference(nums, k);
    cout << "The minimum difference is: " << result << endl; // Example output
    return 0;
}
```

### Potential Improvements

1. **Early Exit**: If `k` is greater than the number of elements in `nums`, an early exit could be implemented with a return statement indicating an error or invalid input.
  
2. **Handling Edge Cases**: Additional checks could be included to handle edge cases such as an empty array or when `k` is equal to 0.

3. **Optimize for Larger Inputs**: For very large inputs, considerations could be made regarding the efficiency of the sorting algorithm and potential parallelization.

By combining sorting with a simple calculation, the solution maintains clarity and efficiency, making it suitable for competitive programming and real-world applications where performance matters.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/)

---
{{< youtube JU5XdBZZtlk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
