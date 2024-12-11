#include <array>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

inline bool isValidMove(const vector<vector<int>>& board, int i, int j)
{
    if (i < 0 || i >= static_cast<int>(board.size()))
        return false;
    else if (j < 0 || j >= static_cast<int>(board[i].size()))
        return false;
    else if (board[i][j] != -1)
        return false;
    else
        return true;
}

int solve(std::vector<std::vector<int>>& board,
          const pair<int,int>& source,
          const pair<int,int>& dest)
{
    static const std::array<std::pair<int,int>, 8> possible_moves {{{2 , 1}, {1 , 2},
                                                                    {-1, 2}, {-2, 1},
                                                                    {-2,-1}, {-1,-2},
                                                                    {1 ,-2}, {2 ,-1}}};

    queue<pair<int,int>> q;
    int next_i, next_j;

    board[source.first][source.second] = 0;
    q.push(source);

    while (!q.empty() && board[dest.first][dest.second] == -1)
    {
        auto curr = q.front();
        q.pop();

        for (const auto& mv: possible_moves)
        {
            next_i = curr.first + mv.first;
            next_j = curr.second + mv.second;

            if (isValidMove(board, next_i, next_j))
            {
                board[next_i][next_j] = board[curr.first][curr.second] + 1;
                q.emplace(next_i, next_j);
            }
        }
    }

    return board[dest.first][dest.second];
}

int main()
{
    int tests;
    cin >> tests;

    while (tests--)
    {
        char a, b, c, d;
        cin >> a >> b >> c >> d;

        vector<vector<int>> board (8,vector<int>(8, -1));

        auto source = pair<int,int>{b - '0' - 1, a - 'a'};
        auto dest   = pair<int,int>{d - '0' - 1, c - 'a'};

       cout << solve(board, source, dest) << endl;
    }

    return 0;
}