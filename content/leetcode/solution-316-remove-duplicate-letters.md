
+++
authors = ["grid47"]
title = "Leetcode 316: Remove Duplicate Letters"
date = "2024-10-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 316: Remove Duplicate Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/316.webp"
youtube = "HjvMWNHZBNI"
youtube_upload_date="2023-09-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HjvMWNHZBNI/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/316.webp" 
    alt="A series of letters gently disappearing from a word, leaving only the unique letters softly glowing."
    caption="Solution to LeetCode 316: Remove Duplicate Letters Problem"
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
    string removeDuplicateLetters(string s) {

        vector<int> frq(26, 0), lidx(26, 0);

        for (int i = 0; i < s.size(); i++) {
            char x = s[i];
            frq[x - 'a']++;
            lidx[x - 'a'] = i;
        }

        vector<bool> seen(26, false);
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            int cur = s[i] - 'a';            
            if(seen[cur]) continue;

            while(st.size() > 0 && st.top() > s[i] && i < lidx[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[cur] = true;
        }

        string ans = "";
        while(st.size() > 0) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The goal here is to remove duplicate letters from a string `s` such that:
1. Every letter appears only once in the final string.
2. The result is the **smallest possible lexicographical order**.

In simple terms, we’re aiming for a unique set of letters from `s`, ordered as early in the alphabet as possible.

---

### 🧠 Approach

Let's break down how we can tackle this with a **greedy algorithm** and a **stack**! The main idea is to:
- Build our result string in alphabetical order.
- Use a stack to ensure only one of each letter, removing larger letters if they can still appear later.

This way, we avoid having to reprocess sections of the string and get the optimal result efficiently.

---

### 🔍 Key Steps

1. **Count Each Character's Occurrences**: We need to know how many times each character appears to keep or remove it appropriately.
   
2. **Lexicographical Order with a Stack**: The stack allows us to build a solution in order while removing any larger letters if they’re not required.

3. **Track Presence with a Boolean Array**: An array helps us know if a letter is already in the result, so we avoid duplicates.

---

### 🔨 Step-by-Step Code Breakdown

Let’s walk through each part of the code and see how it builds the solution!

#### Step 1: Calculate Frequency and Last Index of Each Character

```cpp
vector<int> frq(26, 0), lidx(26, 0);

for (int i = 0; i < s.size(); i++) {
    char x = s[i];
    frq[x - 'a']++;
    lidx[x - 'a'] = i;
}
```

- **`frq` Array**: Counts each character's occurrences.
- **`lidx` Array**: Tracks the last position where each character appears, so we know if it can be removed and appear later.

#### Step 2: Set Up for the Stack and Track Seen Letters

```cpp
vector<bool> seen(26, false);
stack<char> st;
```

- **`seen` Array**: Prevents adding a letter to the stack more than once.
- **`st` Stack**: Builds the result letter-by-letter, keeping the smallest possible order.

#### Step 3: Process Each Character

```cpp
for(int i = 0; i < s.size(); i++) {
    int cur = s[i] - 'a';            
    if(seen[cur]) continue;

    while(st.size() > 0 && st.top() > s[i] && i < lidx[st.top() - 'a']) {
        seen[st.top() - 'a'] = false;
        st.pop();
    }

    st.push(s[i]);
    seen[cur] = true;
}
```

- **Skip Seen Characters**: If a letter is already in the stack, skip it to prevent duplicates.
- **Remove Larger Characters**: If the current character is smaller and any top stack letter can appear later, remove that larger letter.
- **Push and Mark as Seen**: Add the current character to the stack and mark it in the `seen` array.

#### Step 4: Create the Final Result

```cpp
string ans = "";
while(st.size() > 0) {
    ans += st.top();
    st.pop();
}
reverse(ans.begin(), ans.end());
return ans;
```

- **Build the Final String**: The stack holds the letters in reverse order, so we reverse them for the final answer!

---

### 📈 Complexity Analysis

- **Time Complexity**: **O(n)** because we process each character only once.
- **Space Complexity**: **O(n)** to store the stack, plus `seen` and `lidx` arrays (26 fixed size).

---

### 🏁 Conclusion

Using a stack to build a minimal lexicographical order while tracking each character’s frequency is efficient and elegant. By removing unnecessary duplicates and ordering the result, we get the lexicographically smallest string in **O(n)** time.

---

### 🎯 Takeaways

1. **Greedy Method for Lexicographical Order**: The stack and removal strategy ensure we get the smallest possible order.
2. **Tracking for Efficiency**: Arrays for frequency and last index help avoid unnecessary reprocessing.
3. **Optimized for Large Inputs**: This approach scales well with a time complexity of **O(n)**.

Good luck implementing this one! 🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-duplicate-letters/description/)

---
{{< youtube HjvMWNHZBNI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
