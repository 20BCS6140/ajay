string = "This is a string." #double-quotes

another_string = 'This is another string.' #single-quote

multiple_line_string = '''This is a mutliple line string
So, you can write as many as lines using this method.
Nw you can write another line also.'''  #Uisng three single quotes for multiple line strings.

print(*string, sep='')

print(string)

print(len(string))

for i in range(0,len(string)):
    print(string[i], end='', sep='')

print('\n')
for i in string:
    print(i,end='',sep='')