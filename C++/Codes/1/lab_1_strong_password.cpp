#include <iostream>
#include <string>
using namespace std;

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    //switches
    int num= 1;
    int lower = 1;
    int upper = 1;
    int special = 1;
    //final number needed
    int need_num=0;
    

    for (int i=0; i<n ; i++){
        char letter = password[i];

        if (((numbers.find(letter) != string:: npos)) && (num==1)){    //character found
            num=0;
        }
        else if (((lower_case.find(letter) != string:: npos))&& (lower ==1))
        {
            lower =0;
        }
        else if (((upper_case.find(letter) != string:: npos))&& (upper ==1))
        {
            upper =0;
        }
        else if (((special_characters.find(letter) != string:: npos))&& (special ==1))
        {
            special =0;
        }

        }
        need_num = num+lower+upper+special;
        if ((need_num+n) < 6){
            return (6-n);
        }
        else {
            return need_num;
        }
    }



int main() {
    cout << minimumNumber(4, "123!");
  return 0;
}