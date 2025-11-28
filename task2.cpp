#include <iostream>
using namespace std;
#define max_Val 256
#define table_size 101
int* find(string input,string pattern, int &count){
    int n=input.length(), m=pattern.length();
    int* arr = new int[10];
    count =0;
    
    if(m==0||m>n){
        cout << "Invalid pattern";
        delete[] arr;
        return arr;
    }

    int p=0;  
    int t=0;
    int h=1;

    for(int i=0;i<m-1;i++) h=(h*max_Val)%table_size;

    for(int i=0; i<m; i++){
        p=(max_Val*p + pattern[i])% table_size;
        t=(max_Val*t + input[i]) %table_size;
    }

    for(int i=0; i <=n-m; i++){
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (input[i + j] != pattern[j]) {
                    match = false;
                    cout<<"\nIncorrect match: ";
                    for(int a=i;a<i+m;a++) cout<<input[a];
                    break;
                }
            }
            if(match)arr[count++] = i;
            
        }

        if (i<n-m) {
            t = (max_Val*(t-input[i]*h) + input[i+m])% table_size;
            if(t<0) t+=table_size;
        }
    }
    return arr;
}

int main(){
    string text = "Data structures and Algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";
    int count;
    int*arr = find(text, pattern, count);
    cout<<endl<<"Matches at: ";
    for(int i=0;i<count;i++) cout<<arr[i]<<" ";
    return 0;
}

