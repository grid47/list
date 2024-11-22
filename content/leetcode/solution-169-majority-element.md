
+++
authors = ["grid47"]
title = "Leetcode 169: Majority Element"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 169: Majority Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Sorting","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/169.webp"
youtube = "M1IL4hz0QrE"
youtube_upload_date="2020-06-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/M1IL4hz0QrE/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/169.webp" 
    alt="A glowing element standing out in a sequence, symbolizing its majority status."
    caption="Solution to LeetCode 169: Majority Element Problem"
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
    int majorityElement(vector<int>& nums) {
        int e = nums[0], cnt = 1;
        map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] > cnt) {
                cnt = mp[x];
                e = x;
            }
        }
        return e;
    }
};
{{< /highlight >}}
---

### 🌟 Majority Element

The problem is to find the majority element in an array `nums`, which is defined as the element that appears more than **n/2** times, where `n` is the size of the array. If such an element exists, the function should return it.

#### Example:
- In the array `[3, 2, 3]`, the majority element is `3`.
- In the array `[2, 2, 1, 1, 1, 2, 2]`, the majority element is `2`.

The problem guarantees that a majority element will always exist.

### 💡 Approach

To solve the problem efficiently, we need to identify the element that appears more than half the times in the array. A brute force approach would involve checking the occurrences of each element, but that could be inefficient with **O(n²)** time complexity. Instead, we use a more efficient method utilizing a frequency map (hash map).

Here’s the plan:
1. We will iterate through the array and maintain a frequency map (`map<int, int> mp`) that tracks the count of each element.
2. As we process each element, we will update the count and keep track of the element with the highest frequency.
3. At the end, we will return the element with the maximum frequency as the majority element.

### 🔍 Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int e = nums[0], cnt = 1;
map<int, int> mp;
```
- `e` is initialized to the first element of the array, and `cnt` is initialized to `1` because we've already seen the first element.
- `mp` is a frequency map that will store the count of each element.

#### Step 2: Iterate Through the Array

```cpp
for(int x: nums) {
    mp[x]++;
```
- We iterate through each element `x` in the array `nums`.
- For each element, we increment its count in the map (`mp[x]++`).

#### Step 3: Track the Majority Element

```cpp
    if(mp[x] > cnt) {
        cnt = mp[x];
        e = x;
    }
}
```
- For every element, we check if its count in the map exceeds the current maximum count (`cnt`).
- If the count is higher, we update `cnt` to the new count and set `e` to the current element `x`.

#### Step 4: Return the Majority Element

```cpp
return e;
```
- After iterating through all elements, we return `e`, which holds the majority element — the one with the highest frequency.

### 📊 Complexity Analysis

#### Time Complexity:
- **O(n)**: We iterate through the array once, and for each element, the map operations (`mp[x]++`) are **O(1)** on average. Thus, the overall time complexity is linear, **O(n)**, where `n` is the size of the array.

#### Space Complexity:
- **O(n)**: The space complexity is determined by the size of the frequency map `mp`. In the worst case, all elements could be unique, resulting in a map size of `n`. Hence, the space complexity is **O(n)**.

### ✅ Conclusion

This solution efficiently finds the majority element using a frequency map, operating in linear time **O(n)** and with a space complexity of **O(n)**. The approach guarantees that the majority element will be identified as specified in the problem.

#### Key Takeaways:
- **Efficient Time Complexity**: The solution runs in **O(n)** time, making it suitable for large arrays.
- **Space Complexity**: The space complexity is **O(n)** due to the use of a map to store frequencies.
- **Majority Element**: This method ensures that we find the majority element, as the problem guarantees its existence.

This approach provides an optimal and straightforward solution to the majority element problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/majority-element/description/)

---
{{< youtube M1IL4hz0QrE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
