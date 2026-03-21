# Done
class Node:
    def __init__(self,value):
        self.data = value
        self.next = None
        self.prev = None

class DoublyLL:
    # Done 
    def __init__(self):
        self.first = None
        self.iCount = 0

    # Done 
    def InsertFirst(self,no):
        newn = Node(no)

        # LL is empty
        if(self.first == None):
            self.first = newn
        # LL has atleast one node
        else:
            newn.next = self.first
            self.first.prev = newn
            self.first = newn

        self.iCount = self.iCount + 1    

    # Done 
    def InsertLast(self,no):
        newn = Node(no)

        # LL is empty
        if(self.first == None):
            self.first = newn
        # LL has atleast one node
        else:
            temp = self.first
            while(temp.next != None):
                temp = temp.next
            temp.next = newn 
            newn.prev = temp

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
            temp.next.prev = newn

            temp.next = newn 
            newn.prev = temp

            self.iCount = self.iCount + 1       

    # Done 
    def DeleteFirst(self):
        if(self.first == None):
            return
        elif(self.first.next == None):
            del self.first
            self.first = None    
        else:
            self.first = self.first.next  
            self.first.prev = None  

        self.iCount = self.iCount - 1    

    # Done 
    def DeleteLast(self):
        # LL is empty
        if(self.first == None):
            return

        # LL has one node
        elif(self.first.next == None):
            del self.first
            self.first = None

        # LL contains more than one node
        else:
            temp = self.first

            while(temp.next.next != None):
                temp = temp.next

            del temp.next    
            temp.next = None

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
            del temp.next.prev
            temp.next.prev = temp

            self.iCount = self.iCount - 1  

    # Done 
    def Display(self):
        temp = self.first

        while(temp != None):
            print("| ",temp.data," | <=>",end = " ")
            temp = temp.next

        print("None")    

    # Done 
    def Count(self):
        return self.iCount    

def main():
    sobj = DoublyLL()

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