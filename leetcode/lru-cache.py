class Node:
    def __init__(self, key, value, left=None, right=None):
        self.left = left
        self.key = key
        self.right = right
        self.value = value
        
class LRUCache:
    # doubly-linked list. hash table
    def __init__(self, capacity: int):
        self.head = Node(None, -1)
        self.tail = Node(None, -1, self.head)
        self.head.right = self.tail
        self.capacity = capacity
        self.map = {}

    def get(self, key: int) -> int:
        if key in self.map:
            node = self.map[key]
            if node.left != self.head:
                # remove
                node.left.right = node.right
                node.right.left = node.left
                # insert
                node.left = self.head
                node.right = self.head.right
                self.head.right.left = node
                self.head.right = node
            
            return node.value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.get(key) != -1:
            self.map[key].value = value
            return
        if len(self.map.keys()) == self.capacity:
            evict_target = self.tail.left
            evict_target.left.right = evict_target.right
            evict_target.right.left = evict_target.left
            del self.map[evict_target.key]
        nNode = Node(key, value, self.head, self.head.right)
        self.head.right.left = nNode
        self.head.right = nNode
        self.map[key] = nNode
