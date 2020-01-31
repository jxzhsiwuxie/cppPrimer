//练习 3.1：使用恰当的 using 声明重做 1.4.1 节和 2.6.2 节的练习。

/*
 对于练习 1.9：
    #include <iostream>
    using std::cout;
    using std::endl;

    int main()
    {
        int sum = 0, val = 50;

        while (val <= 100){
            sum += val;
            ++val;
        }

        cout << "50 到 100 的和为：" << sum << endl;

        return 0;
    }
*/


/*
 对于练习 1.10：
    #include <iostream>
    using std::cout;
    using std::endl;

    int main()
    {
        int val = 11;
        while (val-- > 0)
            cout << val << endl;
        return 0;
    }
*/


/*
 对于练习 1.11：
    #include <iostream>
    using std::cout;
    using std::endl;

    int main(){
        cout << "请输入两个整数：" << endl;

        int v1 = 0, v2 = 0;

        cin >> v1 >> v2;

        if(v1 >= v2){
            cout << v2 << " 到 " << v1 << "之间的整数有：" << endl;
            while(v2 <= v1) cout << v2++ << " ";
        }else{
            cout << v1 << " 到 " << v2 << "之间的整数有：" << endl;
            while(v1 <= v2) cout << v1++ << " ";
        }
        cout << endl;
        return 0;
    }
*/


/*
 对于练习 2.41：
    #include <iostream>
    #include <string>
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    struct Sales_data
    {
        string bookNo;           //书籍 ISBN 号
        unsigned int units_solid = 0; //销售数量
        double revenue = 0.0;         //销售收入
    };

    int main()
    {
        //读取多条销售记录，统计每个 ISBN 有几条记录以及同一个 ISBN 和。
        Sales_data currentData, currentTotalData;
        double price;
        int count = 0;
        if (cin >> currentTotalData.bookNo)
        {
            //读取第一条记录，确保确实有数据
            count = 1;
            cin >> currentTotalData.units_solid >> price;
            currentTotalData.revenue += currentTotalData.units_solid * price;

            while (cin >> currentData.bookNo >> currentData.units_solid >> price)
            {
                if (currentData.bookNo == currentTotalData.bookNo)
                {
                    ++count;
                    currentData.revenue = currentData.units_solid * price;
                    currentTotalData.units_solid += currentData.units_solid;
                    currentTotalData.revenue += currentData.revenue;
                }
                else
                {
                    //输出上一条记录总和
                    cout << "ISBN 为 " << currentTotalData.bookNo << " 的记录共有 " << count << " 条，";
                    cout << "总销售数量为 " << currentTotalData.units_solid << "，总销售额为 ￥" << currentTotalData.revenue << endl;
                    //设置当前记录总和
                    count = 1;
                    currentTotalData.bookNo = currentData.bookNo;
                    currentTotalData.units_solid = currentData.units_solid;
                    currentData.revenue = currentData.units_solid * price;
                    currentTotalData.revenue = currentData.revenue;
                }
            }
            //循环结束，打印最后一组 ISBN 的总和
            cout << "ISBN 为 " << currentTotalData.bookNo << " 的记录共有 " << count << " 条，";
            cout << "总销售数量为 " << currentTotalData.units_solid << "，总销售额为 ￥" << currentTotalData.revenue << endl;
        }
        else
        {
            return -1;
        }

        return 0;
    }
*/