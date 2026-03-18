# 🏛️ Roman Numerals ➜ Integer

> ✨ Convert a Roman numeral string into its integer value using an efficient one-pass approach.

---

## 🧩 Problem Statement

Roman numerals are represented using **7 symbols**:

| Symbol | Value |
| ------ | ----- |
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

---

## 📜 Rules of Roman Numbers

### ✅ Normal Rule (Addition)

* Symbols are written **from largest to smallest**
* Values are **added**

📌 Example:

```text
XII = 10 + 1 + 1 = 12
```

---

### ⚡ Special Rule (Subtraction)

When a **smaller value appears before a larger value**, we subtract:

| Pattern | Value |
| ------- | ----- |
| IV      | 4     |
| IX      | 9     |
| XL      | 40    |
| XC      | 90    |
| CD      | 400   |
| CM      | 900   |

📌 Example:

```text
IV = 5 - 1 = 4
```

---

## 🧪 Examples

### 🔹 Example 1

```text
Input:  s = "LVIII"
Output: 58
```

💡 Breakdown:

```
L = 50, V = 5, III = 3
👉 Total = 58
```

---

### 🔹 Example 2

```text
Input:  s = "MCMXCIV"
Output: 1994
```

💡 Breakdown:

```
M  = 1000
CM = 900
XC = 90
IV = 4
👉 Total = 1994
```

---

## 🚀 Approach

### 💡 Core Idea

Instead of handling all special cases manually:

> 👉 Compare each character with the **next one**

---

### 🧠 Logic

* If `current < next` → ❌ subtract
* Else → ➕ add

---

## 🪜 Step-by-Step Algorithm

1. Create a map of Roman → Integer values
2. Initialize `result = 0`
3. Traverse string from left to right:

   * Compare current with next
   * Apply add/subtract rule
4. Add the last character
5. Return result

---

## 🔍 Dry Run (Visual)

### Input:

```text
MCMXCIV
```

| Step | Current | Next    | Operation | Result |
| ---- | ------- | ------- | --------- | ------ |
| 1    | M(1000) | C(100)  | Add       | 1000   |
| 2    | C(100)  | M(1000) | Subtract  | 900    |
| 3    | M(1000) | X(10)   | Add       | 1900   |
| 4    | X(10)   | C(100)  | Subtract  | 1890   |
| 5    | C(100)  | I(1)    | Add       | 1990   |
| 6    | I(1)    | V(5)    | Subtract  | 1989   |

➕ Add last character (V = 5)
✅ Final Answer = **1994**

---

## 💻 C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }

        return res + roman[s.back()];
    }
};

int main() {
    Solution sol;
    string s = "MCMXCIV";

    cout << "Integer value: " 
         << sol.romanToInt(s);

    return 0;
}
```

---

## ⏱️ Complexity

| Type     | Complexity |
| -------- | ---------- |
| 🕒 Time  | O(n)       |
| 💾 Space | O(1)       |

---

## 🎯 Key Takeaways

✨ Compare **current vs next**
✨ Subtract when smaller comes first
✨ Add otherwise
✨ Handle last character separately

---

## 🏁 Final Thought

> 💡 “Roman numerals look complex, but a simple comparison trick solves everything!”

🚀 Clean • Efficient • Interview Ready

---
