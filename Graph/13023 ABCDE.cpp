#include <iostream>
#include <algorithm>
#include <vector>

//백준 13023 ABCDE
using namespace std;

bool ABCDE_found = 0;
bool checked[2001];

void find_ABCDE(int i, int depth, vector<vector<int>> &friends) //reference를 넘기지 않고 일반 벡터를 넘기면 시간 초과: copy에 시간 듬
{
  checked[i] = true;
  if (depth == 4)
  {
    // cout << "depth : " << depth << " i: " << i << endl;
    // cout << "ABCDE found" << endl;
    ABCDE_found = true; //ABCDE set found
    return;
  }

  //cout << "depth : " << depth << " i: " << i << endl;
  for (int l = 0; l < friends[i].size(); l++)
  {
    int new_i = friends[i][l];   //new starting point
    if (checked[new_i] == false) //not checked/visited
    {
      find_ABCDE(new_i, depth + 1, friends);
    }
    if (ABCDE_found == true)
      return;
  }
  checked[i] = false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> friends(N);
  for (int i = 0; i < M; i++)
  {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    friends[temp1].push_back(temp2);
    friends[temp2].push_back(temp1);
  } //establish relationship

  for (int i = 0; i < N; i++)
  {
    find_ABCDE(i, 0, friends);
    if (ABCDE_found == true)
    {
      break;
    }
  }

  cout << ABCDE_found << endl;
}

