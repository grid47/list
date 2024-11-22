
+++
authors = ["grid47"]
title = "Leetcode 394: Decode String"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 394: Decode String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/394.webp"
youtube = "kNW1SlfDuJY"
youtube_upload_date="2019-10-17"
youtube_thumbnail="https://i.ytimg.com/vi/kNW1SlfDuJY/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/394.webp" 
    alt="A string decoding into a sequence, with each decoded character softly illuminated."
    caption="Solution to LeetCode 394: Decode String Problem"
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
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
    
    string decode(string &s, int &i) {
        
        
        string res = "";
        
        while(i < s.size() && s[i] != ']') {
            if(!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                
                while(i < s.size() && isdigit(s[i]))
                    n = n * 10 + (s[i++] - '0');
                
                i++;
                string t = decode(s, i);
                i++;
                
                while(n--> 0) res += t;
            }
        }
        
        return res;
    }
    
};
{{< /highlight >}}
---

### 🚀 Problem Statement

We’re tasked with decoding a string that contains encoded substrings in the format of `[k[string]]`. In this encoding, `k` is a number that tells us how many times the substring inside the brackets should be repeated. The goal is to decode the string by expanding each encoded pattern into its repeated form.

For example:
- `"3[a]2[bc]"` becomes `"aaabcbc"`.
- `"3[a2[c]]"` becomes `"accaccacc"`.

Let's break it down and see how we can implement the solution! 

---

### 🧠 Approach

To tackle this problem, we’ll use a recursive approach that processes the string step by step:

1. **Iterate through the string**: As we loop through the string, we will decode characters and handle digits that represent repetition counts.
2. **Digit handling**: When a digit is encountered, it signals that a substring should be repeated `k` times, where `k` is the number we find next to the brackets.
3. **Recursion for nested substrings**: Whenever we encounter a `[`, it indicates that there’s a nested encoded substring. We need to process that substring recursively before moving on.
4. **Base case for recursion**: Recursion ends when we encounter a `]`, signaling the completion of a nested substring.
5. **Build the string**: We’ll accumulate our result string as we decode each part.

By using recursion, we can cleanly handle nested substrings and repetition patterns.

---

### 🔨 Step-by-Step Code Breakdown

Here’s how the solution works step by step:

#### Step 1: Initialize the Function
```cpp
string decodeString(string s) {
    int i = 0;
    return decode(s, i);
}
```
- The function `decodeString` kicks off the decoding process. We initialize an index `i` to track our position in the string, and call the `decode` function with the string and index.

#### Step 2: Recursive Decode Function
```cpp
string decode(string &s, int &i) {
    string res = "";
    
    while(i < s.size() && s[i] != ']') {
```
- The `decode` function is where the magic happens! It iterates through the string until it hits a `]`, which indicates the end of the current substring.

#### Step 3: Handling Regular Characters
```cpp
    if(!isdigit(s[i]))
        res += s[i++];
```
- If the current character is not a digit (i.e., it's a regular letter), we simply add it to the result string `res`.

#### Step 4: Handling Digits (Repetition Factor)
```cpp
    else {
        int n = 0;
        
        while(i < s.size() && isdigit(s[i]))
            n = n * 10 + (s[i++] - '0');
        
        i++;
        string t = decode(s, i);
        i++;
        
        while(n--> 0) res += t;
    }
}
```
- When a digit is found, we calculate the repetition count `n` by parsing the digits until we encounter a `[` (opening a substring).
- After determining `n`, we recursively decode the substring inside the brackets.
- The decoded substring is repeated `n` times and added to the result.

#### Step 5: Return the Result
```cpp
return res;
```
- Once the entire string has been processed, we return the decoded result.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **Time Complexity**: `O(n)`, where `n` is the length of the input string. Each character in the string is processed once. The recursion is efficient, as it only dives deeper into nested substrings and processes them directly.

#### Space Complexity:
- **Space Complexity**: `O(n)`, because the recursion stack and result string both grow with the size of the input string. In the worst case, all characters could be part of a deeply nested structure, making space usage linear.

---

### 🏁 Conclusion

This solution is efficient and elegant for decoding strings with repeated and nested patterns. By using recursion, we’re able to handle both repetition factors and nested substrings in a clean, easy-to-understand way. The solution runs in linear time (`O(n)`) and uses linear space (`O(n)`), making it optimal for typical input sizes.

So go ahead and try it out! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-string/description/)

---
{{< youtube kNW1SlfDuJY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
