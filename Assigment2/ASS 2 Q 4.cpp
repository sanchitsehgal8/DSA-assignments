#include<iostream>
using namespace std;

void concatenate() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    
    int i = 0, j = 0;
    while(str1[i] != '\0') {
        i++;
    }
    while(str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    
    cout << "Concatenated string: " << str1 << endl;
}

void reverseString() {
    char str[100];
    cout << "Enter string: ";
    cin >> str;
    
    int len = 0;
    while(str[len] != '\0') {
        len++;
    }
    
    for(int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
    
    cout << "Reversed string: " << str << endl;
}

void deleteVowels() {
    char str[100];
    cout << "Enter string: ";
    cin >> str;
    
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
           str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    
    cout << "String after removing vowels: " << str << endl;
}

void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    
    char strings[n][100];
    cout << "Enter strings:\n";
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            int k = 0;
            while(strings[j][k] != '\0' && strings[j+1][k] != '\0') {
                if(strings[j][k] > strings[j+1][k]) {
                    char temp[100];
                    int t = 0;
                    while(strings[j][t] != '\0') {
                        temp[t] = strings[j][t];
                        t++;
                    }
                    temp[t] = '\0';
                    
                    t = 0;
                    while(strings[j+1][t] != '\0') {
                        strings[j][t] = strings[j+1][t];
                        t++;
                    }
                    strings[j][t] = '\0';
                    
                    t = 0;
                    while(temp[t] != '\0') {
                        strings[j+1][t] = temp[t];
                        t++;
                    }
                    strings[j+1][t] = '\0';
                    break;
                }
                else if(strings[j][k] < strings[j+1][k]) {
                    break;
                }
                k++;
            }
        }
    }
    
    cout << "Sorted strings:\n";
    for(int i = 0; i < n; i++) {
        cout << strings[i] << endl;
    }
}

void uppercaseToLowercase() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    
    if(ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
    }
    
    cout << "Lowercase: " << ch << endl;
}

int main() {
    int choice;
    
    while(1) {
        cout << "\n1. Concatenate strings\n";
        cout << "2. Reverse string\n";
        cout << "3. Delete vowels\n";
        cout << "4. Sort strings\n";
        cout << "5. Uppercase to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 1) {
            concatenate();
        }
        else if(choice == 2) {
            reverseString();
        }
        else if(choice == 3) {
            deleteVowels();
        }
        else if(choice == 4) {
            sortStrings();
        }
        else if(choice == 5) {
            uppercaseToLowercase();
        }
        else if(choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    return 0;
}