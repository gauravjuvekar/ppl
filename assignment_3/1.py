#!/usr/bin/env python3

s = set()
for r in input("Enter ranges\n").split(','):
    if '-' in r:
        lo, hi = map(int, r.strip().split('-'))
        s |= set(range(lo, hi + 1))
    else:
        s.add(int(r))
print(set(range(1, int(input("Enter total pages: ")) + 1)) - s)
