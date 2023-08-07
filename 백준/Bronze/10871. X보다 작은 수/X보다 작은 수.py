N, X = input().split() #split input into two

holder = []
holder = input().split(" ")

final = ''
for x in holder:
    if int(x) < int(X):
        final += x + " "

print(final)