public class Main {
    public static void main(String[] args){
        LinkedLists.Node root = new LinkedLists.Node(1);
        LinkedLists.Node e1 = new LinkedLists.Node(3);
        root.next = e1;
        LinkedLists.Node e2 = new LinkedLists.Node(2);
        e1.next = e2;
        LinkedLists.Node e3 = new LinkedLists.Node(3);
        e2.next = e3;


        LinkedLists.Node kthLst = LinkedLists.solution2b(root, 2);

        System.out.println(kthLst.data);
    }
}
