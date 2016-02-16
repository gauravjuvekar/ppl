#!/usr/bin/env python3
# Golfing for the fun of it
print('\n'.join(['{:^80}'.format(x)for x in['*']+[' '.join('*'*x)for x in range(3,int(input("Enter depth: "))+2)]]))
