
+++
authors = ["grid47"]
title = "Leetcode 2053: Kth Distinct String in an Array"
date = "2024-04-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2053: Kth Distinct String in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "1KOnvGPv9Mo"
youtube_upload_date="2024-08-05"
youtube_thumbnail="https://i.ytimg.com/vi/1KOnvGPv9Mo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto &s : arr)
            ++mp[s];
        for (auto &s : arr)
            if (mp[s] == 1 && --k == 0)
                return s;
        return "";
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the k-th "distinct" string in an array of strings, where a string is considered distinct if it only appears once in the array. The input is a list of strings `arr` and an integer `k`, representing the position of the distinct string to return. If there are fewer than `k` distinct strings, we should return an empty string.

### Approach

This solution uses a two-pass approach:
1. **Count Occurrences**: In the first pass, count the occurrences of each string in `arr` using a hash map.
2. **Identify the k-th Distinct String**: In the second pass, iterate through `arr` again, checking for distinct strings. For each distinct string encountered, decrement `k`. When `k` reaches zero, we have found the k-th distinct string.

### Code Breakdown (Step by Step)

1. **Class and Method Definition**: The class `Solution` contains the function `kthDistinct`, which accepts a vector of strings `arr` and an integer `k`.

    ```cpp
    class Solution {
    public:
        string kthDistinct(vector<string>& arr, int k) {
    ```

2. **Count Each String's Occurrence**: We define a hash map `mp` to store the count of each string in `arr`. For each string `s` in `arr`, increment its count in `mp`.

    ```cpp
    unordered_map<string, int> mp;
    for (auto &s : arr)
        ++mp[s];
    ```

3. **Second Pass to Find the k-th Distinct String**: After counting, we make another pass through `arr`. For each string `s`:
   - If `mp[s]` equals `1`, the string is distinct.
   - Decrement `k` for each distinct string encountered.
   - When `k` reaches zero, we return the current string `s` as the k-th distinct string.

    ```cpp
    for (auto &s : arr)
        if (mp[s] == 1 && --k == 0)
            return s;
    ```

4. **Return Empty String if k-th Distinct Not Found**: If the loop completes without finding the k-th distinct string, return an empty string.

    ```cpp
    return "";
    ```

5. **Complete Code**: The full code structure is as follows:

    ```cpp
    class Solution {
    public:
        string kthDistinct(vector<string>& arr, int k) {
            unordered_map<string, int> mp;
            for (auto &s : arr)
                ++mp[s];
            for (auto &s : arr)
                if (mp[s] == 1 && --k == 0)
                    return s;
            return "";
        }
    };
    ```

### Complexity

- **Time Complexity**: O(N), where N is the number of strings in `arr`. Both passes over `arr` are O(N), and accessing or updating the hash map is O(1) on average.
- **Space Complexity**: O(N), due to the hash map `mp` storing counts for each unique string in `arr`.

### Conclusion

This solution effectively finds the k-th distinct string by counting occurrences and filtering distinct entries. The use of a hash map ensures efficient lookups and counting, making this approach optimal for large arrays. By minimizing operations and handling both distinct string filtering and index tracking in a single pass, this method provides a clear, concise solution for finding the k-th distinct element in any given list of strings. This code structure is well-suited for quick lookups and frequency-based filtering tasks in competitive programming or real-world scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-distinct-string-in-an-array/description/)

---
{{< youtube 1KOnvGPv9Mo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
