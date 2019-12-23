//by Arun M
// www.github.com/ArunMurugan78/
//template of min heap written in C++
//
template <class T>
class min_heap
{
private:
  unsigned  size,max_capacity;                      //n for number of nodes
  T *arr;                         //this min heap is implemented using an array
  void swap(unsigned i,unsigned j)//for swapping
  {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  //returns true if min heap invariant is satisfied otherwise returns false
  bool invariant(unsigned i);
  //function to satisfy min heap invariant
  void satisfy_invariant(unsigned i);
public:
  min_heap()                                //default constructor
  {
    size = 0;
    max_capacity = 0;                      //defaultly set n = 0
    arr = nullptr;
  }
  min_heap(unsigned m)
  {
    size = 0;
    arr = new T[m];
    max_capacity = m;                       //allocating memory
  }
  ~min_heap()                               //destructor for deallocating memory
  {
    delete[] arr;
  }
  void insert(T elem);          //for insterting nodes
  int remove(T elem);           //for removing nodes
  void bubble_up(int i);
  void bubble_down(int i);
  void resize(unsigned n);
  T pop(); //removes root node and returns it

  /*this function prints the nodes in ascending order
  That is because popping in min heap continuously removes the nodes in
  ascending order. Note that each time you pop ,you are removing the root node.
  If you want to test it remove this function from comment.Don't forget to
  include iostream for output.
  void printp()
  {
    unsigned m = size;
    for(int i = 0;i<m;i++)
    {
      std::cout<<" "<<pop();
    }
  }
  */

};


template <class T>
T min_heap<T>::pop()
{
  T root = arr[0];  //removes and returns the node
  remove(root);
  return root;
}

template <class T>
bool min_heap<T>::invariant(unsigned i)
{
  unsigned parent_index,child_index1,child_index2;
  //to find index of the parent node if it exist ,if not then storing the
  //current index in parent index
  parent_index = (i<=0)?0:i%2 == 0?(i-2)/2:(i-1)/2;
  //to find index of the child node if it exist ,if not then storing the
  //current index in child index

  //Note that there will be 2 child node for each node in a binary tree
  if(2*i+1<=size-1)
  {
    child_index1 = 2*i+1;
  }
  else child_index1 = i;

  if(2*i+2<=size-1)
  {
    child_index2 = 2*i+2;
  }
  else child_index2  = i;
  //return true if the invariant is satisfied or false if not satisfied
  if((arr[parent_index]<=arr[i])&&(arr[i]<=arr[child_index1])&&(arr[i]<=arr[child_index2]))
  {
    return true;
  }
  else return false;
}

template <class T>
void min_heap<T>::satisfy_invariant(unsigned i)
{
  if(invariant(i))
  {
    return; //if invariant satisfied return
  }
  else
  {
    //find parent and children indices
    unsigned parent_index,child_index1,child_index2;
    parent_index = (i<=0)?0:i%2 == 0?(i-2)/2:(i-1)/2;
    if(2*i+1<=size-1)
    {
      child_index1 = 2*i+1;
    }
    else child_index1 = i;

    if(2*i+2<=size-1)
    {
      child_index2 = 2*i+2;
    }
    else child_index2  = i;
    //bubbling up if parent node's value is greater than children node's value
    if(arr[parent_index]>arr[i])
    {
      bubble_up(i);
    }
    //bubbling down if anyone of the child node's value is lesser than parent node's value
    else if(arr[i]>arr[child_index1] || arr[i]>arr[child_index2])
    {
      bubble_down(i);
    }
    else;
  }
}
template <class T>
int min_heap<T>::remove(T elem)//function for removing a node
{
  if(size>0)
  {
    for(unsigned i =0;i<size;i++)
    {
      if(elem == arr[i])    //finding the required node
      {
        T temp = arr[size-1];
        arr[size-1] = arr[i];
        arr[i] = temp;
        size--;
        if(!invariant(i))
        {
          satisfy_invariant(i);
        }
        return 0;                          //return 0 ,if removing is sucessful
      }
    }
  }
  return -1;
}
template <class T>
void min_heap<T>::resize(unsigned n)
{
  T *temp = new T[n];
//there will bo loss in data if n<size-1
  n  = (n>size)?size:n;//for not to copy node containing garbage value if n>size
  for(unsigned i = 0;i<n;i++)
  {
    temp[i] = arr[i];
  }
  delete[] arr;
  arr = temp;
  max_capacity = n;
}
template <class T>
void min_heap<T>::bubble_up(int i)
{
  if(invariant(i))
  {
    return;
  }
  unsigned parent_index;
  while(i>0 && i<= size-1)
  {//finding the parent node's index
    parent_index = (i<=0)?0:i%2 == 0?(i-2)/2:(i-1)/2;
    if(arr[parent_index]>arr[i])
    {
      swap(parent_index,i);
      i = parent_index;
    }
    else return;
  }
}

template <class T>
void min_heap<T>::bubble_down(int i)
{
  if(invariant(i))
   return;
  else
  {
    while (true)
    {
      if(2*i+1 >= size)
      {
        return;
      }
      else
      {
        unsigned child_index1,child_index2,j;
        if(2*i+1<=size-1)
        {
          child_index1 = 2*i+1;
        }
        else child_index1 = i;

        if(2*i+2<=size-1)
        {
          child_index2 = 2*i+2;
        }
        else child_index2  = i;
        j = arr[child_index1] > arr[child_index2] ?child_index2:child_index1;
        if(arr[i]>arr[j])
        {
          swap(j,i);
          i = j;
        }
        else return;
      }
    }
  }
}


template <class T>
void min_heap<T>::insert(T elem)
{
  if(size<=0)
  {
    arr = new T[2];
    max_capacity = 2;
  }
  if(max_capacity == size)
  {
    resize(2*size);
  }
  arr[size] = elem;
  size++;
  int i  = size-1;
  bubble_up(i);
}
