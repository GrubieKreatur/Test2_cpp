#ifndef BOT_H
#define BOT_H

class Bot {
public:
    Bot();
    void makeMove(int board[3][3], bool easy);
private:
    int getBestMove(int board[3][3]);
};

#endif // BOT_H
