# csv_row
C++ Header Only Library to read rows from csv files with std::istream support

Usage:
```cpp
#include "csv_row/csv_row.h"
int main()
{
    std::ifstream file("plop.csv");
    csv_row::CsvRow row;
    while(file >> row)
    {
        std::cout << "3rd Element parsed as float (" << row.get<float>(2) << ")\n";
        std::cout << "4th Element as string (" << row[3] << ")\n";
    }
}
```
