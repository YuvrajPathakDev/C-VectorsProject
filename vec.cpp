#include<iostream>
#include <vector> 
#include <cmath>
class Vectors {
private: 
    std::vector<float> v ; 
   
public:

    Vectors(std::vector <float> v1) : v(v1) { //This doesn't create the empty vector v: it directly copies value of v1 
        // v = v1 ; 
    }
    
    void printVector () {
        for(float i: v){
            std::cout <<i<<std::endl; 

        }

    }

    void magnitudeVector() {

        float SumOfValuesSquared= 0.f  ; 
        // std::cout <<SumOfValuesSquared<<std::endl ; 
        for (float i :v ){  
            SumOfValuesSquared+= std::pow(i,2); 
            

        }
        // std::cout<<SumOfValuesSquared<<std::endl ; 
        std::cout <<"Magnitude is: "<<std::sqrt(SumOfValuesSquared)<<std::endl; 
        
        
    }

    Vectors operator +(const Vectors &other)const{
        std::vector<float>result ; 
        for(int i = 0 ; i < v.size(); i++ ){
            result.push_back(this->v[i]+ other.v[i]); 
        }
        return Vectors(result); 

        


    }


    
   
// MOST VEXING PARSE:
// I learned that some statements that look like object construction
// can be interpreted by C++ as function declarations.
// Example:
//     Vectors obj(std::vector<float>());
// The compiler treats this as a function declaration( function with return type Vectors ), not as an object.
// Using braces removes the ambiguity:
//     Vectors obj{std::vector<float>()};
// Note: In this program, `Vectors v1Object(v1);` is safe because `v1`
// is an existing variable, so the compiler knows an object is being created.



}; 


int main () {
    int numofValues ; 
    float num ; 
    
    std::vector <float> v1 ; 
    std::cout<<"Number of Values in Vector :  "<<std::endl ; 
    std::cin>>numofValues; 
    for (int i= 0  ; i < numofValues; i++ ){
        std::cout<<"Element"<<i+1<<" "; 
        std::cin>>num;
        v1.push_back(num); 
    }
    
    std::vector <float> v2 = {33.1,22.6,63.1}; 
    

    Vectors v1Object{v1}; 
    std::cout <<"First Vector\n"; 
    v1Object.printVector() ;
    std::cout<<"Magnitude of v1: ";
    v1Object.magnitudeVector() ;
    
    Vectors v2Object{v2}; 
    std::cout <<"Second Vector\n"; 
    v2Object.printVector() ;
    std::cout<<"Magnitude of v2: ";
    v2Object.magnitudeVector() ; 

    Vectors v3Object = v1Object+v2Object; 
    std::cout <<"v1 + v2 : \n"; 
    v3Object.printVector() ; 


    


    return 0 ; 
}