class solution {
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        for(int i=arr.size()-1;i>=0;i--){
            bool swapping=false;
            for(int j=0;j<i;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapping=true;
                }
            }
            if(!swapping){
                break ;
            }
        }
    }
};