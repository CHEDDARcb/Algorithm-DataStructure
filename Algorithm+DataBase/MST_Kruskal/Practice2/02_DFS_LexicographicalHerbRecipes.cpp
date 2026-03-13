#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cin >> input;

    sort(input.begin(), input.end());
    input.erase(unique(input.begin(), input.end()), input.end());

    for (int i = 0; i < input.length(); i++) {
        for (int j = 0; j < input.length(); j++) {
            for (int k = 0; k < input.length(); k++) {
                cout << input[i] << input[j] << input[k] << "\n";
            }
        }
    }

    return 0;
}