import random

masterArray = []

for i in range(6):
    masterArray.append(str(random.randint(0,9)))

masterArray = ['1', '2', '4', '3', '2', '2']

def newGuess():
    print("guess, you scrub")
    guessedArray = list(input())

    white = 0
    red = 0
    popped = 0

    for i,x in enumerate(guessedArray):
        if(i>=6):
            print("too many numbers guessed, guess truncated after 6 values")
            guessedArray.insert(i, 'TRUNCATED')
            break

        for j,y in enumerate(masterArray):
            if (x==y) & (i == j):
                red += 1
                break
            elif (x==y) | (y==x):
                white += 1
                break
            else:
                continue


    print("white is", white)
    print("red is", red, "")
    print(guessedArray)
    print(masterArray)
    newGuess()

newGuess()

