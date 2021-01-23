#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
//백준 3055 탈출
using namespace std;

int goseumdochi[51][51]; //time it took to reach
int water[51][51];       //time it took to reach
int row, column;

int dx[4] = {-1, 0, 1, 0}; //columns
int dy[4] = {0, -1, 0, 1}; //rows

void goseumdochi_bfs(pair<int, int> start);
void water_bfs(pair<int, int> start);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> row >> column;
  char map[row][column];

  pair<int, int> S;
  pair<int, int> D;
  queue<pair<int, int>> water_task;

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++) //inserting map
    {
      cin >> map[i][j];
      if (map[i][j] == 'S')
        S = make_pair(i, j);

      if (map[i][j] == 'D')
      {
        D = make_pair(i, j);
        water[i][j] = -1;
      }

      if (map[i][j] == '*') //water starting point
      {
        water_task.push(make_pair(i, j));
      }

      if (map[i][j] == 'X') //unreachable point
      {
        goseumdochi[i][j] = -1;
        water[i][j] = -1;
      }
    }
  }
  while (!water_task.empty())
  {
    pair<int, int> cord = water_task.front();
    water_bfs(cord);
    water[cord.first][cord.second] = 0;
    water_task.pop();
  }

  goseumdochi_bfs(S);

  // for (int i = 0; i < row; i++)
  // {
  //   for (int j = 0; j < column; j++)
  //   {
  //     cout << goseumdochi[i][j];
  //   }
  //   cout << '\n';
  // }

  // for (int i = 0; i < row; i++)
  // {
  //   for (int j = 0; j < column; j++)
  //   {
  //     cout << water[i][j];
  //   }
  //   cout << '\n';
  // }

  if (goseumdochi[D.first][D.second] == 0)
    cout << "KAKTUS" << endl;
  else
    cout << goseumdochi[D.first][D.second] << endl;
}

void goseumdochi_bfs(pair<int, int> start)
{
  //cout << "goseum" << endl;
  queue<pair<int, int>> q;
  q.push(start);
  while (!q.empty()) //recording time is done
  {
    for (int i = 0; i < 4; i++)
    {
      pair<int, int> new_goseum_location(q.front().first + dy[i], q.front().second + dx[i]); //surrounding 고슴도치 blocks

      if (new_goseum_location.first >= 0 && new_goseum_location.first < row && new_goseum_location.second >= 0 && new_goseum_location.second < column) //within range
      {
        if (goseumdochi[new_goseum_location.first][new_goseum_location.second] == 0) //not visited
        {
          if (goseumdochi[q.front().first][q.front().second] + 1 < water[new_goseum_location.first][new_goseum_location.second] || water[new_goseum_location.first][new_goseum_location.second] <= 0) //faster than water
          {
            goseumdochi[new_goseum_location.first][new_goseum_location.second] = goseumdochi[q.front().first][q.front().second] + 1; //recond 고슴도치 new location time
            q.push(new_goseum_location);
          }
        }
      }
    }
    q.pop();
  }
}

void water_bfs(pair<int, int> start)
{
  //cout << "water" << endl;
  queue<pair<int, int>> q;
  q.push(start);
  while (!q.empty())
  {
    for (int i = 0; i < 4; i++)
    {
      pair<int, int> new_water_location(q.front().first + dy[i], q.front().second + dx[i]);
      if (water[new_water_location.first][new_water_location.second] == -1)
        continue;
      if (new_water_location.first >= 0 && new_water_location.first < row && new_water_location.second >= 0 && new_water_location.second < column) //within range
      {
        if (water[new_water_location.first][new_water_location.second] > water[q.front().first][q.front().second] + 1 || water[new_water_location.first][new_water_location.second] == 0) //if it takes less time -> switch
        {
          water[new_water_location.first][new_water_location.second] = water[q.front().first][q.front().second] + 1; //recond 고슴도치 new location time
          q.push(new_water_location);
        }
      }
    }
    q.pop();
  }
}
