
import random

file = open("Dane.txt", "w")

N = random.randint(1,50)


file.write(str(N**2) + ' ')
for i in range((N**2)-1):
    file.write(str(random.randint(0,2500)) + ' ')

file.close()



