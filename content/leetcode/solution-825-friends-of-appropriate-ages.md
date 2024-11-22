
+++
authors = ["grid47"]
title = "Leetcode 825: Friends Of Appropriate Ages"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 825: Friends Of Appropriate Ages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0_4H68f85HQ"
youtube_upload_date="2020-05-19"
youtube_thumbnail="https://i.ytimg.com/vi/0_4H68f85HQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> cnt;
        for(int age: ages)
            cnt[age]++;

        int res = 0;
        for(auto a: cnt)
        for(auto b: cnt)
        if(request(a.first, b.first))
            res += a.second * (b.second - (a.first == b.first? 1: 0));
        return res;
    }

    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given an array of ages, where each element represents the age of a person. The task is to calculate the total number of **friend requests** that can be made based on a specific set of rules. The rules for friend requests between two people with ages `a` and `b` are as follows:

1. A person with age `a` can send a friend request to another person with age `b` if:
   - `b` is greater than 0.5 times `a` plus 7 (`b > 0.5 * a + 7`).
   - `b` is not greater than `a` (`b <= a`).
   - If `b` is greater than 100, `a` must also be greater than 100 (`b <= 100` and `a > 100`).

Given these conditions, the goal is to calculate how many valid friend requests can be made for all pairs of people in the given `ages` list.

### Approach

The approach to solving this problem involves:

1. **Counting the Frequency of Ages**:
   - Since we are only interested in comparing pairs of ages and making requests between them, it is beneficial to first count how many people are of each age. This can be done using a hash map, where the key is the age and the value is the count of people with that age.

2. **Iterating Over All Age Pairs**:
   - Once we have the frequency of each age, we need to iterate over all pairs of ages (`a` and `b`). For each pair, check if the friend request is valid using the provided rules.
   - If a valid friend request exists between ages `a` and `b`, the number of possible requests is the product of their respective frequencies. However, if `a == b`, we subtract one from the count to avoid counting the person sending a request to themselves.

3. **Efficiency**:
   - Instead of comparing every person with every other person (which would take quadratic time), we reduce the problem to a pairwise comparison of distinct ages by counting the occurrences of each age.

4. **Request Function**:
   - A helper function `request(int a, int b)` checks whether a valid request can be made based on the given conditions. This ensures that the core logic is clean and modular.

### Code Breakdown (Step by Step)

1. **Count Frequency of Ages**:
   ```cpp
   unordered_map<int, int> cnt;
   for(int age: ages)
       cnt[age]++;
   ```
   - We create an unordered map `cnt` to store the frequency of each age. By iterating over the `ages` array, we populate this map, where the key is the age and the value is the count of people with that age.

2. **Iterating Through Age Pairs**:
   ```cpp
   int res = 0;
   for(auto a: cnt)
   for(auto b: cnt)
       if(request(a.first, b.first))
           res += a.second * (b.second - (a.first == b.first ? 1 : 0));
   ```
   - We initialize `res` to zero, which will hold the total number of valid requests.
   - We then iterate over all pairs of ages in the frequency map `cnt`. Each pair of ages (`a.first` and `b.first`) is checked to see if a request is valid using the helper function `request`.
   - If the request is valid, we calculate the number of possible requests between these two ages. If both `a` and `b` are the same, we subtract one to ensure that a person doesn’t send a request to themselves.

3. **Helper Function for Validating Requests**:
   ```cpp
   bool request(int a, int b) {
       return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
   }
   ```
   - The `request` function checks if a friend request can be made between two people of ages `a` and `b` by verifying the following conditions:
     1. `b > 0.5 * a + 7`: ensures that `b` is not too small compared to `a`.
     2. `b <= a`: ensures that `b` is not greater than `a` because the rule specifies that a person can only send a request to someone younger or of the same age.
     3. `(b > 100 && a < 100)`: ensures that if `b` is greater than 100, `a` must also be greater than 100.

4. **Return the Result**:
   ```cpp
   return res;
   ```
   - Finally, the total number of valid friend requests `res` is returned.

### Complexity

- **Time Complexity**: 
   - The time complexity is \(O(n + k^2)\), where \(n\) is the size of the `ages` array and \(k\) is the number of distinct ages in the `ages` list.
   - The first part of the code (counting frequencies) takes \(O(n)\), where \(n\) is the number of people in the list.
   - The second part, where we iterate over all pairs of distinct ages, takes \(O(k^2)\), where \(k\) is the number of unique ages. In the worst case, if all ages are distinct, \(k\) is \(n\), leading to a quadratic time complexity for the pairwise comparison.

- **Space Complexity**: 
   - The space complexity is \(O(k)\), where \(k\) is the number of unique ages, as we store the frequency of each unique age in the unordered map `cnt`.

### Conclusion

This solution efficiently calculates the total number of valid friend requests based on the given conditions. By using a frequency map to count the occurrences of each age, we reduce the problem from potentially \(O(n^2)\) (comparing every person to every other person) to \(O(k^2)\), where \(k\) is the number of distinct ages. The helper function `request` ensures that the conditions for valid requests are checked in a modular and clean way. The solution is both time-efficient and space-efficient, making it suitable for large inputs where \(n\) (the number of people) can be large.

[`Link to LeetCode Lab`](https://leetcode.com/problems/friends-of-appropriate-ages/description/)

---
{{< youtube 0_4H68f85HQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
