#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    Solution(){}
    string addBinary(string a, string b) {
        int a_ptr = 0;
        int b_ptr = 0;
        std::string res = "";
        bool carryFlag = false;
        for (a_ptr = a.size() - 1, b_ptr = b.size() - 1; a_ptr >= 0 || b_ptr >= 0; a_ptr--, b_ptr--)
        {
            if (a_ptr < 0)
            {
                if (carryFlag)
                {
                    if (b[b_ptr] == '0' )
                    {
                        carryFlag = false;
                        res.insert(0, "1");
                    }
                    else
                    {
                        res.insert(0, "0");
                    }
                }
                else
                {
                    res = b[b_ptr] + res;
                }
               
                continue;
            }
            else if (b_ptr < 0)
            {
                if (carryFlag)
                {
                    if (a[a_ptr] == '0' )
                    {
                        carryFlag = false;
                        res.insert(0, "1");
                    }
                    else
                    {
                        res.insert(0, "0");
                    }
                }
                else
                {
                    res = a[a_ptr] + res;
                }
               
                continue;
            }
            if (carryFlag)
            {
                if ((a[a_ptr] == '1' && b[b_ptr] == '1')
                 || (a[a_ptr] == '0' && b[b_ptr] == '0'))
                {
                    res.insert(0, "1");
                }
                else 
                {
                    res.insert(0, "0");
                }
                if (a[a_ptr] == '0' && b[b_ptr] == '0')
                {
                    carryFlag = false;
                }
            } 
            else
            {
                if (a[a_ptr] == '1' && b[b_ptr] == '1')
                {
                    res.insert(0, "0");
                    carryFlag = true;
                    continue;
                }
                if (a[a_ptr] == '0' && b[b_ptr] == '0')
                {
                    res.insert(0, "0");
                }
                else
                {
                    res.insert(0, "1");
                }
            }
        }

        if (carryFlag)
        {
            res.insert(0, "1");
        }

        return res;
    }
};

int main ()
{
    Solution a;
    string res = a.addBinary("111", "10");
    cout << "res = " << res;
    return 0;
}