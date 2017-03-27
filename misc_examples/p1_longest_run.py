# Given an array, find the longest run of 
# consecutive numbers in it.

arr = input("Enter an array: ")
ind = 0
output = list()
my_index = [(x+1) for x,y in zip(arr, arr[1:]) if y-x != 1]
for index in my_index:
    new = [x for x in arr[ind:] if x < index]
    output.append(new)
    ind += len(new)
output.append([x for x in arr[ind:]])

print "Longest run of consecutive numbers:", max(output, key=len)
print "Length of longest run is: ", max(len(l) for l in output)


        
        
    
    
