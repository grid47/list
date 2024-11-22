
+++
authors = ["grid47"]
title = "Leetcode 17: Letter Combinations of a Phone Number"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 17: Letter Combinations of a Phone Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/17.webp"
youtube = "F7EoBxhPmBk"
youtube_upload_date="2024-05-01"
youtube_thumbnail="https://i.ytimg.com/vi/F7EoBxhPmBk/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/17.webp" 
    alt="A swirling constellation of letters, with gentle connections forming phone number combinations."
    caption="Solution to LeetCode 17: Letter Combinations of a Phone Number Problem"
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
    vector<string> letterCombinations(string digits) {
        map<char, vector<string>> mp;
        mp['2'] = { "a", "b", "c" };
        mp['3'] = { "d", "e", "f" };
        mp['4'] = { "g", "h", "i" };
        mp['5'] = { "j", "k", "l" };
        mp['6'] = { "m", "n", "o" };
        mp['7'] = { "p", "q", "r", "s" };
        mp['8'] = { "t", "u", "v" };
        mp['9'] = { "w", "x", "y", "z" };
        
        vector<string> ans, tmp;
        ans = mp[digits[0]];
        for(int i = 1; i < digits.size(); i++) {
            tmp = ans;
            ans = {};
            for(int j = 0; j < mp[digits[i]].size(); j++) {
                for(int k = 0; k < tmp.size(); k++)
                    ans.push_back(tmp[k] + mp[digits[i]][j]);
            }
        }

        return ans;
    }
};
{{< /highlight >}}
---

### 📞 **Phone Number Letter Combinations** – A Step-by-Step Guide

This problem requires us to generate all possible letter combinations that a given number sequence on a telephone keypad could represent. Each digit from `2` to `9` corresponds to a set of letters, and the task is to return all possible combinations of letters that can be formed from the given string of digits.

#### Example:
For the input `digits = "23"`, the corresponding combinations are:  
**"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"**

The goal is to generate **all possible combinations** formed from the digits in the order they are provided.

---

### 🧠 **Approach**

This problem is based on the **mapping of digits to letters**, similar to what you would find on an old phone keypad. The idea is to iterate through the input digits and use these mappings to generate all possible combinations of letters.

Let’s break down the approach into clear, manageable steps.

---

### 🔑 **Key Steps**

1. **Mapping Digits to Letters**:
   - Each digit from `2` to `9` corresponds to a set of letters. For example, `2` maps to `['a', 'b', 'c']`.
   - We create a mapping to quickly access the corresponding letters for any digit in the input string.

2. **Start with the First Digit**:
   - Begin by storing the possible letter combinations for the first digit. These are the initial combinations to work with.

3. **Iterative Combination Building**:
   - For each subsequent digit, generate new combinations by appending the letters of the current digit to all existing combinations.

4. **Return the Result**:
   - After processing all digits, the list will contain all possible letter combinations formed from the digits.

---

### 🧑‍💻 **Code Breakdown (Step-by-Step)**

#### Step 1: Create the Digit-to-Letter Mapping

```cpp
map<char, vector<string>> mp;
mp['2'] = { "a", "b", "c" };
mp['3'] = { "d", "e", "f" };
mp['4'] = { "g", "h", "i" };
mp['5'] = { "j", "k", "l" };
mp['6'] = { "m", "n", "o" };
mp['7'] = { "p", "q", "r", "s" };
mp['8'] = { "t", "u", "v" };
mp['9'] = { "w", "x", "y", "z" };
```
- We use a `map<char, vector<string>>` to store the letter mappings for each digit from `2` to `9`.
- Each key represents a digit, and the associated value is a list of strings containing the letters for that digit.

#### Step 2: Initialize the Answer List with the First Digit

```cpp
vector<string> ans, tmp;
ans = mp[digits[0]];
```
- Start by initializing the result list `ans` with the letters corresponding to the first digit in the input string.
- Since the result for the first digit is simply the set of letters mapped to that digit, we directly assign this to `ans`.

#### Step 3: Build Combinations Iteratively

```cpp
for(int i = 1; i < digits.size(); i++) {
    tmp = ans;  // Temporary copy of the current answer list
    ans = {};   // Clear the answer list for new combinations
    
    for(int j = 0; j < mp[digits[i]].size(); j++) {
        for(int k = 0; k < tmp.size(); k++)
            ans.push_back(tmp[k] + mp[digits[i]][j]);
    }
}
```
- We loop through the digits starting from the second one (`i = 1`).
- For each digit, we take a temporary copy of the current combinations stored in `ans`. Then, we clear `ans` to make room for new combinations.
- In the inner loops:
  - We iterate over the letters corresponding to the current digit (`mp[digits[i]]`).
  - For each letter, we append it to every string in `tmp` and store the resulting combination back in `ans`.

#### Step 4: Return the Final Result

```cpp
return ans;
```
- After processing all digits, the `ans` list will contain all possible combinations.
- We return this list as the result.

---

### 🧑‍💻 **Time and Space Complexity**

#### Time Complexity:
- Sorting and iterating through the digits takes **O(d)**, where `d` is the length of the input string `digits`.
- For each digit, the number of possible combinations increases exponentially because each digit can have a variable number of letters. For example, most digits map to 3 letters, but `7` and `9` map to 4 letters.
- The total number of combinations grows as **O(3^d)**, where `d` is the number of digits in the input string.

Thus, the overall time complexity is **O(3^d)**.

#### Space Complexity:
- We need space to store all possible combinations, which grows exponentially as well. In the worst case, the number of combinations is **O(3^d)**.
- Therefore, the space complexity is **O(3^d)**.

---

### 🎯 **Why This Approach Works**

- The **iterative approach** ensures that we build combinations progressively, allowing us to add one digit at a time to the existing combinations.
- The **mapping** enables quick lookups for the letters corresponding to each digit, making the process efficient.
- The solution handles edge cases well and ensures that combinations are generated in the correct order.

---

### 🏁 **Conclusion**

This solution efficiently solves the problem of generating all possible letter combinations for a given string of digits. By using an **iterative approach** and leveraging the power of the **map** for fast lookups, we ensure the solution is both simple and effective. The time complexity is **O(3^d)**, and the space complexity is also **O(3^d)**, making it feasible for moderate input sizes.

Happy coding! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)

---
{{< youtube F7EoBxhPmBk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
