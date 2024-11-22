
+++
authors = ["grid47"]
title = "Leetcode 81: Search in Rotated Sorted Array II"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 81: Search in Rotated Sorted Array II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/81.webp"
youtube = "oUnF7o88_Xc"
youtube_upload_date="2023-08-10"
youtube_thumbnail="https://i.ytimg.com/vi/oUnF7o88_Xc/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/81.webp" 
    alt="A rotating array with elements softly shifting in a clockwise direction."
    caption="Solution to LeetCode 81: Search in Rotated Sorted Array II Problem"
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
    bool search(vector<int>& nums, int target) {
        
     int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }        
        
};
{{< /highlight >}}
---


### 💡 **Search in Rotated Sorted Array with Duplicates** – Let’s Solve It Together!

The **Search in Rotated Sorted Array** problem is a common challenge in coding interviews. In this variation, the array has been rotated at an unknown pivot, and it may contain duplicates. The goal is to **efficiently search for a target number** in the rotated sorted array. Let’s dive into how we can solve this problem using an optimized approach.

### 📝 **What’s the Problem?**

You're given:
- A rotated **sorted array** `nums` that may contain duplicates.
- A **target** number that we need to search for in the array.

Our task is to **determine whether the target exists** in the array and return `true` if it is present, or `false` otherwise.

### 🔍 **Approach: Modified Binary Search**

To solve this problem, we’ll use a **modified binary search** approach. The typical binary search assumes that the array is sorted and does not handle the complexities of rotation or duplicates well. However, with careful adjustments, we can efficiently find the target in a rotated sorted array with duplicates.

#### Key Observations:
1. **The array is rotated** at an unknown pivot.
2. **Duplicates are present**, which complicates the search process.
3. **Binary Search** must be modified to handle both the rotation and duplicates.

### Code Breakdown (Step by Step)

#### Step 1: Function Definition
```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
```
- We define the `search` function, which takes two parameters:
  - `nums`: The rotated sorted array, which may contain duplicates.
  - `target`: The number we are looking for.

#### Step 2: Initializing Pointers
```cpp
int l = 0;
int r = nums.size() - 1;
```
- We initialize two pointers, `l` (left) and `r` (right), to the first and last indices of the array, respectively.

#### Step 3: While Loop for Binary Search
```cpp
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (nums[mid] == target)
        return true;
```
- The `while` loop runs as long as `l` is less than or equal to `r`.
- We calculate the midpoint `mid` using `l + (r - l) / 2` to avoid overflow. If the element at `mid` equals the target, we return `true`.

#### Step 4: Handling Duplicates
```cpp
if ((nums[l] == nums[mid]) && (nums[r] == nums[mid])) {
    l++;
    r--;
}
```
- If both the left (`nums[l]`) and right (`nums[r]`) elements are equal to the middle element (`nums[mid]`), we cannot definitively determine the sorted half because of duplicates.
- We adjust the search range by incrementing `l` and decrementing `r`, effectively narrowing the search window.

#### Step 5: Standard Binary Search Adjustments
```cpp
else if (nums[l] <= nums[mid]) {
    // Target is in the first half
    if ((nums[l] <= target) && (nums[mid] > target))
        r = mid - 1;
    else
        l = mid + 1;
}
```
- If the left side of the array is sorted (`nums[l] <= nums[mid]`), we check if the target is in the first half of the array. If the target is in the range between `nums[l]` and `nums[mid]`, we adjust the right pointer (`r = mid - 1`), otherwise, we adjust the left pointer (`l = mid + 1`).

#### Step 6: Handling the Right Half of the Array
```cpp
else {
    if ((nums[mid] < target) && (nums[r] >= target))
        l = mid + 1;
    else
        r = mid - 1;
}
```
- If the right side of the array is sorted (`nums[mid] < nums[r]`), we check if the target is in the right half. If the target lies within `nums[mid]` and `nums[r]`, we move the left pointer (`l = mid + 1`), otherwise, we adjust the right pointer (`r = mid - 1`).

#### Step 7: Return Statement
```cpp
return false;
```
- If we exit the loop without finding the target, we return `false`, indicating that the target is not in the array.

### ⏱️ **Time and Space Complexity**

#### Time Complexity:
The time complexity is **O(n)** in the worst case. Although binary search typically operates in **O(log n)**, the presence of duplicates can degrade performance. In certain cases, when duplicates are encountered at both ends, the algorithm may fall back to a linear search, making the time complexity **O(n)** in the worst case.

#### Space Complexity:
The space complexity is **O(1)** because we use a constant amount of extra space for variables such as `l`, `r`, and `mid`. The algorithm performs in-place searches, which means it doesn’t require additional memory for data structures.

### 🚀 **Conclusion**

This solution efficiently handles the search for a target in a rotated sorted array with duplicates. By modifying the typical binary search to handle duplicates, we ensure that we don't miss any potential targets. While the worst-case time complexity can be linear due to duplicates, this solution remains highly effective and optimal for most scenarios. 

Keep in mind that while the algorithm might degrade to a linear search in rare cases, it still provides an efficient solution for moderate-sized arrays. Happy coding! 💻🌟

[`Link to LeetCode Lab`](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

---
{{< youtube oUnF7o88_Xc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
