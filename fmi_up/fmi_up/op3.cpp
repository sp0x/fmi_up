#include <cstring>
#include <stdio>
#include <iostream>
#include <cmath>
#include <algorithm>


#if (_MSC_VER >= 1600) || (_MSC_VER >= 1700)
    #if __cplusplus >= 199711L //using c11
        #include <utility>
    #endif
#endif


using namespace std;



void main(){
}

void zad1Vars(){
    string name1; cout << "Student 1: "; cin >> name1; cout << endl;
string name2; cout << "Student 2: "; cin >> name2; cout << endl;
string name3; cout << "Student 3: "; cin >> name3; cout << endl;
string name4; cout << "Student 4: "; cin >> name4; cout << endl;
string name5; cout << "Student 5: "; cin >> name5; cout << endl;
string name6; cout << "Student 6: "; cin >> name6; cout << endl;
string name7; cout << "Student 7: "; cin >> name7; cout << endl;
string name8; cout << "Student 8: "; cin >> name8; cout << endl;
string name8; cout << "Student 8: "; cin >> name8; cout << endl;
string name9; cout << "Student 9: "; cin >> name9; cout << endl;
string name10; cout << "Student 10: "; cin >> ame10; cout << endl;
string name11; cout << "Student 11: "; cin >> ame11; cout << endl;
string name12; cout << "Student 12: "; cin >> ame12; cout << endl;
string name13; cout << "Student 13: "; cin >> ame13; cout << endl;
string name14; cout << "Student 14: "; cin >> ame14; cout << endl;
string name15; cout << "Student 15: "; cin >> ame15; cout << endl;
string name16; cout << "Student 16: "; cin >> ame16; cout << endl;
string name17; cout << "Student 17: "; cin >> ame17; cout << endl;
string name18; cout << "Student 18: "; cin >> ame18; cout << endl;
string name19; cout << "Student 19: "; cin >> ame19; cout << endl;
string name20; cout << "Student 20: "; cin >> ame20; cout << endl;
cout << name1 << endl; cout << name2 << endl; cout << name3 << endl; cout << name4 << endl; cout << name5 << endl; cout << name6 << endl; cout << name7 << endl; cout << name8 << endl; cout << name8 << endl; cout << name9 << endl;
cout << name10 << endl; cout << name11 << endl; cout << name12 << endl; cout << name13 << endl; cout << name14 << endl; cout << name15 << endl; cout << name16 << endl; cout << name17 << endl; cout << name18 << endl; cout << name19 << endl; cout << name20 << endl; }

}


void zad1Arrays(){
    string students[20];
    cout << "Enter a list of 20 students";
    for(int i=0; i<20; cin::getline(cin,students[i++]));
    for(int i=0; i<20; cout << "Student #" << i+1 << students[i++] << endl);
}

void zad2(){
    cout << "How many friends do you have? ";
    int szFrs; cin >> szFrs;
    int iFrAges[3];
    int ixMin=-1, ixMax=-1;
    cout << "Enter the ages of your 3 friends: ";
    for(int i=0; i<3; cin >> iFrAges[i++]);
    for(int i=0; i<3; i++){
        if(iMin==-1){
            ixMin=i;
        } else {
            ixMin= (iFrAges[i]<iFrAges[ixMin]) ? i : ixMin ;
        }
        if(ixMax==-1){
            ixMax=i;
        } else {
            ixMax= (iFrAges[i]>iFrAges[ixMax]) ? i : ixMax ;
        }
    }
    cout << "The oldest of your friends is " << iFrAges[ixMax] <<
     " years old. The youngest is " << iFrAges[ixMin] << "." << endl;
}
void zad3(){
    float gpa=0.0f;
    float grSum;
    int cntGrs=0;
    while(!cntGrs)
         cout << "Number of grades: "; cin >> cntGrs;
    float * fGrades = (float*)calloc(cntGrs ,sizeof(float)); // to lazy to use new :D
    for(int=0; i<cntGrs; i++){
        cout << "Grade #" << i << ": "; cin >> fGrades[i];  grSum+=fGrades[i];
    }
    cout << "Your GPA is " << grSum/cntGrs << endl; //  cntGrs CAN'T BE ZERO, the input was checked.
}

bool isSorted(int * arr , size_t arrlen);
void zad4(){
    int arr1[5]={1,2,3,4,5}; //ascending
    int arr2[5]={5,4,3,2,1}; //descending
    int arr3[5]={145,1,777,123,2}; // randomly ordered
    cout << "Arra 1 is" <<  isSorted(arr1,5) ? "" : "n't" << "sorted";
    cout << "Arra 2 is" <<  isSorted(arr2,5) ? "" : "n't" << "sorted";
    cout << "Arra 3 is" <<  isSorted(arr3,5) ? "" : "n't" << "sorted";
}

bool isSorted(int * arr , size_t arrlen){
    if(arr==0){
        cout << "INVALID ARRAY!"; return false;
    }
    bool ascending = arr[0]<arr[arrlen-1];
    bool descending = arr[0]>arr[arrlen-1];
    for(int i=0; i<arrlen-1; i++){
        if(ascending){
            if(arr[i]>=arr[i+1]) return false; // prev can't be equal or greater than next
        } else if(descending){
            if(arr[i]<=arr[i+1]) return false;// prev can't be equal or less than next
        }
    }
    return true;
}

/*
Does insertion sorting...
*/
void zad5(int * arr, int arrlen){
    for(int i=1; i<arrlen; i++){
        int crVal=arr[i];
        int prev =arr[i-1];
        //iterate backwards untill base is reached. exit if previous is smaller than current
        while( prev>=0 && arr[prev] > crVal){
            arr[prev+1] = arr[prev]; // set the element after the prev. one.
            prev--;
        }
        arr[prev+1]=crVal;
    }
}


void zad6(){
    char * str2Rev;
    cout << "Something funny: "; cin >> str2Rev;
    int len =strlen(str2Rev);
    for(int i= len; i>-1; i--){
        swap(str[i], str[len-i]);
    }
}