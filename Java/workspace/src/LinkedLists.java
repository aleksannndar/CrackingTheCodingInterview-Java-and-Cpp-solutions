import java.util.*;

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

    //space O(n), time O(n), without destroying input lists
    static Node solution5a(Node first, Node second){
        if(first == null)
            return second;

        if(second == null)
            return first;

        Node root = null;
        Node current = root;

        int carry = 0;
        while(first != null && second != null){
            if(current != null) {
                current.next = new Node((first.data + second.data + carry) % 10);
                current = current.next;
            }
            else {
                current = new Node((first.data + second.data + carry) % 10);
            }
            carry = (first.data + second.data + carry) / 10;
            first = first.next;
            second = second.next;
        }

        Node longerList = first == null ? second : first;
        while(longerList != null){
            current.next = new Node((first.data + second.data + carry) % 10);
            current = current.next;
            longerList = longerList.next;
        }
        if(carry > 0){
            current.next = new Node(carry);
        }

        return root;
    }

    //space O(n), time O(n), recursive solution
    static Node solution5b(Node first, Node second, int carry){
        if(first == null && second == null && carry == 0)
            return null;

        Node n = new Node(carry);
        if(first != null)
            n.data += first.data;

        if(second != null)
            n.data += second.data;

        carry = n.data / 10;
        n.data = n.data % 10;

        if(first != null || second != null) {
            first = first == null ? null : first.next;
            second = second == null ? null : second.next;

            Node next = solution5b(first, second, carry);
            n.next = next;
        }

        return n;
    }

    //space O(n), time O(n)
    static boolean solution6a(Node root){
        if(root == null)
            return false;

        Node runner = root;
        Stack<Integer> dataStack = new Stack<>();

        while(runner != null){
            dataStack.push(root.data);
            root = root.next;
            runner = runner.next;
            if(runner == null) {
                dataStack.pop();
                break;
            }
            runner = runner.next;
        }

        while(root != null){
            if(root.data != dataStack.pop())
                return false;
            root = root.next;
        }

        return true;
    }

    //space O(1), time O(n)
    static Node solution7a(Node l1, Node l2){
        if(l1 == null || l2 == null)
            return null;

        Node tmpL1 = l1;
        Node tmpL2 = l2;
        int lengthL1 = 0;
        int lengthL2 = 0;

        while(tmpL1 != null){
            lengthL1++;
            tmpL1 = tmpL1.next;
        }

        while(tmpL2 != null){
            lengthL2++;
            tmpL2 = tmpL2.next;
        }

        Node longer = lengthL1 > lengthL2 ? l1 : l2;
        Node shorter = lengthL1 <= lengthL2 ? l1 : l2;

        for(int i =0; i< Math.abs(lengthL1 - lengthL2); i++){
            longer = longer.next;
        }

        while(longer != null){
            if(longer == shorter)
                return longer;

            longer = longer.next;
            shorter = shorter.next;
        }
        return null;
    }

    //space O(n), time O(n)
    static Node solution8a(Node root){
        if(root == null)
            return null;

        HashSet<Node> nodeAppeared = new HashSet<>();

        while(root != null){
            if(nodeAppeared.contains(root)) {
                return root;
            }
            else{
                nodeAppeared.add(root);
            }
            root = root.next;
        }

        return null;
    }

    //space O(1), time O(n)
    static Node solution8b(Node root){
        Node slow = root;
        Node fast = root;

        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
            if(fast == slow)
                break;
        }

        if(fast == null || fast.next == null)
            return null;

        fast = root;
        while(fast != slow){
            fast = fast.next;
            slow = slow.next;
        }

        return fast;
    }
}
