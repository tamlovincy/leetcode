/*
 * File: 5601.设计有序流.cpp
 * Project: 周赛
 * File Created: Sunday, 15th November 2020 12:09:59 pm
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Sunday, 15th November 2020 12:10:38 pm
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

/*有 n 个 (id, value) 对，其中 id 是 1 到 n 之间的一个整数，value 是一个字符串。
不存在 id 相同的两个 (id, value) 对。
设计一个流，以 任意 顺序获取 n 个 (id, value) 对，并在多次调用时 按 id 递增的顺序 返回一些值。
实现 OrderedStream 类：
OrderedStream(int n) 构造一个能接收 n 个值的流，并将当前指针 ptr 设为 1 。
String[] insert(int id, String value) 向流中存储新的 (id, value) 对。存储后：
如果流存储有 id = ptr 的 (id, value) 对，则找出从 id = ptr 开始的 最长 id 连续递增序列 ，
并按顺序 返回与这些 id 关联的值的列表。然后，将 ptr 更新为最后那个  id + 1 。
否则，返回一个空列表。
*/
class OrderedStream {
public:
    int ptr;
    vector<string> ofs;
    OrderedStream(int n) {
        ptr =1;
        ofs.resize(n+2);
    }
    vector<string> insert(int id, string value) {
        vector<string> res;
        ofs[id] = value;
        while(not ofs[ptr].empty()){
            res.push_back(ofs[ptr]);
            ptr+=1;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */