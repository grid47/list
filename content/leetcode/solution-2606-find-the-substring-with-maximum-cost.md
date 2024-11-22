
+++
authors = ["grid47"]
title = "Leetcode 2606: Find the Substring With Maximum Cost"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2606: Find the Substring With Maximum Cost in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EwSIfXGq2B4"
youtube_upload_date="2023-04-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EwSIfXGq2B4/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char, int> mp;
        for(int i = 0; i < chars.size(); i++) {
            mp[chars[i]] = vals[i];
        }
        for(int i = 0; i < 26; i++) {
            char x = 'a' + i;
            if(mp.count(x)) continue;
            mp[x] = i + 1;
        }
        
        int lmax = 0, gmax = 0;
        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] < lmax + mp[s[i]]) {
                lmax = lmax + mp[s[i]];
            } else lmax = mp[s[i]];
            
            gmax = max(gmax, lmax);
        }
        return gmax;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are tasked with finding the maximum possible cost of a substring in a given string `s`. The cost of each character in `s` is determined by a list of values given in the array `vals` corresponding to a set of characters in the string `chars`. For the characters in `chars`, we use the provided values in `vals`, and for characters that are not in `chars`, we assign a default value based on their alphabetical position. The goal is to calculate the maximum cost of a substring of `s`, where the cost of the substring is defined as the sum of the values of its characters.

### Approach

The solution employs the following approach:

1. **Mapping character values**: First, create a map that stores the value for each character in `chars`. If a character in `s` is not in `chars`, its value is assigned based on its position in the alphabet.
   
2. **Kadane’s Algorithm for Maximum Subarray Sum**: Once the values for each character in `s` are determined, the problem reduces to finding the maximum sum of any contiguous subarray of these values. This is a classic problem solved using Kadane’s algorithm, which keeps track of the running sum and updates the maximum sum encountered.

3. **Iterating through the string**: For each character in `s`, its corresponding value (from the map) is added to the running sum (`lmax`). If this value decreases the sum (i.e., if the sum becomes negative), we reset the running sum to the value of the current character. The global maximum (`gmax`) is updated accordingly to track the highest sum seen so far.

### Code Breakdown (Step by Step)

#### 1. **Map the values for characters**:
```cpp
map<char, int> mp;
for(int i = 0; i < chars.size(); i++) {
    mp[chars[i]] = vals[i];
}
```
- Here, we create a map `mp` where each character in the `chars` string is mapped to its corresponding value from `vals`.
- This allows us to easily look up the value for each character in the string `s`.

#### 2. **Assign default values to missing characters**:
```cpp
for(int i = 0; i < 26; i++) {
    char x = 'a' + i;
    if(mp.count(x)) continue;
    mp[x] = i + 1;
}
```
- This loop checks for characters in the alphabet that are not present in the `chars` string. 
- For those characters, we assign a default value, which is their alphabetical position. For example, 'a' gets a value of 1, 'b' gets a value of 2, and so on.

#### 3. **Initialize variables for Kadane's algorithm**:
```cpp
int lmax = 0, gmax = 0;
```
- `lmax` keeps track of the current running sum of the substring. It is initialized to 0 because we start with no elements selected.
- `gmax` stores the global maximum sum encountered during the iteration through the string `s`.

#### 4. **Iterate through the string to compute the maximum sum**:
```cpp
for(int i = 0; i < s.size(); i++) {
    if(mp[s[i]] < lmax + mp[s[i]]) {
        lmax = lmax + mp[s[i]];
    } else lmax = mp[s[i]];

    gmax = max(gmax, lmax);
}
```
- The loop iterates through each character in the string `s` and uses the previously created map `mp` to get the corresponding value of the character.
- If adding the current character’s value to the running sum (`lmax`) results in a higher value than just using the current character’s value alone, the running sum is updated to include the current character’s value.
- If adding the character’s value results in a smaller sum (i.e., the running sum would be negative), the running sum is reset to the value of the current character.
- At each step, `gmax` is updated to keep track of the highest sum encountered.

#### 5. **Return the result**:
```cpp
return gmax;
```
- After iterating through the string, the function returns `gmax`, which contains the maximum sum of the substring.

### Complexity Analysis

#### Time Complexity:
- **Mapping the character values**: Creating the map from `chars` to `vals` takes \(O(c)\), where \(c\) is the size of `chars`.
- **Assigning default values**: The loop that assigns default values to characters takes \(O(26)\), which is constant and can be ignored.
- **Kadane’s algorithm**: The iteration over the string `s` takes \(O(n)\), where \(n\) is the length of `s`.
- **Overall Time Complexity**: The overall time complexity is \(O(n + c)\), where \(n\) is the length of `s` and \(c\) is the length of `chars`. Since \(c\) is typically much smaller than \(n\), we can approximate the time complexity as \(O(n)\).

#### Space Complexity:
- **Map storage**: The map `mp` stores up to 26 characters (one for each letter of the alphabet), so it uses \(O(26)\) space, which is constant.
- **Other variables**: The other variables (`lmax`, `gmax`) take constant space.
- **Overall Space Complexity**: The space complexity is \(O(1)\), as the map size is bounded by the number of letters in the alphabet (26).

### Conclusion

This solution efficiently calculates the maximum cost of any substring of `s` by first mapping the values of the characters and then applying Kadane’s algorithm to find the maximum sum subarray. The algorithm operates in linear time with respect to the size of the string, making it optimal for large inputs. The approach is both time and space efficient, using a map to store character values and applying a standard algorithm for maximum subarray sum to solve the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/)

---
{{< youtube EwSIfXGq2B4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
