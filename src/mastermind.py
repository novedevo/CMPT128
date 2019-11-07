import random as r

masterArray = []

for i in range(6):
    masterArray.append(str(r.randint(0,9)))

masterArray = ['1', '2', '4', '3', '2', '2']

def newGuess():
    print("guess, you scrub")
    guessedArray = list(input())

    white = 0
    red = 0
    #print(len(masterArray))
    for i,x in enumerate(guessedArray):
        for j,y in enumerate(masterArray):
            while(i>=4):    #FIXME #TODO: tf tf tf
                guessedArray.pop()
                i-=1
                #break
            #print (x,y,i,j)
            #if x == y:
                #print("")
            if (x==y) & (i == j):
                red += 1
                #print("red")
                break
            elif (x==y) | (y==x):
                white += 1
                #print ("white")
                
                #print(i,j)
                break
            else:
                continue

    print("white is", white)
    print("red is", red, "")
    print(guessedArray)
    print(masterArray)
    newGuess()


newGuess()

