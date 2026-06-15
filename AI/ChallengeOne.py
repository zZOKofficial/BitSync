#1. Display name of the month using Match-Case
month = int (input("Enter a month in numeric number: "))
match (month):
    case 1:
        print("January")
    case 2:
        print("February")
    case 3:
        print("March")
    case 4:
        print("April")
    case 5:
        print("May")
    case 6:
        print("June")
    case 7:
        print("July")
    case 8:
        print("August")
    case 9:
        print("September")
    case 10:
        print("October")
    case 11:
        print("Novermber")
    case 12:
        print("December")
    case _:
        print("Invalid month number!")

#2. Calculate factorial of a given number
factorial = int (input("Enter a number to get the factorial: "))
result = 1
for i in range(1, factorial, 1):
    result = result*i

print (result)

#3. Find largest element in a given list of integer
#Descending sort and print first element? Or for loop and temp value with swap condition?
List = [90, 50, 10, 60, 20, 100, 30, 70, 40, 80]
List.sort(reverse="true")
print("Largest number in the list: ", List[0])

#4. Leap year
#Basic leap year, need to add the conditions for the century later after checking information!
print("--LEAP YEAR CHECKER--")
LeapYear = int(input("Enter a year: "))
if ((LeapYear%4) == 0):
    print("That is a leap year!")
else:
    print("Not leap year.")