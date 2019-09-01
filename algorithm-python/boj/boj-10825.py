from collections import namedtuple

n = int(input())
Student = namedtuple('Student', ['name', 'kr', 'en', 'mth'])  # same as temporary class
slist = []
for _ in range(n):
    name, kr, en, mth = input().split(' ')
    slist.append(Student(name,int(kr),int(en),int(mth)))

slist = sorted(sorted(sorted(sorted(slist, key=lambda one:one.name), key=lambda one:one.mth, reverse=True), key=lambda one:one.en), key=lambda one:one.kr, reverse=True)
for s in slist:
    print(s.name)

