/*
 * File: 5389.点菜展示表.cpp
 * Project: 周赛
 * File Created: Sunday, 19th April 2020 11:13:51 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Sunday, 19th April 2020 11:13:53 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
给你一个数组 orders，表示客户在餐厅中完成的订单，确切地说， 
orders[i]=[customerNamei,tableNumberi,foodItemi] ，其中 customerNamei 是客户的姓名，
tableNumberi 是客户所在餐桌的桌号，而 foodItemi 是客户点的餐品名称。
请你返回该餐厅的 点菜展示表 。在这张表中，表中第一行为标题，其第一列为餐桌桌号 “Table” ，
后面每一列都是按字母顺序排列的餐品名称。接下来每一行中的项则表示每张餐桌订购的相应餐品数量，
第一列应当填对应的桌号，后面依次填写下单的餐品数量。
注意：客户姓名不是点菜展示表的一部分。此外，表中的数据行应该按餐桌桌号升序排列。
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<vector<string>,int> table_map; //int 桌，map<string,string> 
        vector<vector<string>> res;
        for (auto ord : orders)
        {
            vector<string> tmp;
            tmp.push_back(ord[1]);
            tmp.push_back(ord[2]);
            table_map[tmp] ++;
        }
        res[0].push_back('Table');
        for (auto it = table_map.begin();it!=table_map.end();it++)
        {
            res[0](it->first[0]);

        }

    }
};

/*

*/
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ret;
        vector<string> tmp;
        tmp.push_back("Table");
        set<string> dish;
        map<int, map<string, int>> f;
        for (auto e : orders)
        {
            int id = stoi(e[1]);
            string d = e[2];
            dish.insert(d);
            f[id][d] ++;
        }
        for (auto d : dish)
        {
            tmp.push_back(d);
        }
        ret.push_back(tmp);
        for (auto [id, order] : f)
        {
            vector<string> tmp;
            tmp.push_back(to_string(id));
            for (auto d : dish)
                tmp.push_back(to_string(f[id][d]));
            ret.push_back(tmp);
        }
        return ret;
    }
};
