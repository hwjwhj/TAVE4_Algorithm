#include <iostream>
#include <string>

using namespace std;

int main(void){
	string input;
	string target;
	string target2;
	int laser=0;
	int floor=0;
	int result=0;
	
	cin >> input;
	for(int i=0;i<input.size()-1;i++){
		laser=0;
		cout << target2 <<endl;
		target=input.substr(i,2);
		if (target=="()"){
			laser++;
			result+=floor*laser;
		}
		if (target=="((")
			floor++;
		if (target=="))") {
			floor--;
			result+=1;
		}
		
	}
	cout << result<<endl;
}