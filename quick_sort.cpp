/*Quick sort*/
/*for sorting worst sorting is O(n^2)
for avg. sorting O(nlogn)
*/
/*choose the pivot(any element)
partition(greater than pivot in one array and smaller than array in another array)
 */
#include<iostream>
using namespace std;
//swap function that swaps two numbers
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
//partition function
int partition (int arr[], int low, int high) { 
	//make the number in last index as pivot
	int pivot = arr[high];    
	int i = (low - 1);   
	//first shift all the smaller or equal to the leftside by loop
	for (int j = low; j <= high- 1; j++) { 
		if (arr[j] <= pivot){ 
			i++;    // increment index of smaller element 
	            swap(arr[i], arr[j]); 
	        } 
	} 
	//change the pivot to its correct position
	swap(arr[i + 1], arr[high]); 
	//return the index of pivot
	return (i + 1); 
} 
//print array
void display(int ar[],int n){
	for(int i=0;i<n;i++){
		cout<<ar[i]<<"->";
	}
	cout<<endl;
}
//QS function
void QS(int ar[],int low,int high){
	if(high<=low)
		{return;}
	
	else{
		//call partition function
		cout << "low : " << low << " -- high : " << high << endl;
		int a=partition(ar,low,high);
		cout << "low : " << low << " -- high : " << high << " a : " << a << endl;
		//do recursion
		cout<<ar[a+1]<<"kkk"<<high<<"kkk"<<a+1;
		display(ar,15);QS(ar,low,a-1);
		QS(ar,a+1,high);
		//return;
		
		}
}
//main function
int main(){
	//drfine variables
	int array[]={6,5,8,9,1,2,3,7,100,95,64,73,91,86,1085};
	int n=sizeof(array)/sizeof(array[0]);
	cout<<"The given array is ";
	//print the array
	display(array,n);
	//the number of elements in the array is 6
	//call the QSfunction
	QS(array,0,n-1);
	cout<<"The array after sorted ";
	display(array,n);
	return 0;
}
