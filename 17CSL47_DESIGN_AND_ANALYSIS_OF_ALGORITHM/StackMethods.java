/*
Program 1 (b):
Write a Java program to implement the Stack using arrays.
Write Push(), Pop(), and display() methods to demonstrate its working.

*/
import java.util.Scanner;
public class StackMethods {
    int top;
    int size;
    int[] stack ;
    public StackMethods(int arraySize)
    {
        size=arraySize;
        stack= new int[size];
        top=-1;
    }
    public void push(int value)
    {
        if(top==size-1)
        {
            System.out.println("Stack is full, can't push a value");
        }
        else
        {
            top=top+1;
            stack[top]=value;
        }
    }
    public int pop()
    {
        int t=0;
        if(top==-1)
        {
            System.out.println("Can't pop...stack is empty");
            return -1;
        }
        else
        {
            t=top--;
            return stack[t];
        }
    }
    public void display()
    {
        for(int i=top;i>=0;i--)
        {
            System.out.print(stack[i]+" ");
        }
        System.out.println("\n");
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Stack operations\n");
        System.out.println("Enter Size of Stack ");
        int n = in.nextInt();
        int choice ;
        /* Creating object of class arrayStack */
        StackMethods stk = new StackMethods(n);
        /* Perform Stack Operations */
        do{
            System.out.println("\nStack Operations");
            System.out.println("1. push");
            System.out.println("2. pop");
            System.out.println("3. display");
            System.out.println("Enter the choice");
            int ch = in.nextInt();
            switch (ch)
            {
                case 1 : System.out.println("Enter element to push");
                    stk.push( in.nextInt() );
                    break;
                case 2 :int s=stk.pop();
                    if (s!=-1)
                        System.out.println("Popped Element = " + s);
                    break;
                case 3 :stk.display();
                    break;
            }
            System.out.println("Do you want to continue press 0/1");
            choice=in.nextInt();
        }
        while(choice==1);
    }
}
/*
Output :
Stack operations

Enter Size of Stack
4

Stack Operations
1. push
2. pop
3. display
Enter the choice
1
Enter element to push
11
Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
1
Enter element to push
12
Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
1
Enter element to push
13
Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
1
Enter element to push
14
Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
1
Enter element to push
15
Stack is full, can't push a value
Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
3
14 13 12 11

Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
2
Popped Element = 14
Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
2
Popped Element = 13
Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
2
Popped Element = 12
Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
2
Popped Element = 11
Do you want to continue press 0/1
1

Stack Operations
1. push
2. pop
3. display
Enter the choice
2
Can't pop...stack is empty
Do you want to continue press 0/1
0
 */