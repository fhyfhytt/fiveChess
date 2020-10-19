//
// Created by Administrator on 2020/9/27 0027.
//

#ifndef FIVECHESS_POINTER_H
#define FIVECHESS_POINTER_H


class Pointer {
public:
    int x;
    int y;
    int score=0;
    Pointer(int x,int y,int score){
        this->x=x;
        this->y=y;
        this->score=score;
    }
    void addScore(int score){
        this->score+=score;
    }
    void setScore(int score){
        this->score=score;
    }
    ~Pointer(){

    }
};


#endif //FIVECHESS_POINTER_H
