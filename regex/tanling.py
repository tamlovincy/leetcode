# -*- coding: utf-8 -*-
# @Author: wilson_t
# @Date:   2020-11-09 23:06:45
# @Last Modified by:   wilson_t
# @Last Modified time: 2020-11-10 23:13:18

# state
NORMAL = 0
LESS_EQUAL = 1
GREATER_EQUAL = 2

# target for replacement
REPLACE_TARGET = 'VHDL_RD'

def indexstr(str1,str2):
    n = len(str2)
    m = len(str1)
    res = []
    i = 0
    while str2 in str1[i:]:
        indextmp = str1.index(str2, i, m)
        res.append(indextmp)
        i = (indextmp + n)
    return res

fpath = "F:/MyGit/leetcode/regex/"
fileStr = open(fpath+"conv.v", 'r', encoding='utf-8').read()

# print(fileStr)
outStr = ""
length = len(fileStr)
state = NORMAL
i = 0
while(i < length):
    if(state == NORMAL):
        if(fileStr[i] == '<' and i+1 < length and fileStr[i+1] == '='):
            outStr += fileStr[i]
            outStr += fileStr[i+1]
            i += 2
            while(i < length and fileStr[i] == ' '):
                outStr += fileStr[i]
                i += 1
            state = LESS_EQUAL
        else:
            outStr += fileStr[i]
            i += 1
    elif(state == LESS_EQUAL):
        midStr = ""
        while(i < length and fileStr[i] != ';'):
            midStr += fileStr[i]
            i += 1
        # deal with mid string
        pos = midStr.find("after")
        # find no 'after'
        if(pos == -1):
            outStr += "("
            outStr += midStr
            outStr += ")"
            outStr += ("after " + REPLACE_TARGET)
        # find 'after'
        else:
            outStr += midStr[0: pos]
            outStr += "after "
            outStr += REPLACE_TARGET
        state = NORMAL
outFile = open('outfile.v', 'w', encoding='utf-8')
outFile.write(outStr)
outFile.close()
