
+++
authors = ["grid47"]
title = "Leetcode 678: Valid Parenthesis String"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 678: Valid Parenthesis String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/678.webp"
youtube = "QhPdNS143Qg"
youtube_upload_date="2022-01-29"
youtube_thumbnail="https://i.ytimg.com/vi/QhPdNS143Qg/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/678.webp" 
    alt="A string of parentheses being validated, with valid ones glowing softly and invalid ones fading away."
    caption="Solution to LeetCode 678: Valid Parenthesis String Problem"
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
    bool checkValidString(string s) {
        stack<int> stk, str;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*')
                str.push(i);
            else if(s[i] == '(')
                stk.push(i);
            else {
                if(!stk.empty())
                stk.pop();
                else if(!str.empty()) str.pop();
                else return false;
            }
        }
        while(!stk.empty() && !str.empty() && stk.top() < str.top()) {
            str.pop();
            stk.pop();
        }

        return stk.empty();
    }
};
{{< /highlight >}}
---

### Problem Statement:
The problem asks us to check whether a given string `s` representing a sequence of parentheses is valid. The string contains three types of characters: `'('`, `')'`, and `'*'`. The `*` character can represent either a `'('`, a `')'`, or an empty string. We need to determine if it is possible to replace the `*` characters in such a way that the resulting string is a valid parentheses string.

### Approach:
The approach to solving this problem involves using two stacks to simulate the behavior of matching parentheses while considering the flexibility of the `*` character.

#### Key Observations:
1. **Valid Parentheses String:** A string is valid if every opening parenthesis `(` has a corresponding closing parenthesis `)`. The `*` character adds a layer of flexibility because it can represent either a left or right parenthesis, or nothing at all.
2. **Two Stacks:** We can use one stack to track the positions of `(` characters and another stack to track the positions of `*` characters. By using these two stacks, we can simulate the matching of parentheses and replace `*` when necessary.
3. **Greedy Approach:** We can greedily try to match `*` characters to form valid parentheses pairs. Specifically, when encountering a closing parenthesis `)`, we first check if we can match it with an opening parenthesis `(` from the stack. If not, we try to use a `*` from the `*` stack as a valid replacement.

The algorithm works by iterating through the string while maintaining stacks of the indices of `(` and `*`. As we encounter characters, we perform the necessary operations on the stacks. At the end of the string, if there are any unmatched `(` left in the stack, the string is invalid.

### Code Breakdown (Step by Step):

#### Step 1: Initialize Stacks and Variables
```cpp
stack<int> stk, str;  // stk is for '(' positions, str is for '*' positions
int cnt = 0;  // Variable to track the number of valid parentheses
```
We declare two stacks: `stk` for storing indices of `(` and `str` for storing indices of `*`. The variable `cnt` is not needed here, so it can be removed for clarity.

#### Step 2: Iterate Through the String
```cpp
for(int i = 0; i < s.size(); i++) {
    if(s[i] == '*')
        str.push(i);  // Push index of '*' into the str stack
    else if(s[i] == '(')
        stk.push(i);  // Push index of '(' into the stk stack
    else {
        // For closing parenthesis ')'
        if(!stk.empty()) 
            stk.pop();  // Try to match with an opening '('
        else if(!str.empty()) 
            str.pop();  // If no '(' available, try to match with a '*'
        else 
            return false;  // If neither is available, the string is invalid
    }
}
```
We iterate through each character in the string:
- If the character is `*`, we push its index into the `str` stack.
- If the character is `(`, we push its index into the `stk` stack.
- If the character is `)`, we check:
  - If the `stk` stack is not empty, we pop it, simulating the matching of a `(` with `)`.
  - If the `stk` stack is empty but the `str` stack is not empty, we pop a `*`, treating it as an opening parenthesis.
  - If neither condition holds, it means we cannot match the current `)`, and we return `false`.

#### Step 3: Match Remaining Opening Parentheses with *
```cpp
while(!stk.empty() && !str.empty() && stk.top() < str.top()) {
    str.pop();  // Pop a '*' to match with a '('
    stk.pop();  // Pop a '(' since it has been matched
}
```
After the loop finishes, we have to handle any remaining unmatched opening parentheses `(`. We try to match these with the `*` characters. If a `(` index is smaller than a `*` index (meaning we can replace that `*` with a `)` to close the parenthesis), we pop both the `*` and the `(` from their respective stacks.

#### Step 4: Return Result
```cpp
return stk.empty();  // If the stk stack is empty, all parentheses are matched
```
Finally, if the `stk` stack is empty, it means all opening parentheses `(` have been matched with closing parentheses `)` (either directly or by replacing `*`). If `stk` is not empty, there are unmatched opening parentheses, so we return `false`.

### Complexity:

#### Time Complexity:
- **O(n):** The algorithm iterates through the string once, and during each iteration, we perform constant-time operations: either pushing or popping from the stacks. Since each operation is O(1), the overall time complexity is O(n), where `n` is the length of the input string `s`.

#### Space Complexity:
- **O(n):** The space complexity is O(n) because, in the worst case, we might need to store all the indices of `(` and `*` in the stacks. Therefore, the space used by the stacks is proportional to the length of the string.

### Conclusion:

This solution efficiently handles the problem by simulating the matching of parentheses using two stacks. The key idea is to use the flexibility of `*` to match unpaired opening and closing parentheses. By iterating through the string and maintaining stacks of `(` and `*` indices, we can quickly determine if a valid parentheses string can be formed. The approach is optimal with a linear time complexity of O(n) and uses O(n) space for the stacks. This solution is both time-efficient and space-efficient, making it suitable for solving this problem on large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-parenthesis-string/description/)

---
{{< youtube QhPdNS143Qg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
