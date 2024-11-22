
+++
authors = ["grid47"]
title = "Leetcode 393: UTF-8 Validation"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 393: UTF-8 Validation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/393.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/393.webp" 
    alt="A string being validated for UTF-8 encoding, with each valid byte sequence softly glowing."
    caption="Solution to LeetCode 393: UTF-8 Validation Problem"
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
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for(auto c : data) {
            if(count == 0) {
                if((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 3) == 0b11110) count = 3;
                else if (c >> 7) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The task is to determine whether a given list of integers represents valid UTF-8 encoded data. UTF-8 is a variable-length encoding used to represent all characters in Unicode. Here's how it works:

- A 1-byte character (ASCII) is represented as `0xxxxxxx`.
- A 2-byte character is represented as `110xxxxx 10xxxxxx`.
- A 3-byte character is represented as `1110xxxx 10xxxxxx 10xxxxxx`.
- A 4-byte character is represented as `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx`.

We need to check if a given sequence of bytes follows these rules and is a valid UTF-8 encoded string.

---

### 🧠 Approach

To solve this, we need to parse the list of integers (which represent the bytes) and validate each byte according to the UTF-8 format. The steps are straightforward and can be broken down as follows:

1. **Check the Leading Byte**: The first byte in the sequence determines how many continuation bytes follow it.
2. **Validate Continuation Bytes**: Each continuation byte must start with `10xxxxxx`.
3. **End of Sequence**: Ensure that after parsing all the bytes, we haven't left any incomplete characters (i.e., no more continuation bytes should be expected).

Let's dive deeper into how this approach works step-by-step!

---

### 🔨 Step-by-Step Code Breakdown

#### Step 1: Initialize the Count of Continuation Bytes

```cpp
int count = 0;
```

- `count` keeps track of how many continuation bytes we expect for the current character. Initially, it’s set to 0 because no continuation bytes are expected at the beginning.

#### Step 2: Iterate Over the Data

```cpp
for(auto c : data) {
```

- We loop through each byte `c` in the input array `data`, checking each byte to ensure it's in compliance with the UTF-8 standard.

#### Step 3: Handle the First Byte of a Character

```cpp
if(count == 0) {
    if((c >> 5) == 0b110) count = 1;  // 2-byte character
    else if ((c >> 4) == 0b1110) count = 2;  // 3-byte character
    else if ((c >> 3) == 0b11110) count = 3;  // 4-byte character
    else if (c >> 7) return false;  // Invalid starting byte
}
```

- When `count == 0`, we're starting a new character:
  - We use bitwise shifts to check the first bits of `c`.
  - If `c` starts with `110`, we know it's the start of a 2-byte character (expecting 1 continuation byte).
  - If `c` starts with `1110`, it’s a 3-byte character (expecting 2 continuation bytes).
  - If `c` starts with `11110`, it’s a 4-byte character (expecting 3 continuation bytes).
  - If `c` doesn’t match any of these, it’s an invalid byte, and we return `false`.

#### Step 4: Handle Continuation Bytes

```cpp
else {
    if ((c >> 6) != 0b10) return false;  // Continuation byte should start with 10
    count--;
}
```

- If `count` is greater than 0, we expect a continuation byte:
  - A continuation byte must start with `10`, so we use `(c >> 6)` to check if the first two bits are `10`. If not, we return `false`.
  - After validating the continuation byte, we decrease `count` to track the processed continuation byte.

#### Step 5: Check for Unfinished Characters

```cpp
return count == 0;
```

- After processing all bytes, if `count` is 0, it means all characters were fully processed with the correct number of continuation bytes.
- If `count` is not 0, it means some characters were incomplete, so we return `false`.

---

### 📊 Complexity Analysis

#### Time Complexity:
- **O(n)**, where `n` is the number of bytes in the input array. We go through each byte once, performing constant-time bitwise operations for each byte.

#### Space Complexity:
- **O(1)**. We only use a constant amount of extra space (the `count` variable), regardless of the input size.

---

### 🏁 Conclusion

In this solution, we've used a **bitwise approach** to efficiently verify if a sequence of bytes is valid UTF-8 encoded data. By checking the first byte and the continuation bytes for proper structure, we ensure that the encoding is correct and that there are no incomplete characters.

With a linear time complexity of `O(n)` and constant space complexity, this approach is both **time-efficient** and **space-efficient**, making it perfect for large inputs.

So, if you’re ever working with UTF-8 encoded data and need to validate its correctness, this is the way to go! 👍 

---

### ✨ Summary
To recap, the key steps involve:
- Validating the first byte to determine how many continuation bytes follow.
- Ensuring each continuation byte starts with `10`.
- Ensuring that all characters are fully completed by the end of the sequence.

This solution will ensure that your UTF-8 data is correct and can handle all valid (and invalid) cases effectively!

[`Link to LeetCode Lab`](https://leetcode.com/problems/utf-8-validation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
