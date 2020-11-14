class Node<T>{
    public T data;
    public Node<T> next;
    public Node(){
        next = null;
    }
    public Node(T e){
        data = e;
        next = null;
    }
}
public class LinkList<T extends Comparable>{
    private Node<T> head;
    private int length;

    private void QSort(int left, int right){
        if (left >= right)
            return;
        T pri_key = this.get(left);
        int i = left;
        int j = right;
        while (i < j){
            while (i < j && this.get(j).compareTo(pri_key) >= 0) j--;
            if (i == j)
                break;
            this.set(i, this.get(j));
            i++;
            while (i < j && this.get(i).compareTo(pri_key) <= 0) i++;
            if (i == j)
                break;
            this.set(j, this.get(i));
            j--;
        }
        this.set(i, pri_key);
        QSort(left, i-1);
        QSort(i+1, right);
    }

    public LinkList(){
        head = new Node<>();
        length = 0;
    }
    public boolean push_back(T value){
        Node<T> p = head;
        while (p.next != null) p = p.next;
        p.next = new Node<>(value);
        if (p.next == null)
            return false;
        length++;
        return true;
    }
    public boolean insert(int pos, T value){
        if (pos < 0 || pos > length){
            return false;
        }
        Node<T> p = head;
        while (pos-- != 0 && p != null) p = p.next;
        if (p == null)
            return false;
        Node<T> node = new Node<>(value);
        if (node == null)
            return false;
        node.next = p.next;
        p.next = node;
        length++;
        return true;
    }
    public boolean delete(int pos){
        if (pos < 0 || pos >= length){
            return false;
        }
        Node<T> p = head;
        while (pos-- > 0) p = p.next;
        p.next = p.next.next;
        length--;
        return true;
    }
    public T get(int pos) throws NullPointerException{
        if (pos < 0 || pos >= length){
            throw new NullPointerException();
        }
        Node<T> p = head.next;
        while (pos-- > 0) p = p.next;
        return p.data;
    }
    public boolean set(int pos, T value){
        if (pos < 0 || pos >= length){
            return false;
        }
        Node<T> p = head.next;
        while (pos-- > 0) p = p.next;
        p.data = value;
        return true;
    }
    public void print(){
        Node<T> p = head.next;
        while (p != null) {
            System.out.print(p.data);
            System.out.print(" ");
            p = p.next;
        }
    }
    public void sort(){
        QSort(0, length-1);
    }
    public static void main(String[] args) {
        LinkList<Integer> list = new LinkList<>();
        list.push_back(2);
        list.push_back(1);
        list.push_back(2);
        list.insert(0, 0);
        list.insert(4, -1);
//        list.delete(0);
//        list.delete(3);
        list.set(0, 5);
        System.out.println(list.get(0));
        list.sort();
        list.print();
    }
}