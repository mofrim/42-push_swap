# 42-push_swp
42's push_swap project

Operations:

    sa (swap a): Swap the first 2 elements at the top of stack a.
        Do nothing if there is only one or no elements.
    sb (swap b): Swap the first 2 elements at the top of stack b.
        Do nothing if there is only one or no elements.
    ss : sa and sb at the same time.
    pa (push a): Take the first element at the top of b and put it at the top of a.
        Do nothing if b is empty.
    pb (push b): Take the first element at the top of a and put it at the top of b.
        Do nothing if a is empty.
    ra (rotate a): Shift up all elements of stack a by 1.
        The first element becomes the last one.
    rb (rotate b): Shift up all elements of stack b by 1.
        The first element becomes the last one.
    rr : ra and rb at the same time.
    rra (reverse rotate a): Shift down all elements of stack a by 1.
        The last element becomes the first one.
    rrb (reverse rotate b): Shift down all elements of stack b by 1.
        The last element becomes the first one.

## ideas / init...

One of my first thoughts on how to tackle this problem was: 

    maybe i can just do some distance minimizing. sort all numbers first using
    quicksort and then do something like calculating the distance of every input
    number to its final position. After that try every move and see if the
    overall distance is lowered. the end will be reached if overall distance is
    zero. maybe one can also do this recursively. i mean just branch of after
    every move and do every possible move again so we end up calculatin every
    possible sequence like a superposition of all possible sequences and finally
    filter out the shortest

The second complete and good thought:

    Do a couple of steps until the list is sorted. In every step try every move
    and record the move that reduced the distances the most (maybe even by
    absolute values for only a number of items, i.e. not average). Then do that
    move. In the next step do the same again. Eventually we will reach distance
    zero from sorted state. But is it certain that this will lead to a sorted
    list? Or: How to prove that this is the fastest way?!?

**How to prove what is the fastest way for solving this?**

next idea:

    Push everything to b. than find highest number in b, move to top in b and
    pa. again, again, again. this would be for 4 numbers:
    or.... find lowest number in a, rotate to top, pb, find lowest number in b
    again, rotate to top, pb, until to elems remain in a, if first > than last,
    sa, then pa, pa, pa

    pb, pb, pb



## investigations

 | a | b |
 | - | - |
 | 4 | x |
 | 3 | x |
 | 2 | x |
 | 1 | x |

 1) First sorting approach:
    1. ra -> a = [3,2,1,4]
    2. ra -> a = [2,1,4,3]
    3. sa -> a = [1,2,4,3]
    4. ra -> a = [2,4,3,1]
    5. ra -> a = [4,3,1,2]
    6. sa -> a = [3,4,1,2]
    7. sa -> a = [3,4,1,2]
    8. ra -> a = [4,1,2,3]
    9. ra -> a = [1,2,3,4]

    => 9 moves

 2) 2nd approach:
    1. pb -> a = [3,2,1,x], b = [4,x,x,x]
    2. pb -> a = [2,1,x,x], b = [3,4,x,x]
    3. ss -> a = [1,2,x,x], b = [4,3,x,x]
    4. pa -> a = [4,1,2,x], b = [3,x,x,x]
    5. pa -> a = [3,4,1,2], b = [x,x,x,x]
    6. ra -> a = [4,1,2,3], b = [x,x,x,x]
    7. ra -> a = [1,2,3,4], b = [x,x,x,x]

    => 7 moves

 3) 3rd approach:

    0. a = [4,3,2,1]
    1. sa -> a = [3,4,2,1], b = [x,x,x,x]
    2. ra -> a = [4,2,1,3], b = [x,x,x,x]
    3. ra -> a = [2,1,3,4], b = [x,x,x,x]
    4. sa -> a = [1,2,3,4], b = [x,x,x,x]

    => 4 moves... hmmmmm

 4) sequence 2 swap to arbitrary elements

    0. a = [5,4,3,2,1] -> goal: swap 3 & 2
    1. ra,ra,sa,rra,rra

    more stable: bring first elem to top -> pb, bring 2nd elem to top -> pb,
    sb, pa, pa



