import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Student{
    public int rollNo;
    public String name;

    Student(int rollNo,String name)
    {
        this.rollNo = rollNo;
        this.name = name;
    }
}

class SortByRoll implements Comparator<Student>{
    public int compare(Student st1,Student st2)
    {
        return st1.rollNo - st2.rollNo;
    }
}

class SortByName implements Comparator<Student>{
    public int compare(Student st1,Student st2)
    {
        return st1.name.compareTo(st2.name);
    }
}

class SortArrayList{
    public static void main(String args[])
    {
        ArrayList<Integer> arr = new ArrayList();
        arr.add(10);
        arr.add(2);
        arr.add(32);
        arr.add(9);

        Collections.sort(arr);


        // Using comparator interface to sort in a particular manner
        ArrayList<Student> students = new ArrayList<>();
        students.add(new Student(12,"Akhil"));
        students.add(new Student(2,"Aman"));
        students.add(new Student(1,"Zendaya"));
        students.add(new Student(99,"Zoro"));

        // Print the sorted by roll number ArrayList
        students.sort(new SortByRoll());
        System.out.println("Sorted By RollNo");
        for(Student st:students)
        {
            System.out.println(st.rollNo+" "+st.name);
        }

        // Print the sorted by name ArrayList
        students.sort(new SortByName());
        System.out.println("Sorted By Name");
        for(Student st:students)
        {
            System.out.println(st.name+" "+st.rollNo);
        }
    }
}