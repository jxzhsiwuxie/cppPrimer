//练习 11.33：实现你自己的单词转换程序。


#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::map;
using std::runtime_error;
using std::string;

//生成转换规则
map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;                  //保存转换规则
    string key;                                     //要转换的单词
    string value;                                   //转换你后的内容
    //读取第一个单词存入 key 中，行中剩余内容存入 value 中
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)                       //检查是否有转换规则
            trans_map[key] = value.substr(1);       //跳过前导空格
            //trans_map.insert({key,value.substr(1)});
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

//生成转换文本
const string &transform(const string &s, const map<string, string> &m) {
    //实际的转化工作
    auto map_it = m.find(s);
    if (map_it != m.end())
        return map_it->second;          //使用替换短语
    else
        return s;                       //否则返回原 string
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = buildMap(map_file);    //保存转换规则
    string text;                            //保存输入中的每一行
    while (getline(input, text)) {          //读取一行输入
        istringstream stream(text);         //读取每个单词
        string word;
        bool firstword = true;              //控制是否打印空格
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";

            cout << transform(word, trans_map);     //打印输出
        }
        cout << endl;                               //完成一行的转换
    }
}

int main() {
    ifstream map_ifs("../samples/map_file.txt");
    ifstream input_ifs0("../samples/input.txt");
    ifstream input_ifs1("../samples/input.txt");
    string line;

    cout << "转换前的文本为：" << endl;
    while (getline (input_ifs0, line))
        cout << line << endl;
    cout << "------------------------"<<endl;

    cout << "转换后的文本为：" << endl;
    word_transform(map_ifs, input_ifs1);

    return 0;
}
