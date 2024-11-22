
+++
authors = ["grid47"]
title = "Leetcode 205: Isomorphic Strings"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 205: Isomorphic Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/205.webp"
youtube = "WIJcGWvzu24"
youtube_upload_date="2022-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/WIJcGWvzu24/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/205.webp" 
    alt="Two strings gently morphing into each other, with glowing connections between each corresponding character."
    caption="Solution to LeetCode 205: Isomorphic Strings Problem"
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
    bool isIsomorphic(string s, string t) {
       
         
        map<char, char> fwd, rwd;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if (fwd.count(s[i])){
                if(fwd[s[i]] != t[i])
                    return false;
            }
            if(rwd.count(t[i])){
                if(rwd[t[i]] != s[i])
                    return false;
            }
            fwd[s[i]] = t[i];
            rwd[t[i]] = s[i];
        }
        return true;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

Let’s explore the **Isomorphic Strings** problem! 🌟 We’re given two strings `s` and `t`, and we need to determine if they are **isomorphic**. That means:
1. Every character in `s` maps to a unique character in `t`.
2. No two different characters in `s` can map to the same character in `t`.
3. The mapping should be consistent throughout the strings.

#### Example:
- **Input:** `s = "egg"`, `t = "add"`
- **Output:** `true` (because `'e'` maps to `'a'` and `'g'` maps to `'d'`).

- **Input:** `s = "foo"`, `t = "bar"`
- **Output:** `false` (since `'o'` maps to both `'a'` and `'r'`, violating the one-to-one mapping rule).

Ready to check if two strings are isomorphic? Let’s dive in! 🚀

---

### 🔍 Approach

To solve this problem, we can use a **two-way mapping** approach. We’ll set up two maps:
1. **`fwd`** will store the mapping from characters in `s` to characters in `t`.
2. **`rwd`** will store the reverse mapping from characters in `t` to characters in `s`.

#### Key Steps:
1. Initialize two maps (`fwd` and `rwd`) to track the mappings.
2. Loop through each character of both strings.
3. For each character at index `i`, check if the mapping in both directions is valid.
4. If everything checks out, the strings are isomorphic!

Let’s see how it works step-by-step! 🧠

---

### 🔨 Step-by-Step Code Breakdown

Here’s how we can implement the solution. 💻

#### Step 1: Initialize Maps
```cpp
map<char, char> fwd, rwd;
```
- **Purpose:** We create two maps to store the character mappings between the two strings:
  - `fwd` stores the forward mapping (from `s` to `t`).
  - `rwd` stores the reverse mapping (from `t` to `s`).

#### Step 2: Loop Through Both Strings
```cpp
for (int i = 0; i < n; i++) {
    if (fwd.count(s[i])) {
        if (fwd[s[i]] != t[i])
            return false;
    }
    if (rwd.count(t[i])) {
        if (rwd[t[i]] != s[i])
            return false;
    }
    fwd[s[i]] = t[i];
    rwd[t[i]] = s[i];
}
```
- **Purpose:** We loop through both strings and check if the mappings are consistent:
  1. **Forward Mapping Check:** 
     - If `s[i]` is already mapped in `fwd`, we check if it maps to `t[i]`. If not, return `false`.
  2. **Reverse Mapping Check:** 
     - If `t[i]` is already mapped in `rwd`, we check if it maps to `s[i]`. If not, return `false`.
  3. After checking, we add the new mappings to `fwd` and `rwd`.

#### Step 3: Return the Result
```cpp
return true;
```
- **Purpose:** If all checks pass, return `true`, indicating the strings are isomorphic! 🎉

---

### 📊 Complexity Analysis

Let’s break down the time and space complexity. ⏱️💾

#### Time Complexity:
- **O(n):** 
  - We loop through both strings once, performing constant-time operations for each character. 
  - Therefore, the time complexity is **O(n)**, where `n` is the length of the strings.

#### Space Complexity:
- **O(n):**
  - We use two maps to store character mappings. In the worst case, each character in the strings is unique, so we need space proportional to the length of the strings.
  - Hence, the space complexity is **O(n)**.

---

### 🏁 Conclusion

We’ve successfully solved the problem of checking whether two strings are isomorphic using a **two-way mapping** approach! 🎯 Here’s a quick recap:

1. **Efficiency:** The solution runs in **O(n)** time, making it fast for large strings.
2. **Space:** The space complexity is **O(n)**, which is manageable for typical input sizes.
3. **Simplicity:** The algorithm is simple and intuitive, relying on maps to track the character mappings.

This method ensures that we detect any inconsistencies in the mappings and confirm whether the strings are truly isomorphic. Keep practicing, and you’ll master these string manipulation challenges in no time! 🌟

[`Link to LeetCode Lab`](https://leetcode.com/problems/isomorphic-strings/description/)

---
{{< youtube WIJcGWvzu24 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
