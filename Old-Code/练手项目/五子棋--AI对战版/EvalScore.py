# encoding: utf-8

ROW = 15  # 棋盘15行
COL = 15  # 棋盘15列
SPACE = 0  # 空格用0表示
BLACK = 1  # 在棋盘矩阵中，黑子用1表示
WHITE = 2  # 在棋盘矩阵中，白子用2表示

live_score = [0, 1, 10, 100, 1000, 10000]  # 活0:0分；活1:1分；活2：10分；活3:100分；活4:1000分；活5:10000分；
live_jump_score = [0, 0, 6, 60, 800, 900]  # 跳活
half_live_score = [0, 0, 3, 40, 800, 10000]
half_live_jump_score = [0, 0, 2, 35, 700, 800]
dead_score = [0, 0, 0, 0, 0, 10000]  # 死0:0分；死1:0分；死2:0分；死3:0分；死4:0分；死5:10000分；
dead_jump_score = [0, 0, 0, 0, 500, 600]
push_score = [0, 0, 0, 0, 1000, 1000]

def eval_score(node):
    lines = []
    for i in range(0, ROW):  # 所有行的元素 共有15行
        lines.append([node.board[i][j] for j in range(0, COL)])
    for j in range(0, COL):  # 所有列的元素 共有15列
        lines.append([node.board[i][j] for i in range(0, ROW)])

    for i in range(1, ROW - 4):
        lines.append([node.board[x][x - i] for x in range(i, ROW)])  # 对角线（斜率是-1）
        lines.append([node.board[y - i][y] for y in range(i, COL)])  # 对角线（斜率是-1）

    lines.append([node.board[x][x] for x in range(0, ROW)])  # 对角线（斜率是-1）

    for i in range(4, ROW - 1):
        lines.append([node.board[x][i - x] for x in range(i, -1, -1)])  # 对角线（斜率是1）
        lines.append([node.board[x][COL + ROW - x - 2 - i] for x in range(ROW - 1 - i, ROW)])  # 对角线（斜率是1）

    lines.append([node.board[x][ROW - 1 - x] for x in range(0, ROW)])  # 对角线（斜率是1）

    final_score = 0  # 最终分数

    for line in lines:  # 每个方向都考虑进来
        blackScore, whiteScore = evalforline(line)

        if node.color == BLACK:  # 如果程序是黑子
            final_score += blackScore - whiteScore
        else:  # 如果程序是白子
            final_score += whiteScore - blackScore
    return final_score


# 分析每一行 每一列 或每一条对角线
def evalforline(line):
    Score = {BLACK: 0, WHITE: 0}  # 要返回的分数
    step_color = line[0]  # 3个可选值，0/1/2.值为0代表空；值为1表示是黑子；值为2表示是白子；
    block = [[step_color, 1, 0]]  # 统计每种棋子最多连成了几个（至少是1）最后1个值0是默认值，过会儿会修改
    for i in range(1, len(line)):
        if line[i] == step_color:
            block[-1][1] += 1
        else:
            block.append([line[i], 1, 0])
            step_color = line[i]

    new_block = [block[0]]
    index = 1
    while index < len(block) - 1:
        my_color, my_colornum, _ = block[index]
        step_color, step_colornum, _ = block[index - 1]
        next_color, next_colornum, _ = block[index + 1]
        if step_color == next_color and step_color != SPACE and my_color == SPACE \
                and step_colornum < 4 and next_colornum < 4 and my_colornum == 1:
            if new_block[-1][2] == 1:
                new_block.append([my_color, 1, 0])
            else:
                new_block.pop(-1)
            new_block.append([next_color, step_colornum + next_colornum, 1])
            index += 2
        else:
            new_block.append(block[index])
            index += 1
    if index < len(block):
        new_block.append(block[index])

    for i in range(1, len(new_block) - 1):
        my_color, my_colornum, my_flag = new_block[i]
        # print('my_colornum is %s' % (my_colornum))
        step_color, step_colornum, step_flag = new_block[i - 1]
        next_color, next_colornum, new_flag = new_block[i + 1]
        if my_color == SPACE:
            continue
        if my_colornum >= 5 and my_flag == 0:
            Score[my_color] += live_score[5]
        elif step_color == next_color == SPACE:
            if my_flag == 0:
                Score[my_color] += live_score[my_colornum] + push_score[my_colornum]
            else:
                Score[my_color] += live_jump_score[my_colornum] + push_score[my_colornum]
        elif (step_color != next_color) and (step_color == SPACE or next_color == SPACE):
            if my_flag == 0:
                Score[my_color] += half_live_score[my_colornum] + push_score[my_colornum]
            else:
                Score[my_color] += half_live_jump_score[my_colornum] + push_score[my_colornum]
        else:
            if my_flag == 0:
                Score[my_color] += dead_score[my_colornum]
            else:
                Score[my_color] += dead_jump_score[my_colornum] + push_score[my_colornum]

    return Score[BLACK], Score[WHITE]