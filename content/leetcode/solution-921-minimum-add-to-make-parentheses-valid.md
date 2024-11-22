
+++
authors = ["grid47"]
title = "Leetcode 921: Minimum Add to Make Parentheses Valid"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 921: Minimum Add to Make Parentheses Valid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EPr9X0Y3vmo"
youtube_upload_date="2021-02-19"
youtube_thumbnail="https://i.ytimg.com/vi/EPr9X0Y3vmo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        stack<int> stk;
        for(char &a : s) {
            if(a == '(') {
                stk.push(a);
            } else {
                if(stk.empty()) {
                    res++;
                } else {
                    stk.pop();
                }
            }
        }
        
        res += stk.size();
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves ensuring that a given string of parentheses `s` is valid by determining the minimum number of parentheses to add. A string is considered valid if every opening parenthesis has a matching closing parenthesis in the correct order. The task is to calculate the minimum additions needed to make the string valid.

### Approach

To solve this problem, we use a **stack-based approach** to manage the balancing of parentheses as we traverse through the string. Here’s the strategy:

1. **Using a Stack to Track Opening Parentheses**:
   - We iterate over each character in the string.
   - For every opening parenthesis `'('`, we push it onto the stack, indicating a need for a closing parenthesis in the future.
   - For every closing parenthesis `')'`, we check if the stack has an unbalanced opening parenthesis.
     - If the stack is not empty, we pop an element (indicating that one opening parenthesis has found a match).
     - If the stack is empty, we increment a counter `res`, as this closing parenthesis doesn’t have an opening match, so it will require an additional `'('` to make it valid.

2. **Counting Remaining Unmatched Opening Parentheses**:
   - After traversing the entire string, any remaining items in the stack represent unmatched opening parentheses that will require a corresponding number of `')'` additions.

3. **Calculating the Total Number of Additions**:
   - The result `res` is incremented by the number of items left in the stack, representing the additional closing parentheses needed for balance.
   - Finally, `res` gives us the minimum number of parentheses required to make the string valid.

### Code Breakdown (Step by Step)

1. **Initialize Result Counter and Stack**:
   ```cpp
   int res = 0;
   stack<int> stk;
   ```
   - `res` is initialized to zero to store the count of additional parentheses needed.
   - `stk` is a stack that will be used to keep track of unmatched opening parentheses.

2. **Traverse the String**:
   ```cpp
   for(char &a : s) {
       if(a == '(') {
           stk.push(a);
       } else {
           if(stk.empty()) {
               res++;
           } else {
               stk.pop();
           }
       }
   }
   ```
   - We loop through each character in the string `s`.
   - If the character is `'('`, we push it onto the stack, signifying an unmatched opening parenthesis.
   - If the character is `')'`:
     - We check if `stk` is empty:
       - If yes, it means there is no matching `'('` for this `')'`, so we increment `res` to count an additional `'('`.
       - If no, we pop an item from `stk`, balancing one opening parenthesis with this closing parenthesis.

3. **Count Remaining Items in Stack**:
   ```cpp
   res += stk.size();
   ```
   - After finishing the loop, any unmatched opening parentheses are still in `stk`.
   - We add the size of `stk` to `res` to account for the necessary closing parentheses to balance these.

4. **Return Result**:
   ```cpp
   return res;
   ```
   - `res` now contains the minimum number of parentheses required to make the input string valid.

### Complexity

1. **Time Complexity**:
   - The time complexity is **O(n)**, where `n` is the length of the string `s`. Each character is processed once, either being pushed onto the stack or checked against it.

2. **Space Complexity**:
   - The space complexity is **O(n)** as well, in the worst case where all characters are `'('`, requiring each to be stored in the stack.

### Conclusion

This solution efficiently finds the minimum number of parentheses required to make the string valid by leveraging a stack-based approach to track unmatched opening parentheses and directly counting unmatched closing parentheses. This approach offers an optimal **O(n)** time complexity, making it suitable for larger strings while maintaining simplicity and readability in code structure. The solution effectively handles various cases, including fully balanced strings, unbalanced strings with excess opening or closing parentheses, and empty strings. By directly managing mismatched parentheses, this method ensures that the string becomes valid with the minimum number of additions.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/)

---
{{< youtube EPr9X0Y3vmo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
