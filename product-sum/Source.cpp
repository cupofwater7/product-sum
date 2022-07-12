#include <any>
#include <vector>
#include <iostream>

using namespace std;

int productSum(vector<any> array, int multiplier = 1);

int main()
{
    vector<any> test = { 5, 2, vector<any>{7, -1}, 3,vector<any>{6, vector<any>{-13, 8}, 4} };
    int result = productSum(test);
    cout << result << " ";
    return 0;
}


// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)
int productSum(vector<any> array, int multiplier) {
    // Write your code here.
    // o(n)time o(d)space
    int sum = 0;

    for (auto el : array)
    {
        if (el.type() == typeid(vector<any>))
            sum += productSum(any_cast<vector<any>>(el), multiplier + 1);
        else
            sum += any_cast<int>(el);

    }
    return sum * multiplier;
}
