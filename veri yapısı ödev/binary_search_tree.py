class Node(object):
    def __init__(self, val):
        self.sol = None
        self.sag = None
        self.val = val

class BST(object):
    def __init__(self):
        self.root = None

    def eleman_ekleme(self, val):
        new_node = Node(val)
        if self.root is None:
            self.root = new_node
            return
        current_node = self.root
        while True:
            if val < current_node.val:
                if current_node.sol is None:
                    current_node.sol = new_node
                    return
                current_node = current_node.sol
            else:
                if current_node.sag is None:
                    current_node.sag = new_node
                    return
                current_node = current_node.sag

    def arama(self, val):
        current_node = self.root
        while current_node is not None:
            if val == current_node.val:
                print("value is in the tree")
                return True
            elif val < current_node.val:
                current_node = current_node.sol
            else:
                current_node = current_node.sag
        print("value is not in the tree")
        return False

tree = BST()
root = None
nums = list(range(1,1000001))
for num in nums:
    root = tree.eleman_ekleme( num)
t = int(input('Enter the key to be searched:\t'))
tree.arama(t)
import time
st = time.time()
time.sleep(1)
et = time.time()
elapsed_time = et - st
print('Execution time:', elapsed_time, 'seconds')