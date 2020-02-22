if __name__ == "__main__":
    n = int(input())
    grph = [0] * 101
    for i in range(1, n+1):
        grph[i] = int(input())
    cnt:int = 0
    discovered:list= [-1] * 101 
    finished:list = [0] * 101
    rpair:list = []
    # find cycle
    def dfs(node):
        global cnt, rpair
        discovered[node] = cnt
        cnt += 1
        if discovered[grph[node]] == -1:
            dfs(grph[node])
        elif finished[grph[node]] == 0:
            rpair += list(range(discovered[grph[node]], cnt))
        finished[node] = 1

    # find all cycle
    def dfs_all():
        ret = []
        for i in range(1, n+1):
            if discovered[i] == -1:
                dfs(i)
        for i in range(1, n+1):
            if discovered[i] in rpair:
                ret.append(i)
        print(len(ret))
        print(*ret, sep='\n')

    dfs_all()
        