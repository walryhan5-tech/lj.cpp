#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    string S;
    cin >> S;

    vector<int> total(26, 0);
    for (char c : S) {
        total[c - 'a']++;
    }

    vector<int> seen(26, 0);
    string result = "";

    for (char c : S) {
        int idx = c - 'a';
        seen[idx]++;
        if (total[idx] >= K && seen[idx] > total[idx] - K) {
            result += c;
        }
    }

    cout << result << "\n";

    return 0;
}
