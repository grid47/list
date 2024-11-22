
+++
authors = ["grid47"]
title = "Leetcode 153: Find Minimum in Rotated Sorted Array"
date = "2024-10-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 153: Find Minimum in Rotated Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/153.webp"
youtube = "H2U24n4bcQQ"
youtube_upload_date="2024-03-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/H2U24n4bcQQ/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/153.webp" 
    alt="A rotating array with a glowing highlight marking the minimum element."
    caption="Solution to LeetCode 153: Find Minimum in Rotated Sorted Array Problem"
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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int ans = -1;

        if(n == 1) return nums[0];

        while(s < e) {
            int mid = s + (e - s) / 2;

            // if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]) return nums[mid];

            if(nums[e] < nums[mid]) {
                s = mid + 1;
            } else{
                e = mid;
            }
        }
        cout << "Hi" << e;
        return nums[e];
    }
};
{{< /highlight >}}
---

### 🌐 Find Minimum in Rotated Sorted Array

In this task, we’re given a rotated sorted array, and our goal is to identify the **minimum element** efficiently. This array was originally sorted in ascending order but was then rotated at an unknown pivot point. 

For instance:
- Original array: `[1, 2, 3, 4, 5, 6, 7]`
- After rotating by 3 positions: `[4, 5, 6, 7, 1, 2, 3]`

In this case, `1` is the smallest element, and we want to locate it using an optimized approach with **O(log n)** time complexity. Let’s dive into the steps to solve this problem efficiently!

---

### 💡 Approach

Our approach leverages **binary search** principles but with a twist to account for the rotation:

1. **Rotation Insight**: The minimum element is where the array “rotates” or changes direction. We compare the middle element (`nums[mid]`) with the last element (`nums[e]`) to determine which half contains the minimum.
2. **Binary Search Adjustments**:
   - If `nums[mid]` is greater than `nums[e]`, the minimum element is in the **right half** of the array.
   - If `nums[mid]` is less than or equal to `nums[e]`, the minimum is in the **left half** or could be `mid` itself.

---

### 📝 Code Breakdown (Step-by-Step)

#### 🔹 Step 1: Initialize Variables

```cpp
int n = nums.size();
int s = 0, e = n - 1;

if(n == 1) return nums[0];
```

Explanation:
- `n`: Size of the input array `nums`.
- `s` and `e`: Represent the start and end indices, respectively.
- If there’s only one element (`n == 1`), it’s trivially the minimum.

#### 🔹 Step 2: Binary Search Loop

```cpp
while(s < e) {
    int mid = s + (e - s) / 2;
```

This `while` loop will continue as long as `s` is less than `e`. It calculates `mid` using `s + (e - s) / 2` to prevent overflow.

#### 🔹 Step 3: Adjust Search Range Based on Element Comparison

```cpp
if(nums[e] < nums[mid]) {
    s = mid + 1;
} else {
    e = mid;
}
```

Key steps:
- If `nums[e] < nums[mid]`, the minimum must be in the right half, so we update `s` to `mid + 1`.
- Otherwise, the minimum is in the left half, so we update `e` to `mid`.

#### 🔹 Step 4: Return the Minimum Element

```cpp
return nums[e];
```

At the end, `s` and `e` converge at the minimum element’s index, so we return `nums[e]`.

---

### 🔎 Complexity

- **Time Complexity**: **O(log n)** due to the binary search approach.
- **Space Complexity**: **O(1)** since we only use a few extra variables.

### ✅ Conclusion

This modified binary search provides an optimal solution to locate the minimum element in **O(log n)** time, even when the array is rotated. This method is efficient for large arrays and showcases how binary search can be adapted to solve rotated array problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

---
{{< youtube H2U24n4bcQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
