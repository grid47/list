
+++
authors = ["grid47"]
title = "Leetcode 2780: Minimum Index of a Valid Split"
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2780: Minimum Index of a Valid Split in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qhvhUTBnYd8"
youtube_upload_date="2023-07-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/qhvhUTBnYd8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        int dom = -1;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(2 * mp[nums[i]] > n) {
                dom = nums[i];
            }
        }
        
        int frq = mp[dom];
        
        int l = 0, r = frq;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == dom) {
                l++;
                r--;
            }
            if(2 * l > (i + 1) && 2 * r > (n - (i + 1)))
                return i;
        }
        return -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine the index of the smallest position in the array `nums` such that the element at that index is the majority element (appears more than half of the time) in both the prefix (from the start to that index) and the suffix (from that index to the end) of the array.

### Approach

To solve this problem, we need to first identify the majority element in the entire array. Then, we check at each index whether the prefix and suffix of the array both have this majority element and that it appears more than half the times in both parts.

### Steps to Solve:

1. **Identify the Majority Element**: 
    - We begin by counting the frequency of each element in the array. The element with a frequency greater than half of the size of the array (`n / 2`) is the majority element, also known as the "dominating" element.

2. **Divide the Array**:
    - We check each index in the array and treat the part of the array before it as the prefix and the part after it as the suffix.

3. **Prefix and Suffix Condition**:
    - We need to verify whether this majority element appears more than half the times in both the prefix and suffix. If it does, we return that index.
    - The check for the prefix is done by maintaining a count of how many times the majority element appears in the prefix and comparing it to half the current prefix length.
    - Similarly, for the suffix, we check how many times the majority element appears after the current index and compare it to half the length of the suffix.

### Code Breakdown

#### Step 1: Finding the Majority Element
```cpp
map<int, int> mp;
int n = nums.size();
int dom = -1;
for(int i = 0; i < n; i++) {
    mp[nums[i]]++;
    if(2 * mp[nums[i]] > n) {
        dom = nums[i];
    }
}
```
- **`mp`**: A map `mp` is used to store the frequency of each number in the array.
- **`n`**: This variable stores the size of the array `nums`.
- **`dom`**: The majority element is stored in the variable `dom`.
    - For every element in the array, we increase its frequency in `mp`.
    - If the frequency of an element exceeds half the size of the array (i.e., `2 * mp[nums[i]] > n`), we set that element as the majority element `dom`.

#### Step 2: Calculate the Frequency of the Majority Element
```cpp
int frq = mp[dom];
```
- **`frq`**: This variable stores the frequency of the majority element in the entire array. It will be used later to compare with the number of times the majority element appears in the prefix and suffix parts.

#### Step 3: Split the Array into Prefix and Suffix
```cpp
int l = 0, r = frq;

for(int i = 0; i < n - 1; i++) {
    if(nums[i] == dom) {
        l++;
        r--;
    }
    if(2 * l > (i + 1) && 2 * r > (n - (i + 1)))
        return i;
}
```
- **`l` and `r`**: These variables represent the number of times the majority element appears in the prefix and suffix, respectively. Initially, `l` is 0 (nothing has been added to the prefix yet) and `r` is set to `frq` (all occurrences of the majority element are in the suffix).
- The loop iterates over each index `i` (from 0 to `n-2`). For each index, we update `l` and `r`:
    - If `nums[i]` equals `dom`, we increase `l` (because we've added one more occurrence of the majority element to the prefix) and decrease `r` (since that occurrence is no longer in the suffix).
- After updating `l` and `r`, we check whether both the prefix and the suffix contain more than half of their respective lengths as the majority element:
    - **`2 * l > (i + 1)`** checks if the majority element appears more than half the times in the prefix.
    - **`2 * r > (n - (i + 1))`** checks if the majority element appears more than half the times in the suffix.
- If both conditions are true, we return the current index `i` as the result.

#### Step 4: Return the Final Result
```cpp
return -1;
```
- If no index satisfies the condition, we return `-1` indicating no such index exists.

### Complexity

#### Time Complexity:
- **O(n)**: The algorithm makes two passes through the array:
    - The first pass is used to determine the majority element by counting the frequencies (O(n)).
    - The second pass is used to check the prefix and suffix conditions for each index (O(n)).
- Therefore, the overall time complexity is **O(n)**.

#### Space Complexity:
- **O(n)**: The algorithm uses a map `mp` to store the frequency of each element in the array. In the worst case, if all elements in the array are unique, the space complexity will be O(n).

### Conclusion

This approach efficiently identifies the index where the element is the majority in both the prefix and the suffix of the array. It uses a combination of frequency counting and dynamic updating of the prefix and suffix counts, making it an optimal solution with a time complexity of **O(n)**.

The solution effectively leverages the majority element property and updates counts incrementally to find the required index. This approach is optimal in terms of both time and space, making it highly suitable for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-index-of-a-valid-split/description/)

---
{{< youtube qhvhUTBnYd8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
