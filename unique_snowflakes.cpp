#include <bits/stdc++.h>
using namespace std;

unordered_set<int> u;

int main()
{
    int n, s, sf;
    cin>>n;
    while(n--)
    {
        u.clear();
        int ms=0;
        cin>>s;
        deque<int> box;
        while(s--)
        {
            cin>>sf;
            if(u.count(sf)<=0) //not found in map
            {
                u.insert(sf);
                box.push_back(sf);
            }
            else //found in map
            {
                while(box.front()!=sf)
                {
                    u.erase(box.front());
                    box.pop_front();
                }
                box.pop_front();
                box.push_back(sf);
            }

           ms=max(ms, (int)box.size());
        }
        cout<<ms<<endl;
    }
}