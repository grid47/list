
+++
authors = ["grid47"]
title = "Leetcode 162: Find Peak Element"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 162: Find Peak Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/162.webp"
youtube = "31foR5tJapQ"
youtube_upload_date="2021-02-22"
youtube_thumbnail="https://i.ytimg.com/vi/31foR5tJapQ/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/162.webp" 
    alt="A smooth curve of numbers with the highest point glowing brightly, symbolizing the peak."
    caption="Solution to LeetCode 162: Find Peak Element Problem"
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
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        
        int l = 0, r = n - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            bool x = mid > 0? arr[mid - 1] < arr[mid] : true;
            bool y = mid < n -1 ? arr[mid + 1] < arr[mid] : true;
            
            if(x && y) return mid;
            if(!x && y) r = mid - 1;
            else if(x && !y) l = mid + 1;
            else r = mid - 1;            
        }
        return l;
    }
};
{{< /highlight >}}
---

### 🌐 Peak Element: Finding the Local Maximum Efficiently

In this problem, we are tasked with finding a **peak element** in an array. A peak element is defined as an element that is greater than or equal to its neighbors. Specifically:
- The first element is a peak if it is greater than or equal to the second element.
- The last element is a peak if it is greater than or equal to the second-last element.
- Any other element is a peak if it is greater than or equal to both its neighbors.

The challenge is to find a peak element using a **binary search approach**, which will give us a **O(log n)** time complexity.

---

### 💡 Approach

To solve this problem efficiently, we can use a **binary search** strategy. The key observation is that we can reduce the search space at each step based on the properties of a peak:
- If the middle element is greater than or equal to both its neighbors, it is a peak element.
- If the middle element is smaller than the next element, then there is a peak element on the right side.
- If the middle element is smaller than the previous element, then there is a peak element on the left side.

By halving the search space at each step, we can find a peak element in **O(log n)** time.

---

### 📝 Code Breakdown (Step-by-Step)

#### 🔹 Step 1: Initial Setup

```cpp
int n = arr.size();
int l = 0, r = n - 1;
```
- First, the size of the array `arr` is calculated and stored in `n`.
- `l` and `r` represent the left and right bounds of the search space. Initially, `l` is set to 0 (the first index) and `r` is set to `n - 1` (the last index).

#### 🔹 Step 2: Binary Search Loop

```cpp
while(l <= r) {
    int mid = l + (r - l) / 2;
```
- The loop continues as long as `l` is less than or equal to `r`. We calculate the middle index `mid` using the formula `l + (r - l) / 2` to avoid overflow.

#### 🔹 Step 3: Check if Middle Element is a Peak

```cpp
bool x = mid > 0 ? arr[mid - 1] < arr[mid] : true;
bool y = mid < n - 1 ? arr[mid + 1] < arr[mid] : true;
```
- The conditions `x` and `y` check whether the current element at index `mid` is greater than or equal to its neighbors:
  - `x` checks if `arr[mid]` is greater than or equal to the previous element (`arr[mid - 1]`), unless `mid` is the first element (`mid == 0`).
  - `y` checks if `arr[mid]` is greater than or equal to the next element (`arr[mid + 1]`), unless `mid` is the last element (`mid == n - 1`).

#### 🔹 Step 4: Check for Peak Element

```cpp
if(x && y) return mid;
```
- If both `x` and `y` are true, then `arr[mid]` is a peak element. We return the index `mid` as the result.

#### 🔹 Step 5: Narrow Search Space Based on Comparisons

```cpp
if(!x && y) r = mid - 1;
else if(x && !y) l = mid + 1;
else r = mid - 1;
```
- If the middle element is not greater than its left neighbor (`!x`), then there must be a peak on the left side, so we update `r` to `mid - 1` to search in the left half.
- If the middle element is not greater than its right neighbor (`!y`), then there must be a peak on the right side, so we update `l` to `mid + 1` to search in the right half.

#### 🔹 Step 6: Return the Peak Element Index

```cpp
return l;
```
- Once the loop terminates, the index `l` will be the index of the peak element. Since the loop ensures that either `arr[l]` or `arr[r]` is a peak, returning `l` guarantees we always find a peak.

---

### 🔎 Complexity

#### Time Complexity:
- **O(log n)**: The binary search approach ensures that the search space is halved at each step, leading to a logarithmic time complexity.

#### Space Complexity:
- **O(1)**: The algorithm uses a constant amount of extra space (just a few integer variables to track the bounds `l`, `r`, and `mid`), making the space complexity **O(1)**.

### ✅ Conclusion

This solution uses a **binary search** approach to efficiently find a peak element in an array. By narrowing down the search space based on the comparison of middle elements with their neighbors, we achieve an optimal time complexity of **O(log n)**, while using **O(1)** extra space.

#### Key Insights:
- A peak element is guaranteed to exist, but it is not necessarily unique.
- The binary search approach reduces the complexity from **O(n)** (linear search) to **O(log n)**, making it ideal for large input sizes.
- Edge cases such as the first or last element being a peak are handled with conditional checks.

This approach is particularly useful when dealing with large arrays, as it allows us to find a peak element without scanning the entire array.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-peak-element/description/)

---
{{< youtube 31foR5tJapQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
