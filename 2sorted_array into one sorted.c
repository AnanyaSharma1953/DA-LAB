#include<stdio.h>
int main()
{
	int n,m;
	printf("enter size ");
	scanf("%d%d",&n,&m);
	int a[n],b[m];
	int r[n+m];
	printf("1st array:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("2nd array");
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
	int x=0,y=0,z=0;
	while(x!=n||y!=m)
	{
		if(a[x]>b[y])
		{
			r[z++]=b[y++];
		}
		else
			r[z++]=a[x++];
	}
	while (x < n) {
        r[z++] = a[x++];
    }

    // Copy remaining elements from array b
    while (y < m) {
        r[z++] = b[y++];
    }
	for(int i=0;i<n+m;i++)
	{
		printf("%d ",r[i]);
	}
}
