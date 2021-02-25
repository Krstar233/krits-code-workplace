# -*- coding:utf-8 -*-

import five_ai

BLACK = 1
WHITE = 2

class GobangGameTest():

    def __init__(self):
        self.board = []
        self.SIZE = 15
        self.winner = 0
        self.flag = 0

        for i in range(self.SIZE):
            line = []
            for j in range(self.SIZE):
                line.append(0)
            self.board.append(line)

    def show(self):
        print('#', end="  ")
        for i in range(self.SIZE):
            print("{:0>2d}".format(i), end=" ")
        print('y')
        j = 0
        for line in self.board:
            print("{:0>2d}".format(j), end=" ")
            j += 1
            for e in line:
                if e == 0:
                    print(" ", end="  ")
                    continue
                if e == 1:
                    print('X', end="  ")
                if e == 2:
                    print('O', end="  ")
            print('#')
        print('x  ',end="")
        print('#  ' * (self.SIZE+1))

    def complete(self):
        hasZero = False
        for line in self.board:
            if 0 in line:
                hasZero = True
                break
        if not hasZero:
            return True

        ROW = self.SIZE
        COL = self.SIZE
        lines = []
        for i in range(0, ROW):  # 所有行的元素 共有15行
            lines.append([self.board[i][j] for j in range(0, COL)])
        for j in range(0, COL):  # 所有列的元素 共有15列
            lines.append([self.board[i][j] for i in range(0, ROW)])

        for i in range(1, ROW - 4):
            lines.append([self.board[x][x - i] for x in range(i, ROW)])  # 对角线（斜率是-1）
            lines.append([self.board[y - i][y] for y in range(i, COL)])  # 对角线（斜率是-1）

        lines.append([self.board[x][x] for x in range(0, ROW)])  # 对角线（斜率是-1）

        for i in range(4, ROW - 1):
            lines.append([self.board[x][i - x] for x in range(i, -1, -1)])  # 对角线（斜率是1）
            lines.append([self.board[x][COL + ROW - x - 2 - i] for x in range(ROW - 1 - i, ROW)])  # 对角线（斜率是1）

        lines.append([self.board[x][ROW - 1 - x] for x in range(0, ROW)])  # 对角线（斜率是1）

        # 判断是否五子连珠
        for line in lines:
            count1 = 0
            count2 = 0
            for e in line:
                if e == 0:
                    count1 = 0
                    count2 = 0
                elif e == 1:
                    count2 = 0
                    count1 += 1
                elif e == 2:
                    count1 = 0
                    count2 += 1
                if count1 >= 5 or count2 >= 5:
                    break
            if count1 >= 5:
                self.winner = 1
                break
            if count2 >= 5:
                self.winner = 2
                break
        if self.winner != 0:
            return True
        return False

    def putChess(self, color, pos_x, pos_y):
        if pos_x < 0 or pos_y < 0 or pos_x >= self.SIZE or pos_y >= self.SIZE:
            return False
        if self.board[pos_x][pos_y] != 0:
            return False
        self.board[pos_x][pos_y] = color
        return True

    def playGame(self, first='r'):
        '''
        开始游戏
        :param first: 先手玩家，'r' --> 人类，'ai' --> AI 
        :return: None
        '''

        gobang.show()


        if first == 'r':  # 玩家先手
            print('game start!')
            while not self.complete():
                x = int(input("input a chess pos_x:"))
                y = int(input("input a chess pos_y:"))
                if (not self.putChess(BLACK, x, y)):
                    continue
                self.flag += 1
                self.show()
                x, y = five_ai.decide(self.board, WHITE, self.flag)
                self.putChess(WHITE, x, y)
                self.flag += 1
                self.show()

        if first == 'ai': # ai先手
            self.putChess(BLACK, int(self.SIZE/2), int(self.SIZE/2))
            self.flag += 1
            while not self.complete():
                x = input("input a chess pos_x:")
                y = input("input a chess pos_y:")
                if (not self.putChess(WHITE, x, y)):
                    continue
                self.flag += 1
                self.show()
                x, y = five_ai.decide(self.board, BLACK, self.flag)
                self.putChess(BLACK, x, y)
                self.flag += 1
                self.show()

        if first == 'db_ai': # 两个ai对战
            while not self.complete():
                x, y = five_ai.decide(self.board, BLACK, self.flag)
                self.putChess(BLACK, x, y)
                self.flag += 1
                self.show()
                x, y = five_ai.decide(self.board, WHITE, self.flag)
                self.putChess(WHITE, x, y)
                self.flag += 1
                self.show()

        print("GameOver~!")
        print("winner =", self.winner)

if __name__ == '__main__':
    while True:
        gobang = GobangGameTest()
        print("选择：")
        print("A. 我与AI对战，我先下棋")
        print("B. 我与AI对战，AI先下棋")
        print("C. AI与AI对战，我看它们下棋")
        choose = input("请选择：")
        if choose == 'A':
            gobang.playGame('r')
        elif choose == 'B':
            gobang.playGame('ai')
        elif choose == 'C':
            gobang.playGame('db_ai')
        else:
            continue;
      # 参数说明： 'r'--玩家先手， 'ai'--ai先手， 'db_ai'--两个ai对战