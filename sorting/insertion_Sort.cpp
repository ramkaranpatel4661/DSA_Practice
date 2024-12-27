class solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        for(int i=0;i<arr.size();i++){
            int j=i;
            while(j!=0){
                if(arr[j-1]>arr[j]){
                    swap(arr[j-1],arr[j]);
                }
                j--;
            }
        }
    }
}