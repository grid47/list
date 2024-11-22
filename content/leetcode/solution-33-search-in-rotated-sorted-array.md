
+++
authors = ["grid47"]
title = "Leetcode 33: Search in Rotated Sorted Array"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 33: Search in Rotated Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/33.webp"
youtube = "U8XENwh8Oy8"
youtube_upload_date="2020-06-18"
youtube_thumbnail="https://i.ytimg.com/vi/U8XENwh8Oy8/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/33.webp" 
    alt="A rotating spiral of light, revealing new paths and points of connection."
    caption="Solution to LeetCode 33: Search in Rotated Sorted Array Problem"
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
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while(s <= e) {
            int mid = s + (e - s + 1) / 2;
            if(nums[mid] == target) return mid;
            if(nums[s] <= nums[mid]) {// window contain jerk
                if(nums[s] <= target && target < nums[mid])
                    e = mid - 1;
                else s = mid + 1;
            } else {// window is linear
                if(nums[mid] < target && target <= nums[e])
                    s = mid + 1;
                else e = mid - 1;
            }
        }
        return -1;
    }
};
{{< /highlight >}}
---

### 🔍 **Search in Rotated Sorted Array**

The task is to find the **index of a target value** in a **rotated sorted array**. The array was initially sorted in ascending order, but has been rotated at an unknown pivot. Your goal is to efficiently search for the target and return its index. If the target is not found, return `-1`.

For example:
- **Input:** `nums = [4, 5, 6, 7, 0, 1, 2]`, `target = 0`
  - **Output:** `4`
- **Input:** `nums = [4, 5, 6, 7, 0, 1, 2]`, `target = 3`
  - **Output:** `-1`

The challenge is to find an optimal solution with a time complexity of **O(log n)**, which suggests we should use a binary search approach.

### 🧠 **Approach**

A **rotated sorted array** is an array that was originally sorted but has been rotated at some pivot. This means the array contains two sorted subarrays, with one part shifted to the front.

To solve this problem efficiently, we adapt **binary search** to account for the rotation:

1. **Properties of Rotated Sorted Arrays:**
   - One half of the array is sorted, while the other is shifted.
   - By comparing the middle element with the left and right elements, we can determine which half is sorted and which part is rotated.

2. **Binary Search Adaptation:**
   - We perform binary search, but instead of searching a single sorted array, we need to check which part is sorted and adjust our search accordingly.

3. **Key Observations:**
   - If the left half of the array (`nums[s]` to `nums[mid]`) is sorted, we can check if the target lies within this range.
   - If the right half (`nums[mid]` to `nums[e]`) is sorted, we adjust our search range accordingly.

### 🧑‍💻 **Code Breakdown**

```cpp
int n = nums.size();
int s = 0, e = n - 1;
```
- Initialize the size of the array `nums` and set the start (`s`) and end (`e`) indices for binary search.

```cpp
while(s <= e) {
    int mid = s + (e - s + 1) / 2;
```
- Continue the search as long as the search window is valid (`s <= e`).
- Compute the middle index `mid` using a formula that avoids overflow.

```cpp
if(nums[mid] == target) return mid;
```
- If the middle element is equal to the target, return the `mid` index.

```cpp
if(nums[s] <= nums[mid]) {
```
- If the left half of the array (`nums[s]` to `nums[mid]`) is sorted, check if the target lies within this sorted range.

```cpp
if(nums[s] <= target && target < nums[mid])
    e = mid - 1;  // Target lies within the sorted left half
else 
    s = mid + 1;  // Search in the right half
}
```

- If the target is within the sorted left half (`nums[s] <= target < nums[mid]`), adjust the search to the left half (`e = mid - 1`).
- Otherwise, search in the right half (`s = mid + 1`).

```cpp
else {
```
- If the left half is not sorted, then the right half must be sorted.

```cpp
if(nums[mid] < target && target <= nums[e])
    s = mid + 1;  // Target lies within the sorted right half
else 
    e = mid - 1;  // Search in the left half
}
```

- If the target is within the sorted right half (`nums[mid] < target && target <= nums[e]`), adjust the search to the right half (`s = mid + 1`).
- Otherwise, search in the left half (`e = mid - 1`).

```cpp
}
return -1;  // Target not found
```
- If the target is not found by the end of the loop, return `-1`.

### 📊 **Time and Space Complexity**

#### **Time Complexity:**
- **O(log n):** The algorithm performs binary search, reducing the search space by half with each step. Thus, the time complexity is logarithmic.

#### **Space Complexity:**
- **O(1):** The algorithm uses a constant amount of extra space, as it only maintains a few variables (indices `s`, `e`, `mid`).

### 🚀 **Conclusion**

The **search** function efficiently finds the index of the target value in a rotated sorted array using a modified **binary search**. The algorithm adapts binary search to handle the rotation by determining which half of the array is sorted and adjusting the search range accordingly.

- **Time Complexity:** **O(log n)**, making it optimal for large arrays.
- **Space Complexity:** **O(1)**, as the algorithm uses constant space.

This approach is well-suited for searching in rotated sorted arrays, providing both time and space efficiency.

[`Link to LeetCode Lab`](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

---
{{< youtube U8XENwh8Oy8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
