// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

/*
GIVEMESOMEMONEY
FIND
*/
int main() {

    string message, key;
    int row, column;
    cin>>message>>key;

    int message_length=message.size();
    int key_length=key.size();
    
    //calculate row size and column size
    row=key_length;
    if(message_length%key_length==0) {
        column=ceil(message_length/key_length);
    }
    else column=message_length/key_length+1;
    //cout<<row<<" "<<column<<endl; 
    
    //fill the blank spaces with '*'
    for(int i=0; i<row*column-message.length(); i++) {
        message+='*';
    }

    map<char, int>sorted_key_with_actual_index;
    for(int i=0; i<key.size(); i++) {
        sorted_key_with_actual_index[key[i]]=i;
    }
    /*
    for(auto i:sorted_key_with_actual_index) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    */

    string message_in_matrix_form[100];
    int j1=0;
    for(int i=0; i<message.size(); i++) {
        message_in_matrix_form[j1]+=message[i];
        if(i%row==row-1) {
            j1++;
        }
    }
    cout<<endl<<"Matrix:"<<endl;
    for(int i=0; i<row; i++) {
        cout<<message_in_matrix_form[i]<<endl;
    }

    string message_in_transpose_matrix_form[100];
    int j2=0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            message_in_transpose_matrix_form[j2]+=message_in_matrix_form[j][i];
        }
        j2++;
    }
    cout<<endl<<"Transpose Matrix:"<<endl;
    for(int i=0; i<row; i++) {
        cout<<message_in_transpose_matrix_form[i]<<endl;
    }

    cout<<endl<<"Cipher Text:"<<endl;
    for(auto i:sorted_key_with_actual_index) {
        cout<<message_in_transpose_matrix_form[i.second];
    }
    
    /*
    for(int i=0; i<row; i++) {
        cout<<message_in_transpose_matrix_form[i]<<endl;
    }
    */
    cout<<endl<<endl<<"Decrypted Text:"<<endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            cout<<message_in_transpose_matrix_form[j][i];
        }
    }
}