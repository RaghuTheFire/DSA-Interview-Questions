/**********************************************************************
Check if a word exists in a 2D grid.
Example:
Input: Board = [['D', 'O', 'G'], ['R', 'A', 'T'], ['C', 'A', 'T']], word =
"CAT"
Output: true
Explanation:
Word "CAT" exists in the grid
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool searchWord(vector<vector<char>>& board, string word, int x, int y, int index) {
    if (index == word.size()) return true;
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]) return false;

    char temp = board[x][y];
    board[x][y] = '#'; // Mark as visited

    bool found = searchWord(board, word, x + 1, y, index + 1) ||
                 searchWord(board, word, x - 1, y, index + 1) ||
                 searchWord(board, word, x, y + 1, index + 1) ||
                 searchWord(board, word, x, y - 1, index + 1);

    board[x][y] = temp; // Restore original value
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (searchWord(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {{'D', 'O', 'G'}, {'R', 'A', 'T'}, {'C', 'A', 'T'}};
    string word = "CAT";
    bool result = exist(board, word);
    cout << (result ? "true" : "false") << endl;
    return 0;
}

