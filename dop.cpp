#include <cstdio>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

vector<string> readWords() {
    vector<string> w;
    string cur;
    int ch;
    while ((ch = getchar()) != EOF) {
        if (isspace(ch)) {
            if (!cur.empty()) { w.push_back(cur); cur.clear(); }
        } else cur.push_back(ch);
    }
    if (!cur.empty()) w.push_back(cur);
    return w;
}

string justify(const vector<string>& words, int width, bool last) {
    if (words.size() == 1 || last) {
        string s = words[0];
        for (size_t i = 1; i < words.size(); i++) s += " " + words[i];
        s += string(width - s.size(), ' ');
        return s;
    }
    int chars = 0;
    for (auto& x : words) chars += x.size();
    int gaps = words.size() - 1;
    int spaces = width - chars;
    int base = spaces / gaps, extra = spaces % gaps;

    string s;
    for (size_t i = 0; i < words.size(); i++) {
        s += words[i];
        if (i < words.size() - 1) {
            s += string(base + (extra > 0), ' ');
            if (extra > 0) extra--;
        }
    }
    return s;
}

int main() {
    int width;
    scanf("%d", &width);
    getchar();

    vector<string> w = readWords();
    vector<string> line;
    int len = 0;

    for (size_t i = 0; i < w.size(); i++) {
        int L = w[i].size();
        if (line.empty()) {
            line.push_back(w[i]);
            len = L;
        } else if (len + 1 + L > width) {
            string s = justify(line, width, false);
            printf("%s\n", s.c_str());
            line.clear();
            line.push_back(w[i]);
            len = L;
        } else {
            line.push_back(w[i]);
            len += 1 + L;
        }
    }

    if (!line.empty()) {
        string s = justify(line, width, true);
        printf("%s\n", s.c_str());
    }
}
