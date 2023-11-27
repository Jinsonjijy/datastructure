#include<stdio.h>
int size,front,rear;
    struct ab{
        int ITEM,PRIORITY;
    }A[20];
    void enqueue(int item,int priority){
        int i,loc;
        if(front==0 && rear==size-1){
            printf("insertion is not possoble the queue is full");
        }else if(front==-1){
            front=0;
            rear=0;
            A[front].ITEM=item;
            A[front].PRIORITY=priority;
            rear++;

        }else if(rear==size-1){
            for(i=front;i<rear;i++)
            {
                A[i-1]=A[i];
                rear--;
                front--;

            }
            for ( i = rear; i < front; i--)
            {
                if(A[i].PRIORITY<priority){
                    break;
                }
            }
            loc=i+1;
            for(i=loc;i<rear;i++){
                A[i+1]=A[i];
                rear++;
            }
            A[loc].ITEM=item;
            A[loc].PRIORITY=priority;

            
        }else{
            for(i=rear;i<front;i--){
                if(A[i].PRIORITY<priority){
                    break;
                }
                loc=i+1;
            }
            for(i=loc;i<rear;i++){
                A[i+1]=A[i];
            }
            A[loc].ITEM=item;
            A[loc].PRIORITY=priority;
        }
    }
        /// @brief 
        void dq(){
            if(front==-1){
                printf("\nthe queue is empty\n");
            }else{
                printf("the element dequed is\t \n %d\t",A[front].ITEM);
                front++;
            }
        } void ds(){
            int i;
            if(front==-1){
                printf("\nthe queue is empty\n");
            } else{
                for(i=front;i<rear;i++){
                    printf("%d",A[i].ITEM);
                }
            }
        }


    
    void main(){
        int item,priority,opt;
        front=-1;
        rear=-1;
        printf("\n\tenter the size of the queue\n");
        scanf("%d",&size);
        do{
            printf("\n\tenter the option\n");
            printf("\t1 for enqueue \n\t 2 for dequeue \n\t 3 for display\n \t4 for exit");
            scanf("%d",&opt);
            switch (opt)
            {
            case 1:
                printf("enter the item and its priority ");
                scanf("%d%d",&item,&priority);
                enqueue(item,priority);
                break;
            case 2:
                dq();
                break;
            case 3:
                 ds();
            case 4:
                break;

            default:
                printf("enter a valid option");
                break;
            }
        }while(opt!=4);
    }