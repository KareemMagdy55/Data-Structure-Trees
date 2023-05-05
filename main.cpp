#include <iostream>
#include "Students_database/students_DB.cpp"
using namespace std;

int main() {
    loadTxtFile();
    cout << students[0];
    return 0;
}
