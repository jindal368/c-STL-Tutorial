#include <iostream>
using namespace std;
int result =0;
int partition(int arr[] , int p , int q){
    int min=arr[p],index=p;
    for(int i=0;i<q;i++){
        if(arr[i]<min){
            min = arr[i];
            index=i;
        }
    }
    if((index-p+1)*min>result){
        result = (index-p+1)*min;
    }
    return index;
}
void hist(int arr[] , int p , int r){
    int q;
    if(p<r)
    q=partition(arr , p , r);
    hist(arr , p , q);
    hist(arr , q+1 , r);
    
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	   
	    hist(arr ,0 , n);
	    cout<<result<<endl;
	    result =0;
	}
	return 0;
}
