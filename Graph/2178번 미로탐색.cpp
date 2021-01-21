#include <iostream>
#include <vector>
#include <queue>
//백준 2178 미로탐색
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main()
{
  int N, M;
  cin >> N >> M;

  bool visited[N][M];
  char maze[N][M];
  int count[N][M];

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> maze[i][j];
      visited[i][j] = false; //all initialized to 0
      count[i][j] = 0;
    }
    getchar();
  }

  queue<pair<int, int>> q;
  pair<int, int> start(0, 0);
  q.push(start);
  visited[start.first][start.second] = true; //visited starting point

  while (!q.empty())
  {
    for (int i = 0; i < 4; i++)
    {
      pair<int, int> new_start(q.front().first + dy[i], q.front().second + dx[i]);
      if (new_start.first >= 0 && new_start.first < N && new_start.second >= 0 && new_start.second < M)
      {
        if (!visited[new_start.first][new_start.second] && maze[new_start.first][new_start.second] == '1' && count[new_start.first][new_start.second] == 0) //not visited & is 1
        {
          count[new_start.first][new_start.second] = count[q.front().first][q.front().second] + 1;
          q.push(new_start);
          visited[new_start.first][new_start.second] = true;
        }
      }
    }
    q.pop();
  }

  cout << count[N - 1][M - 1] + 1 << endl;
}
