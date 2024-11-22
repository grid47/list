
+++
authors = ["grid47"]
title = "Leetcode 91: Decode Ways"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 91: Decode Ways in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/91.webp"
youtube = "6aEyTjOwlJU"
youtube_upload_date="2021-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/6aEyTjOwlJU/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/91.webp" 
    alt="A glowing key unlocking multiple pathways, symbolizing decoding and transformation."
    caption="Solution to LeetCode 91: Decode Ways Problem"
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
    vector<int> memo;
    int numDecodings(string s) {
        
        memo.resize(s.size(), -1);
        return !s.size()? 0: ways(0, s);
    }
    
    int ways(int i, string s) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(memo[i] > -1) return memo[i];
        int res = ways(i + 1, s);
        
        if(i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
            res += ways(i + 2, s);
        
        return memo[i] = res;
    }
};
{{< /highlight >}}
---

### 🔐 **Decode Ways** – Unravel the Mystery of Decoding!

The **Decode Ways** problem is a fascinating challenge, where you’re tasked with decoding a string of digits into alphabetic characters. Each digit or pair of digits represents a letter in the alphabet ('A' = 1, 'B' = 2, ..., 'Z' = 26). Your goal is to determine the number of distinct ways the string can be decoded.

#### Example Walkthrough:
- **Input**: `"12"`  
  - Decodings: "AB" (1 → A, 2 → B) or "L" (12 → L)  
  - **Output**: `2`
  
- **Input**: `"226"`  
  - Decodings: "BBF", "BZ", "VF"  
  - **Output**: `3`

We also need to handle edge cases like leading zeros or numbers greater than 26, which represent invalid decodings.

### 🛠️ **Approach**

The problem is solved efficiently using **dynamic programming (DP)** with **memoization**. The idea is to break down the problem into smaller subproblems, storing intermediate results to avoid redundant calculations. Here's a step-by-step breakdown:

1. **Base Case**:  
   If we reach the end of the string, we return 1 because it means the string is fully decoded.

2. **Invalid Cases**:  
   If the current digit is '0', it’s an invalid character (since no letter corresponds to '0'). We return 0 for this case.

3. **Memoization**:  
   We use a `memo` array to store the results of subproblems. This ensures that we don’t recompute the number of decodings for the same index multiple times.

4. **Recursive Case**:  
   - Recursively calculate the number of ways to decode starting from the next index (`i + 1`).
   - If the current and next characters form a valid two-digit number (between 10 and 26), recursively calculate the number of ways to decode starting from `i + 2`.

### 📜 **Code Breakdown**

#### Step 1: Memoization Setup

```cpp
vector<int> memo;
```

- We declare a vector `memo` that will store the number of decodings for each index in the string. Initially, it is empty and will be resized according to the size of the input string `s`.

#### Step 2: Main Function to Call the Helper

```cpp
int numDecodings(string s) {
    memo.resize(s.size(), -1); // Initialize memoization array
    return !s.size()? 0 : ways(0, s);
}
```

- The `memo` array is resized to match the length of the input string `s`, with all elements initialized to `-1` (indicating that no subproblem has been solved yet).
- The function checks if the string is empty. If so, it returns 0 because an empty string cannot be decoded.

#### Step 3: Helper Function for Recursion

```cpp
int ways(int i, string s) {
    if(i == s.size()) return 1;  // Base case: reached the end of the string
    if(s[i] == '0') return 0;    // Invalid character ('0' cannot be decoded)
    if(memo[i] > -1) return memo[i];  // Return memoized result if already computed

    int res = ways(i + 1, s);  // Decode the current character as a single digit

    // If current and next character together form a valid two-digit number (10-26)
    if(i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
        res += ways(i + 2, s);  // Decode the pair of digits as a two-digit number
    }

    return memo[i] = res;  // Store the result in the memoization array
}
```

- **Base Case 1**: If `i` reaches the end of the string (`i == s.size()`), return 1 because we've successfully decoded the entire string.
- **Base Case 2**: If the current character is `'0'`, return 0 since it cannot be decoded into any letter.
- **Memoization Check**: If the result for the current index `i` is already calculated (`memo[i] > -1`), simply return the stored value.
- We recursively calculate the number of decodings starting from index `i + 1` (for single-digit decoding).
- If the current and next character together form a valid two-digit number between 10 and 26, we also calculate the number of decodings starting from `i + 2` (for two-digit decoding).

#### Step 4: Return the Result

The result is stored in the `memo` array and returned to avoid redundant calculations.

### 📈 **Time and Space Complexity**

#### Time Complexity:
- The time complexity of the solution is **O(n)**, where `n` is the length of the input string `s`. This is because each index is processed only once due to memoization.

#### Space Complexity:
- The space complexity is **O(n)** because we use a memoization array of size `n` and recursion depth can also reach `n` in the worst case.

### 🏁 **Conclusion**

The **dynamic programming** approach with **memoization** efficiently counts the number of decodings of a string. By breaking the problem into subproblems and reusing previously computed results, the algorithm achieves a time complexity of **O(n)**. This approach ensures that we avoid redundant calculations and scale well for large inputs.

This solution is **optimal** for this problem, making it perfect for scenarios where you need to decode strings of significant length efficiently.

### 🌟 **Final Thoughts**

This problem is a great example of how **dynamic programming** and **memoization** can transform a seemingly complex recursive problem into an efficient one. Understanding this technique will help you tackle many similar challenges in coding interviews and competitive programming.

Keep practicing and decoding more problems! 🚀 Happy coding! ✨

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-ways/description/)

---
{{< youtube 6aEyTjOwlJU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
