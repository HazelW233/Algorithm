#include<iostream>

void swap(int nums[], int l, int r){
    int temp=nums[l];
    nums[l]=nums[r];
    nums[r]=temp; 
}

void QuickSort(int nums[], int left, int right){
    if(left<right){
        int e=nums[right];
        int l=left;
        int r=right;
        while(l<r){
            while(nums[l]<=e&&l<r)
                l++;
            while(nums[r]>=e&&l<r)
                r--;
            if(l<r)
                swap(nums,l,r);
        }
        swap(nums,l,right);
        QuickSort(nums,left,l-1);
        QuickSort(nums,l+1,right);
    }
}

/*
quick sort
input:要进行排序的数组
output:按非递减形式排序好的数组
*/
void QuickSort(int &nums[],int n){
    int n=sizeof(nums)/sizeof(nums[0]);
    QuickSort(nums, 0, n-1);
}

int main(){
    int nums[]={82,53,-3,-52,92,3,-5,24,2};
    int n=sizeof(nums)/sizeof(nums[0]);
    QuickSort(nums);
    for(int i=0; i<n; i++){
        std::cout<<nums[i]<<" ";
    }
    std::cout<<std::endl;
}
