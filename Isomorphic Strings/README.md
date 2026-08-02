# 🔤 Isomorphic Strings

## 📌 Problem Statement

Given two strings `s` and `t`, determine whether they are **isomorphic**.

Two strings are **isomorphic** if:

- Every character in `s` maps to exactly one character in `t`.
- No two different characters in `s` map to the same character in `t`.
- The order of characters must remain the same.

If the mapping is valid, return `true`; otherwise, return `false`.

---

# 📝 Example 1

### Input

```text
s = "egg"
t = "add"
```

### Output

```text
true
```

### Explanation

```
e → a
g → d
```

The mapping is consistent.

---

# 📝 Example 2

### Input

```text
s = "foo"
t = "bar"
```

### Output

```text
false
```

### Explanation

```
f → b
o → a
o → r
```

The same character (`o`) maps to two different characters (`a` and `r`), which is not allowed.

---

# 📝 Example 3

### Input

```text
s = "paper"
t = "title"
```

### Output

```text
true
```

### Explanation

```
p → t
a → i
e → l
r → e
```

The mapping remains consistent throughout the strings.

---

# 💡 Intuition

Instead of storing the character mapping directly using a map, we store the **last position** where each character appeared.

If two strings are isomorphic, then the current characters in both strings should always have appeared at the **same previous position**.

To achieve this, we use two arrays:

- `arr1` stores the last occurrence of characters in string `s`.
- `arr2` stores the last occurrence of characters in string `t`.

---

# ✅ C++ Solution

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int arr1[256] = {0};
        int arr2[256] = {0};

        int n = s.size();

        for(int i = 0; i < n; i++) {

            if(arr1[s[i]] != arr2[t[i]])
                return false;

            arr1[s[i]] = i + 1;
            arr2[t[i]] = i + 1;
        }

        return true;
    }
};
```

---

# 🔍 Step-by-Step Explanation

## Step 1: Create Two Arrays

```cpp
int arr1[256] = {0};
int arr2[256] = {0};
```

### Why?

- `arr1` stores the last seen position of characters from `s`.
- `arr2` stores the last seen position of characters from `t`.

Initially, every value is `0`.

```
arr1

a → 0
b → 0
c → 0
...

arr2

a → 0
b → 0
c → 0
...
```

`0` means the character has **not appeared yet**.

---

## Step 2: Traverse Both Strings

```cpp
for(int i = 0; i < n; i++)
```

Move through both strings together.

```
s : e g g
    ↑

t : a d d
    ↑
```

---

## Step 3: Compare Previous Positions

```cpp
if(arr1[s[i]] != arr2[t[i]])
    return false;
```

If the previous occurrence positions are different, the mapping is invalid.

---

## Step 4: Update the Position

```cpp
arr1[s[i]] = i + 1;
arr2[t[i]] = i + 1;
```

Store the current position.

We use `i + 1` instead of `i`.

### Why `i + 1`?

If we stored `i`, then the first character would be stored at index `0`, which is the same value used to represent **not seen**.

Using `i + 1` avoids this conflict.

Example

```
Index = 0

Store = 1
```

Meaning

```
0 = Not Seen

1 = Seen at Index 0

2 = Seen at Index 1

3 = Seen at Index 2
```

---

# 📊 Dry Run

## Input

```text
s = "egg"
t = "add"
```

Initially

```
arr1 = all 0
arr2 = all 0
```

---

### Iteration 1

```
i = 0

s = e

t = a
```

Compare

```
arr1[e] = 0

arr2[a] = 0
```

Equal ✔

Update

```
arr1[e] = 1

arr2[a] = 1
```

Diagram

```
e → 1

a → 1
```

---

### Iteration 2

```
i = 1

s = g

t = d
```

Compare

```
arr1[g] = 0

arr2[d] = 0
```

Equal ✔

Update

```
arr1[g] = 2

arr2[d] = 2
```

Diagram

```
arr1

e → 1
g → 2

----------------

arr2

a → 1
d → 2
```

---

### Iteration 3

```
i = 2

s = g

t = d
```

Compare

```
arr1[g] = 2

arr2[d] = 2
```

Equal ✔

Update

```
arr1[g] = 3

arr2[d] = 3
```

Diagram

```
arr1

e → 1
g → 3

----------------

arr2

a → 1
d → 3
```

Loop ends.

Return

```text
true
```

---

# 📊 Dry Run Table

| i | s[i] | t[i] | arr1 Value | arr2 Value | Result |
|---|------|------|------------|------------|--------|
| 0 | e | a | 0 | 0 | ✔ Match |
| 1 | g | d | 0 | 0 | ✔ Match |
| 2 | g | d | 2 | 2 | ✔ Match |

Output

```text
true
```

---

# 🎯 Example 2

### Input

```text
s = "foo"

t = "bar"
```

### Iteration 1

```
f → b
```

Store

```
f → 1

b → 1
```

---

### Iteration 2

```
o → a
```

Store

```
o → 2

a → 2
```

---

### Iteration 3

```
o

r
```

Compare

```
arr1[o] = 2

arr2[r] = 0
```

They are different.

Return

```text
false
```

Diagram

```
foo

bar

↓

f ↔ b ✔

↓

o ↔ a ✔

↓

o ↔ r ✘

Return false
```

---

# 🌟 Visual Flow Diagram

```
Input

s = "egg"

t = "add"

        │
        ▼

Create Two Arrays

arr1

arr2

        │
        ▼

Traverse Both Strings

        │
        ▼

Compare Previous Positions

arr1[s[i]]

==

arr2[t[i]]

        │
        ▼

Same?

├── No → Return false

└── Yes

        │
        ▼

Update Both Arrays

arr1[s[i]] = i + 1

arr2[t[i]] = i + 1

        │
        ▼

Repeat Until End

        │
        ▼

Return true
```

---

# 🤔 Why Does This Work?

Consider

```
s = "paper"

t = "title"
```

Previous occurrence table:

| Index | s | Previous Position | t | Previous Position |
|------:|---|-------------------|---|-------------------|
| 0 | p | 0 | t | 0 |
| 1 | a | 0 | i | 0 |
| 2 | p | 1 | t | 1 |
| 3 | e | 0 | l | 0 |
| 4 | r | 0 | e | 0 |

The previous positions always match, so the strings are isomorphic.

---

# ⏱ Time Complexity

We traverse the strings only once.

```text
O(n)
```

---

# 💾 Space Complexity

We use two arrays of fixed size `256`.

```text
O(1)
```

because the array size is constant and does not depend on the input size.

---

# ✅ Key Points

- Use two arrays of size `256` to store the last seen position of each character.
- Compare previous occurrence positions instead of storing character mappings.
- Use `i + 1` to distinguish between **not seen (`0`)** and **seen at index `0` (`1`)**.
- If the previous positions don't match, return `false`.
- If all positions match, return `true`.

---

# 📌 Summary

✔ Traverse both strings together.

✔ Compare the last seen positions of the current characters.

✔ Update both arrays with `i + 1`.

✔ Return `false` on the first mismatch.

✔ Return `true` if the entire traversal completes.

### Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`
