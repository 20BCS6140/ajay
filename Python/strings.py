string = "This is a string." #double-quotes

another_string = 'This is another string.' #single-quote

multiple_line_string = '''This is a mutliple line string
So, you can write as many as lines using this method.
Nw you can write another line also.'''  #Uisng three single quotes for multiple line strings.

string3 = ''

string3.join(string)

string3.join(another_string)
string3 = string+another_string

print("This is joined string: ",string3)

print(*string, sep='')

print(string)

print(len(string))

for i in range(0,len(string)):
    print(string[i], end='', sep='')

print('\n')
for i in string:
    print(i,end='',sep='')