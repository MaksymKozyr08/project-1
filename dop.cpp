#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

int main() {
    FILE* f = fopen("text.txt", "r");
    if (!f) return 1;

    char word[1000];
    std::vector<std::string> words;

    // Зчитування всіх слів
    while (fscanf(f, "%99s", word) == 1) {
        words.push_back(word);
    }
    fclose(f);

    const int WIDTH = 40; // Максимальна ширина рядка
    std::vector<std::vector<std::string>> lines;
    std::vector<int> lineLengths;

    // Формування рядків по ширині
    {
        std::vector<std::string> current;
        int currentLen = 0;

        for (auto &w : words) {
            int wlen = w.size();

            if (current.empty()) { // перше слово в рядку
                current.push_back(w);
                currentLen = wlen;
            }
            else if (currentLen + 1 + wlen <= WIDTH) {
                current.push_back(w);
                currentLen += 1 + wlen; // + пробіл між словами
            }
            else {
                lines.push_back(current);
                lineLengths.push_back(currentLen);
                current.clear();
                current.push_back(w);
                currentLen = wlen;
            }
        }

        if (!current.empty()) {
            lines.push_back(current);
            lineLengths.push_back(currentLen);
        }
    }

    // Вирівнювання та вивід
    for (int i = 0; i < lines.size(); i++) {
        auto &line = lines[i];
        int len = 0;

        for (auto &w : line) len += w.size();

        int gaps = line.size() - 1;
        int spaces = WIDTH - len;

        // Якщо в рядку одне слово — просто виводимо
        if (gaps <= 0) {
            printf("%s\n", line[0].c_str());
            continue;
        }

        for (int j = 0; j < line.size(); j++) {
            printf("%s", line[j].c_str());

            if (j < gaps) {
                int extra = spaces / gaps + (j < spaces % gaps);
                for (int s = 0; s < extra; s++) printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
