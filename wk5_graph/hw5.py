class Solution:
    # 1971. Find if Path Exists in Graph
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        from collections import defaultdict
        if source == destination:
            return True
        connection_dict = defaultdict(list)
        for edge in edges:
            connection_dict[edge[0]].append(edge[1])
            connection_dict[edge[1]].append(edge[0])
        
        connected = set(connection_dict[source])
        visited = set()
        while True:
            new_set = set()
            for x in connected:
                if x == destination:
                    return True
                if x not in visited:
                    visited.add(x)
                    for y in connection_dict[x]:
                        new_set.add(y)
            if len(new_set) == 0:
                break
            else:
                connected = new_set
        return False
    # 997. Find the Town Judge
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trust_array = [0] * n
        for x, y in trust:
            trust_array[x - 1] -= 1
            trust_array[y - 1] += 1
        for i, x in enumerate(trust_array):
            if x == n - 1:
                return i + 1
        return -1


        from collections import defaultdict
        possible_judge = defaultdict(list)
        possible_non_judge = defaultdict(list)
        for x, y in trust:
            possible_judge[y].append(x)
            possible_non_judge[x].append(y)
        for i in range(n):
            if len(possible_judge[i + 1]) == n - 1 and len(possible_non_judge[i + 1]) == 0:
                return i + 1
        return -1
    # 1129. Shortest Path with Alternating Colors
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        from collections import defaultdict, deque
        graph = defaultdict(list)
        for x, y in redEdges:
            graph[x].append((y, 'r'))
        for x, y in blueEdges:
            graph[x].append((y, 'b'))

        res = [-1] * n
        queue = deque([(0, 0, None)])
        visited = set()

        while queue:
            node, dist, prev_edge = queue.popleft()
            visited.add((node, prev_edge))
            if res[node] == -1:
                res[node] = dist
            for neighbour, edge in graph[node]:
                if (neighbour, edge) not in visited and prev_edge != edge:
                    queue.append((neighbour, dist + 1, edge))

        return res


