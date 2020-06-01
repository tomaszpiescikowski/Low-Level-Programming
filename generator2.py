
import random

file = open("struct.txt", "w")

for i in range(200):
    file.write(str(231*i+11111)+ ' ')
    file.write(str(random.random()*random.randint(111,555))+ ' ')
    file.write(str(random.random()*random.randint(111,555))+ ' ')
    file.write(str(random.random()*random.randint(111,555))+ ' ')
    file.write(str(0.0)+ '\n')

file.close()