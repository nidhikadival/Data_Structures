// Singly Circular Linked List
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

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
        
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
        }

        this.last.next = this.first;

        this.iCount++;   
    }

    public void InsertLast(int no)
    {
        node newn = null;

        newn = new node(no);

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.last.next = newn;
            this.last = newn;
        }

        this.last.next = this.first;

        this.iCount++;
    }

    public void DeleteFirst()
    {
        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if (this.first == this.last)
        {
            this.first = null;
            this.last = null;
            System.gc();
        }
        else
        {
            this.first = this.first.next;
            System.gc();
        }
        this.last.next = this.first;

        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if (this.first == this.last)
        {
            this.first = null;
            this.last = null;
            System.gc();
        }
        else
        {
            temp = this.first;

            while(temp.next.next != this.last)
            {
                temp = temp.next;
            }
            this.last = temp.next;
            System.gc();
        }
        this.last.next = this.first;

        this.iCount--;
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

        do
        {
            System.out.print("| "+temp.data+" | -> ");
            temp = temp.next;
        }
        while(temp != this.last.next);

        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }

    void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;

        int iCnt = 0;

        if((pos<1) || (pos>iCount+1))
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos==1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount+1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new node(no);

            temp = this.first;

            for(iCnt=1;iCnt<pos-1;iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            this.iCount++;
        }
    }

    void DeleteAtPos(int pos)
    {
        node temp = null;

        int iCnt = 0;

        if((pos<1) || (pos>iCount))
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos==1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt=1;iCnt<pos-1;iCnt++)
            {
                temp = temp.next;
            }
            
            temp.next = temp.next.next;
            System.gc();
        }
    }

}

class SCL
{
    public static void main(String A[])
    {
        SinglyCL obj = null;

        obj = new SinglyCL();

        int iRet = 0;

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