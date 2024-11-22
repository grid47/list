
+++
authors = ["grid47"]
title = "Leetcode 2150: Find All Lonely Numbers in the Array"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2150: Find All Lonely Numbers in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "oX00CiVJ00Q"
youtube_upload_date="2022-01-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/oX00CiVJ00Q/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num: nums) mp[num]++;

        vector<int> res;
        for(auto [x, cnt]: mp) {
            if(cnt == 1 && !mp.count(x - 1) && !mp.count(x +1))
                res.push_back(x);
        }

        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement
Given an array of integers `nums`, a number is defined as *lonely* if it meets two conditions:
1. The number appears exactly once in the array.
2. Neither of its adjacent numbers (`x - 1` or `x + 1`) exist in the array.

The goal is to return a list of all such lonely numbers in the input array.

### Approach
The approach to solve this problem efficiently leverages a hash map to count occurrences of each number in the array. By counting the occurrences, we can identify numbers that only appear once. Additionally, using the map, we can check whether adjacent numbers (`x - 1` or `x + 1`) exist, ensuring that the number is truly *lonely*.

### Code Breakdown (Step by Step)
1. **Initialization of the Hash Map:**
   ```cpp
   unordered_map<int, int> mp;
   ```
   - This map, `mp`, will store each number as the key and its frequency as the value.

2. **Counting Frequencies:**
   ```cpp
   for(int num: nums) mp[num]++;
   ```
   - Loop through each number in `nums` and populate the map with the count of occurrences for each number.

3. **Finding Lonely Numbers:**
   ```cpp
   vector<int> res;
   for(auto [x, cnt]: mp) {
       if(cnt == 1 && !mp.count(x - 1) && !mp.count(x + 1))
           res.push_back(x);
   }
   ```
   - Create a result vector `res` to store lonely numbers.
   - Iterate over the map, checking each number (`x`) and its count (`cnt`).
   - If `cnt` equals 1 (indicating the number appears exactly once), and neither `x - 1` nor `x + 1` exist in `mp`, add `x` to the result list.

4. **Return Result:**
   ```cpp
   return res;
   ```
   - Return the `res` vector containing all lonely numbers.

### Complexity
- **Time Complexity**: 
  - The code runs in O(n) time, where `n` is the number of elements in the input array. This is because counting the elements and then checking conditions for each element both take O(n).
- **Space Complexity**: 
  - The space complexity is O(n) due to the hash map `mp` storing up to `n` keys and the result vector `res`.

### Conclusion
The code provided is an efficient solution for finding lonely numbers in an array. It uses a hash map for quick lookups, ensuring that the solution runs in linear time. This makes the algorithm suitable for large input sizes where O(n) performance is required. The conditions for loneliness are thoroughly checked in one pass after counting the elements, striking an optimal balance between simplicity and performance.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/)

---
{{< youtube oX00CiVJ00Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
