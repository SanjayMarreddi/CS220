#### Misc. Important Points

- Printing `2` as `2.00`  (Int as Float with known Precision) :-

```
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float m = 2;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << m;
}
```
```
#include <stdio.h>

int main()
{
    int i = 1, 2, 3;
    
    printf("%d", i);
    
    /*COMPLIER ERROR
    Comma acts as a separator here. The compiler creates an integer variable and initializes it with 1. The compiler fails to create integer variable 2 because 2 is not a valid identifier.*/

    return 0;
}
```
```
#include <stdio.h>

int main()
{
    int i = (1, 2, 3);
    
    printf("%d", i);
    /*
    Prints 3
    The bracket operator has higher precedence than assignment operator. The expression within bracket operator is evaluated from left to right but it is always the result of the last expression which gets assigned. 
    
    */
    
    return 0;
}
```

```
#include <stdio.h>

int main()
{
    int i;
    
    i = 1, 2, 3;
    printf("%d", i);
    /*
    Prints 1
    Comma acts as an operator. The assignment operator has higher precedence than comma operator. So, the expression is considered as (i = 1), 2, 3 and 1 gets assigned to variable i.
    */
    
    return 0;
}
```

- Encapsulation allows us to focus on what something does without considering the complexities of how it works.
- Abstraction allows us to consider complex ideas while ignoring irrelevant detail that would confuse us.
- A publicly derived class is a subtype of its base class.
- Inheritance provides for code reuse.
- Overloading is a static or compile time binding and overriding is dynamic or runtime binding.
- Converting a primitive type data into its corresponding wrapper class object instance is called Autoboxing.
- Instantiation is creation or a real instance or a particular realization of an abstraction or template.
- Wrapping encapsulates and hides the underlying complexity of another entity.
- Boxing is the process of converting a value type to the type object or to any interface type implemented by this value type
- Members of a class are `private` by default and members of struct are `public` by default. When deriving a struct from a class/struct, default access-specifier for a base class/struct is public and when deriving a class, default access specifier is private.
- Size of an empty class is not zero in C++
- Objects of a class do not share non-static members. Every object has its own copy.
- Header file can not be passed to a function in C++.
- Every class containing abstract method must be declared abstract.
- Abstract class can not be directly be initiated with ‘new’ operator.
- Abstract class can be initiated.
- Abstract class does not contain any definition of implementation.
- When a method in a subclass has the same name and type signatures as a method in the superclass, then the method in the subclass overrides the method in the superclass.
- Overloading allows different methods to have same name, but different signatures where signature can differ by number of input parameters or type of input parameters or both. Overloading is related to compile time (or static) polymorphism..
- Friend Class A friend class can access private and protected members of other class in which it is declared as friend.
- The capability of a class to derive properties and characteristics from another class is called Inheritance.
- When one object reference variable is assigned to another object reference variable then a copy of the reference is created
```
// a= ++b
// This is pre-increment operation.
// The value of b will first be incremented and then used in the operation. Thus,

b = 3
a= ++b;
After execution b = 4; a = 4

// a = b++
// This is post-increment operation. First the value of b will be assigned to a and then incremented. Thus,

b = 3;
a = b++
After execution; a = 3; b = 4
```

```
int bar() { return x++; }


It's equivalent to:

int bar()
{
  int temp = x;
  ++x;
  return temp;
}

It returns before incrementing.


Similar thing holds for `cout << a++ << b--`
```

Pass by Reference as well as Pass by Pointer also can perform SWAPPING.

```

int main()
{
    double* val = NULL;
    val = new double;
    *val = 38184.26;
    cout << *val;
    delete val;
}
// Yields 38184.3
```

```
int main()
{
    extern int i;
    i = 20;
    cout << sizeof(i);
    return 0;
}

// Yields Error -> undefined reference to `i'
```

Structure Instance can have same name as structure
Eg :-

```
struct sample
{
    int a;
} sample;

```

```
int main() 
{ 
    char str[] = "Cplusplus"; 
    cout << 5[str]; 
    return 0; 
}
// Yields `p`.
```

```
int main(){
    int *ptr = NULL;
    ptr++;
    delete ptr;
    return 0;
}

// Think about the Output.
```

Firstly these two represent the same.

`const int *` and `int const *`

- When using `const int*` or `int const *` - You are allowed to change the variable it points to, but can't dereference the pointer and change value.

- `int * const` - Works exactly the opposite way - You can dereference and change the value but can't change the variable it points to.

- `const int *` or `int const *` - pointer to const int - Can't dereference and update.

- `int * const` - const pointer to int - Can't change the variable it is pointing to.

Dont forget to consider the Integer OverFlow !!

```
#include <climits>

typedef long long ll;

ll left_sum = LLONG_MIN,

ll sum // It can hold very large Quantity
```

- `int mid = low + (high - low)/2;` This Helps in avoiding Overflow .
`typedef unsigned long long int ull;` This too..

- If required we can take Integer input as Strings.

- For `sort` We can pass the pointers too not only Iterators which Implies we can pass Array(Since It behaves like Pointer).

- Ternary Operators :

    `variable = (Expression) ? expressionTrue : expressionFalse;`

    Refer [this](https://media.geeksforgeeks.org/wp-content/uploads/20190920110229/Conditional-or-Ternary-Operator-__-in-C_C.jpg) for Clear Idea

- Let S1, S2 are Two Strings, `return S1.compare(S2) > 0 ? 1 : 0;`
  This returns 1 if Both strings are Equal or S1 > S2 Else It returns 0.
- This comes in handy If we want to compare Two Integers Lexicographically but not Numerically.
- `S1.compare(S2)` returns `Negative` Value if S1 < S2, `Positive` Value if S1 > S2. `Zero` If S1==S2.

- Let us assume `a` is of the type `string`. Then we can reverse a string in this way `reverse(a.begin(), a.end());`
- Be very careful while defining the  `custom comparator` function to use in `sort` function. If the Custom Function returns `true` Then the Order of parameters passed remains same & It gets swapped when it returns `false`. Solve the `Modulo Sort` question in the `Quick Sort` exam to get an Overview.
- Dont forget to use `push_back` function when Constructing an Vector from the Inputs.
  Ex :-

```
vector<int> a;
int n ;
cin >> n;
for(int i = 0; i< n; i++){
int temp;
cin >> temp;
a.push_back(temp);

}
```

- Checking for Disjoint elements in the 2 Vectors efficiently ( Holds for other containers too)

- find(START, END, KEY_TO_LOOK_FOR) returns an Iterator.

- Finds the element in the given range of numbers.
Returns an iterator to the first element in the range [first,last) that compares equal to val.
If no such element is found, the function returns last

-
Traversing elements of `a` and checking its presence in `b`.
  
```
  vector<int> a_uni;
  for (int i = 0; i < a.size(); i++ ){
  
    if ((!(find(b.begin(), b.end(), a[i]) != b.end())) 
        a_uni.push_back(a[i]);
  }
```

- Learning Algorithms Like Sorting Algos are helpful in similar scenarios like `Counting the Inversions/Divide and Conquer`
- Square in C++ is done by `pow(number, 2)`. We need to include `cmath`
- Getting the Unique Characters present in a given String :

```
    sort(s2.begin(), s2.end()); 
    auto res = unique(s2.begin(), s2.end()); 
    for (auto itr = s2.begin() ; itr != res; itr++){
        cout << *itr ;  // This prints the Unique characters in given string s2.
    }
```

- Finding the count of the characters in the string :
`int freq = count(s.begin(), s.end(), *itr);`  // Counting number of occurences of element at `itr` in the string `s`

Its always advisable to use `typedef long long int ll` or  `typedef unsigned long long int ull`in every question at every point except at `int main()`to avoid Overflow cases !!

We do the String to Integer and Viceversa Conversions as shown below :

- `int String2Integer =  stoi(StringName);`
- `string s = to_string(Number)`;

Sometimes TLE happens when we pass the arguments to functions as VALUES. Passing by Reference (Pointers) reduces the Time Complexity since it avoids Copying the entire data again

Counting Sort :

- We can use Counting Sort with Ordered_Map with any Input.But it will lead to O(nlogn)
- To use Counting Sort in Linear Time [ O(n+k) ] for Negative Input also, We make the Input numbers `Positive` by adding a `Fixed Number` before sorting & subtracting it after sorting.

### We can directly find out the Maximum Element using `max_element` under `algorithm` Header

`int max = *max_element(array, array + size)`

### To pass the Vector as an array or a Pointer, We can use this

```
vector<int> vec = { 10, 20, 30, 40, 50 };
int* pos = vec.data();
```

Generate random numbers between a negative and positive value :
The algorithm goes like this

```
min + rand() % ( max - min + 1 )
```

Checking whether a given number is Palindrome or not

```
#include <string>

bool pal(int i){
    string s = to_string(i);
    return ( s == string(s.rbegin(), s.rend()));
}
```

`rbegin()` -> Returns a reverse iterator pointing to the last element in the container.
`rend()` -> Returns a reverse iterator pointing to the theoretical element preceding the first element in the container
The range between `vector::rbegin` and `vector::rend` contains all the elements of the vector in REVERSE ORDER.

## Rotate the vector using STL

Types of Rotations :

`void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last)`

first, last : Forward Iterators to the initial and final positions of the sequence to be rotated

middle : Forward Iterator pointing to the element within the range [first, last] that is moved to the **first position in the range.**

Left Rotation : To rotate left, we need to add the vector index. For example, you have to rotate vector left 3 times. The 3th index of vector becomes first element. `vec.begin() + 3` will rotate vector 3 times left.

Right Rotation : To rotate right, we need to subtract the vector index. For example, you have to rotate vector right 3 times. The 3th last index of vector becomes first element.`vec.begin()+vec.size()-3` will rotate vector 3 times right.

Example :

```
// Rotates/ Shifts the array to the right by `k` positions 
rotate(b.begin(), b.begin() + b.size()-k, b.end());   

// Rotates/ Shifts the array to the left by `k` positions 
rotate(b.begin(), b.begin() + k, b.end());   
```

When the Input is Unknown Number of  Space Separated Integers :-

```
vector<int> v;
int temp;
while (cin >> temp)
    { v.push_back(temp);}
```

When using the maps/sets, Better to use the find function present in the corresponding header only
Ex:

```

map <int,int> m;

m.find(data)->second   // This `find` comes from the corresponding `map` header only. This is better to use.

find(m.begin(), m.end(),data) // This `find` comes from the `algorithm` header. Avoid using this.
```

Also to check presence of element & incrementing ( Keeping track of Frequency ) use the code similar to below one :

```
    map <int,int> m;
    if ( m.count(data) == 0 ){
        m.insert(make_pair(data, 1));
    }
    else{
        // If the element is already present, Increment the count by 1.
        (m.find(data)->second)++;
    }
```

Also, To sort the map using its Values, We make use of extra Multimap & insert elements after swapping as shown below :

```


multimap<int, int, greater<int>> final_map;  // It contains descending order of elements based on keys

// Iterating over our initial map m which has pairs of (element, count)
    for (auto& it : m) { 
        
        // We make a map with pairs (count, element). Since it(final_map) is a
        // Multimap with gerater<int> specified, It sorts the elements based on 
        // the count in descending order

    final_map.insert({ it.second, it.first }); 
} 
    
```

Its better practise to free up Dynamically alloted memory after every test case, when dealing with Multiple Test Cases.

- In AVL Trees, During Rotation, We shift the SubTrees ! (Not just the Nodes)

- Though both AVL & Red-Black trees are balanced, when there are more insertions and deletions to make the tree balanced, AVL trees should have more rotations, it would be better to use red-black. but if more search is required AVL trees should be used.
  
- We can use `memset` to fill the memory or Initialise a container,
Ex :

```
    int array[n][n];
    memset(array, 0, sizeof(int)*n*n);
```

```
string str;
`scanf("%s", &str);` // Note that this wont work. C++ std::string wont work with SCANF.
cin >> str             // This should be used.
```

- Avoid Using `unsigned` unless required since it may introduce bugs that are hard to debug.
  
- Converting a `bitset` into Integer :

```

typedef long long int ll;
bitset<64> a;
...... 
int integer = (ll)a.to_ulong() 

```

- Searching a string for a character :

```
#include <iostream> 
#include <string> 
  
using namespace std; 
  
int main() 
{ 
    string str = "geeksforgeeks a computer science"; 
    string str1 = "geeks"; 

    // Find first occurrence of "geeks" 
    auto itr = str.find(str1); 
    if (itr != string::npos) 
        cout << "First occurrence is " << itr << endl; 

// IMPORTANT: If it is not found , `itr == string::npos`
```

- Use vectors for 2D Data Structures too Ex : For a 2D Rectangle of size m*n, instead of using int a[m][n], use :

```
// Filling the grid with m rows of vectors of size n;
vector<vector<int>> grid(m, vector<int>(n));

for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
        cin >> grid[i][j];
}


// So we can just pass the vector lonely to function & return.
// We can get dimensions in this way.
int m =  grid.size();
int n =  grid[0].size(); 
```

- Sometimes, Storing `strings` as `Vectors of characters` helps a lot to recursively iterate.
- Moreover, Sometimes, `Large numbers` are also stored as `Vectors of its each digits`.
- Use `#include <bits/stdc++.h>` to include all the header files.
  
- NOTE :
    In C++, all variables are declared with type. C++ forces you to specify the type explicitly, but doesn't force you to initialize the variable at all.

    ```
    long int a = 2;
    long int b = 2L;
    long int c; 
    ```

    This code above makes 3 variables of the same type long int.

    ```
    int a = 2;
    int b = 2L;
    int c;
    ```

    This code above makes 3 variables of the same type int.

    The idea of type is roughly "the set of all values the variable can take".
    It doesn't (and cannot) depend on the initial value of the variable - whether it's 2 or 2L or anything else.

    So, if you have two variables of different type but same value

    ```
    int a = 2L;
    long int b = 2;
    ```

    The difference between them is what they can do further in the code. For example:

    ```
    a += 2147483647; // most likely, overflow since Its of type `int`
    b += 2147483647; // probably calculates correctly
    ```

    The type of the variable won't change from the point it's defined onwards.

    Another example:

    `int x = 2.5;`
    Here the type of x is int, and it's initialized to 2. Even though the initializer has a different type, C++ regards the declaration type of x "more important".

    BTW C++ has support for "type inference"; you can use it if you want the type of the initializer to be important:

    ```
    auto a = 2L; // "a" has type "long int"
    auto b = 2; // "b" has type "int"
    ```

    ```
    typedef long long ll;
    ll K;
    if ((K %  2L ) == 0L) cout << "Bye" ;
    ```

    `L` is a long integer literal.
    Integer literals have a type of int by default; the L suffix gives it a type of long (Note that if the value cannot be represented by an int, then the literal will have a type of long even without the suffix).

- We can check whether a quantity is `infinity` or not using `isinf()`.
- We use `(int)` to type cast a ceiled float to get the number in the integer format instead of exponential powers.
Ex :-

```
float Final = 123123123.23123
cout << (int)ceil(Final);
```

- We need to send the same datatypes to min/max algos of STL. In such scenario's, `LL` at the back of integers may help
- Ex :

```
typedef long long int ll;
ll big = 100012;
cout << min (big, 12)   // Shows error
cout << min (big, 12LL) // Works fine

ll small = 12;
cout << min (small, big) // Anyhow works

```

- If we are sure that computation involves only positive values, Its advisable to use
`typedef unsigned long long int ulli` when dealing with large numbers. But sometimes it may yield unncessary erros if we include `unsigned` term

- If we knew the recurrence relations, Implementing using DP is very easy. Ex : Catalan Numbers, Fibonacci Sequence.
So, Knowledge of Maths helps a lot!!

- In most of the DP cases, We try to frame the subproblems in this way,
  1. Leave the last element/ Current element, reduce the number, solve
  2. Consider that last element/ Current element is included, reduce the number, modify accordingly, solve
  3. Combine the results of both the above 2 cases logically (Sometimes, It might be + , &&, etc...)
    Ex :
  - [Coin Change](https://www.geeksforgeeks.org/coin-change-dp-7/)
  - [Subset with Sum](https://www.geeksforgeeks.org/subset-sum-problem-dp-25/)
  4. Sometimes, DP problems becomes easy, if u know the base conditions since we can construct the equation from base terms.
  5. **In many cases of DP applications, Recursive Implementation is very Intuitive & Once we get the recursive implementation idea, we can easily translate it into the DP easily. So We can start thinking a DP problem's solution in a Recursive way including SUB PROBLEMS.**
  6. So Start with base cases, Think of a recursive approach, Draw a Recursive Tree, Convert it into Iterative Bottom Up appraoch using DP for more efficient solution.

    Ex : [Cutting a Rod](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/)

- Note the difference between the Subarray, subsequence, subset, substring

  Consider an array: {1,2,3,4}

    Subarray: contiguous sequence in an array i.e.
    {1,2},{1,2,3}

    Subsequence: Need not to be contiguous, but maintains order i.e.
    {1,2,4}

    Subset: Same as subsequence except it has empty set i.e.
    {1,3},{}

    A substring is exactly the same thing as a subarray but in the context of strings.


- Sometimes, Using `else` at the end of multiple `if` statements, leads to unexpected things.
- So Its better practise to use `else if` instead of multiple `if`. 

- We can deal with negative modulo with `abs` itself. Else we need to do `((a%k + k)%k)`

- Better to use `sqrt()` for getting square roots instead of `pow(10, 1/2)`.
- The maximum precision can be set using the below code. 
      ```
      cout.precision(17);
      cout  << fixed ;
      ```
-  Maximum float we can use in C++ is `long double`
-  To find the occurence of a First occurence of a substring in a string from the end (i.e. Last Occurence of a substring in a string), We use `str.rfind("substr")`

- Dont use `typedef long long int ll` unless required. When dealing with the STL Library functions, Storing the results in
  `ll` format leads to unexpected results. 
  Ex:
  ```
       int occ_11 = s.find("11");    // This Works

       // ll occ_11 = s.find("11");  // This wont work as expected.

       if (occ_11 != -1){
           cout << "found";
       }
  ```
- `size_t` is an unsigned integer data type which can assign only 0 and greater than 0 integer values. 
  It measures bytes of any object's size and returned by sizeof operator. const is the syntax representation of `size_t`, but without const you can run the program. `const size_t number;`
- Dont forget changing the `INT_MAX` to `ULLONG_MAX` when dealing with `unsigned long long` type.
- Say we want to take TIME as input. We can read it as STRING entirely using cin  & take required quantities or Using scanf & pattern, take only require quantities.
        Ex :-
```
        // INPUT : 12:30

        // Method-1
        int h, m, curr_h_int,curr_m_int;
        scanf("%d%d%d:%d", &h, &m, &curr_h_int, &curr_m_int);


        // Method-2
        int h, m;
        string s;
        cin >> h >> m >> s;
        int curr_h_int = stoi(s.substr(0, 2));
        int curr_m_int = stoi(s.substr(3, 2));
```
- Note that we cant use both methods in a same program at different locations if we used the line 
        ` ios_base::sync_with_stdio(0); cin.tie(0);`. Since we turned off sync between cin  & scanf.
- Note that, Character array & string datatype are not exactly SAME.
- Tokenizing a `string` dataype based on a delimeter :- 
  ```
    // Tokenizing a String based on ":"

    #include <bits/stdc++.h>
    using namespace std;
    int main(){
    string input = "abc:def:ghi";
        stringstream ss(input);
        string token;

        while(getline(ss, token, ':')) {
            cout << token << '\n';
        }
    }
  ```
- Minimum number to be added to x to make it divisible by k.
```
int min_number_to_be_added(int x, int k) {
    return ( k - (x % k) ) % k;}
```
- **Fact:** A point with the smallest summary distance is between left and right median. 
    The summary distance is the sum of distances from the point to all the other points on the Line. 
    To find out No of such points on NUMBER LINE of Integers with minimal summary distance, We only need to sort the array and find the elements on positions ⌊(n+1)/2⌋ and ⌊(n+2)/2⌋ and return their difference plus one.
    ```
    Ex :
    Input Points :  0,2,3,1 
    Sorted : 0,1,2,3 
    n = 4
    Left median (2nd element)  is 1, Right Median (3rd element) is 2. No of elements =  (2-1) + 1 = 2.
    Therefore 2 such points with Minimal Summary distance exist for the given input points.
    
    // ACTUAL IMPLEMENTATION
        
    ll count(ll arr[]){
        sort(arr, arr+n);
        ll right_median  =  (n) / 2  ;
        ll left_median   =  (n - 1) / 2   ;
        return ( arr[right_median] - arr[left_median] ) + 1 ;
    }    
    ```

- Don't make the vectors/any sort of containers as Global Variables. If we make it, We need to ensure that they are cleared after each test case. So, Keep them inside the loop of test cases only so that we need not clear them.

- Dont make silly mistakes in Binary search. Depending upon the Problem, The way we update the `low` and `high` limits accordingly with `mid` term in each iteration differs.
  
  Ex :-
  ```
  // In Binary search :

    int main() {
    
    fastIO;
    ll arr[] =  {1,2,3,4,5,6,7,8,9,10};        
    ll x = 8;
    
    ll low = 0;
    ll high = sizeof(arr)/sizeof(arr[0]) -1;
    ll mid ;
    while (high > low){
        
        mid = (high + low)/2;                         // Till this line, Everything will be same for every implementation.

        if ( arr[mid] > x )  {
            high = mid;                               // Notice this
        }
        else if  ( arr[mid] < x ) {
            low = mid;                               // Notice this
        }   
        else{
            break;
        }
    }

    if (arr[mid] == x) {
        cout << "found";
    }
    // deb(arr[mid]); deb2(arr[low], arr[high]);
    }   
  ```
    Now Lets take a problem that involves Binary search :
    Ex :- https://codeforces.com/contest/1490/problem/E
    
    ```
    bool Can_Win(ll position, vector<ll> &sorted_input){
        
        ll curr_tokens = sorted_input[position];
        for (ll i = 0 ;  i<sorted_input.size() ; i++){
            
            if (i == position){
                continue;
            }
    
            if ( curr_tokens < sorted_input[i]){
                return false;
            }
    
            curr_tokens += sorted_input[i];
        }
    
        return true;
    
    }
    
    int main() {
        
        fastIO;
        ll t, n, temp;
        cin >> t;
        while (t--) {
 
            vector<ll> input;
            vector<ll> sorted_input;
            
            cin >> n;
            for (ll  i = 0; i <n; i++){
                cin >> temp;
                input.push_back(temp);
                sorted_input.push_back(temp);
            }
    
            sort(all(sorted_input));
    
            ll low = 0;
            ll high = n-1;
            ll mid;
            while (high > low){
                
                mid = (high + low)/2;                       // Till this line, Everything will be same for every implementation.
    
                if (Can_Win(mid, sorted_input)){
                    high = mid;                             // Notice this
                }
                else{
                    low = mid+1;                           // Notice this. If we put, `low = mid` It never converges.
                }
            }
            
            vector<ll> result;
            for (ll i = 0; i <n ; i++){
                if (input[i] >= sorted_input[high]){
                    result.push_back(i+1);
                }
            }
    
            cout << result.size() << endl;
            for (ll i = 0; i< result.size() ; i++){
                cout << result[i] << " ";
            }
    
            cout << endl;
    
        }
    
        return 0;
    }

    ```
## upper_bound & lower_bound

- `upper_bound` :

- Returns an iterator pointing to the first element in the range [first,last) `which compares greater than val.`
- There are 2 versions. The elements are compared using operator< for the first version, and comp for the second. 
- **The elements in the range shall already be sorted according to this same criterion (operator< or comp), or at least partitioned with respect to val.**
- Unlike lower_bound, the value pointed by the iterator returned by this function cannot be equivalent to val, only greater.
#### Searches for the first value which is greater than val given.  

- In order to find the Maximum element in a sorted vector (or any sorted container) which is less than  or equal to a given Value, `val`
  We can use `upper_bound`.
  i.e I want to find a value which is maximum among all the values that are less than or equal to 15 in vector v = {1,13,14,14,15,16,17,18};

```
  auto itr = upper_bound(v.begin(), v.end(), 15);
  itr--;
  int required_number = *itr;
````
 

- `lower_bound` : Returns an iterator pointing to the first element in the range [first,last) which `does not compare less than val.`
- There are 2 versions. The elements are compared using operator< for the first version, and comp for the second. 
- **The elements in the range shall already be sorted according to this same criterion (operator< or comp), or at least partitioned with respect to val.**
- Unlike upper_bound, the value pointed by the iterator returned by this function may also be equivalent to val, and not only greater.
#### Searches for the first value which is greater than or equal to val given.

```

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}

Result : 
lower_bound at position 3
upper_bound at position 6

```

- For multisets,  `auto itr =  s.upper_bound(val);` is faster than `auto itr =  upper_bound(s.begin(), s.end(), val);`

- In questions, Where we are using DP & we are supposed to make Matrices/Tables, Make them as Global Variables with the Maximum Size required based on the Constraints mentioned in the Problem Statement. Example for Reference [here](https://codeforces.com/contest/1498/submission/111851989
-
    ```
    #define lbd(a,x) lower_bound(all((a)),(x)) - (a).begin()
    #define ubd(a,x) upper_bound(all((a)),(x)) - (a).begin()
    ```
    When using the above Macros. If result returned is equal to `a.size()`; It means, corresponding bound doesnot exist for `x`. 
    ```
    vi check = {1,2,3};
    int a = lbd(check,4);
    int b =  ubd(check,4);

    // Here a == 3 & b==3 which means `4` doesnot have either upper_bound or lower_bound in the given vector (check). 
    ```

## Removing elements from Vector

```
vector<int> v = {1,2,3,4,5};

// Removes all the elements of the vector & makes it size 0.
v.clear();   


// To remove the elements of the vector using position, we use erase.

v.erase(itr);                   // Removes the single element at given position, itr.
v.erase(start_itr, end_itr);    // Removes a range of elements ([start_itr, end_itr))

```
IMPORTANT : Remove an element from the vector using an element.
- std::remove : It doesn’t actually delete elements from the container but only shunts non-deleted elements forwards on top of deleted elements.
- std::remove does not actually erase the element from the container, but it does return the new end iterator which can be passed to container_type::erase to do the REAL  removal of the extra elements that are now at the end of the container.

For this task, we use the [erase-remove](https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom) idiom.
```
bool IsOdd(int i) { return i & 1; }

void Print(const std::vector<int>& vec) {
  for (const auto& i : vec) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int main() {
    // Initializes a vector that holds numbers from 0-9.
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Print(v);

    // Removes all elements with the value 5.
    v.erase(std::remove(v.begin(), v.end(), 5), v.end());
    Print(v);

    // Removes all odd numbers.
    v.erase(std::remove_if(v.begin(), v.end(), IsOdd), v.end());
    Print(v);
}

/*
Output:
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 6 7 8 9
0 2 4 6 8
*/
```
- If we need `⌈m/a⌉` i.e Ceil of m/a, Performing `ceil(m/a)` will yield wrong value, since C++ rounds the value inside itself after performing divisio. So we need to use `ceil(m/(float)a)` or **the other option is to use `( ( m + (a-1) ) /a)` to get the value of Ceil of m/a.**

- Whenever TLE occurs, First think in terms of DP, Think whether same SUB PROBLEM is being repeatedly called or not.
Then if DP is suitable, First pre calculate using the maximum values provided in the question.

- In Questions, where answer%MOD is asked, **Dont use** `unsigned`.
Instead, simply use, `#define ll long long` and take Mod at every step in the solution, where the numbers can overflow.
Whenever there is a chance of overflowing, using the `ll` at every position instead of `int` creates no ERRORS. It helps.
  
- In C++
    - We cant modify the element of a set, We can just remove or insert elements.
    - We cant modify the existing `key` of a map i.e, we cant change the first element in the pair, We can just remove or insert keys. 
    - We can modify the `value` of the existing `key`, eg: mymap['key']++;

- `Deques` are faster for insertion/deletion of elements at the beginning than `vectors`.
- Using Builtin functions from GCC also helps in Bit Manipulations. Refer this [link](https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/)
- When dealing with multiplications/additions of numbers using `ll` be very careful & declare the `type` of the temporary values too. Also when using the `pow` to raise power of numbers. 

- Use `size()`
 ```
  vl a = {1,2,3,4,4};
  ll n = sizeof(a) / sizeof(a[0])     // This way of computing vector size when dealing with vector of LONG LONG yields incorrect value.
  ll n = a.size();                    // Works
```
- All Interactive Problems need not use BINARY/TERNARY SEARCH approach. They can be Constructive in nature too. Example [here](https://codeforces.com/contest/1521/problem/C)

- Sometimes, using Normal arrays is better than using complicated containers like multimap,etc. [Ex](https://codeforces.com/contest/1515/submission/116906408)
-  With the current template, we have a bug here :

```
  vll results;
  // `results` store the subsets of a given vector.


  fr(i,0,results.size()-1){
      ll size = ( results[i].size()-1 );  
      fr(j, 0, size){                                     // This works. but  `fr(j, 0,  results[i].size()-1 ){  }` wont work.
          cout << results[i][j] << " ";                   // becoz, the template just expects direct value. It cant do the computation (+,-..) there. 
      }
      cout << endl;
  }
```

DP Notes :
- In Recursive Memoisation, Usually we will have conditions for validation ( like out of possible Indices) which need not be included in the DP/Lookup table. We just need to return some values like 0/1/INT_MAX/INT_MIN/something depending on the context.
- So structure/order of Recursive Memoisation looks somewhat like :
   VALIDATION -> LOOKUP -> BASE CASE -> RECURSIVE STEP -> STORE in LOOKUP & RETURN.
- In CF Contests, Recursive always works. But sometimes may be difficult to think. Some times on GFG/LEETCODE/Interview Bit, It may yield TLE. So, 1st try for RECURSIVE always, If it fails or gives TLE/Memory exceeded go for ITERATIVE. Its anyhow very easy to convert Recursive to Iterative. Just need to think which subproblem to be solved first. ( TOPOLOGICAL SORTING. )
- Its always advisable to have the dp table of size `n+1` for `n` input in both approaches of DP 
- Sometimes, Iterative way is easy to think of & implement than the recursive one. In those cases, implement Iterative one only.
- Also, In some cases, We may need to use the `map/unordered_map` to act as DP table instead of `vvl`. In those cases, Lookup is like `map_name.count(Name) != 0` instead of `dp[i] != -1`.
- Note that, Sometimes even DP gives TLE, then the solution expected from us is most likely a GREEDY one.
- Also, It is not that any problem can be solved by DP, But most of the Optimisation Problems/Counting Problems/CheckIfPossible type can be solved. If even thinking for a while, made all kinds of subproblems, but unable to relate them to original subproblem, It means that OPTIMAL SUBSTRUCTURE may be missing for that particular problem though Overlapping subproblems are present. In those cases, since DP is not going to help, Try Greedy/Recursive BackTracking/Divide&Conquer.  
- Note that DP is mostly helpful in reducing Exponential (say 2^n) Time Complexities to Polynomial (say n^2). But in some cases,
Even DP gives TLE/ Memory Limit Exceeded. In those cases, Either Memory efficient DP (usually Bottom up with clever space optimisation) may help. Even if that fails/ unable to make it a Space efficient one, Try GREEDY approach. It really solves problems in such scenarios. In some cases, Just Observation of the exact logic & using bruteforce works even better. Example [here.](https://codeforces.com/contest/1485/problem/B)
- In some DP problems, We might encounter most famous recurrences like Fibonacci, Catalan. They are hidden inside the Problem. If we carefully analyse, we can very easily solve them. [Example](https://codeforces.com/contest/1245/submission/120350792). 
So, be thorough with all the standard/classic DP Problems. All the remaining are just the variants of these!!
- DP with Strings/Arrays:
  Subproblems are usually -> Prefixes [ Top.sort order: 0,1....n-1 ],
                          -> Suffixes [ Top.sort order: n-1,n-2,...0 ],
                          -> Subarrays[ Top.sort order: increasing order of sizes of subarrays ], 
                          -> Subsets ( using Bitmasks )

- In Dp, Once Recurrence is known and inorder to implement BOTTOM UP approach, Dont blindly write `for` loops.
  See the Topological sorted order. Just simple observation of recurrence lets us find which quantity is to be computed first. 
  One standard example : `dp[i][j] = dp[i+1][j-1];` dp[i + 1][j - 1] should be calculated before  dp[i][j]. That is, i is decreasing during the bottop-up dp implementation, and `j` is increasing or the dist between i and j is increasing, that's why :
   ```
   // Method-1:
  // i is decreasing & dist is increasing
   int len = str.size();
   for (int i = len - 1; i >= 0; i--) {
            for (int dist = 0; dist < len - i; dist++) {
                int j = i+dist
        }
   }

    // Method-2: (Intuitive)
    // i is decreasing & j is increasing
    for(int i = len-1; i >= 0; i--){    
        for(int j = i; j < len; j++){          
   ```
                           
- DP subproblems when dealing with subsequences/substrings/subarrays:
    DP[i] -> Required quantity for the subsequences/substrings/subarrays that END/BEGIN at index `i` 

- Many subarrray/substring problems can be solved using SLIDING WINDOW/ TWO POINTERS methods/ Prefix Sums.

- Some problems involving subarrays can be solved very cleverly using prefix sums. Once we find prefix sums,
we group all the prefix sums based on their value. Since we need to select to indices (l,r) to make a subarray, we are likely to use `N^C_2` where `N` represents the number of prefix indices with same value.
This type of relations are intutive if we are some how able to relate the answer (subarray) with prefixes. 
[Example.](https://codeforces.com/problemset/problem/1398/C)

- When ever we have more parameters in DP_states, try to think in a way similar to `/CP/References/DP_Notes_MIT/MIT6_006F11_lec22.pdf  Page-2`
- Sometimes, DP problem seems very difficult to solve. They may be asking to find the set of quantities that give the maximum/ minium result. In such cases, First solve the problem of a simpler DP which is just finding the maximum result value first. Then we can just use the Parent pointer sort of thing using argmin/argmax and construct the entire required solution. 
- In Bitmasks DP problems, One standard trick we use to evaluate `(S\x)` i.e. removing element `x` from the subset `S` given that `S` contains `x` is as follows:
    ```
    if ( S & (1 << x) ){
        int newsubset =  ( S^(1 << x ) );
    }
    ```
- In DP, Dont think that all similar problems have exactly same recurrences, They might look exactly similar but might differ at one corner depending on the problem, which makes your solution as complete wrong. So, be very careful while constructing a Recurrence. 
Example: 
`Main\Problem_Solving_Paradigms\3. DP\Practise_IB_Hubs_Rec_Mem\1.Coin_Change.cc  LINE 85`
vs `Main\Problem_Solving_Paradigms\3. DP\Practise_IB_Hubs_Rec_Mem\3.Check_Subset_Sum_Iter.cc  LINE 69`
- In some Bottom Up DP, Ordering of the for loops might also cause the difference in execution time and may yield TLE. Ex: [1](https://cses.fi/problemset/result/2569297/) vs [2](https://cses.fi/problemset/result/2569295/) 

- If we are sure that, all the quantities are positive & they are very large, we can use , `unsigned long long` instead of `long long`
- If we declare Vector with Initialisation in Global & take size of vector from INPUT in the Local Function, It gives unexpected errors since `n` gets random value in the beginning & the corresponding sized vector may be created.
   ```
   ll n;
   vl dp(n+1,-1);


   void solve(){
       cin >> n ;;
       ....
   }
    ```
- Note that `Segmentation fault (core dumped)` error may arise even when u exceeded the Memory provided, i.e. Stack overflow due to many recursive calls. Read more cases [here](https://www.geeksforgeeks.org/core-dump-segmentation-fault-c-cpp/)

- Keeping track of the Current Max element in STACK : 
An efficient approach would be to maintain an auxiliary stack while pushing element in the main stack. This auxiliary stack will keep track of the maximum element.

    Steps :
    1. Create an auxiliary stack, say ‘trackStack’ to keep the track of maximum element
    2. Push the first element to both mainStack and the trackStack.
    3. Now from the second element, push the element to the main stack. Compare the element with the top element of the track stack, if the current element is greater than the top of trackStack then push the current element to trackStack otherwise push the top element of trackStack again into it.
    4. If we pop an element from the main stack, then pop an element from the trackStack as well.
    5. Now to compute the maximum of the main stack at any point, we can simply print the top element of Track stack.

```
class StackWithMax
{
    // main stack
    stack<ll> mainStack;
  
    // stack to keep track of max element
    stack<ll> trackStack;
  
public:
    void push(ll x)
    {
        mainStack.push(x);
        if (mainStack.size() == 1)
        {
            trackStack.push(x);
            return;
        }
  
        if (x > trackStack.top())
            trackStack.push(x);
        else
            trackStack.push(trackStack.top());
    }
  
    ll getMax()
    {
        return trackStack.top();
    }
  
    ll pop()
    {
        mainStack.pop();
        trackStack.pop();
        return 0;
    }

    ll empty()
    {
        return mainStack.empty();
    }

    ll top()
    {   ll ele = mainStack.top();
        return ele;
    }
};

// Using in Code :
StackWithMax s;
s.push(1);
s.getMax();

Note that only functions defined above can be used with the class. All builtins are not possible (obviously).
```

Time Complexity : O(1)

Auxiliary Complexity : O(n)

Reference : [Link](https://www.geeksforgeeks.org/tracking-current-maximum-element-in-a-stack/)

- Checking whether a given string of brackets is a regular bracket sequence or not :
- A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example, bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)" whereas ")(", "((()" and ")" are not.

```
// From GFG
bool isBalanced(string exp)
{
    // Initialising Variables
    bool flag = true;
    int count = 0;
  
    // Traversing the Expression
    for (int i = 0; i < exp.size(); i++) {
  
        if (exp[i] == '(') {
            count++;
        }
        else {
            // It is a closing parenthesis
            count--;
        }
        if (count < 0) {
            // This means there are
            // more Closing parenthesis
            // than opening ones
            flag = false;
            break;
        }
    }
  
    // If count is not zero,
    // It means there are more
    // opening parenthesis
    if (count != 0) {
        flag = false;
    }
  
    return flag;
}
```
- Some times, zero indexing simplifes the problem. 
i.e. treating 1,2,3,4,5.. as 0,1,2,3,4,..
Ex : [here](https://codeforces.com/contest/1487/submission/118125075)

- Most of the A,B problems sometimes C too in CF Div-2 rounds are just based on the careful observation & simple implementation. So, Just do careful analysis & get the logic from the given test cases, then test them on custom corner cases without hurry, submit!

- Number of inversions in a Palindrome remains the same irrespective of the values they contain. [Usage](https://codeforces.com/contest/1473/problem/C)

- Proper usage of Hash Tables (map) can make O(n^2) solution to O(n) very easily. Mostly traversing of arrays/vectors can be onverted to lookups in Hash Tables based on constraints. [Example](https://codeforces.com/contest/1481/problem/C)  

- Its always advisable to use **-INF** ( We already defined INF as `INF = 1e18;` in our template)  to represent very small numbers during computation instead of using INT_MIN. [Example](https://www.codechef.com/viewsolution/47463019)

- To calculate the number of substrings of a given string that satisy a particular property, We can use:
```
// Note that number of sustrings that end at index i, is equal to string length (i+1) . (0 based indexing) 
// Hence total substrings of a given string, is  summation over i from 0 to n-1 ( sustrings that end at index i.)
```
Refer this example for more clarity : [here](https://codeforces.com/contest/1535/submission/118571314)

- Note that in some problems, where DP is being used & `long long` is NOT REQUIRED, using the `long long` may lead to RUN TIME ERROR/ MEMORY LIMIT EXCEEDED becoz we allocate a `vector<vector<long long>> dp` which may exceed the given constraints. [Example](https://cses.fi/problemset/task/1636/) So, use `int` in all the DP PROBLEMS unless it is required. Maximum value possible is `2147483647` ~ `1e9`. So If values are larger than `1e9` in DP then only use `ll` else use `int`.

- When taking input in a loop, dont print the answer & return in middle once answer is known. Take all the lements as input for that testcase & then print the answer. Otherwise the onput from current testcase will go to next testcase & will cause WRONG RESULTS. [Ex](https://codeforces.com/contest/1536/submission/118691508)

- In the case of `string` problems, Though the problem looks very complicated in the beginning, If we carefully look at the constraints on the string length, & the characters being involved in the input string, Even Bruteforce will solve the problem since we usually have only `26` characters!!
[Example1](https://codeforces.com/contest/1536/problem/B)
[Example2](https://codeforces.com/contest/1451/submission/120954157)

- Moreover, sometimes, Constraints give a hint on which part of the problem can be calculated using BRUTEFORCE approach. [Example](https://codeforces.com/contest/1474/submission/119965586)

- For a string of size n, 
No of substrings of length 1 is n
No of substrings of length 2 is n-1
No of substrings of length 3 is n-2
So, There are at most n + n−1 + n−2 = 3n−3 possible substrings of length 3 or shorter in the input. 

- Checking if a substring is present in a given string can be done as :
`orig_str.find(some_string) == string::npos` --> If `True`, It means given substring(some_string) is not present in the original string(orig_str).

- Habituate to use Arrays for DP instead of Vectors since if more states are there, Making a Vector of vectors & initialisation is difficult and not easy to read.
Ex: `ll dp[A][B][C][D]; memset(dp,-1,sizeof(dp));` vs `vvvvl(A, vvvl(B, vvl(C, vl(D,-1))))`

```
small = min(x, min(y, min(z, k))); // the old way
small = min({x, y, z, k});         // This can be done.
```

```
pair<int, int> cur = {1, 2};
auto [x, y] = cur;
// x is now 1, y is now 2
// no need of cur.first and cur.second

array<int, 3> arr = {1, 0, -1};
auto [a, b, c] = arr;
// a is now 1, b is now 0, c is now -1
```
- To find the Maximum Subarray Sum of Length atleast k in O(N) using Prefix Sum array, refer this [example](https://codeforces.com/contest/1486/submission/119761728)

- For some problems which seem very difficult to come up with a EFFICIENT ALGORITHM, By seeing the Constraints of the Problem, Some times
 we will be able to solve the problem very easily by careful observation that yields a simple algo which makes sure that the maximum constraint problem passes in given Time & Space Complexity. [Example](https://codeforces.com/contest/1469/submission/119768088).
 So do look at the Constraints of the problem in the beginning itself.

 - Note that, No of times we need to divide a number(a) by a number (b) to make the number a = 1, is `Ceil(logb(a))` i.e, Ceil ( Log(a) to the base b ) .   

- To check for the number of occurences of a substring in a given string, If length of substring is very less, We can assume that it is done O(N) though O(N^2)[Example](https://codeforces.com/contest/1379/submission/120019949). But in general it is done using [KMP Algorithm](https://www.geeksforgeeks.org/frequency-substring-string/) in O(M+N) time.

- Declare the DP array, Extra arrays, Graphs, in the global Namespace & clear them for each test case instead of passing them to functions as arguments since it is too ugly while writing RECURSIVE functions.


Graphs/Trees Notes:
- Be careful abt the numbering of the vertcies being used in the problem. Sometimes it may be from [ 1,2,..N ] or [ 0,1,2,,..N-1]
so, when using pre-written codes, make necessary changes according to the problem.

- In most of the Tree DP, Its just the usual DFS/BFS. We just need to add the Lookup & Base cases in the beginning & inside the loop of children of the current node: when ( e != s )  -> while making recursive call, we do some computation & store inside DP Table. 

- Note that Tree is always connected. So  there is no need to perform BFS/DFS more than once to traverse it.
- Get the intuition ( or Naive Proof ) behind using Two DFS's or Two BFS's for solving a problem.
- When using the pre-written codes related to graphs/trees in contests, make sure to check the Node values ranges. They may lie between [0,N-1] or [1,N].
-  Many of the Tree problems reduce to DP by just rooting the tree at some node & thinking on what are the possibilites for the root node to solve the problem such that we can make similar sub problems. Then, in most cases, our subproblems are all the Subtrees rooted at each node.
- So, start solving the problem by DRAWING a general tree on Paper rooted at some node & think how to break the problem into subproblems!
- Filling 2D DP in Trees can be tricky, Refer this classic [Example](https://codeforces.com/contest/161/submission/121837651).
- Note that multiple answers are present while performing a BFS/DFS depending upon the order in which adjacent elements are considered.
- Marking the colors of the nodes while traversing using BFS/DFS as `BLACK` (or some other thing) when a node is completely processed helps in optimising traversal of vertices in some algorithms. Refer BFS/DFS using_colors for clarity.
- Some points to note when dealing with `Shortest Paths`:

    shortest path - with no weights -> ( bfs always )

    shortest path - with weights as 0/1 - > (0/1 bfs always )

    shortest path - with any weights( without -ve edge cycle ) -> (DFS with DP) / (BFS) / (dijkstra)

- When we are performing BFS/ MultiSource BFS for finding shortest path/similar quantity on Matrices/Grids,
we rarely use `visited`. Instead we use `distance` using which we push the elements into the Queue.

    Example1: Data_Structures\10.Graphs_and_Trees\Basics_and_Traversal\MultiSource_BFS_Ex2.cc

    Example2: Data_Structures\10.Graphs_and_Trees\Basics_and_Traversal\Normal_BFS_for_Multi_Ex2.cc
    Also, We need NOT explicitly write down all the adjacent/ reachable cells of grid. We can directly use for loops :)

- Bipartite Graph:
    A bipartite graph (or bigraph) is a graph whose vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V. Vertex sets U and V are usually called the parts of the graph.
    - A graph is bipartite if and only if it does not contain an odd cycle.
    - A graph is bipartite if and only if it is 2-colorable, (i.e. its chromatic number is less than or equal to 2).
    - All trees are bipartite. 

- Note that, In any Tree:
    - The depth of node u is means there are dep_u nodes on the path (ROOT -> u)
    - The size of the subtree rooted on node u means that there are siz_u nodes v that u is on the path (ROOT -> v)

-  In many Problems of Graphs/ Trees, If we are asked to choose some number of nodes (say k) such that a given quantity (say Q) is Minimised/Maximised/similar.., One approach for solving those type of Qs is performing a BFS/DFS on the given Graph/ Tree and evaluating & storing some value ( that helps in evaluating Q ) using DYNAMIC PROGRAMMING during traversal. After that, we just perform relevant operations on the stored values & select the nodes appropriately. [Example](https://codeforces.com/problemset/problem/1336/A) 

Binary Trees:
- The AVERAGE space Complexity of PreOrder, PostOrder, InOrder Traversal in O(h) not O(n) for both Recursive/Iterative. where h = O(logn),
h -> Height of the tree, n-> Number of nodes in the tree. But WORST CASE SPACE Complexity is still O(n).
1. Because, In Iterative approach, The Stack/Queue data structures wont get filled to a size of `n`, they get filled & popped & on average only O(logn) elements stay. 
2. In recursive approach, The addresses are removed from the stack when returning. This space is re-used when making a new call from a level closer to the root. So the maximum numbers of memory addresses on the stack at the same time is the tree height.
- In all the 4 types of traversals, we pass the `root` of the tree to the function to initiate the traversal.
- To traverse the tree from bottom to up, use the POST ORDER TRAVERSAL which means the node is visited only after the LEFT & RIGHT CHILDREN are visited, which inturn makes sure that we move from Bottom to Top, i.e. Leaves to Root of the tree. 
Example : `Competitive_Programming\Main\Data_Structures\10.Graphs_and_Trees\Trees\Binary_Trees\Maximum_Sum_Path_in_Tree.cc`
- Level order traversal ignoring the nulls can be used as the order in which the nodes are inserted into the BST & one can build BST using `insert`, if we know that the given Level Order traversal corresponds to a BST already and all the elements in the BST are UNIQUE.
- If the Level Order of a BST is given where the nodes can have same elements (i.e, Non unique values), we cant construct the BST using `insert`. We need to use the general way of constructing a BINARY TREE from given LEVEL order Traversal.
- Most of the Binary Tree problems that look very difficult at the first look can actually be solved very easily by just performing some traversal (Pre/Post/In/Level) and computing some quantities like Levels, HorizLevels, etc. Example: `Competitive_Programming\Main\Data_Structures\10.Graphs_and_Trees\Trees\Binary_Trees\Vertical_Order_Traversal.cc`

- std::memset, as is the case for any function, can only be called within a function. We can't simply call it in "global scope". [Example](https://stackoverflow.com/questions/40871661/error-expected-constructor-destructor-or-type-conversion-before-token-a)

- Standard ways to improve O(N) to O(logN):
1. Divide by two: 
    - Binary Search
    - Divide & Conquer
2. Powers of two:
    - Segment Trees
    - Binary Lifting
    - Sparse Tables

- Every number can be represented as sum of powers of two (Use Binary Representation)

- Sometimes O(n^2) solutions can be converted into O(nlogn) solution if we use the method followed in Sieve of Eratosthenes, given that all the elements are distinct & range of elements is not so large( <= 2*1e5 ). The idea is to iterate of the multiples of a particular number within the given range. [Example](https://codeforces.com/contest/1541/submission/120944671)

- Whenever large numbers are present, to use the digits, DONT CONVERT IT INTO STRING & THEN USE BY INDEX. **Instead, Access the digits by dividing the number by 10 & take reminders and store them in vector as shown below**. Also sometimes using `set` when not needed instead of vector can also lead to TLE. So use them only when required. **Examples:** [1](https://codeforces.com/contest/1465/submission/121335679)  [2](https://codeforces.com/contest/1465/submission/101869576)
    ```
    vi dig;
    int x = n;
    while(x){
        dig.pb(x%10);
        x /= 10;
    }
    ```

- In many Ad-hoc / Observation based questions ( Especially in CF ), The ordering of the elements( indices ) does not matter though there is a explicit condition in question. A careful observation of this fact makes the problem solvable very easily. [Example](https://codeforces.com/contest/1406/problem/B)

- Try avoiding passing of vectors/some other large Data Strutures as arguments to functions. Even if we pass,
Pass by reference `&`, otherwise it may lead to TLE.
- Note that `int n = sizeof(arr)/sizeof(arr[0])` wont be accurate for Vectors unlike for arrays, since Vectors are dynamic in nature & also the way the contents of vectors are stored inside memory are different. So, always use arr.size() for vectors!

- Sometimes, using Vector can cause TLE when compared to vector. 
 Example -> [vector](https://cses.fi/problemset/result/2495316/), [array](https://cses.fi/problemset/result/2495314/)

- Converting `char` to `std::string`:
    ```
    char c = 'g';
    string str(1, c);
    cout << str; // It prints `g`
    ```
- Taking a string with spaces as input, i.e. Taking entire line as input into a string. Becareful with new lines, `\n` when using this syntax, `getline(cin,str)` with normal inputs, `cin >> a` simultaneously.
    ```
    string str;
    getline(cin, str);
    ```
-  Most of the `parenthesis matching` problems can be solved by just tracking the count of Opening & Closing parenthesis & counting valid sets every time they encounter a CLOSING BRACKET. Also sometimes, Stacks/queues may be useful.
- Dont get confused with `Ternary Operator expression` in C++. It is `Expression = ( Conditional ) ? Value1 : Value2 `. If conditional is True, Value1 is assigned to expression, else Value2.
- Basic techniques like Two Pointers, Sliding Window are helpful for reducing O(n^2) or more complex solutions to O(n) easily in many problems. 
- To deal with string character frequencies, We can use their ascii values ( `cnt[s[i]]++` ) instead of `cnt[s[i]-'0']++ or cnt[s[i]-'a']++`
- When we are supposed to find the maximum / minimum in O(1) time instead of O(N), we can do it using prefix & suffix arrays. [Example](https://leetcode.com/contest/weekly-contest-250/problems/maximum-number-of-points-with-cost/)
- Many problems can be solved using LPS array used in KMP algorithm. Mostly that deal with prefix & suffix substrings equality like Palindromic property,etc. Example: `Competitive_Programming\Main\Topic_Wise\String_Algorithms\Problems\Min_Chars_remov_Palindrome.cc` 

# Maths:

-  GCD(i, i+1) = 1 for all i>= 1
-  Catalan numbers satisfy the following recurrence relation :
    ![image info](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-6e37684751c57a980ebaca5148b4736a_l3.svg)
- There are lots of applciations of [Catalan Numbers](https://www.geeksforgeeks.org/applications-of-catalan-numbers/)

- Fibonacci Numbers are : F0 = 0, F1 = 1, Fn = Fn-1 + Fn-2.  Note that these sequences may occur in general problems too.

Check if Integer (X) can be written as a summation of Integral Multiple of two numbers.
Ex : X, 11, 111

```
X = a*11 + b*111    // a, b are Integers
``` 
- Trick is to express coefficient of bigger number in terms of smaller number so that we can BRUTEFORCE easily.

```
b = c*11 + d,  Here   0 <= d < 11   // c, d are Integers

X = a*11 + ( c*11 + d )*111

X = 11*( a + c* 111 ) + d*111
```
Now we can bruteforce as follows. For each value of d, subtract d*111 from X & check if the result % 11 == 0.

- Sum-Xor property: `(a+b) = ( a⊕b + 2(a&b) )`. Extended Version with two equations: `(a+b) = ( a|b + a&b AND a⊕b ) = (a|b − a&b).` [Example.](https://codeforces.com/problemset/problem/1325/D)

- The pigeonhole principle states that if `n` items are put into `m` containers, with `n>m`, then at least one container must contain more than one item.

GCD Properties :
- gcd{a,b} = gcd{|a|,b} = gcd{a,|b|} = gcd{|a|,|b|}  So, the result of gcd should always be printed as POSITIVE. 
- If a > b, GCD(a,b) = GCD(b, a%b)
- gcd(a,b,c) = gcd(a,gcd(b,c)) = gcd(gcd(a,b),c)                       // Associative
- gcd(a,b)=gcd(a,b−a) = gcd(a-b,b)                                     // Take abs for difference terms.
- GCD(x,y) = GCD(x−y,y). The same applies for multiple arguments: GCD(x,y,z,…) = GCD(x−y,y,z,…) . Note that we have to assume that GCD of an empty set is 0, and GCD(x,0)=x for any x, since 0 is the only number divisible by any other number. So start by initialising gcd to 0. [Example](https://codeforces.com/contest/1459/submission/119794117)
- Then we can extend to multiple arguments by mathematical induction :

    **gcd(a1,a2,⋯,an−2,an−1,an)** 

    =gcd(a1,a2,⋯,an−2,gcd(an−1,an))

    =gcd(a1,a2,⋯,an−2,gcd(an−1,an−an−1))

    =gcd(a1,a2,⋯,an−2,an−1,an−an−1)

    =gcd(a1,a2,⋯,gcd(an−2,an−1),an−an−1)

    =gcd(a1,a2,⋯,gcd(an−2,an−1−an−2),an−an−1)

    =gcd(a1,a2,⋯,an−2,an−1−an−2,an−an−1)

    ⋯

    =gcd(a1,a2−a1,⋯,an−1−an−2,an−an−1)

    We do not need to choose adjacent differences. gcd(a1,a2,⋯,an−2,an−1,an) is also equal to gcd(a1,a2−a1,⋯,an−1−a1,an−a1), which can be proved similarly.

- When answer is P/Q, we are usually asked to print, `P * Q^(−1) modulo 10^9+7, where Q^(−1) is the multiplicative inverse of Q modulo 10^9+7`
  To find, Multiplicative inverse of Q modulo M  use `Q_inv =  modpow(Q, M-2)`

- Also, Many problems which take O(n^2) in bruteforce can cleverly be brought down to O(n) by performing Two traversals, One from `right to Left` & other one from `Left to right` & similar ways.

- Sometimes, Problems where TLE is encountered & we know the range of answer we are trying to find, using Binary Search helps.
[Example](https://leetcode.com/submissions/detail/528147416/).
It also has a utility function that checks if a string is a subsequence of other. It is used quite often. We should be able to code it up faster in OA.
    ```
        // Check if str1 is a subsequence of str2.
        bool isSubSequence(string str1, string str2){
            int m = str1.size(), n = str2.size();
            
            int j = 0;
            
            // Iterate over the characters of bigger string. If any of its character matches with the current character of str1, increment index.
            for (int i = 0; i < n && j < m; i++)
                if (str1[j] == str2[i])
                    j++;
            
            // It means all the characters of str1 are covered.
            return (j == m);
        }
    ```
- Many Matrix/Grid Problems can be solved very easily by just performing a simple DFS/BFS from some/all positions & keeping track of required value during traversal. [Example](https://leetcode.com/problems/count-sub-islands/submissions/). Understand the problem's solution very clearly since it helps in lot of similar problems.
- Its not required that, whenever we see a word subsequence in the problem, we need to traverse all of them explicitly. In most of the cases,
We can do it by clever observation & taking min/max while traversing the entire array once. [Example](https://leetcode.com/problems/maximum-alternating-subsequence-sum/submissions/)

- When dealing with Long long, If we are adding any number, use `LL` suffix. Ex: `long long temp = 12121212123`, `temp += 1LL`. Else there may be overflow & Runtime error may occur. [Example](https://leetcode.com/problems/validate-binary-search-tree/submissions/)

- When ever we encounter a question related to `Queries`, we either solve it using some sort of `PRECOMPUTATION (either Prefix/Suffix/DP/Someother)` or `Segment Trees/Fenwick Trees`

- Given a string containing values separated by some delimeter (say `,`), Accessing each element using `getline, stringstream`:
```
string data = "my,name,is,sanjay";
stringstream ss(data);
string item;
while( getline(ss, item, ',')){  // Dont forget to pass the delimeter as `char` i.e single character enclosed in ''
    cout << item << "\n";
}
```
- Serialize and Deserialize Binary Tree vs Binary Search Tree:  
    - We can reconstruct BST by only using preorder(/postorder/levelorder) traversal.
    - However, in the binary tree situation, we need to use preorder(/postorder/levelorder) + inorder to reconstruct the tree. If we want to directly construct BT, we have to use "#" or "null".
    
    - One of the ways a BST tree is different from a general binary tree is its structure is wholly dependent on the order in which the values are inserted. A string created from a preorder traversal of a BST will tell you the order in which the values were inserted into the tree. - Since you just need the order the values were inserted, you do not need to account for null nodes in the string with "#" or "null". Hence, the final string contains only the values and separators, which makes it the most compact possible.
    - Note that the exact code used in binary tree can also be used in binary search tree too. But we used slightly different code since we are asked to do it in a compact form in the question.
    - Refer: https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/ and LEETCODE problems ( #297, #449 )

- In most of the `Two Pointer` algo problems, `while( left < right )` or  `while( left <= right )` are sufficient. [Example](https://leetcode.com/problems/container-with-most-water/)

- Rotating a matrix by 90 degrees/ similar problems can be solved by observation of how indices map after writing down the indices of original & rotated matrix. [Example](https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/#:~:text=16%2012%208%204-,Method%202%3A,-Approach%3A%20The%20approach)

- In C language LEETCODE submissions, When returning a pointer from function, We need to explicitly set the value of this `returnSize` variable (if present) to the size of array being returned by `*returnSize = SomeVal`. [Example](https://leetcode.com/problems/counting-bits/submissions/)
- Element from a vector can be removed by just using `v.erase(itr)`. If index is known, use `v.erase(v.begin()+i)` to remove the ith element from vector.
- Case Conversion:
    - transform : Performs a transformation on given array/string.
    - toupper(int c) : Returns upper case version of character c. If c is already in uppercase, return c itself.
    - tolower(int c) : Returns lower case version of character c. If c is already in lowercase, return c itself.
        string su = "Jatin Goyal";
        transform(su.begin(), su.end(), su.begin(), ::toupper);  // JATIN GOYAL
        transform(su.begin(), su.end(), su.begin(), ::tolower);  // jatin goyal

- When dealing with Linked Lists & Pointers, Dont forget allocating memory :)
  Ex: `ListNode *HEAD = new ListNode();` not just `ListNode *HEAD;`. [Detailed Example](https://leetcode.com/problems/reverse-linked-list/)

- Interesting Math Property:
// Count of integers that have exactly k digits & are divisible by a[i] but the first digit is not equal to b[i] is:
// The count of integers that have exactly k digits & are divisible by a[i](  [99999..k times] /a[i] ), 
// minus the count of integers that have exactly k digits & have 1st digit as b[i] & are divisible by a[i] (  [ b[i]9999..k-1 times] /a[i] ), 
// plus  the count of integers that have exactly k digits & have 1st digit as b[i]-1  (only if b[i] > 0) & are divisible by a[i] 
// (  [ b[i]-1 9999..k-1 times] /a[i] ) 
[Example](https://codeforces.com/contest/595/problem/B)

- Divide & conquer is underrated. But it comes very handy in some cases. We usually use the appraoch when problem can be broken down into
INDEPENDENT sub problems. [Example: Merge K sorted Linked Lists](https://leetcode.com/problems/merge-k-sorted-lists/submissions/)
- Be careful with Global declarations of variables. At lines `1467-1468`, If we place   
`int ans = 0, m = grid.size(), n = grid[0].size(), N = n, M = m;`  The values of M & N will not be updated. They remain `0`.
    ```
    class Solution {
    public:
        int cnt = 0, N, M;
        void dfs(int i, int j, vector<vector<int>>& grid ){
            if ( i < 0 or i >= M or j < 0 or j >= N  or grid[i][j] == 0){
                return;
            }
            grid[i][j] = 0;
            cnt++;
            dfs(i,j+1,grid);
            dfs(i+1,j,grid);
            dfs(i-1,j,grid);
            dfs(i,j-1,grid);
        }
        
        
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int ans = 0, m = grid.size(), n = grid[0].size();
            N = n, M = m;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if (grid[i][j] == 1){
                        dfs(i,j, grid); 
                        ans = max(ans, cnt);
                        cnt = 0;
                    }
                }
            }
            return ans;
        }
    };
    ```
- Count Divisors of n:  This approach takes O(sqrt(n)) time. 
    ```
    // C implementation of Naive method to count all
    // divisors
    #include <bits/stdc++.h>
    using namespace std;

    // function to count the divisors
    int countDivisors(int n)
    {
        int cnt = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                // If divisors are equal,
                // count only one
                if (n / i == i)
                    cnt++;

                else // Otherwise count both
                    cnt = cnt + 2;
            }
        }
        return cnt;
    }

    /* Driver program to test above function */
    int main()
    {
        printf("Total distinct divisors of 100 are : %d",
            countDivisors(100));
        return 0;
    }

    ```
  - A number usually has its Factors/Divisors in pairs. To check whether the number of divisors of a number is EVEN/ODD, we can use this fact.
    For perfect squares, due to the double divisor, they have Odd number of divisors but rest all Non perfect square numbers have Even number of divisors.
    - Ex: Divisors come in pairs, like i=12 has divisors 1 and 12, 2 and 6, and 3 and 4. --> #divisors = 6
    - Except when i is a square, like 36 has divisors 1 and 36, 2 and 18, 3 and 12, 4 and 9, and double divisor 6. -->  #divisors = 9
  - Count of numbers in [1,n] which are perfect squares is just `sqrt(n)`.
- Using `C` builtin `qsort`:
    ```
    // sorts an array in ascending order
    int comparator (const void * p1, const void * p2){
    return (*(int*)p1 - *(int*)p2);
    }

    int main() {
        int n = 5;
        int input[] = {3, 7, 5, 6, 2}; int sum = 0;
        qsort(input, n, sizeof(int), comparator);
    }
    ```

## Estimating Efficiency of Algorithms:
### 1. TIME COMPLEXITY

- The answer to this question is directly related to the number of operations that are allowed to perform within a second. Most of the sites these days allow **10^8 operations per second**, only a few sites still allow 10^7 operations. After figuring out the number of operations that can be performed, search for the right complexity by looking at the constraints given in the problem.

- In any problem in competitive programming, you are given the time limit for running of the program (usually 1 second) and the constraints on the input data. **Also, it is important to know that computers can perform about 10^7 to 10^8 individual operations per second.** Based on this, some estimates on the time complexity of your algorithm can be made, based on the constraints on the input:

    - [Ref](https://blogtech.online/competitive-programming-and-time-complexity/):

    Constraint   	Required Time Complexity

    n <= 10	         O(n!)

    n <= 20	         O(2^n)

    n <= 500	     O(n^3)

    n <= 5000	     O(n^2)

    n <= 10^6	     O(n) or O(n log n)

    n can be > 10^6	 O(1) or O(log n) (and in some cases O(√n))

- Online Judge Restrictions: 
    TLE comes because the Online judge has some restriction that it will not allow to process the instruction after a certain Time limit given by Problem setter the problem(1 sec).

- Server Configuration:
    The exact time taken by the code depends on the speed of the server, the architecture of the server, OS, and certainly on the complexity of the algorithm. So different servers like practice, CodeChef, SPOJ, etc., may have different execution speeds. By estimating the maximum value of N (N is the total number of instructions of your whole code), you can roughly estimate the TLE would occur or not in 1 sec. 

- **[Imp]** Updated Table from [GFG](https://www.geeksforgeeks.org/overcome-time-limit-exceedtle/):

    MAX value of N                    Time complexity

    10^8                              O(N) Border case

    10^7                              O(N) Might be accepted

    10^6                              O(N) Perfect

    10^5                              O(N * logN)

    10^4                              O(N ^ 2)

    10^2                              O(N ^ 3)

    10^9                              O(logN) or Sqrt(N)

- However, one important limitation of time complexity is that it hides the constant factors (recall that the time complexity is O(n) whether the loop executes n or 10n or 20n times). These constant factors, though usually small, may have a significant effect on the actual running time of the algorithm.
- Additional [Ref.]( https://www.hackerearth.com/practice/basic-programming/complexity-analysis/time-and-space-complexity/tutorial/)

### 2. SPACE COMPLEXITY:
- Generally, all online platforms have the same memory limit as 256 MB. Users can only declare a **global 1-D array of size ~ 10^7**, not more than that. Or Multi Dimensional array of total ~ 10^7 elements.  Below is the exact analysis for `256 MB` 

- Lets assume `int` takes 4 bytes:   

    **256 MB = 256 x 10^6 bytes = 25.6 x 10^7 bytes ~  4 x ( 6 x 10^7 ) bytes. Can store ~ ( 6 x 10^7 ) `int` values i.e Integer array of size ` <= ( 6 x 10^7 )`.**

    **4 MB   = 4 x 10^6 bytes =  can store 10^6 `int` values. i.e. Integer array of size `10^6`.**

-  Maximum size of the array:       We must be knowing that the maximum size of array declared inside the main function is of the order of 10^6 but if you declare array globally then you can declare its size upto 10^7. [Ref.](https://www.geeksforgeeks.org/c-tricks-competitive-programming-c-11/)
- If one declared a global 1-D array of size > 10^7, an error called the memory limit exceeded (`MLE`) occurs, some online platforms can also give an error as a Segmentation Fault(`SIGSEGV`). 
- Note that trying to exceed the memory limit may sometimes result in other errors.
- An example would be if users are using `malloc` in C to allocate memory. If malloc fails because the user is trying to allocate too much, it simply returns a null pointer which, unless checked for it, would probably cause a `Run Time Error` when the user tries to use it.
- Similarly, trying to allocate too much memory in C++ using new would cause a `SIGABRT` and give `Run Time Error`.

- While solving problems using BackTracking it is not compuslory to use `visited`. Sometimes we directly use a vector/array to store the **parts of results.** Example: `Main\Problem_Solving_Paradigms\1. Complete_Search\Problems\Subsets_of_array.cc`
- Note that, In DFS on Grids, It's advisable to use `visited[i][j]` instead of altering the value at the `grid[i][j]` to avoid revisiting since it is easy to understand, implement and debug. [Example](https://codeforces.com/contest/377/problem/A).

- Simple Tricks from LinkedIn post:
    Must Known for a CP learner(Interview Prep. Oriented)

    If input array is sorted then
    - Binary search
    - Two pointers

    If asked for all permutations/subsets then
    - Backtracking

    If given a Tree/Graph then
    - DFS
    - BFS

    If given a linked list then
    - Two pointers

    If recursion is banned then
    - Stack

    If must solve in-place then
    - Swap corresponding values
    - Store one or more different values in the same pointer

    If asked for maximum/minumum subarray/subset/options then
    - Dynamic programming/SLIDING WINDOW/ TWO POINTERS methods/ Prefix Sums.

    If asked for top/least K items then
    - Heap

    If asked for common strings then
    - Map
    - Trie

    Else
    - Map/Set for O(1) time & O(n) space
    - Sort input for O(nlogn) time and O(1) space

- Transpose of a matrix is nothing but swapping the elements across the main diagonal. Notice the bounds of `for` loops in below code.
  If we use two complete for loops, it has no effect on the matrix since each pair gets swapped twice.
    ```
    void transform(vector<vector<int>>& matrix) {
            int n = matrix.size();
            for(int i = 0; i <n; i++){                  //  i : (0,...n-1)
                for(int j = i; j <n; j++){              //  j : (i,...n-1)
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
    }
    ```
    Rotating a matrix by 90 degrees can be thought of as a Transpose of a matrix followed by Reflection ( Reversing the row elements.)