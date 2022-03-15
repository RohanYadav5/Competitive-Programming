// creating one template handler using template in c++
template<typename T>

// making class using template
class Pair{
  T x;
  T y;
  
  public:
  
  void setX(T x){
    this->x=x 
  }
  
  T getX(){ return x; }
  
   void setY(T y){
    this->y=y 
  }
  
  T getY(){ return y; }

}


int main(){
  
  //using pair class for the templete
  Pair<int> p1;
  
}
