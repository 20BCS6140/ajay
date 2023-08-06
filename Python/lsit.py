lst = [5,10,4,2,3,10]

lst.append(1)

print(lst)

# lst.reverse()

# lst.sort()

# lst.sirt(reversed == True)



print(lst.index(10)) # throws an error if element not found

print(lst.count(10)) # returns no. of occurance of the element

reference_lst = lst # reference_lst is pointing to the lst, it is not making another copy

reference_lst[1] = 100
print(lst)

copied_lst = lst.copy() #it will make another copy of the list
print(copied_lst)

another_list = [100,200,300]

reference_lst.extend(another_list)
print(reference_lst)

reference_lst.extend([1000])
print(reference_lst)