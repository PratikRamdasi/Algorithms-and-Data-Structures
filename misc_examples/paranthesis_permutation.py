'''
Author - Pratik Ramdasi

Date - 4/ 5/ 2017

Title - Permutations of Paranthesis
'''

### Problem Statement - Print all possible n pairs of balanced parantheses.

results = []
num = 0

def print_parantheses(left, right):
	global num
	global results 
	# when left is equal to right =  0, print the results
	if left == 0 and right == 0:
		print results
		return
	# pos is the next position for printing parantheses
	pos = num - left - right
	if (left > 0):
		results[pos] = '('
		print_parantheses(left-1, right)

	if (left < right):
		results[pos] = ')'
		print_parantheses(left, right-1)
	
def print_all_permutations(n):
	global num
	global results
	num = n * 2
	results = [None] * num
	print_parantheses(n, n)

n = 3
print_all_permutations(n)
