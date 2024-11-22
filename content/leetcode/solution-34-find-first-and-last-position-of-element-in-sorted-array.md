
+++
authors = ["grid47"]
title = "Leetcode 34: Find First and Last Position of Element in Sorted Array"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 34: Find First and Last Position of Element in Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/34.webp"
youtube = "4sQL7R5ySUU"
youtube_upload_date="2021-02-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4sQL7R5ySUU/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/34.webp" 
    alt="A soft glowing bar where the positions of elements light up in sequence."
    caption="Solution to LeetCode 34: Find First and Last Position of Element in Sorted Array Problem"
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
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);

        if(it1 == nums.end() || *it1 != target) return {-1, -1};

        return {(int) (it1 - nums.begin()), (int) (it2 - nums.begin() - 1)};
    }
};
{{< /highlight >}}
---

### 🔍 **First and Last Position in Sorted Array**

The task is to find the **first and last position** of a **target value** in a **sorted array**. If the target is not found, return `[-1, -1]`.

For example:
- **Input:** `nums = [5, 7, 7, 8, 8, 10]`, `target = 8`
  - **Output:** `[3, 4]`
- **Input:** `nums = [5, 7, 7, 8, 8, 10]`, `target = 6`
  - **Output:** `[-1, -1]`

The goal is to find the **range** of the target value in a sorted array using an efficient algorithm with **O(log n)** time complexity.

### 🧠 **Approach**

We can solve this problem efficiently by leveraging **binary search** and utilizing C++ Standard Library functions `lower_bound` and `upper_bound`.

1. **Binary Search with Lower and Upper Bound:**
   - `lower_bound`: Finds the **first occurrence** of an element **greater than or equal to** the target.
   - `upper_bound`: Finds the **first occurrence** of an element **greater than** the target.
   
2. **Finding the Range of the Target:**
   - `lower_bound(nums.begin(), nums.end(), target)` will return an iterator pointing to the first element **greater than or equal to** the target. If the target exists, this points to the first occurrence of the target.
   - `upper_bound(nums.begin(), nums.end(), target)` will return an iterator pointing to the first element **greater than** the target, which helps find the position just after the last occurrence of the target.
   
   The **range** of indices is then derived:
   - The first position is given by the iterator `it1` from `lower_bound`.
   - The last position is given by the iterator `it2` from `upper_bound`, adjusted by subtracting 1.

3. **Edge Case Handling:**
   - If the target is not found, both `lower_bound` and `upper_bound` will indicate positions where the target would be inserted, but the target value is absent. In this case, we return `[-1, -1]`.

### 🧑‍💻 **Code Breakdown**

```cpp
auto it1 = lower_bound(nums.begin(), nums.end(), target);
auto it2 = upper_bound(nums.begin(), nums.end(), target);
```
- **Step 1:** Use `lower_bound` to find the first occurrence of `target` and `upper_bound` to find the position just past the last occurrence of `target`.

```cpp
if(it1 == nums.end() || *it1 != target) return {-1, -1};
```
- **Step 2:** Check if the target is found by verifying if `it1` points to the target. If not, return `[-1, -1]`.

```cpp
return {(int) (it1 - nums.begin()), (int) (it2 - nums.begin() - 1)};
```
- **Step 3:** If the target is found, return a **range**:
  - The index of the first occurrence is `(it1 - nums.begin())`.
  - The index of the last occurrence is `(it2 - nums.begin() - 1)` because `it2` points just past the last occurrence of the target.

### 📊 **Time and Space Complexity**

#### **Time Complexity:**
- **O(log n):** Both `lower_bound` and `upper_bound` perform binary search, so the time complexity for each function is **O(log n)**. The overall complexity is **O(log n)**.

#### **Space Complexity:**
- **O(1):** The algorithm uses constant extra space as it only relies on iterators `it1` and `it2`.

### 🚀 **Conclusion**

This solution efficiently finds the **first and last positions** of a target value in a sorted array using **binary search-based** functions `lower_bound` and `upper_bound`. The approach ensures an optimal **O(log n)** time complexity, making it suitable for large arrays. By leveraging C++’s built-in binary search functions, the solution achieves excellent performance and minimal space usage, making it ideal for problems with sorted arrays where range searching is required.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

---
{{< youtube 4sQL7R5ySUU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
