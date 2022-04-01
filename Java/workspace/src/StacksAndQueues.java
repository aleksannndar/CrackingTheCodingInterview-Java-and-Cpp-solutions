import java.util.EmptyStackException;
import java.util.NoSuchElementException;

public class StacksAndQueues {

    class MyStack<T>{
        class StackNode<T>{
            T data;
            StackNode<T> next;

            public StackNode(T data){
                this.data = data;
            }
        }

        StackNode<T> top;

        public MyStack(){
            top = null;
        }

        public MyStack(T data){
            top = new StackNode<T>(data);
        }

        public void push(T data){
            StackNode<T> node = new StackNode<T>(data);
            node.next = top;
            top = node;
        }

        public T pop(){
            if(top == null) throw new EmptyStackException();
            StackNode<T> r = top;
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

        class QueueNode<T>{
            T data;
            QueueNode<T> next;

            public QueueNode(T data){
                this.data = data;
            }
        }

        QueueNode<T> first;
        QueueNode<T> last;

        public MyQueue(){
            first = null;
            last = null;
        }

        public void add(T data){
            QueueNode<T> node = new QueueNode<T>(data);

            if(last != null)
                last.next = node;
            last = node;

            if(first == null)
                first = last;
        }

        public T remove(){
            if(first == null) throw new NoSuchElementException();

            QueueNode<T> node = first;
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

    

}
