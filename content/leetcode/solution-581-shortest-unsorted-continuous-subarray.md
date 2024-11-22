
+++
authors = ["grid47"]
title = "Leetcode 581: Shortest Unsorted Continuous Subarray"
date = "2024-09-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 581: Shortest Unsorted Continuous Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Stack","Greedy","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/581.webp"
youtube = "NzVaNmqPaSo"
youtube_upload_date="2021-02-25"
youtube_thumbnail="https://i.ytimg.com/vi/NzVaNmqPaSo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/581.webp" 
    alt="An array where the shortest unsorted subarray is found, each element softly glowing as it is highlighted."
    caption="Solution to LeetCode 581: Shortest Unsorted Continuous Subarray Problem"
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
    int findUnsortedSubarray(vector<int>& nums) {
        
        int mn = 0, mx = 0, n = nums.size();
        
        
        vector<pair<int, int>> tmp(n);
        
        for(int i = 0; i < n; i++)
        tmp[i] = make_pair(nums[i], i);
        
        sort(tmp.begin(), tmp.end());
        
        int start = -1, end = -1;
        
        for(int i = 0; i < n; i++) {
            if(i != tmp[i].second)
                if (start == -1) start = i;
                else               end = i;
        }
        
        if(start == -1) return 0;
        return end - (start - 1);
    }
};
{{< /highlight >}}
---

### Problem Statement:

The problem asks us to find the shortest subarray in an array of integers `nums` that, if sorted, would result in the entire array being sorted. In other words, we need to identify a contiguous subarray that is out of order and should be sorted so that the entire array becomes sorted.

We are given an integer array `nums`, and we need to find the length of this subarray. If the array is already sorted, the result should be `0`.

### Approach:

To solve this problem, we need to identify the range within the array that is out of order. The strategy is to:
1. Sort the array, keeping track of the original indices of the elements.
2. Compare the sorted version with the original array to find the starting and ending positions of the unsorted subarray.
3. Calculate the length of the subarray between the starting and ending indices.

We can break down the solution into several steps:

1. **Sorting the Array**: First, we sort the array, but while doing this, we need to keep track of the original indices. This is crucial because the sorted array will allow us to identify which elements are misplaced.
   
2. **Identify Start and End Indices**: We then iterate through both the original and sorted arrays to find where the original array deviates from the sorted array. This deviation gives us the boundaries of the unsorted subarray.
   
3. **Return the Length**: Once we have identified the `start` and `end` indices of the unsorted subarray, we can easily compute the length of the subarray.

### Code Breakdown (Step by Step):

#### Step 1: Initialize Variables and Prepare for Sorting
```cpp
int mn = 0, mx = 0, n = nums.size();
vector<pair<int, int>> tmp(n);
```
- We start by defining the necessary variables. `mn` and `mx` are placeholders for tracking the minimum and maximum values, but they aren't used in this version of the solution.
- `n` stores the size of the input array `nums`.
- `tmp` is a vector of pairs, where each pair consists of an element from the original array and its corresponding index. This will help us track the original positions of the elements after sorting.

#### Step 2: Create Pairs of Elements and Indices
```cpp
for(int i = 0; i < n; i++)
    tmp[i] = make_pair(nums[i], i);
```
- We iterate through the array and populate `tmp` with pairs of values from the `nums` array and their original indices.

#### Step 3: Sort the Array of Pairs
```cpp
sort(tmp.begin(), tmp.end());
```
- We sort the array `tmp` based on the values of the elements (the first part of each pair). This will allow us to compare the original array with the sorted version to identify where the elements are out of order.

#### Step 4: Identify the Start and End of the Unsorted Subarray
```cpp
int start = -1, end = -1;
for(int i = 0; i < n; i++) {
    if(i != tmp[i].second)
        if (start == -1) start = i;
        else               end = i;
}
```
- After sorting, we loop through the array again and compare each element's original index (from `tmp[i].second`) with its position in the sorted array (`i`). If the original index is not equal to the current index, it indicates that the element is misplaced.
- The first time we encounter a mismatch, we set `start` to that index. If a mismatch occurs again, we set `end` to that index. This gives us the boundaries of the unsorted subarray.
  
#### Step 5: Return the Length of the Unsorted Subarray
```cpp
if(start == -1) return 0;
return end - (start - 1);
```
- If no mismatches were found (i.e., the array is already sorted), we return `0`.
- Otherwise, we calculate and return the length of the subarray by subtracting the `start` index from the `end` index.

### Complexity:

#### Time Complexity:
- **O(n log n)**: The time complexity is dominated by the sorting step, where `n` is the number of elements in the array. Sorting takes O(n log n) time, while the rest of the operations (initialization and iteration through the array) take linear time O(n). Thus, the overall time complexity is O(n log n).

#### Space Complexity:
- **O(n)**: We use an additional vector `tmp` to store pairs of elements and their indices, which requires O(n) space. The space complexity is linear with respect to the number of elements in the input array.

### Conclusion:

This solution efficiently finds the shortest subarray that needs to be sorted in order to sort the entire array. By using sorting and tracking the original indices, we can easily identify the misplaced elements and calculate the boundaries of the unsorted subarray. The time complexity of O(n log n) is acceptable for arrays of typical sizes encountered in competitive programming, and the space complexity of O(n) is reasonable for this problem.

The algorithm performs well in terms of both time and space efficiency, making it an ideal solution for this problem. It effectively handles edge cases, such as when the array is already sorted or when the entire array needs to be sorted, and provides a clear and simple approach to identifying the required subarray.

[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/)

---
{{< youtube NzVaNmqPaSo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
