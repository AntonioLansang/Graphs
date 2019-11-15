#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>


using namespace std;


struct node
{
        int num;
        node *NextNode;

};

class graph
{
        public:
        //Constructor
                graph(int x);
                void insert(int x, int y);
                void print(int VCount);
        private:
                node **Array;
                node *makenode(int y);
};


graph::graph(int x)
{
        Array=new node*[x+1];

}


struct node *  graph::makenode(int val)
{
        struct node *box;
        box=new node;
        box->num=val;
        box->NextNode=NULL;
        return box;
}

void graph::print(int VCount)
{
        for(int k=1;k<=VCount;k++)
        {
                //Print out current row
                printf("Vertex %d: ", k);
                struct node *end=Array[k];

                while(end!=NULL)
                {
                        printf("%d ", end->num);
                        end=end->NextNode;

                }
                printf("\n");


        }

        return;

}

void graph::insert(int x, int y)
{
        struct node *n=makenode(y);
        struct node *end=Array[x];

//      printf("%d is the value passing in\n", n->num);

        //First time doing each index
        if(Array[x]==NULL)
        {
                Array[x]=n;
                return;
        }


        //Traversing the row
        while(end->NextNode!=NULL)
        {
                end=end->NextNode;
        }

        end->NextNode=n;

//      printf("%d is the now at the end\n", end->num);

        return;
}


int main(int argc, char *argv[])
{

//Formalities in case the user did not provide file/file not exist etc.
        ifstream ifp;

        if(argc !=2)
        {
                cout << "No cmd file provided" << endl;
                return 2;
        }

        ifp.open(argv[1]);
        if ( ! ifp.is_open() )
    {
        cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
        return 3;
     }

//G=(V,E)
        int VCount=0;
        int ECount=0;
        int FirstNum=0;
        int SecondNum=0;

        ifp >> VCount;
        ifp >> ECount;

//Allocating the graph
        graph G(VCount+1);


        for(int k=1;k<=ECount;k++)
        {
                ifp >> FirstNum;
                ifp >> SecondNum;

                G.insert(FirstNum,SecondNum);
                G.insert(SecondNum,FirstNum);
        }


        G.print(VCount);


        return 0;
}
