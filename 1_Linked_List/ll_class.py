# Linked list class - basic structure
# the LL class  - unordered list (add  - : append, pop, insert, index) 

# the node class
class Node:
	def __init__(self, data=None):
		self.data = data
		self.next = None
	
	def getData(self):
		return self.data
	
	def getNext(self):
		return self.next
	
	def setData(self, newdata):
		self.data = newdata
	
	def setNext(self, newnext):
		self.next = newnext
	
	def __str__(self):
		return str(self.data)
		
# linked list class - unordered and ordered		
class LinkedList:
	def __init__(self, head=None):   #contains length of the list and ref for head node 
		self.head = head
	
	# check if list is empty ------- O(1)
	def isEmpty(self):
		return self.head == None
	
	# add element to the unordered list ------ O(1)
	def add(self, item):
		tmp = Node(item)
		tmp.setNext(self.head)
		self.head = tmp
	
	'''
	# add element to the ordered list ---------- O(n)
	def add(self, item):
		current = self.head
		previous = None
		stop = False
		while current != None and not stop:
			if current.getData() > item:
				stop = True
			else:
				previous = current
				current = current.getNext()
		 
		tmp = Node(item)
		if previous == None:
			tmp.setNext(self.head)
			self.head = tmp
		else:
			tmp.setNext(current)
			previous.setNext(tmp)
	'''	
	
	# length of the list ------------ O(n)
	def size(self):
		current = self.head
		count = 0
		while current != None:
			count += 1
			current = current.getNext()
		return count
	
	# search an element in unordered list ------- O(n)
	def search(self, item):
		current = self.head
		found = False
		while current != None and not found:
			if current.getData() == item:
				found = True
			else:
				current = current.getNext()
		return found
	
	'''	
	# search element in ordered list ---------- O(n)
	def search_ordered(self, item):
		current = self.head
		found = False
		stop = False    # stop when the node data is greater than the item
		while current != None and not found and not stop:
			if current.getData() == item:
				found = True
			else:
				if current.getData() > item:
					stop = True
				else:
					current = current.getNext()
		return found
	'''
	
	# remove element from unordered list --------- O(n)
	def remove(self, item):
		current  = self.head
		previous = None
		found = False
		while not found:
			if current.getData() == item:
				found = True
			else:
				previous = current            # previous should move ahead first , then current : 'inch-warming'
				current = current.getNext()
		
		if previous == None:                  # check if first node is getting removed
			self.head = current.getNext()
		else:
			previous.setNext(current.getNext())
				
			
mylist = LinkedList()
mylist.add(31)
mylist.add(13)
mylist.add(54)
mylist.add(26)
mylist.add(76)
mylist.add(88)
mylist.add(28)

print (mylist.size())
print (mylist.search(88))

mylist.remove(76)
print (mylist.size())
