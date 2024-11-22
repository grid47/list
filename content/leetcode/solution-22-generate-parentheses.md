
+++
authors = ["grid47"]
title = "Leetcode 22: Generate Parentheses"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 22: Generate Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/22.webp"
youtube = "7aSAbqCWhwE"
youtube_upload_date="2024-03-11"
youtube_thumbnail="https://i.ytimg.com/vi/7aSAbqCWhwE/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/22.webp" 
    alt="A swirl of parentheses gently unfolding, forming balanced pairs that radiate a sense of calm."
    caption="Solution to LeetCode 22: Generate Parentheses Problem"
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
    
    void gen(string op, vector<string> &ans, int open, int closed, int n, int i) {
        if(i== 2*n) {
            ans.push_back(op);
            return;
        }
        
        if(open < n) {
            gen(op + "(", ans, open + 1, closed,n, i + 1);
        }
        if(open > closed) {
            gen(op + ")", ans, open, closed + 1,n, i + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen("", ans, 0, 0, n, 0);
        return ans;
    }
};
{{< /highlight >}}
---

### 🌟 **Generating Valid Parentheses Combinations** – A Step-by-Step Guide!

Let’s walk through how to generate all possible valid combinations of parentheses for a given number `n` pairs of parentheses. With a little bit of **backtracking**, we can efficiently explore the possibilities and generate all valid combinations! 🚀

---

#### 📝 **The Problem**

Given an integer `n`, the task is to generate **all valid combinations** of well-formed parentheses. Each combination should have exactly `n` opening parentheses `(` and `n` closing parentheses `)`, and the parentheses must be balanced.

---

#### 🧠 **Backtracking: The Key to Success**

Backtracking is the technique we'll use to explore all possible combinations. Here's how it works:

1. We can **add an opening parenthesis** `(` as long as the number of opening parentheses used is less than `n`.
2. We can **add a closing parenthesis** `)` only if the number of closing parentheses used is less than the number of opening parentheses used. This ensures that the parentheses are balanced.

By recursively exploring all possibilities and adhering to these rules, we can generate all valid combinations.

---

#### 🔑 **Code Breakdown: Backtracking in Action**

Let’s break down the code to see how the magic happens!

**Step 1: The `generateParenthesis` Function**

```cpp
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    gen("", ans, 0, 0, n, 0);
    return ans;
}
```
- This is the starting point! We initialize an empty result vector `ans` to hold our valid combinations and call the helper function `gen` to start generating the strings.

---

**Step 2: The Recursive `gen` Function**

```cpp
void gen(string op, vector<string> &ans, int open, int closed, int n, int i) {
    if(i == 2 * n) {
        ans.push_back(op);
        return;
    }
    
    if(open < n) {
        gen(op + "(", ans, open + 1, closed, n, i + 1);
    }
    if(open > closed) {
        gen(op + ")", ans, open, closed + 1, n, i + 1);
    }
}
```
- **Base Case**:  
    Once we’ve generated a string of length `2 * n` (because each valid string must have `n` opening and `n` closing parentheses), we add that string to our result list.

    ```cpp
    if(i == 2 * n) {
        ans.push_back(op);
        return;
    }
    ```

- **Recursive Case**:
    - **Adding an Opening Parenthesis**:  
        If we haven't yet used all `n` opening parentheses, we add one more and recurse to generate the rest of the string.
        
        ```cpp
        if(open < n) {
            gen(op + "(", ans, open + 1, closed, n, i + 1);
        }
        ```
    
    - **Adding a Closing Parenthesis**:  
        We can add a closing parenthesis if the number of closing parentheses used is less than the number of opening parentheses. This keeps the string balanced.
        
        ```cpp
        if(open > closed) {
            gen(op + ")", ans, open, closed + 1, n, i + 1);
        }
        ```

---

#### ⏳ **Time and Space Complexity**

- **Time Complexity**:  
  **O(4^n / √n)**, where `n` is the number of pairs of parentheses. The recursive backtracking approach explores all possible valid combinations, and the number of valid combinations is asymptotically given by the Catalan number.

- **Space Complexity**:  
  **O(n)**, where `n` is the number of pairs. The recursion depth is at most `2 * n` (the length of the string we’re building), making the space complexity proportional to `n`.

---

#### 💡 **Why This Approach Works!**

- **Elegant and Simple**:  
    The backtracking approach elegantly handles the constraints of the problem. Each recursive call explores adding an opening or closing parenthesis, ensuring the parentheses remain balanced.

- **Efficiency**:  
    Instead of generating all possible combinations and then filtering out invalid ones, this approach directly generates only valid combinations, saving computation time.

---

#### 🌱 **Keep Practicing!**

Backtracking is a powerful technique, and the more you practice it, the more natural it will become. This problem is a great exercise to understand recursion and constraints handling.

You’re doing awesome, and with each problem you solve, you’re getting closer to mastering these techniques! 💪

[`Link to LeetCode Lab`](https://leetcode.com/problems/generate-parentheses/description/)

---
{{< youtube 7aSAbqCWhwE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
