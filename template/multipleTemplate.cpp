//creating template which can handle different types of types


template<typename T , typename V>

class DoublePair{
    T x;
    V y;
  
  public:
  
    void setX(T x){
      this->x=x;
    }
  
  
    void setY(V y){
      this->y=y;
    }
  
  T getX(){ return x; }
  
  T getY(){ return y; }
  
}

int main(){
  DoublePair<int,string> d1;
  
  
}
