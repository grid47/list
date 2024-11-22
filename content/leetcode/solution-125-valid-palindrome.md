
+++
authors = ["grid47"]
title = "Leetcode 125: Valid Palindrome"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 125: Valid Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/125.webp"
youtube = "jJXJ16kPFWg"
youtube_upload_date="2021-10-11"
youtube_thumbnail="https://i.ytimg.com/vi/jJXJ16kPFWg/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/125.webp" 
    alt="A string of letters that glow in perfect symmetry, forming a calm and balanced palindrome."
    caption="Solution to LeetCode 125: Valid Palindrome Problem"
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
    
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i <= j) {
            if(!isalnum(s[i])) {
                i++; continue;
            }
            if(!isalnum(s[j])) {
                j--; continue;
            }
            if(tolower(s[i]) == tolower(s[j])) {
                i++, j--;
            } else return false;
        }
        return true;
    }
};
{{< /highlight >}}
---

### 💡 **Palindrome Checker: Is it a Palindrome? Let's Find Out!**

The **Palindrome** problem challenges us to check if a given string is a palindrome, ignoring spaces, punctuation, and case sensitivity. A palindrome is a sequence that reads the same backward as forward.

Let’s break down how we can solve this problem efficiently and elegantly. 🚀

---

### 📝 **Problem Statement**

Given a string `s`, determine whether it is a palindrome, considering only alphanumeric characters and ignoring case sensitivity.

#### **Example 1**:
- **Input**: `"A man, a plan, a canal: Panama"`
- **Output**: `true`
  - **Explanation**: After removing all non-alphanumeric characters and ignoring case, the string becomes `"amanaplanacanalpanama"`, which is a palindrome.

#### **Example 2**:
- **Input**: `"race a car"`
- **Output**: `false`
  - **Explanation**: After removing non-alphanumeric characters, the string becomes `"raceacar"`, which is not a palindrome.

---

### 🛠️ **Approach: Two-Pointer Technique**

To solve this problem, we’ll use a **two-pointer** approach:
- One pointer (`i`) starts at the beginning of the string.
- Another pointer (`j`) starts at the end of the string.

We compare the characters at these two pointers and move them toward each other. If at any point the characters don’t match, we know the string is not a palindrome.

---

### ✨ **Step-by-Step Solution**

#### 1️⃣ **Function Definition**

```cpp
bool isPalindrome(string s)
```
The function `isPalindrome` takes a string `s` as input and returns `true` if it's a palindrome and `false` otherwise.

---

#### 2️⃣ **Initialize Two Pointers**

```cpp
int i = 0, j = s.size() - 1;
```
- **`i`** starts at the beginning of the string.
- **`j`** starts at the last character of the string (`s.size() - 1`).

---

#### 3️⃣ **Main Loop: Compare Characters**

```cpp
while(i <= j) {
```
We continue looping as long as `i` is less than or equal to `j`. This means we haven’t yet checked all pairs of characters.

---

#### 4️⃣ **Skip Non-Alphanumeric Characters**

```cpp
if(!isalnum(s[i])) {
    i++; continue;
}
if(!isalnum(s[j])) {
    j--; continue;
}
```
- We check if the character at position `i` is **not alphanumeric** (i.e., it's a space, punctuation, etc.). If it's not, we increment `i` and continue the loop.
- Similarly, we check the character at position `j`. If it's not alphanumeric, we decrement `j` and continue.

---

#### 5️⃣ **Compare Characters Case-Insensitively**

```cpp
if(tolower(s[i]) == tolower(s[j])) {
    i++, j--;
} else {
    return false;
}
```
- Convert both characters to lowercase using `tolower()` to **ignore case**.
- If the characters match, we move both pointers towards the center (`i++` and `j--`).
- If they don’t match, return `false` immediately, since the string is not a palindrome.

---

#### 6️⃣ **Return Result**

```cpp
return true;
```
If we complete the loop without finding any mismatched characters, the string is a palindrome, and we return `true`.

---

### 🔍 **Time and Space Complexity**

- **Time Complexity**:  
  **O(n)** — We traverse the string only once, with each character being processed in constant time.

- **Space Complexity**:  
  **O(1)** — We only use two extra variables (`i` and `j`), so the space complexity is constant.

---

### 🧑‍💻 **Example Walkthrough**

Let’s go through the example **`"A man, a plan, a canal: Panama"`**:

1. **Initialization**:  
   - `i = 0`, `j = 29`

2. **First Iteration** (`i = 0`, `j = 29`):
   - `s[i] = 'A'` and `s[j] = 'a'` → After converting to lowercase, they match.
   - Move `i` to 1, `j` to 28.

3. **Skip Non-Alphanumeric**:  
   - `s[i] = ' '` (not alphanumeric), so move `i` to 2.

4. **Second Iteration** (`i = 2`, `j = 28`):
   - `s[i] = 'm'` and `s[j] = 'm'` → They match, move `i` to 3, `j` to 27.

5. **Continue Checking**:  
   - As we move through the string, all corresponding characters match after ignoring non-alphanumeric characters.

6. **Final Iteration** (`i = 14`, `j = 15`):
   - No mismatches! The pointers meet, and the function returns `true`.

**Output**: `true`

---

### 🏁 **Conclusion: Mission Accomplished!**

By using the **two-pointer approach**, we efficiently solved the palindrome problem while ignoring case and non-alphanumeric characters. 🎉 The solution is **time-efficient** (O(n)) and **space-efficient** (O(1)).

---

### 🌱 **Keep Coding and Keep Improving!**

Remember, each problem you solve makes you a stronger coder. Keep practicing, stay curious, and you’ll be solving even more complex problems soon! ✨


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-palindrome/description/)

---
{{< youtube jJXJ16kPFWg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
