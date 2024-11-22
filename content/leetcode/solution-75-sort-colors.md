
+++
authors = ["grid47"]
title = "Leetcode 75: Sort Colors"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 75: Sort Colors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/75.webp"
youtube = "4xbWSRZHqac"
youtube_upload_date="2021-06-24"
youtube_thumbnail="https://i.ytimg.com/vi/4xbWSRZHqac/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/75.webp" 
    alt="A radiant sequence of colors gently sorting themselves in a peaceful, fluid motion."
    caption="Solution to LeetCode 75: Sort Colors Problem"
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
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        
        for(int k = 0; k < n; k++) {
            
            while(nums[k] == 2 && k < j) {
                swap(nums[k], nums[j--]);                
            }
            while(nums[k] == 0 && k > i) {
                swap(nums[k], nums[i++]);  
            }
        }
    }
};
{{< /highlight >}}
---

### 🏳️ **Dutch National Flag Problem** - Sort Array of 0s, 1s, and 2s

In this problem, we are tasked with sorting an array of integers that only contains the values `0`, `1`, and `2`. The goal is to rearrange the array such that all the `0`s come first, followed by all the `1`s, and then all the `2`s, using a single pass through the array. The challenge is to do this efficiently, in **O(n)** time complexity, and **without extra space** (i.e., sorting **in-place**).

### 🚀 **Approach**

To solve this problem efficiently, we can use a **three-pointer technique**. This technique is well-suited for problems where we need to partition an array into multiple categories. In our case, the three categories are `0`s, `1`s, and `2`s.

We will use three pointers to help us manage these partitions:
1. **`i` (beginning of the array)**: This pointer tracks where the next `0` should be placed.
2. **`j` (end of the array)**: This pointer tracks where the next `2` should be placed.
3. **`k` (current element)**: This pointer will iterate through the array, inspecting each element one by one.

The key idea is to use these pointers to swap elements into their correct positions:
- If we encounter a `0`, it is swapped to the front (`i` pointer).
- If we encounter a `2`, it is swapped to the end (`j` pointer).
- If we encounter a `1`, it is already in the correct position, and we move on.

### 📝 **Code Breakdown**

#### Step 1: Initialize Pointers
```cpp
int n = nums.size();
int i = 0, j = n - 1;
```
- We first determine the size of the array, `n`, and initialize two pointers: `i` (set to the beginning of the array) and `j` (set to the end of the array).

#### Step 2: Iterating through the Array
```cpp
for(int k = 0; k < n; k++) {
```
- We use a for loop to iterate over the array, with the `k` pointer acting as the iterator for each element in the array.

#### Step 3: Handling the Case for `2`
```cpp
while(nums[k] == 2 && k < j) {
    swap(nums[k], nums[j--]);
}
```
- If the current element is `2`, we swap it with the element at the `j` pointer (which points to the last unprocessed element). After swapping, we decrement `j` to move it toward the left.

#### Step 4: Handling the Case for `0`
```cpp
while(nums[k] == 0 && k > i) {
    swap(nums[k], nums[i++]);
}
```
- If the current element is `0`, we swap it with the element at the `i` pointer (which points to the first unprocessed element). After swapping, we increment `i` to move it toward the right.

#### Step 5: Loop Continuation and Finalization
- The loop continues, ensuring all elements are processed and the array is sorted in-place.

### 📊 **Complexity Analysis**

#### Time Complexity:
- **O(n)**: The algorithm iterates through the array once using the `k` pointer. Each element is processed once — either being swapped into the correct position for `0`s, `1`s, or `2`s. There are no nested loops, so the time complexity is **O(n)**, where `n` is the size of the input array.

#### Space Complexity:
- **O(1)**: The algorithm uses only a constant amount of space for the pointers (`i`, `j`, and `k`). There are no additional arrays or data structures used, so the space complexity is **O(1)**. The array is sorted **in-place**.

### 🎯 **Conclusion**

This solution leverages the **three-pointer technique** to efficiently solve the **Dutch National Flag problem**. By using the `i`, `j`, and `k` pointers, we are able to sort the array in-place with **O(n)** time complexity and **O(1)** space complexity. 

This approach is optimal because:
- It processes each element only once.
- It avoids extra space usage, making it suitable for memory-constrained environments.

This solution is especially effective when sorting arrays that contain a limited set of distinct values (such as `0`, `1`, and `2`). The algorithm is both **time-efficient** and **space-efficient**, making it ideal for large datasets or situations with limited memory resources.

---

### 🌟 **Key Takeaways**
- The **three-pointer technique** is great for partitioning an array into multiple categories.
- Sorting with **O(n)** time and **O(1)** space is optimal when dealing with arrays containing a small number of distinct values.
- The algorithm sorts the array **in-place**, making it efficient for memory usage.

---


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-colors/description/)

---
{{< youtube 4xbWSRZHqac >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
