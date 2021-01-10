#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
bool visited[1001];
queue<int> q;

void elements(int i, vector<vector<int>> &tree)
{
  q.push(i);
  while (!q.empty()) //until queue is empty
  {
    int cur = q.front(); //regard as visited
    q.pop();
    if (visited[cur])
      continue;
    visited[cur] = 1;                          //mark as visited
    for (int j = 0; j < tree[cur].size(); j++) //insert all elements in tree[cur]
    {
      if (!visited[tree[cur][j]]) // if not visited
        q.push(tree[cur][j]);
    }
  }
}

int main()
{
  int N, M; //N = 점, M = 선
  cin >> N >> M;
  vector<vector<int>> tree(N + 1); //needs 2d vector with N rows
  //tree.resize(N + 1);
  int count = 0;

  for (int i = 0; i < M; i++) //insert numbers to vector
  {
    int fir, sec;
    cin >> fir >> sec;
    tree[fir].push_back(sec);
    tree[sec].push_back(fir); // connect two dots
  }

  for (int i = 1; i <= N; i++)
  {
    if (visited[i] == 0) //not visited
    {
      elements(i, tree); //pass address of tree
      count++;
    }
  }
  cout << count << endl;
}
