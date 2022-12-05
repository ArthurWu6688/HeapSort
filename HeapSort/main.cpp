#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct{
    ElemType *array;
    int length;
}OrderTable;

void InitTable(OrderTable &OT,int len){
    OT.length=len;
    OT.array=(ElemType*)malloc(sizeof(ElemType)*OT.length);
    srand(time(NULL));
    for(int i=0;i<OT.length;++i){
        OT.array[i]=rand()%100;
    }
}

void PrintTable(OrderTable OT){
    for(int i=0;i<OT.length;++i) {
        printf("%3d", OT.array[i]);
    }
    printf("\n");
}

void swap(ElemType &a,ElemType &b){
    ElemType temp;
    temp=a;
    a=b;
    b=temp;
}

//将某个子树调整为大根堆的函数
void AdjustDown(ElemType *arr,int SubtreeNum,int len){
    int dad=SubtreeNum;//父亲的下标
    int son=2*dad+1;//左孩子的下标
    while(son<len){
        if(son+1<len&&arr[son+1]>arr[son]){//看下有没有右孩子，左右孩子选最大的
            ++son;
        }
        if(arr[son]>arr[dad]){//比较孩子和父亲，如果孩子大于父亲则交换
            swap(arr[son],arr[dad]);
            dad=son;//孩子重新作为父亲，判断下一棵子树是否符合大根堆
            son=2*dad+1;
        }else{
            break;
        }
    }
}

void HeapSort(ElemType *arr,int len){
    int i;
    for(i=len/2-1;i>=0;--i){
        //调整为大根堆
        AdjustDown(arr,i,len);
    }
    swap(arr[0],arr[len-1]);//交换顶部和数组最后一个元素
    for(i=len-1;i>1;--i){
        AdjustDown(arr,0,i);//剩下的元素调整为大根堆
        swap(arr[0],arr[i-1]);
    }
}

int main(){
    OrderTable OT;
    InitTable(OT,10);
    PrintTable(OT);

    HeapSort(OT.array,OT.length);
    PrintTable(OT);

    return 0;
}