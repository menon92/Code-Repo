#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int value(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
}

int main()
{
    string s1, s2;
    vector <long long> v1;
    vector <long long> v2;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin >> s1 >> s2)
    {
        int n, m;

        // calculate the minimum base for first number.
        n = 1; m = 1;
        for(int i = 0; i < s1.size(); i++) {
             n = max(n, value(s1[i])) + 1;
        }

        // calculate the minimum base for second number.
        for(int i = 0; i < s2.size(); i++) {
              m = max(m, value(s2[i])) + 1;
        }

        // clear the vector after each input.
        v1.clear(); v2.clear();
        long long ax;

        // calculate the 10 base equivalent number for each n to 36 base for first number.
        for(int i = n; i <= 36; i++) {
            ax = 0;
            for(int j = 0; j < s1.size(); j++) {
                ax = ax * i + value(s1[j]);
            }
            v1.push_back(ax);
        }

        // calculate the 10 base equibalent nuber for each n to 36 base for second nubmer.
        for(int i = m; i <= 36; i++) {
            ax = 0;
            for(int j = 0; j < s2.size(); j++) {
                ax = ax * i + value(s2[j]);
            }
            v2.push_back(ax);
        }

        // search for  the base in the vector.
        bool equal = false;
        for(int i = 0; i < v1.size() && !equal; i++) {
            for(int j = 0; j < v2.size() && !equal; j++) {
                if(v1[i] == v2[j]) {
                    equal = true;
                    cout << s1 << " (base " << i + n << ") = " << s2 << " (base " << j + m << ")" << endl;
                }
            }
        }
        if(!equal) {
            cout << s1 << " is not equal to " << s2 << " in any base 2..36" << endl;
        }
    }

    return 0;
}
