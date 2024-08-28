#!/usr/bin/env python3

import random as rand
import matplotlib.pyplot as plt
from subprocess import run

def worstcase(Nums, lim):
    worst = [rand.randint(-lim, lim)]
    for i in range(Nums - 1):
        n = rand.randint(-lim, lim)
        while ((abs(worst[i] - n) < lim/3) or (n in worst)):
            n = rand.randint(-lim, lim)
        worst.append(n)
    return(worst)


def worstcase2(Nums, lim):
    worst = [rand.randint(-lim, lim)]
    for i in range(Nums - 1):
        n = rand.randint(-lim, lim)
        while (n in worst):
            n = rand.randint(-lim, lim )
        worst.append(n)
    return(worst)


def anothercase(Nums, lim):
    randlst = []
    for i in range(int(Nums/2)):
        n = Nums/2 - i
        randlst.append(n)
    for i in range(int(Nums/2)):
        n = rand.randint(-lim, lim)
        while (n in randlst):
            n = rand.randint(-lim, lim )
        randlst.append(n)
    return (randlst)


def testrun():
    '''Single test run with plotting.'''
    # lim = rand.randint(0, 13412883)
    # rands = worstcase(100, lim)
    rands = worstcase2(500, 1000)
    # rands = bestcase(100)
    # print(f"rands:\n{rands}\n")
    args = [str(x) for x in rands]
    cmd = './push_swap'
    for x in args:
        cmd += f" {x}"
    cmd += ' | wc -l'
    # print(cmd)
    out = run(cmd, shell=True, capture_output=True, text=True)
    print(out.stdout)
    if (int(out.stdout.rstrip()) > 5500):
        plt.hist(rands, 100)
        plt.show()


def testrun_loop(lstlen, lim=1000, rand_func=worstcase2, runs=5000):
    '''
    Good for testing other people's stuff.
    @param lstlen Length of number list to be sorted.
    @param lim Upper / lower boundary for random numbers to be generated.
    @param rand_func Random number generation function to be used.
    '''
    moves_sum = 0
    for i in range(runs):
        rands = rand_func(lstlen, lim)
        args = [str(x) for x in rands]
        cmd = '../push_swap'
        for x in args:
            cmd += f" {x}"
        cmd += ' | wc -l'
        out = run(cmd, shell=True, capture_output=True, text=True)
        numofmoves = int(out.stdout.rstrip())
        print(numofmoves)
        moves_sum += numofmoves
        if (lstlen == 500 and numofmoves > 5500):
            print(f"Num of moves > 5500 for 500 Numbers: numofmoves = {numofmoves}")
            print(f"cmd:\n{cmd}")
            input()
        if (lstlen == 100 and numofmoves > 700):
            print(f"Num of moves > 700 for 100 Numbers: numofmoves = {numofmoves}")
            print(f"cmd:\n{cmd}")
            input()
    print(f"lstlen = {lstlen}, avg moves = {moves_sum/runs}")


def testrun_benchmark(runs=300, bin='../push_swap', rands_func=worstcase2):
    '''
    Well, this is obviously good for benchmarking.
    @param runs Number of loops for every list len.
    @param bin Binary to run
    @param rands_func Function to use for random number generation.
    '''
    print(f"::: bin = {bin}, runs = {runs} :::")
    for Nums in [10, 50, 100, 200, 300, 500]:
        moves_sum = 0
        for i in range(runs):
            rands = rands_func(Nums, 10*Nums)
            args = [str(x) for x in rands]
            cmd1 = bin
            for x in args:
                cmd1 += f" {x}"
            cmd1 += ' | wc -l'
            out1 = run(cmd1, shell=True, capture_output=True, text=True)
            moves_sum += int(out1.stdout.rstrip())
        print(f"Nums = {Nums}, avg moves = {moves_sum/runs}")


if __name__ == "__main__":
    # testrun_loop(lstlen=500, runs=200)
    testrun_benchmark(runs=500, bin='../push_swap')
    # testrun_benchmark(runs=300, bin='./mcomb')
