from pathNode import pathNode
reverse = 0
class path:

    def __init__ (self):
    
       self.n = 0
       self.root = None
       reverse = 0

   # Get current number of elements in the list
    def getSize(self):
        if self.root == None:  return 0
        else:  return self.root.getSize()

    def tree(self):
       self.treeAux(self.root, 0)

    def treeAux(self, v, indent):
         if v == None:  
            print ' ' * 3 * indent + '*'
         else:
            if v.getParent() == None:  parentKey = ''
            else:  parentKey = v.getParent().getKey() 
            if v.getRight(reverse) != None:
              self.treeAux(v.getRight(reverse), indent+1)
            print ' ' * 3 * indent + str(v.getKey()) + ':' + str(v.getSize()) + ':' + str(parentKey)
            if v.getLeft(reverse) != None:
              self.treeAux(v.getLeft(reverse), indent+1)
    
    def naiveInsert(self, key, position):
        self.n = self.n + 1
        if self.n == 1:
           self.root = pathNode(None, key, None, 1, None)
        else:
           self.naiveInsertAux(self.root, key, position)

    def naiveInsertAux(self, v, key, position):
        v.setSize(v.getSize() + 1)
        leftSize = p.getNodeSize(v.getLeft(reverse))

        if leftSize == 0 and position <= 1:
           v.setLeft(pathNode(None, key, None, 1, v), reverse)  
        elif position <= leftSize + 1:  
          self.naiveInsertAux(v.getLeft(reverse), key, position)
        elif p.getNodeSize(v.getRight(reverse)) == 0 and position > leftSize+1:
           v.setRight(pathNode(None, key, None, 1, v), reverse)
        else:
           self.naiveInsertAux(v.getRight(reverse), key, position - (leftSize + 1))    
    
    def findNode(self, position):
        if self.getSize() == 0:  return None
        else:  
           if position < 1:  position = 1
           elif position > self.getSize():  position = self.getSize()
           return self.findNodeAux(self.root, position)

    def findNodeAux(self, v, position):
        leftSize = p.getNodeSize(v.getLeft(reverse))
        if leftSize == 0 and position <= 1:
           return v
        elif position == leftSize + 1:
           return v.getLeft(reverse)
        elif position < leftSize + 1:    
           self.findNodeAux(v.getLeft(reverse), position)
           return v.getLeft(reverse)
        elif position > leftSize+1:
           self.findNodeAux(v.getRight(reverse),position-(leftSize+1))
           return v.getRight(reverse)

if __name__ == '__main__':
    p = path()
    p.naiveInsert(10,1)
    p.naiveInsert(7,1)
    p.naiveInsert(3,1)
    p.naiveInsert(15,4) 
    p.naiveInsert(105,5)
    p.naiveInsert(103,5)
    p.naiveInsert(107,7)
    p.naiveInsert(4,2)
    p.naiveInsert(8,4)
    p.naiveInsert(2,1)
    p.naiveInsert(12,7)
    