
+++
authors = ["grid47"]
title = "Leetcode 395: Longest Substring with At Least K Repeating Characters"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 395: Longest Substring with At Least K Repeating Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Divide and Conquer","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/395.webp"
youtube = "bHZkCAcj3dc"
youtube_upload_date="2020-07-17"
youtube_thumbnail="https://i.ytimg.com/vi/bHZkCAcj3dc/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGMgZShMMA8=&rs=AOn4CLCuVJe9ynceDrU12Sdzi3WrnCQ1Pg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/395.webp" 
    alt="A string with glowing characters highlighting the longest substring with at least K repeating characters."
    caption="Solution to LeetCode 395: Longest Substring with At Least K Repeating Characters Problem"
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
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size()) return 0;
        if(k == 0) return s.size();

        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        int idx = 0;
        while(idx < s.size() && mp[s[idx]] >= k) idx++;
        if(idx == s.size()) return s.size();

        int left = longestSubstring(s.substr(0, idx), k);
        int right = longestSubstring(s.substr(idx + 1), k);

        return max(left, right);
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The challenge here is to find the longest substring in a string `s` where every character in that substring appears **at least `k` times**. If no such substring exists, the function should return `0`.

For example:
- Given the string `"aaabb"`, and `k = 3`, the longest substring is `"aaa"`, as it is the only substring where each character appears at least 3 times.
- For the string `"ababbc"`, with `k = 2`, the longest substring is `"abb"`, as both 'a' and 'b' appear at least 2 times.

---

### 🧠 Approach

We’ll solve this using a **divide and conquer** strategy to break the string down into manageable parts. The main idea is to recursively find substrings where each character appears at least `k` times.

#### Key Steps:
1. **Base Cases**: 
   - If the string is empty or `k` exceeds the string’s length, we immediately return `0`.
   - If `k == 0`, we can consider the entire string as valid, so we return the entire string's length.
2. **Frequency Map**: Build a frequency map to count how often each character appears in the string.
3. **Split the String**: As we traverse the string, we split it wherever we encounter a character that appears fewer than `k` times.
4. **Recursion**: For each substring, we apply the same process recursively.
5. **Combine Results**: After splitting, we combine the results by finding the longest valid substring from the split parts.

This approach narrows down the search space efficiently, focusing only on parts of the string that might contain valid substrings.

---

### 🔨 Step-by-Step Code Breakdown

Let's dive into how the code works, step by step:

#### Step 1: Base Cases
```cpp
if(s.size() == 0 || k > s.size()) return 0;
if(k == 0) return s.size();
```
- If the string is empty or `k` is greater than the string’s length, we can’t have any valid substring, so we return `0`.
- If `k == 0`, every substring is valid, so we return the size of the entire string.

#### Step 2: Frequency Map
```cpp
unordered_map<char, int> mp;
for(int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
}
```
- We create a frequency map `mp` to count how many times each character appears in the string.
- This allows us to quickly check if a character meets the required frequency.

#### Step 3: Splitting the String
```cpp
int idx = 0;
while(idx < s.size() && mp[s[idx]] >= k) idx++;
if(idx == s.size()) return s.size();
```
- We initialize an index `idx` to find the first character that appears less than `k` times.
- We move `idx` forward until we find a character that doesn’t meet the frequency requirement. If `idx` reaches the end of the string, it means all characters are valid, and we return the length of the entire string.

#### Step 4: Recursive Call on Substrings
```cpp
int left = longestSubstring(s.substr(0, idx), k);
int right = longestSubstring(s.substr(idx + 1), k);
```
- When we find a character that appears fewer than `k` times, we split the string at that point.
- We recursively call `longestSubstring` on the left and right substrings, splitting the problem into smaller pieces.

#### Step 5: Combine Results
```cpp
return max(left, right);
```
- After recursively solving the left and right substrings, we take the maximum of their results because we want the longest valid substring.
- The result is then returned.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **Time Complexity**: `O(n)`, where `n` is the length of the string. The algorithm scans through the string once to build the frequency map, and each recursive call works on progressively smaller substrings. So, the overall time complexity remains linear in terms of the length of the string.

#### Space Complexity:
- **Space Complexity**: `O(n)`. We use a frequency map to store the counts of characters, and the recursion stack can also go as deep as `n` in the worst case.

---

### 🏁 Conclusion

This solution effectively solves the problem by using a divide-and-conquer approach. By recursively splitting the string and focusing only on the parts that could potentially contain valid substrings, we efficiently find the longest substring where each character appears at least `k` times. With a time complexity of `O(n)` and space complexity of `O(n)`, this solution is optimal for large inputs.

Remember, breaking down the problem into smaller subproblems is key here! 🌟 Keep up the good work, and don’t forget to practice more to strengthen your problem-solving skills! 💪

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/)

---
{{< youtube bHZkCAcj3dc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
