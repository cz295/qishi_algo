class Solution:
    # 1644. Lowest Common Ancestor of a Binary Tree II
    def lowestCommonAncestor(self, root1: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def dfs(root, path, x):
            if root is None:
                return False
            path.append(root)
            if root.val == x.val:
                return True
            if dfs(root.left, path, x) or dfs(root.right, path, x):
                return True
            path.pop(-1)
            return False
        path_p = []
        path_q = []
        if (not dfs(root1, path_p, p)) or (not dfs(root1, path_q, q)):
            return None
        for i in range(min(len(path_p), len(path_q))):
            if path_q[i] != path_p[i]:
                return path_p[i - 1]
        return path_p[i]

    # 1197. Minimum Knight Moves
    def minKnightMoves(self, x: int, y: int) -> int:
        from collections import deque
        visited = set((0, 0))
        next_step = [
            (dx, dy) for dx in (-2, -1, 1, 2) for dy in (-2, -1, 1, 2) if abs(dx) != abs(dy)
        ]
        curr_level = deque([(0, 0)])
        steps = 0
        while(curr_level):
            curr_length = len(curr_level)
            #print(curr_level, curr_length, steps)
            for i in range(curr_length):
                node = curr_level.popleft()
                if (node[0] == x) and (node[1] == y):
                    return steps
                visited.add(node)
                for dx, dy in next_step:
                    if (node[0] + dx, node[1] + dy) not in visited:
                        visited.add((node[0] + dx, node[1] + dy))
                        curr_level.append((node[0] + dx, node[1] + dy))
            steps += 1
            #print(curr_level)
        return steps

    # 79. Word Search
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        visited = set()
        def bfs(word_str, i, j):
            # print(word_str, i, j, visited)
            if len(word_str) == 0:
                return True
            if word_str[0] != board[i][j]:
                return False
            else:
                visited.add((i, j))
                if len(word_str[1:]) == 0:
                    return True
                for dx, dy in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                    if -1 < i + dx < m and  -1 < j + dy < n:
                        if (i + dx, j + dy) not in visited and bfs(word_str[1:], i + dx, j + dy):
                            return True
                visited.remove((i, j))
                return False

        for i in range(m):
            for j in range(n):
                if bfs(word, i, j):
                    return True
        return False

    # 110. Balanced Binary Tree
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(root):
            if root is None:
                return True, 0
            else:
                left_flag, left_depth = dfs(root.left)
                right_flag, right_depth = dfs(root.right)
                curr_depth = max(left_depth, right_depth) + 1
                if left_flag and right_flag and abs(left_depth - right_depth) <= 1:
                    return True, curr_depth
                else:
                    return False, curr_depth
        return dfs(root)[0]
    #207. Course Schedule
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        from collections import defaultdict
        pre_dict = defaultdict(list)
        for x, y in prerequisites:
            pre_dict[x].append(y)

        visited = [0] * numCourses

        def is_cycle(course):
            if visited[course] == 1:
                return True
            if visited[course] == 2:
                return False
            visited[course] = 1
            for prerequisite in pre_dict[course]:
                if is_cycle(prerequisite):
                    return True
            visited[course] = 2
            return False
        for course in range(numCourses):
            if is_cycle(course):
                return False

        return True


