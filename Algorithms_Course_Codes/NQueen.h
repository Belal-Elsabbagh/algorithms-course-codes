#pragma once
#include <iostream>
#include <vector>
class NQueen
{
public:
    void solveNQueen(int number);
private:
	bool isSafe(const std::vector<std::vector<int>>& board, int column = 0, int row = 0);
    void generate_solution(std::vector<std::vector<int>>& board, int column = 0);
    void printBoard(std::vector<std::vector<int>> board)
    {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++)
                std::cout << " " << board[i][j] << " ";
            std::cout << "\n";
        }
    }
};

inline void NQueen::solveNQueen(int number)
{
	std::vector<std::vector<int>> board(number, std::vector<int>(number, 0));
    generate_solution(board, 0);
}

inline bool NQueen::isSafe(const std::vector<std::vector<int>>& board, int column, int row)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < column; i++)
        if (board[row][i] == 1) return false;

    /* Check upper diagonal on left side */
    for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    for (i = row, j = column; j >= 0 && i < board.size(); i++, j--)
        if (board[i][j] == 1) return false;

    return true;
}

inline void NQueen::generate_solution(std::vector<std::vector<int>>& board, int column)
{
    if (column == board.size())
    {
        std::cout << "I guess...\n";
        printBoard(board);
        return;
    }
    for (int row = 0; row < board.size(); row++) {
        if (!isSafe(board, row, column)) continue;
        board[row][column] = 1;
        generate_solution(board, column + 1);
        board[row][column] = 0;
    }
}

void TEST_NQueen()
{
    NQueen test;
    test.solveNQueen(4);
}
