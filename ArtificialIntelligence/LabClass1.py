print("SWITCH CASE: ")
switch = int(input ("Enter a numnber: ")) #int() converts string to integer, input takes string as a default
match (switch): #match(case(x) / default)
    case 5:
        print(5)
    case 10:
        print(10)
    case 100:
        print(100)
    case _:
        print("This is default")

print("RANGE: ")
ranges = range(1000)
print (ranges)
for i in range(5,101,5): #range(start, stop, step)
    print (i, end = "   ")

#List
print("LIST: ")
List = [10, 20, 10, 50]
print (List)
List.append(0)
print("append")
print(List)

List.pop(0)
print("pop")
print(List)
#Touple

#Set: 

#Dict:

#Sorting
print("SORTING")
List.sort(reverse= "true")
print(list)