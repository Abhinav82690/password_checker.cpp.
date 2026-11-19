
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string password;
    int score = 0;

    cout << "===== PASSWORD STRENGTH CHECKER =====\n";
    cout << "Enter your sample password: ";
    getline(cin, password);

    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool special = false;

    for (char ch : password) {
        if (isupper((unsigned char)ch))
            upper = true;
        else if (islower((unsigned char)ch))
            lower = true;
        else if (isdigit((unsigned char)ch))
            digit = true;
        else
            special = true;
    }

    if (password.length() >= 8)
        score++;

    if (password.length() >= 12)
        score++;

    if (upper) score++;
    if (lower) score++;
    if (digit) score++;
    if (special) score++;

    cout << "\nPassword Analysis:\n";
    cout << "Length: " << password.length() << "\n";
    cout << "Uppercase: " << (upper ? "Yes" : "No") << "\n";
    cout << "Lowercase: " << (lower ? "Yes" : "No") << "\n";
    cout << "Numbers: " << (digit ? "Yes" : "No") << "\n";
    cout << "Special Characters: "
         << (special ? "Yes" : "No") << "\n";

    cout << "\nPassword Strength: ";

    if (score <= 2)
        cout << "WEAK";
    else if (score <= 4)
        cout << "MEDIUM";
    else
        cout << "STRONG";

    cout << "\n\nThank you for using the checker!\n";

    return 0;
}

