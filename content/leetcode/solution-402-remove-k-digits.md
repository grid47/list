
+++
authors = ["grid47"]
title = "Leetcode 402: Remove K Digits"
date = "2024-09-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 402: Remove K Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/402.webp"
youtube = "cFabMOnJaq0"
youtube_upload_date="2022-02-18"
youtube_thumbnail="https://i.ytimg.com/vi/cFabMOnJaq0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/402.webp" 
    alt="A string of digits where each one is gently erased one by one, leaving the smallest number behind, glowing softly."
    caption="Solution to LeetCode 402: Remove K Digits Problem"
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
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.size();
        if(num.size() <= k) return "0";
        
        for(char c : num) {
            
            while(!ans.empty() && (ans.back() > c) && k) {
                ans.pop_back();
                k--;
            }
            
            if(!ans.empty() || c != '0') {
                ans.push_back(c);
            }
            
        }
        while(!ans.empty() && k--)
            ans.pop_back();
        if (ans.empty()) return "0";
        while (!ans.empty()) {
            num[n - 1] = ans.back();
            ans.pop_back(), n--;
        }
        return num.substr(n);
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires removing `k` digits from a given string `num` (representing a non-negative integer) to create the smallest possible number. The number must not have leading zeros, and if removing `k` digits results in an empty string, the result should be "0". The task is to return this smallest number after the removal.

### Approach

To solve this problem, we need to efficiently remove `k` digits to minimize the number. A greedy approach is best suited for this task. Here's a step-by-step breakdown of the approach:

1. **Iterate through the digits**:
   We want to traverse the digits of the string `num` one by one and decide whether to include each digit in the final answer or remove it. The goal is to always keep the smallest possible digits in the answer by removing larger digits when needed.

2. **Use a stack for digits**:
   To efficiently determine which digits to keep, we can use a stack (represented by the string `ans` here). The stack will hold the digits in the current order, but we will pop larger digits from it when we encounter a smaller digit, since the smaller digit can potentially lead to a smaller number.

3. **Ensure k digits are removed**:
   We will perform this removal while ensuring exactly `k` digits are removed. After processing all the digits, if there are still any remaining digits to be removed (i.e., if `k > 0`), we can simply remove digits from the end of the stack.

4. **Handle leading zeros**:
   The problem explicitly asks for no leading zeros in the final result. To address this, we only push non-zero digits to the stack, unless the stack is empty.

5. **Return the result**:
   After processing all digits, if the stack is empty (i.e., all digits were removed), we return "0". Otherwise, the remaining digits in the stack represent the smallest possible number. The string is then formatted by trimming any remaining leading zeros.

### Code Breakdown (Step by Step)

#### Step 1: Handle Edge Case

```cpp
if(num.size() <= k) return "0";
```

- If the length of the input string `num` is less than or equal to `k`, this means we would remove all digits, so the result should be "0".

#### Step 2: Initialize Variables

```cpp
string ans = "";
int n = num.size();
```

- `ans` is a string used as a stack to hold the digits of the final answer.
- `n` stores the size of the input string `num`.

#### Step 3: Traverse the Digits and Build the Answer

```cpp
for(char c : num) {
    while(!ans.empty() && (ans.back() > c) && k) {
        ans.pop_back();
        k--;
    }
    if(!ans.empty() || c != '0') {
        ans.push_back(c);
    }
}
```

- **Main loop**: We iterate over each digit `c` in the string `num`.
- **Greedy removal**: The `while` loop checks if the last digit in the stack is larger than the current digit (`ans.back() > c`) and if we still have digits left to remove (`k`). If both conditions are true, we remove the last digit from the stack and decrement `k` by 1.
- **Avoid leading zeros**: We only push the current digit `c` to the stack if it’s not leading zeros (`c != '0'`), except when the stack is empty, in which case leading zeros can be safely ignored.

#### Step 4: Remove Extra Digits (If Necessary)

```cpp
while(!ans.empty() && k--)
    ans.pop_back();
```

- After iterating through all the digits in `num`, if there are still digits left to remove (`k > 0`), we continue removing digits from the end of the stack.

#### Step 5: Handle the Case of an Empty Stack

```cpp
if (ans.empty()) return "0";
```

- If the stack is empty (i.e., we have removed all digits), we return "0" because the final number is zero.

#### Step 6: Construct the Final Answer

```cpp
while (!ans.empty()) {
    num[n - 1] = ans.back();
    ans.pop_back(), n--;
}
```

- We then construct the final result by filling the string `num` with the digits from the stack `ans` in reverse order. This step is used to convert the stack to a string representation of the smallest possible number.

#### Step 7: Return the Final Answer

```cpp
return num.substr(n);
```

- Finally, we return the substring of `num` starting from index `n` to remove any unused portion of the string, ensuring the result is correctly formatted.

### Complexity

#### Time Complexity:

- The algorithm processes each digit in the input string exactly once. Each digit is pushed to or popped from the stack at most once, leading to a total time complexity of **O(n)**, where `n` is the length of the input string `num`.

#### Space Complexity:

- The space complexity is determined by the storage required for the stack (`ans`), which can hold up to `n` digits in the worst case. Therefore, the space complexity is **O(n)**.

### Conclusion

The provided solution effectively solves the problem of removing `k` digits to form the smallest possible number using a greedy approach with a stack. The algorithm efficiently removes digits and ensures the smallest number by always keeping the smallest available digits. It also handles edge cases like leading zeros and situations where `k` is greater than or equal to the length of the number.

This approach has a time complexity of **O(n)**, making it efficient for even large inputs. The use of a stack allows the algorithm to perform the necessary operations efficiently, ensuring that we can easily construct the desired smallest number. 

In summary, the solution is both time-efficient and space-efficient, handling all possible edge cases and providing the correct result in optimal time.

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-k-digits/description/)

---
{{< youtube cFabMOnJaq0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
