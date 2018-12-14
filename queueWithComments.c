#include <stdio.h>
#include <stdlib.h>//for malloc()
struct Queue
{
	int front,rear,size;
	unsigned capacity;
	int* array;
};

//a queue memory alloted which is a structure containg 
//size front rear and array info
//capacity
//front//rear//space to array

/*
****************************************
 how is malloc used?

allocate a certain amount of memory 
it will request a block of memory from the heap. 
The operating system will reserve a block of memory 


 malloc statement first looks at the amount of memory available on the heap 
The amount of memory needed for the block 
 			-- in this case, sizeof(int) is 4 bytes. 
 If  not enough memory available, 	
 		returns the address zero ( NULL ).
  Otherwise
	malloc proceeds.
	"allocates" a block 

The system then places into the pointer variable 
******************************************************
*/


// creates queue with fixed capacity
// initialises front rear and size
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
/*
************
on L.H.S struct Queue* to delcare queue-----
on R.H.S  tells malloc function to return a pointer of type struct Queue
************
*/
	queue->capacity = capacity;

/*
***********
queue->capacity
is equivalent to

(*queue).capacity
capacity of the value (stored at d addres q) 
***********
*/

	queue->size=queue->front=0;
	queue->rear = -1;
	//alocating space to array at run time!!!dynaminc!!
	queue->array = (int*)malloc(queue->capacity*sizeof(int));
	return queue;

}

// q full size = capacity!!
int isFull(struct Queue* queue)
{
	return(queue->size == queue->capacity);
}

// empty size =0
int isEmpty(struct Queue* queue)
{
	return(queue->size==0);
}

//adding to queue
//change size and rear
// pass th q and the item
//check if its full
void enqueue(struct Queue* queue,int item)
{
	if (isFull(queue))
		return;
	queue->rear=queue->rear+1;
	queue->array[queue->rear] = item;
	queue->size=queue->size+1;
	printf("%d -> enqueued to queue\n",item );


}

//deleting
//check empty
//size decrease
//front changed
void dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
		return;
	queue->front=queue->front+1;
	queue->size=queue->size-1;
	printf("%d <- dequeued from queue \n",queue->array[queue->front-1] );

}

//to check the front item
int front(struct Queue* queue)
{
	return(queue->array[queue->front]);
}

//to check rear
int rear(struct Queue* queue)
{
	return(queue->array[queue->rear]);
}

// main Driver program to test the above function

int main()

{
	struct Queue* queue1 = createQueue(1000);
	enqueue(queue1,100);
	enqueue(queue1,20);
	enqueue(queue1,10);
	dequeue(queue1);
	return 0;
}