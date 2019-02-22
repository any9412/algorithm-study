#!/usr/bin/env python3

"""
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree.


Example 1:

Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]
Example 2:

Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
Output: [null,3,4,[1,2,3,4,5,6,7,8]]


Note:

The initial given tree is complete and contains between 1 and 1000 nodes.
CBTInserter.insert is called at most 10000 times per test case.
Every value of a given or inserted node is between 0 and 5000.
"""


class CBTInserter:
    def __init__(self, root: 'TreeNode'):
        t = [root]
        self.root = root
        self.tree = []
        while t:
            tmpNode = t.pop(0)
            if not tmpNode.left or not tmpNode.right:
                self.tree.append(tmpNode)
            if tmpNode.left:
                t.append(tmpNode.left)
            if tmpNode.right:
                t.append(tmpNode.right)

    def insert(self, v: 'int') -> 'int':
        self.tree.append(TreeNode(v))
        parentNode = self.tree[0]
        if not parentNode.left:
            parentNode.left = self.tree[-1]
        else:
            parentNode.right = self.tree[-1]
            self.tree.pop(0)
        return parentNode.val

    def get_root(self) -> 'TreeNode':
        return self.root


def main():
    # testcase 1
    # inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
    root_node = TreeNode(0)
    tree = root_node.create_tree([1])
    obj = CBTInserter(tree)
    print(obj.insert(2))
    print(obj.get_root())

    # testcase 2
    # inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
    root_node = TreeNode(0)
    tree = root_node.create_tree([1,2,3,4,5,6])
    obj = CBTInserter(tree)
    print(obj.insert(7))
    print(obj.insert(8))
    print(obj.get_root())


if __name__ == '__main__':
    main()
