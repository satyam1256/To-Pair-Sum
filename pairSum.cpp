#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int pairSum(int *ar, int start, int end, int num)
{
    int count=0;
    while(start < end)
    {
        if((ar[start] + ar[end]) < num) {
            start++;
        }
        else if(ar[start] + ar[end] > num) {
            end--;
        }
        else{
            int elementatstart=ar[start];
            int elementatend=ar[end];
            if(elementatstart==elementatend)
            {
                int temp =end-start+1;
                count+=(temp*(temp-1))/2;
                return count;
            }
            int tempstartindex=start+1;
            int tempendindex=end-1;
            while((tempstartindex <= tempendindex) && ar[tempstartindex]==elementatstart) {
                tempstartindex++;
            }
            while((tempendindex >= tempstartindex) && ar[tempendindex]==elementatend) {
                tempendindex--;
            }
            int totalstartelements=tempstartindex-start;
            int totalendelements=end-tempendindex;
            count+=totalstartelements * totalendelements;
            start=tempstartindex;
            end=tempendindex;
        }
    }
    return count;
}
int main()
{	
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;

	return 0;
}
