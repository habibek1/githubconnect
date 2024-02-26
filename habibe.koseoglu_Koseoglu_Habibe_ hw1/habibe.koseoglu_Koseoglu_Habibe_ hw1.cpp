
// Habibe Koseoglu cs204 hw1

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void goright(vector<vector<string> > & M,string & mystr, int step, int x, int & y, int lenword,int & count ) {
    // this function is used for going to the right direction for searching
    //it gets a matrix, a string value, stepsize, x and y coordinates of matrix, the lenght of the searched word and totalsteps before this function
    // it founds the char and adds to the string called mystr
    for (int i=1; i<= step; i++) {
        y=y+1;
        if (((x >= 0) && (x < M.size())) &&((y >= 0) && (y < M[x].size()))) {
            string str1 = M[x][y];
            mystr += str1;
            count++;
            if (count==lenword) {
                break;}}}}

void godown (vector<vector<string> > & M,string & mystr, int step, int & x, int & y, int lenword,int & count ) {
    // this function is used for going to the down direction for searching
    //it gets a matrix, a string value, stepsize, x and y coordinates of matrix, the lenght of the searched word and totalsteps before this function
    // it founds the char and adds to the string called mystr
    for (int i=1; i<= step; i++) {
        x=x+1;
        if (((x >= 0) && (x < M.size())) &&((y >= 0) && (y < M[x].size()))) {
            string str1 = M[x][y];
            mystr += str1;
            count++;
            if (count==lenword) {
                break;}}}}

void goleft (vector<vector<string> > & M,string & mystr, int step, int & x, int & y, int lenword,int & count ) {
    // this function is used for going to the left direction for searching
    //it gets a matrix, a string value, stepsize, x and y coordinates of matrix, the lenght of the searched word and totalsteps before this function
    // it founds the char and adds to the string called mystr
    for (int i=1; i<= step; i++) {
        y=y-1;
        if (((x >= 0) && (x < M.size())) &&((y >= 0) && (y < M[x].size()))) {
            string str1 = M[x][y];
            mystr += str1;
            count++;
            if (count==lenword) {
                break;}}}}

void goup (vector<vector<string> > & M,string & mystr, int step, int & x, int & y,int lenword,int & count ) {
    // this function is used for going to the up direction for searching
    //it gets a matrix, a string value, stepsize, x and y coordinates of matrix, the lenght of the searched word and totalsteps before this function
    // it founds the char and adds to the string called mystr
    for (int i=1; i<= step; i++) {
        x=x-1;
        if (((x >= 0) && (x < M.size())) &&((y >= 0) && (y < M[x].size()))) {
            string str1 = M[x][y];
            mystr += str1;
            count++;
            if (count==lenword) {
                break;}}}}

void printvector(vector<string> & vector){
    // it gets a vector and prints its elements
    for (int i=0; i < vector.size(); i++) {
        cout << vector[i]<< " ";
    }
}

int main() {
    int a=0;
    
    while (a==0) {
        string filename;
        cout << "Enter the name of the file" << endl;
        cin >> filename;
        
        ifstream input1(filename);

        if (input1.fail()) {
            
            cout << "Could not open the file " << filename << endl;

            }
        else {a=1;
            string line;
            
            // checking loop's condition
            bool aa = true;
            int totalrow=0;
            input1.clear();
            input1.seekg(0);
            // for getting first line of the matrix
            getline(input1, line);
            int num= stoi(line);
            //checking whether the matrix is valid or not
            for (int i = 0; i < num; i++)
            {
                totalrow++;
                getline(input1, line);
                stringstream ss(line);
                char ch;
                int totalcolumn=0;
                
                for (int ii=0; ii < line.length();ii++) {
                    ss.get(ch);
                    if (isalpha(ch)) {
                        if (isupper(ch)) {
                            totalcolumn++;
                        }
                        else { aa= false;}
                    }
                    else { aa= false;}}
            if (num!=totalcolumn) {
                aa= false;
            }
            }
            if ((aa==true) && (num==totalrow)) {

                vector<vector<string> > M(totalrow, vector<string>(num));

                //reading file again
                input1.clear();
                input1.seekg(0);
                //passing firts line
                getline(input1,line);
                string firstline= line;
                char ch2;
                
                // filling up the matrix M
                for (int i3 = 0; i3 < totalrow; i3++)
                {
                    getline(input1, line);
                    stringstream ss2(line);

                    for (int j2 = 0; j2 < num; j2++)
                    {
                        ss2.get(ch2);
                        M[i3][j2]=ch2;
                    }

                }
                // get the line that shows the number of searching words and assign the number to variable k
                getline(input1,line);
                stringstream ss2(line);
                int k= stoi(ss2.str());
                int t=0, d=0, stepsize=1, totalsteps=1;
                vector<string> Searchingwords (k); // vector of words to search
                vector<string> Searchedwords ;  // vector of found words
                for (int i4=0; i4 < k; i4++) // filling the Searchingwords vector
                {
                    getline(input1, line);
                    string linestr= line;
                    Searchingwords[i4]=linestr;
                }
                int numoffoundwords=0;
                for (int h=0; h < k; h++) {
                    string word1= Searchingwords[h];
                    int lenofword = static_cast<int>(word1.size());
                    bool isnotfound= true; // to understand that is the word found
                    for (int x=0; x <totalrow ; x++) {
                        for (int y=0; y < num; y++) { //num is also equal to columns of matrix
                            if (M[x][y][0]== Searchingwords[h][0]) { // both are char type
                                // there are total of 8 directions to search
                                //case 1
                                string mystr2;
                                mystr2= M[x][y];
                                // t= number of recurrent stepsize (a stepsize is repeated twice then it increases) t shows that if it is repeated or not, d= different directions
                                t=0; d=0; stepsize=1; totalsteps=1;
                                int xx = x, yy = y; // to access their first value later
                                while (totalsteps < lenofword) {
                                    if (t==2) {
                                        stepsize++; t=0;}
                                    if (d==0) {
                                        goright(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                        t++;
                                        d++;}
                                    else if (d==1){
                                        godown(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                        t++;
                                        d++;}
                                    else if (d==2){
                                        goleft(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                        t++;
                                        d++;}
                                    else if (d==3){
                                        goup(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                        t++;
                                        d=0; } }
                                bool isitappended = false; // to prevent printing a word two times
                                if (mystr2==word1) {
                                    for (int u=0; u < Searchedwords.size(); u++) { //this for loop checks if the vector includes the found word
                                        if (Searchedwords[u]== mystr2) {
                                            isitappended = true;} }
                                    if (!isitappended) { // if the vector does not include the found word it will append the word to the vector
                                        Searchedwords.push_back(mystr2);
                                        numoffoundwords++;
                                        isnotfound = false;}}
                                // other cases are similar with case 1 but they are searching in different directions
                                //case 2
                                if (isnotfound){ t=0; d=0; stepsize=1; totalsteps=1; xx = x; yy = y; mystr2= M[x][y];
                                    while (totalsteps < lenofword) {
                                        if (t==2) {
                                            stepsize++; t=0;}
                                        if (d==0) {
                                            goright(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==1){
                                            goup(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==2){
                                            goleft(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==3){
                                            godown(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d=0; }}
                                    bool isitappended = false;
                                    if (mystr2==word1) {
                                        for (int u=0; u < Searchedwords.size(); u++) {
                                            if (Searchedwords[u]== mystr2) {
                                                isitappended = true;}}
                                        if (!isitappended) {
                                            Searchedwords.push_back(mystr2);
                                            numoffoundwords++;
                                            isnotfound = false;}}}

                                //case 3
                                if (isnotfound){t=0; d=0; stepsize=1; totalsteps=1; xx = x; yy = y; mystr2= M[x][y];
                                    while (totalsteps < lenofword) {
                                        if (t==2) {
                                            stepsize++; t=0;}
                                        if (d==0) {
                                            goup(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==1){
                                            goright(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==2){
                                            godown(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==3){
                                            goleft(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d=0; } }
                                    bool isitappended = false;
                                    if (mystr2==word1) {
                                        for (int u=0; u < Searchedwords.size(); u++) {
                                            if (Searchedwords[u]== mystr2) {
                                                isitappended = true;}}
                                        if (!isitappended) {
                                            Searchedwords.push_back(mystr2);
                                            numoffoundwords++;
                                            isnotfound = false;}}}
                                //case 4
                                if (isnotfound){t=0; d=0; stepsize=1; totalsteps=1; xx = x; yy = y; mystr2= M[x][y];
                                    while (totalsteps < lenofword) {
                                        if (t==2) {
                                            stepsize++; t=0;}
                                        if (d==0) {
                                            goup(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==1){
                                            goleft(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==2){
                                            godown(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==3){
                                            goright(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d=0; }}
                                    bool isitappended = false;
                                    if (mystr2==word1) {
                                        for (int u=0; u < Searchedwords.size(); u++) {
                                            if (Searchedwords[u]== mystr2) {
                                                isitappended = true; } }
                                        if (!isitappended) {
                                            Searchedwords.push_back(mystr2);
                                            numoffoundwords++;
                                            isnotfound = false;}}}
                                //case 5
                                if (isnotfound){t=0; d=0; stepsize=1; totalsteps=1; xx = x; yy = y; mystr2= M[x][y];
                                    while (totalsteps < lenofword) {
                                        if (t==2) {
                                            stepsize++; t=0;}
                                        if (d==0) {
                                            goleft(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==1){
                                            godown(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==2){
                                            goright(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==3){
                                            goup(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d=0; } }
                                    bool isitappended = false;
                                    if (mystr2==word1) {
                                        for (int u=0; u < Searchedwords.size(); u++) {
                                            if (Searchedwords[u]== mystr2) {
                                                isitappended = true; } }
                                        if (!isitappended) {
                                            Searchedwords.push_back(mystr2);
                                            numoffoundwords++;
                                            isnotfound = false;}}}
                                //case 6
                                if (isnotfound){t=0; d=0; stepsize=1; totalsteps=1; xx = x; yy = y; mystr2= M[x][y];
                                    while (totalsteps < lenofword) {
                                        if (t==2) {
                                            stepsize++; t=0;}
                                        if (d==0) {
                                            goleft(M, mystr2, stepsize,  xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==1){
                                            goup(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==2){
                                            goright(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==3){
                                            godown(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d=0; }}
                                    bool isitappended = false;
                                    if (mystr2==word1) {
                                        for (int u=0; u < Searchedwords.size(); u++) {
                                            if (Searchedwords[u]== mystr2) {
                                                isitappended = true; }}
                                        if (!isitappended) {
                                            Searchedwords.push_back(mystr2);
                                            numoffoundwords++;
                                            isnotfound = false;}} }
                                // case 7
                                if (isnotfound){t=0; d=0; stepsize=1; totalsteps=1; xx = x; yy = y; mystr2= M[x][y];
                                    while (totalsteps < lenofword) {
                                        if (t==2) {
                                            stepsize++; t=0;}
                                        if (d==0) {
                                            godown(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==1){
                                            goright(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==2){
                                            goup(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==3){
                                            goleft(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d=0; }}
                                    bool isitappended = false;
                                    if (mystr2==word1) {
                                        for (int u=0; u < Searchedwords.size(); u++) {
                                            if (Searchedwords[u]== mystr2) {
                                                isitappended = true;}   }
                                        if (!isitappended) {
                                            Searchedwords.push_back(mystr2);
                                            numoffoundwords++;
                                            isnotfound = false;}}}
                                // case 8
                                if (isnotfound){t=0; d=0; stepsize=1; totalsteps=1; xx = x; yy = y; mystr2= M[x][y];
                                    while (totalsteps < lenofword) {
                                        if (t==2) {
                                            stepsize++; t=0;}
                                        if (d==0) {
                                            godown(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==1){
                                            goleft(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==2){
                                            goup(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d++;}
                                        else if (d==3){
                                            goright(M, mystr2, stepsize, xx, yy, lenofword, totalsteps);
                                            t++;
                                            d=0; }
                                        
                                        bool isitappended = false;
                                        if (mystr2==word1) {
                                            for (int u=0; u < Searchedwords.size(); u++) {
                                                if (Searchedwords[u]== mystr2) {
                                                    isitappended = true; }}
                                            if (!isitappended) {
                                                Searchedwords.push_back(mystr2);
                                                numoffoundwords++;
                                                isnotfound = false;}}}} }  }}}
                if (numoffoundwords!=0) { // if any word is found print the words
                    cout<< numoffoundwords << " Words are Found:  "; // two spaces after ":" as mentioned in hw1 file
                    printvector(Searchedwords);}}
            else {
                cout << "Error: Input file is not in correct format!" << endl;}}}
    
    return 0;}
