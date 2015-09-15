#include <iostream>
#include <vector>

using namespace std;

    int findkth(vector<int> &nums1, int st1, vector<int> &nums2, int st2, int k){
         if (st1==nums1.size())
            return nums2[st2+k];
        else if (st2==nums2.size())
            return nums1[st1+k];
        else if (k==0)
            return min(nums1[st1],nums2[st2]);
        int mid1=st1+(k-1)/2<nums1.size()?st1+(k-1)/2:nums1.size()-1;
        int mid2=st2+(k-1)/2<nums2.size()?st2+(k-1)/2:nums2.size()-1;
        if (nums1[mid1]>nums2[mid2])
            return findkth(nums1,st1,nums2,mid2+1,k-mid2+st2-1);
        else //if (nums1[mid1]<nums2[mid2])
            return findkth(nums1,mid1+1,nums2,st2,k-mid1+st1-1);
        //else return nums1[mid1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n,m;
        n=nums1.size();
        m=nums2.size();
        if ((n+m)%2==0)
            return ((double)findkth(nums1,0,nums2,0,(n+m)/2-1)+findkth(nums1,0,nums2,0,(n+m)/2))/2;
        else return findkth(nums1,0,nums2,0,(n+m)/2);
    }

int main(int argc, char const *argv[]) {
    vector<int> nums1;
    vector<int> nums2{2,3};
    nums1.clear();
    cout<<findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}
