things = [1, 2, 9, 5, 6, 4, 3, 7, 0, 1]

print(list(map(lambda x: x * 2, filter(lambda y: y % 2 == 0, things))))

print([x * 2 for x in things if x % 2 == 0])
