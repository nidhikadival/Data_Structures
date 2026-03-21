# Done
class Node:
    def __init__(self,value):
        self.data = value
        self.next = None

class SinglyCL:
    # Done 
    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

    # Done 
    def InsertFirst(self,no):
        newn = Node(no)

        # LL is empty
        if((self.first == None) and (self.last == None)):
            self.first = newn
            self.last = newn
        # LL has atleast one node
        else:
            newn.next = self.first
            self.first = newn

        self.last.next = self.first

        self.iCount = self.iCount + 1    

    # Done 
    def InsertLast(self,no):
        newn = Node(no)

        # LL is empty
        if(self.first == None):
            self.first = newn
            self.last = newn
        # LL has atleast one node
        else:
            self.last.next = newn
            self.last = newn 

        self.last.next = self.first    

        self.iCount = self.iCount + 1           

    # Done 
    def InsertAtPos(self,no,pos):
        # Filter
        if(pos<1 or pos>(self.iCount+1)):
            print("Invalid Position")
            return

        if(pos == 1):
            self.InsertFirst(no)
            return
        elif(pos == (self.iCount+1)):
            self.InsertLast(no)
            return  
        else:
            newn = Node(no)
            temp = self.first

            for i in range(1,pos-1):
                temp = temp.next

            newn.next = temp.next
            temp.next = newn 

            self.iCount = self.iCount + 1       

    # Done 
    def DeleteFirst(self):
        if((self.first == None) and (self.last == None)):
            return
        elif(self.first == self.last):
            self.first = None
            self.last = None
        else:
            self.first = self.first.next        

        self.last.next = self.first

        self.iCount = self.iCount - 1    

    # Done 
    def DeleteLast(self):
        # LL is empty
        if((self.first == None) and (self.last == None)):
            return

        # LL has one node
        elif(self.first == self.last):
            self.first = None
            self.last = None

        # LL contains more than one node
        else:
            temp = self.first

            while(temp.next.next != self.last):
                temp = temp.next

            self.last = temp.next

        self.last.next = self.first    

        self.iCount = self.iCount - 1 

    # Done 
    def DeleteAtPos(self,pos):
        # Filter
        if(pos<1 or pos>(self.iCount)):
            print("Invalid Position")
            return

        if(pos == 1):
            self.DeleteFirst()
            return
        elif(pos == (self.iCount)):
            self.DeleteLast()
            return 
        else:
            temp = self.first

            for i in range(1,pos-1):
                temp = temp.next

            temp.next = temp.next.next 

            self.iCount = self.iCount - 1  

    # Done 
    def Display(self):
        temp = self.first

        while(temp != self.last):
            print("| ",temp.data," |->",end = " ")
            temp = temp.next
            
        print("| ",temp.data," |-> None")    

    # Done 
    def Count(self):
        return self.iCount    

def main():
    sobj = SinglyCL()

    sobj.InsertFirst(101)
    sobj.InsertFirst(51)
    sobj.InsertFirst(21)
    sobj.InsertFirst(11)

    print("Elements of the Linked List are : ")
    sobj.Display()

    print("Number of elements in the Linked List are : ",sobj.Count())

    sobj.InsertLast(111)
    sobj.InsertLast(121)
    
    print("Elements of the Linked List are : ")
    sobj.Display()

    print("Number of elements in the Linked List are : ",sobj.Count())

    sobj.InsertAtPos(75,4)
    
    print("Elements of the Linked List are : ")
    sobj.Display()

    print("Number of elements in the Linked List are : ",sobj.Count())

    sobj.DeleteFirst()
    sobj.DeleteFirst()

    print("Elements of the Linked List are : ")
    sobj.Display()

    print("Number of elements in the Linked List are : ",sobj.Count())

    sobj.DeleteLast()

    print("Elements of the Linked List are : ")
    sobj.Display()

    print("Number of elements in the Linked List are : ",sobj.Count())

    sobj.DeleteAtPos(3)
    
    print("Elements of the Linked List are : ")
    sobj.Display()

    print("Number of elements in the Linked List are : ",sobj.Count())


if __name__ == "__main__":
    main()