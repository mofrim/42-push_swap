# 42-push_swp

42's push_swap project

## Current Status

I got stuck using my array-approach. In principle it should be possible to
solve this exercise also using the array-approach. But right now i am lacking
the right idea to do it.

Rewriting everything with linked lists will cost a lot of time. Plus, having
read mcombeau's solution i strongly have the feeling i really do not want to
copy-implement stuff according to her solution after putting so much work into
it.

Conclusion: i think i have to keep going with my approach and somehow,
hopefully in an elegant way make it meet the requirements.


## Operations:

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

another one:

    bring max to top. until min is 2 under max do sa ra. then 1x sa. and max is
    sorted. now take max-1. bring max-1 to top. do sa ra until max is 2 under
    max-1. one time sa. and finished.
    ... BUT!!! a quicker version might be: take whatever is at the top of the
    stack. say this is x_i in sorted stack. do sa ra or sa rra until x_i+1 is 2
    under x_i. 1 more time sa. and x_i is sorted relative to x_i+1. repeat this
    for whatever is at the top of the stack.

but maybe:

    ..it takes less operations to just move x_i to top -> pb -> ra until x_i+1
    is at top -> pa, move x_i+1 to top -> pb -> move x_i+2 to top -> and so
    on...

bus_sort:

    The idea: scan for an area where we have elems in stack-a that would
    need shifting in the same direction. Then, start ra'ing and pb'ing. stack-b
    functions like a bus where the elements wait until it is time to drop
    them of. in every block, ra or rra to the element with the highest shift
    needed.
 
    until we reach the first position where one of the elems should be
    dropped of. this would...
 
    damn. i slowly get the feeling that working with linked lists here would be
    much more convenient. with the lists we could save for every list item its
    position in the final sorted list, its distance from that position, ...

### the strategy approach

okay. let's call it `the strategies approach`. from the beginning the goal
is to fill stack b with the reversely sorted stack in order to push that
back to stack a. at every instance we have a couple of strategies, say 4
different ones:

1. ra or rra stack a until min is at top -> pb to put it on top of stack b,
    do the same for min+1 & min+2
2. ra or rra stack a until min+1 is at top -> pb, then, ra or rra until min
    is at top -> pb -> sb
3. ra / rra stack a until min+2 is top -> pb, ra / rra until min+1 is top ->
    pb, ra / rra until min is top -> pb. at this moment stack_b looks like
    this [min, min+1, min+2, min-1,...]. correct order would be: [min+2,
    min+1, min, min-1,...] => sort it: sb, rb, sb, rrb, sb - voilá.

now for every strategy the number of moves is counted. the one with the
least number of moves will be executed. this also means we have to deal with
the stack sizes 1 and 2 seperately because this only works for stacks >= 3



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

 5) oh man, i really need progress here

    0. a = [5,4,3,2,1]
    00. `rra`: a = [1,5,4,3,2]
    1. bring min to top: `rra` a = [1,5,4,3,2]
    2. `pb`: a = [5,4,3,2] b = [1]

 6) last try

    a =     [5,3, 1,4, 2], sortd = [1,2,3,4,5] =>
    dists = [4,1,-2,0,-3]

## 2 halves sort approach

What to do with this?

    a[ 0] =  35, dst =  -7   ||   b[ 0] =   3, dst =  -8
    a[ 1] =  22, dst =   1   ||   b[ 1] =   4, dst =  -6
    a[ 2] =  33, dst =  -4   ||   b[ 2] =  13, dst =   0
    a[ 3] =  37, dst =  -5   ||   b[ 3] =  16, dst =   3
    a[ 4] =  39, dst =  -5   ||   b[ 4] =   2, dst =  -5
    a[ 5] =  25, dst =   3   ||   b[ 5] =  11, dst =   1
    a[ 6] =  23, dst =   5   ||   b[ 6] =  10, dst =   1
    a[ 7] =  27, dst =   4   ||   b[ 7] =  15, dst =   6
    a[ 8] =  32, dst =   3   ||   b[ 8] =  12, dst =   5
    a[ 9] =  28, dst =   5   ||   b[ 9] =   7, dst =   3

0) after every initial push to b check if b->size >2 { if a[0] > a[1] && b[0] <
   b[1] } and do a ss. this does a little presorting.
1) Calc dists differently: f.ex. a[0] in the above table should not have dst -7
   but +2. the current code:

    ```c
    (*st)->dsts[i] = i - indexof_long((*st)->st[i], sortd, size);

    ```

    should be:

    ```c
    dst = i - indexof_long(...);
    if (ft_abs(dst) > size - ft_abs(dst))
        dst = size - ft_abs(dst);
         
    ```
2) swap_sort?!?!?

