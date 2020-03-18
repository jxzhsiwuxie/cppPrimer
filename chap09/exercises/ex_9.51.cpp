//练习 9.51：设计一个类，它有三个 unsigned 成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的 string 参数。
//你的构造函数应该能处理不同数据格式如 January 1, 1900、1/1/1990、Jan 1 1990 等。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class MDate {
   private:
    unsigned year;
    unsigned month;
    unsigned day;

    void processDateStr(string &);
    void processDateStr(const char *date) {
        string str(date);
        processDateStr(str);
    }

   public:
    MDate() : year(1970), month(1), day(1) {}
    MDate(string &date) { processDateStr(date); }
    MDate(const char *date) { processDateStr(date); }

    unsigned getYear() const { return year; }
    unsigned getMonth() const { return month; }
    unsigned getDay() const { return day; }
};

// October 1, 1900、12/1/1990、Oct 1 1990
//当前函数还有很多问题，最明显的就是不能输入太多的空格（比如 Nov   1   1990  ），这里需要改善
void MDate::processDateStr(string &str) {
    string yearStr, monthStr, dayStr;
    string::size_type pos = string::npos;

    if ((pos = str.find_first_of(',')) != string::npos) {
        pos += 1;
        yearStr = str.substr(pos);
        monthStr = str.substr(0, str.find_first_of(' '));
        dayStr = str.substr(str.find_first_of(' '), pos);
    } else if ((pos = str.find_first_of('/')) != string::npos) {
        pos += 1;
        yearStr = str.substr(str.find_last_of('/') + 1);
        monthStr = str.substr(0, pos);
        dayStr = str.substr(pos, str.find_last_of('/') + 1);
    } else if ((pos = str.find_first_of(' ')) != string::npos && pos != str.find_last_of(' ')) {
        yearStr = str.substr(str.find_last_of(' '));
        monthStr = str.substr(0, pos);
        dayStr = str.substr(pos, str.find_last_of(' '));
    }

    if (!yearStr.empty() && !monthStr.empty() && !dayStr.empty()) {
        year = std::stoi(yearStr);

        if (monthStr == "Jan" || monthStr == "January")
            month = 1;
        else if (monthStr == "Feb" || monthStr == "February")
            month = 2;
        else if (monthStr == "Mar" || monthStr == "March")
            month = 3;
        else if (monthStr == "Apr" || monthStr == "April")
            month = 4;
        else if (monthStr == "May")
            month = 5;
        else if (monthStr == "Jun" || monthStr == "June")
            month = 6;
        else if (monthStr == "Jul" || monthStr == "July")
            month = 7;
        else if (monthStr == "Aug" || monthStr == "August")
            month = 8;
        else if (monthStr == "Sep" || monthStr == "September")
            month = 9;
        else if (monthStr == "Oct" || monthStr == "October")
            month = 10;
        else if (monthStr == "Nov" || monthStr == "November")
            month = 11;
        else if (monthStr == "Dec" || monthStr == "December")
            month = 12;
        else
            month = std::stoi(monthStr);

        day = std::stoi(dayStr);
    }
}

int main() {
    cout << "输入一个日期，以下三种格式之一（October 1, 1900、12/1/1990、Oct 1 1990）" << endl;
    string dateStr;
    if (std::getline(cin, dateStr)) {
        MDate date(dateStr);

        cout << date.getYear() << " 年 " << date.getMonth() << " 月 " << date.getDay() << " 日。" << endl;
    } else {
        cout << "未获取到数据。" << endl;
    }

    return 0;
}