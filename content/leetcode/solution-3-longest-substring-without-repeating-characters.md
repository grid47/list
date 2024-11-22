
+++
authors = ["grid47"]
title = "Leetcode 3: Longest Substring Without Repeating Characters"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3: Longest Substring Without Repeating Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/3.webp"
youtube = "wiGpQwVHdE0"
youtube_upload_date="2020-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/wiGpQwVHdE0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/3.webp" 
    alt="A flowing ribbon with distinct, colorful segments, twisting and avoiding repetition."
    caption="Solution to LeetCode 3: Longest Substring Without Repeating Characters Problem"
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
    int lengthOfLongestSubstring(string s) {
        int prv = -1, len = 0;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            if(mp.count(s[i]))
                prv = max(prv, mp[s[i]]);
            mp[s[i]] = i;
            len = max(len, i - prv);
        }
        return len;
    }
};
{{< /highlight >}}
---

### 🔍 **Longest Substring Without Repeating Characters** – Explained Simply!

In the **Longest Substring Without Repeating Characters** problem, we are given a string `s`, and we need to determine the **length of the longest substring** that contains unique characters (no repeats). This problem is often encountered in algorithmic challenges and tests your ability to efficiently manage substring uniqueness.

### 📝 **Problem Statement**

**Input**: 
- A string `s`, consisting of characters.

**Output**: 
- An integer representing the **length of the longest substring** of `s` with all unique characters.

### 💡 **Key Idea: Sliding Window with Hashmap**

To tackle this problem efficiently, we’ll use a **sliding window** approach combined with a **hashmap**. The sliding window helps manage the substring boundaries, while the hashmap enables us to quickly track characters and their most recent positions, allowing us to keep the substring unique.

#### **Steps to Solve the Problem:**

1. **Sliding Window**: Use a window that slides across the string. The window will expand as we move right and adjust (shrink from the left) when duplicate characters are found.
   
2. **Hashmap**: Use a hashmap to store each character's **latest index** in the string. This lets us know where to adjust the left boundary if a repeated character is encountered.

3. **Calculate Length**: As we slide the window, we continuously calculate the length of the current valid substring and track the maximum length found.

### Step-by-Step Solution

#### Step 1: Initialize Variables

```cpp
int prv = -1, len = 0;  // Previous boundary index and max length
map<char, int> mp;  // Map to store characters and their latest positions
```

- `prv`: Represents the **left boundary** of the window, initialized to `-1` (before the start of the string).
- `len`: Stores the length of the **longest valid substring** found.
- `mp`: A hashmap that stores the **latest index** of each character encountered, allowing quick access and efficient window adjustment.

#### Step 2: Traverse the String

```cpp
for(int i = 0; i < s.size(); i++) {
    if(mp.count(s[i])) 
        prv = max(prv, mp[s[i]]);  // Update left boundary to avoid duplicate
    mp[s[i]] = i;  // Update the latest index of the character
    len = max(len, i - prv);  // Calculate length of current valid substring
}
```

- **Loop through each character** (`i` is the current index):
  - **Check for duplicates**:
    - If `s[i]` is already in `mp`, it means we’ve seen this character before.
    - **Adjust left boundary**: `prv = max(prv, mp[s[i]])` ensures `prv` moves right to the latest occurrence of `s[i]`.
  - **Update the hashmap**: Set `mp[s[i]] = i`, marking `s[i]`'s latest position.
  - **Calculate the length**: `len = max(len, i - prv)` updates `len` if the current substring (from `prv` to `i`) is the longest so far.

#### Step 3: Return the Maximum Length

```cpp
return len;
```

- After processing the string, `len` will hold the length of the longest substring without repeating characters, which we return as the result.

### ⏱️ **Time and Space Complexity Analysis**

- **Time Complexity**: **O(n)**, where `n` is the length of the string `s`. We perform a single pass through `s`, with each operation inside the loop (hashmap access and updates) taking constant time.
- **Space Complexity**: **O(min(n, m))**, where `n` is the length of the string, and `m` is the size of the character set. The hashmap `mp` stores at most one entry per unique character in `s`.

### 🌟 **Why This Solution Works**

This solution is efficient and intuitive:
- **Single Pass (O(n) Time)**: The sliding window ensures each character is processed once.
- **Efficient Window Adjustment**: The hashmap enables quick lookups to reposition the left boundary, maintaining uniqueness within the window.

### 🏆 **In Summary**

This approach makes it easy to tackle the **Longest Substring Without Repeating Characters** by combining a sliding window with a hashmap. With this method, we can solve the problem in linear time, making it well-suited for large strings. This technique is useful not only for solving similar substring problems but also for real-world applications involving efficient string processing.

---

### 🎉 **Practice Makes Perfect!**

With each problem you solve, you sharpen your coding skills and gain confidence. Keep coding, stay curious, and remember that every solved problem brings you closer to mastery. Good luck, and happy coding! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

---
{{< youtube wiGpQwVHdE0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
