
+++
authors = ["grid47"]
title = "Leetcode 168: Excel Sheet Column Title"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 168: Excel Sheet Column Title in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/168.webp"
youtube = "X_vJDpCCuoA"
youtube_upload_date="2023-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/X_vJDpCCuoA/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/168.webp" 
    alt="A radiant column title unfolding slowly, forming the Excel-style alphanumeric title."
    caption="Solution to LeetCode 168: Excel Sheet Column Title Problem"
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
    string convertToTitle(int columnNumber) {
        string res = "";
        int mod;
        while(columnNumber > 0) {
            mod = --columnNumber % 26;
            char x = ('A' + mod);
            res = x + res;
            columnNumber /= 26;
        }
        return res;
    }
};
{{< /highlight >}}
---

### 🌟 Excel Column Title Conversion

The problem requires converting a given positive integer, `columnNumber`, into its corresponding Excel column title. Here’s how we can approach the solution.

#### Example:
- A column number of `1` corresponds to the title `"A"`.
- A column number of `28` corresponds to the title `"AB"`.
- A column number of `701` corresponds to the title `"ZY"`.

This problem mimics the process of converting a number into a base-26 system, with a twist: the digits are represented by letters from `A` to `Z`.

### 💡 Approach

The main idea here is to treat the column number as a **base-26 number system**, where:
- `A` corresponds to `1`, `B` corresponds to `2`, ..., and `Z` corresponds to `26`.

However, since Excel's numbering starts at `1` (not `0`), we adjust the column number during our conversion to properly map it to letters.

### 🔍 Code Breakdown (Step-by-Step)

#### Step 1: Initialize the Result String

```cpp
string res = "";
```
- We start with an empty string `res` where the final column title will be built from the right to the left.

#### Step 2: Process the Column Number

```cpp
while(columnNumber > 0) {
    mod = --columnNumber % 26;
    char x = ('A' + mod);
    res = x + res;
    columnNumber /= 26;
}
```

- **Looping Condition**: The loop runs as long as `columnNumber > 0`. Each iteration processes one "digit" (letter) of the column title.
  
- **Modulus Operation**:
  - `mod = --columnNumber % 26`: We first decrement `columnNumber` by 1 (to adjust for the `1-based` system in Excel). Then, the modulus operation gives us the "digit" corresponding to the current letter.
  
- **Character Conversion**:
  - `char x = ('A' + mod)`: This converts the modulus value into the corresponding letter. For example, if `mod = 0`, `x` will be `'A'`.
  
- **Build the Result**:
  - `res = x + res`: The current letter `x` is added to the front of the result string `res` to build the title from right to left.
  
- **Update Column Number**:
  - `columnNumber /= 26`: After processing the current "digit", we divide the column number by 26 to move on to the next "digit".

#### Step 3: Return the Result

```cpp
return res;
```
- After the loop completes, we return the string `res`, which now contains the Excel column title.

### 📊 Complexity Analysis

#### Time Complexity:
- **O(log₁₆₆ n)**: Since we are repeatedly dividing the column number by 26, the number of iterations is proportional to the logarithm of `n` (base 26). Hence, the time complexity is **O(log₁₆₆ n)**, where `n` is the input `columnNumber`.

#### Space Complexity:
- **O(log₁₆₆ n)**: The space complexity is driven by the number of characters stored in the result string `res`. Each iteration adds one character, and the number of iterations is proportional to `log₁₆₆ n`. Therefore, the space complexity is **O(log₁₆₆ n)**.

### ✅ Conclusion

This approach efficiently converts a column number into its corresponding Excel title using a base-26-like conversion method. The key idea is adjusting the number and repeatedly dividing by 26 to determine each "digit" (letter) in the column title.

#### Key Takeaways:
- The solution is similar to a base conversion but adjusted for Excel's `1-based` numbering system.
- The algorithm runs in **O(log₁₆₆ n)** time complexity, which is efficient even for large column numbers.
- Space complexity is **O(log₁₆₆ n)** due to the space needed to store the result string.

This method ensures that the solution is both time and space-efficient, making it ideal for solving this problem with large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/excel-sheet-column-title/description/)

---
{{< youtube X_vJDpCCuoA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
