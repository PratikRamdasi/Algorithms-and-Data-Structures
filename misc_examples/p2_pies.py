'''
Author - Pratik Ramdasi

Date - 05/ 30/ 2016

'''

### Problem Statement -
	# Given the list of pies and number of slices in each pie, 
	# calculate max number of slices that n people 
	# could receive if each person got the same amount of slices 
	# and did not get slices from more than 1 pie.

from itertools import izip
import operator

# generate factors of a number
def factors(n):  
    fac = []
    for i in range(1,n+1):
        if n % i == 0:
           fac.append(i)
    return fac
    
# assume given distribution of slices 
pieSlices = ['one', 8,'two', 6, 'three', 12, 'four', 16]
i = iter(pieSlices)
d = dict(izip(i,i)) 
nPeople = input("Enter number of people:") 
slices = d.values()
print "slices for each pie: ",slices
slicesMax = min(slices) 
listFac=factors(slicesMax)
print "List of all possible slices per person: ", listFac

# find out max number of slices people would get
diffArray = []
for i in listFac:
    val_list = [slices[idx]/i for idx in range(len(slices))]
    #print val_list
    s = 0
    for i in range(0, len(val_list)):
       s += val_list[i]
    #print "sum is: ", s
    if (s - nPeople) >= 0: 
        diff = (s - nPeople)
        diffArray.append(diff)
        
#print diffArray
min_index, min_value = min(enumerate(diffArray), key=operator.itemgetter(1))
maxSlices = listFac[min_index] # max slices per person 
print "Max number of slices per person is: ", maxSlices

    
        
        
    




 
