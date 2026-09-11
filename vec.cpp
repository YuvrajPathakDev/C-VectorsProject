#include<iostream>
#include <vector> 
#include <cmath>
#include <algorithm> //for clamp function
class Vectors {
private: 
    std::vector<float> v ; 
   
public:

    Vectors(std::vector <float> v1) : v(v1) { //This doesn't create the empty vector v: it directly copies value of v1 
        // v = v1 ; 
    }
    
    void printVector () const {
        std::cout<<"( "; 
        for(float i: v){
            std::cout <<i<<" "; 

        }
        std::cout<<")"<<std::endl <<std::endl; 

    }

    float magnitudeVector()const {

        float SumOfValuesSquared= 0.f  ; 
        // std::cout <<SumOfValuesSquared<<std::endl ; 
        for (float i :v ){  
            SumOfValuesSquared+= std::pow(i,2); 
            

        }
        // std::cout<<SumOfValuesSquared<<std::endl ; 
        // std::cout<<std::<<std::endl; 
        // std::cout<<std::endl ; 
        return sqrt(SumOfValuesSquared); 
        
        
    }

    Vectors operator +(const Vectors &other)const{
        
        if (this->v.size()!=other.v.size()){
            throw std::invalid_argument("Dimensions don't match"); 

        }

    
        std::vector<float>addresult ; 
        for(size_t i = 0 ; i < v.size(); i++ ){
            addresult.push_back(this->v[i]+ other.v[i]); 
        }
        return Vectors(addresult); 

         
    }
    
    Vectors operator -(const Vectors &other)const {
        
        if (this->v.size()!=other.v.size()){
            throw std::invalid_argument("Dimensions don't match"); 

        }

    
        std::vector<float>subresult ; 
        for(int i = 0 ; i < v.size(); i++ ){
            subresult.push_back(this->v[i]- other.v[i]); 
        }
        return Vectors(subresult); 
        
    }

    float dotProduct(const Vectors &other)const{

        if (this->v.size()!=other.v.size()){
            throw std::invalid_argument("Dimensions don't match"); 

        }
        
        float dotProductValue = 0.f ; 
        for(int i =0 ; i<v.size() ; i++){
            dotProductValue+= this->v[i]*other.v[i]; 

        }

        return dotProductValue ; 
        
    }


    Vectors scalarProduct(float scalarValue)const{
        std::vector<float> ScalarProductResult; 
        for (float i: v ){
            ScalarProductResult.push_back(i*scalarValue); 
        }
        return Vectors(ScalarProductResult); 

    }

    

    Vectors NormalizeVector(float vectorMagnitude){
        std::vector<float> NormalizedVector; 
        for (float i:v){
            NormalizedVector.push_back(i/vectorMagnitude); 
        }
        return Vectors(NormalizedVector);


    }

    float DistanceBetweenVectors (const Vectors &other)const{ 
        if (this->v.size()!=other.v.size()){
            throw std::invalid_argument("Dimensions don't match"); 

        }

        
        std::vector<float>Vecsubresult ; 
        float magnitudeSubVectors= 0.f ; 
        for(int i = 0 ; i < v.size(); i++ ){
            Vecsubresult.push_back(this->v[i]- other.v[i]); 
        }

        for (float j : Vecsubresult){ 
            magnitudeSubVectors += std::pow(j,2); 
            
        }
        return sqrt(magnitudeSubVectors); 



        


        
    }

    float cosineSimilarity(const Vectors &other)const{
        if (this->v.size()!=other.v.size()){
            throw std::invalid_argument("Dimensions don't match"); 

        }
        
       float dotProductforCosine = this->dotProduct(other); 
       float magnitude1 = this->magnitudeVector() ;
       float magnitude2 =other.magnitudeVector() ;


       if(magnitude1==0 ||magnitude2== 0 ){ 
        throw std::invalid_argument("Cosine Similarity is undefined for zero vectors."); 
       }

       float cosValue= dotProductforCosine/(magnitude1*magnitude2); 
       return cosValue ; 


    }


    float angleBetweenVectors(const Vectors &other)const { 
       float cosValue=  this->cosineSimilarity(other); 
       cosValue = std::clamp(cosValue, -1.0f, 1.0f)  ; 
       float angleInRadians = std::acos(cosValue); 
       return angleInRadians ; 
       
        
    }





}; 


int main () {
    int numofValues ; 
    float num ; 
    float scalarVal = 3; 
    
    std::vector <float> v1 ; 
    std::cout<<"Number of Values in Vector :\t " ; 
    std::cin>>numofValues; 
    for (int i= 0  ; i < numofValues; i++ ){
        std::cout<<"Element"<<i+1<<": "; 
        std::cin>>num;
        v1.push_back(num); 
    }
    
    std::vector <float> v2 = {33.1,22.6,63.1}; 
    

    Vectors v1Object{v1}; 

    std::cout <<"First Vector\n"; 
    v1Object.printVector() ;
    
    float v1Mag= v1Object.magnitudeVector() ;
    std::cout<<"Magnitude of v1: "<<v1Mag<<"\n"; 

    
    Vectors v2Object{v2}; 
    std::cout <<"Second Vector\n"; 
    v2Object.printVector() ;
    float v2Mag = v2Object.magnitudeVector() ; 
    std::cout<<"Magnitude of v2: "<<v2Mag<<"\n";
    

    Vectors v3Object = v1Object+v2Object; 
    std::cout <<"v1 + v2 : \n"; 
    v3Object.printVector() ;

    Vectors v4Object = v1Object - v2Object ; 
    std::cout<<"v1-v2 :\n"; 
    v4Object.printVector() ; 
    

    std::cout<<"Dot Product : "<< v1Object.dotProduct(v2Object)<<std::endl ; 

    Vectors v5Object = v1Object.scalarProduct(scalarVal);

    std::cout<<scalarVal<<"*"<< "v1: "; 
    
    v5Object.printVector() ; 


    Vectors v6Object = v1Object.NormalizeVector(v1Object.magnitudeVector()); 
    std::cout<<"The Normalized Vector of v1 : "; 
    v6Object.printVector(); 


    std::cout<<"The distance between the vectors v1 and v2\t" ; 
    std::cout<< v1Object.DistanceBetweenVectors(v2Object)<<std::endl ; 


    std::cout<<"The Cos value of the vectors v1 and v2 : "<<v1Object.cosineSimilarity(v2Object)<<std::endl ;

    std::cout<<"The angle between the vectors v1 and v2 (in Radians) :  "<<v1Object.angleBetweenVectors(v2Object)<<std::endl; 


    return 0 ; 
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