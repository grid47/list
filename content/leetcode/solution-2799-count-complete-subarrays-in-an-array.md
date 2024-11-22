
+++
authors = ["grid47"]
title = "Leetcode 2799: Count Complete Subarrays in an Array"
date = "2024-02-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2799: Count Complete Subarrays in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1wXkWZtSD28"
youtube_upload_date="2023-07-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1wXkWZtSD28/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt = 0;
        set<int> dist;
        map<int, int> mp;
        for(int x: nums)
            dist.insert(x);
        int cur = 0, req = dist.size();
        int j = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp.size() < req) continue;
            while(mp.size() >= req) {
                cnt+= (n - i);
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the number of **complete subarrays** in a given array `nums`. A subarray is considered complete if it contains **all the distinct elements** that appear in the entire array. A complete subarray can be of any length, starting from a single element to the full array. The goal is to count all subarrays that are complete.

### Approach

To solve this problem, we can use a **sliding window** technique along with a **hash map** (or dictionary) to keep track of the elements in the current subarray. The key idea is to maintain a window of subarrays, adjusting its boundaries to ensure that every subarray has all distinct elements that appear in the entire array.

Here’s how we can approach it:

1. **Identify the number of distinct elements**: The first step is to find out how many distinct elements exist in the given array. This is done by inserting all elements into a `set`, which automatically filters out duplicates. The size of this `set` will give us the total number of distinct elements that any complete subarray must contain.

2. **Sliding Window Technique**: The sliding window is formed by two pointers (`i` and `j`). The pointer `i` represents the right end of the window (current element being added), and `j` represents the left end of the window (elements being removed). As we slide the window, we attempt to adjust the window's size such that the subarray contains all distinct elements.

3. **Use of HashMap for Tracking Elements**: A `map` (or hash map) is used to store the count of each element within the current window. The map helps us track how many times each element appears in the window. We can easily check if a window contains all the distinct elements by checking the size of the map.

4. **Counting Complete Subarrays**: Once the window contains all distinct elements (i.e., the size of the map equals the number of distinct elements in the array), we start counting all subarrays that can be formed by the current window. The number of subarrays that can be formed with the current window is given by `(n - i)` where `n` is the total length of the array and `i` is the current index of the right pointer. For each valid window, we increment the count by this number.

5. **Shrinking the Window**: After counting the valid subarrays, we attempt to shrink the window from the left by incrementing `j`. If shrinking the window still results in a valid subarray (i.e., it still contains all the distinct elements), we continue to count more subarrays. If it no longer contains all distinct elements, we stop and move to the next position of `i`.

### Code Breakdown (Step by Step, break the code to parts)

1. **Initialization**:
   ```cpp
   set<int> dist;
   map<int, int> mp;
   for(int x: nums)
       dist.insert(x);
   int cur = 0, req = dist.size();
   int j = 0, n = nums.size();
   ```
   - A `set<int> dist` is used to store all distinct elements in the array.
   - A `map<int, int> mp` is used to track the frequency of elements within the current window.
   - The `req` variable stores the number of distinct elements in the array.
   - `j` is the left pointer of the window, and `n` is the size of the array.

2. **Main Loop (Iterating over the Array)**:
   ```cpp
   for(int i = 0; i < n; i++) {
       mp[nums[i]]++;
       if(mp.size() < req) continue;
   ```
   - The `for` loop iterates over each element in the array with the `i` pointer.
   - For each element `nums[i]`, its count is incremented in the `map`.
   - If the size of the `map` is less than `req`, the current window does not contain all distinct elements, so we continue to the next element.

3. **Counting Valid Subarrays**:
   ```cpp
   while(mp.size() >= req) {
       cnt += (n - i);
       mp[nums[j]]--;
       if(mp[nums[j]] == 0)
           mp.erase(nums[j]);
       j++;
   }
   ```
   - When the window contains all the distinct elements (i.e., the size of `mp` is greater than or equal to `req`), we start counting valid subarrays.
   - The number of valid subarrays that can be formed from the current position of `i` is given by `(n - i)`, as any subarray starting from `i` and ending anywhere from `i` to `n-1` will be complete.
   - The element at `nums[j]` is removed from the window by decrementing its count in the `map`. If its count becomes zero, it is erased from the `map`.
   - The left pointer `j` is incremented to shrink the window.

4. **Return the Result**:
   ```cpp
   return cnt;
   ```
   - After iterating through the entire array, the variable `cnt` will contain the total number of complete subarrays, which is then returned as the result.

### Complexity

1. **Time Complexity**:
   - **O(n)** where `n` is the number of elements in the array.
   - The outer loop iterates over each element of the array once, and for each element, the `j` pointer only moves forward, making it effectively a linear pass over the array. Each element is inserted and removed from the map at most once, so the overall time complexity is **O(n)**.

2. **Space Complexity**:
   - **O(n)** due to the space required to store the distinct elements in the `set` and the elements in the `map`.
   - In the worst case, if all elements in the array are distinct, the map will store all elements, and the set will contain `n` distinct elements.

### Conclusion

This solution efficiently counts the number of complete subarrays using the sliding window technique and hash map for tracking element counts. By maintaining a dynamic window, the algorithm can count all valid subarrays without having to brute force through all possible subarrays, which would be inefficient. With a time complexity of **O(n)**, this solution is optimal and works well for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/)

---
{{< youtube 1wXkWZtSD28 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
