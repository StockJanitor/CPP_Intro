// #include <iostream>
// #include <stdexcept>
// using namespace std;

// int main() {
//    int userNum;
//    int divNum;
//    int result;
//    cin.exceptions(ios::failbit);       // Allow cin to throw exceptions

//    try {
//       cin >> userNum;
//       cin >> divNum;
//       if (divNum==0)
//       {
            // this is a runtime error
//          throw runtime_error("Runtime Exception: Divide by zero!");
//       }
//       cout << userNum / divNum << endl;
//    }
      // must catch before runtime error, because this is run time error too. so catch this first
//    catch (ios_base::failure& excpt)
//    {
//       cout << "Input Exception: basic_ios::clear: iostream error" << endl;
//    }
//    catch (runtime_error& excpt)
//    {
//       cout << excpt.what() << endl;
//    }


//    return 0;
// }


#include<iostream>
#include<stdexcept>

using namespace std;

int main(){
	int userNum;
	int divNum;
	int result;
	cin.exceptions(ios::failbit);
	try {

		cin>>userNum;
		cin>>divNum;
		if(divNum==0)
		      throw overflow_error("Runtime Exception: Divide by zero!");

		result = userNum/divNum;
		cout<<result<< endl;

    }
    catch (overflow_error &e) {
        cout <<  e.what() << endl;
    }
    catch (const ios_base::failure& e)
    {
      //  cout << "Input Exception: basic_ios::clear: iostream error" << endl;
      cout << "Input Exception: " << e.what() << endl;
    }
}