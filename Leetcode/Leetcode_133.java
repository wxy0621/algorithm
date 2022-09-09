// 克隆图
// 定义
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

// 哈希记录走过的点
class Solution {
    private HashMap<Node, Node> visited = new HashMap <> ();
    public Node cloneGraph(Node node) {
        if (node == null) return node;
        if (visited.containsKey(node)) return visited.get(node);
        Node res = new Node(node.val);
        visited.put(node, res);
        for (Node neighbor: node.neighbors) {
            res.neighbors.add(cloneGraph(neighbor));
        }
        return res;
    }
}