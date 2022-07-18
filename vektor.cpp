#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>

#define arrsize(x) (sizeof(x)/sizeof(*x))

typedef struct vektor {
  int* array;
  int size;
  int capacity;
} vektor;

int* vektor_begin(vektor* pvektor){
  return pvektor->array;
}
int* vektor_end(vektor* pvektor){
  return (pvektor->array)+pvektor->size;
}

void vektor_sizer(vektor* pvektor, int change){
  while (pvektor->size+change >= pvektor->capacity){
    pvektor->array = (int*) reallocarray(pvektor->array,pvektor->capacity*2,sizeof(int));
    pvektor->capacity *= 2;
    return;
  }
  while (pvektor->size+change <= pvektor->capacity/4){
    pvektor->array = (int*) reallocarray(pvektor->array,pvektor->capacity/2,sizeof(int));
    pvektor->capacity /= 2;
    return;
  }

}


void vektor_init(vektor* pvektor, int* values=0,int values_size=0)
{
  pvektor->array = (int *) malloc(sizeof(int)*16);
  pvektor->size = 0;
  pvektor->capacity = 16;
  if (values){
    vektor_sizer(pvektor,values_size);
    for (int i=0;i<values_size;i++)
    {
      pvektor->array[pvektor->size]=values[i];
      pvektor->size += 1;
    }
  }
}

int vektor_size(vektor* pvektor)
{
  return pvektor->size;
}
int vektor_capacity(vektor* pvektor)
{
  return pvektor->capacity;
}
int vektor_is_empty(vektor* pvektor)
{
  return pvektor->size==0;
}
int vektor_at(vektor* pvektor,int i)
{
  if (i>=0 && i<pvektor->size)
    return pvektor->array[i];
  return -1;
}
void vektor_insert(vektor* pvektor,int n, int i)
{
  if (i>=0 && i<=pvektor->size){
    for (int shift=pvektor->size;shift>i;shift--)
      pvektor->array[shift] = pvektor->array[shift-1];
    pvektor->array[i]=n;
    vektor_sizer(pvektor, 1);
    pvektor->size+=1;
  }
}
void vektor_prepend(vektor* pvektor, int n)
{
  vektor_insert(pvektor,n,0);
}
std::vector<int> tasd;

void vektor_push_back(vektor* pvektor, int n){
  /* Pişman mıyım , her şey handler fonksiyonu oluşturmamla başladı yapmam gereken şeyi mi yaptım emin değilim. Pişmanlıklarla dolu bir yaşamım oldu umarım bu son olur.
     if (pvektor->size+1 >= pvektor->capacity){
     pvektor->array = (int*) reallocarray(pvektor->array,pvektor->capacity*2,sizeof(int));
     pvektor->capacity *= 2;
     }
     */
  vektor_sizer(pvektor,1);
  pvektor->array[pvektor->size] = n;
  pvektor->size += 1;
}

void vektor_pop_back(vektor* pvektor){
  vektor_sizer(pvektor,-1);
  pvektor->array[pvektor->size] = 0;
  pvektor->size -= 1;
}

void vektor_delete(vektor* pvektor, int i){
  if (i>=0 && i<pvektor->size){
    for (;i<pvektor->size;i++)
      pvektor->array[i] = pvektor->array[i+1];
    vektor_sizer(pvektor,-1);
    pvektor->size-=1;
  }
}

void vektor_remove(vektor* pvektor, int n)
{
  for(int i=0;i<pvektor->size;i++){
    if (i==n)
      vektor_delete(pvektor,i);
  }
}

int vektor_find(vektor* pvektor, int n){
  int i;
  for(i=0;i<pvektor->size;i++){
    if (pvektor->array[i]==n)
      return i;
  }
  return -1;
}


int main (int argc, char *argv[])
{
  vektor vec;
  vektor* gos=&vec;
  int array[] = {1,2,3,4,1,2,3,2};
  vektor_init(gos,array,arrsize(array));
  return 0;
}
