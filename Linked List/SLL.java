// Singly Linear Linked List
class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL
{
    private node first;    
    private int iCount;

    public SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        this.iCount++;
    }

    public void DeleteFirst()
    {
        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
            System.gc();
        }
        else
        {
            this.first = this.first.next;
            System.gc();
        }
        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
            System.gc();
        }
        else
        {
            temp = this.first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
            System.gc();
        }
        this.iCount--;
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" | -> ");
            temp = temp.next;
        }
        System.out.println("null");

    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        node temp = null;
        node newn = null;

        int iCnt = 0;

        if((pos<1) || (pos>iCount+1))
        {
            System.out.println("Invalid Position\n");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount+1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new node(no);

            temp = this.first;

            for(iCnt=1; iCnt<pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;  

            this.iCount++; 
        }
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        node target = null;

        int iCnt = 0;

        if((pos<1) || (pos>iCount))
        {
            System.out.println("Invalid Position\n");
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt=1; iCnt<pos-1; iCnt++)
            {
                temp = temp.next;
            }
            target = temp.next;

            temp.next = target.next;
            System.gc();

            this.iCount--;
        }
    }

}

class SLL
{
    public static void main(String A[])
    {
        int iRet = 0;

        SinglyLL obj = null;

        obj = new SinglyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are: "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are: "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are: "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are: "+iRet);

        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are: "+iRet);

        obj.DeleteAtPos(4);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of nodes are: "+iRet);

    }
}