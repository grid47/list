
+++
authors = ["grid47"]
title = "Leetcode 1647: Minimum Deletions to Make Character Frequencies Unique"
date = "2024-05-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1647: Minimum Deletions to Make Character Frequencies Unique in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "h8AZEN49gTc"
youtube_upload_date="2023-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/h8AZEN49gTc/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDeletions(string s) {
        map<char, int> mp;
        int n= s.size();
        for(char x: s)
            mp[x]++;
        vector<pair<int, char>> arr;
        for(auto it: mp) {
            arr.push_back({it.second, it.first});
        }
        sort(arr.begin(), arr.end());
        n = arr.size();
        set<int> cnt;
        int del = 0;
        for(int i = 0; i < n; i++) {
            int tmp = arr[i].first;
            while(tmp > 0 && cnt.count(tmp)) {
                tmp--;
                del++;
            }
            if(tmp > 0) cnt.insert(tmp);
        }
        return del;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal is to determine the minimum number of deletions needed from a string \( s \) such that the frequencies of all characters in the string become unique. This problem is particularly relevant in scenarios where unique frequency distributions are required, such as in cryptography or data compression.

### Approach

To solve this problem, the following steps are taken:

1. **Count Character Frequencies**: Use a map to count the frequency of each character in the string.
2. **Create a Frequency List**: Store the frequencies in a vector along with their corresponding characters for further processing.
3. **Sort Frequencies**: Sort the frequency list in ascending order to facilitate the identification of duplicates.
4. **Track Unique Frequencies**: Use a set to track the frequencies that have already been used. Iterate through the sorted frequency list and decrement the frequency as needed until a unique frequency is found or it reaches zero.
5. **Count Deletions**: Keep a count of how many deletions are made to achieve unique frequencies.

### Code Breakdown (Step by Step)

Let’s break down the provided code:

```cpp
class Solution {
public:
    int minDeletions(string s) {
```
- We define a class `Solution` and a public method `minDeletions` that accepts a string \( s \) as input.

```cpp
        map<char, int> mp;
        int n = s.size();
        for (char x : s)
            mp[x]++;
```
- We initialize a map `mp` to store the frequency of each character. We iterate through the string \( s \), incrementing the count for each character encountered.

```cpp
        vector<pair<int, char>> arr;
        for (auto it : mp) {
            arr.push_back({it.second, it.first});
        }
```
- We create a vector `arr` to hold pairs of frequencies and their corresponding characters. We iterate through the map `mp` and populate the vector with frequency-character pairs.

```cpp
        sort(arr.begin(), arr.end());
```
- We sort the vector `arr` based on frequencies in ascending order. This allows us to efficiently manage the deletion of duplicate frequencies.

```cpp
        n = arr.size();
        set<int> cnt;
        int del = 0;
```
- We store the size of the sorted frequency list in \( n \), initialize an empty set `cnt` to keep track of used frequencies, and a variable `del` to count the total deletions needed.

```cpp
        for (int i = 0; i < n; i++) {
            int tmp = arr[i].first;
            while (tmp > 0 && cnt.count(tmp)) {
                tmp--;
                del++;
            }
```
- We iterate through the sorted frequency list. For each frequency, we temporarily store it in `tmp`. A `while` loop is employed to decrement `tmp` as long as it is greater than zero and exists in the set `cnt`. Each time we decrement `tmp`, we increment the deletion count `del`.

```cpp
            if (tmp > 0) cnt.insert(tmp);
        }
```
- If after the loop `tmp` is still greater than zero, it means we found a unique frequency. We insert this unique frequency into the set `cnt`.

```cpp
        return del;
    }
};
```
- Finally, we return the total count of deletions required to make all character frequencies unique.

### Complexity

- **Time Complexity**: 
  - Counting character frequencies takes \( O(n) \) time, where \( n \) is the length of the string \( s \).
  - Storing frequencies in a vector and sorting it takes \( O(k \log k) \), where \( k \) is the number of unique characters in the string (at most 26 for lowercase English letters).
  - The overall complexity is \( O(n + k \log k) \).

- **Space Complexity**: 
  - The space complexity is \( O(k) \) due to the storage of the frequency map and the vector that holds frequency-character pairs.

### Conclusion

The `minDeletions` method efficiently calculates the minimum number of deletions required to ensure all character frequencies in a string are unique. By utilizing a combination of frequency counting, sorting, and unique frequency tracking, the solution effectively addresses the problem while maintaining optimal performance.

**Key Takeaways**:
1. **Utilization of Maps and Sets**: This solution demonstrates effective use of maps for counting and sets for tracking unique elements, which is a common strategy in algorithmic challenges.
2. **Sorting for Efficient Comparison**: Sorting the frequencies simplifies the process of checking for duplicates and managing deletions, showcasing a typical approach in greedy algorithms.
3. **Efficiency Considerations**: The approach is efficient in both time and space, making it suitable for handling large input strings within reasonable limits.

This method can be adapted for various applications where unique constraints are needed on collections of items, making it a versatile technique in the programmer's toolkit.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/)

---
{{< youtube h8AZEN49gTc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
