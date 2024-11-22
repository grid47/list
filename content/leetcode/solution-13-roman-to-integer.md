
+++
authors = ["grid47"]
title = "Leetcode 13: Roman to Integer"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 13: Roman to Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/13.webp"
youtube = "3jdxYj3DD98"
youtube_upload_date="2021-08-30"
youtube_thumbnail="https://i.ytimg.com/vi/3jdxYj3DD98/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/13.webp" 
    alt="Roman numerals transitioning into flowing numbers, visualizing transformation."
    caption="Solution to LeetCode 13: Roman to Integer Problem"
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
    int romanToInt(string s)
    {
        int ln = s.length();
        int res= RomToNum(s[ln-1]);
        int prv= res, curr = 0;
        for (int i = ln -2; i >=0; i--)
        {
            curr = RomToNum(s[i]);
            (curr < prv)? (res -= curr): (res += curr);
            prv = curr;
        }
        return res;
    }
    
    int RomToNum(char s)
    {
        switch (s)
        {
            case 'I' : return 1		;
            case 'V' : return 5		;
            case 'X' : return 10	;
            case 'L' : return 50	;
            case 'C' : return 100	;
            case 'D' : return 500	;
            case 'M' : return 1000	;
        }
        return 0;
    }
};
{{< /highlight >}}
---

### 🌟 **Converting Roman Numerals to Integer: A Step-by-Step Guide**

The task is to convert a Roman numeral string into its integer equivalent. Roman numerals are a combination of characters that represent specific values. For example:
- "III" becomes 3.
- "IV" becomes 4.
- "IX" becomes 9.
- "LVIII" becomes 58.
- "MCMXCIV" becomes 1994.

Let's dive into how we can approach this problem in a simple, efficient way! 🧠✨

---

### 🧐 **Roman Numeral Rules Recap**

1. **Subtraction Rule**: If a smaller numeral appears before a larger one (e.g., "IV" for 4), its value is subtracted.
2. **Addition Rule**: If a numeral is followed by one of equal or smaller value, it's added (e.g., "VI" for 6).

We'll use these rules to build our solution step by step.

---

### 🔑 **Approach: The Greedy Strategy**

The key is to traverse the Roman numeral string **from right to left**. At each step, compare the current numeral’s value to the previous numeral’s value:
- If the current numeral’s value is smaller, subtract it (because it's part of a subtraction rule like "IV" or "IX").
- If it's greater than or equal to the previous numeral’s value, add it.

Let’s go through the steps in detail.

---

### 🏃‍♂️ **Step-by-Step Code Walkthrough**

#### Step 1: Define the `romanToInt` Function

We begin by initializing some important variables:
- **`res`** stores the final result.
- **`prv`** tracks the previous numeral’s value (starting with the value of the last character).
- **`curr`** stores the current numeral’s value during the iteration.

```cpp
int romanToInt(string s)
{
    int ln = s.length();  // Get the length of the input string.
    int res = RomToNum(s[ln-1]);  // Convert the last character to its integer value.
    int prv = res, curr = 0;
```

---

#### Step 2: Iterate Through the String

Now we move left through the string, converting each character to its corresponding integer value and comparing it to the previous one.

```cpp
for (int i = ln -2; i >= 0; i--)  // Start iterating from the second last character.
{
    curr = RomToNum(s[i]);  // Convert the current character to its integer value.
    
    (curr < prv) ? (res -= curr) : (res += curr);  // Add or subtract based on comparison.
    
    prv = curr;  // Update the previous value to the current value.
}
```

- **If `curr < prv`**: We subtract `curr` from `res`, handling cases like "IV" or "IX".
- **Otherwise**: We add `curr` to `res`.

---

#### Step 3: Return the Result

After processing all characters, we return the result.

```cpp
return res;  // Return the computed result.
```

---

#### Step 4: Helper Function to Convert Roman Numerals

We also need a helper function to map Roman numeral characters to their respective integer values.

```cpp
int RomToNum(char s)
{
    switch (s)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }
    return 0;  // If the character is not a valid Roman numeral, return 0.
}
```

- This function handles the conversion from Roman numerals ('I', 'V', 'X', etc.) to integers.

---

### ⏱️ **Time and Space Complexity**

- **Time Complexity**: **O(n)**, where `n` is the length of the input string `s`. We iterate through the string once, processing each character in constant time.
  
- **Space Complexity**: **O(1)**. We only use a few integer variables for tracking the result and values, so the space used is constant.

---

### 🎯 **Key Takeaways**

- By processing the Roman numeral string from **right to left**, we can efficiently handle both addition and subtraction rules.
- The greedy approach ensures that we always know whether to add or subtract the current numeral’s value.

#### **Advantages**:
- **Efficient**: We process the string in a single pass, making the solution fast and straightforward.
- **Simple**: The solution is easy to follow, with a clear division between the main logic and the helper function.

#### **Limitations**:
- Assumes the input string is a valid Roman numeral, within the range of 1 to 3999.

---

### 🎉 **Summary**

This solution efficiently converts a Roman numeral string to an integer using a greedy approach. By moving from right to left and deciding whether to add or subtract based on the current and previous values, we handle all Roman numeral conventions correctly. The solution is simple to understand and highly efficient, with a time complexity of **O(n)** and space complexity of **O(1)**. Keep practicing, and you’ll master Roman numeral conversions in no time! ✨

[`Link to LeetCode Lab`](https://leetcode.com/problems/roman-to-integer/description/)

---
{{< youtube 3jdxYj3DD98 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
