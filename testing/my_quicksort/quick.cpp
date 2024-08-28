int count;


int MedianOfThreePartition(int a[],int p, int r) {
    int x=a[p],
	y=a[(r-p)/2+p],
	z=a[r-1],
	i=p-1,
	j=r;

    if (y>x && y<z || y>z && y<x ) 
		x=y;
    else if (z>x && z<y || z>y && z<x ) 
		x=z;
    while (1) {
        do
		{
			j--;
			// count++;
		} while (a[j] > x);
        do  
		{
			i++;
			// count++;
		} while (a[i] < x);
        if  (i < j) 
			swap(&a[i],&a[j]);
        else return j+1;
    }
}

void QuickSortMedian(int a[],int start,int end) {
    int q;
    count++;
    if (end-start<2) return;
    q=MedianOfThreePartition(a,start,end);
    QuickSortMedian(a,start,q);
    QuickSortMedian(a,q,end);
}
