# 4 - Strings

### What are strings?

In order to understand the true meaning of strings, we should split its concept into 4 sections

1. **Character Set or ASCII Codes**
    - Remember that a computer system works on a binary number system i.e. everything in computers is numbers.
    - Computers support characters by making every character be defined by some numeric value.
    - So in conclusion for every character, there are some codes defined.
    - Every electronic machine follows those codes called the **American Standard Code for Information Interchange**.
    - These codes are given by the ANSI and ISO.
    - To check the codes for each letter in the alphabet visit [ASCII Character Table](http://sticksandstones.kstrom.com/appen.html).
    - There are ASCII Codes for letters, numbers, symbols, and keys. ASCII Codes range from 0 - 127.
2. **Character**

```cpp
char temp;
 // This is fine:
temp = 'A';
// These are not fine:
temp = 'AB';
temp = A;
temp = "A";
```

Graphically this would look like this:

![Untitled](4%20-%20String%20d846e/Untitled.png)

- Inside memory, the value 65 is stored.

```cpp
char temp;
// This is fine:
temp = 'A';
// To access the character:
printf("%c\n", temp);
// To access the ASCII code:
printf("%d\n", temp);

» A
65
```

1. **Character Array**

```cpp
// We can initialize an array of characters by:
// Providing size
char X[5] = {'A', 'B', 'C', 'D', 'E'};
// Not providing size
char X[] = {'A', 'B', 'C', 'D', 'E'};
// Providing the ASCII code
char X[5] = {65, 66, 67, 68, 69, 70};
```

1. **Strings**
- An array of characters are strings.
- For store names, words, sentences, or paragraphs we need strings.
- If a string size is 4, and the array size is 10; we must know where the string ends by adding null i.e. \0 for marking the end of the string aka **String Delimiter, End of string char, Null char, or String terminator**.
- The size of a string is known in C++ by its string delimiter, but in java by its length.

```cpp
char name[10] = {'F', 'E', 'L', 'I', 'P', 'E', '\0'};
// %s is used for displaying strings:
printf("%s\n", name);

» FELIPE
```

1. **Creating a string**

There are multiple methods of creating strings:

```cpp
char name[10] = {'F', 'E', 'L', 'I', 'P', 'E', '\0'};
/ This also works:
char name[] = {'F', 'E', 'L', 'I', 'P', 'E', '\0'};
// The compiler automatically create an array:
char name[] = "john";
// This will live inside heap:
char *name = "john";
```

To scan a single word until we hit the enter key we can use:

```cpp
scanf("%s\n", name);
```

To scan a string containing spaces until we hit enter we use:

```cpp
gets(name);
```

### **String Operations**

**Finding the length of a string**

- For solving this problem we should know that we can find the length of the string by finding \0.
- We can place i in index 0 and increment until we find \0.

```cpp
void stringLength(char *A){
    int i;
    for (i = 0; A[i] != '\0'; i++){}
    cout << "Length is " << i - 1 << endl;
}

int main() {
    char* A = "welcome";
    stringLength(A);
    return 0;
}

» Length is 6
```

**Changing case of a string**

- This problem consists of changing the case from lower case to upper case or opposite of the characters of a string.
- Let’s take a moment to briefly remember the ASCII codes for alphabet letters.
- Acknowledge that the difference between uppercase and lowercase is 32 (e.g. A - 65, a - 97; 97 - 64 = 32).

```cpp
void upperToLower(char* A){
    int i;
    for (i = 0; A[i] != '\0'; i++)
        A[i] += 32;
    printf("%s\n", A);
}

int main() {
    char A[] = "WELCOME";
    upperToLower(A);
    return 0;
}

» welcome
```

**Toggle the cases**

- Toggle the case means if it is a lower case we change it to upper case and so on.

```cpp
void caseToggle(char *A){
    int i;
    for (i = 0; A[i] != '\0'; i++)
        if (A[i] > 65 && A[i] < 90)
            A[i] += 32;
        else if (A[i] >= 97 && A[i] <= 122)
            A[i] -= 32;
    printf("%s\n", A);
}

int main() {
    char A[] = "weLCOme";
    caseToggle(A);
    return 0;
}

» WElcoME
```

**Counting vowels in a string**

- We should write a function that can count vowels no matter what case the vowels are.

```cpp
void vowelCount(char *A){
    int i, vcount {0};
    for (i = 0; A[i] != '\0'; i++)
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
            vcount++;
    printf("The number of vowels we have is %d\n", vcount);
}

int main() {
    char A[] = "How are you";
    vowelCount(A);
    return 0;
}

» The number of vowels we have is 5
```

**Count words in a string**

- Spaces will help us identify words.

```cpp
void wordCount(char *A){
    int i, word {1};
    for (i = 0; A[i] != '\0'; i++)
        if (A[i] == ' ' && A[i - 1] != ' ')
            word++;
    printf("The number of words inside the string is %d\n", word);
}

int main() {
    char A[] = "How are you";
    wordCount(A);
    return 0;
}

» The number of words inside the string is 3
```

**Validating a string**

- Validating a string is seen when a system is trying to validate a password or not.
- A valid password may include only characters, numbers, or no special characters allowed.

```cpp
bool stringValidation(char *A){
    int i;
    for (i = 0; A[i] != '\0'; i++)
        if (!(A[i] > 65 && A[i] < 90)
            && !(A[i] > 97 && A[i] < 122)
            && !(A[i] > 48 && A[i] < 57))
            return false;
    return true;
}

int main() {
    char A[] = "Guangzhou1!";
    cout << stringValidation(A) << endl;
    return 0;
}

» False
```

**Reverse a string**

- For reversing a string we can use the same array.
- Acknowledge that the strings that live inside the heap cannot be modified, only strings that live in the stack are mutable.

```cpp
void reverse(char *A){
    char t;
    int i = 0, j;
    for (j = 0; A[j] != '\0'; j++){}
    j -= 1;
    for (i = 0; i < j; i++, j--){
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    printf("%s\n", A);
}

int main() {
    char A[] = "python";
    reverse(A);
    return 0;
}

» nohtyp
```

**Compare strings**

- For comparing two strings we should scan through all the elements in the string.
- If any letter at equal locations doesn’t match, then the two strings are not the same, also we can tell which letter comes first by comparing the ASCII code.
- We must place two variables at index 0 of both strings, if the element in both strings at the same index is equal then i++, and j++.
- Once the first loop has terminated we run a second loop that prints if it is equal or not.
- With regards to the casing, we can write an extra function to change the cases of the strings so that both match.

```cpp
void compare(char *A, char *B){
    int i, j;
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
        if (A[i] != B[j])
            break;
    
    if (A[i] == B[j])
        cout << "Equal" << endl;
    else
        cout << "Not equal" << endl;   
}

int main() {
    char A[] = "C";
    char B[] = "C++";
    compare(A, B);
    return 0;
}

» Not equal
```

**Checking Palindrome**

- A string is said to be a palindrome if we reverse it and it remains the same.
- The procedure includes, compare if variable i and j’s elements are the same or not; we should place i in the beginning and j at the end of the string. If equal then i++ and j-- and stop until both variables meet.
- So two steps; reverse and compare.

```cpp
void palindrome(char* A){
    char* B;
    int i, j;
    
    for (j = 0; A[j] != '\0'; j++){}
    
    j -= 1;
    
    for (i = 0; i < j; i++, j--){
        B = &A[i];
        A[i] = A[j];
        A[j] = *B;
    }
    
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j--)
        if (A[i] != B[j])
            break;
    
    if (A[i] == B[i])
        cout << "Not a palindrome word" << endl;
    else
        cout << "A palindrome word" << endl;
}

int main() {
    char A[] = "madam";
    
    palindrome(A);
    
    return 0;
}

» A palindrome word
```

### **Finding Duplicates in a string**

**Hash table**

- We should annotate the ASCII codes of each element in the string.
- The size of the H array should be from 97 to the largest ASCII code in the string. An array of size 25 is sufficient because if it starts from 0 upwards will be too lengthy.

```cpp
void duplicateH(char* A){
    int H[26] {0};
    
    for (int i = 0; A[i] != '\0'; i++)
        H[A[i] - 97]++;

    for (int i = 0; i < 26; i++)
        if (H[i] > 1){
            printf("The letter %c", i + 97);
            printf(" got repeated %d times\n", H[i]);
        }
}

int main() {
    char A[] = "finding";
    duplicateH(A);
    return 0;
}

» The letter i got repeated 2 times
The letter n got repeated 2 times
```

**Using Bitwise Operations**

- To perform Bitwise Operations we must know 3 of the primary operations:
    1. Left shift
        
        ![Untitled](4%20-%20String%20d846e/Untitled%201.png)
        
        1. Let’s imagine we have an array of 8 indexes i.e. one-byte array.
        2. The left side is for the most significant bit and the right side is for the least significant bit.
        3. The binary value of numbers can be solved by looking at the base numbers of the array. Visit [Binary Number List](https://www.javatpoint.com/binary-numbers-list)
        4. By left shift operation, we mean shifting the bits by the specified number. (e.g. if we have H = 1 the array will look like 00000001, but when we type H = H << 1, then the array will be 00000010 or if we type H = H << 2, the array will be 000000100)
    
    2.   Bits ORing (Merging)
    
    1. The rule of OR is 1 | 1 = 1, 1 | 0 = 1, 0 | 1 = 1, 0 | 0 = 0.
    2. As an example let’s take 10 and 6, in binary 1010 and 0110 the result of AND operation in both will be 1110 which is 14.
    3. Merging means concatenating both arrays into a single array.
    
    3.   Bits ANDing (Masking)
    
    1. The rule of AND is 1 & 1 = 1, 1 & 0 = 0, 0 & 1 = 0, 0 & 0 = 0.
    2. As an example let’s take 10 and 6, in binary 1010 and 0110 the result of AND operation in both will be 0010 which is 2.
    3. By masking means return bool value if two arrays are the same or not in a binary perspective.

```cpp
void duplicateB(char* A){
    long int H {0}, X {0};
    
    for (int i = 0; A[i] != '\0'; i++){
        X = 1;
        X = X << (A[i] - 97);
        
        if ((X & H) > 0){
            printf("%c got duplicated\n", A[i]);
        } else {
            H = X | H;
        }
    }
}

int main() {
    char A[] = "finding";
    
    duplicateB(A);
    
    return 0;
}

» i got duplicated
n got duplicated
```

### **Checking if two strings are an anagram**

- Anagrams are two strings that are formed the same set of alphabets i.e. rearranging both will form the same two words, for example, medical and decimal are anagram words.
- The procedure would consist of; checking if both strings share the same size, use a hash table to keep track of the letters, where we add when checking on the first string, and subtract on the second string so the hash table remains with 0s. If we get a -1 on H then it is not an anagram.

```cpp
void anagram(char* A, char* B){
    int H[26] {0};
    int i;

    for (i = 0; A[i] != '\0'; i++)
        H[A[i] - 97]++;
    
    for (i = 0; B[i] != '\0'; i++)
        H[B[i] - 97]--;
    
    for (i = 0; i < 26; i++)
        if (H[i] < 0){
            cout << "Not anagram\n";
            return;
        } else {
            cout << "Anagram\n";
            return;
        }   
}

int main() {
    char A[] = "decimal";
    char B[] = "medical";
    anagram(A, B);
    return 0;
}

» Anagram
```

### **Permutation of a string**

- A permutation is a technique that determines the number of possible arrangements in a set, in this case, a string.
- For example, if we have ABC then the permutation of ABC will be **ACB, BAC, BCA, CAB, CBA**.

![Untitled](4%20-%20String%20d846e/Untitled%202.png)

- We can solve this algorithm with the help of backtracking.

```cpp
void perm(char *S, int k){
    static int A[10] {0};
    static char Res[10];
    int i;
    
    if (S[k] == '\0'){
        printf("%s\n", Res);
    } else {
        for (i = 0; S[i] != '\0'; i++){
            if (A[i] == 0){
                Res[k] = S[i];
                A[i] = 1;
                perm(S, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main() {
    char S[] = "ABC";
    perm(S, 0);
    return 0;
}

» ABC ACB BAC BCA CAB CBA
```