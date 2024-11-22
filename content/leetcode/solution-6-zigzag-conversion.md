
+++
authors = ["grid47"]
title = "Leetcode 6: Zigzag Conversion"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 6: Zigzag Conversion in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/6.webp"
youtube = "2NMMVnxV6lo"
youtube_upload_date="2024-07-30"
youtube_thumbnail="https://i.ytimg.com/vi/2NMMVnxV6lo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/6.webp" 
    alt="A ribbon of light moving in smooth, calming zigzags across a gentle curve."
    caption="Solution to LeetCode 6: Zigzag Conversion Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
#include <string>
#include <vector>
#include <iostream>
class Solution {
public:
    string convert(string str, int n) {

        int len = str.size();
        
        if(n == 1) return str;
        
        vector<string> s(n, "");

        bool down = true; int ridx = 1;
        for (int i = 0; i < len; i++) {

            s[ridx - 1] += str[i];
            if (down) ridx++;
            else      ridx--;

            if ( (ridx == n) || 
                 (ridx == 1) ) 
                down = !down;
            
        }
        string res = "";
        for(int i = 0; i < n; i++)
            res += s[i];
        return res;
    }
};
{{< /highlight >}}
---

### 💡 **Zigzag Conversion**

Given a string `str`, convert it to a "zigzag" pattern across `n` rows and then read it row by row to produce the final string.

#### ✨ **Example**
For `str = "PAYPALISHIRING"` and `n = 3`, the zigzag pattern would look like:

```
P   A   H   N
A P L S I I G
Y   I   R
```

The final output, reading row-by-row, is `"PAHNAPLSIIGYIR"`.

---

### ⚙️ **Approach: Simulating the Zigzag Pattern**

1. **Special Case (`n == 1`):** If there's only one row, the result is the original string since no zigzag pattern can form.

2. **Set Up Rows:** Use a vector of strings to represent each row. Each element in the vector corresponds to one row in the zigzag pattern.

3. **Simulate Zigzag Movement:** Traverse through `str`:
   - Place each character in the current row.
   - Move "down" to the next row if we're descending; move "up" if ascending.
   - Switch directions upon reaching the top or bottom row.

4. **Form the Result String:** Concatenate the rows to produce the final string.

---

### 📘 **Code Explanation**

#### Step 1: Handle Special Case for Single Row

```cpp
if (n == 1) return str;
```

- If `n == 1`, the zigzag pattern is just the original string, so we can return it immediately.

#### Step 2: Initialize Rows

```cpp
vector<string> rows(n, "");
```

- Create a vector `rows` with `n` empty strings, one for each row.

#### Step 3: Simulate the Zigzag Pattern

```cpp
bool going_down = true; 
int row_index = 0;
for (char c : str) {
    rows[row_index] += c;
    if (row_index == 0) going_down = true;
    if (row_index == n - 1) going_down = false;
    row_index += going_down ? 1 : -1;
}
```

- **Direction Control (`going_down`)**: `true` when moving downward, `false` when moving upward.
- **Row Update**: 
  - For each character `c`, place it in `rows[row_index]`.
  - Toggle `going_down` at the top (`row_index == 0`) and bottom (`row_index == n - 1`) rows to change direction.
  - Adjust `row_index` based on `going_down`.

#### Step 4: Combine the Rows for the Result

```cpp
string result = "";
for (const string& row : rows)
    result += row;
return result;
```

- After filling `rows`, concatenate them to create the final zigzag string.

---

### 📊 **Complexity Analysis**

- **Time Complexity:** **O(n)**, where `n` is the length of `str`. Each character is processed once and concatenated in the end.
- **Space Complexity:** **O(n)**, as we store each character in one of the rows, resulting in `n` characters in total across all rows.

---

### 🔑 **Key Insights**

Simulating the zigzag pattern with directional control is effective and uses optimal space. This straightforward approach ensures we avoid unnecessary data structures, making it both clean and efficient for larger inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/zigzag-conversion/description/)

---
{{< youtube 2NMMVnxV6lo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
