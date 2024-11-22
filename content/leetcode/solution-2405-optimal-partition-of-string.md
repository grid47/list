
+++
authors = ["grid47"]
title = "Leetcode 2405: Optimal Partition of String"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2405: Optimal Partition of String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1Zx7gEznzfI"
youtube_upload_date="2023-04-04"
youtube_thumbnail="https://i.ytimg.com/vi/1Zx7gEznzfI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkBit(int &flag, int &n) {
        return flag & (1<< n);
    }

    void setBit(int &flag, int & n) {
        flag |= (1<<n);
    }

    int partitionString(string s) {
        int flag = 0, ans = 1;
        for(auto c: s) {
            int n = c - 'a';
            if(checkBit(flag, n)) {
                flag = 0;
                ans++;
            }
            setBit(flag, n);
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to divide the given string `s` into the minimum number of substrings such that no character is repeated in any substring. In other words, we want to partition the string into parts where each part contains only unique characters. The task is to return the minimum number of such partitions.

### Approach

The approach to solve this problem efficiently involves utilizing a **bitmasking** technique, which allows us to track the characters we've seen in the current partition in an efficient manner.

#### Key Insights:
1. **Bitmasking**: Each character of the string can be mapped to a unique bit in an integer (for example, 'a' maps to the least significant bit, 'b' to the second least significant bit, and so on). Using this bitmask representation, we can efficiently check if a character has been seen before in the current partition and add it if it's not already present.
   
2. **Greedy Partitioning**: We can process the string character by character and partition the string as we go. Every time we encounter a character that has already been seen in the current partition, we increment the partition count and start a new partition.

3. **Efficiency**: Bitmasking operations like checking a bit and setting a bit are constant time operations, which makes this approach efficient. The overall time complexity is linear with respect to the size of the string.

### Code Breakdown (Step by Step)

#### Step 1: Helper Functions to Manage Bitmask
The solution makes use of two helper functions: `checkBit` and `setBit`.

```cpp
bool checkBit(int &flag, int &n) {
    return flag & (1 << n);
}

void setBit(int &flag, int &n) {
    flag |= (1 << n);
}
```

- **`checkBit(int &flag, int &n)`**:
  - This function checks if the `n`-th bit in the `flag` is set to `1`. If the bit is set, it indicates that the character corresponding to this bit has already been seen in the current partition.
  - It uses the bitwise AND operation `&` to check if the bit is set: `flag & (1 << n)`. This operation shifts `1` to the `n`-th position and performs the AND operation with `flag`. If the result is non-zero, the bit is set, and we return `true`.

- **`setBit(int &flag, int &n)`**:
  - This function sets the `n`-th bit in the `flag` to `1`. It uses the bitwise OR operation `|= (1 << n)` to set the `n`-th bit.
  - The bitwise OR operation ensures that the corresponding bit in `flag` is set to `1` without affecting other bits.

#### Step 2: Main Logic in `partitionString`

```cpp
int partitionString(string s) {
    int flag = 0, ans = 1;
    for (auto c: s) {
        int n = c - 'a';
        if (checkBit(flag, n)) {
            flag = 0;
            ans++;
        }
        setBit(flag, n);
    }
    return ans;
}
```

- **`int flag = 0, ans = 1;`**: 
  - The `flag` variable is used to track which characters have been seen in the current partition. It is initially set to `0`, meaning no characters have been seen.
  - The `ans` variable tracks the number of partitions. It starts at `1` because we always have at least one partition.

- **`for (auto c: s)`**:
  - This loop iterates over every character `c` in the string `s`.
  
- **`int n = c - 'a';`**:
  - We convert the character `c` to an integer `n` representing its position in the alphabet. For example, for the character 'a', `n` will be `0`, for 'b' it will be `1`, and so on.
  
- **`if (checkBit(flag, n)) {`**:
  - This checks if the character corresponding to `n` has already been seen in the current partition. If it has, it means we need to start a new partition.
  - We reset `flag` to `0`, which means the new partition doesn't contain any previously encountered characters.
  - We increment the partition count `ans` to reflect the start of a new partition.
  
- **`setBit(flag, n);`**:
  - After checking if the character has already been seen in the current partition, we set the corresponding bit for the character `n` in `flag`. This marks the character as seen in the current partition.

- **`return ans;`**:
  - Finally, after processing all characters in the string, we return the value of `ans`, which represents the minimum number of partitions.

### Complexity

#### Time Complexity:
- **O(n)**: 
  - The loop processes each character in the string `s` exactly once. Each operation inside the loop (checking and setting bits) is constant time due to the efficient bitwise operations. Therefore, the overall time complexity is **O(n)**, where `n` is the length of the string `s`.

#### Space Complexity:
- **O(1)**: 
  - The space complexity is constant because we only use a fixed amount of space regardless of the input size. Specifically, the `flag` variable uses a fixed amount of space (a 32-bit integer), and there is no need for extra space that grows with the input size.

### Conclusion

This solution provides an efficient way to partition a string into the minimum number of substrings where each substring contains unique characters. By leveraging **bitmasking** for constant-time checks and updates, the solution achieves optimal time complexity of **O(n)**. 

#### Key Points:
- **Bitmasking** is a powerful technique to track character occurrences efficiently.
- The solution works by greedily partitioning the string whenever a repeated character is found.
- The overall time complexity is linear with respect to the size of the string, making the solution scalable for large inputs.

This approach ensures that we solve the problem efficiently while using minimal space, making it ideal for competitive programming or real-world applications where performance is crucial.

[`Link to LeetCode Lab`](https://leetcode.com/problems/optimal-partition-of-string/description/)

---
{{< youtube 1Zx7gEznzfI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
