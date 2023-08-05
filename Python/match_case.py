option = int(input("Enter a number: "))

match option:

    case 0:
        print("option is zero")
    
    case 1:
        if(option %2 == 0): print("x is divisible")
        else: print("x is not divisible")
        print("x is number: ", option)

    case 2 if(option %2 == 0):
        print("we can also use match with condition statements")
    
    case _:
        print("This is default case.")