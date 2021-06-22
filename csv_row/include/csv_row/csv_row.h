#pragma once

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string_view>
#include <string>

namespace csv_row {

    class CsvRow
    {
    public:
        char sep = ';';
        CsvRow() {}
        CsvRow(char sep) : sep(sep) {}
        std::string const& operator[](std::size_t index) const;
        std::size_t size() const;
        void readNextRow(std::istream& str);

    private:
        std::vector<std::string> m_data;
    };

    std::string const& CsvRow::operator[](std::size_t index) const
    {
        return m_data[index];
    }

    std::size_t CsvRow::size() const
    {
        return m_data.size();
    }

    void CsvRow::readNextRow(std::istream& str)
    {
        std::string      line;
        std::getline(str, line);

        std::stringstream   lineStream(line);
        std::string      cell;

        m_data.clear();
        while(std::getline(lineStream, cell, sep))
        {
            m_data.push_back(cell);
        }
        // This checks for a trailing comma with no data after it.
        if (!lineStream && cell.empty())
        {
            // If there was a trailing comma then add an empty element.
            m_data.push_back("");
        }
    }


} // namespace csv_row

std::istream& operator>>(std::istream& str, csv_row::CsvRow& data)
{
    data.readNextRow(str);
    return str;
}


// Usage:
// int main()
// {
//     std::ifstream file("plop.csv");

//     csv_row::CsvRow row;
//     while(file >> row)
//     {
//         std::cout << "4th Element(" << row[3] << ")\n";
//     }
// }