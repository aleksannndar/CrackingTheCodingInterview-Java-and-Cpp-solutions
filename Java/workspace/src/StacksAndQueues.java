import java.util.*;

public class StacksAndQueues {

    class Node<T>{
        T data;
        Node<T> next;

        public Node(T data){
            this.data = data;
        }
    }

    class MyStack<T>{

        Node<T> top;

        public MyStack(){
            top = null;
        }

        public MyStack(T data){
            top = new Node<T>(data);
        }

        public void push(T data){
            Node<T> node = new Node<T>(data);
            node.next = top;
            top = node;
        }

        public T pop(){
            if(top == null) throw new EmptyStackException();
            Node<T> r = top;
            top = top.next;
            return r.data;
        }

        public T peek(){
            return top.data;
        }

        public boolean isEmpty(){
            return top == null ? true : false;
        }
    }

    class MyQueue<T>{

        Node<T> first;
        Node<T> last;

        public MyQueue(){
            first = null;
            last = null;
        }

        public void add(T data){
            Node<T> node = new Node<T>(data);

            if(last != null)
                last.next = node;
            last = node;

            if(first == null)
                first = last;
        }

        public T remove(){
            if(first == null) throw new NoSuchElementException();

            Node<T> node = first;
            first = first.next;
            return node.data;
        }

        public T peek(){
            if(first == null) throw new NoSuchElementException();

            return first.data;
        }

        public boolean isEmpty(){
            return first == null ? true : false;
        }
    }

    //solution 2
    class NodeWithMin{
        int data;
        int min;
        NodeWithMin next;

        public NodeWithMin(int data, int min){
            this.data = data;
            this.min = min;
        }
    }

    public class StackWithMin extends MyStack<NodeWithMin>{
        public StackWithMin(int data){
            int m = Math.min(data, min());
            super.push(new NodeWithMin(data, m));
        }

        int min(){
            if(peek() == null){
                return Integer.MAX_VALUE;
            }else{
                return peek().min;
            }
        }
    }

    public class StackWithMin2 extends MyStack<Integer>{
        MyStack<Integer> minStack;

        public StackWithMin2(){
            minStack = new MyStack<Integer>();
        }

        public int min(){
            if(minStack.isEmpty()){
                return Integer.MAX_VALUE;
            }else{
                return minStack.peek();
            }
        }

        public void push(int data){
            if(data < min()){
                minStack.push(data);
            }
            super.push(data);
        }

        public Integer pop(){
            int data = super.pop();
            if(data == minStack.peek())
                minStack.pop();
            return data;
        }
    }

    public class SetOfStacks{
        List<Stack> stacks = new ArrayList<>();
        int capacity;

        public SetOfStacks(int capacity){
            this.capacity = capacity;
        }

        public void push(int data){
            if(stacks.isEmpty() || stacks.get(stacks.size() - 1).size() == capacity){
                stacks.add(new Stack<Integer>());
            }
            stacks.get(stacks.size() - 1).push(data);
        }

        public int remove(){
            if(stacks.isEmpty())
                throw new EmptyStackException();
            int data = (int) stacks.get(stacks.size() - 1).pop();
            if(stacks.get(stacks.size() -1).isEmpty()){
                stacks.remove(stacks.size() - 1);
            }
            return data;
        }
    }

}
