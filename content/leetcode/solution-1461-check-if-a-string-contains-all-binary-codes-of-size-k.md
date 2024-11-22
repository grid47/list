
+++
authors = ["grid47"]
title = "Leetcode 1461: Check If a String Contains All Binary Codes of Size K"
date = "2024-06-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1461: Check If a String Contains All Binary Codes of Size K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Rolling Hash","Hash Function"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qU32rTy_kOM"
youtube_upload_date="2022-05-31"
youtube_thumbnail="https://i.ytimg.com/vi/qU32rTy_kOM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.size();
        set<int> cnt;
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            if(i < k) {
                tmp = tmp * 2 + (s[i] == '0'? 0: 1);
                continue;
            }
            cnt.insert(tmp);
            tmp *= 2;
            tmp &= ((1 << k) - 1);            
            tmp += (s[i] == '0'? 0: 1);
        }
        cnt.insert(tmp);
        // cout << cnt.size() << " " << (1 << k);
        return cnt.size() == (1 << k);
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine if a binary string `s` contains all possible binary codes of length `k`. A binary code of length `k` is simply a sequence of `k` bits (0s and 1s). For example, for \( k = 2 \), the valid codes are "00", "01", "10", and "11". If the string contains all possible binary codes of length \( k \), the function should return `true`; otherwise, it should return `false`.

### Approach

To solve this problem, we can use a sliding window technique combined with bit manipulation. The key idea is to slide through the string while constructing binary numbers based on the current window of size \( k \). Here’s a breakdown of the approach:

1. **Initialize Variables**:
   - We will maintain a set to keep track of the unique binary codes found in the string.
   - A temporary integer will be used to store the current binary number being formed.

2. **Iterate Through the String**:
   - As we traverse the string, we will continuously update the binary number.
   - For the first \( k \) characters, we build the initial binary number.
   - After processing the first \( k \) characters, we start sliding the window by one character at a time:
     - Shift the current binary number left by one (multiply by 2).
     - Ensure that the binary number stays within the limits of \( k \) bits using bitwise AND.
     - Add the new bit from the string to the current binary number.

3. **Store Unique Codes**:
   - Each time a new binary number is formed, it is added to the set.
   - After processing the entire string, we check if the size of the set matches the number of unique binary codes possible for length \( k \) (which is \( 2^k \)).

4. **Return the Result**:
   - If the size of the set is equal to \( 2^k \), we return `true`; otherwise, we return `false`.

### Code Breakdown (Step by Step)

Here's the detailed breakdown of the provided code:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```

   - The solution is implemented within a class named `Solution`, which is standard in competitive programming and coding interviews.

2. **Function Definition**:
   ```cpp
   bool hasAllCodes(string s, int k) {
   ```

   - This function takes a binary string `s` and an integer `k` as inputs and returns a boolean indicating whether all binary codes of length \( k \) are present in the string.

3. **Variable Initialization**:
   ```cpp
   int n = s.size();
   set<int> cnt;
   int tmp = 0;
   ```

   - `n`: The length of the string `s`.
   - `cnt`: A set to store the unique binary codes we find.
   - `tmp`: A temporary variable to construct the current binary number.

4. **Iterate Through the String**:
   ```cpp
   for(int i = 0; i < n; i++) {
   ```

   - We begin a loop to iterate through each character of the string.

5. **Building the Initial Binary Number**:
   ```cpp
   if(i < k) {
       tmp = tmp * 2 + (s[i] == '0'? 0: 1);
       continue;
   }
   ```

   - For the first \( k \) characters, we construct the initial binary number by shifting left and adding the current bit:
     - If the current character is '0', we add 0; if it's '1', we add 1.
   - The `continue` statement skips the remaining code in the loop for this iteration.

6. **Sliding Window Logic**:
   ```cpp
   cnt.insert(tmp);
   tmp *= 2;
   tmp &= ((1 << k) - 1);
   tmp += (s[i] == '0'? 0: 1);
   ```

   - Once we have processed the first \( k \) characters:
     - We insert the current binary number `tmp` into the set.
     - We shift `tmp` left by one (i.e., multiply by 2) to make space for the next bit.
     - The bitwise AND operation ensures that `tmp` retains only the least significant \( k \) bits.
     - We then add the new bit corresponding to the character at index \( i \).

7. **Final Insertion**:
   ```cpp
   cnt.insert(tmp);
   ```

   - After the loop, we need to insert the last binary number formed from the final window into the set.

8. **Check the Result**:
   ```cpp
   return cnt.size() == (1 << k);
   ```

   - We compare the size of the set `cnt` with \( 2^k \) (which can be computed as `1 << k`).
   - If they are equal, it means we have found all possible binary codes of length \( k \).

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \( O(n) \), where \( n \) is the length of the string `s`. This is because we traverse the string once, performing constant-time operations within the loop.

- **Space Complexity**: The space complexity is \( O(1) \) for the `tmp` variable and \( O(2^k) \) for the set, which may grow depending on the value of \( k \). Since there are at most \( 2^k \) unique codes, the overall space complexity is dictated by the set storage.

### Conclusion

This solution efficiently determines if all binary codes of length \( k \) are present in the given binary string using a combination of sliding window techniques and bit manipulation. The approach is optimal in both time and space, making it suitable for large strings and various values of \( k \). Key points of the solution include:

1. **Sliding Window**: By managing a rolling binary number, we efficiently compute and track all possible binary codes without having to create explicit substrings.

2. **Set Usage**: Using a set to store unique codes allows us to easily track and count the codes found during the iteration.

3. **Bit Manipulation**: The bitwise operations provide a clear and concise method for managing binary data.

Overall, this approach provides a robust framework for solving the problem, demonstrating effective use of algorithms and data structures in competitive programming contexts.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/)

---
{{< youtube qU32rTy_kOM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
