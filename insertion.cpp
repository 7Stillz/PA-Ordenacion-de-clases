#include<iostream>
using namespace std;

template <class T>
class Ordenador{
    public:
        virtual void Ordena(T *A, int n) = 0;
};
template <class T>
class Insertionshort : public Ordenador<T>{
    public:
        void Ordena(T *A, int n);
};
template <class T>
void Insertionshort<T> :: Ordena(T *A, int n){
  int j;
  T key;
  for (int i = 1; i < n; i++)
  {
    key = A[i];
    j = i - 1;
    while (j >= 0 and A[j] > key)
    {
      A[j + 1] = A[j];
      j--;
		}
		A[j+1]=key;
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
    
    Insertionshort<Alumno> objIDD;
    objIDD.Ordena(A,n);


    cout<<"\nDatos ordenados"<<endl;
    for(int i = 0; i < n; i++){
        cout<<A[i]<<endl; 
    }
    return 0;
}