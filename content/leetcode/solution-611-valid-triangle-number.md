
+++
authors = ["grid47"]
title = "Leetcode 611: Valid Triangle Number"
date = "2024-09-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 611: Valid Triangle Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/611.webp"
youtube = "AZrQMv5ne54"
youtube_upload_date="2021-02-27"
youtube_thumbnail="https://i.ytimg.com/vi/AZrQMv5ne54/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/611.webp" 
    alt="A set of triangle side lengths where the valid triangles glow softly, and invalid ones fade."
    caption="Solution to LeetCode 611: Valid Triangle Number Problem"
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
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int cnt = 0, n = nums.size();
        
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0, k = i - 1; j < k;) {
                if(nums[i] < nums[j] + nums[k]) {
                    cnt+= k - j;
                    k--;
                } else j++;
            }
        
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array of integers `nums`, we are tasked with finding the number of valid triangles that can be formed with three sides where the side lengths are taken from the array. For a set of three side lengths to form a valid triangle, the sum of any two sides must be greater than the third side. Specifically, given three side lengths `a`, `b`, and `c` (where `a <= b <= c`), the condition for forming a triangle is:

- `a + b > c`

### Approach

To solve this problem efficiently, we can use the **two-pointer technique** combined with sorting. The main idea is to:
1. **Sort the array**: Sorting the array will allow us to simplify checking the triangle inequality condition. If the array is sorted, for any triplet of sides `a`, `b`, and `c` (where `a <= b <= c`), we only need to check if `a + b > c` to verify if they form a valid triangle.
2. **Iterate through each element**: For each element `nums[i]`, treat it as the largest side (`c`) of the triangle.
3. **Use two pointers**: For each fixed `nums[i]` as `c`, use two pointers (`j` and `k`) to find pairs of numbers from the previous elements (`nums[0]` to `nums[i-1]`) that can form valid triangles with `nums[i]`. Specifically, for each pair `nums[j]` and `nums[k]`, we check if they satisfy the condition `nums[j] + nums[k] > nums[i]`.

### Code Breakdown (Step by Step)

#### Step 1: Sorting the Array
```cpp
sort(nums.begin(), nums.end());
```
- We begin by sorting the `nums` array in ascending order. This ensures that for each triplet `a`, `b`, and `c` where `a <= b <= c`, the triangle inequality check (`a + b > c`) will be straightforward to implement.

#### Step 2: Initialize Variables
```cpp
int cnt = 0, n = nums.size();
```
- `cnt` will store the count of valid triangles.
- `n` is the size of the input array `nums`.

#### Step 3: Loop Over the Largest Side (`c`)
```cpp
for(int i = n - 1; i >= 0; i--)
```
- We start by iterating backward from the last element of the sorted array (`i = n - 1`). The element at index `i` is considered as the largest side (`c`) of the triangle.
- The reason for iterating backwards is that we want to consider the largest possible side first and check for possible valid triangles with smaller sides.

#### Step 4: Use Two Pointers to Find Valid Pairs
```cpp
for(int j = 0, k = i - 1; j < k;)
```
- For each fixed value of `nums[i]`, we use two pointers (`j` and `k`) to check for valid pairs of sides from the previous elements (`nums[0]` to `nums[i-1]`).
  - `j` starts at 0 (the smallest element) and `k` starts at `i - 1` (the element just before `nums[i]`).
  - The goal is to check if the sum of `nums[j]` and `nums[k]` is greater than `nums[i]` (the largest side of the triangle).

#### Step 5: Check Triangle Validity and Update Pointers
```cpp
if(nums[i] < nums[j] + nums[k]) {
    cnt += k - j;
    k--;
} else j++;
```
- If `nums[j] + nums[k] > nums[i]`, we have found valid pairs that can form a triangle with `nums[i]` as the largest side.
  - The number of valid triangles with `nums[i]` as the largest side is `k - j`, because every pair of `nums[j]` and `nums[l]` (where `j <= l <= k`) will satisfy the condition `nums[j] + nums[l] > nums[i]`.
  - We increment the count `cnt` by `k - j` and move the pointer `k--` to check the next smaller pair.
- If `nums[j] + nums[k] <= nums[i]`, we increment `j` to try with a larger value for `nums[j]`.

#### Step 6: Return the Final Count
```cpp
return cnt;
```
- After iterating through all possible valid triangles, the final count of valid triangles is returned.

### Complexity

#### Time Complexity:
- **O(n^2)**: 
  - Sorting the array takes **O(n log n)** time.
  - The outer loop runs `n` times (for each `nums[i]`), and for each iteration of the outer loop, the inner loop runs with two pointers, resulting in a total of **O(n^2)** iterations in the worst case.
  - Therefore, the overall time complexity is **O(n^2)**.

#### Space Complexity:
- **O(1)**: 
  - The space complexity is constant because we only use a few extra variables (`cnt`, `n`, `j`, `k`), and no extra space is used for storing additional data structures (except for the input array).
  - Therefore, the space complexity is **O(1)**.

### Conclusion

This solution efficiently counts the number of valid triangles that can be formed from the given array of integers. By leveraging sorting and the two-pointer technique, we can reduce the complexity of the problem from **O(n^3)** (brute force approach) to **O(n^2)**, making it suitable for larger input sizes. The algorithm ensures that all possible triplets are checked in an optimal manner, yielding the correct count of valid triangles. This method is both time-efficient and space-efficient, providing an ideal solution for counting valid triangles from side lengths in a sorted array.

[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-triangle-number/description/)

---
{{< youtube AZrQMv5ne54 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
