
+++
authors = ["grid47"]
title = "Leetcode 383: Ransom Note"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 383: Ransom Note in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/383.webp"
youtube = "i3bvxJyUB40"
youtube_upload_date="2024-04-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/i3bvxJyUB40/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/383.webp" 
    alt="A sequence of letters forming a ransom note, with the available letters glowing to form the required note."
    caption="Solution to LeetCode 383: Ransom Note Problem"
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
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for(int x: magazine)
            mp[x]++;
        
        for(int j = 0; j < ransomNote.size(); j++) {
            if(!mp.count(ransomNote[j])) return false;
            else {
                mp[ransomNote[j]]--;
                if(mp[ransomNote[j]] == 0) mp.erase(ransomNote[j]);
            }
        }
        return true;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, you’re given two strings: `ransomNote` and `magazine`. The task is to check if you can construct the `ransomNote` string using characters from the `magazine` string. The characters in the magazine can only be used **once**, and you're allowed to use **multiple occurrences** of the same character if it's available. 

For example:
- If `ransomNote = "aa"` and `magazine = "aab"`, it's possible to construct the ransom note because the magazine has enough 'a' characters.
- If `ransomNote = "aa"` and `magazine = "ab"`, it's impossible to construct the ransom note since there's not enough 'a' characters in the magazine.

The goal is to return **true** if the ransom note can be constructed and **false** otherwise.

---

### 🧠 Approach

To solve this problem, we can use a **frequency counting** approach by checking the number of characters in both strings. Here's how we can approach it:

1. **Count Characters in the Magazine**: First, we count how many times each character appears in the `magazine`. This helps us know how many characters are available to use for the ransom note.
  
2. **Check the Ransom Note Characters**: Next, we check if each character in the `ransomNote` is available in the `magazine`. If any character is missing or not available enough times, we return **false**. Otherwise, we proceed with the check and reduce the count for each character in the `magazine`.

3. **Return True if All Characters Are Available**: After checking all characters, if all characters are available in the required quantity, we return **true**.

By using a map (or hash map), we can efficiently track the frequency of characters and check if we have enough of each one.

---

### 🔨 Step-by-Step Code Breakdown

Let’s dive into the code to understand how we implement this approach:

#### Step 1: Initializing the Frequency Map for the Magazine
```cpp
map<char, int> mp;
for(int x: magazine)
    mp[x]++;
```
- We create a `map<char, int>` called `mp` to store the frequency of characters in the `magazine`.
- For every character `x` in the `magazine`, we increment its count in the map. This allows us to track how many occurrences of each character are available.

#### Step 2: Checking if Each Character in the Ransom Note Can Be Constructed
```cpp
for(int j = 0; j < ransomNote.size(); j++) {
    if(!mp.count(ransomNote[j])) return false;
    else {
        mp[ransomNote[j]]--;
        if(mp[ransomNote[j]] == 0) mp.erase(ransomNote[j]);
    }
}
```
- We iterate over each character `ransomNote[j]` in the `ransomNote` string.
- If the character `ransomNote[j]` is not found in the `magazine` (i.e., `mp.count(ransomNote[j]) == 0`), we return **false** immediately because we can't construct the ransom note without that character.
- If the character is available, we decrease its count in the map (`mp[ransomNote[j]]--`). If the count becomes zero, we remove the character from the map to prevent using it more times than it appears in the `magazine`.

#### Step 3: Return True if All Characters Are Available
```cpp
return true;
```
- If we make it through the entire loop without returning **false**, it means that every character in the `ransomNote` can be matched with enough characters from the `magazine`.
- In that case, we return **true**, indicating that it is possible to construct the ransom note.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **O(m + n)**, where `m` is the length of the `magazine` string and `n` is the length of the `ransomNote` string.
  - The first loop where we count characters in the `magazine` takes O(m) time.
  - The second loop, where we check each character in the `ransomNote`, takes O(n) time.
  - Thus, the overall time complexity is O(m + n).

#### Space Complexity:
- **O(m)**, where `m` is the number of unique characters in the `magazine` string.
  - The map stores the frequency of characters in the `magazine`, and its size depends on the number of unique characters. In the worst case, this could be O(m), where `m` is the number of unique characters.

---

### 🏁 Conclusion

This solution solves the problem by efficiently counting the frequencies of characters in both the `ransomNote` and `magazine`. Here's a quick summary of the approach and its benefits:

- **Time Complexity**: **O(m + n)**, where `m` and `n` are the lengths of the `magazine` and `ransomNote` strings, respectively.
- **Space Complexity**: **O(m)**, where `m` is the number of unique characters in the `magazine`.

By using a frequency map, we ensure that we check if we can match the characters needed for the ransom note while maintaining the efficiency of the algorithm. This makes the solution optimal and scalable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/ransom-note/description/)

---
{{< youtube i3bvxJyUB40 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
