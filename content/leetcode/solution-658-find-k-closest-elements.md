
+++
authors = ["grid47"]
title = "Leetcode 658: Find K Closest Elements"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 658: Find K Closest Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sliding Window","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/658.webp"
youtube = "o-YDQzHoaKM"
youtube_upload_date="2022-01-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/o-YDQzHoaKM/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/658.webp" 
    alt="A set of elements with the k closest ones glowing softly as they are identified."
    caption="Solution to LeetCode 658: Find K Closest Elements Problem"
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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() -k;
        while(l < r) {
            int m = (l + r) / 2;
            if(x - arr[m] > arr[m + k] - x) {
                l = m + 1;
            } else r = m;
        }
        
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
{{< /highlight >}}
---

### Problem Statement

Given a **sorted array** `arr`, an integer `k`, and an integer `x`, the task is to find the **k closest elements** to `x` in the array. The result should be returned in **sorted order**.

The array `arr` is sorted in **non-decreasing order**, and we need to determine which `k` elements are closest to `x`. We can either use the absolute difference between each element and `x` to calculate proximity. If there are ties (i.e., two elements with the same distance to `x`), we should include the smaller element in the result.

### Approach

To solve this problem, we aim to find a **subarray** of length `k` that contains the closest elements to `x`. The sorted nature of the array allows us to apply **binary search** for efficient processing. Here's how we approach the solution:

1. **Binary Search:**  
   The key idea is to use binary search to locate the potential starting point for the subarray that contains the closest elements to `x`. We will perform the binary search to find the position where the `k` closest elements start in the array.

2. **Sliding Window/Two Pointers:**  
   By narrowing down the search window with binary search, we ensure that we can efficiently find the `k` closest elements. Once we determine the starting index, extracting the result becomes trivial.

3. **Efficient Comparison:**  
   The problem can be solved in **O(n)** time using a linear scan after finding the correct starting index using binary search.

### Code Breakdown (Step by Step)

#### 1. **Function Signature**
```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x)
```
This function takes a sorted array `arr`, an integer `k`, and an integer `x`. It returns a vector of the `k` closest elements to `x` from the array, sorted in non-decreasing order.

#### 2. **Binary Search Initialization**
```cpp
int l = 0, r = arr.size() - k;
```
Here, `l` and `r` are initialized to represent the possible starting index range for the subarray of length `k` that will contain the closest elements. We initialize `r` as `arr.size() - k` because we are looking for a subarray that ends at `r + k - 1` without exceeding the size of the array.

#### 3. **Binary Search Loop**
```cpp
while (l < r) {
    int m = (l + r) / 2;
    if (x - arr[m] > arr[m + k] - x) {
        l = m + 1;
    } else {
        r = m;
    }
}
```
In the binary search loop:
- We calculate the midpoint `m` of the current search range `[l, r]`.
- We compare the proximity of `x` to the first element of the potential subarray (`arr[m]`) and the last element of the subarray (`arr[m + k]`).
  - If the difference `x - arr[m]` (distance from `x` to the starting element of the subarray) is greater than `arr[m + k] - x` (distance from `x` to the ending element of the subarray), it indicates that the subarray starting from `m + 1` will likely be closer to `x`.
  - Otherwise, we keep searching in the left half by adjusting `r = m`.

#### 4. **Extracting the Result**
```cpp
return vector<int>(arr.begin() + l, arr.begin() + l + k);
```
After binary search concludes, `l` represents the starting index of the `k` closest elements in the array. We create a new vector using the `begin()` and `end()` iterators to extract the `k` closest elements from the array and return them.

### Complexity

#### Time Complexity:
- **Binary Search:**  
  The binary search runs in **O(log(n - k))** time, where `n` is the size of the array. This is because we are reducing the search range by half at each step, searching within a range of possible starting points for the subarray of length `k`.
  
- **Subarray Extraction:**  
  After finding the correct starting point using binary search, the final step involves copying `k` elements from the array, which takes **O(k)** time.

Thus, the total time complexity is **O(log(n - k) + k)**. In the worst case, this simplifies to **O(log n + k)**.

#### Space Complexity:
- We are using **O(k)** additional space to store the result, which contains the `k` closest elements.

Therefore, the space complexity is **O(k)**.

### Conclusion

This solution efficiently solves the problem of finding the `k` closest elements to `x` in a sorted array using a binary search approach. By narrowing down the range of possible starting indices using binary search, we achieve a **logarithmic time complexity** for the search part, followed by a linear pass to extract the result. This makes the solution both time-efficient and space-efficient, particularly when the number of closest elements `k` is much smaller than the size of the array `n`.

This approach is particularly effective for large arrays, as it reduces the problem of finding the closest `k` elements to an optimal solution with logarithmic time complexity for searching and linear time complexity for extraction. This solution is ideal for applications where performance is crucial, such as real-time data processing or large-scale analytics.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-k-closest-elements/description/)

---
{{< youtube o-YDQzHoaKM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
