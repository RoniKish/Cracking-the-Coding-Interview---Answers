// Implementing a simple binary tree
public class binary_tree_layout {

    Node rootNode;

    public binary_tree_layout() {
        this.rootNode = null;
    }

    public void add(int value) {
        this.rootNode = addRecursive(this.rootNode, value);
    }

    private Node addRecursive(Node current, int value) {
        if (current == null) {
            return new Node(value);
        }
        if (value <= current.value)
            current.leftChild = addRecursive(current.leftChild, value);
        else
            current.rightChild = addRecursive(current.rightChild, value);

        return current;
    }

    public void inOrderTraversal(Node currentNode) {
        if (currentNode != null) {
            inOrderTraversal(currentNode.leftChild);
            System.out.println(currentNode.value);
            inOrderTraversal(currentNode.rightChild);
        }
    }

    public void preOrderTraversal(Node currentNode) {
        if (currentNode != null) {
            System.out.println(currentNode.value);
            preOrderTraversal(currentNode.leftChild);
            preOrderTraversal(currentNode.rightChild);
        }
    }

    public void postOrderTraversal(Node currentNode) {
        if (currentNode != null) {
            postOrderTraversal(currentNode.leftChild);
            postOrderTraversal(currentNode.rightChild);
            System.out.println(currentNode.value);
        }
    }

    public static void main(String[] args) {
        binary_tree_layout binaryTree = new binary_tree_layout();
        binaryTree.add(5);
        binaryTree.add(1);
        binaryTree.add(10);
        binaryTree.inOrderTraversal(binaryTree.rootNode);
        System.out.println();
        binaryTree.preOrderTraversal(binaryTree.rootNode);
        System.out.println();
        binaryTree.postOrderTraversal(binaryTree.rootNode);
    }
}
