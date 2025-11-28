#include <iostream>
using namespace std;

int* find(string input,string pattern,int n, int m, int &count){
    int* arr = new int[10];
    count =0;
    for(int i=0;i<n-m;i++){
        int j=0;
        while(input[i+j]==pattern[j]){
            j++;
            if(j==m){
                arr[count++]=i;
            }
        }
    }
    return arr;
}

int main(){
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    int count;
    int*arr = find(text, pattern, text.length(), pattern.length(), count);
    for(int i=0;i<count;i++) cout<<arr[i]<<" ";
    return 0;
}
