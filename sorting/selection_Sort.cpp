class solution {
 public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        
        for(int j=0;j<arr.size();j++){
           int min=arr[j];
           int ind=j;
            for(int i=j+1;i<arr.size();i++){
            if(min>arr[i]){
                min=arr[i];
                ind =i;
            }
        }
        swap(arr[j],arr[ind]);
      }
      
    }
};
