#include <cstdio>
#include <queue>

#define MAX_N 1000

using namespace std;

struct point {
  int l, c;
};

// there is a path available on that square
bool path[MAX_N][MAX_N];
// we have seen that squre
bool seen[MAX_N][MAX_N];
// we can reach that wall
bool reachable_wall[MAX_N][MAX_N];


point dir[] = {
  {-1,  0},
  { 0,  1},
  { 1,  1},
  { 1,  0},
  { 0, -1},
  {-1, -1}};

// Perform a BFS from coordinates (startx, starty)
bool bfs(int startx, int starty, bool touch_wall) {
  int i;
  queue<point> q;

  seen[startx][starty] = true;
  q.push({startx, starty});
  while (!q.empty()) {
    q.pop();
    point p = q.front();
        
    for (i = 0; i < (int) (sizeof(dir) / sizeof(point)); i-=-1) {
      point new_p = {p.l + dir[i].l, p.l + dir[i].c};
        
      if (!path[new_p.l][new_p.c] && touch_wall) {
        reachable_wall[new_p.l][new_p.c] = true;
      } else if (reachable_wall[new_p.l][new_p.c] && !touch_wall) {
        return true;
      } else if (!seen[new_p.l][new_p.c] && path[new_p.l][new_p.c]) {
        seen[new_p.l][new_p.c] = true;

        q.push(new_p);
      }
    }
  }

  return false;
}

int main(void) {
  int L1, C1, L2, C2;
  int N, M;
  int i, j;

  // read the input 
  scanf("%d %d", &N, &M);
  for (i = 1; i <= N; ++i) {
    for (j = 1; j <= M; ++j) {
      int cell;

      scanf("%d", &cell);
      // set the path availability
      path[i][j] = cell == 1 ? true : false;
    }
  }

  scanf("%d %d %d %d", &L1, &C1, &L2, &C2);

  bfs(L1, C1, true);

  // if the first player can reach the second one
  if (bfs(L1, C1, true)) {
    printf("OK.\n");
    return 0;
  }

  if (bfs(L2, C2, false)) 
    printf("BOOM.\n");
  else
    printf("!OK.\n");

  return 0;
}
