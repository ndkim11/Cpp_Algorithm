#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> tree; //needs 2d vector with N rows
bool visited[1001];

void elements(int i)
{
  if (visited[i] == 0) //not visited
  {
    visited[i] = 1; //check as visited
    for (int j = 0; j < tree[i].size(); j++)
    {
      int next = tree[i][j];
      //cout << "elements : "<< next << endl;
      elements(next); //DFS
    }
    //cout << tree[i].size() << endl;
  }
}

int main()
{
  int N, M; //N = 점, M = 선
  cin >> N >> M;
  tree.resize(N+1);
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
      //cout <<"main : "<< i << endl;
      count++;
      elements(i);
    }
  }
  cout << count << endl;
}
