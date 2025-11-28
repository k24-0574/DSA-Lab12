#include <iostream>
using namespace std;

int* find(string input,string pattern, int &count){
    int n=input.length(), m=pattern.length();
    int comp = 0;
    int* arr = new int[10];
    count =0;
    for(int i=0;i<n-m;i++){
        comp++;
        int j=0;
        
        while(input[i+j]==pattern[j]){
            j++;
            
            if(j==m){
                arr[count++]=i;
            }
            comp++;
        }
    }

    cout<<"Comparisions: "<<comp<<endl;

    return arr;
}

int main(){
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    int count;
    int*arr = find(text, pattern, count);
    for(int i=0;i<count;i++) cout<<arr[i]<<" ";
    return 0;
}
