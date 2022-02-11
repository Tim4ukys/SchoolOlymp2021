#include <iostream>
#include <map>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    std::uint16_t numbBars; // Кол-во брусков
    std::uint16_t result{};
    cin >> numbBars;

    std::map<std::uint32_t, std::uint8_t> bars; // длинны брусков
    for (int i{}; i < numbBars; i++)
    {
        std::uint32_t t;
        cin >> t;

        bars.emplace(t, 0);
        if (++bars[t] != 3)
            continue;

        result++;
        bars.erase(t);
    }

    cout << result << endl;

    return 0;
}