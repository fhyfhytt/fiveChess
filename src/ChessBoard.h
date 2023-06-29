//
// Created by Administrator on 2020/9/18 0018.
//

#ifndef SERVER_CHESSBOARD_H
#define SERVER_CHESSBOARD_H
#pragma once
#define ROW 15
#define COL 15
#include <iostream>
class ChessBoard {
public:
    char m_cSquare[ROW][COL];
public:
    ChessBoard();
    void show();

};


#endif //SERVER_CHESSBOARD_H
