''' 
Title: Python script for mergesort algorithm
Author: Pratik Ramdasi
'''

# method definition
def mergeSort(list):
    print ("splitting ", list)
    if len(list)>1:
        mid = len(list)//2  
        left = list[:mid]      # left half of the list
        right = list[mid:]     # right half of the list
        mergeSort(left)
        mergeSort(right)       # recursive calls to the function for each of the sublist 
        i = 0
        j = 0
        k = 0
        while i < len(left) and j < len(right):
            if (left[i] < right[j]):
                list[k] = left[i]
                i+=1
            else:
                list[k] = right[j]
                j+=1
            k+=1
                
        while i < len(left):
            list[k] = left[i]
            i+=1
            k+=1
           
        while j < len(right):
            list[k] = right[j]
            j+=1
            k+=1
        
    print ("Merging ",list)
                           
list= [3,4,28,14,45,20,11,6]
mergeSort(list)
               
            
