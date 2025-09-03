#include <iostream>
#include <string>
#include <algorithm> // for sort, transform
using namespace std;

// (a) Concatenate strings
void concatenateStrings() {
    string s1 = "Hello";
    string s2 = " World!";
    string result = s1 + s2;
    cout << "(a) Concatenated String: " << result << endl;
}

// (b) Reverse a string
void reverseString() {
    string str = "OpenAI";
    reverse(str.begin(), str.end());
    cout << "(b) Reversed String: " << str << endl;
}

// (c) Delete vowels from a string
void deleteVowels() {
    string str = "Programming is fun";
    string result = "";
    for (char c : str) {
        char lower = tolower(c);
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
            result += c;
        }
    }
    cout << "(c) String without vowels: " << result << endl;
}

// (d) Sort strings alphabetically
void sortStrings() {
    string arr[] = {"banana", "apple", "cherry", "mango", "grape"};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    cout << "(d) Sorted Strings: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// (e) Convert uppercase to lowercase
void convertToLowercase() {
    string str = "HELLO WORLD";
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "(e) Lowercase String: " << str << endl;
}

int main() {
    concatenateStrings();
    reverseString();
    deleteVowels();
    sortStrings();
    convertToLowercase();

    return 0;
}
