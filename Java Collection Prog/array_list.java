import java.util.ArrayList;
import java.util.Iterator;

class ArrayL{
    public static void main(String args[])
    {
        // Creating an ArrayList
        ArrayList<String> arr1 = new ArrayList();
        ArrayList<String> arr2 = new ArrayList(4);  // define the capacity of the list

        // Adding elements to arr1
        arr1.add("akhil");
        arr1.add("raman");
        arr1.add("shanu");


        // Adding elements to arr2
        arr2.add(0,"akhil");
        arr2.add(1,"raman");
        arr2.add(2,"shanu");
        arr2.add(3,"ayush");

        // printing the size of arr1
        System.out.println("Size of arr1 : "+arr1.size());


        // Iterating over arr1 and arr2 different methods

        // 1 - using Iterator interface
        Iterator itr = arr1.iterator();
        while(itr.hasNext())
        {
            System.out.println(itr.next());
        }

        // 2 - using for-each loop
        System.out.println("Using for-each loop");
        for(String s:arr2)
        {
            System.out.println(s);
        }

        // 3 - using for loop
        System.out.println("using for loop");
        for(int i=0;i<arr2.size();i++)
        {
            System.out.println(arr2.get(i));
        }

        // changing the element of arr1 
        arr1.set(0,"keshav");
        System.out.println("using for loop");
        for(int i=0;i<arr1.size();i++)
        {
            System.out.println(arr1.get(i));
        }
    }
}