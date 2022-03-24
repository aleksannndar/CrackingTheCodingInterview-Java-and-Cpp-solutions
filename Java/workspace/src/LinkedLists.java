import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class LinkedLists {

    static class Node{
        public Node next = null;
        public int data;

        public Node(int d){
            data = d;
        }
    }

    //space O(n), time O(n)
    static void solution1a(Node root){
        Set<Integer> dataSet = new HashSet<>();
        Node previousNode = null;

        while(root != null){
            if(dataSet.contains(root.data)){
                previousNode.next = root.next;
            }
            else{
                dataSet.add(root.data);
                previousNode = root;
            }
            root = root.next;
        }
    }

    //space O(1), time O(n^2)
    static void solution1b(Node root){
        if(root == null || root.next == null)
            return;

        while(root != null){

            Node previousNode = root;
            Node runnerNode = root.next;
            while(runnerNode != null){
                if(root.data == runnerNode.data){
                    previousNode.next = runnerNode.next;
                }else{
                    previousNode = runnerNode;
                }
                runnerNode = runnerNode.next;
            }
            root = root.next;
        }
    }

    //space O(1), time O(n)
    static Node solution2a(Node root, int k){
        int counter = 0;

        Node current = root;
        while(current != null){
            counter++;
            current = current.next;
        }

        int kthLast = counter - k;
        if(kthLast < 0)
            return null;

        current = root;
        while(kthLast > 0){
            kthLast--;
            current = current.next;
        }

        return current;
    }

    //space O(1), time O(n), without list size
    static Node solution2b(Node root, int k){
        if(root == null || k <= 0)
            return null;

        Node runner = root;

        for(int i = 0; i < k; i++){
            if(runner == null){
                return null;
            }
            runner = runner.next;
        }

        Node current = root;
        while(runner != null){
            runner = runner.next;
            current = current.next;
        }
        return current;
    }

    //space O(1), time O(1)
    static void solution3a(Node middle){
        if(middle == null || middle.next == null)
            return;
        middle.data = middle.next.data;
        middle.next = middle.next.next;
    }

    //space O(1), time O(n)
    static Node solution4a(Node root, int x){
        Node leftPartition = null;
        Node rightPartition = null;
        Node lastLeft = null;

        while(root != null){
            Node next = root.next;
            if(root.data < x){
                if(leftPartition == null){
                    leftPartition = root;
                    lastLeft = leftPartition;
                }else{
                    lastLeft.next = root;
                    lastLeft = root;
                }
            }
            else{
                root.next = rightPartition;
                rightPartition = root;
            }
            root = next;
        }

        lastLeft.next = rightPartition;

        return leftPartition;
    }


}
