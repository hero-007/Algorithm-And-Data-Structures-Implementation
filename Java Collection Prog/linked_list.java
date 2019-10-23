import java.util.LinkedList;

class LinkedListTest{
    public static void main(String args[])
    {
        LinkedList<Integer> list = new LinkedList();

        list.add(12);
        list.add(13);
        list.add(14);
        list.add(15);

        int k = list.remove(2);
        System.out.println("Element removed : "+k);
        for(Integer i:list)
        {
            System.out.println(i);
        }


        System.out.println("Size of the list : "+list.size());

        // updating element at index 1
        list.set(1,99);
        System.out.println("Updated list is : ");
        for(Integer i:list)
        {
            System.out.println(i);
        }

    }
}