/*
 * Design a class in Java which implements the Deque interface. (i.e. Implement your own Double Ended Queue in Java without using any collections)7 methods to be implemented: addFirst(), addLast(), removeFirst(), removeLast(), peekFirst(), peekLast(), size()
 */

import javax.management.RuntimeErrorException;

class MyDeque<E> {

    private class Node {
        private E data;
        private Node next, prev;

        Node(E data) {
            this.data = data;
        }
    }    

    private Node head, tail;
    private int size;

    MyDeque(){
        head = tail = null;
        size = 0;
    }

    void addFirst(E data){

        Node newNode = new Node(data);

        if(head == null){           
            head = tail = newNode;            
        }
        else{
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }

        size++;
    }

    void addLast(E data){
        Node newNode = new Node(data);

        if(head == null){           
            head = tail = newNode;            
        }
        else{
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }

        size++;

    }

    E removeFirst(){
        if(head == null) throw new RuntimeException("Deque is empty");

        E data = head.data;
        head = head.next;

        if(head == null) tail = null;
        else head.prev = null;

        size--;

        return data;
    }

    E removeLast(){
        if(tail == null) throw new RuntimeException("Deque is empty");

        E data = tail.data;
        tail = tail.prev;

        if(tail == null) head = null;
        else tail.next = null;

        size--;

        return data;
    }

    E peekFirst(){
        if(head == null ) throw new RuntimeException("Deque is empty");
        return head.data;
    }

    E peekLast(){
        if(tail == null) throw new RuntimeException("Deque is empty");
        return tail.data;
    }

    int getSize(){
        return size;
    }

    void print(){
        Node temp = head;
        while(temp !=  null){
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public class Deque {
    public static void main(String[] args){
        MyDeque deque = new MyDeque();

        deque.addFirst(1);        
        deque.addLast(2);        
        // deque.removeFirst();
        // deque.removeLast();
        deque.peekFirst();
        deque.peekLast();
        deque.getSize();
    }
}