#include <iostream>
#include <algorithm>
#include <vector>
//백준 4963 섬의 개수
using namespace std;

void find_land_around(int i, int j, bool (*map)[52], bool (*checked)[52]);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int W, H;
  while (1)
  {
    bool map[52][52] = {};
    bool checked[52][52] = {};
    //bool(*mapptr)[52] = map;
    //bool(*checkedptr)[52] = checked;

    cin >> W >> H; // W row H column
    if (!W && !H)  // both 0 -> escape
      break;
      
    int count = 0;
    for (int i = 1; i <= H; i++) //i height
    {
      for (int j = 1; j <= W; j++) //j width
      {
        cin >> map[i][j];
      }
    } //insert land 1 sea 0

    for (int i = 1; i <= H; i++)
    {
      for (int j = 1; j <= W; j++)
      {
        if (map[i][j]) //when it is land -> check
        {
          if (!checked[i][j]) //only when not checked
          {
            count++;
            find_land_around(i, j, map, checked);
          }
        }
      }
    }

    cout << count << '\n';
  }
}

void find_land_around(int i, int j, bool (*map)[52], bool (*checked)[52])
{
  checked[i][j] = 1;
  for (int delta_x = -1; delta_x <= 1; delta_x++)
  {
    for (int delta_y = -1; delta_y <= 1; delta_y++)
    {
      if (checked[i + delta_x][j + delta_y] == 0 && map[i + delta_x][j + delta_y] == 1)
      {
        find_land_around(i + delta_x, j + delta_y, map, checked);
      }
      else
      {
        checked[i + delta_x][j + delta_y] = 1;
      }
    }
  }
}
