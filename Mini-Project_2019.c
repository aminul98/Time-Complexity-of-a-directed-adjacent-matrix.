#include <stdio.h>
#include <stdlib.h>

int adj_mat[6000][6000];

time_t t1,t2;
double time;
int t_indegree = 0, t_outdegree = 0;

void main()
{
     printf("\n #A Program to represent a Graph by using an ");
     printf("Adjacency Matrix method \n ");
     printf("\n #Directed Graph :\n");

     dir_graph();
}

int dir_graph()
{
    int n;
    int in_deg, out_deg, i, j;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    t1 = clock();
    read_graph(n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d  ",adj_mat[i][j]);
        }
        printf("\n");
    }

    printf("\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ");

    for (i = 1; i <= n ; i++ )
    {
        in_deg = 0;
        out_deg = 0;

        for ( j = 1 ; j <= n ; j++ )
        {
                if ( adj_mat[j][i] == 1 )
                    in_deg++;
        }
        t_indegree = t_indegree + in_deg;

        for ( j = 1 ; j <= n ; j++ )
            if (adj_mat[i][j] == 1 )
                out_deg++;

        t_outdegree = t_outdegree + out_deg;
        printf("\n\n %5d\t\t\t%d\t\t%d\t\t%d\n\n",i,in_deg,out_deg,in_deg+out_deg);


    }

    printf("Total Out-Degree is: %d\n",t_outdegree);
    printf("Total In-Degree is: %d\n",t_indegree);

    t2 = clock();
    time = (((double)t2 - (double)t1)/1000)*pow(10,9);
    printf(" Time is: %lf ns\n",time);
    return;
}

int read_graph ( int n )
{
    int i, j;

    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
            {
                adj_mat[i][j] = 0;
                continue;
            }

          int ran_val;
          ran_val = rand()%2;
          adj_mat[i][j] = ran_val;
        }
    }
    return;
}
