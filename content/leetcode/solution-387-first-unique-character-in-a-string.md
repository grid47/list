
+++
authors = ["grid47"]
title = "Leetcode 387: First Unique Character in a String"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 387: First Unique Character in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Queue","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/387.webp"
youtube = "nFiAUwTH0zY"
youtube_upload_date="2020-05-05"
youtube_thumbnail="https://i.ytimg.com/vi/nFiAUwTH0zY/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/387.webp" 
    alt="A glowing string with the first unique character softly highlighted."
    caption="Solution to LeetCode 387: First Unique Character in a String Problem"
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
    int firstUniqChar(string s) {
        
        map<char, int> mp;
        for(char x: s) mp[x]++;
        
        for(int i = 0; i < s.size(); i++)
            if(mp[s[i]] == 1) return i;
        
        return -1;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

We need to find the **first unique character** in a given string `s`. A character is considered unique if it appears exactly once in the string. If there's no unique character, we return `-1`.

For example, for the input string `s = "leetcode"`, the output should be `0` because the first unique character is `'l'`, which is at index `0`.

---

### 🧠 Approach

To solve this problem, we’ll use a **two-pass approach**:

1. **Count the frequency** of each character in the string.
2. **Iterate again** to find the first character with a frequency of `1`.

The solution uses a **map** (or hash map) to store character frequencies, which allows us to efficiently count occurrences and find the first unique character in linear time.

Here’s how the solution works step by step:

- In the **first pass**, count how many times each character appears.
- In the **second pass**, go through the string and check the frequency of each character. The first character with a count of `1` is returned.

---

### 🔨 Step-by-Step Code Breakdown

Here’s the code that implements this solution:

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, int> mp;
        for(char x: s) mp[x]++;
        
        for(int i = 0; i < s.size(); i++)
            if(mp[s[i]] == 1) return i;
        
        return -1;
    }
};
```

#### 1. **Class Declaration**
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
```
- We define the `Solution` class with a public method `firstUniqChar` that takes a string `s` as input.

#### 2. **Count Character Occurrences**
```cpp
map<char, int> mp;
for(char x: s) mp[x]++;
```
- A `map<char, int>` named `mp` is used to store the frequency of each character in the string `s`. 
- We loop through the string and update the map with the frequency of each character.

#### 3. **Find the First Unique Character**
```cpp
for(int i = 0; i < s.size(); i++)
    if(mp[s[i]] == 1) return i;
```
- We loop through the string again. For each character, we check if its frequency is `1` in the map. 
- If we find such a character, we immediately return its index.

#### 4. **Handle No Unique Character**
```cpp
return -1;
```
- If no unique character is found, we return `-1`, indicating that there is no unique character in the string.

---

### 📈 Complexity Analysis

- **Time Complexity**: **O(n)**, where `n` is the length of the string `s`.
  - The first loop takes **O(n)** time to count character occurrences.
  - The second loop also takes **O(n)** time to find the first unique character.
  - Hence, the total time complexity is **O(n)**, making this an efficient solution for large strings.
  
- **Space Complexity**: **O(n)**, where `n` is the number of unique characters in the string.
  - The space is used by the map `mp` to store character frequencies. In the worst case, every character could be unique, requiring **O(n)** space.

---

### 🏁 Conclusion

This solution efficiently solves the problem of finding the **first unique character** in a string using a **two-pass approach** with a map:

1. **First pass**: Count the occurrences of each character.
2. **Second pass**: Find the first character with a frequency of `1`.

With a time complexity of **O(n)** and a space complexity of **O(n)**, this solution is both time and space-efficient. It is optimal for handling strings of varying sizes while maintaining clarity and simplicity.

### 🎯 Key Takeaways:
- The **two-pass approach** ensures we efficiently process the string.
- Using a **map** allows us to count character frequencies and quickly find the first unique character.
- This solution is fast and works well for both small and large inputs.

Keep up the great work, and keep coding! 💪

[`Link to LeetCode Lab`](https://leetcode.com/problems/first-unique-character-in-a-string/description/)

---
{{< youtube nFiAUwTH0zY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
