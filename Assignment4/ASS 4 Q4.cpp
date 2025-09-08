#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

/*
   Function to print the first non-repeating character
   after reading each character from the input string.
*/
void firstNonRepeating(string str) {
    queue<char> q;                  // to maintain character order
    unordered_map<char, int> freq;  // to count character frequency

    cout << "\nStep-wise Output: ";
    for (char ch : str) {
        // Skip spaces so that input like "a a b" works correctly
        if (ch == ' ') continue;

        // Increase frequency count for this character
        freq[ch]++;

        // Add this character into the queue
        q.push(ch);

        // Remove characters from queue front if they are repeating
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // Print the first non-repeating char, or -1 if none exists
        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;

    cout << "====== First Non-Repeating Character Program ======\n";
    cout << "Enter a string (with spaces between chars if needed): ";
    getline(cin, input);

    cout << "You entered: " << input << endl;
    firstNonRepeating(input);

    return 0;
}

