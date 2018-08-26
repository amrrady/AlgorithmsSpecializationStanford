def getIntLength(v):
    return len(str(abs(v)))


def karatsubaMultiplication(firstNumber, secondNumber):
    
    firstNumberLength = getIntLength(firstNumber);
    secondNumberLength = getIntLength(secondNumber);
    
    maxLength = 0;
    if(firstNumberLength > secondNumberLength):
        maxLength = firstNumberLength
    else:
        maxLength = secondNumberLength
    
    # base case to stop dividing to input data if the numbers is less than 3 digits
    if(maxLength < 2):
        return firstNumber*secondNumber;
    
    dividedLength = (maxLength//2) + (maxLength%2);
    multiplier = pow(10, dividedLength)
    
    # divide the two number into 4 parts .. ex: 4422*6677 then a = 44; b = 22; c = 66; d = 77
    a = firstNumber // multiplier;
    b = firstNumber - (a* multiplier);
    c = secondNumber // multiplier;
    d = secondNumber - (c* multiplier);
    
    # karatsuba terms
    firstTermAC = karatsubaMultiplication(a, c);
    secondTermBD = karatsubaMultiplication(b, d);
    thirdTerm = karatsubaMultiplication((a+b), (c+d));
    
    forthTerm = thirdTerm - secondTermBD - firstTermAC;
    
    # karatsuba equation
    return (firstTermAC * pow(10, dividedLength*2))\
    + secondTermBD\
    + (forthTerm * pow(10, dividedLength))




print("This program will multiply two integers:")
x = int(input("Enter your first number\n"))
y = int(input("Enter your second number\n"))
print("Using karatsuba Multiplication Algorithm:")

answer = karatsubaMultiplication(x,y)

actualAnswer = x*y
print(answer)
print("The Correct answer is:")
print(actualAnswer)