
+++
authors = ["grid47"]
title = "Leetcode 1898: Maximum Number of Removable Characters"
date = "2024-05-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1898: Maximum Number of Removable Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NMP3nRPyX5g"
youtube_upload_date="2021-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/NMP3nRPyX5g/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int isSubseq(string &s, string &p, vector<int>& mp, int k) {
        int i = 0, j = 0;
        while(i < s.size() && j < p.size()) {
            if(mp[i] <= k) {
                i++;
                continue;
            }
            if(s[i] == p[j]) {
                i++;
                j++;
                if(j == p.size()) return true;
            } else i++;
        }
        return false;
    }
    
    int maximumRemovals(string s, string p, vector<int>& rm) {
        vector<int> mp(s.size(), INT_MAX);
        for(int i = 0; i < rm.size(); i++)
            mp[rm[i]] = i;
        int l = 0, r = rm.size() - 1, ans = -1;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(isSubseq(s, p, mp, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans + 1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the maximum number of characters from a string `s` that can be removed while still ensuring that the string `p` remains a subsequence of the modified string. A subsequence is a sequence derived from another sequence where some elements may be deleted without changing the order of the remaining elements.

Given a string `s`, a string `p`, and an array `rm` that contains the indices of characters in `s` that can potentially be removed, the goal is to find the maximum number of characters that can be removed such that `p` remains a subsequence of the remaining characters in `s`.

### Approach

The solution to this problem employs a combination of binary search and a two-pointer technique. The core idea is to use binary search to find the maximum number of characters we can remove while still maintaining the subsequence condition.

1. **Binary Search**: We perform a binary search over the possible number of characters that can be removed, ranging from `0` to the size of the `rm` array.
2. **Subsequence Check**: For each middle value in the binary search, we check if `p` is still a subsequence of `s` after removing the specified characters using a helper function `isSubseq`.

### Code Breakdown (Step by Step)

1. **Class Definition**: We start by defining a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **isSubseq Function**: This function checks if `p` is a subsequence of `s` after removing characters according to the removal map `mp`.

   ```cpp
       int isSubseq(string &s, string &p, vector<int>& mp, int k) {
           int i = 0, j = 0;
           while(i < s.size() && j < p.size()) {
   ```

   - **Parameters**:
     - `s`: The original string.
     - `p`: The string to check as a subsequence.
     - `mp`: A map that marks the indices of characters in `s` that are allowed to be removed.
     - `k`: The maximum number of characters that can be removed.
   
   - **Pointer Initialization**: Two pointers, `i` for traversing `s` and `j` for traversing `p`, are initialized.

   ```cpp
               if(mp[i] <= k) {
                   i++;
                   continue;
               }
   ```

   - **Character Check**: If the character at index `i` in `s` is in the removal list up to `k`, we skip it by incrementing `i`. 

   ```cpp
               if(s[i] == p[j]) {
                   i++;
                   j++;
                   if(j == p.size()) return true;
               } else i++;
           }
           return false;
       }
   ```

   - **Subsequence Match**: If the characters match, we increment both `i` and `j`. If all characters of `p` are matched (`j == p.size()`), we return `true`. If they do not match, we simply increment `i` to continue checking.

3. **maximumRemovals Function**: This function uses binary search to find the maximum number of removable characters.

   ```cpp
       int maximumRemovals(string s, string p, vector<int>& rm) {
           vector<int> mp(s.size(), INT_MAX);
           for(int i = 0; i < rm.size(); i++)
               mp[rm[i]] = i;
   ```

   - **Initialization**: A vector `mp` is created to track the indices of characters in `s` that can be removed. It is initialized to `INT_MAX` to signify that no characters can be removed by default.

   ```cpp
           int l = 0, r = rm.size() - 1, ans = -1;
           while(l <= r) {
               int mid = l + (r - l + 1) / 2;
               if(isSubseq(s, p, mp, mid)) {
                   ans = mid;
                   l = mid + 1;
               } else {
                   r = mid - 1;
               }
           }
           return ans + 1;
       }
   };
   ```

   - **Binary Search Logic**: The search continues until `l` is less than or equal to `r`. For each midpoint `mid`, it checks if `p` remains a subsequence of `s` after removing `mid` characters. If it does, we update `ans` and search in the right half; otherwise, we search in the left half.

   - **Return Value**: Finally, the function returns `ans + 1`, as the count of removable characters is expected to be zero-indexed.

### Complexity

- **Time Complexity**: The overall time complexity of this solution is \( O(n \cdot m) \), where \( n \) is the length of string `s` and \( m \) is the length of string `p`. The binary search runs in \( O(\log r) \) iterations, where \( r \) is the size of the `rm` array, and in each iteration, the `isSubseq` function checks if `p` is a subsequence, taking \( O(n) \) time.

- **Space Complexity**: The space complexity is \( O(n) \) for the `mp` vector, which holds the removal indices.

### Conclusion

The `maximumRemovals` function effectively utilizes a combination of binary search and a subsequence checking mechanism to determine the maximum number of characters that can be removed from `s` while keeping `p` as a subsequence. This method is efficient and scales well with the size of the input strings and the removal indices.

This solution is not only optimal but also highlights the importance of combining different algorithmic strategies, such as binary search and two-pointer techniques, to solve complex problems efficiently. The approach is particularly useful in scenarios where we need to check conditions involving subsequences and character manipulations, making it a valuable addition to any algorithmic toolkit.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-removable-characters/description/)

---
{{< youtube NMP3nRPyX5g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
