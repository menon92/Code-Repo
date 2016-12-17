/**
  * Writer : Mehadi Hasan Menon.
  **/
#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using std::stack;
using namespace std;

int evaluate_postfix(char *exp)
{
    stack <int> s;
    int len = strlen(exp);

    for(int i = 0; i < len; )
    {
        int top1, top2;

        if(exp[i] == '+')
        {
            top1 = s.top(); s.pop();
            top2 = s.top(); s.pop();
            s.push(top2 + top1);
            i++;
           // cout << "plus :" << top1 + top2 << endl;
        }
        else if(exp[i] == '-')
        {
            top1 = s.top(); s.pop();
            top2 = s.top(); s.pop();
            s.push(top2 - top1);
            i++;
            //cout << "sub : " << top2 - top1 << endl;
        }
        else if(exp[i] == '*')
        {
            top1 = s.top(); s.pop();
            top2 = s.top(); s.pop();
            s.push(top2 * top1);
            i++;
           // cout << "mul: " << top1 * top2 << endl;
        }
        else if(exp[i] == '/')
        {
            top1 = s.top(); s.pop();
            top2 = s.top(); s.pop();
            //cout << top1 << " " << top2 << endl;
            s.push(top2 / top1);
            i++;
            //cout << "div : " << top2 / top1 << endl;
        }
        else
        {
            char tmp[10];
            int k = 0;

            while(exp[i] == ' ') {
                i++;
            }
            while(isdigit(exp[i]))
            {
                tmp[k] = exp[i];
                k++; i++;
            }
            tmp[k] = '\0';

            if(strlen(tmp) > 0)
            {
                //std::cout << "tamp: " << tmp << std::endl;
                s.push(atoi(tmp));
            }
        }

    }
    return s.top();
}


int main()
{
    char exp[] = "5 6 2 + * 12 4 / -";

    //while(gets(exp))
   // {
        std::cout << "After evaluation value is : " << evaluate_postfix(exp) << std::endl;
   // }

    return 0;
}
