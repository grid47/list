
+++
authors = ["grid47"]
title = "Leetcode 1218: Longest Arithmetic Subsequence of Given Difference"
date = "2024-07-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1218: Longest Arithmetic Subsequence of Given Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NpQ-ZKBNCa8"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/NpQ-ZKBNCa8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        map<int, int> mp;
        int ans = 1;
        for(int x: arr) {
            mp[x] = 1 + max(mp[x - diff], mp.count(x)? mp[x] -1 :0);
            ans = max(ans, mp[x]);
        }
        return ans;
    }
};
{{< /highlight >}}
---


### Problem Statement
The goal of this problem is to find the length of the longest subsequence in an array `arr` such that the difference between consecutive elements in the subsequence is a fixed value `diff`. A subsequence is a sequence derived from another sequence by deleting some elements without changing the order of the remaining elements. 

For instance, given an array like `[1, 5, 3, 4, 2]` and a difference of `1`, the longest valid subsequence would be `[1, 2, 3, 4]`, yielding a length of `4`.

### Approach
To solve this problem efficiently, we can use a hashmap (or in C++, a `map`) to keep track of the maximum length of subsequences that can be formed with a specific ending value. As we iterate through the array, we can compute the length of the subsequence that ends with the current number by checking how many valid subsequences exist for the number that is `diff` less than the current number.

The steps involved in the approach are:
1. Initialize a map to store the maximum lengths of subsequences ending at each number.
2. Iterate through the array, updating the map based on the current number and the maximum length of subsequences that could extend to this number.
3. Keep track of the maximum length encountered during the iteration.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
```
- **Lines 1-3**: Define the `Solution` class and the `longestSubsequence` method, which takes a vector of integers `arr` and an integer `diff` as parameters.

```cpp
        map<int, int> mp;
        int ans = 1;
```
- **Lines 4-5**: Initialize a `map<int, int> mp` to store the lengths of subsequences ending with each number. We also initialize `ans` to `1` to account for at least one element in the subsequence.

```cpp
        for(int x: arr) {
```
- **Line 6**: Begin a loop to iterate through each integer `x` in the input vector `arr`.

```cpp
            mp[x] = 1 + max(mp[x - diff], mp.count(x)? mp[x] -1 :0);
```
- **Line 7**: Update the map for the current number `x`. The value is computed as follows:
    - Start with `1`, representing the current element itself.
    - Check if there is a subsequence ending with `x - diff`. If so, add its length to the current value.
    - If `x` is already in the map, we check to ensure we do not count it again for the same element (this is managed with `mp.count(x)? mp[x] -1 :0`).

```cpp
            ans = max(ans, mp[x]);
```
- **Line 8**: Update the variable `ans` with the maximum length found so far by comparing it to `mp[x]`, which is the length of the subsequence ending at `x`.

```cpp
        return ans;
    }
};
```
- **Lines 9-11**: After processing all elements in the array, return the length of the longest subsequence found, stored in `ans`.

### Complexity
1. **Time Complexity**:
   - The time complexity of this solution is \(O(n)\), where \(n\) is the length of the input array `arr`. Each element is processed once, and map operations (insertions and lookups) are \(O(1)\) on average.

2. **Space Complexity**:
   - The space complexity is \(O(n)\) in the worst case, where each number in `arr` could be unique and thus stored in the map.

### Conclusion
The `longestSubsequence` function provides an efficient method to determine the length of the longest subsequence in an array that adheres to a specific difference constraint. By utilizing a hashmap to track the lengths of valid subsequences, the solution efficiently computes the answer in linear time. This approach is particularly useful for problems involving subsequences, allowing for quick updates and lookups. Overall, this function showcases the power of dynamic programming and hashmap data structures in solving sequence-related challenges in programming contests and software development.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/)

---
{{< youtube NpQ-ZKBNCa8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
