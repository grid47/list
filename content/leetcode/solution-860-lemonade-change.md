
+++
authors = ["grid47"]
title = "Leetcode 860: Lemonade Change"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 860: Lemonade Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mSVAw0AUZgA"
youtube_upload_date="2024-08-15"
youtube_thumbnail="https://i.ytimg.com/vi/mSVAw0AUZgA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int x : bills) {
                 if (x == 5) five++;
            else if (x == 10) {
                     if (five > 0) five--, ten++;
                else return false;
            } else {
                     if (five > 0 && ten > 0) five--, ten--;
                else if (five > 2) five -= 3;
                else return false;
            }
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is a simulation of a lemonade stand where customers pay with $5, $10, or $20 bills. The objective is to determine whether the cashier can provide the correct change for every customer, based on the bills they give. 

The cashier starts with no money, and each time a customer pays, the cashier must provide change:
- If the customer pays with a $5 bill, no change is required.
- If the customer pays with a $10 bill, the cashier must provide $5 as change.
- If the customer pays with a $20 bill, the cashier must provide $15 as change. This can be done with either one $10 bill and one $5 bill, or three $5 bills.

We need to determine if it is possible to provide correct change for every customer in line. If at any point the cashier cannot give the correct change, the function should return `false`. Otherwise, it should return `true`.

### Approach

The key to solving this problem efficiently is to simulate the process step by step, keeping track of how many $5 and $10 bills the cashier has available for giving change. We can use the following steps to solve the problem:

1. **Tracking Cash on Hand**: The cashier's ability to give correct change depends on the number of $5 and $10 bills available. We will track these counts using two variables, `five` and `ten`, where:
   - `five` keeps track of the number of $5 bills.
   - `ten` keeps track of the number of $10 bills.

2. **Process Each Customer**: We will process each bill in the input list one by one:
   - If the customer pays with a $5 bill, the cashier does not need to give any change, so we just increase the count of $5 bills.
   - If the customer pays with a $10 bill, the cashier needs to give $5 as change. If there is at least one $5 bill available, the cashier can give the change by reducing the count of $5 bills and increasing the count of $10 bills.
   - If the customer pays with a $20 bill, the cashier needs to give $15 as change. The preferred way to give $15 is with one $10 bill and one $5 bill, as it preserves more $5 bills for future transactions. If this is not possible, the cashier can give the change with three $5 bills.

3. **Edge Cases**: We need to ensure that the cashier never runs out of the required bills to give the correct change. If at any point, the cashier cannot provide the required change, we should return `false`.

4. **End of Process**: If we successfully process all the customers without running into an issue with giving change, we return `true`.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int five = 0, ten = 0;
```

- We start by initializing two variables, `five` and `ten`, to keep track of the number of $5 and $10 bills the cashier has.

#### Step 2: Process Each Bill

```cpp
for (int x : bills) {
```

- We iterate over each bill in the `bills` array. Each customer pays with a $5, $10, or $20 bill, and we need to handle the change accordingly.

#### Step 3: Handle $5 Bill

```cpp
if (x == 5) five++;
```

- If the customer pays with a $5 bill, no change is needed. We simply increment the count of $5 bills by 1.

#### Step 4: Handle $10 Bill

```cpp
else if (x == 10) {
    if (five > 0) five--, ten++;
    else return false;
}
```

- If the customer pays with a $10 bill, the cashier needs to give $5 as change. If the cashier has at least one $5 bill, we decrement the count of $5 bills by 1 and increment the count of $10 bills by 1.
- If the cashier doesn't have any $5 bills to give as change, we return `false` immediately, indicating that it's impossible to provide the correct change.

#### Step 5: Handle $20 Bill

```cpp
else {
    if (five > 0 && ten > 0) five--, ten--;
    else if (five > 2) five -= 3;
    else return false;
}
```

- If the customer pays with a $20 bill, the cashier needs to provide $15 as change. The preferred method is to give one $10 bill and one $5 bill as change. If the cashier has both, we decrement the counts of $5 and $10 bills.
- If the cashier doesn't have both, we try to give the change using three $5 bills. If the cashier has at least three $5 bills, we decrement the count of $5 bills by 3.
- If neither of these options is possible, the cashier cannot provide the correct change, so we return `false`.

#### Step 6: Return True

```cpp
return true;
```

- If we have processed all customers without running into any issues providing change, we return `true`, indicating that the cashier was able to give the correct change to every customer.

### Complexity

#### Time Complexity:
- The time complexity of this solution is **O(n)**, where `n` is the number of customers in the `bills` array. We iterate through the array once and perform constant-time operations for each bill, so the time complexity is linear in the size of the input.

#### Space Complexity:
- The space complexity is **O(1)**, as we only use a fixed amount of extra space (the variables `five` and `ten`) regardless of the size of the input.

### Conclusion

This solution efficiently simulates the process of giving change at a lemonade stand. By tracking the number of $5 and $10 bills the cashier has, we can determine whether the cashier is able to provide the correct change for every customer in the line. The algorithm runs in **O(n)** time, making it suitable for large inputs, and it uses **O(1)** space, which ensures space efficiency.

[`Link to LeetCode Lab`](https://leetcode.com/problems/lemonade-change/description/)

---
{{< youtube mSVAw0AUZgA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
