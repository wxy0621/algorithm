#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <stack>
#include <math.h>

using namespace std;

bool cmp(string& v1, string& v2) {
    if (v1.size() == v2.size()) return v1 > v2;
    return v1.size() < v2.size();
}

int main() {

    vector<string> vec;
    vec.emplace_back("abc");
    vec.emplace_back("ab");
    vec.emplace_back("bbc");

    sort(vec.begin(), vec.end(), cmp);

    for (auto& str: vec) {
        cout << str << " ";
    }
    cout << endl;
    cout << ("ab" < "bbc") << endl;

    return 0;
}