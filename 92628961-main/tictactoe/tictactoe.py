"""
Tic Tac Toe Player
"""

import math
import copy

X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    X_kiekis = 0
    O_kiekis = 0

    for row in range(len(board)):
        for col in range(len(board[row])):
            if board[row][col] == X:
                X_kiekis += 1
            if board[row][col] == O:
                O_kiekis += 1

    if X_kiekis > O_kiekis:
        return O
    else:
        return X


def actions(board):
    """
     """
    possible_actions = set()
    for row in range(len(board)):
        for col in range(len(board[row])):
            if board[row][col] == EMPTY:
                possible_actions.add((row, col))
    return possible_actions


def result(board, action):
    """
    Returns the new board that results from making a move in the given action.
    """
    if action not in actions(board):
        raise Exception("Invalid action")

    NewBoard = copy.deepcopy(board)
    row, col = action
    NewBoard[row][col] = player(board)

    return NewBoard

def checkRow(board, player):
    for row in range(len(board)):
        if board[row][0] == player and board[row][1] == player and board[row][2] == player:
            return True
    return False

def checkColumn(board, player):
    for col in range(len(board)):
        if board[0][col] == player and board[1][col] == player and board[2][col] == player:
            return True
    return False

def checkDiagonals(board, player):
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return True
    return False


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    for player in [X, O]:
        if checkRow(board, player) or checkColumn(board, player) or checkDiagonals(board, player):
            return player
    return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    return winner(board) is not None or all(board[i][j] != EMPTY for i in range(3) for j in range(3))


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    winner_symbol = winner(board)
    if winner_symbol == X:
        return 1
    elif winner_symbol == O:
        return -1
    else:
        return 0


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    def max_value(board):
        if terminal(board):
            return utility(board)

        v = -math.inf
        for action in actions(board):
            v = max(v, min_value(result(board, action)))
        return v

    def min_value(board):
        if terminal(board):
            return utility(board)

        v = math.inf
        for action in actions(board):
            v = min(v, max_value(result(board, action)))
        return v

    if terminal(board):
        return None

    current_player = player(board)

    if current_player == X:
        optimal_value = -math.inf
        optimal_action = None
        for action in actions(board):
            value = min_value(result(board, action))
            if value > optimal_value:
                optimal_value = value
                optimal_action = action
        return optimal_action
    else:
        optimal_value = math.inf
        optimal_action = None
        for action in actions(board):
            value = max_value(result(board, action))
            if value < optimal_value:
                optimal_value = value
                optimal_action = action
        return optimal_action
