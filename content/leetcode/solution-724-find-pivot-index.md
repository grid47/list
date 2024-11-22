
+++
authors = ["grid47"]
title = "Leetcode 724: Find Pivot Index"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 724: Find Pivot Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/724.webp"
youtube = "u89i60lYx8U"
youtube_upload_date="2021-12-29"
youtube_thumbnail="https://i.ytimg.com/vi/u89i60lYx8U/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/724.webp" 
    alt="A number array where the pivot index is found, with the pivot glowing brightly as it’s identified."
    caption="Solution to LeetCode 724: Find Pivot Index Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i++) {
            right -= nums[i];
            if(right == left) return i;
            left  += nums[i];
        }
        return -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to find the **pivot index** of an array of integers. The pivot index is defined as the index where the sum of the elements to the left of it is equal to the sum of the elements to the right. If no such index exists, return -1.

### Approach

To solve this problem, we need to use an efficient approach that does not involve recalculating the left and right sums for each index, as that could lead to an O(n^2) time complexity. Instead, we can leverage the following strategy:

1. **Calculate Total Sum**: Start by calculating the total sum of the array.
2. **Iterate and Maintain Left and Right Sums**: Iterate through the array, maintaining a running sum of the left side and computing the right sum by subtracting the left sum and the current element from the total sum.
3. **Check for Pivot Index**: For each index, if the left sum equals the right sum, that index is the pivot index, and we return it immediately.
4. **Return -1 if No Pivot Found**: If no pivot index is found by the end of the loop, return -1.

By maintaining a running left sum and adjusting the right sum dynamically, we can solve the problem in O(n) time with O(1) space, which is optimal for this problem.

### Code Breakdown (Step by Step)

#### Initialization
```cpp
int left = 0;
int right = accumulate(nums.begin(), nums.end(), 0);
```
- **left**: This variable will maintain the sum of elements to the left of the current index.
- **right**: This variable is initialized to the total sum of all elements in the array. We can calculate this using the `accumulate` function from the C++ standard library.

#### Iteration Through the Array
```cpp
for(int i = 0; i < nums.size(); i++) {
    right -= nums[i];  // Subtract the current element from right
    if(right == left) return i;  // Check if the sums on both sides are equal
    left  += nums[i];  // Add the current element to left
}
```
- In each iteration, we adjust the `right` sum by subtracting the current element (`nums[i]`), since we are moving the pivot point from the left to the right.
- After adjusting `right`, we check if the `left` sum is equal to `right`. If they are equal, it means the current index `i` is the pivot index, so we return `i`.
- We also update the `left` sum by adding the current element (`nums[i]`), which will represent the sum of elements to the left of the next index in the next iteration.

#### Return -1 if No Pivot Found
```cpp
return -1;
```
- If the loop completes without finding a pivot index, we return -1 to indicate that no pivot index exists.

### Complexity Analysis

#### Time Complexity: **O(n)**
- The function iterates through the array only once.
- The calculation of the total sum using `accumulate()` takes O(n) time.
- In each iteration, the algorithm performs constant time operations (subtracting from `right`, comparing `left` and `right`, and updating `left`).
- Hence, the overall time complexity is **O(n)**, where `n` is the number of elements in the array.

#### Space Complexity: **O(1)**
- The algorithm uses a constant amount of extra space. The only extra space used is for the variables `left` and `right`, which store integer values, regardless of the input size.
- Thus, the space complexity is **O(1)**.

### Conclusion

This solution efficiently finds the pivot index in an array in linear time **O(n)** and constant space **O(1)**. It uses the concept of dynamically maintaining the sums of the left and right parts of the array, thus avoiding the need for redundant calculations. The algorithm's approach of using a total sum and adjusting the left and right sums during the iteration ensures that we can solve the problem optimally.

This method is both **time-efficient** and **space-efficient**, making it suitable for large arrays. If no pivot index exists, the function returns `-1`, which satisfies the problem's requirement. 

This approach leverages simple arithmetic operations and makes the problem-solving process straightforward and clean. The solution is optimal and scalable, ensuring that it works even for large inputs, and provides a great example of how careful use of running totals can simplify problems that involve balancing sums or other similar patterns.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-pivot-index/description/)

---
{{< youtube u89i60lYx8U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
