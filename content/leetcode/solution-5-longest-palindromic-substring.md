
+++
authors = ["grid47"]
title = "Leetcode 5: Longest Palindromic Substring"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 5: Longest Palindromic Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/5.webp"
youtube = "XYQecbcd6_c"
youtube_upload_date="2020-08-10"
youtube_thumbnail="https://i.ytimg.com/vi/XYQecbcd6_c/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/5.webp" 
    alt="A mirror reflecting a glowing word, with symmetry and balance radiating outward."
    caption="Solution to LeetCode 5: Longest Palindromic Substring Problem"
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
    int lo, len;
    string longestPalindrome(string s) {
        len = 0;
        
        for(int i = 0; i < s.size(); i++) {
            pal(s, i, i);
            pal(s, i, i + 1);
        }
        return s.substr(lo, len);
    }
    
    void pal(string &s, int i, int j) {
        while(i >= 0 && j <= s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        if(len < j - i - 1) {
            lo = i + 1;
            len = j - i - 1;
        }
    }
};
{{< /highlight >}}
---


### 💡 **Longest Palindromic Substring**

Our task is to find the **longest palindromic substring** within a given string `s`. A **palindrome** reads the same forwards and backwards, so we want the longest substring that fits this definition.

#### ✨ **Example**
- Input: `"babad"`
- Output: `"bab"` or `"aba"` (either is correct)

The string can be up to **10^3** characters, so an efficient solution is necessary.

---

### ⚙️ **Approach: Center Expansion**

We can use the **center-expansion technique**:
1. **Expand from Each Character (Center):** Treat each character as the middle of a possible palindrome. Expand outward while the characters on both sides are equal.
2. **Consider Odd and Even-Length Centers:**
   - Odd-length centers use a single character as the center.
   - Even-length centers use two adjacent characters as the center.
3. **Track the Longest Palindrome:** Keep a record of the longest palindrome found during expansion.
4. **Return the Result:** After checking all possible centers, return the longest palindrome substring.

This approach is efficient with **O(n^2)** time complexity, making it suitable for large strings.

---

### 📘 **Code Breakdown**

Let’s break down each part of the code:

#### Step 1: Initialize Variables

```cpp
int lo, len = 0;
```

- `lo`: The starting index of the longest palindrome found.
- `len`: The length of the longest palindrome found.

#### Step 2: Iterate Over Each Character

```cpp
for (int i = 0; i < s.size(); i++) {
    pal(s, i, i);       // Check for odd-length palindrome
    pal(s, i, i + 1);   // Check for even-length palindrome
}
```

- We loop through each character, treating it as a center. We use the function `pal` to:
  - `pal(s, i, i)`: Expand around a single character for odd-length palindromes.
  - `pal(s, i, i + 1)`: Expand around two characters for even-length palindromes.

#### Step 3: Expand Around the Center

```cpp
void pal(string &s, int i, int j) {
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        i--;
        j++;
    }
    if (len < j - i - 1) {
        lo = i + 1;
        len = j - i - 1;
    }
}
```

- This function is responsible for finding the longest palindrome centered at `i` and `j`.
  - **Expansion:** As long as `s[i] == s[j]`, we expand by moving `i` left and `j` right.
  - **Update the Longest Palindrome:** After expanding, if the current palindrome’s length (`j - i - 1`) is greater than `len`, we update `lo` and `len`.

#### Step 4: Return the Longest Palindromic Substring

```cpp
return s.substr(lo, len);
```

- Finally, we return the longest palindromic substring found by extracting `s.substr(lo, len)`.

---

### 📊 **Complexity Analysis**

- **Time Complexity:** **O(n^2)**, where `n` is the length of the string.
  - Each center expansion could take up to `O(n)` time, and we repeat this for each character.
- **Space Complexity:** **O(1)**, as we only use a few variables for tracking indices.

---

### 🧠 **Key Insights**

This solution is effective because it avoids the overhead of merging or storing additional data structures, focusing on direct character comparisons.

### 🔑 **Practice Insight**

This technique (center expansion) is a powerful method for substring problems involving symmetry, such as palindromes, and allows an intuitive understanding of the longest palindrome without complex data structures.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-palindromic-substring/description/)

---
{{< youtube XYQecbcd6_c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
