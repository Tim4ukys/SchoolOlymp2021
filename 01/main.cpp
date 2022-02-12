#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    std::int32_t nSizeVacation; // продолжительность отпуска
    std::uint8_t day; // День в неделе: среда, четверг, суббота...

    cin >> nSizeVacation >> day;
    day -= '0';

    if (day != 1) nSizeVacation -= 8 - day;

    cout << std::max(nSizeVacation / 7, 0) << endl;

    return 0;
}