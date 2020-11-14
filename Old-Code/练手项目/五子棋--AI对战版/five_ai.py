# encoding: utf-8

import time
from copy import deepcopy
import random
from EvalScore import eval_score

ROW = 15 # 棋盘15行
COL = 15 # 棋盘15列 （行和列一般都相同）
SPACE = 0 # 空格用0表示
BLACK = 1 # 在棋盘矩阵中，黑子用1表示
WHITE = 2 # 在棋盘矩阵中，白子用2表示
DEPTH = 2 # 提前考虑2步（注意，一定是偶数）

# 博弈搜索树
class MGTNode():
    def __init__(self, board, color, depth):
        self.board = board
        self.color = color
        self.depth = depth
        self.pos_x = -1
        self.pos_y = -1

    # 在某个位置(x,y)落子
    def set(self, x, y, color):
        if color == BLACK or color == WHITE:
            if x in range(0,ROW) and y in range(0,COL):
                self.board[x][y] = color

    # 返回搜索树对象，x和y
    def search(self):
        for x in range(0, ROW):
            for y in range(0, COL):
                if self.board[x][y] != SPACE:
                    continue
                next_color = BLACK ^ self.color ^ WHITE
                next_node = MGTNode(deepcopy(self.board), next_color, self.depth-1)
                next_node.set(x, y, self.color)
                yield next_node, x, y

# 极大极小值搜索（无alpha-beta剪枝）。没用到。我们使用的是alpha_beta()方法
def mini_max(node):
    if node.depth <= 0:
        return eval_score(node)
    score = -1000000
    for next_node, x, y in node.search():
        val = -mini_max(next_node)
        if val > score:
            score = val
            node.pos_x, node.pos_y = x, y
    return score

def alpha_beta(node, alpha=-1000000, beta=1000000):
    if node.depth <= 0:
        return eval_score(node)
    for next_node, x, y in node.search():
        val = -alpha_beta(next_node, -beta, -alpha)
        if val >= beta:
            return beta
        if val > alpha:
            alpha = val
            node.pos_x, node.pos_y = x, y
    return alpha

# 棋手下第二步棋 （如果棋盘是15*15）,第二步在第一步的周围下 (第一步下的是(pos_x,pos_y))
def secondstep(pos_x, pos_y):
    low = pos_x - 1
    high = pos_y + 1
    pos_set = []
    # print("debug_low_high", low, "---", high)
    # print("debug_x_y", pos_x, "---", pos_y)
    for x in range(low, high+1):
        # print("debug_1")
        for y in range(low, high+1):
            if x == pos_x and y == pos_y:
                continue
            if x < 0 or y < 0:
                continue
            if x >= COL or y >= ROW:
                continue
            pos_set.append([x,y])
    ret = random.choice(pos_set) # 从几个选择中随机挑选一个位置落子
    # print("debug_ret:",ret)
    return ret

# 判断下一步在哪里落子
# 详细参数为：
# board：当前棋盘矩阵信息 15*15 如：
#  [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#   [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
# color: 如果是黑子，color=1，如果是白子，color=2
# flag: 下了几步了。从0步开始。如果程序是黑子，那么flag的值依次为：0 2 4 6 8 10
def decide(board, color, flag):
    ts = time.time()
    try:
        if flag == 0: # 如果是第一个下
            return int(ROW/2), int(COL/2)
        elif flag == 1: # 如果是第二个下
            i = 0
            for line in board:
                j = 0
                for e in line:
                    if e != 0:
                        [x, y] = secondstep(i, j)
                        return x, y
                    j += 1
                i += 1
            return 0, 0
        else:
            node = MGTNode(board, color, DEPTH)
            alpha_beta(node) # 调用极大极小值搜索（有alpha-beta剪枝）
            ret = node.pos_x, node.pos_y

    except:
        ret = 0, 0
        for x in range(ROW):
            for y in range(COL):
                if board[x][y] == SPACE:
                    ret = x, y
                break
            break
    print ("ai play:", ret)
    tm = time.time() - ts
    print ("time_cost:", tm)
    if tm > 20:
        print ("board:", board)
        print ("color:", color)
    return ret