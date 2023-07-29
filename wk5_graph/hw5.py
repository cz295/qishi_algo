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
    # 2359. Find Closest Node to Given Two Nodes
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        from collections import deque

        def get_dist_to_node(node):
            dist_to_node = {node: 0}
            queue = deque([node])
            while queue:
                curr_node = queue.popleft()
                next_node = edges[curr_node]
                if next_node == -1:
                    return dist_to_node
                if next_node in dist_to_node:
                    return dist_to_node
                dist_to_node[next_node] = dist_to_node[curr_node] + 1
                queue.append(next_node)
            return dist_to_node
                

        dist_to_node1 = get_dist_to_node(node1)
        dist_to_node2 = get_dist_to_node(node2)
        min_val = -1
        min_index = -1

        for key in dist_to_node1:
            if key in dist_to_node2:
                curr_dist = max(dist_to_node1[key], dist_to_node2[key])
                if min_val == -1:
                    min_val = curr_dist
                    min_index = key
                else:
                    if min_val >= curr_dist:
                        if min_val > curr_dist:
                            min_index = key
                            min_val = curr_dist
                        else:
                            min_index = min(key, min_index)

                    
        return min_index
        
    
    # 2246. Longest Path With Different Adjacent Characters
    def longestPath(self, parent: List[int], s: str) -> int:

        from collections import defaultdict
        n = len(parent)
        from collections import defaultdict
        node_to_neighbour = defaultdict(list)
        for i in range(1, n):
            node_to_neighbour[parent[i]].append(i)

        def dfs(node):
            max_val = max_leg1 = max_leg2 = 0
            for nbr in node_to_neighbour[node]:
                leg, val = dfs(nbr)
                if s[nbr] == s[node]:
                    leg = 0
                if leg > max_leg1:
                    max_leg2, max_leg1 = max_leg1, leg
                elif leg > max_leg2:
                    max_leg2 = leg
                max_val = max(max_val, val)
            max_val = max(max_val, max_leg1 + max_leg2 + 1)
            return max_leg1 + 1, max_val
        return dfs(0)[1]

    # 2421. Number of Good Paths
   def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        from collections import defaultdict
        node_to_neighbour = defaultdict(list)
        for x, y in edges:
            node_to_neighbour[x].append(y)
            node_to_neighbour[y].append(x)

        val_map = defaultdict(list)
        for i, val in enumerate(vals):
            val_map[val].append(i)
        
        uf = UnionFind(len(vals))
        n = 0

        for val in sorted(val_map.keys()):
            for node in val_map[val]:
                for nbr in node_to_neighbour[node]:
                    if vals[node] >= vals[nbr]:
                        uf.union(node, nbr)
            count = defaultdict(int)
            for node in val_map[val]:
                root = uf.find(node)
                count[root] += 1
                n += count[root]
        return n

class UnionFind:
    def __init__(self, n):
        self.root = [i for i in range(n)]

    def union(self, a, b):
        ra = self.find(a)
        rb = self.find(b)
        self.root[ra] = self.root[rb] = min(ra, rb)

    def find(self, node):
        if node == self.root[node]:
            return node
        return self.find(self.root[node])

