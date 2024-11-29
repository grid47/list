
+++
authors = ["grid47"]
title = "Leetcode 2241: Design an ATM Machine"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2241: Design an ATM Machine in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "edP4gaMO80E"
youtube_upload_date="2022-04-16"
youtube_thumbnail="https://i.ytimg.com/vi/edP4gaMO80E/maxresdefault.jpg"
comments = true
+++



---
Design an ATM machine that can handle deposits and withdrawals of five denominations: $20, $50, $100, $200, and $500. When withdrawing, the machine always tries to use the highest denominations available first. Implement methods to deposit money and withdraw specified amounts.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of operations performed on the ATM, including deposits and withdrawals.
- **Example:** `Input
["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
[[], [[1,2,3,0,1]], [250], [[0,1,0,1,2]], [570], [1000]]`
- **Constraints:**
	- banknotesCount.length == 5
	- 0 <= banknotesCount[i] <= 10^9
	- 1 <= amount <= 10^9
	- At most 5000 calls in total to withdraw and deposit.
	- Sum of banknotesCount[i] in all deposits doesn't exceed 10^9.

{{< dots >}}
### Output Specifications 📤
- **Output:** Output the result of each operation: null for deposits, an array of withdrawn banknotes for successful withdrawals, or [-1] if a withdrawal cannot be fulfilled.
- **Example:** `Output
[null, null, [0,0,2,0,0], null, [-1], [-1]]`
- **Constraints:**
	- For successful withdrawals, the output array must be of length 5 and reflect the denominations used in the order $20, $50, $100, $200, $500.
	- If a withdrawal cannot be fulfilled, output [-1].

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate the ATM operations while adhering to the constraints of prioritizing higher denominations for withdrawals.

- Initialize the ATM with five denominations and their counts set to 0.
- For deposits, update the count of each denomination.
- For withdrawals, calculate the maximum possible banknotes of each denomination that can be used while satisfying the total amount.
- If the amount cannot be withdrawn exactly, return [-1] without modifying the ATM's state.
{{< dots >}}
### Problem Assumptions ✅
- The ATM starts with no banknotes.
- Withdrawals are rejected if the exact amount cannot be formed.
- Deposits do not specify the order of operations; they directly add banknotes to the ATM.
{{< dots >}}
## Examples 🧩
- **Input:** `Input
["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
[[], [[1,1,0,0,1]], [300], [[0,0,2,1,0]], [750], [70]]`  \
  **Explanation:** 1. ATM is initialized. 2. Deposit adds $20 (1), $50 (1), and $500 (1). 3. Withdraw 300 uses $50 (1) and $500 (1). 4. Deposit adds $100 (2) and $200 (1). 5. Withdraw 750 fails as exact denominations are not available. 6. Withdraw 70 fails as $20 and $50 cannot fulfill the amount.

{{< dots >}}
## Approach 🚀
Use a greedy algorithm for withdrawals and maintain a dynamic count of banknotes for deposits.

### Initial Thoughts 💭
- The withdrawal process must prioritize larger denominations to minimize the number of notes used.
- Deposits are straightforward additions to the banknotes count.
- Edge cases include failed withdrawals when exact change cannot be made.
- A greedy approach works well for this problem since we prioritize larger denominations first.
{{< dots >}}
### Edge Cases 🌐
- Withdrawal amount is 0.
- Maximum banknotes or amounts near the upper limit of constraints.
- Withdrawal amount equals the value of one denomination.
- Withdrawal amount cannot be exactly fulfilled.
- Withdrawal fails if any single denomination required exceeds its count in the ATM.
{{< dots >}}
## Code 💻
```cpp
vector<long long> note;
ATM() {
    note.resize(5, 0);
}

void deposit(vector<int> cnt) {
    for(int i = 0; i < 5; i++)
        note[i] += cnt[i];
}

vector<int> withdraw(int amnt) {
    int cnt500 = 0, cnt200 = 0, cnt100 = 0, cnt50 = 0, cnt20 = 0;
    int taken = 0;
    if(amnt >= 500) {
        cnt500 = amnt / 500;
        
        if(cnt500 > note[4]) {
            cnt500 = note[4];
        }
        amnt -= (cnt500 * 500);
    }
    if(amnt >= 200) {
        cnt200 = amnt / 200;
        if(cnt200 > note[3]) {
            cnt200 = note[3];
        }
        amnt -= (cnt200 * 200);
    }
    if(amnt >= 100) {
        cnt100 = amnt / 100;
        if(cnt100 > note[2]) {
            cnt100 = note[2];                
        }
        amnt -= (cnt100 * 100);

    }
    if(amnt >= 50) {
        cnt50 = amnt / 50;
        if(cnt50 > note[1]) {
            cnt50 = note[1];                                
        }
        amnt -= (cnt50 * 50);
    }        
    if(amnt >= 20) {
        cnt20 = amnt / 20;
        if(cnt20 > note[0]) {
            cnt20 = note[0];                                
        }
        amnt -= (cnt20 * 20);
    }       
    if(amnt != 0) return vector<int>{-1};
    note[4] -= cnt500;
    note[3] -= cnt200;
    note[2] -= cnt100;
    note[1] -= cnt50;
    note[0] -= cnt20;

    return vector<int>{cnt20, cnt50, cnt100, cnt200, cnt500};
}
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
```

This is a solution for an ATM system where we handle deposit and withdrawal operations with 5 types of banknotes. The ATM class manages the banknote inventory, allowing the deposit and withdrawal of specific amounts. The `withdraw` function returns the number of banknotes dispensed for the requested withdrawal amount.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<long long> note;
	```
	This line declares a vector `note` to store the count of each denomination of banknotes in the ATM.

2. **Constructor**
	```cpp
	ATM() {
	```
	Constructor for the ATM class, initializing the `note` vector with 5 elements, all set to 0, representing the initial count of banknotes.

3. **Vector Operations**
	```cpp
	    note.resize(5, 0);
	```
	The `resize` function ensures that the `note` vector has 5 elements, each initialized to 0, which corresponds to the 5 types of banknotes.

4. **Deposit Method**
	```cpp
	void deposit(vector<int> cnt) {
	```
	The `deposit` function allows depositing banknotes into the ATM by taking an input vector `cnt` containing the number of banknotes of each type.

5. **Loop**
	```cpp
	    for(int i = 0; i < 5; i++)
	```
	A loop iterating through the 5 types of banknotes in the ATM.

6. **Vector Operations**
	```cpp
	        note[i] += cnt[i];
	```
	For each denomination, the number of banknotes deposited is added to the respective index in the `note` vector.

7. **Withdraw Method**
	```cpp
	vector<int> withdraw(int amnt) {
	```
	The `withdraw` function handles withdrawal requests by calculating how many banknotes of each denomination are needed to meet the requested amount.

8. **Variable Initialization**
	```cpp
	    int cnt500 = 0, cnt200 = 0, cnt100 = 0, cnt50 = 0, cnt20 = 0;
	```
	Initialization of counters for each denomination (500, 200, 100, 50, 20) of banknotes.

9. **Variable Initialization**
	```cpp
	    int taken = 0;
	```
	A variable `taken` is initialized to keep track of the total amount taken during the withdrawal process.

10. **Conditional Check**
	```cpp
	    if(amnt >= 500) {
	```
	Checks if the requested amount is greater than or equal to 500, the highest denomination.

11. **Mathematical Operations**
	```cpp
	        cnt500 = amnt / 500;
	```
	Calculates how many 500 denomination notes can be dispensed.

12. **Conditional Check**
	```cpp
	        if(cnt500 > note[4]) {
	```
	Checks if the available number of 500 denomination notes is sufficient to fulfill the request.

13. **Variable Assignment**
	```cpp
	            cnt500 = note[4];
	```
	Sets the count of 500 denomination notes to the available number in the ATM.

14. **Mathematical Operations**
	```cpp
	        amnt -= (cnt500 * 500);
	```
	Deducts the withdrawn amount from the total requested amount.

15. **End of Method**
	```cpp
	    return vector<int>{cnt20, cnt50, cnt100, cnt200, cnt500};
	```
	If the withdrawal is successful, the function returns the number of each denomination dispensed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for deposit; O(1) for withdrawal with sufficient notes.
- **Average Case:** O(5) for both operations due to the fixed denominations.
- **Worst Case:** O(5) for withdrawal when denominations need to be checked sequentially.

Both operations are efficient as they involve a constant number of denominations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1) since only a fixed array of length 5 is used.

Space usage is minimal as only an array of size 5 is maintained for denominations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-an-atm-machine/description/)

---
{{< youtube edP4gaMO80E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
