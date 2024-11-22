
+++
authors = ["grid47"]
title = "Leetcode 1371: Find the Longest Substring Containing Vowels in Even Counts"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1371: Find the Longest Substring Containing Vowels in Even Counts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "o17MBWparrI"
youtube_upload_date="2024-09-15"
youtube_thumbnail="https://i.ytimg.com/vi/o17MBWparrI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<char, int> id = {
            {'a' , 1},
            {'e' , 2},
            {'i' , 3},
            {'o' , 4},
            {'u' , 5},
            };
        int res = 0, msk = 0;
        map<int, int> mp;
 
        mp[0] = -1;
        for (int i = 0; i < s.length(); i++) {
            int x = id[s[i]];
            
            if(x != 0)
            msk ^= (1 << x);
            if(mp.count(msk)) {
            res = max(res, i - mp[msk]);
                }
            else {
            mp[msk] = i;}
        }
        
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem is to find the length of the longest substring of a given string `s` that contains an even number of each vowel: 'a', 'e', 'i', 'o', and 'u'. A substring is defined as a contiguous sequence of characters within the string. The challenge lies in efficiently tracking the occurrences of vowels and ensuring that each vowel appears an even number of times within any considered substring.

### Approach
To solve this problem, we can utilize a bitmasking technique combined with a hash map to track the state of vowel occurrences. The key steps are as follows:
1. **Bitmask Representation**: Use a bitmask to represent the even or odd occurrence of each vowel. For example, if 'a' has been encountered an odd number of times, the corresponding bit in the mask will be set to 1.
2. **Map to Track Indices**: Use a map to store the first occurrence of each unique mask encountered while traversing the string. This allows us to calculate the length of substrings with matching masks efficiently.
3. **Iterate Through the String**: As we iterate through the string, update the mask and check if it has been seen before. If it has, compute the length of the substring and update the maximum length accordingly.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Map to assign a unique number for each vowel
        map<char, int> id = {
            {'a' , 1},
            {'e' , 2},
            {'i' , 3},
            {'o' , 4},
            {'u' , 5},
        };
        
        int res = 0; // Variable to store the result (maximum length)
        int msk = 0; // Bitmask to track vowel parity
        map<int, int> mp; // Map to store the first occurrence of each mask

        mp[0] = -1; // Initial condition: mask 0 corresponds to index -1
        for (int i = 0; i < s.length(); i++) {
            int x = id[s[i]]; // Get the bit position for the current character

            // If the character is a vowel, toggle its corresponding bit in the mask
            if(x != 0)
                msk ^= (1 << x);
            
            // Check if this mask has been seen before
            if(mp.count(msk)) {
                // Calculate the length of the substring
                res = max(res, i - mp[msk]);
            } else {
                // Store the first occurrence of this mask
                mp[msk] = i;
            }
        }
        
        return res; // Return the maximum length found
    }
};
```

1. **Class Definition**:
   - The `Solution` class contains the public method `findTheLongestSubstring`.

2. **Vowel Mapping**:
   - The `id` map assigns a unique bit position for each vowel: 
     - 'a' → 1
     - 'e' → 2
     - 'i' → 3
     - 'o' → 4
     - 'u' → 5
   - The bitmask uses these positions to track the parity of vowel occurrences.

3. **Initialization**:
   - `res`: This variable will store the maximum length of the substring found that satisfies the conditions.
   - `msk`: The bitmask initialized to zero. This will be updated as we iterate through the string.
   - `mp`: A map initialized to contain the entry `{0: -1}`, representing the default state (no vowels seen) at an imaginary index before the start of the string.

4. **Iterating Through the String**:
   - For each character in the string:
     - Check if it’s a vowel by looking it up in the `id` map.
     - If it is a vowel, toggle the corresponding bit in the `msk` using the XOR operation: `msk ^= (1 << x)`. This effectively flips the bit, allowing us to track even/odd occurrences.
     - Use `mp.count(msk)` to check if this mask has been seen before. If it has:
       - Calculate the length of the substring from the index stored in `mp[msk]` to the current index `i`.
       - Update `res` with the maximum length found.
     - If the mask has not been seen before, store the current index `i` in the map with the key `msk`.

5. **Return the Result**:
   - After processing the entire string, return the maximum length stored in `res`.

### Complexity Analysis
- **Time Complexity**:
  - The algorithm runs in \(O(N)\), where \(N\) is the length of the string `s`. This is due to the single pass through the string and constant-time operations for bit manipulation and map accesses.
  
- **Space Complexity**:
  - The space complexity is \(O(1)\) for the bitmask since it uses a fixed number of bits (5 bits for vowels). The space for the map `mp` could be considered \(O(N)\) in the worst case, where each state is unique.

### Conclusion
The provided solution effectively utilizes bit manipulation and hashing to find the longest substring containing an even number of each vowel. This approach is efficient and elegant, leveraging the properties of binary representation to manage the counting of vowel occurrences. By iterating through the string only once and maintaining a hash map for quick lookups, the solution achieves optimal performance. This methodology can serve as a useful reference for tackling similar substring problems involving character frequency conditions.

This comprehensive explanation highlights the key components of the code while ensuring clarity and detail, making it suitable for readers looking to understand or implement similar solutions.


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/)

---
{{< youtube o17MBWparrI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
