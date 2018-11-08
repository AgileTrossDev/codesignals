def mergeKArrays(arrays):
    firstUnused = []    # index into next unused element in each array
    result = []         # Sorted Array
    n = 0               # Total Length of merged arrays
    for i in range(len(arrays)):  # Initialization
        firstUnused.append(0)
        n += len(arrays[i])
    for i in range(n):
        minIndex = -1
        minValue = 0
        for j in range(len(arrays)):
            if firstUnused[j] < len(arrays[j]):
                if arrays[j][firstUnused[j]] < minValue :
                    minIndex = j
                    minValue = arrays[j][firstUnused[j]]
        result.append(minValue)
        firstUnused[minIndex] += 1
    return result