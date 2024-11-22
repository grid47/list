
+++
authors = ["grid47"]
title = "Leetcode 2540: Minimum Common Value"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2540: Minimum Common Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "pbKnQYJuSY0"
youtube_upload_date="2023-01-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pbKnQYJuSY0/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int x: nums1)
            mp[x] = true;
        for(int y: nums2)
            if(mp.count(y))
                return y;
        return -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are given two arrays `nums1` and `nums2`. Our task is to find the first common element between these two arrays. If no common element is found, return `-1`. The solution should be efficient and handle the constraints optimally.

### Approach

To solve this problem, we will use a hash map (or unordered_map in C++) to store elements from one array and then check for common elements in the second array. The idea is to efficiently find the first common element between the two arrays by leveraging constant-time lookups offered by hash maps.

#### Steps:
1. **Insert Elements into a Hash Map**: First, we insert each element from `nums1` into an unordered map (`mp`). This allows us to quickly check if any element from `nums2` exists in `nums1`.
2. **Iterate Through `nums2`**: After storing all elements from `nums1`, we loop through `nums2` and check if any element exists in the hash map. The first time we find a match, we return that element as the first common element.
3. **Return -1 if No Common Element is Found**: If we finish the loop through `nums2` without finding a common element, we return `-1`.

This approach uses the unordered_map for constant-time lookups, making the solution more efficient than a brute-force approach.

### Code Breakdown (Step by Step)

#### Step 1: Create an Unordered Map
```cpp
unordered_map<int, int> mp;
```
Here, we declare an unordered map `mp`. This map will store the elements of `nums1` as keys. We set the value of each key to `true` (or any arbitrary value) to mark its existence in `nums1`.

#### Step 2: Insert Elements from `nums1` into the Map
```cpp
for(int x: nums1)
    mp[x] = true;
```
In this step, we iterate over each element `x` in `nums1` and insert it into the unordered map `mp`. By doing this, we ensure that we can check the existence of any element from `nums2` in constant time later on.

#### Step 3: Check for Common Elements in `nums2`
```cpp
for(int y: nums2)
    if(mp.count(y))
        return y;
```
We now loop through each element `y` in `nums2`. The `mp.count(y)` function checks whether `y` is present in the map `mp`. If it is, we immediately return `y` because it is the first common element between `nums1` and `nums2`.

#### Step 4: Return `-1` if No Common Element is Found
```cpp
return -1;
```
If we reach the end of the second loop without finding a common element, we return `-1` as specified in the problem statement. This indicates that no common element exists between `nums1` and `nums2`.

### Complexity Analysis

#### Time Complexity:
- **Building the Hash Map**: Inserting elements from `nums1` into the unordered map takes `O(n)` time, where `n` is the length of `nums1`.
- **Checking for Common Elements**: Iterating through `nums2` and performing constant-time lookups in the unordered map takes `O(m)` time, where `m` is the length of `nums2`.
- **Overall Time Complexity**: The total time complexity is `O(n + m)`, where `n` is the size of `nums1` and `m` is the size of `nums2`. This is because we iterate over each array once, and each lookup operation in the unordered map is `O(1)` on average.

#### Space Complexity:
- **Space for the Hash Map**: The space required for the unordered map `mp` is `O(n)`, where `n` is the number of elements in `nums1`. This is because we store each element of `nums1` in the map.
- **Overall Space Complexity**: The space complexity is `O(n)` due to the storage of `nums1` in the hash map.

### Conclusion

This solution efficiently finds the first common element between two arrays using an unordered map for constant-time lookups. The time complexity is linear, `O(n + m)`, where `n` and `m` are the sizes of the input arrays `nums1` and `nums2`. The space complexity is also linear, `O(n)`, due to the hash map storing the elements of `nums1`.

By using a hash map, we avoid the need for a nested loop, which would have resulted in a quadratic time complexity. This approach is optimal and scales well for large input sizes, making it a good choice for solving this problem within the given constraints.



[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-common-value/description/)

---
{{< youtube pbKnQYJuSY0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
