import numpy as np

arr1 = [[1,2],[3,4],[5,6]]
arr2 = [[3,3],[3,3]]

a1 = np.array(arr1)
a2 = np.array(arr2)

print(a1@a2)

ans = [[0] * len(arr2[0]) for _ in range(len(arr1))]
for i in range(len(arr1)):
    for k in range(len(arr2)):
        sum = 0
        for j in range(len(arr1[0])):
            sum += arr1[i][j] * arr2[j][k]
        ans[i][k] = sum
print(ans)
