
+++
authors = ["grid47"]
title = "Leetcode 38: Count and Say"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 38: Count and Say in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/38.webp"
youtube = "4PFCdoSOsiA"
youtube_upload_date="2023-12-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4PFCdoSOsiA/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/38.webp" 
    alt="A series of glowing numbers transforming into words, forming a pattern of calm repetition."
    caption="Solution to LeetCode 38: Count and Say Problem"
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
    string countAndSay(int n) {
        if (n == 1) return "1";

        string tmp = countAndSay(n-1);
        string ans = "";

        for(int i = 0; i < tmp.size(); ) {

            char ch = tmp[i];
            int cnt = 0;

            while(tmp[i] == ch && i < tmp.size()) {
                cnt++;
                i++;
            }

            ans.push_back(cnt+'0');
            ans.push_back(tmp[i-1]);
        }

        return ans;
    }
};
{{< /highlight >}}
---

### 📝 Problem Statement

The task is to generate the **Nth term** of the "Count and Say" sequence. The sequence starts with:
- `1` (1st term)
- `11` (2nd term)
- `21` (3rd term)
- `1211` (4th term)
- `111221` (5th term)
- `312211` (6th term)

The idea is to describe the digits of the previous term, counting consecutive digits. For example:
- "1" is read as "one 1" → "11"
- "11" is read as "two 1s" → "21"
- "21" is read as "one 2, one 1" → "1211"

We need to generate the `n`th term of this sequence!

### 💡 Approach

The key idea is simple: we **count and say**. If `n == 1`, the answer is "1". For any higher `n`, the next term is obtained by processing the previous term, counting consecutive digits, and constructing the new term based on that description.

#### Step-by-Step Breakdown

**1. Base Case:**

```cpp
if (n == 1) return "1";
```

If `n == 1`, the sequence starts with "1". No need to process anything further!

**2. Generate the Previous Term:**

```cpp
string tmp = countAndSay(n-1);
```

For any other term, we need to find the term before it by recursively calling the function. It’s like stepping back before you can move forward!

**3. Counting Consecutive Digits:**

```cpp
for(int i = 0; i < tmp.size(); ) {
    char ch = tmp[i];
    int cnt = 0;
```

We look at each character in the previous term and count how many times it repeats consecutively. This is like "seeing" the sequence and describing it in words. If a character repeats, we count it!

**4. Counting the Digits:**

```cpp
while(tmp[i] == ch && i < tmp.size()) {
    cnt++;
    i++;
}
```

As long as the next character matches, we keep counting. The key is to move step-by-step, increasing the count, until the sequence changes.

**5. Construct the New Term:**

```cpp
ans.push_back(cnt+'0');
ans.push_back(tmp[i-1]);
```

Once we know how many times a digit repeats, we add the count and the digit to the new term. This is the essence of "Count and Say": describing the previous term in terms of consecutive digits.

**6. Return the Result:**

```cpp
return ans;
```

After building the new term, we return it. We’ve built the `n`th term by repeatedly "saying" what we saw in the previous term!

### 🔍 Complexity

**Time Complexity:**
- **O(n * m):** Here, `n` is the term we’re generating, and `m` is the average length of the term. The time grows exponentially because each term is roughly twice as long as the previous one. This gives us an approximate complexity of **O(n * 2^n)**.

**Space Complexity:**
- **O(m):** The space complexity is influenced by the space required to store the string for the current term. It also includes the recursive call stack, which grows as the sequence length increases.

### 🌱 Conclusion

Think of this approach as building a story from the previous one. You **count** and **say** what you see, and build upon it for the next term. The recursive calls help in going back to the earlier term, and we keep adding more details step by step. While the time complexity grows quickly, this method is efficient for smaller `n` values and gives us a clear, step-by-step way of constructing the sequence.

---

**Remember: Practice Makes Perfect!** The more you get comfortable with recursion and building on previous results, the better you'll understand this sequence. 😊

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-and-say/description/)

---
{{< youtube 4PFCdoSOsiA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
