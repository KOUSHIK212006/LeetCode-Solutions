# Valid Anagram — Java HashMap Solution

## Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`. Otherwise, return `false`.

An anagram contains the same characters with the same frequencies, but the order of the characters can be different.

### Example

```text
Input:

s = "anagram"
t = "nagaram"

Output:

true
```

---

## Approach: HashMap Frequency Counting

We use a `HashMap` to store the frequency of every character in the first string.

```java
HashMap<Character, Integer> map = new HashMap<>();
```

The structure of the HashMap is:

```text
Character → Frequency
```

For example:

```text
a → 3
n → 1
g → 1
r → 1
m → 1
```

---

## Step 1: Check the Lengths

```java
if (s.length() != t.length()) {
    return false;
}
```

Two strings cannot be anagrams if they have different lengths.

For example:

```text
s = "cat"
t = "cats"
```

Since their lengths are different, we immediately return `false`.

---

## Step 2: Create the HashMap

```java
HashMap<Character, Integer> map = new HashMap<>();
```

The HashMap stores:

```text
Key   → Character
Value → Frequency
```

---

## Step 3: Count Characters in the First String

```java
for (int i = 0; i < s.length(); i++) {
    char ch = s.charAt(i);

    map.put(ch, map.getOrDefault(ch, 0) + 1);
}
```

The loop goes through every character of `s`.

For:

```text
s = "anagram"
```

The HashMap becomes:

```text
a → 3
n → 1
g → 1
r → 1
m → 1
```

### Understanding This Line

```java
map.put(ch, map.getOrDefault(ch, 0) + 1);
```

`getOrDefault(ch, 0)` gets the current frequency of the character.

If the character does not exist in the HashMap, it returns `0`.

Then we add `1` and store the updated frequency using `put()`.

The logic is:

```text
Get current frequency
        ↓
Character doesn't exist? Use 0
        ↓
Add 1
        ↓
Store updated frequency
```

---

## Step 4: Subtract Characters Using the Second String

```java
for (int i = 0; i < t.length(); i++) {
    char ch = t.charAt(i);

    map.put(ch, map.getOrDefault(ch, 0) - 1);

    if (map.get(ch) < 0) {
        return false;
    }
}
```

The second loop goes through every character of `t`.

Instead of adding `1`, we subtract `1`.

The first string adds characters to the HashMap:

```text
+1
```

The second string removes matching characters:

```text
-1
```

For example:

```text
s = "anagram"
t = "nagaram"
```

After processing `s`:

```text
a → 3
n → 1
g → 1
r → 1
m → 1
```

Now process `t`:

```text
Character    Frequency Change

n            1 → 0
a            3 → 2
g            1 → 0
a            2 → 1
r            1 → 0
a            1 → 0
m            1 → 0
```

Final HashMap:

```text
a → 0
n → 0
g → 0
r → 0
m → 0
```

Every character has been perfectly matched.

Therefore, the strings are anagrams.

---

## Why Check for Negative Frequency?

```java
if (map.get(ch) < 0) {
    return false;
}
```

Suppose:

```text
s = "rat"
t = "car"
```

After processing `s`:

```text
r → 1
a → 1
t → 1
```

The first character of `t` is:

```text
c
```

But `c` does not exist in the HashMap.

Therefore:

```java
map.getOrDefault('c', 0)
```

returns:

```text
0
```

We subtract `1`:

```text
0 - 1 = -1
```

Now:

```text
c → -1
```

Since the frequency is negative:

```java
if (map.get(ch) < 0)
```

returns `true`, so we return:

```java
false
```

A negative frequency means that `t` contains a character more times than `s` does.

---

## Complete Java Solution

```java
import java.util.HashMap;

class Solution {

    public boolean isAnagram(String s, String t) {

        if (s.length() != t.length()) {
            return false;
        }

        HashMap<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);

            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        for (int i = 0; i < t.length(); i++) {

            char ch = t.charAt(i);

            map.put(ch, map.getOrDefault(ch, 0) - 1);

            if (map.get(ch) < 0) {
                return false;
            }
        }

        return true;
    }
}
```

---

## Mental Model

```text
First String (s)
        ↓
Count every character
        ↓
Add +1 to HashMap


Second String (t)
        ↓
Match every character
        ↓
Subtract -1 from HashMap


Does any frequency become negative?
        ↓
YES                     NO
 ↓                       ↓
return false          Continue


Loop finishes successfully
        ↓
return true
```

## Simple Way to Remember the Logic

Think of the HashMap as a bank account.

The first string deposits characters:

```text
+1
```

The second string withdraws characters:

```text
-1
```

If the balance becomes negative, the second string is trying to use a character that the first string did not have enough of.

Therefore:

```text
Negative balance → Not an Anagram
No negative balance → Valid Anagram
```

---

## Time Complexity

The first loop processes `s` once.

The second loop processes `t` once.

Therefore:

```text
O(n) + O(n) = O(n)
```

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(k)
```

where `k` is the number of unique characters stored in the HashMap.

---

## Key HashMap Pattern Learned

### Increase Frequency

```java
map.put(ch, map.getOrDefault(ch, 0) + 1);
```

### Decrease Frequency

```java
map.put(ch, map.getOrDefault(ch, 0) - 1);
```

### Check Whether a Character Was Overused

```java
if (map.get(ch) < 0) {
    return false;
}
```

The main pattern learned from this problem is **frequency counting using a HashMap**.
