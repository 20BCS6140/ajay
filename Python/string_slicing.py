string = "This is a string." #double-quotes

another_string = 'This is another string.' #single-quote

multiple_line_string = '''This is a mutliple line string
So, you can write as many as lines using this method.
Nw you can write another line also.'''  #Uisng three single quotes for multiple line strings.

#slicing

print("string length: ", len(string))

print(string[:]) #print(string[0:len(string)]) IT WILL PRINT FULL STRING.

print(string[0:]) #print(string[0:len(string)]) INTREPRETER AUTOMATICALLY PRINTS TILL END OF STRING.

print(string[:len(string)]) #print(string[0:len(string)]) INTREPRETER AUTOMATICALLY STARTS PRINTING FROM INDEX 0.

print(string[-1:0])