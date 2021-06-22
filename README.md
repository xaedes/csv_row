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
        std::cout << "4th Element(" << row[3] << ")\n";
    }
}
```
