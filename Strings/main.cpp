//
//  main.cpp
//  Strings
//
//  Created by Felipe Vallejo on 26/7/21.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

void stringLength(char* string){
    int i;
    
    for (i = 0; string[i] != '\0'; i++){}
    
    cout << "Length is " << i - 1 << endl;
}

void upperToLower(char* string){
    int i;
    
    for (i = 0; string[i] != '\0'; i++)
        string[i] += 32;
    
    printf("%s\n", string);
    
}

void caseToggle(char* string){
    int i;
    
    for (i = 0; string[i] != '\0'; i++)
        if (string[i] > 65 && string[i] < 90)
            string[i] += 32;
        else if (string[i] >= 97 && string[i] <= 122)
            string[i] -= 32;
    
    printf("%s\n", string);
}

void vowelCount(char* string){
    int i, vcount {0};
    
    for (i = 0; string[i] != '\0'; i++)
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
            vcount++;
    printf("The number of vowels we have is %d\n", vcount);
}

void wordCount(char* string){
    int i, word {1};
    
    for (i = 0; string[i] != '\0'; i++)
        if (string[i] == ' ' && string[i - 1] != ' ')
            word++;
    
    printf("The number of words inside the string is %d\n", word);
}

bool stringValidation(char* string){
    int i;
    
    for (i = 0; string[i] != '\0'; i++)
        if (!(string[i] > 65 && string[i] < 90)
            && !(string[i] > 97 && string[i] < 122)
            && !(string[i] > 48 && string[i] < 57))
            return false;
    return true;
}

void reverse(char* A){
    
    char B;
    int i, j;
    
    for (j = 0; A[j] != '\0'; j++){}
    
    j -= 1;
    
    for (i = 0; i < j; i++, j--){
        B = A[i];
        A[i] = A[j];
        A[j] = B;
    }
    
    printf("%s\n", A);
    
}

void compare(char* A, char* B){
    int i, j;
    
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
        if (A[i] != B[j])
            break;
    
    if (A[i] == B[j])
        cout << "Equal" << endl;
    else
        cout << "Not equal" << endl;
    
}

void palindrome(char* A){
    char* B;
    int i, j;
    
    for (j = 0; A[j] != '\0'; j++){}
    
    j -= 1;
    
    B = new char[j + 1];
    
    for (i = 0; j >= 0; i++, j--)
        B[i] = A[j];
    
    B[i] = '\0';
    
    for (i = 0; A[i] != '\0' && B[j] != '\0'; i++)
        if (A[i] != B[j])
            break;
    
    if (A[i] != B[i])
        cout << "Not a palindrome word" << endl;
    else
        cout << "A palindrome word" << endl;
}

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
