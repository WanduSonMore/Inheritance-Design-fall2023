def factorial(number): 
    # print(number)
    if number == 1:
        print(number)
        return 1
    else:
        return factorial(number - 1) * number
    
print(factorial(4))