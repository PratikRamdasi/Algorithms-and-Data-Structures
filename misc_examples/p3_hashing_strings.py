'''
Author - Pratik Ramdasi

Date - 06/ 01/ 2016

'''
### Problem Statement  - Given multiple strings like "candy","carry", "dummy", etc.
	# These strings are stored as c3y, c3y and d3y etc.
	# Write a function which returns a boolean if the string is unique 
	# to the dictionary
	# if the strings are in a file and you load it when the program loads, 
	# How will you store it?

# hash function method
def hash(astring):
    sum = 0
    for pos in range(len(astring)):
        sum += ord(astring[pos])* pos # weighted sum of chars to solve anagrams problem
    return sum
# method to find if the given string is unique 
# to the dictionary and if yes, then store it
def isUniqueDictionaryWord(d, string):
    currVal = hash(string)  
    for val in d.values():
        if (currVal == val):
            return False
    newDict[string] = currVal
    return True

# define the dictionary and store hash values into the new dictionary
d = {'candy': 'c3y' ,'carry': 'c3y' ,'dummy': 'd3y'}
newDict = {}
for key in d.keys():
    h = hash(key)
    newDict[key] = h

# Testing on several strings     
print isUniqueDictionaryWord(newDict, 'dummy')
print isUniqueDictionaryWord(newDict, 'cathy') 
print isUniqueDictionaryWord(newDict, 'camry') 
print isUniqueDictionaryWord(newDict, 'carry')
print isUniqueDictionaryWord(newDict, 'Pratik') 

# solving anagram problem  
print isUniqueDictionaryWord(newDict, 'macry') 
# storing unique word into dictionary and check the output
'''
print "Original Dictionary: ", newDict 
print isUniqueDictionaryWord(newDict, 'canopy')
print "After Addition of unique word: ", newDict
print isUniqueDictionaryWord(newDict, 'canopy')
'''
