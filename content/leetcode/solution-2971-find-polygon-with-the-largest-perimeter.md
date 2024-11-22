
+++
authors = ["grid47"]
title = "Leetcode 2971: Find Polygon With the Largest Perimeter"
date = "2024-01-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2971: Find Polygon With the Largest Perimeter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Yk9Mor-Y488"
youtube_upload_date="2024-02-15"
youtube_thumbnail="https://i.ytimg.com/vi/Yk9Mor-Y488/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n, 0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
        for(int i = n - 1; i >= 2; i--)
            if(nums[i] < sum[i - 1])
                return sum[i];
        return -1;
    }
};
{{< /highlight >}}
---

### Problem Statement:

The task is to find the largest possible perimeter of a triangle that can be formed using three sides from an array of integers `nums`. A valid triangle is formed when the sum of any two sides is greater than the third side, i.e., for three sides `a`, `b`, and `c`, the following conditions must hold:
- `a + b > c`
- `a + c > b`
- `b + c > a`

The goal is to return the largest perimeter of a valid triangle, or return `-1` if it is not possible to form any valid triangle using the integers in the array.

### Approach:

1. **Understanding the Triangle Inequality Theorem**:
   The key insight to solve this problem is based on the **triangle inequality theorem**. For three numbers to form a triangle, the sum of any two sides must be strictly greater than the third side. If we sort the array in non-decreasing order, the largest possible perimeter will be formed by the last three numbers in the sorted array that satisfy this condition.

2. **Sorting the Array**:
   Sorting the array allows us to easily check the largest possible sides that can form a triangle. By sorting the array, the largest element is at the end, and we can simply check if the sum of the two smaller numbers is greater than the largest one.

3. **Prefix Sum Calculation**:
   We can utilize a prefix sum array to efficiently calculate the sum of the first `i` elements. This helps in quickly checking whether the sum of the two smaller sides (from a sorted array) is greater than the third side.

4. **Iterate to Find the Largest Valid Triangle**:
   After sorting the array, we can start from the third largest element and check if the sum of the first two elements of the potential triangle (the two smaller sides) is greater than the third. If this condition holds true, the perimeter of the triangle is the sum of these three sides. If no valid triangle can be formed, return `-1`.

### Code Breakdown (Step by Step):

#### Step 1: Sorting the array
```cpp
sort(nums.begin(), nums.end());
```
- The first step is to sort the array in non-decreasing order. This allows us to easily check the largest possible triplet of numbers that could form a valid triangle.

#### Step 2: Calculate prefix sum
```cpp
vector<long long> sum(n, 0);
sum[0] = nums[0];
for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
```
- We create a `sum` array where each element at index `i` contains the sum of all elements in the `nums` array up to that index. This helps quickly compute the sum of any subset of elements.

#### Step 3: Check for valid triangles from the largest possible sides
```cpp
for(int i = n - 1; i >= 2; i--)
    if(nums[i] < sum[i - 1])
        return sum[i];
```
- We iterate from the end of the array to the third element, checking if the largest side `nums[i]` is less than the sum of the other two sides `sum[i - 1]`. If this condition is true, it means that `nums[i-2]`, `nums[i-1]`, and `nums[i]` can form a valid triangle, and we return the perimeter of this triangle, which is simply the sum of these three sides.

#### Step 4: Return `-1` if no valid triangle is found
```cpp
return -1;
```
- If we finish checking all possible triplets and none of them form a valid triangle, we return `-1` to indicate that no valid triangle can be formed from the given sides.

### Complexity Analysis:

#### Time Complexity:
- **Sorting**: Sorting the array takes `O(n log n)`, where `n` is the size of the `nums` array.
- **Prefix sum calculation**: Calculating the prefix sum array takes `O(n)`.
- **Checking for valid triangles**: The loop where we check for valid triangles runs in `O(n)`.
- Overall, the time complexity is dominated by the sorting step, so the total time complexity is **O(n log n)**.

#### Space Complexity:
- **Space for the prefix sum array**: We use an extra array `sum` of size `n`, so the space complexity is **O(n)**.
- Other than this, the space complexity is constant, i.e., **O(1)** for the variables used in the algorithm.
- Overall, the space complexity is **O(n)** due to the space used for the `sum` array.

### Conclusion:

This approach efficiently solves the problem by leveraging sorting and prefix sum techniques. By sorting the array and using the triangle inequality theorem, the solution is able to quickly check the largest possible valid triangle and return its perimeter. The solution has a time complexity of **O(n log n)**, which is optimal for this type of problem, and the space complexity is linear due to the additional storage used for the prefix sum array. This solution is both efficient and easy to understand, making it suitable for solving the problem with large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/)

---
{{< youtube Yk9Mor-Y488 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
