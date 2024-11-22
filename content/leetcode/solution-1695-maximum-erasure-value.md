
+++
authors = ["grid47"]
title = "Leetcode 1695: Maximum Erasure Value"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1695: Maximum Erasure Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XIFl0gXnq9s"
youtube_upload_date="2020-12-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XIFl0gXnq9s/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        map<int, int> mp;
        
        int mx = 0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            sum += nums[i];
            
            while(mp[nums[i]] > 1) {
                mp[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            
            mx = max(mx, sum);
        }
        return mx;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to find the maximum sum of a unique subarray from a given integer array `nums`. A unique subarray is defined as a contiguous segment of the array that contains no duplicate elements. Our goal is to identify such a subarray and return the highest possible sum of its elements.

### Approach

To tackle this problem, we can use a sliding window technique combined with a hash map (or dictionary) to keep track of the count of each element within the current window. The sliding window will allow us to expand and contract the range of the subarray as we iterate through the array. Here’s the general approach:

1. **Initialize Variables**: We will maintain a sum of the current window, a maximum sum encountered so far, and a hash map to count occurrences of each element in the current window.

2. **Expand the Window**: We will iterate through the array, adding elements to the current window while updating the sum and the count of elements in the hash map.

3. **Contract the Window**: If we encounter a duplicate element (i.e., the count in the hash map exceeds 1), we will increment the start of the window to remove elements from the left until the subarray becomes unique again.

4. **Update Maximum Sum**: After adjusting the window, we check if the current sum is greater than our previously recorded maximum sum and update accordingly.

5. **Return the Result**: After processing all elements, we return the maximum sum of unique subarrays found.

### Code Breakdown (Step by Step)

Here is a detailed breakdown of the code implementation:

```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
```
- **Class Definition**: The `Solution` class contains the method `maximumUniqueSubarray`, which takes a vector of integers as input.

```cpp
        int sum = 0, n = nums.size();
        map<int, int> mp;
```
- **Variable Initialization**: We initialize `sum` to keep track of the current sum of the unique subarray, `n` as the size of the input array, and a map `mp` to count occurrences of elements in the current window.

```cpp
        int mx = 0;
        int j = 0;
```
- **Maximum Sum and Window Start Index**: We define `mx` to hold the maximum sum encountered and `j` as the start index of the sliding window.

```cpp
        for(int i = 0; i < n; i++) {
```
- **Iterating Through the Array**: We start a loop to iterate over the elements of the array with index `i`.

```cpp
            mp[nums[i]]++;
            sum += nums[i];
```
- **Add Current Element**: For each element at index `i`, we increment its count in the map and add its value to `sum`.

```cpp
            while(mp[nums[i]] > 1) {
```
- **Check for Duplicates**: We enter a while loop that checks if the current element is a duplicate (i.e., its count in the map is greater than 1).

```cpp
                mp[nums[j]]--;
                sum -= nums[j];
                j++;
```
- **Contract the Window**: Inside the while loop, if a duplicate is found, we decrement the count of the element at index `j` in the map, subtract its value from `sum`, and increment `j` to effectively move the start of the window forward.

```cpp
            mx = max(mx, sum);
```
- **Update Maximum Sum**: After adjusting the window, we compare the current `sum` with `mx` and update `mx` if the current `sum` is greater.

```cpp
        return mx;
    }
};
```
- **Return the Result**: After the loop finishes, we return the maximum sum of unique subarrays found.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(N)\), where \(N\) is the number of elements in the input array. Each element is processed at most twice (once when added and once when removed from the window).

- **Space Complexity**: The space complexity is \(O(M)\), where \(M\) is the number of unique elements in the input array. This is due to the storage required for the hash map that tracks the count of elements in the current window.

### Conclusion

The provided solution effectively utilizes the sliding window technique combined with a hash map to find the maximum sum of unique subarrays in linear time. Here are the key points to summarize:

1. **Sliding Window Technique**: The sliding window allows for efficient tracking of the current subarray while maintaining uniqueness by dynamically adjusting the window size.

2. **Use of Hash Map**: The hash map provides an efficient way to check for duplicates and manage the counts of elements within the current window, enabling quick adjustments as the window moves.

3. **Dynamic Sum Calculation**: By maintaining a running sum, we can efficiently update the maximum sum without the need for nested loops, making the solution optimal.

This code can be applied in various scenarios where the maximum sum of distinct elements is desired, demonstrating a common pattern in competitive programming and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-erasure-value/description/)

---
{{< youtube XIFl0gXnq9s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
