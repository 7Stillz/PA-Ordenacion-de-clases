#include<iostream>
using namespace std;

template <class T>
class Ordenador{
    public:
        virtual void Ordena(T *A, int n) = 0;
};
template <class T>
class Selectionsort : public Ordenador<T>{
    public:
        void Ordena(T *A, int n);
};
template <class T>
void Selectionsort<T> :: Ordena(T *A, int n){
  int k;
  T menor;
  for (int i = 0; i < n-1; i++)
  {
    menor = A[i];
    k = i;
    for (int j = i + 1; j < n;j++)
    {
      if (menor>A[j])
      {
        menor = A[j];
        k = j;
      }
    }
    A[k] = A[i];
    A[i] = menor;
	}
}
class Alumno{
    private:
        int cod;
        char nombre[40];
    public:
        Alumno(){}
        bool operator>(Alumno);
        friend istream& operator>>(istream &, Alumno &);
        friend ostream& operator<<(ostream &, Alumno &);
};
bool Alumno::operator>(Alumno objA){
    if(cod > objA.cod)
        return true;
    else
        return false;
} 
istream& operator>>(istream &Lee, Alumno &objA){
    cout<<"Ingrese codigo: "; Lee>>objA.cod;
    cout<<"Ingrese nombre: "; Lee>>objA.nombre;
    return Lee;
}


ostream& operator<<(ostream &Escribe, Alumno &objA){
    Escribe<<"Codigo: "<<objA.cod<<endl;
    Escribe<<"Nombre: "<<objA.nombre<<endl;
    return Escribe;
}
int main(){
    Alumno A[10];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>A[i];
        cout<<endl;       
    }
    
    Selectionsort<Alumno> objIDD;
    objIDD.Ordena(A,n);


    cout<<"\nDatos ordenados"<<endl;
    for(int i = 0; i < n; i++){
        cout<<A[i]<<endl; 
    }
    return 0;
}