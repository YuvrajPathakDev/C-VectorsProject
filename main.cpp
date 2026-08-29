#include <iostream>
#include <cmath>
class vector2D{
private: 
    double Xcoordinate ; 
    double Ycoordinate ; 
public: 
    vector2D(double xValue , double yValue){
        Xcoordinate = xValue ; 
        Ycoordinate = yValue ; 
    }
    void printVector () {
        std::cout<<"("<<Xcoordinate<<","<<Ycoordinate<<")"<<std::endl; 
    }
    void magnitudeVector () {
        double magnitude = std::sqrt(Xcoordinate*Xcoordinate+Ycoordinate*Ycoordinate); 
        std::cout <<"Magnitude:"<<magnitude<<std::endl ; 
    }
    //Operator Overloading : 

    vector2D operator + ( vector2D other) {
        double newX= this->Xcoordinate + other.Xcoordinate; 
        double newY = this->Ycoordinate + other.Ycoordinate; 
        return vector2D(newX, newY); 

    }   

    vector2D operator - (vector2D other){
        double newX= this->Xcoordinate- other.Xcoordinate; 
        double newY = this->Ycoordinate - other.Ycoordinate; 
        return vector2D(newX, newY);
    }

    double dotProduct (vector2D other){
        return Xcoordinate*other.Xcoordinate+Ycoordinate*other.Ycoordinate;

    }
    //returning scalar works for the 2D vector because only z-component exists:
    double crossProduct(vector2D other){
        return Xcoordinate*other.Ycoordinate- Ycoordinate*other.Xcoordinate;

    }
}; 

int main () {

    vector2D v1 (33.1, 11.7); 
    vector2D v2(66.7,93.9) ;
    vector2D v3 = v1+v2 ; 
    vector2D v4 = v1 - v2 ; 
    v1.printVector() ; 
    v1.magnitudeVector() ; 
    v2.printVector() ; 
    v2.magnitudeVector(); 
    v3.printVector() ; 
    v4.printVector() ; 
    std::cout <<v1.dotProduct(v2)<<std::endl;
    std::cout<<v1.crossProduct(v2)<<std::endl; ; 


}