#include <iostream>
#include <filesystem>
#include <string>
#include <string.h>
#include <fstream>
#include <ctime>

using namespace std;

#define TMP_DIR_NAME "./temp_suck"

const int MAX_TEST = 22;

int main(int argn, char* argv[])
{
    if (argn < 2) {
        cout << "ERR: Usage: " << argv[0] << " <program_test.name>" << endl;
        return EXIT_FAILURE;
    }

    using namespace filesystem;

    create_directory(path(TMP_DIR_NAME));
    
    struct testsInfo {
        std::uint16_t m_nTestOK;
        std::uint16_t m_nCountTest;
    } tests{};

    for (int i{ 1 }; i < MAX_TEST + 1; i++) 
    {
        char buff[256];
        snprintf(buff, 256, "%s < %s%02d > %s/%02d", argv[1], "./tests/", i, TMP_DIR_NAME, i);

        auto time = clock();
        system(buff);
        auto newTime = clock();
        printf("%d> time: %d.%03d; STATE: ", i, static_cast<int>((newTime - time) / CLOCKS_PER_SEC), static_cast<int>((newTime - time) % CLOCKS_PER_SEC));
        
        snprintf(buff, 256, "%s%02d.a", "./tests/", i);
        std::ifstream file1(buff, std::ios_base::in);
        std::string str1{std::istreambuf_iterator<char>(file1), std::istreambuf_iterator<char>()};
        
        snprintf(buff, 256, "%s/%02d", TMP_DIR_NAME, i);
        std::ifstream file2(buff, std::ios_base::in);
        std::string str2{std::istreambuf_iterator<char>(file2), std::istreambuf_iterator<char>()};
        
        if (str1 == str2) {
            cout << "OK" << endl;
            tests.m_nTestOK++;
        }
        else {
            cout << "FAIL" << endl;
        }

        tests.m_nCountTest++;
    }

    remove_all(path(TMP_DIR_NAME));

    cout << "==============" << endl;
    cout << "Result: " << int(tests.m_nTestOK) << "/" << int(tests.m_nCountTest) << endl;

    return EXIT_SUCCESS;
}