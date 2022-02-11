#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    std::uint32_t nSizeVacation; // продолжительность отпуска
    std::uint8_t day; // День в неделе: среда, четверг, суббота...

    cin >> nSizeVacation >> day;
    day -= '0';

    if (day != 1) nSizeVacation -= 8 - day;

    cout << nSizeVacation / 7 + ((nSizeVacation % 7) == 5 ? 1 : 0) << endl;

    return 0;
}