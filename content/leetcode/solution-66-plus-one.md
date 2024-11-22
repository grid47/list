
+++
authors = ["grid47"]
title = "Leetcode 66: Plus One"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 66: Plus One in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/66.webp"
youtube = "tDjI08W1I7g"
youtube_upload_date="2022-03-07"
youtube_thumbnail="https://i.ytimg.com/vi/tDjI08W1I7g/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/66.webp" 
    alt="A glowing number gently increasing by one, signifying growth and positivity."
    caption="Solution to LeetCode 66: Plus One Problem"
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
    vector<int> plusOne(vector<int>& d) {
        int sum = 1;
        list<int> lst;
        for(int i = d.size() - 1; i >= 0; i--) {
            sum += d[i];
            lst.push_front(sum % 10);
            sum = sum /10;
        }
        if(sum > 0) lst.push_front(sum);
        vector<int> res(lst.begin(), lst.end());
        return res;
    }
};
{{< /highlight >}}
---

### ➕ **Add One to a Number Represented by Digits**

This problem involves adding one to a non-negative integer represented as a list of digits. For example, if the input list `d` represents the number `129`, the output should be `130`, represented as `[1, 3, 0]`. The task is to handle potential carryover, where adding one may affect multiple digits, especially in cases like `999`, which becomes `1000`.

### 🧠 **Approach**

The solution iterates backward from the least significant digit (last element in the array) to the most significant digit (first element). It adds one to the least significant digit, and if a carry is generated (i.e., a digit becomes `10`), it continues to propagate this carry towards the most significant digit. To keep track of the carry, the algorithm:
- Uses a variable `sum` initialized to `1`, representing the "plus one" operation.
- For each digit, it adds the carry to the digit, determines the resulting digit (using modulo `10`), and updates `sum` to be the carry for the next iteration.

This approach efficiently updates each digit in a single pass through the array, handling carries as they occur.

### 🔍 **Code Breakdown (Step by Step)**

#### Step 1: Initialize Carry

```cpp
int sum = 1;
list<int> lst;
```
- The `sum` variable is initialized to `1`, representing the initial addition. A `list<int>` named `lst` is used to build the result, allowing efficient addition of elements at the front.

#### Step 2: Loop Through Digits from Right to Left

```cpp
for(int i = d.size() - 1; i >= 0; i--) {
    sum += d[i];
    lst.push_front(sum % 10);
    sum = sum / 10;
}
```
- For each digit starting from the last:
  - Adds `d[i]` to `sum`.
  - Adds the unit place of `sum` (i.e., `sum % 10`) to the front of `lst`.
  - Updates `sum` to be the carry (i.e., `sum / 10`) for the next digit.

#### Step 3: Handle Remaining Carry

```cpp
if(sum > 0) lst.push_front(sum);
```
- If `sum` is greater than zero after processing all digits, a leftover carry is added to the front of `lst`, covering cases like `999` becoming `1000`.

#### Step 4: Convert Linked List to Vector

```cpp
vector<int> res(lst.begin(), lst.end());
```
- Converts `lst` to a `vector<int>` for the final output, as the return type is a vector.

#### Step 5: Return Result

```cpp
return res;
```
- The final result is returned as a vector representing the number after adding one.

### 📊 **Complexity Analysis**

#### Time Complexity:
- **O(n)**: The algorithm iterates through the list of digits once, where `n` is the number of digits.

#### Space Complexity:
- **O(n)**: The space used by the list and the resulting vector is proportional to the number of digits.

### 🌟 **Conclusion**

This solution is efficient for adding one to a large integer represented by an array of digits. It effectively handles carries through the linked list’s flexibility, allowing easy addition at the front. This approach is optimal, with a single traversal of the digits and minimal auxiliary space, making it suitable for cases with large numbers or multiple carries.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/plus-one/description/)

---
{{< youtube tDjI08W1I7g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
