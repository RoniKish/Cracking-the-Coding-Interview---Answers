public class min_heap_layout {

    Node rootNode;

    public min_heap_layout() {
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

    public void preOrderTraversal(Node currentNode) {
        if (currentNode != null) {
            System.out.println(currentNode.value);
            preOrderTraversal(currentNode.leftChild);
            preOrderTraversal(currentNode.rightChild);
        }
    }

    public static void main(String[] args) {
        min_heap_layout minHeap = new min_heap_layout();


    }

}