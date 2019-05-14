#include<stdio.h>
int main()
{
int n,i;
int key =0;
int j,x=0;
float a,b;
printf("\t\t\t\tWelcome To ABS PACKERS AND MOVERS.\n\n");
printf("\t\t\t\tRespecting Fragility since 1999.\n\n");
printf("Please Read the Details Before Proceeding Further.\n\n");
printf("Maximum Permissible Dimension Are As Follows: \n\t WIDTH - 2.3m. \n\t DEPTH - 12m \n\t HEIGHT - 3m.\n\n");
printf("Please Enter the number of Boxes to be Transported : ");
scanf("%d",&n);
float depth[n];
float height[n];
float width[n];
for(i=0;i<n;i++)
{
printf("\nEnter the Width in metre of Box No-%d : ",i+1);
scanf("%f",&width[i]);
if(width[i]>2.3 || width[i]<0)
{
    printf("\n\tEntered value was not in the Specified Range.\n");
    printf("\n\tPlease Re-Enter the Width in metre of Box No-%d : ",i+1);
    scanf("%f",&width[i]);
}
printf("\nEnter the Depth in metre of Box No-%d  : ",i+1);
scanf("%f",&depth[i]);
if(depth[i]>12 || depth[i]<0)
{
   printf("\n\tEntered value was not in the Specified Range.\n");
     printf("\n\tPlease Re-Enter the Depth in metre of Box No-%d  : ",i+1);
scanf("%f",&depth[i]);
}
printf("\nEnter the Height in metre of Box No-%d : ",i+1);
scanf("%f",&height[i]);
if(height[i]>3 || height[i]<0)
{
printf("\n\tEntered value was not in the Specified Range.\n");
      printf("\n\tPlease Re-Enter the Height in metre of Box No-%d  : ",i+1);
     scanf("%f",&height[i]);
}
printf("\n\t\t\t\t\tDimensions Of The Box Have Been Stored.\n");
}
float heightsort[n];
for(i=0;i<n;i++)
{
heightsort[i]=height[i];
}
float basearea[n];
for(i=0;i<n;i++)
{
    basearea[i]=depth[i]*width[i];
}
float temp3,temp4;
	for (i = 0 ; i < ( n - 1 ); i++){
    		for (j= 0 ; j < n - i - 1; j++){
      			if(heightsort[j] < heightsort[j+1]){
        			temp3=heightsort[j];
        			heightsort[j]   = heightsort[j+1];
        			heightsort[j+1] = temp3;
        			temp4=basearea[j];
        			basearea[j]   = basearea[j+1];
        			basearea[j+1] = temp4;
      			}
    		}
  	}
printf("\n\n\nBase Area Of Each Box: \n");
for(i=0;i<n;i++)
{
    printf("\n%f\n",basearea[i]);
}
float cluster[n][n];
float clusterarea[n][n];
for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
{
    cluster[i][j]=0;
    clusterarea[i][j]=0;
}
 }
int sm=0;
for(i=0;i<n;i++)
    {
        a = heightsort[key];
        for(j=key;j<n;j++)
        {
            if(heightsort[j]>=(0.75*a))
            {
                cluster[i][j-x] = heightsort[j];
                clusterarea[i][j-x]= basearea[sm];
                sm++;
            }
            else
            {
                x=j;
                key=j;
                break;
            }
            if(j==(n-1))
            {
                i=n-1;
            }
        }
    }
    printf("\n\n\nCluster Containing Height Elements Of Same Height or Greater 0.75*Layer Height.\n");
  for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%f",cluster[i][j]);
        }
        printf("\n");
    }

printf("\n\n\nCluster Wise Area Initial\n");
 for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%f",clusterarea[i][j]);
        }
        printf("\n");
    }
int k;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            for (k =(j + 1); k < n; ++k)
            {
                if (clusterarea[i][j] < clusterarea[i][k])
                {
                    a = clusterarea[i][j];
                    clusterarea[i][j] = clusterarea[i][k];
                    clusterarea[i][k] = a;
                }
            }
        }
    }
    printf("\n\n\nCluster Wise Base Area Sorted : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%f",clusterarea[i][j]);
        }
        printf("\n");
    }

    int bincount=1;
    float sum;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (clusterarea[i][j]>0)
            {
              sum=sum+clusterarea[i][j];
              if(sum>27.6)
              {   sum=sum-clusterarea[i][j];
                  printf("No Further Boxes Can Be Loaded in Container-%d",bincount);
                  printf("\nTotal Base Area Covered of Container-%d is %f",bincount,sum);
                  sum=clusterarea[i][j];
                  bincount++;
              }
            }
        }
    }
printf("\nTotal Base Area Covered of Container-%d is %f",bincount,sum);

printf("\n\n\t\t\tHence The Total Number Of Containers Needed For Transportation is %d",bincount);
}


/*void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do
            i++;

        while(a[i]<v&&i<=u);

        do
            j--;
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}*/



/*quick_sort(heightsort,0,n-1);
for(i=0;i<n;i++)
{
    printf("\n%d\n",heightsort[i]);
}
int heightdec[n];
for(i=0;i<n;i++)
{
    heightdec[i]=heightsort[n-1-i];
}*/

/*int temp,count,k;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
{
    if(cluster[i][j]!=0)
     {
      temp=cluster[i][j];
      count=0;
      for(k=0;k<n;k++)
      {
          if(temp==height[k])
          {
              clusterarea[i][j]=basearea[k];
              break;
      }
     }
}
}
}
int temp,count,k;
int basearht[n];
for(i=0;i<n;i++)
{
    temp=heightdec[i];
    for(j=0;j<n;j++)
    {
        if(temp==height[j])
        {
        basearht[i]=basearea[j];
        break;
        }
    }
}
count=0;
for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        { if(cluster[i][j]!=0)
        {
         clusterarea[i][j]=basearht[count];
         count++;
        }
        }
    }*/
