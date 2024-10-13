#include <iostream>
#include <stack>

using namespace std;

bool hasBrackets(const string& str)
{
    for (char c : str)
    {
        if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
        {
            return true;  
        }
    }

    return false;
}

int main()
{

    string str;
    stack <char> st;

    int nachalo = 0, end = 0;

    cout << "Введите строку: " << endl;
    cin >> str;
    if (!hasBrackets(str))
    {
        cout << "Скобок нету" << endl;
        return 0;
    }

    for (auto c : str)
    {
        if (c == '(' || c == '[' || c == '{')
            nachalo++;

        if (c == ')' || c == '}' || c == ']')
            end++;
    }

    if (nachalo != end)
        cout << "Несбалансированные скобки" << endl;
    else
    {
        for (auto c : str)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            if (c == ')' || c == '}' || c == ']')
            {
                if (st.empty())
                {
                    cout << "Несбалансированные скобки" << endl;
                    return 0;
                }
                if (c == ')' && st.top() == '(')
                    st.pop();
                else if (c == ']' && st.top() == '[')
                    st.pop();
                else if (c == '}' && st.top() == '{')
                    st.pop();
                else
                {
                    cout << "Несбалансированные скобки" << endl;
                    return 0;
                }
            }
        }
        if (st.empty())
            cout << "Сбалансированные скобки" << endl;
        else
            cout << "Несбалансированные скобки" << endl;
    }
    return 0;
}
