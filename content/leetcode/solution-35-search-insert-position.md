
+++
authors = ["grid47"]
title = "Leetcode 35: Search Insert Position"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 35: Search Insert Position in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/35.webp"
youtube = "K-RYzDZkzCI"
youtube_upload_date="2020-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/K-RYzDZkzCI/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/35.webp" 
    alt="A glowing insertion point in a calm array, gently creating a new position."
    caption="Solution to LeetCode 35: Search Insert Position Problem"
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
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};
{{< /highlight >}}
---

### 🏷️ **Problem Statement**

Given a **sorted array of integers** and a **target value**, the task is to find the **index** where the target should be **inserted** in the array while maintaining the sorted order. If the target is already present, return its current index.

For example:
- **Input:** `nums = [1, 3, 5, 6]`, `target = 5`
  - **Output:** `2` (because 5 is at index 2)
  
- **Input:** `nums = [1, 3, 5, 6]`, `target = 2`
  - **Output:** `1` (because 2 should be inserted at index 1)

- **Input:** `nums = [1, 3, 5, 6]`, `target = 7`
  - **Output:** `4` (because 7 should be inserted at index 4)

### 🧠 **Approach**

To solve this problem efficiently, we can use **binary search**, which allows us to find the **insertion index** in **O(log n)** time. Here's how:

1. **Binary Search Overview:**
   - Binary search is an algorithm that repeatedly divides the search space in half based on comparisons with the middle element.
   - Since the array is sorted, we can apply binary search to determine the insertion point for the target.

2. **Steps to Solve:**
   - Initialize two pointers `l` (left) and `r` (right) to represent the bounds of the search.
   - Perform binary search while `l <= r`:
     - Calculate the middle index `mid` as `l + (r - l) / 2` to avoid overflow.
     - If `nums[mid]` is equal to the target, return `mid` as the target’s index.
     - If `nums[mid]` is less than the target, move the left pointer (`l = mid + 1`) to search the right half.
     - If `nums[mid]` is greater than the target, move the right pointer (`r = mid - 1`) to search the left half.
   - After the loop ends, the left pointer `l` will point to the index where the target should be inserted.

### 💻 **Code Breakdown**

```cpp
int l = 0, r = nums.size() - 1;
```
- **Step 1:** Initialize the left pointer `l` at 0 and the right pointer `r` at the last index of the array.

```cpp
while(l <= r) {
    int mid = l + (r - l) / 2;
```
- **Step 2:** Start the binary search loop. Calculate the middle index `mid` as the average of `l` and `r`, ensuring no overflow.

```cpp
if(nums[mid] == target) return mid;
```
- **Step 3:** If the middle element equals the target, return `mid` as the index of the target.

```cpp
if(nums[mid] < target) l = mid + 1;
else r = mid - 1;
```
- **Step 4:** Adjust the search bounds based on whether `nums[mid]` is less than or greater than the target:
  - If `nums[mid] < target`, move `l` to `mid + 1` to search the right half.
  - If `nums[mid] > target`, move `r` to `mid - 1` to search the left half.

```cpp
return l;
```
- **Step 5:** If the target is not found, return `l`, which now points to the insertion index.

### 📊 **Time and Space Complexity**

#### Time Complexity:
- **O(log n):** Since we are using binary search, the time complexity is **O(log n)**, where `n` is the number of elements in the array. Each iteration of the binary search reduces the search space by half.

#### Space Complexity:
- **O(1):** The algorithm uses a constant amount of extra space because only a few integer variables (`l`, `r`, and `mid`) are used.

### 🚀 **Conclusion**

This solution efficiently finds the **insertion index** of the target value in a **sorted array** using **binary search**. The approach ensures an optimal **O(log n)** time complexity, making it ideal for large datasets. The space complexity is minimal, **O(1)**, as no additional data structures are required. This solution is well-suited for scenarios requiring fast insertion point search, especially when working with large arrays.

[`Link to LeetCode Lab`](https://leetcode.com/problems/search-insert-position/description/)

---
{{< youtube K-RYzDZkzCI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
