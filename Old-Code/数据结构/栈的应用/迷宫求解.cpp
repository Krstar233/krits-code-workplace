#include "Stack.h"
#include "Windows.h"
#include <iostream>

using namespace std;

const int MAZESIZE = 10;
int maze[MAZESIZE][MAZESIZE];//0代表空白， 1代表墙， 2代表足迹， 3代表不能走的标记
class PosType{
public:
    int x, y;

    PosType(){}
    PosType(int x, int y): x(x),y(y){}
    bool operator == (const PosType &pos_b){
        return x == pos_b.x && y == pos_b.y;
    }
};

class Foot{
public:
    int ord; //通道块在路径上的序号
    PosType seat; //通道块在迷宫中的 “坐标位置”
    int dir; //从此通道块走向下一通道块的方向   1--东， 2--南， 3--西， 4--北

    Foot(){}
    Foot(int ord, PosType seat, int dir):ord(ord), seat(seat), dir(dir){}
};

void FootPrint(PosType pos){
    maze[pos.x][pos.y] = 2;
}//记录足迹

PosType NextPos(PosType pos, int dir){
    if (dir == 1){
        pos.y++;
    }
    else if (dir == 2){
        pos.x++;
    }
    else if (dir == 3){
        pos.y--;
    }
    else if (dir == 4){
        pos.x--;
    }
    return pos;
}//获取沿某方向的下一坐标

void Mark(PosType pos){
    maze[pos.x][pos.y] = 3;
}//记录此路不通

bool Pass(PosType pos){
    return maze[pos.x][pos.y] == 0;
}

bool MazePath(PosType start, PosType end){
    Stack<Foot> stack;
    PosType curpos = start;
    int curstep = 1;//步骤序号

    do{
        if (Pass(curpos)){
            FootPrint(curpos);
            Foot e(curstep, curpos, 1);
            stack.push(e);
            if (curpos == end)
                return true;
            curpos = NextPos(curpos, 1);
            curstep++;
        }
        else{
            if (!stack.empty()){
                Foot e = stack.pop();
                while (e.dir == 4 && !stack.empty()){
                    Mark(e.seat);
                    e = stack.pop();    //留下不能通过的标记，并退回一步
                }
                if (e.dir < 4){
                    e.dir++;    stack.push(e);// 换下一个方向探索
                    curpos = NextPos(e.seat, e.dir);
                }
            }
        }
    }while(!stack.empty());
    return false;
}

void MakeMaze(){
    char ch;
    cout << "Please input a maze(10*10):" << endl;
    for (int i = 0; i < MAZESIZE; i++){
        for (int j = 0; j < MAZESIZE; j++){
            ch = getchar();
            if (ch == ' ')
                maze[i][j] = 0;
            else
                maze[i][j] = 1;
            getchar();
        }
    }
}

void show(){
    for (int i = 0; i < MAZESIZE; i++){
        for (int j = 0; j < MAZESIZE; j++){
            if (maze[i][j] == 1){
                cout << "# ";
            }
            else if (maze[i][j] == 2){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                cout << "* ";//路径输出成红色
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }

}
int main(){
    PosType start(1,1), end(8,8);

    MakeMaze();

    if (MazePath(start, end)){
        cout << "Done!" << endl;
        show();
    }
    else{
        cout << "Error!" << endl;
    }
}

/*
maze 1:
# # # # # # # # # #
#                 #
#                 #
#                 #
#                 #
#                 #
#                 #
#                 #
#                 #
# # # # # # # # # #

maze 2:
# # # # # # # # # #
#               # #
# #               #
#   #   #         #
#   # # #     # # #
# #             # #
#           # # # #
#                 #
#                 #
# # # # # # # # # #

maze 3:
# # # # # # # # # #
#     #       #   #
#     #       #   #
#         # #     #
#   # # #         #
#       #         #
#   #       #     #
#   # # #   # #   #
# #               #
# # # # # # # # # #

 */