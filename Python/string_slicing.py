#strings are immutable.

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

print(string[0:-3])  #print(string[0:len(string)-3])


print(string[2:9])  # starts from n+1 and ends at nth position

print(string[-1:-len(string)-1:-1]) # Reverse a string

print(string[::-1]) # Reverse a string

# Methods in strings.

print(string.upper()) #to check if the string is upper or lower we can use isupper()/ islower()

string_upper = "AJAY"

print(string_upper.lower())

string_strip = "   Ajay   " #obj.strip() is sued to remove spaces from before and after string 
print("String before before removing spaces: ",string_strip)
print("String after removing spaces: ", string_strip.strip())

string_rstrip = "ooo my god!!!"  #obj.rstrip("!") is used to remove any trailing characters from string
print("String before removing trailing characters : ",string_rstrip)
print("String after removing trailing characters : ", string_rstrip.rstrip("!"))

string_lstrip  = "#9985313130" #obj.rstrip("#") is used to remove any front characters from string
print("String before removing trailing characters : ",string_lstrip)
print("String after removing trailing characters : ", string_lstrip.lstrip("#"))

string_replace = "oh my god!!!" #replace("","") replaces all the occurances of the chars with another chars
print("String before replacing the characters: ", string_replace)
print("String after replacing the characters: ", string_replace.replace("oh", "aha"))

string_split = string.split("s") #converts a string into a list 
string_split1 = string.split(" ") #converts a string into a list 

print(string_split)
print(string_split1)

string_captalize = "mY nAme iS aJaY" #to check this we can use istitle()
print(string_captalize.capitalize()) # captalize() converts first char of string to upper and all other chars to lower

string_count = multiple_line_string.count("m") #count the number of coccurances of a char in string
print(string_count)

string_check_endswith = "oh my god!!!" #check if a string is ending with given string
print(string_check_endswith.endswith("!"))
print(string_check_endswith.endswith("a")) 

print(string_check_endswith.endswith("my",2,5)) # we can also check in between string by providing the indexes.


print(string_check_endswith.find("o")) #retruns first occurance of string or eles return -1
print(string_check_endswith.find("z"))

#we can also use startswith() for the same case

print(string_check_endswith.index("my")) # returns index or else error

string_username = "gajula21ajay " 

print(string_username.isalnum()) #returns true if string conatins numbers and alphabets, No symbols and no white spaces
print(string_username.isalpha()) # returns true if string contains only alphabets
print(string_username.isnumeric()) # returns true if string conatins only numbers

is_space="    "
print(is_space.isspace())

is_printable = "Ajay\n" #\n \t \v these kind of things are not printable. so, returns false
print(is_printable.isprintable())






