#include <iostream>
#include <bits/stdc++.h> 
std::vector<int> list[1001];
bool vis[1001];
int con_comp = 0;
void dfs(int cur)
{
  vis[cur] = true;
  for(int i = 0; i < list[cur].size(); i++)
  {
    if(vis[list[cur][i]]) continue;
    dfs(list[cur][i]);
  }
  return;
}
int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 0; i < m; i ++)
  {
    int u, v;
    std::cin >> u >> v;
    list[u].push_back(v);
    list[v].push_back(u);
  }
  for(int i = 1; i <= n; i++)
  {
    if(vis[i]) continue;
    con_comp++; dfs(i);
  }
  std:: cout << con_comp;
} 
