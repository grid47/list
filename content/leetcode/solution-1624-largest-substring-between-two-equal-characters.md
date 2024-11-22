
+++
authors = ["grid47"]
title = "Leetcode 1624: Largest Substring Between Two Equal Characters"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1624: Largest Substring Between Two Equal Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rfjeFs3JuYM"
youtube_upload_date="2020-12-21"
youtube_thumbnail="https://i.ytimg.com/vi/rfjeFs3JuYM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        map<char, int> mp;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(mp.count(s[i])) {
                ans = max(ans, i - mp[s[i]] - 1);
            }
            if(!mp.count(s[i])) {
                mp[s[i]] = i;
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the maximum length of a substring in a given string \( s \) that exists between two equal characters. In other words, we need to find the largest distance between two identical characters in the string while excluding those characters from the count. If no such characters exist, the function should return \(-1\).

### Approach

To solve this problem efficiently, we can use a single pass through the string combined with a hash map (or unordered map) to keep track of the last seen index of each character. The approach can be summarized in the following steps:

1. **Initialize a Hash Map**: Use a hash map to store the last seen index of each character as we traverse the string.
  
2. **Iterate Through the String**: For each character in the string:
   - Check if the character has been seen before:
     - If yes, calculate the distance between the current index and the last seen index of that character.
     - Update the maximum length if the calculated distance is greater than the previous maximum.
   - If the character is encountered for the first time, store its index in the hash map.

3. **Return the Result**: At the end of the iteration, return the maximum length found, or \(-1\) if no pairs of identical characters were found.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code:

```cpp
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
```
- The class `Solution` contains a public method `maxLengthBetweenEqualCharacters` that takes a string \( s \) as input.

```cpp
        int n = s.size();
        map<char, int> mp;
        int ans = -1;
```
- We first determine the size of the string \( n \).
- We declare a map `mp` to store the last seen index of each character.
- We initialize `ans` to \(-1\) to signify that if we don’t find any matching characters, we will return \(-1\).

```cpp
        for(int i = 0; i < n; i++) {
```
- We start a loop that iterates over each character in the string.

```cpp
            if(mp.count(s[i])) {
                ans = max(ans, i - mp[s[i]] - 1);
            }
```
- Inside the loop, we check if the character \( s[i] \) has been seen before using `mp.count(s[i])`.
- If it has been seen, we calculate the distance from its last occurrence:
  - `i` is the current index, and `mp[s[i]]` gives the last index where the character was found.
  - We subtract \( 1 \) to exclude the characters themselves from the count.
- We then update `ans` to be the maximum of its current value and the newly calculated distance.

```cpp
            if(!mp.count(s[i])) {
                mp[s[i]] = i;
            }
```
- If the character has not been seen before, we record its index in the hash map: `mp[s[i]] = i`.

```cpp
        }
        return ans;
    }
};
```
- After the loop finishes, we return the maximum distance found, which is stored in `ans`.

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n) \), where \( n \) is the length of the string. This is because we traverse the string once and perform constant time operations for each character.
  
- **Space Complexity**: The space complexity is \( O(1) \) in terms of character set, as the maximum number of unique characters is limited (for example, 26 lowercase letters or 128 ASCII characters). Thus, the space used by the hash map will not exceed this limit.

### Conclusion

The presented solution efficiently finds the maximum length of the substring between two equal characters by leveraging a single traversal and a hash map for constant time lookups. This approach is optimal and scales well with larger inputs.

**Key Takeaways**:
1. **Hash Maps for Efficient Lookups**: Using a hash map allows us to store and retrieve indices quickly, leading to a linear time complexity.
2. **Single Pass Algorithms**: Whenever possible, aim to solve problems in a single pass to optimize performance.
3. **Handling Edge Cases**: The solution accounts for cases where no equal characters exist by returning \(-1\), ensuring robust output.

This technique can be applied to various similar problems involving substring analysis, character frequency counting, and more. Understanding the utility of hash maps and efficient traversal methods is crucial for tackling such algorithmic challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/)

---
{{< youtube rfjeFs3JuYM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
