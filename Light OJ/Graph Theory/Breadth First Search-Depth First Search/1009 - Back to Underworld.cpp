#include <bits/stdc++.h>
using namespace std;
vector <int> g[21000];
vector <int> ff,ss;
bool visit[21000],pre[21000];

void clean()
{
    for(int i = 0;i<21000;i++) {
        g[i].clear();
        visit[i] = 0;
        pre[i] = 0;
    }
    ff.clear();
    ss.clear();
}

void dfs(int startingNode,int flg)
{
    if(visit[startingNode]) return;
    visit[startingNode] = 1;
    int nflg;
    if(flg == 1) nflg = 2;
    else nflg = 1;
    if(flg == 1) ff.push_back(startingNode);
    else ss.push_back(startingNode);

    for(int i = 0;i<g[startingNode].size();i++)
    {
        int u = g[startingNode][i];
        dfs(u,nflg);
    }
}

int main()
{
    int T;
    cin >> T;
    for(int j = 1;j<=T;j++)
    {
        int edges;
        cin >> edges;
        clean();
        int maximumNodes = 0;


        for(int i = 0;i<edges;i++)
        {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            pre[u] = 1;
            pre[v] = 1;
            maximumNodes = max(maximumNodes,max(u,v));
        }

        int Total = 0;
        for(int i = 1;i <= maximumNodes; i++)
        {
            if(pre[i] && !visit[i])
            {
                dfs(i,1);
                Total += max(ff.size(),ss.size());
                ff.clear();
                ss.clear();
            }
        }
        cout<<"Case "<< j <<": ";
        cout<< Total <<endl;
    }
    return 0;
}
