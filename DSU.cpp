int Arr[N], size[N];
 
void initialize(int sz){
    for(int i = 0;i < sz; i++){
		Arr[ i ] = i ;
		size[ i ] = 1;
	}
}
 
int root (int i){
    while(Arr[ i ] != i){
        Arr[i] = Arr[Arr[i]]; 
		i = Arr[i]; 
    }
return i;
}
 
void weighted_union(int A,int B){
    int root_A = root(A);
    int root_B = root(B);
    if(root_A == root_B) return ;
    if(size[root_A] < size[root_B ]){
	Arr[ root_A ] = Arr[root_B];
	size[root_B] += size[root_A];
	}
    else{
	Arr[ root_B ] = Arr[root_A];
	size[root_A] += size[root_B];
	}
}
