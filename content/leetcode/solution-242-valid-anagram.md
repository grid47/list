
+++
authors = ["grid47"]
title = "Leetcode 242: Valid Anagram"
date = "2024-10-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 242: Valid Anagram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/242.webp"
youtube = "QMXliZEU9dU"
youtube_upload_date="2022-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/QMXliZEU9dU/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/242.webp" 
    alt="Two strings gently transforming into each other, with letters rearranging to form valid anagrams."
    caption="Solution to LeetCode 242: Valid Anagram Problem"
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
    bool isAnagram(string s, string t) {
        vector<int> ch(26, 0);
        for(char x: s) ch[x - 'a']++;
        for(char x: t) ch[x - 'a']--;
        for(int x: ch) if(x != 0) return false;
        return true;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, we need to determine whether two strings, `s` and `t`, are **anagrams** of each other. 🧩 

Two strings are anagrams if they contain the same characters in the same frequencies, but potentially in a different order. Here's how we can check:

**Example 1**:
- **Input**: s = "anagram", t = "nagaram"
- **Output**: `true` ✅ (Both strings contain the same characters with the same frequencies)

**Example 2**:
- **Input**: s = "rat", t = "car"
- **Output**: `false` ❌ (The strings contain different characters)

We need to implement a function `isAnagram` that returns `true` if the two strings are anagrams and `false` otherwise. Let's dive in! 🎯

---

### 🧠 Approach

To solve this, we can use a simple and efficient approach. The main idea is to count the frequency of each character in both strings and then compare them. 🧑‍💻

Here's how we can do it:

1. **Character Frequency Count**: We can compare the character counts of both strings. If they have the same characters with the same frequencies, they are anagrams.
2. **Optimized Approach**: Instead of comparing characters one-by-one, we'll use an array of size 26 (one for each lowercase English letter) to count the frequencies.
3. **Why Size 26?** Since we only care about lowercase English letters, we only need 26 spots in our frequency array. ✅

---

### 🔨 Step-by-Step Code Breakdown

Now, let's break down the code into small, digestible steps! 🛠️

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
```
- Here, we define the function `isAnagram` that takes two strings `s` and `t`. The goal is to check if these two strings are anagrams of each other. Let's check it out!

```cpp
        vector<int> ch(26, 0);
```
- We create a vector `ch` of size 26, initialized to 0. This vector will help us track the frequency of each letter in the strings. It will correspond to the letters 'a' to 'z'. 🅰️ to 🅾️

```cpp
        for(char x: s) ch[x - 'a']++;
```
- We loop over each character in string `s` and update the frequency of that character in the `ch` vector. The index for each character is determined by `x - 'a'`. For example, for 'a', it updates `ch[0]`, for 'b', `ch[1]`, and so on.

```cpp
        for(char x: t) ch[x - 'a']--;
```
- Next, we do the same for string `t`, but this time we **decrement** the frequency. This way, if both strings are anagrams, the counts will cancel out, leaving us with zeroes in all positions.

```cpp
        for(int x: ch) if(x != 0) return false;
```
- Now, we check the `ch` vector. If any of its values is not zero, that means the frequencies of the characters in `s` and `t` are different, and they can't be anagrams! In that case, we return `false`.

```cpp
        return true;
```
- If all values are zero, it means both strings have the same character frequencies, so we return `true` to indicate that `s` and `t` are anagrams. 🏆

---

### 📈 Complexity Analysis

Let's break down the time and space complexities! 🧮

#### Time Complexity:
- **O(n)**: Where `n` is the length of the longer string between `s` and `t`. We iterate through both strings once, updating the frequency counts in a fixed-size array. So, it's linear with respect to the size of the strings.

#### Space Complexity:
- **O(1)**: The space complexity is constant because the size of the `ch` array is always 26 (fixed for the alphabet). No matter how long the input strings are, the space used by `ch` stays the same. 💾

---

### 🏁 Conclusion

In this problem, we efficiently check whether two strings are anagrams using a frequency counting method with an array of size 26. Here's what we learned:

#### Key Points:
1. **Efficiency**: The solution runs in **O(n)** time, making it optimal for large inputs.
2. **Space Optimization**: The space used is constant, **O(1)**, because we only store counts for 26 characters.
3. **Simplicity**: It's a simple approach that uses a single pass through the strings to count characters and check if they match.
4. **Practical**: This method works perfectly for problems involving anagram checks or frequency counting for fixed-size alphabets (like lowercase English letters). 📚

By using this approach, you can quickly determine if two strings are anagrams, making it a solid solution for many string-based challenges! 💪

### ✨ Quick Recap:
- **Time**: O(n) ⏱️
- **Space**: O(1) 💡
- **Solution**: Frequency counting with an array of size 26!

Hope this helps! Keep up the good work! 👏

[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-anagram/description/)

---
{{< youtube QMXliZEU9dU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
