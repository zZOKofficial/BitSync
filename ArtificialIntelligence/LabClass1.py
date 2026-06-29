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
T = (10, 20, 30, 11, 11, 17)
#Can not change anything in touple.
print(T)
print(type(T))

#Set: 
S = {87, 23, 23, 23, 2, 7, 9} 
print(S)
#Does not allow duplicate value, and does not follow any index. 
#No sort, No nothing. Can not modify by indexes. Adding and removing is possible.
S.add(100)
S.remove(9)
#Converting set to list.
L = list(S) 

#Dict:
#D = {'key' : 'value'}
players = {
	'Messi' : 10,
    'Neymar' : 11,
    'Ronaldo' : 7
}
print(players['Messi'])
print(players.get('Neymar'))
players.update({'Paolo Maldini': 2})
players.popitem()
print(players)
players.popitem(Ronaldo)

#Sorting
print("SORTING")
List.sort(reverse= "true")
print(list)

#Graph
graph = {
	'A' : ['B', 'C'],
    'B' : ['D', 'E'],
    'C' : 'F',
    'D' : [],
    'E' : [],
    'F' : []
}
print(graph.values())